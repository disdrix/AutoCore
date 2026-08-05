# Function record: Client_ConfirmEquipOrCustomizeItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941b20` |
| **Canonical name** | `Client_ConfirmEquipOrCustomizeItem` |
| **Address** | `0x00941b20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B complete (accept-with-gaps)** — 2026-07-29 live Ghidra seal |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Alias

- Ghidra: `FUN_00941b20`
- Twin record: `aa_00941b20_FUN_00941b20.md`
- NAMING_REGISTRY: equip/customize confirms

## Purpose

Client equip / customize **pre-gate** for non-skill inventory items. Town/space/equipability checks, optional permanent-customize modal (`0x4e58`/`0x4e59`), then C2S equip via `FUN_00931440` (**0x203c** / **0x2053**). Sibling of skill-use arm in `Client_UseInventoryItem_Inferred` (**0x2045**).

## Signature (register + stack)

```c
// EAX = client*
// stdcall stack:
//   item*, mode (uint32), confirmFlag (char)
// returns uint32: 0 = fail/defer, 1 = equip packet sent
uint32_t Client_ConfirmEquipOrCustomizeItem(void* item, uint32_t mode, char confirmFlag);
```

## Key offsets / constants

| Location | Role |
|---|---|
| `client+0xe98` | Local character |
| `char+0x250` | Vehicle |
| `char+0x6b4` | Town bypass int (`>=1` allows type-0xe out of town) |
| `item[0x2a]+0x38` | Clone/object type (`0xe` town-gated; `4` silent reject) |
| `item[0x5f]` / `item+0x17c` | Flags; bit20 = permanent-customize already accepted |
| `item[0x58]/[0x59]` | COID halves into `FUN_00513fc0` |
| `client+0x3bf8` / `+0x3bfc` | Staged item* / mode for modal Yes (`DAT_00d1e438` / `DAT_00d1e43c`) |
| Modal Yes / No | `0x4e58` / `0x4e59` |
| Toast chrome id | `0x4e24` (town + space strings) |
| Success packets | type `0xe` → **0x2053** size `0x10`; else **0x203c** size `0x40` |

## Callers / callees

| Direction | Addr | Name / role |
|---|---|---|
| Caller | `0x00941d50` | `Client_UseInventoryItem_Inferred` equip arm (`confirmFlag=1`) |
| Caller | `0x00861200` | UI equip path |
| Caller | `0x00911840` @ `0x00912627` | Modal Yes `0x4e58` re-entry (`confirmFlag=0`) |
| Callee | `0x004ce5f0` | Town/in-garage probe |
| Callee | `0x004fabc0` | Equip precheck → reason code |
| Callee | `0x00931db0` | `Client_ShowEquipFailureMessage` |
| Callee | `0x00522020` | Mode → inventory grid/slot |
| Callee | `0x005715d0` / `0x005714e0` | Space / FindFreeForItem |
| Callee | `0x00513fc0` | Permanent-bind needed? |
| Callee | `0x00513e30` | Set/clear bit20 (from Yes handler) |
| Callee | `0x007fc270` | Inventory UI open/focus when no grid |
| Callee | `0x00931440` | Emit equip C2S |
| Callee | `0x007a6de0` / `0x007fdfb0` | Localize + modal/toast |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00941b20_FUN_00941b20.md`
- Annotated: `docs/reconstruction/raw/aa_00941b20_FUN_00941b20.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ConfirmEquipOrCustomizeItem.cpp`
- Clean (FUN scaffold): `docs/reconstruction/reconstructed-exact/FUN_00941b20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md`

## Confidence

| Claim | Level |
|---|---|
| ABI (EAX client + 3 stack + RET 0xC) | **Confirmed** |
| Multi-gate CF + three string toasts | **Confirmed** |
| Modal 0x4e58/0x4e59 + staging fields | **Confirmed** |
| Success opcodes 0x203c / 0x2053 | **Confirmed** (via callee) |
| Product symbol | Tentative |
| Runtime wire | Open |
