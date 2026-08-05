import json, subprocess, sys, time
from pathlib import Path
import requests

ROOT = Path(r"C:\Users\josh\Documents\GitHub\AutoCore")
WL = ROOT / "docs/reconstruction/coverage/worklists_waveE"
OUT = ROOT / "docs/reconstruction/coverage"
EMIT = ROOT / "docs/reconstruction/coverage/emit_units_industrial.py"
URL = "http://127.0.0.1:8089/batch_decompile"
TIMEOUT = 600
BULKS = list(range(117, 130))
LOG = OUT / "tmp_emit_waveE_117_129_log.txt"
CHUNK = 10  # full-20 can time out; 10 worked via MCP

def log(msg):
    line = msg if msg.endswith("\n") else msg + "\n"
    print(line, end="", flush=True)
    with LOG.open("a", encoding="utf-8") as f:
        f.write(line)

def load_addrs(n):
    text = (WL / f"fun_bulk_{n:03d}.txt").read_text(encoding="utf-8")
    line1 = text.splitlines()[0].strip()
    return [a.strip() for a in line1.split(",") if a.strip()]

def batch_decompile(addrs, attempt=1):
    functions = ",".join(addrs)
    log(f"  request attempt={attempt} n={len(addrs)}")
    t0 = time.time()
    r = requests.get(URL, params={"functions": functions}, timeout=TIMEOUT)
    log(f"  status={r.status_code} dt={time.time()-t0:.1f}s len={len(r.text)}")
    r.raise_for_status()
    return r.json()

def batch_decompile_chunked(addrs):
    """Decompile in CHUNK-sized pieces; retry each chunk once."""
    merged = {}
    for i in range(0, len(addrs), CHUNK):
        chunk = addrs[i : i + CHUNK]
        data = None
        for attempt in (1, 2):
            try:
                data = batch_decompile(chunk, attempt=attempt)
                break
            except Exception as e:
                log(f"  batch fail chunk[{i}:{i+len(chunk)}] attempt={attempt}: {e}")
                if attempt == 1:
                    time.sleep(3)
                else:
                    data = {}
        for k, v in (data or {}).items():
            merged[norm_key(k)] = v
    return merged

def fallback_single(addrs, existing):
    out = dict(existing)
    for a in addrs:
        key = f"0x{a.lower().replace('0x','').zfill(8)}"
        val = out.get(key) or out.get(a)
        if val and not str(val).strip().startswith("ERROR") and "Failed to decompile" not in str(val)[:80]:
            if len(str(val)) > 20:
                continue
        log(f"  fallback decompile_function {a}")
        for attempt in (1, 2):
            try:
                t0 = time.time()
                r = requests.get(
                    "http://127.0.0.1:8089/decompile_function",
                    params={"address": a},
                    timeout=TIMEOUT,
                )
                log(f"    attempt={attempt} status={r.status_code} dt={time.time()-t0:.1f}s len={len(r.text)}")
                r.raise_for_status()
                # decompile_function may return plain text or JSON
                try:
                    j = r.json()
                    if isinstance(j, dict) and "decompiled" in j:
                        out[key] = j["decompiled"]
                    elif isinstance(j, dict) and key in j:
                        out[key] = j[key]
                    elif isinstance(j, str):
                        out[key] = j
                    else:
                        out[key] = r.text
                except Exception:
                    out[key] = r.text
                break
            except Exception as e:
                log(f"    FAIL attempt={attempt}: {e}")
                if attempt == 1:
                    time.sleep(2)
                else:
                    out[key] = f"ERROR: {e}"
    return out

def norm_key(k):
    return f"0x{str(k).lower().replace('0x','').zfill(8)}"

# reset log
LOG.write_text("", encoding="utf-8")
results = []
for n in BULKS:
    tag = f"{n:03d}"
    out_path = OUT / f"tmp_batch_waveE_{tag}.json"
    addrs = load_addrs(n)
    wanted = {norm_key(a) for a in addrs}
    log(f"=== bulk {tag} ({len(addrs)} addrs) ===")
    # skip if already complete
    if out_path.exists():
        try:
            prev = json.loads(out_path.read_text(encoding="utf-8"))
            good = sum(
                1
                for k, v in prev.items()
                if norm_key(k) in wanted
                and v
                and not str(v).startswith("ERROR")
                and len(str(v)) > 20
            )
            if good >= len(addrs):
                log(f"  skip existing complete {out_path.name} good={good}")
                proc = subprocess.run(
                    [sys.executable, str(EMIT), str(out_path), "--system", "unknown"],
                    cwd=str(ROOT),
                    capture_output=True,
                    text=True,
                    encoding="utf-8",
                    errors="replace",
                )
                log(proc.stdout or "")
                if proc.returncode != 0:
                    log("STDERR: " + (proc.stderr or "")[-1000:])
                results.append((tag, good, proc.returncode))
                continue
        except Exception as e:
            log(f"  existing unreadable: {e}")

    final = batch_decompile_chunked(addrs)

    missing = []
    for a in addrs:
        key = norm_key(a)
        val = final.get(key)
        if (
            not val
            or str(val).strip().startswith("ERROR")
            or "Failed to decompile" in str(val)[:80]
            or len(str(val)) < 20
        ):
            missing.append(a)
    if missing:
        log(f"  missing/failed {len(missing)}")
        final = fallback_single(missing, final)
        final = {norm_key(k): v for k, v in final.items()}

    final = {k: v for k, v in final.items() if k in wanted}
    for a in addrs:
        key = norm_key(a)
        if key not in final:
            final[key] = "ERROR: missing after fallback"

    out_path.write_text(json.dumps(final, ensure_ascii=False), encoding="utf-8")
    log(f"  saved {out_path.name} keys={len(final)}")

    proc = subprocess.run(
        [sys.executable, str(EMIT), str(out_path), "--system", "unknown"],
        cwd=str(ROOT),
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    log(proc.stdout or "")
    if proc.returncode != 0:
        log("STDERR: " + (proc.stderr or "")[-1500:])
    results.append((tag, len(final), proc.returncode))

log("==== SUMMARY ====")
for tag, nkeys, rc in results:
    log(f"bulk {tag}: keys={nkeys} emit_rc={rc}")
log("DONE")
