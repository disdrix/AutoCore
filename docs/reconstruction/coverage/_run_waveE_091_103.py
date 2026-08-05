"""WaveE fun_bulk_091..103: HTTP batch_decompile -> tmp_batch_waveE_XXX.json -> emit."""
import json
import subprocess
import sys
import time
from pathlib import Path

import requests

ROOT = Path(r"C:\Users\josh\Documents\GitHub\AutoCore")
WL = ROOT / "docs/reconstruction/coverage/worklists_waveE"
OUT = ROOT / "docs/reconstruction/coverage"
EMIT = ROOT / "docs/reconstruction/coverage/emit_units_industrial.py"
URL = "http://127.0.0.1:8089/batch_decompile"
TIMEOUT = 600
BULKS = list(range(91, 104))
CHUNK = 10
LOG = OUT / "tmp_emit_waveE_091_103_log.txt"


def log(msg: str) -> None:
    line = msg if msg.endswith("\n") else msg + "\n"
    print(line, end="", flush=True)
    with LOG.open("a", encoding="utf-8") as f:
        f.write(line)


def load_addrs(n: int) -> list[str]:
    text = (WL / f"fun_bulk_{n:03d}.txt").read_text(encoding="utf-8")
    line1 = text.splitlines()[0].strip()
    return [a.strip() for a in line1.split(",") if a.strip()]


def norm_key(k: str) -> str:
    return f"0x{str(k).lower().replace('0x', '').zfill(8)}"


def batch_decompile(addrs: list[str], attempt: int = 1) -> dict:
    functions = ",".join(addrs)
    log(f"  request attempt={attempt} n={len(addrs)}")
    t0 = time.time()
    r = requests.get(URL, params={"functions": functions}, timeout=TIMEOUT)
    log(f"  status={r.status_code} dt={time.time() - t0:.1f}s len={len(r.text)}")
    r.raise_for_status()
    return r.json()


def batch_decompile_chunked(addrs: list[str]) -> dict:
    merged: dict = {}
    for i in range(0, len(addrs), CHUNK):
        chunk = addrs[i : i + CHUNK]
        data = None
        for attempt in (1, 2):
            try:
                data = batch_decompile(chunk, attempt=attempt)
                break
            except Exception as e:
                log(f"  batch fail chunk[{i}:{i + len(chunk)}] attempt={attempt}: {e}")
                if attempt == 1:
                    time.sleep(3)
                else:
                    data = {}
        for k, v in (data or {}).items():
            merged[norm_key(k)] = v
    return merged


def fallback_single(addrs: list[str], existing: dict) -> dict:
    out = dict(existing)
    for a in addrs:
        key = norm_key(a)
        val = out.get(key)
        if (
            val
            and not str(val).strip().startswith("ERROR")
            and "Failed to decompile" not in str(val)[:80]
            and len(str(val)) > 20
        ):
            continue
        log(f"  fallback decompile_function {a}")
        for attempt in (1, 2):
            try:
                r = requests.get(
                    "http://127.0.0.1:8089/decompile_function",
                    params={"address": a},
                    timeout=TIMEOUT,
                )
                r.raise_for_status()
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


def is_good(v) -> bool:
    return bool(v) and not str(v).startswith("ERROR") and len(str(v)) > 20


def main() -> int:
    LOG.write_text("", encoding="utf-8")
    results = []
    for n in BULKS:
        tag = f"{n:03d}"
        out_path = OUT / f"tmp_batch_waveE_{tag}.json"
        addrs = load_addrs(n)
        wanted = {norm_key(a) for a in addrs}
        log(f"=== bulk {tag} ({len(addrs)} addrs) ===")
        final = None
        if out_path.exists():
            try:
                prev = json.loads(out_path.read_text(encoding="utf-8"))
                good = sum(
                    1
                    for k, v in prev.items()
                    if norm_key(k) in wanted and is_good(v)
                )
                if good >= len(addrs):
                    log(f"  reusing existing complete {out_path.name} good={good}")
                    final = {norm_key(k): v for k, v in prev.items() if norm_key(k) in wanted}
            except Exception as e:
                log(f"  existing unreadable: {e}")

        if final is None:
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
                log(f"  missing/bad {len(missing)} -> fallback")
                final = fallback_single(missing, final)
            final = {k: v for k, v in final.items() if k in wanted}
            out_path.write_text(json.dumps(final, ensure_ascii=False), encoding="utf-8")
            log(f"  saved {out_path.name} keys={len(final)} bytes={out_path.stat().st_size}")

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
            log("STDERR: " + (proc.stderr or "")[-2000:])
        good = sum(1 for v in final.values() if is_good(v))
        results.append((tag, good, proc.returncode))

    log("=== SUMMARY ===")
    for tag, good, rc in results:
        log(f"  bulk {tag}: good={good}/20 emit_rc={rc}")
    return 0 if all(rc == 0 for _, _, rc in results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
