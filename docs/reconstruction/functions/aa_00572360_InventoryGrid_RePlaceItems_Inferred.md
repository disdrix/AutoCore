# Function record: InventoryGrid_RePlaceItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572360` |
| **Canonical name** | `InventoryGrid_RePlaceItems_Inferred` |
| **Ghidra name** | `FUN_00572360` |
| **Address** | `0x00572360` |
| **Body** | `0x00572360`–`0x00572595` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B complete** (2026-07-29 W21-B) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Re-place / commit inventory items on a grid: walk enumeration, CanPlace at saved origin or FindFree (page `-1`), PlaceItemFootprint; success clears item RB (+ optional cell realloc); fail restores via `FUN_00571e10` and returns 0.

## Signature (image-sealed)

```c
// __thiscall ECX=InventoryGrid*, stack relatedPtr + flag, ret 8
// returns 1 success / 0 fail; relatedPtr==null → 0
uint32_t InventoryGrid_RePlaceItems_Inferred(
    void *thisGrid,
    void *relatedPtr,
    char flag);
```

## Artifacts

| Role | Path |
|---|---|
| Raw scaffold + W21-B re-verify | `docs/reconstruction/raw/aa_00572360_FUN_00572360.md` |
| Annotated | `docs/reconstruction/raw/aa_00572360_FUN_00572360.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_RePlaceItems_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572360.cpp` |
| Legacy seed alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes_00572360.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00572360_InventoryGrid_RePlaceItems_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00572360_FUN_00572360.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x00572a4f` | `InventoryGrid_SortAndRepack_Inferred` success commit |
| Caller | `0x005253c7` / `…406` / `…5a8` | `FUN_005252f0` cargo resize (×3) |
| Caller | `0x00521ea3` | `FUN_00521e90` wrapper flag=1 |
| Callee | `0x00570840` | `InventoryGrid_CanPlace` |
| Callee | `0x005713a0` | `InventoryGrid_FindFreeSlot` (page `-1`) |
| Callee | `0x00571620` | `InventoryGrid_PlaceItemFootprint` |
| Callee | `0x00570720` family | `InventoryGrid_AllocateCellArray_Inferred` |
| Callee | `0x005731c0` | RB node free |
| Callee | `0x00571e10` | fail/success restore helper |
| Callee | list helpers | `FUN_004294f0`, `FUN_004022a0`, `FUN_00573810`, `FUN_004bc580` |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Walk / CS region base | `this+0x2c` | High |
| Grid CS / held | `+0x30` / `+0x54` | High |
| Item RB / count | `+0x60` / `+0x64` | High |
| Item type field | `item[0x2a]+0x38` (4 = skip CanPlace/FindFree) | High |
| InvSize bytes | clonebase `+0x406` / `+0x407` | High |
| Item vfuncs | `+0x250`, `+0x254`, `+0x25c` | High |

## Confidence

| Claim | Level |
|---|---|
| ABI ret 8 + null related → 0 + returns 0\|1 | High |
| Place / CanPlace / FindFree roles | High (prior duals + body) |
| Success RB clear + optional AllocCell | High (CF) |
| Product name | Tentative (`_Inferred`) |
| relatedPtr exact type / 571e10 full ABI | Tentative |
| Why success empties RB after Place | Open (intent) |
| Runtime / bit-exact | Open |
