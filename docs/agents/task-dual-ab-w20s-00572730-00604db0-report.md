# Dual A/B report — W20-S OWN-ONLY (`0x00572730`, `0x00604db0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W20-S  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x00572730`, `0x00604db0` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_xrefs`). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x00572730` | `InventoryGrid_SortAndRepack_Inferred` | **accept-with-gaps** |
| `0x00604db0` | `CVOGHBBase_SetPartnerLink` | **accept** |

---

## VA `0x00572730` — InventoryGrid_SortAndRepack_Inferred

### Sealed facts

1. **ABI:** `__thiscall` ECX = grid; stack `compareFn*`, `compareCtx`; **`RET 8`**. Returns **1** success / **0** fail.
2. **Adjusted-null:** `lea esi,[this+0x2c]; cmp esi,0` → `this == 0xFFFFFFD4` returns **0** (bytes @ entry).
3. **Temp grid:** `operator_new(0x68)` + `InventoryGrid_ctor_Inferred` with this **`+0x08/+0x0c/+0x14`**.
4. **Clear this item RB** at **`+0x60`** (`FUN_005731c0` left subtree); reinit sentinel; count **`+0x64 = 0`**.
5. **Selection-sort loop:** pick best under `compareFn(ctx, cand, best)`; type **`item[0x2a]+0x38 == 4`** → origin (0,0); else **`InventoryGrid_FindFreeSlot(..., page=-1)`**; then **`InventoryGrid_PlaceItemFootprint`**.
6. **Fail** → `FUN_00571e10(0,0)`, destroy temp, **return 0**. **Success** → `AllocateCellArray(this)`, `FUN_00572360`, destroy temp, **return 1**.
7. **Callers (only):** `FUN_00572ed0` → cmp `FUN_00572f30`; `FUN_00572ef0` → cmp `LAB_00572fe0`.
8. Live decompile **≡** 2026-07-23 raw (no CF delta).

### Gaps

1. Product C++ name (`_Inferred`).
2. Decompiler residual on some thiscall ECX targets (which list/grid per helper).
3. `FUN_00572360` source-list arg (decomp shows `0`; callee null-guards).
4. `FUN_00571e10` fail-restore contract (not owned).
5. Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00572730_FUN_00572730.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_SortAndRepack_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572730.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_00572730_FUN_00572730.md` |
| Annotated | `docs/reconstruction/raw/aa_00572730_FUN_00572730.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |

**Sibling context (not owned):** wrappers `0x00572ed0` / `0x00572ef0`; FindFree `0x005713a0`; Place `0x00571620`; commit `0x00572360`.

---

## VA `0x00604db0` — CVOGHBBase_SetPartnerLink

### Sealed facts

1. **ABI:** `__thiscall` ECX = HB; stack partner*; **`RET 4`**; void leaf.
2. **Bytes (complete body):**  
   `8B442404 85C0 7408 8B5018 3B5118 7403 894124 C20400`
3. **Semantics:**  
   `if (partner==null || partner[+0x18] != this[+0x18]) this[+0x24] = partner;`  
   else leave `+0x24` unchanged.
4. **Fields:** `+0x18` owner (AttachOwner family); `+0x24` partner HB.
5. **Callers (only):** `Object_SetSelectedTarget` @ `0x005173b6` and `0x005173be` (both-ways cross-link after dual `new(0x28)` targeting HBs).
6. **Callees:** none.
7. Live decompile **≡** raw; full CF byte-sealed.
8. **Rename:** scaffold DriveControlTick seed name **superseded**.

### Gaps

1. Product C++ method name (family inferred).
2. Runtime golden of partner pair.
3. Whether same-owner skip is hit in retail (defensive residual).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Function record | `docs/reconstruction/functions/aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00604db0_FUN_00604db0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBBase_SetPartnerLink.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00604db0.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604db0.cpp` |
| Raw + re-verify | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00604db0_CVOGHBBase_SetPartnerLink.md` |

**Sibling context (not owned):** `Object_SetSelectedTarget` `0x005172d0`; `CVOGHBPlayerTargetingLink_ctor` `0x00512090`; targeting base ctor `0x00604d40`.

---

## AutoCore impact

- **Inventory sort:** implement comparator-driven repack via **temp same-size grid**, type-4 fixed (0,0), whole-grid FindFree (`page=-1`), clear item tree before reorder; do not assume in-place cell swaps.
- **Target HB pairing:** when setting selected target, cross-link partners at **HB+0x24** with **owner(+0x18) gate**; clear always allowed; same-owner non-null skips overwrite.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`00572730`, `00604db0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
