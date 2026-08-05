# Annotated low-level: Client_RecvInventoryEquip (`aa_00813f40`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **VA** | `0x00813f40` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00813f40_Client_RecvInventoryEquip.md` (capture 2026-07-23) |
| **System** | inventory-transfer |
| **Wire** | S2C **`0x203C`** size **`0x40`**; no C2S 0x203C builder (equip via Drop type hardpoint=2) |
| **Residual** | 2026-07-29: opcode/ABI + dual-path hardpoint class map (incl. wheelset) sealed; helper slot stores confirmed |

---

## 1. Packet fields (plate)

| Offset | Meaning |
|---:|---|
| `+0x08` | New item TFID (COID lo/hi) |
| `+0x10` | New item **global flag** (also non-local `ResolveObjectTarget` first arg) |
| `+0x18` | Vehicle TFID |
| `+0x20` | Vehicle global/realm for `FUN_004bafe0` |
| `+0x28` | Old item TFID / COID pair |
| `+0x38` | **putInHand** (1 = hand path) |
| `+0x39` | **srcX** (grid origin when not hand) |
| `+0x3a` | **srcY** |
| `+0x3b` | **invTypeFrom** |

Registers: packet as stack arg (`PUSH ESI` @ dispatch); client as `in_EAX` (`MOV EAX,EBP` @ `0x0081597a`).

---

## 2. Control flow

```text
log "Requesting InventoryEquip: char Old New TFIDs"

vehicle = FUN_004bafe0(realm@+0x20, id@+0x18/+0x1c)
if vehicle == NULL:
  if resolve item: FUN_009440e0(item,...); return
  // else fall out

owner = vehicle hardpoint owner chain (+0xb0 → vfunc +0x1dc)
if owner and owner.char == client+0xe98:
  if putInHand == 1:
    handObj = CVOGReaction_ResolveObjectTarget(1, itemCoid...)
  else if vehicle+0x2b0:
    handObj = FUN_00571010(itemCoid); FUN_00571b80(handObj, 1, 0)  // unstamp

  equipped = FUN_00502e90(vehicle /*this*/, handObj)  // FULL class equip

  // cargo UI dirty checks client+0x1040→+0x50c

  if equipped == NULL:
    if putInHand && oldCoid is empty FFs: FUN_007fc150()  // clear cursor
  else if putInHand:
    FUN_007fc270(invTypeFrom)
  else:
    // place previous/out or item into grid at srcX/srcY
    FUN_00571620(equipped, srcX, srcY, 1)

  refresh windows client+0x1078 / +0x104c via FUN_008801b0
  client+0x30b4 = 1; client+0x30b5 = 0
  if client+0x309c: vfunc+4(0)
  return

// non-local hardpoint type switch (types 6,10,0x0c,0x10,0x1c)
// ornament / plant / weapon / WHEELSET / armor; scale 1.0f;
// FUN_009440e0 previous; FUN_0092f120
```

---

## 3. Side-effect order

1. Log.
2. Resolve vehicle / item.
3. Ownership gate to local character.
4. Pull item from hand or cargo (`FUN_00571b80` unstamp).
5. **`FUN_00502e90` equip** (local hardpoint class dispatcher).
6. Cursor / grid place (`PlaceItemFootprint` when not putInHand).
7. UI flags + window refreshes.
8. Alternate: type-switch hardpoint equip for non-local objects (same helpers).

---

## 4. Dual-path hardpoint class map (sealed 2026-07-29)

Local (`FUN_00502e90`) and non-local switch share helpers. Slots sealed from helper bodies (not plate guess).

| Class | Helper | Slot | Evidence |
|---:|---|---|---|
| 6 + subtype 10 | `FUN_004fe620` | `+0x26c` | helper store + `"Set ornament of unhappy type…"` |
| 6 + subtype 0xb | `Vehicle_SetEquippedRaceItem` | race | **local only** |
| 10 | `Vehicle_EquipPowerPlant` | plant | named + RTTI `CVOGPowerPlant` |
| 0xc + subtype 9 | `FUN_004fe800` | `+0x264` | helper store + `"Set weapon melee of unhappy type…"` |
| 0xc else | `FUN_004fe110` → `Vehicle_AttachWeapon` | `+0x260` | array + `"Tried to equip same weapon %d"` |
| **0x10** | **`FUN_004ff510` → `Vehicle_SetWheelset`** | **`+0x258` (600)** | helper + wheelset strings + RTTI `CVOGWheelSet` |
| 0x1c | `FUN_00502180` → `Vehicle_SetEquippedArmor` | `+0x254` | helper + `"Tried to equip same armor %d"` |

---

## 5. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| Opcode 0x203C | Sole PacketDispatch xref `0x0081597c` | **Confirmed** |
| Framing EAX client + stack packet | Call site image bytes | **Confirmed** |
| No C2S 0x203C | Equip via drop-to-hardpoint | **High** |
| `putInHand` at +0x38 | Controls hand vs grid source | **Confirmed** |
| Local path hardpoint equip | Via `FUN_00502e90`, not UI-only | **High** |
| Class 0x10 wheelset | In this switch (not open elsewhere only) | **High** |
| `FUN_00571620` place path | Grid place after equip when not putInHand | **High** |
| `0x3f800000` | 1.0f visual scale | **Confirmed** |
| RTTI cast in case 6 | Graphics simple-object path | **High** |
| `+0x10` global flag vs “type hint” | Same TFID byte; resolve consumes it | **High** |

---

## 6. Confidence / open

| Area | Level |
|---|---|
| Local character equip happy path | **High** |
| Non-local class map (incl. wheelset) | **High** |
| Product FUN_* renames | Open / Probable roles |
| Runtime / differential | Open |
