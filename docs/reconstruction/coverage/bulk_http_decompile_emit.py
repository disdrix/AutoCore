"""Bulk decompile remaining worklists via Ghidra HTTP API + industrial emit.

Usage:
  python docs/reconstruction/coverage/bulk_http_decompile_emit.py [--start N] [--end N] [--workers W]

Reads docs/reconstruction/coverage/worklists/fun_bulk_XXX.txt (line 1 = comma addrs).
GET http://127.0.0.1:8089/batch_decompile?functions=...
Writes tmp_batch_http_XXX.json and runs emit_units_industrial.py.
"""
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

ROOT = Path("docs/reconstruction/coverage")
WL = ROOT / "worklists"
OUT_PREFIX = ROOT / "tmp_batch_http"
GHIDRA = "http://127.0.0.1:8089/batch_decompile"
EMIT = ROOT / "emit_units_industrial.py"


def load_addrs(path: Path) -> str:
    line = path.read_text(encoding="utf-8").splitlines()[0].strip()
    return line


def decompile_batch(addrs: str, timeout: int = 180) -> dict:
    q = urllib.parse.urlencode({"functions": addrs})
    url = f"{GHIDRA}?{q}"
    req = urllib.request.Request(url, method="GET")
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        raw = resp.read().decode("utf-8", errors="replace")
    data = json.loads(raw)
    if isinstance(data, dict) and "result" in data and isinstance(data["result"], dict):
        data = data["result"]
    if isinstance(data, str):
        data = json.loads(data)
    if not isinstance(data, dict):
        raise RuntimeError(f"unexpected response type {type(data)}")
    return data


def process_one(idx: int) -> dict:
    wl = WL / f"fun_bulk_{idx:03d}.txt"
    if not wl.exists():
        return {"idx": idx, "status": "missing_wl"}
    addrs = load_addrs(wl)
    expected = [a.strip() for a in addrs.split(",") if a.strip()]
    out_json = Path(f"{OUT_PREFIX}_{idx:03d}.json")
    try:
        data = decompile_batch(addrs)
    except Exception as e:
        # retry once
        time.sleep(1.0)
        try:
            data = decompile_batch(addrs, timeout=240)
        except Exception as e2:
            return {"idx": idx, "status": "decompile_fail", "error": str(e2), "expected": len(expected)}

    out_json.write_text(json.dumps(data), encoding="utf-8")
    proc = subprocess.run(
        [sys.executable, str(EMIT), str(out_json), "--system", "unknown"],
        capture_output=True,
        text=True,
        cwd=str(Path.cwd()),
    )
    new_raw = proc.stdout.count("NEW ")
    keep = proc.stdout.count("keep ")
    return {
        "idx": idx,
        "status": "ok" if proc.returncode == 0 else "emit_fail",
        "keys": len(data),
        "expected": len(expected),
        "new": new_raw,
        "keep": keep,
        "rc": proc.returncode,
        "stderr": (proc.stderr or "")[:300],
    }


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--start", type=int, default=0)
    ap.add_argument("--end", type=int, default=9999)
    ap.add_argument("--workers", type=int, default=4)
    args = ap.parse_args()

    indices = []
    for p in sorted(WL.glob("fun_bulk_*.txt")):
        try:
            i = int(p.stem.split("_")[-1])
        except ValueError:
            continue
        if args.start <= i <= args.end:
            indices.append(i)

    print(f"batches={len(indices)} workers={args.workers} range={args.start}-{args.end}")
    totals = {"ok": 0, "fail": 0, "new": 0, "keep": 0, "keys": 0}
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as ex:
        futs = {ex.submit(process_one, i): i for i in indices}
        for fut in as_completed(futs):
            r = fut.result()
            if r.get("status") == "ok":
                totals["ok"] += 1
                totals["new"] += r.get("new", 0)
                totals["keep"] += r.get("keep", 0)
                totals["keys"] += r.get("keys", 0)
                print(f"OK {r['idx']:03d} keys={r['keys']} new={r['new']} keep={r['keep']}")
            else:
                totals["fail"] += 1
                print(f"FAIL {r}")
    print("TOTALS", json.dumps(totals))
    return 0 if totals["fail"] == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
