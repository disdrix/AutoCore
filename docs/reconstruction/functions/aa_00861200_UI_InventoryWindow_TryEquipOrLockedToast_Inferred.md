# Function record: UI_InventoryWindow_TryEquipOrLockedToast_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00861200` |
| **Canonical name** | `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` |
| **Address** | `0x00861200`–`0x00861254` exclusive (**84 B** / `0x54`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Dual A/B complete (accept-with-gaps)** — MEGA-125 2026-08-05 |
| **Bit-for-bit / runtime / diff** | Open (static seal only; terminal false) |

## Alias

- Ghidra: `FUN_00861200`
- Twin record: `aa_00861200_FUN_00861200.md`
- Retired string scaffold: `Inv_This_equipment_cannot_be_changed_at_this_time_00861200` (string-only; not canonical)
- Partition hint: `UI_InventoryWindow_OnEquipCommand` — maps to **parent** `FUN_008612b0`; this unit is the equip confirm/locked-toast **leaf**

## Purpose

Leaf equip gate under the inventory window command handler:

1. **Ready path:** non-null item\* (ECX) and non-null `window+0x56c` (EAX window) → load mode `@slot+4` → `item->vtbl[+0x3ac](mode,1)` → dualed **`Client_ConfirmEquipOrCustomizeItem`** (`0x00941b20`, client `DAT_00d1a840`, confirmFlag=1).
2. **Blocked path:** missing item or mode slot → toast *“This equipment cannot be changed at this time.”* via locale helpers; chrome id **`0x4e24`**; return **0**.

Does **not** emit equip C2S itself (ConfirmEquip → `Client_SendInventoryEquipC2S`).

## Signature (register)

```c
// ECX = item* (selected / resolved inventory object)
// EAX = inventory window* (UI this from parent EDI)
// bare RET
// returns: ConfirmEquip result, or 0 on locked toast
uint32_t __fastcall UI_InventoryWindow_TryEquipOrLockedToast_Inferred(
    void* item, void* window);
```

## Key offsets / constants

| Location | Role |
|---|---|
| `window+0x56c` | Mode/state object\* (null → locked toast) |
| `*(window+0x56c)+4` | Mode dword (parent discriminates 1 / 3 / 4) |
| item `vtbl[+0x3ac]` | Resolve related object with `(mode, 1)` |
| `DAT_00d1a840` | Client singleton (ConfirmEquip EAX + toast host) |
| String @ `0x00a2cc74` | `"This equipment cannot be changed at this time."` |
| Chrome id `0x4e24` | Toast/modal id (shared family with ConfirmEquip town/space toasts) |

## Callers / callees

| Direction | Addr | Name / role |
|---|---|---|
| Caller ×1 | `0x008615f4` | Parent `FUN_008612b0` equip branch (`MOV ECX,EBX; MOV EAX,EDI`) |
| Callee | `vtbl[+0x3ac]` | Item resolve |
| Callee | `0x00941b20` | `Client_ConfirmEquipOrCustomizeItem` (dualed) |
| Callee | `0x007a69d0` | String pool |
| Callee | `0x007a6de0` | Localize |
| Callee | `0x007fdfb0` | Show toast/modal |

## Artifacts

- Raw (+ MEGA-125 re-verify): `docs/reconstruction/raw/aa_00861200_FUN_00861200.md`
- Annotated: `docs/reconstruction/raw/aa_00861200_FUN_00861200.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_TryEquipOrLockedToast_Inferred.cpp`
- Clean (FUN twin): `docs/reconstruction/reconstructed-exact/FUN_00861200.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md`
- Report: `docs/agents/task-dual-ab-00861200-mega-125-report.md`
- Legacy string scaffold (retired): `docs/reconstruction/reconstructed-exact/Inv_This_equipment_cannot_be_changed_at_this_time_00861200.cpp`

## Confidence

| Claim | Level |
|---|---|
| CF + body span + string + chrome `0x4e24` | **Confirmed** |
| ECX=item\*, EAX=window\*, bare RET | **Confirmed** |
| Forward to dualed ConfirmEquip | **Confirmed** |
| Stack dual-use / caller-clean `vtbl[+0x3ac]` | **High** (balance + peer sites) |
| Product window class / mode English / vtbl method | **Open** → `_Inferred` |
| Runtime / bit-exact / differential | **Open** |
