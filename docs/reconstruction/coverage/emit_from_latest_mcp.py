"""Find newest MCP batch_decompile JSON containing a marker address and emit units."""
from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

SESSION = Path(
    r"C:\Users\josh\.grok\sessions\C%3A%5CUsers%5Cjosh%5CDocuments%5CGitHub%5CAutoCore"
    r"\019f8ec7-1220-7a12-afba-d2a1cb356d2e\mcp"
)
COV = Path("docs/reconstruction/coverage")


def main() -> int:
    if len(sys.argv) < 2:
        print("usage: emit_from_latest_mcp.py <marker_addr_like_0x0043e7f0> [tag]")
        return 2
    marker = sys.argv[1].lower()
    if not marker.startswith("0x"):
        marker = "0x" + marker
    tag = sys.argv[2] if len(sys.argv) > 2 else marker[-6:]
    for p in sorted(SESSION.glob("call-*.json"), key=lambda x: -x.stat().st_mtime)[:40]:
        try:
            text = p.read_text(encoding="utf-8")
        except OSError:
            continue
        if f'"{marker}"' not in text:
            continue
        try:
            data = json.loads(text)
        except json.JSONDecodeError:
            continue
        if isinstance(data, dict) and "result" in data:
            data = data["result"]
            if isinstance(data, str):
                try:
                    data = json.loads(data)
                except json.JSONDecodeError:
                    continue
        if not isinstance(data, dict) or marker not in {k.lower() for k in data}:
            # try exact
            if not (isinstance(data, dict) and any(k.lower() == marker for k in data)):
                continue
        # normalize keys
        norm = {k if k.startswith("0x") else k: v for k, v in data.items() if isinstance(v, str)}
        out = COV / f"tmp_auto_{tag}.json"
        out.write_text(json.dumps(norm), encoding="utf-8")
        print(f"found {p.name} keys={len(norm)} -> {out}")
        subprocess.check_call(
            [
                sys.executable,
                str(COV / "emit_units_industrial.py"),
                str(out),
            ]
        )
        return 0
    print("not found", marker)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
