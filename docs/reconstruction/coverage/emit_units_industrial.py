"""
Industrial emit: batch_decompile JSON + optional name map → raw/annotated/clean/function records.

Usage:
  python emit_units_industrial.py <batch.json> [--names names.jsonl] [--system SYS] [--force]

batch.json: { "0x00aabbcc": "void FUN_...() { ... }", ... }
names.jsonl: lines of {"addr":"0x...","name":"...","system":"..."} (system optional)
"""
from __future__ import annotations

import argparse
import json
import re
from datetime import date
from pathlib import Path

ROOT = Path("docs/reconstruction")
RAW = ROOT / "raw"
ANN = ROOT / "raw"  # annotated next to raw as *.annotated.md
FUNC = ROOT / "functions"
CLEAN = ROOT / "reconstructed-exact"

SIG_RE = re.compile(
    r"(?:void|undefined4|undefined1|undefined|int|char|bool|float|uint|"
    r"byte|short|long|double|longlong|ulong|uint32_t|int32_t)\s+"
    r"(?:__thiscall\s+|__fastcall\s+|__cdecl\s+|__stdcall\s+)?"
    r"(\w+)\s*\(",
    re.I,
)

SYSTEM_HINTS = [
    (re.compile(r"(?i)mission|objective|quest|xp|experience|levelup|credit"), "missions-progression"),
    (re.compile(r"(?i)skill|cast|quickbar|cooldown|status.?effect"), "skills-abilities"),
    (re.compile(r"(?i)inventory|equip|unequip|grab|drop|cargo|item|slot"), "inventory-transfer"),
    (re.compile(r"(?i)steer|longitudinal|handbrake|drive|throttle|vehicle.?input"), "input-drive-control"),
    (re.compile(r"(?i)dialog|journal|npc"), "missions-progression"),
]


def norm_addr(addr: str) -> str:
    a = str(addr).lower().replace("0x", "").strip()
    return f"0x{a.zfill(8)}"


def load_names(path: Path | None) -> dict[str, dict]:
    out: dict[str, dict] = {}
    if not path or not path.exists():
        return out
    text = path.read_text(encoding="utf-8")
    if path.suffix == ".json":
        data = json.loads(text)
        if isinstance(data, dict):
            for k, v in data.items():
                if isinstance(v, str):
                    out[norm_addr(k)] = {"name": v}
                elif isinstance(v, dict):
                    out[norm_addr(k)] = v
        elif isinstance(data, list):
            for row in data:
                out[norm_addr(row["addr"])] = row
        return out
    for line in text.splitlines():
        line = line.strip()
        if not line:
            continue
        row = json.loads(line)
        out[norm_addr(row["addr"])] = row
    return out


def infer_system(name: str, explicit: str | None, default: str) -> str:
    if explicit and explicit != "unknown":
        return explicit
    for rx, sysname in SYSTEM_HINTS:
        if rx.search(name):
            return sysname
    return default


def clean_code(code: str) -> str:
    code2 = code
    code2 = code2.replace("undefined4", "uint32_t /* width from decompiler */")
    code2 = code2.replace("undefined1", "uint8_t")
    code2 = code2.replace("undefined2", "uint16_t")
    code2 = code2.replace("undefined8", "uint64_t")
    # keep "undefined " carefully
    return code2


def write_unit(
    addr: str,
    code: str,
    name_map: dict[str, dict],
    default_system: str,
    force: bool,
) -> dict:
    key = norm_addr(addr)
    hexpart = key[2:]
    meta = name_map.get(key, {})
    m = SIG_RE.search(code)
    decomp_name = m.group(1) if m else f"FUN_{hexpart}"
    name = meta.get("name") or decomp_name
    if name in ("if", "while", "switch"):
        name = decomp_name
    system = infer_system(name, meta.get("system"), default_system)
    stable = f"aa_{hexpart}"
    today = date.today().isoformat()

    RAW.mkdir(parents=True, exist_ok=True)
    FUNC.mkdir(parents=True, exist_ok=True)
    CLEAN.mkdir(parents=True, exist_ok=True)

    raw_path = RAW / f"{stable}_{name}.md"
    ann_path = RAW / f"{stable}_{name}.annotated.md"
    # also try legacy annotated name next to raw
    func_path = FUNC / f"{stable}_{name}.md"
    clean_path = CLEAN / f"{name}.cpp"

    result = {
        "stable": stable,
        "addr": key,
        "name": name,
        "system": system,
        "raw": str(raw_path).replace("\\", "/"),
        "new_raw": False,
        "new_clean": False,
        "new_func": False,
    }

    if force or not raw_path.exists():
        body = (
            f"# Raw capture: {name}\n\n"
            f"| Field | Value |\n"
            f"|---|---|\n"
            f"| **Stable ID** | `{stable}` |\n"
            f"| **Module** | `autoassault.exe` |\n"
            f"| **Image base** | `0x400000` |\n"
            f"| **VA** | `{key}` |\n"
            f"| **Canonical name** | `{name}` |\n"
            f"| **System** | {system} |\n"
            f"| **Capture timestamp** | `{today}` |\n"
            f"| **Tool** | Ghidra MCP `batch_decompile` |\n"
            f"| **Integrity** | Do not overwrite this raw body; append versioned sections only |\n\n"
            f"---\n\n"
            f"## Raw pseudocode (authoritative decompile)\n\n"
            f"```c\n{code.strip()}\n```\n"
        )
        raw_path.write_text(body, encoding="utf-8")
        result["new_raw"] = True

    if force or not ann_path.exists():
        ann = (
            f"# Annotated low-level: {name}\n\n"
            f"| Field | Value |\n"
            f"|---|---|\n"
            f"| Stable ID | `{stable}` |\n"
            f"| VA | `{key}` |\n"
            f"| System | {system} |\n"
            f"| Date | {today} |\n\n"
            f"## Machine-level notes\n\n"
            f"- Source: raw capture for `{stable}`.\n"
            f"- Prefer assembly when decompiler conflicts.\n"
            f"- Recover types for still-generic parameters via callers/xrefs.\n"
            f"- Map DAT_* globals and FUN_* callees in follow-up waves.\n\n"
            f"## Pseudocode (annotated copy of raw)\n\n"
            f"```c\n{code.strip()}\n```\n\n"
            f"## Open questions\n\n"
            f"- Confirm calling convention and full signature against callers.\n"
            f"- Recover meaningful types for still-generic parameters.\n"
        )
        ann_path.write_text(ann, encoding="utf-8")

    cleaned = clean_code(code.strip())
    if force or not clean_path.exists():
        clean_body = f"""// =============================================================================
// {name}
// -----------------------------------------------------------------------------
// Stable ID: {stable}
// Address:   {key}  (autoassault.exe, image base 0x400000)
// System:    {system}
// Generated: {today} from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

{cleaned}
"""
        clean_path.write_text(clean_body, encoding="utf-8")
        result["new_clean"] = True

    if force or not func_path.exists():
        # first line of signature for record
        first = cleaned.splitlines()[0] if cleaned else name
        func_body = f"""# Function record: {name}

| Field | Value |
|---|---|
| **Stable ID** | `{stable}` |
| **Canonical name** | `{name}` |
| **Address** | `{key}` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | {system} |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
{first}
```

## Artifacts

- Raw: `docs/reconstruction/raw/{stable}_{name}.md`
- Annotated: `docs/reconstruction/raw/{stable}_{name}.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/{name}.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
"""
        func_path.write_text(func_body, encoding="utf-8")
        result["new_func"] = True

    return result


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("batch_json")
    ap.add_argument("--names", default="")
    ap.add_argument("--system", default="unknown")
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--ledger", default="docs/reconstruction/coverage/emit_ledger.jsonl")
    args = ap.parse_args()

    batch_path = Path(args.batch_json)
    batch = json.loads(batch_path.read_text(encoding="utf-8"))
    # unwrap if MCP wrapped
    if isinstance(batch, dict) and "result" in batch and isinstance(batch["result"], dict):
        batch = batch["result"]
    if not isinstance(batch, dict):
        print("batch must be address->code map")
        return 2

    name_map = load_names(Path(args.names) if args.names else None)
    # also load default named files if present
    for p in [
        ROOT / "coverage" / "named_not_yet_reconstructed.jsonl",
        ROOT / "coverage" / "high_priority_named.jsonl",
    ]:
        name_map.update(load_names(p))

    results = []
    for addr, code in batch.items():
        if not isinstance(code, str) or not code.strip():
            continue
        results.append(write_unit(addr, code, name_map, args.system, args.force))

    ledger = Path(args.ledger)
    ledger.parent.mkdir(parents=True, exist_ok=True)
    with ledger.open("a", encoding="utf-8") as f:
        for r in results:
            f.write(json.dumps(r) + "\n")

    new_raw = sum(1 for r in results if r["new_raw"])
    new_clean = sum(1 for r in results if r["new_clean"])
    print(f"units={len(results)} new_raw={new_raw} new_clean={new_clean}")
    for r in results:
        flag = "NEW" if r["new_raw"] else "keep"
        print(f"  {flag} {r['stable']} {r['name']} [{r['system']}]")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
