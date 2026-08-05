# Annotated low-level: Client_RecvInventoryAddItem (`aa_008151a0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008151a0` |
| **VA** | `0x008151a0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_008151a0_Client_RecvInventoryAddItem.md` (capture 2026-07-23) |
| **System** | inventory-transfer |
| **Wire** | S2C **`0x2047`** (`Client_PacketDispatch` case → this VA; body has no opcode load) |

---

## 1. Calling convention

```c
// param_1 = client (stack); EBX = packet base (prologue [ebx+8]/[ebx+0xc])
void Client_RecvInventoryAddItem(Client* client /*param_1*/);
```

### Packet fields used

| Offset | Type | Role |
|---:|---|---|
| `+0x08/+0x0c` | u32×2 | Item COID / TFID halves for resolve |
| `+0x10/+0x11` | u8×2 | Wire cargo X/Y — **not read** by this body |
| `+0x12` | u8 | `bAddToExistingItem` — non-zero + in-grid → `FUN_00571830` merge |
| `+0x14` | i32 | **Quantity** (loot string `x%d` if ≥2 and helper ok) |
| `+0x18` | u8 | **Master enable** — if 0, function returns after resolve attempt without add |

---

## 2. Control flow

```text
FUN_007a69d0()
item = CVOGReaction_ResolveObjectTarget(1, coidLo, coidHi)
if item == NULL: return

if pkt[+0x18] == 0: return            // disabled / non-event

// loot toast if DAT_00d1b8dc (chat/combat log host)
if DAT_00d1b8dc:
  build "Received Loot: [Broken: ]name[ xN]"
  // bit 19 of item[0x5f] → "Broken: " prefix
  FUN_008f8200(host, 0x17, empty, msg, 0)

// optional loot window feed: client+0xf38 open?
if client+0xf38 open && +0xcb8:
  that.vtbl+0x3ac(item)

// placement
if pkt[+0x12]==0 OR no character OR no vehicle OR
   FUN_00571010(coid) already exists == 0:
  FUN_00945540(client)                 // generic add / re-find path
else:
  FUN_00571830(qty, coidLo, coidHi)    // cargo-aware place helper

if DAT_00d1b894 open: FUN_0089c6c0(1)
FUN_0092ce90()
return
```

---

## 3. Side-effect order

1. Resolve existing world/item object by COID (must already exist).
2. Optional **loot chat** line.
3. Optional loot UI inject.
4. **Inventory place** via one of two helpers (not direct `PlaceItemFootprint` in this function).
5. Secondary UI (`FUN_0089c6c0`, `FUN_0092ce90`).

Does not itself stamp cells; callees own first-fit / keep-position.

---

## 4. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `unaff_EBX` | Packet | **High** |
| `param_1` | Client | **High** |
| `item[0x5f] >> 19 & 1` | Broken/degraded loot prefix | **Probable** |
| `FUN_00571830` | Cargo place with qty + COID | **High** |
| `FUN_00945540` | Fallback inventory add on client | **Probable** |
| Empty string `DAT_00a1419b` | Zero-length prefix when not broken | **High** |

---

## 5. Confidence / open

| Area | Level |
|---|---|
| Loot toast formatting | **High** |
| Dual place helpers | **High** |
| Exact opcode id in dispatch table | **Probable** (see system map / 0x2047) |
| Full packet size | **Open** |
