# Annotated low-level: Client_SendInventoryGrab_FromGrid (`aa_00860e20`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **VA** | `0x00860e20` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00860e20_Client_SendInventoryGrab_FromGrid.md` (capture 2026-07-23; re-decompile 2026-07-29 matches) |
| **System** | inventory-transfer |
| **Wire** | C2S opcode **`0x2034`**, send size **`0x20`** |
| **S2C peer** | GrabResponse `0x2035` (not this unit). Drop side closes via DropResponse type switch — see link §7 |
| **Call xrefs** | `0x0083e677`, `0x00861a98`, `0x00861b3c` (asm residual 2026-07-29) |

---

## 1. Signature (recovered)

```c
// Stack args + EDI = selected object / cursor host (call-site sealed register)
uint32_t Client_SendInventoryGrab_FromGrid(
    UIWindow* invWindow,     // param_1 — provides inventory type at +0x56c
    uint32_t quantity);      // param_2 — whole-stack or partial-split request count → +0x1c
// EDI: selection host; vfunc +0x3ac → item with TFID at +0x160/+0x164 and +0x168 byte
// Callers: qty via item vfunc +0x25c or field +0x4fc; MOV EDI,host then CALL
```

| Name | Width | Role | Confidence |
|---|---|---|---|
| `invWindow` | ptr | Source window; type byte at `*(window+0x56c)+4` | **High** (call-site PUSH) |
| `quantity` | u32 | Grab / split request → packet `+0x1c` (`lQuantity`) | **Confirmed** |
| `EDI` host | ptr | Selection host; vfunc `+0x3ac` → payload object | **High** (call-site `MOV EDI,host`) |
| **return** | u32 | Always **1** in this capture (even busy-skip) | **Confirmed** |

---

## 2. Packet layout (stack buffer `auStack_20`, size arg `0x20`)

### Decompile evidence (raw body)

| Stack name | Packet offset | Write | Source |
|---|---:|---|---|
| `auStack_20[0]` | `+0x00` | `0x2034` | literal opcode |
| *(unwritten)* | `+0x04` | **not written** | leftover stack / not filled by FromGrid |
| `uStack_18` | `+0x08` | `*(item+0x160)` | TFID / COID lo |
| `uStack_14` | `+0x0c` | `*(item+0x164)` | TFID / COID hi |
| `uStack_10` | `+0x10` | `*(item+0x168)` | TFID global / flags byte |
| *(unwritten)* | `+0x11..+0x17` | **not written** | pad |
| `uStack_8` | `+0x18` | `*(*(window+0x56c)+4)` | **`ucTypeFrom`** |
| *(unwritten)* | `+0x19..+0x1b` | **not written** | pad |
| `uStack_4` | `+0x1c` | `param_2` | **`lQuantity`** |

Send: `conn.vtbl+0x18(0xFFFFFFFF, &auStack_20, **0x20**, 0)` when `g_pSectorNetConnection_INFERRED != NULL`.

### Sealed map (decompile + retail struct)

Aligned to `Documentation/PACKET STRUCTURES.md` `SMSG_Sector_InventoryGrab` (Id=5653, Size=`0x20`) and server `InventoryGrabPacket`:

| Offset | Size | Field | Evidence |
|---:|---:|---|---|
| `+0x00` | u32 | Opcode **`0x2034`** | Immediate `auStack_20[0] = 0x2034` |
| `+0x04` | 4 | Unused by this builder | Not written in body (docs call “transaction ID”; **FromGrid leaves garbage**) |
| `+0x08` | 8 | `fidItem` COID | item `+0x160/+0x164` via dual `vtbl+0x3ac` resolve |
| `+0x10` | u8 | Item global / TFID byte | item `+0x168` (server `ItemGlobal`) |
| `+0x11` | 7 | Pad | Unwritten |
| `+0x18` | u8 | **`ucTypeFrom`** | `*(window+0x56c)+4` |
| `+0x19` | 3 | Pad | Unwritten |
| `+0x1c` | i32 | **`lQuantity`** | stack `param_2` |

**Opcode / size confidence: Confirmed** (live Ghidra re-decompile 2026-07-29 identical to raw capture).

---

## 3. Control flow

```text
if EDI != NULL:
  item = EDI.vtbl+0x3ac()
  if item==0 OR g_active==0 OR item == g_active[0x146]:
    DAT_00d1d8f4 = 1
    DAT_00d1d8f5 = 0
    if g_active: g_active.vtbl+4(0)     // UI deselect / clear

FUN_007fbbb0()                          // pre-send UI/helper

if DAT_00d1a8f6 == 0:                   // not already in-flight
  build packet 0x2034 as above
  if g_pSectorNetConnection != NULL:
    conn.vtbl+0x18 (0xFFFFFFFF, &pkt, 0x20, 0)   // send
  DAT_00d1b4b0 = 1
  DAT_00d1a8f6 = 1                      // in-flight lock
return 1
```

---

## 4. Side-effect order

1. Optional UI clear of active selection (`DAT_00d1d8dc` path).
2. `FUN_007fbbb0`.
3. Conditional **network send** 0x20 bytes via sector connection vtable `+0x18`.
4. Set globals `DAT_00d1b4b0`, `DAT_00d1a8f6` (request outstanding).
5. If `DAT_00d1a8f6` already set: **no send**, still return 1.

Does **not** place into a grid — wait for S2C GrabResponse; subsequent Drop uses DropToGrid → DropResponse.

---

## 5. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `unaff_EDI` | Caller-owned register arg (item host) | **High** |
| `0x2034` / size `0x20` | Grab C2S | **Confirmed** |
| `g_pSectorNetConnection_INFERRED` | Sector net conn singleton | **Probable** name |
| Type from `window+0x56c` | Inventory type enum (1 cargo, 3 locker, …) | **High** |
| item`+0x168` | TFID global byte (`ItemGlobal`) | **High** (server + struct) |

---

## 6. Pack vs split duties

| Stage | Owner |
|---|---|
| Pack `lQuantity@+0x1c` | **this unit** |
| Choose whole vs partial count | UI caller (GetQty `+0x25c` / field `+0x4fc`) |
| Peel stack / SplitCoid / cursor | GrabResponse `aa_00811be0` (`splitFlag@+0x20`) |
| Place into grid | Drop / DropResponse |

FromGrid **does not** compare request qty to source qty and **does not** peel stacks.

### Sibling pack note (Hardpoint `0x00862d90`)

Hardpoint writes type **literal 2** at `+0x18`, **omits** `+0x1c`, sends via `Client_SendSectorPacket`. Server equip path may reinterpret unwritten `+0x04/+0x14` — not FromGrid.

---

## 7. Confidence / open

| Area | Level |
|---|---|
| Opcode/size | **Confirmed** |
| Qty + typeFrom sources | **Confirmed** / **High** |
| Full 0x20 field map (written fields) | **Confirmed** |
| Caller ABI (window, qty, EDI host) | **High** |
| `+0x04` “transaction ID” meaning | **Open** — not written by FromGrid |
| Parent names at 3 xrefs | **Open** (addresses not in named funcs) |
| Runtime grab capture | **Open** |

---

## 8. Link: DropResponse `inventoryType` switch (already documented)

Grab’s `ucTypeFrom` (`+0x18`) selects **source** inventory. After grab, a drop writes `ucTypeTo` at Drop C2S `+0x1a`; the S2C peer resolves the **destination** grid with the same type enum:

| Artifact | Path |
|---|---|
| DropResponse annotated switch | [`raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md`](aa_00813730_Client_RecvInventoryDropResponse.annotated.md) § inventoryType switch |
| DropResponse clean | `reconstructed-exact/Client_RecvInventoryDropResponse.cpp` |
| System map | `systems/inventory-transfer.md` § DropResponse packet |
| Wire RE | `docs/inventory-cargo-wire-re.md` § Locker (type 3) |

| `inventoryType` | DropResponse grid binding (summary) |
|---:|---|
| **1** | Cargo: vehicle `char+0x250` → `vehicle+0x2b0` |
| **3** | Locker: `char+0xcbc` |
| **5** | Trade: `char+0xce0` |
| **6** | Other object inventory via TFID |
| default / **2** | Invalid → error toast (hardpoint uses equip path, not DropResponse place) |

Server sequence for cargo↔locker: **Grab (`0x2034`, typeFrom 1\|3) → GrabResponse → Drop (`0x2036`, typeTo 1\|3) → DropResponse (`0x2037`)** with place via `FUN_00571620`.
