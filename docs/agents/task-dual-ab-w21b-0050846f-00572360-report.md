# Dual A/B report — W21-B OWN-ONLY (`0x0050846f`, `0x00572360`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W21-B  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x0050846f`, `0x00572360` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_xrefs` / `get_function_by_address`). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x0050846f` | `CVOGHBBase_EndOrDestroy_SoftMarkEpilogue` | **accept** |
| `0x00572360` | `InventoryGrid_RePlaceItems_Inferred` | **accept-with-gaps** |

---

## VA `0x0050846f` — CVOGHBBase_EndOrDestroy_SoftMarkEpilogue

### Sealed facts

1. **Fragment ABI:** no prologue; live-in **ESI=this**, **EBX=0**, **EBP=parent frame**; epilogue **`RET 8`**.
2. **Complete body bytes:**  
   `c6462001 895e18 8b4df4 5f5e 64890d00000000 5b 8be5 5d c20800`
3. **Semantics:**  
   `this+0x20 = 1` (soft-ended); `this+0x18 = ebx` (clear owner); restore `ExceptionList` from `[ebp-0xc]`; leave + `ret 8`.
4. **Body range:** `0x0050846f`–`0x00508488` (Ghidra).
5. **Callers (only):** four jumps from `FUN_0050843d` (`CVOGHBBase_EndOrDestroy_HardListUnlink`) — soft path always.
6. **Callees:** none (leaf).
7. Live decompile **≡** 2026-07-23 raw; full CF byte-sealed.
8. **Rename:** MissionPatrol seed alias **superseded**.

### Gaps

1. Product C++ symbol (may be inlined end of `EndOrDestroy`).
2. Runtime golden of soft path without hard list remove.
3. English label of `+0x20` beyond soft-ended (family-consistent).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Function record | `docs/reconstruction/functions/aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0050846f_FUN_0050846f.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0050846f.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatro_0050846f.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_0050846f_FUN_0050846f.md` |
| Annotated | `docs/reconstruction/raw/aa_0050846f_FUN_0050846f.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |

**Sibling context (not owned):** parent `CVOGHBBase_EndOrDestroy` `0x005083f0`; hard-unlink `0x0050843d`; list remove `0x005085b0`.

---

## VA `0x00572360` — InventoryGrid_RePlaceItems_Inferred

### Sealed facts

1. **ABI:** `__thiscall` ECX = `InventoryGrid*`; stack `relatedPtr`, `char flag`; **`RET 8`**. Returns **1** success / **0** fail (AL).
2. **Null gate:** `relatedPtr == 0` → **return 0** (entry bytes).
3. **Walk base:** `lea ebp,[this+0x2c]` → `FUN_004294f0` / `FUN_004022a0` item enumeration.
4. **Per item:** origin vfuncs `+0x250/+0x254`; type (`item[0x2a]+0x38`) **≠ 4** → CanPlace (`00570840`) at origin with InvSize `+0x406/+0x407`; on miss FindFree page **`-1`** (`005713a0`); Place (`00571620`) with vfunc `+0x25c`.
5. **Type 4:** skip CanPlace/FindFree; place at vfunc origins.
6. **Fail:** `FUN_00571e10`, leave CS if `+0x54`, **return 0**.
7. **Success:** leave CS; if `flag` → `FUN_00571e10`; free/reinit item RB at **`+0x60`** (count **`+0x64=0`**); if `!flag` → `FUN_004bc580` + `AllocateCellArray`; **return 1**.
8. **Callers:** `FUN_00572730` (SortAndRepack commit @ `0x00572a4f`); `FUN_005252f0` ×3 (cargo resize); `FUN_00521e90` wrapper (flag=1).
9. Live decompile **≡** 2026-07-23 raw; ABI sealed via entry/exit bytes.
10. **Rename:** ShowInventoryFull seed alias **superseded**.
11. Closes W20-S residual that SortAndRepack’s second arg to this unit is only “decomp 0” — call site pushes real `esi` related pointer + `ebx` flag.

### Gaps

1. Product C++ name (`_Inferred`).
2. Exact object type of `relatedPtr` (null-checked companion for `FUN_00571e10`).
3. Product intent of emptying destination RB after successful Place loop (CF sealed).
4. Full `FUN_00571e10` arity/ECX (not owned).
5. Some thiscall ECX targets decompiler-weak (roles sealed via prior duals).
6. Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00572360_FUN_00572360.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_RePlaceItems_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572360.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes_00572360.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_00572360_FUN_00572360.md` |
| Annotated | `docs/reconstruction/raw/aa_00572360_FUN_00572360.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |

**Sibling context (not owned):** SortAndRepack `0x00572730`; Place `0x00571620`; FindFree `0x005713a0`; CanPlace `0x00570840`; restore helper `0x00571e10`; cargo parent `0x005252f0`.

---

## AutoCore impact

- **HB end soft path:** after optional hard list-unlink, always soft-mark **`HB+0x20=1`** and clear **`HB+0x18`** owner link before SEH teardown (`ret 8`).
- **Inventory re-place:** implement CanPlace-at-origin then whole-grid FindFree (`page=-1`) then Place; type-4 skips search; null companion pointer fails fast; success path re-inits item RB empty and optionally reallocates cells when `flag==0` (e.g. SortAndRepack commit). Do not treat seed “inventory full message” name as authoritative.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`0050846f`, `00572360`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
| Avoid bare `undefined4` in clean | Yes (`uint32_t` / `uint8_t`) |
