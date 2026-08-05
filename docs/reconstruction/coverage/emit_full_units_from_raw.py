"""
Generate annotated + clean + function-record scaffolds from raw captures.
Important units should still be human-refined and dual-reviewed.
Does not overwrite existing non-empty clean/function files unless --force.
"""
from __future__ import annotations

import argparse
import re
from datetime import date
from pathlib import Path

ROOT = Path("docs/reconstruction")
RAW = ROOT / "raw"
ANN_SUFFIX = ".annotated.md"
FUNC = ROOT / "functions"
CLEAN = ROOT / "reconstructed-exact"

HEADER_RE = re.compile(r"\*\*Stable ID\*\*\s*\|\s*`([^`]+)`")
VA_RE = re.compile(r"\*\*VA\*\*\s*\|\s*`([^`]+)`")
NAME_RE = re.compile(r"\*\*Canonical name\*\*\s*\|\s*`([^`]+)`")
SYS_RE = re.compile(r"\*\*System\*\*\s*\|\s*([^\n|]+)")
CODE_RE = re.compile(r"```c\n(.*?)```", re.S)


def parse_raw(text: str) -> dict:
    def g(rx, default=""):
        m = rx.search(text)
        return m.group(1).strip() if m else default

    code_m = CODE_RE.search(text)
    return {
        "stable": g(HEADER_RE, "aa_unknown"),
        "va": g(VA_RE, "0x0"),
        "name": g(NAME_RE, "Unknown"),
        "system": g(SYS_RE, "unknown"),
        "code": code_m.group(1).strip() if code_m else "",
    }


def clean_from_raw(meta: dict) -> str:
    code = meta["code"]
    # Light humanization: strip undefined4/undefined1 where float/byte clear from comments
    code2 = code
    code2 = code2.replace("undefined4", "uint32_t /* or float bits */")
    code2 = code2.replace("undefined1", "uint8_t")
    code2 = code2.replace("undefined ", "/*undefined*/ ")
    return f"""// =============================================================================
// {meta['name']}
// -----------------------------------------------------------------------------
// Stable ID: {meta['stable']}
// Address:   {meta['va']}  (autoassault.exe, image base 0x400000)
// System:    {meta['system']}
// Generated: {date.today().isoformat()} from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

{code2}
"""


def annotated_from_raw(meta: dict) -> str:
    return f"""# Annotated low-level: {meta['name']}

| Field | Value |
|---|---|
| Stable ID | `{meta['stable']}` |
| VA | `{meta['va']}` |
| System | {meta['system']} |
| Date | {date.today().isoformat()} |

## Machine-level notes

- Source: raw capture for `{meta['stable']}`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
{meta['code']}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
"""


def function_record(meta: dict) -> str:
    return f"""# Function record: {meta['name']}

| Field | Value |
|---|---|
| **Stable ID** | `{meta['stable']}` |
| **Canonical name** | `{meta['name']}` |
| **Address** | `{meta['va']}` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | {meta['system']} |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

See raw capture. Reconstructed signature may use improved types when evidence exists.

## Behavioral summary

See plate comments in raw decompile and system map for `{meta['system']}`.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | Probable (Ghidra) |
| Signature | Tentative–Probable |
| Control flow | Probable (decompiler) |
| Naming | Probable if non-FUN_ name; else Tentative |
| Side effects | Partial |
| Overall | Partial scaffold |

## Open questions

- Full caller/callee validation
- Runtime observation
- Differential equivalence

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/{meta['stable']}_{meta['name']}.md` |
| Annotated | `raw/{meta['stable']}_{meta['name']}.annotated.md` |
| Clean | `reconstructed-exact/{meta['name']}.cpp` |
"""


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--force", action="store_true")
    ap.add_argument("--only-stable", action="append", default=[])
    args = ap.parse_args()
    FUNC.mkdir(parents=True, exist_ok=True)
    CLEAN.mkdir(parents=True, exist_ok=True)
    n = 0
    for raw_path in sorted(RAW.glob("aa_*.md")):
        if raw_path.name.endswith(".annotated.md"):
            continue
        text = raw_path.read_text(encoding="utf-8")
        meta = parse_raw(text)
        if args.only_stable and meta["stable"] not in args.only_stable:
            continue
        if not meta["code"]:
            continue
        ann = RAW / f"{raw_path.stem}.annotated.md"
        fn = FUNC / f"{meta['stable']}_{meta['name']}.md"
        # prefer existing setsteer style name
        clean = CLEAN / f"{meta['name']}.cpp"
        for path, content in (
            (ann, annotated_from_raw(meta)),
            (fn, function_record(meta)),
            (clean, clean_from_raw(meta)),
        ):
            if path.exists() and not args.force and path.stat().st_size > 200:
                # keep hand-written
                continue
            path.write_text(content, encoding="utf-8")
            n += 1
    print(f"wrote_or_skipped_cycle files_touched_estimate={n}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
