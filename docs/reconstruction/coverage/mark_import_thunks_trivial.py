"""Mark import thunks / short external stubs as trivial-batch in a side ledger."""
from __future__ import annotations

import json
from pathlib import Path

INV = Path("docs/reconstruction/coverage/inventory.jsonl")
OUT = Path("docs/reconstruction/coverage/trivial_batch_imports.jsonl")
HAVE = Path("docs/reconstruction/functions")

# Names that are pure import thunks or CRT stubs (not game logic managers)
IMPORT_PREFIXES = (
    "WSA",
    "Direct3D",
    "D3DX",
    "ov_",
    "nci",
    "fputs",
    "fwrite",
    "fread",
    "fclose",
    "fopen",
    "malloc",
    "free",
    "memcpy",
    "memset",
    "strcpy",
    "strcmp",
    "strlen",
    "sprintf",
    "printf",
    "operator_",
    "std::",
    "__",
    "setjmp",
    "longjmp",
    "atexit",
    "exit",
    "abort",
)


def main() -> int:
    have = set()
    for p in HAVE.glob("aa_*.md"):
        parts = p.stem.split("_")
        if len(parts) >= 2:
            have.add("0x" + parts[1].lower())

    rows = []
    for line in INV.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        r = json.loads(line)
        n = r.get("name") or ""
        a = r["addr"].lower()
        if a in have:
            continue
        if n.startswith("FUN_") or n.startswith("Unwind@") or n.startswith("Catch@"):
            continue
        if any(n.startswith(p) for p in IMPORT_PREFIXES) or "Thunk" in n or n.startswith(
            "thunk_"
        ):
            rows.append(
                {
                    "addr": r["addr"],
                    "name": n,
                    "status": "trivial-batch",
                    "reason": "import thunk / CRT / external stub",
                }
            )

    OUT.write_text(
        "\n".join(json.dumps(x) for x in rows) + ("\n" if rows else ""), encoding="utf-8"
    )
    print(f"wrote {OUT} count={len(rows)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
