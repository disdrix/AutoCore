# Dual A/B report — `aa_0056f570` EmptyRet

**Date:** 2026-07-29  
**Agent:** W17-P OWN-ONLY  
**Scope:** OWN ONLY VA `0x0056f570`. Dual A/B + artifacts. Seal single-byte empty ret.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0056f570` EmptyRet | **accept** — **1-byte `c3` nop leaf sealed; multi-role shared stub** |

---

## Sealed facts

1. **Body:** `0x0056f570` = **`c3` (`ret`)** only. Exclusive end `0x0056f571`. Following `cc` is pad, not body.

2. **CF:** empty `return;` — decompile ≡ 2026-07-23 raw ≡ live re-verify.

3. **ABI:** bare `ret` (not `ret n`). Body ignores ECX and any stack args callers may push.

4. **Callees:** none. Classification: **stub**.

5. **Roles (xref evidence, not body logic):**
   - Default empty **vtable** methods (DATA `70 f5 56 00`; sample base HB `0x009cdfb0` slot 7).
   - MSVC **EH Unwind** / trivial vector dtor targets (100+ CALL xrefs).
   - Format-string call sites (LED helpers) act as **dead sinks**.

6. **Name:** `EmptyRet` (descriptive). Parent-seed `Named_CalleeOf_…_InitInstance_*` is **misleading** — not InitInstance-specific.

7. **Not this VA:** `VehicleEntity_DrivePathNoOp` @ `0x004f3700` (separate empty ret). Derived HB slot 7 override `0x0051b850` (non-empty).

---

## Gaps

1. Original PDB/compiler symbol.  
2. Exhaustive DATA-slot census (hundreds of hits).  
3. Runtime / bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0056f570_EmptyRet.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0056f570_EmptyRet.md` |
| Function record | `docs/reconstruction/functions/aa_0056f570_EmptyRet.md` |
| Function record (FUN alias) | `docs/reconstruction/functions/aa_0056f570_FUN_0056f570.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyRet.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0056f570.cpp` |
| Raw (authoritative + live append) | `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.md` |
| Annotated | `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.annotated.md` |
| This report | `docs/agents/task-dual-ab-0056f570-emptyret-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

- Treat as **shared nop** — do not invent logging, free, or notify behavior at this address.
- When porting vtables, empty slots may collapse to a single shared empty function (or omit).
- Overrides of slots that default here (e.g. player targeting slot 7) are **separate** duals with real bodies.
