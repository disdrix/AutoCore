# Review A (reconstruction fidelity): `aa_00941b20` Client_ConfirmEquipOrCustomizeItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941b20` |
| **VA** | `0x00941b20` |
| **Canonical name** | `Client_ConfirmEquipOrCustomizeItem` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (live Ghidra dual) |
| **Counterpart** | `reviews/B_aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ConfirmEquipOrCustomizeItem.cpp` |
| FUN scaffold | `docs/reconstruction/reconstructed-exact/FUN_00941b20.cpp` |
| Raw | `docs/reconstruction/raw/aa_00941b20_FUN_00941b20.md` |
| Annotated | `docs/reconstruction/raw/aa_00941b20_FUN_00941b20.annotated.md` |
| Function record | `docs/reconstruction/functions/aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md` |
| Live Ghidra | `decompile_function` `0x00941b20`; callees `0x004ce5f0` / `0x004fabc0` / `0x00931db0` / `0x00522020` / `0x005715d0` / `0x005714e0` / `0x00513fc0` / `0x00931440` / `0x00513e30` / `0x007fc270`; callers `0x00941d50` / `0x00861200` / `0x00911840@0x00912627`; `read_memory` prologue + permanent-dialog / success tail |

**Purpose:** Client pre-gate for equip / customize apply. Not skill-use (that is sibling arm in `Client_UseInventoryItem_Inferred`). On success, emits equip C2S via `FUN_00931440` (opcodes **0x203c** / **0x2053**).

---

## 2. Signature / ABI (sealed from call-site asm)

```text
; EAX = client (DAT_00d1a840 / ESI from UseInventoryItem)
; stack stdcall (RET 0xC):
;   [esp+4]  item*
;   [esp+8]  mode (uint32; inventory-window / equip-source selector)
;   [esp+C]  confirmFlag (char; 1 = may show permanent-customize modal)
; returns AL/EAX: 0 fail/defer, 1 success (equip packet sent)
```

Callers:

| Site | Context |
|---|---|
| `0x00941ddc` in `Client_UseInventoryItem_Inferred` | Non-skill item: `PUSH 1; PUSH mode; PUSH item; MOV EAX,ESI; CALL` |
| `0x00861222` in `FUN_00861200` | UI equip path: resolve item via vtable `+0x3ac`, mode from `*(window+0x56c)+4`, confirmFlag `1` |
| `0x00912627` in `Client_UiModalDispatch` case **0x4e58** | Permanent-customize **Yes**: `FUN_00513e30(1)` then `FUN_00941b20(client+0x3bf8, client+0x3bfc, 0)` then close modal |

`client+0x3bf8` ≡ `DAT_00d1e438`, `client+0x3bfc` ≡ `DAT_00d1e43c` (`0x00d1a840 + 0x3bf8/0x3bfc`).

---

## 3. Control flow (sealed)

```
Client_ConfirmEquipOrCustomizeItem(client, item, mode, confirmFlag):
  if client.char@+0xe98 == 0 OR char.vehicle@+0x250 == 0 OR item == null:
    return 0

  type = *(item[0x2a] /* cloneMeta */ + 0x38)

  // --- type 0xe town gate (string-sealed) ---
  if type == 0xe:
    ctx = item->vtbl[+0x1d4]()
    inTownish = FUN_004ce5f0(ctx)
    if !inTownish AND *(char+0x6b4) < 1:
      toast "This item can only be changed in town."  // dialog chrome EAX=0x4e24
      return 0

  // --- type 4 silent reject ---
  if type == 4:
    return 0

  FUN_007a69d0()  // string/table prep
  gridOrSlot = FUN_00522020(mode)   // mode 1→vehicle cargo grid @vehicle+0x2b0;
                                    // mode 3→char+0xcbc; mode 5→char+0xce0; else 0
  outEquipTarget = null
  reason = FUN_004fabc0(item, &outEquipTarget)  // equipability / class dispatch
  if reason != 0:
    FUN_00931db0()  // ShowEquipFailureMessage(reason) — town/space/unident/heavy/...
    return 0

  if outEquipTarget != null:
    if gridOrSlot == 0:
      FUN_007fc270(2)   // open / focus inventory UI (arg 2)
    else:
      sx = item->vtbl[+0x250](); sy = item->vtbl[+0x254]()
      if !FUN_005715d0(outEquipTarget, sx, sy, scratch)
         AND !FUN_005714e0(outEquipTarget, &sx, &sy, 1, -1):
        toast "There is not enough space in your inventory for this equipment."
        // EAX dialog chrome 0x4e24
        return 0

  // --- permanent customize confirm ---
  // item flags at item+0x17c == item[0x5f]; bit 20 (>>0x14)
  if confirmFlag != 0
     AND (item[0x5f] >> 20 & 1) == 0
     AND FUN_00513fc0(item[0x58], item[0x59]) != 0:   // owned/trade-bind probe
    client+0x3bf8 = item
    client+0x3bfc = mode
    modal Yes=0x4e58 / No=0x4e59:
      "Warning: This will permanently customize this item to you! ..."
    return 0   // deferred until Yes re-enters with confirmFlag=0

  FUN_00931440:  // ECX=client, EAX=item, stack=mode
    type 0xe → C2S 0x2053 size 0x10 (COID lo/hi @item+0x160/0x164)
    else     → C2S 0x203c size 0x40 (full TFID @+0x160..+0x16c + mode byte)
  return 1
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX=client; 3 stack args; `RET 0xC` | **Confirmed** | Call-site + epilogue asm |
| Gate: char@client+0xe98, vehicle@char+0x250, item≠null | **Confirmed** | Body + parent UseInventoryItem same pattern |
| Type `*(item[0x2a]+0x38)` branch 0xe / 4 / other | **Confirmed** | CF + type table family |
| Town-only string on type 0xe when `FUN_004ce5f0` false and `char+0x6b4 < 1` | **Confirmed** | String + CF |
| Type 4 → silent return 0 (no toast, no packet) | **Confirmed** | `!= 4` wraps whole equip body |
| `FUN_004fabc0` non-zero → `FUN_00931db0` equip-fail toast map | **Confirmed** | Callee decompile + reason enum strings |
| Space fail toast when both FindFree probes fail | **Confirmed** | String + `0x005715d0` / `0x005714e0` |
| Permanent customize bit20 `item+0x17c` / `item[0x5f]` | **Confirmed** | CF + `FUN_00513e30` xor mask `0x100000` |
| Modal Yes `0x4e58` / No `0x4e59` | **Confirmed** | Open: `MOV EAX,0x4e58` + stack `0x4e59`; dispatch cases |
| Staging `client+0x3bf8/0x3bfc` ≡ `DAT_00d1e438/43c` | **Confirmed** | Arithmetic + Yes handler |
| Yes path: set bit via `FUN_00513e30(1)`, re-call with confirmFlag=0 | **Confirmed** | `FUN_00911840` case 0x4e58 |
| Success `FUN_00931440` → C2S **0x203c** / **0x2053** | **Confirmed** | Callee decompile; S2C equip known as 0x203c recv |
| `FUN_00522020(mode)` inventory source selector | **High** | Modes 1/3/5 match DropResponse cargo/locker/trade grids |
| Product symbol name | **Tentative** | String-renamed; no RTTI |
| Semantic of type 0xe / 4 product names | **Probable** | 0xe = vehicle/chassis family; 4 = non-equippable/special |
| `char+0x6b4` semantic (town override counter?) | **Open** | Compared `< 1` only |
| `FUN_00513fc0` exact “must bind” predicate | **High** | Types 0xc/0x1c/0xa/0x10/0xe/(6 subtype 10/11) + owner vtbl+0x60 |
| Runtime wire of 0x203c/0x2053 from this path | **Open** | Static only |

---

## 5. Equip failure reason map (via `FUN_00931db0`, sealed strings)

| Code | Toast |
|---:|---|
| 0, 3 | (silent return) |
| 1 | This item can only be changed in town. |
| 2 | There is not enough space in your inventory for this equipment. |
| 4 | You cannot equip unidentified technology. |
| 5 | This equipment is too heavy for your vehicle. |
| 6 | This technology is too advanced for you to use. |
| 7 | This equipment does not match your vehicle's size requirements. |
| 8, 0xc | This item cannot be equipped. |
| 9 | You cannot equip a broken item. |
| 10 | This item must be swapped directly with another item. |
| 0xd | Cannot change this item while in Hazard Mode! |
| 0xe | You must remove everything from your vehicle first.! |
| 0xf | This equipment cannot be changed in an arena. |
| default | This equipment cannot be changed at this time. |

(`FUN_004fabc0` is the producer of these codes for the equip precheck.)

---

## 6. Relation to UseInventoryItem

Parent `0x00941d50` **rejects** type 0xe and broken bit19 before any arm. Equip arm only when `cloneMeta+0x3f2 & 0x80 == 0` (non-skill). Skill arm emits **0x2045** — **out of this seal**.

---

## 7. Gaps

1. Product / RTTI name for this function and for type 0xe / 4 classes.
2. Full field layout of C2S **0x203c** size 0x40 beyond COID block + mode byte (owned by `FUN_00931440`).
3. Semantic of `char+0x6b4` town bypass.
4. Runtime capture of equip packet from this path.
5. Exact meaning of `FUN_007fc270(2)` UI surface (inventory panel focus).

**Verdict:** **accept-with-gaps** — client equip/customize pre-gate + permanent-bind modal + success packet family sealed; product names and full 0x203c layout residual.
