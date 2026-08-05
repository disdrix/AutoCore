# Annotated low-level: Client_UI_InventoryDropToGrid (`aa_00860a50`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **VA** | `0x00860a50` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00860a50_Client_UI_InventoryDropToGrid.md` (capture 2026-07-23; re-decompile 2026-07-29 matches) |
| **System** | inventory-transfer |
| **Wire** | C2S **`0x2036`** size **`0x20`** (grid drop); store path size **`0x40`** opcode **`0x2027`** (`'\''` + `' '`) |
| **S2C peer** | DropResponse `0x2037` — type switch already documented; see §7 |

---

## 1. Signature

```c
// this / in_EAX: inventory UI window object
uint32_t Client_UI_InventoryDropToGrid(void /*EAX=window*/);
// returns 1 on send success / busy soft-OK; 0 on reject
```

| Register / state | Role |
|---|---|
| `EAX` (`in_EAX`) | Drop target UI window |
| `DAT_00d1b6d8` | Global client / sector context (null → fail) |
| `DAT_00d1b1f8` | Cursor / grabbed object host |
| `DAT_00d1a8f6` | In-flight inventory request flag (shared with grab) |

---

## 2. Control flow (high level)

```text
if DAT_00d1b6d8 == 0: return 0

// resolve drop cell coords
ok = FUN_0085f220(&x, &y, &local_104)
if !ok: return 0

invType = *(i32*)(window[0x15b] + 4)   // target inventory type
// 0x15b dwords → offset 0x56c (matches grab path window+0x56c)

// reject dropping type-4 (vehicle part?) items into non-cargo/locker
// (types not 1/3) — NOT an exclusive allow-list of only 1/3
if invType not in {1,3}:
  item = cursor.vtbl+0x3ac()
  if item.blob+0x38 == 4: return 0

// trade (type 5) gates
if invType == 5 and item.flags bit 20: toast "customized to you"; fail
if invType == 5 and clone+0x4be != 0: toast "cannot trade this"; fail

// optional bind vehicle context window[0x15d]
if window[0x15d] && *(+0x2b0): window.vtbl+0xb0(vehicle)

if DAT_00d1a8f6 != 0: return 1          // already in-flight: pretend OK

item = cursor.vtbl+0x3ac()
if item == 0: error "not found"; return 0

// build & send:
//  A) store/vendor special: size 0x40, opcode 0x2027, richer fields
//  B) normal grid drop: size 0x20, opcode 0x2036, x/y/type in packet
Client_SendSectorPacket(&DAT_00d1a840, size, buf)
DAT_00d1a8f6 = 1
return 1
```

---

## 3. Normal drop packet (size `0x20`) — decompile field map

Buffer base = `acStack_100`. Grid branch (not type-4 store, not vendor mode-4 shortcut):

### Decompile writes

| Stack name / expression | Packet offset | Source |
|---|---:|---|
| `acStack_100[0..3]` = `'6',' ',0,0` | `+0x00` | Opcode LE **`0x00002036`** (`0x2036`) |
| *(unwritten)* | `+0x04` | Not written by grid path |
| `uStack_f8` | `+0x08` | held item `+0x160` (COID lo) |
| `uStack_f4` | `+0x0c` | held item `+0x164` (COID hi) |
| `uStack_f0` | `+0x10` | held item `+0x168` (global byte) |
| `uStack_e8` low byte | `+0x18` | `local_106` = **locX** from `FUN_0085f220` |
| `uStack_e8` byte1 | `+0x19` | **`pageH * pageIdx + local_105`** = **locY** (asm-sealed) |
| `uStack_e8` byte2 | `+0x1a` | `*(typeHost+4)` = **`ucTypeTo`** (EDX live; asm-sealed) |
| size arg | — | **`0x20`** |

Opcode packing proof: `'6' = 0x36`, `' ' = 0x20` → little-endian dword `0x00002036` (`mov dword [esp+0x10], 0x00002036` @ pack site).

### Sealed map (decompile + pack-site asm + retail struct)

Aligned to `Documentation/PACKET STRUCTURES.md` `SMSG_Sector_InventoryDrop` (Id=5654, Size=`0x20`) and server `InventoryDropPacket`:

| Offset | Size | Field | Evidence |
|---:|---:|---|---|
| `+0x00` | u32 | Opcode **`0x2036`** | Pack-site dword immediate **Confirmed** |
| `+0x04` | 4 | Unused by this builder | Not written on grid path |
| `+0x08` | 8 | `fidItem` COID | cursor item `+0x160/+0x164` |
| `+0x10` | u8 | Item global | item `+0x168` |
| `+0x11` | 7 | Pad | Unwritten |
| `+0x18` | u8 | **`ucInventoryLocX`** | `local_106` |
| `+0x19` | u8 | **`ucInventoryLocY`** | `pageH×pageIdx+cellY` (**High**/asm) |
| `+0x1a` | u8 | **`ucTypeTo`** | `*(typeHost+4)` (**Confirmed**/asm) |
| `+0x1b` | 5 | Pad / stack garbage | Grid path does **not** write `lQuantity` at `+0x1c` |

**Opcode / size confidence: Confirmed** for grid path. Alternate store path **`0x2027` / `0x40`** is a separate CF arm (not pure InventoryDrop).

### Y / type packing (residual sealed 2026-07-29)

| Piece | Asm / body | Meaning |
|---|---|---|
| `typeHost` | `mov edx,[esi+0x56c]` @ `0x00860c38` | UI window type host |
| `pageH` | `FUN_0085f1d0`: `[this+0x56c]` → `[host+0x1c]` | Page height (grid family `+0x1c`) |
| `pageIdx` | `imul byte ptr [esi+0x564]` after call | Window dword `0x159` / byte page index |
| `cellY` | `add al,[esp+local_105]` | Hit-test out from `FUN_0085f220` |
| `wireY` | store to packet `+0x19` | Absolute grid Y |
| `ucTypeTo` | `mov dl,[edx+4]` → packet `+0x1a` | Same host as Grab type-from |

Decompiler `CONCAT*` / `extraout_EDX` are non-authoritative; pack-site bytes are authoritative.

---

## 4. Side-effect order

1. Resolve grid coordinates (`FUN_0085f220`).
2. Client-side validation (type/trade).
3. Optional vehicle bind vfunc.
4. In-flight short-circuit.
5. Build packet; **`Client_SendSectorPacket`**.
6. Set `DAT_00d1a8f6 = 1`.
7. Or toast via `FUN_007fdfb0` on failure.

Does **not** call `PlaceItemFootprint` — placement waits for S2C DropResponse (`aa_00813730`).

---

## 5. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `in_EAX` | Inventory UI window **this** | **High** |
| `in_EAX[0x15b]` | `window+0x56c` type host | **High** |
| Opcode char `'6'` | **0x2036** InventoryDrop | **Confirmed** |
| Opcode char `'\''` (0x27) | Alternate **0x2027** store transaction path size 0x40 | **High** CF; store semantics **Probable** |
| Trade bit `>> 0x14 & 1` | Item flag “soulbound/custom” | **Probable** (string-backed reason) |
| Early “allows only 1 and 3” | **Overstated** — blocks class-4 into non-1/3 only | **High** |

---

## 6. Confidence / open

| Area | Level |
|---|---|
| Grid opcode `0x2036` + size `0x20` | **Confirmed** |
| Field offsets X/Y/type/COID | **Confirmed** / High |
| Type-1/3 class-4 gate wording | **High** |
| Y scale formula (`pageH×pageIdx+cellY`) | **High** (asm-sealed residual 2026-07-29) |
| ucTypeTo host (`window+0x56c→+4`) | **Confirmed** |
| Full 0x40 store layout | **Probable** |
| Runtime multi-page drop round-trip | **Open** |

---

## 7. Link: DropResponse `inventoryType` switch (already documented)

C2S Drop writes **`ucTypeTo` at `+0x1a`**. S2C DropResponse echoes destination type at the **same offset** and binds the grid:

| Artifact | Path |
|---|---|
| DropResponse annotated switch | [`raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md`](aa_00813730_Client_RecvInventoryDropResponse.annotated.md) § inventoryType switch |
| DropResponse clean | `reconstructed-exact/Client_RecvInventoryDropResponse.cpp` (bind by `inventoryType@+0x1A`) |
| System map | `systems/inventory-transfer.md` § DropResponse packet |
| Wire RE | `docs/inventory-cargo-wire-re.md` § Locker (type 3) — case 3 binds locker + `FUN_00571620` |

| `inventoryType` @ DropResponse `+0x1a` | Grid resolution |
|---:|---|
| **1** | Cargo: `*(*(client+0xe98)+0x250)+0x2b0` |
| **3** | Locker: `*(client+0xe98)+0xcbc` |
| **5** | Trade: `*(client+0xe98)+0xce0` |
| **6** | Other via TFID at `char+0xcd8/+0xcdc` |
| default / **2** | Invalid toast (hardpoint equip is **not** this path) |

Place uses DropResponse `locX@+0x18` / `locY@+0x19` → `InventoryGrid_PlaceItemFootprint` (`0x00571620`). This UI unit only **requests**; it never places.
