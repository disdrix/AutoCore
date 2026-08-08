# Function record: Item_RequiresBindOrTradeLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513fc0` |
| **Canonical name** | `Item_RequiresBindOrTradeLock` |
| **Ghidra name** | `FUN_00513fc0` |
| **Address** | `0x00513fc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Parent dual / context** | `Client_ConfirmEquipOrCustomizeItem` `0x00941b20` (MEGA-050 partition) |
| **Completion status** | **Dual A/B complete — accept-with-gaps** (2026-08-05 MEGA-050) |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal **false**) |

## Alias

- Ghidra: `FUN_00513fc0`
- Twin record: `aa_00513fc0_FUN_00513fc0.md`
- **Retired:** `Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0`

## Purpose

Client inventory predicate answering: “Does this item require permanent bind / customize / trade-lock handling?” Used before permanent-customize modal (equip + click paths), for `"Customizes On Equip"` UI, and to auto-set `ItemFlag_Customized` on vehicle-switch failure when the probe returns true.

## Signature

```c
bool __thiscall Item_RequiresBindOrTradeLock(
    Item *item /*ECX*/,
    uint32_t coid_lo,   // item+0x160
    uint32_t coid_hi);  // item+0x164
// RET 8
```

## Closed form

```text
obj = ResolveObjectTarget(*( *(item+0xa4) + 0xe4e8 ), 1, coid_lo, coid_hi)
if !obj: false
if type(obj) not eligible: false
if obj.vtbl[0x60]() != 0: true
return (int16)(cloneblob+0x4b8) >= 2
```

**Type eligible:** `{0xc, 0x1c, 0xa, 0x10, 0xe}` **or** `(type==6 && subtype∈{10,11})` at `blob+0x3f4`.

## Not this unit

| Role | VA |
|------|-----|
| Set Customized bit20 | `0x00513e30` `Item_SetCustomized` |
| Equip pre-gate / modal host | `0x00941b20` |
| Stack eligibility | `0x00513e70` |
| Stack capacity | `0x0040abf0` |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_RequiresBindOrTradeLock.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513fc0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00513fc0_Item_RequiresBindOrTradeLock.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00513fc0_Item_RequiresBindOrTradeLock.md` |
| Report | `docs/agents/task-dual-ab-00513fc0-mega-050-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / boundary / ABI | **Confirmed** (static) |
| Role vs mutator/packet | **Confirmed** (static) |
| Product symbol / type English | Tentative |
| Runtime wire | Open |
