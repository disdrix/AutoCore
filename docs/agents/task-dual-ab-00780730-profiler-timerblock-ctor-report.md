# Dual A/B report — `aa_00780730` Profiler_TimerBlock_Ctor

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00780730`. Dual A/B + three-rep strengthen.  
**Agent:** W17-S  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `get_xrefs_to` + `get_function_by_address` (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00780730` Profiler_TimerBlock_Ctor | **accept** — ESI this / EAX return, QPF÷1e6 divisor, timer 0x30 layout sealed |

---

## Sealed facts

1. **Role:** Profiler **timer sample-block constructor**. Allocated `operator_new(0x30)` by zone ctor; stored at **`zone+4`**.

2. **Body span:** `0x00780730` – `0x00780773`.

3. **ABI:** Register **`ESI` = this**, **`EAX` = this** return, **`ret`** (no stack formals). Not ECX-thiscall.

4. **Math:** `QueryPerformanceFrequency` (IAT `[0x009c61b4]`) → `__alldiv(..., 1000000, 0)` → store 64-bit at **`+0x10/+0x14`**. Imm **`0x000F4240`** sealed in body bytes.

5. **Zero set:** start, accum, avg, count, last, max. Divisor slot receives QPF then scaled value (never left zero intentionally).

6. **Unit:** ticks per **microsecond**; matches accumulate last/max and start preserve-divisor contract.

7. **Xrefs (1):** `FUN_00786280` @ `0x00786313`.

---

## Gaps

1. Product C++ type name (no plate string on this VA).  
2. `+0x2c` pad usage.  
3. Runtime / bit-diff.  
4. QPF-fail (zero frequency) not handled in body.

---

## Dual A/B

| Review | Path | Verdict |
|--------|------|---------|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00780730_Profiler_TimerBlock_Ctor.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00780730_Profiler_TimerBlock_Ctor.md` | **accept** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00780730_Profiler_TimerBlock_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00780730_Profiler_TimerBlock_Ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00780730_FUN_00780730.md` |
| Named function record | `docs/reconstruction/functions/aa_00780730_Profiler_TimerBlock_Ctor.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Profiler_TimerBlock_Ctor.cpp` |
| Clean (FUN_) | `docs/reconstruction/reconstructed-exact/FUN_00780730.cpp` |
| Raw | `docs/reconstruction/raw/aa_00780730_FUN_00780730.md` |
| Annotated | `docs/reconstruction/raw/aa_00780730_FUN_00780730.annotated.md` |
| This report | `docs/agents/task-dual-ab-00780730-profiler-timerblock-ctor-report.md` |

---

## AutoCore impact

- **No mandatory server port** — client instrumentation only.  
- If client profiler parity ever needed: construct 0x30 timer with divisor = QPF/1e6; keep start/accum consumers in µs.
