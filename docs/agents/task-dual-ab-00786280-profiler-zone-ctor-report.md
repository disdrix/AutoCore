# Dual A/B report — `aa_00786280` Profiler_Zone_Ctor

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00786280`. Dual A/B + three-rep strengthen.  
**Agent:** W17-S  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `get_xrefs_to` + `get_function_by_address` (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00786280` Profiler_Zone_Ctor | **accept-with-gaps** — construct ABI/layout/timer seal; map `+0x1c` / `+0x0c` / flag English open |

---

## Sealed facts

1. **Role:** Profiler **zone node in-place constructor** for pre-`operator_new(0x5c)` storage.

2. **Body span:** `0x00786280` – `0x00786335`.

3. **ABI:** **ECX = parent** (nullable), **stack0 = self**, **stack1 = name**, **`ret 8`**, returns **self in EAX**. Not self-in-ECX thiscall.

4. **Init:** name/`timer=0`/parent; child vec zero; empty RB map header via `FUN_0044e100` at `+0x20`, size 0; stats zero; **`+0x58=1`**; timer `new(0x30)`+`FUN_00780730` → `+4`.

5. **Xrefs (2):**
   - `FUN_00786470` FindOrCreateChildZone @ `0x00786532` (parent=current).
   - `FUN_007866e0` EnsureThreadSlot @ `0x007867a6` (parent=NULL, name=`"Hermann"` @ `0x00a9adc4`).

6. **Callee timer:** owned dual `aa_00780730` (QPF/1e6 µs divisor).

---

## Gaps

1. Unwritten `+0x0c`.  
2. Full map object layout at `+0x1c` (insert site uses it; ctor sets head/size).  
3. Per-dword English for `+0x28..+0x54` beyond nest/hierarchical known from siblings.  
4. Flag `+0x58` product name.  
5. Runtime / bit-diff.  
6. Full dual of `FUN_0044e100`.

---

## Dual A/B

| Review | Path | Verdict |
|--------|------|---------|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00786280_Profiler_Zone_Ctor.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00786280_Profiler_Zone_Ctor.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00786280_Profiler_Zone_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00786280_Profiler_Zone_Ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00786280_FUN_00786280.md` |
| Named function record | `docs/reconstruction/functions/aa_00786280_Profiler_Zone_Ctor.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Profiler_Zone_Ctor.cpp` |
| Clean (FUN_) | `docs/reconstruction/reconstructed-exact/FUN_00786280.cpp` |
| Raw | `docs/reconstruction/raw/aa_00786280_FUN_00786280.md` |
| Annotated | `docs/reconstruction/raw/aa_00786280_FUN_00786280.annotated.md` |
| This report | `docs/agents/task-dual-ab-00786280-profiler-zone-ctor-report.md` |

---

## AutoCore impact

- **No mandatory server port** — client profiler instrumentation.  
- Root zone name `"Hermann"` is a call-site literal, not embedded in this VA.  
- Port note: do not invert parent/self; timer may be null on OOM.
