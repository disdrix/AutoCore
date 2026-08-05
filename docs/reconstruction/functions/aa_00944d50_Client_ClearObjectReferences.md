# Function record: Client_ClearObjectReferences

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944d50` |
| **Canonical name** | `Client_ClearObjectReferences` |
| **Prior names** | `FUN_00944d50` |
| **Address** | `0x00944d50` |
| **Body** | `0x00944d50`–`0x00945367` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / object lifecycle / UI unbind |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-07-29 W17-H |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Client fan-out cleanup of all UI/client slots that reference a departing object. Clears sticky pointers, COID tree nodes, select chrome, inventory/mission bindings, selection targets; ends with `FUN_00996ff0(COID)`. Distinct from `VOGClient_CompletelyDestroyObject` (`0x009440e0`).

## Signature (sealed)

```c
void __thiscall Client_ClearObjectReferences(void *client, int *obj);
// ECX = client, stack = obj*, RET 4. Null obj → early return.
```

## Stage summary (sealed order)

1. Null guard  
2. Clear `client+0x3bf8` if match  
3. Optional related-object `FUN_00405920` via vfuncs `+0x1d4/+0x1d8`  
4. COID tree erase at `+0xd24/+0xd28`  
5. UI host `+0xf40` vtbl+0x444  
6. Selection/chrome (`+0x3048`, select widgets → `FUN_00837d50`, slots `+0x1088/+0x1068`)  
7. Misc panels (`+0x10cc`, `+0x1098`)  
8. Inventory/equip membership → `Client_RefreshOpenMissionUiWindows`  
9. Inventory sheets `+0x105c/+0x1060` → `FUN_0085fd20`  
10. Cargo/CBID panel `+0x10a0`  
11. Always `FUN_007fdab0` + `FUN_008027e0`  
12. Character class 0x0E path  
13. Selection list clear via `Object_SetSelectedTarget`  
14–18. Secondary clear, global dialog, list, panels, local-player panel  
19. `FUN_00996ff0(COID lo/hi)`  

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.md`
- Annotated: `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_ClearObjectReferences.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00944d50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00944d50_Client_ClearObjectReferences.md`
- Review B: `docs/reconstruction/reviews/B_aa_00944d50_Client_ClearObjectReferences.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `ClientSpecialEvent_Respawn_dtor`, `FUN_009791c0`, `FUN_009788b0` (+ DATA `0x00a2c2dc`) |
| **Named callees** | `Object_SetSelectedTarget`, `InventoryGrid_ContainsItem`, `Vehicle_HasEquippedTFID`, `UiSelectWidget_ApplySelectChrome`, `Client_UI_InventorySheet_RemoveByItem`, `Client_RefreshOpenMissionUiWindows` |
| **Other callees** | See raw / annotated list |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + RET 4 + null guard | **High** |
| Stage order / major branches | **High** |
| Client/object offsets listed | **High** (loads/stores in body) |
| Product method name | **Probable** (inferred; no string) |
| Full panel product types | **Tentative** |
| COID tree iterator decompiler noise | **Probable** (raw authoritative) |
| Runtime | Open |

## Dual A/B

| Review | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |
