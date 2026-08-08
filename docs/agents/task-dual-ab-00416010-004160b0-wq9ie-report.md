# Dual A/B report — WQ9I-E OWN-ONLY (`0x00416010`, `0x004160b0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9I-E**  
**Scope:** VAs `0x00416010`, `0x004160b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-E**.  
**Work item:** WQ-009 depth-6 residual dual seal (00416xxx residual neighborhood).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416010` StdList_Incsize_Max1fffffff | **accept-with-gaps** — CF/ABI/max/string/size field sealed; product throw type + runtime open |
| `aa_004160b0` Class_00a6f61c_ScalarDeletingDtor | **accept-with-gaps** — scalar CF/ABI/vtbl[0]/flags&1 sealed; product class English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-Incsize, merge-with-0x3fffffff-twin, always-free, array-deleting, false-noreturn-as-true all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00416010` — sealed facts

1. **Body:** `0x00416010`–`0x0041607e` inclusive (**111 B** / `0x6F`); plain **`RET`** (`C3`).
2. **ABI:** custom **`__fastcall`** — **ECX** = count, **EDX** = list*; no stack args; void.
3. **Semantics:** MSVC-style `std::list` **`_Incsize`**:
   - Gate: if `(0x1fffffffU - *(list+8)) < count` → `"list<T> too long"` @ `0x00a1581c` → `FUN_00401a40` → `_CxxThrowException(..., DAT_00acc388)` noreturn.
   - Else `*(list+8) += count` (`_Mysize`).
4. **Callers (3 fn / 4 sites):** `FUN_00415dd0` @ `0x00415deb`; `FUN_00834700` @ `0x00834728`; `FUN_008dfc60` @ `0x008dfd85`/`0x008dfdc2` — all pass **count=1** after buy-node `FUN_00415ed0` (node size **0x10**).
5. **Xrefs:** 4 UNCONDITIONAL_CALL.
6. **Name:** `StdList_Incsize_Max1fffffff` (Ghidra `FUN_00416010`). Distinct from sealed `StdList_Incsize` @ `0x0043fe60` (max **`0x3fffffff`**) and thiscall twin `FUN_00403600` (max **`0x6666666`**).
7. **Decompile ≡ raw CF**; max/string/size sealed via `read_memory` + disassembly listing.

### Gaps

- Product / exception-type English behind ThrowInfo `DAT_00acc388`.  
- Why max is `0x1fffffff` vs other Incsize specializations (open).  
- Full dual of buy-node / insert parents (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416010_StdList_Incsize_Max1fffffff.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416010_StdList_Incsize_Max1fffffff.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416010_FUN_00416010.md` |
| Annotated | `docs/reconstruction/raw/aa_00416010_FUN_00416010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Incsize_Max1fffffff.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416010.cpp` |
| Function | `docs/reconstruction/functions/aa_00416010_FUN_00416010.md` |
| Function named | `docs/reconstruction/functions/aa_00416010_StdList_Incsize_Max1fffffff.md` |

---

## VA `0x004160b0` — sealed facts

1. **Body:** `0x004160b0`–`0x004160cd` inclusive (**30 B** / `0x1E`); `CC` pad after **`RET 4`**.
2. **ABI:** **`__thiscall`** — **ECX** = this; stack **flags**; **`RET 4`**; returns **this\*** in EAX. Entry `56 8B F1`.
3. **Semantics:** MSVC **scalar-deleting destructor** for vtbl family **`PTR_FUN_00a6f61c`**:
   - Always `FUN_0097a8a0(this)` (complete: reinstall vtbl, chain `FUN_00792c20`).
   - If `(flags & 1)`: `operator_delete(this)` (returns — decompiler noreturn WARNING is **false**).
   - Return this.
4. **Callers:** none by CALL; **DATA** only — `PTR_FUN_00a6f61c[0]` @ `0x00a6f61c` = `0x004160b0`.
5. **Xrefs:** 1 DATA.
6. **Name:** `Class_00a6f61c_ScalarDeletingDtor` (Ghidra `FUN_004160b0`). Product English open; ctor twin `FUN_0097a8e0` references UI asset `i_w_tut_2d_wnd_highlight.dds` (circumstantial only).
7. **Decompile ≡ raw CF**; vtbl/entry/exit sealed via `read_memory`.

### Gaps

- Product / RTTI demangle for class behind `PTR_FUN_00a6f61c`.  
- Full dual of complete dtor `0097a8a0` / base `00792c20` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004160b0_FUN_004160b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004160b0_FUN_004160b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a6f61c_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004160b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004160b0_FUN_004160b0.md` |
| Function named | `docs/reconstruction/functions/aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00415dd0 / FUN_00834700 / FUN_008dfc60   [list insert helpers]
  ├─ FUN_00415ed0  buy node (0x10)           [residual]
  └─ StdList_Incsize_Max1fffffff (0x00416010) [OWN WQ9I-E]

vtbl PTR_FUN_00a6f61c
  [0] = Class_00a6f61c_ScalarDeletingDtor (0x004160b0)  [OWN WQ9I-E]
          └─ FUN_0097a8a0 complete dtor
                └─ FUN_00792c20 base teardown           [residual]

FUN_0097a8e0  ctor (same vtbl; UI highlight dds)        [residual]
FUN_004160d0  neighbor scalar (WQ9I-F)                   [not OWN]
```

Partition labeled these as **00416xxx residual neighborhood** by VA proximity; machine CF is **STL list Incsize** + **UI-class scalar deleting dtor** — co-owned only by partition assignment (unrelated systems).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416010-004160b0-wq9ie-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416010` | Port as **shared list Incsize** with max **`0x1fffffff`**. **ECX**=count, **EDX**=list*, `_Mysize` @ **+8**, bare ret. Do **not** merge with `StdList_Incsize` @ `0x0043fe60` (max `0x3fffffff`) or thiscall twin `00403600`. Pair with buy-node `00415ed0` when dualed. |
| `004160b0` | Port as **scalar deleting only**: call complete `0097a8a0`, free host iff `flags&1`, return this, **RET 4**. vtbl[0] of `PTR_FUN_00a6f61c`. Do not inline base teardown here. |
| Pair with | Incsize twins; buy-node/insert parents; complete dtor / ctor for `00a6f61c` family when dualed. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or container/STL residual table — Incsize is general list; scalar is UI-class residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416010`, `0x004160b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank-line paste).  
- Odd behavior preserved: decompiler false-noreturn on `operator_delete`; Incsize max specialization.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
