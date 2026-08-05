# Annotated low-level: Client_RecvInventoryUnequipNotify (`aa_00813bf0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813bf0` |
| **VA** | `0x00813bf0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00813bf0_Client_RecvInventoryUnequipNotify.md` (capture 2026-07-23) |
| **System** | inventory-transfer |
| **Wire** | S2C **`0x203E`** size **`0x30`** (bidirectional opcode; C2S unequip shares number) |

---

## 1. Signature / registers

```c
// fastcall-ish decompile: param_1 = client; packet often in EAX as in_EAX
void __fastcall Client_RecvInventoryUnequipNotify(Client* client /*param_1*/);
// Packet base observed as in_EAX in body
```

### Packet fields (plate)

| Offset | Meaning |
|---:|---|
| `+0x08` | Item TFID |
| `+0x10` | Type/byte for resolve fallback |
| `+0x18` | Vehicle TFID (64-bit split) |
| `+0x20` | Lookup discriminator for `FUN_004bafe0` |
| `+0x28` | **destX** |
| `+0x29` | **destY** |
| `+0x2a` | **invType** destination |

---

## 2. Control flow

```text
log "Requesting InventoryUnequip: char:%I64d Old:%I64d"

vehicle = FUN_004bafe0(pkt+0x20, vehicleTfid...)
if vehicle == NULL:
  item = Object_ResolveFromTFID(itemTfid)
  if item: FUN_009440e0(item, 1, 0, -1, -1)   // force detach/drop visual
  return

// vehicle hardpoint / inventory owner chain
owner = *(*(vehicle+4)+4 + 0xb0 + vehicle)
if owner != NULL:
  charRef = owner.vtbl+0x1dc()
  if charRef == 0 OR charRef != client+0xe98: goto HARDPOINT_FALLBACK

  itemObj = Object_ResolveFromTFID(itemTfid)
  placed = FUN_00504f60(itemObj)          // may yield placeable wrapper
  if placed: placed.vtbl+0x2ac(client+0xd34)

  switch invType@+0x2a:
    case 0: break
    case 1: // cargo grid from vehicle+0x2b0 via char+0x250
            PlaceItemFootprint(item, destX, destY, 1)
            on fail: toast "This equipment cannot be changed at this time."
    case 2: FUN_0093d6e0(client, 1)       // hand / qty?
    case 3: // locker grid char+0xcbc + PlaceItemFootprint
    default: debug stop

  Client_RefreshOpenMissionUiWindows(client)
  if client+0x1078: FUN_008801b0; vfunc +0x34c
  return

HARDPOINT_FALLBACK:
  obj = CVOGReaction_ResolveObjectTarget(...)
  obj.vtbl+0x104(0)
  switch typeId at blob+0x38:
    6, 10, 0x0c, 0x10, 0x1c → equipment-specific unequip helpers
      (power plant, wheel, etc.)
  FUN_009440e0(...); FUN_0092f120()
```

---

## 3. Side-effect order

1. Debug log.
2. Resolve vehicle; soft path if missing.
3. Character ownership check vs `client+0xe98`.
4. **Place into cargo/locker** via `FUN_00571620` when invType 1/3.
5. UI refresh + paperdoll/inventory window update (`+0x1078`).
6. Or hardpoint teardown switch + `FUN_0092f120`.

---

## 4. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| Opcode 0x203E bidirectional | S2C notify ≠ C2S builder | **Confirmed** (plate) |
| `FUN_00571620` | Place into dest inventory | **Confirmed** |
| Type 10 power plant path | `Vehicle_EquipPowerPlant(..., NULL, ...)` clear | **High** |
| `0x3f4` short compares | Equipment subtype on clonebase | **Probable** |

---

## 5. Confidence / open

| Area | Level |
|---|---|
| Cargo/locker return path | **High** |
| Full hardpoint type switch | **High** (dual residual 2026-07-29: 6/10/0xc/0x10/0x1c → ornament/PP/melee/weapon/wheelset/armor) |
| C2S/S2C demux of 0x203E | **High** — directional (`PacketDispatch` vs `SendSectorPacket`); not body demux |
| Register identity of packet vs client | **Probable** (dual use of EAX/param_1 messy) |
| Runtime | Open |

Residual scratch: `reviews/a_00813bf0.md`
