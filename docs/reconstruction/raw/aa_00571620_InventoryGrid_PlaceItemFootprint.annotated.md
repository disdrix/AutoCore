# Annotated low-level: InventoryGrid_PlaceItemFootprint (`aa_00571620`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **VA** | `0x00571620` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00571620_InventoryGrid_PlaceItemFootprint.md` (capture 2026-07-23) |
| **Asm residual seal** | 2026-07-29 (`read_memory` stamp core + epilogue; see `reviews/a_00571620.md`) |
| **System** | inventory-transfer |
| **Server parity** | multi-cell occupancy stamp |

---

## 1. Signature (asm-sealed)

```c
// thiscall on grid; RET 0x10 → four stack dwords
uint32_t /*0 fail / 1 ok*/ __thiscall InventoryGrid_PlaceItemFootprint(
    InventoryGrid* this,   // ECX
    GameObject* item,      // stack0 → ESI; type host item+0xa8
    uint32_t originX,      // stack1
    uint32_t originY,      // stack2
    uint32_t quantity);    // stack3 → vtbl+0x260
```

| Name | Role | Confidence |
|---|---|---|
| `this` | Target grid (`+0x28` cells, `+0x04` type, `+0x0c` height/stride, `+0x24` bind arg) | **High** |
| `item` | Object to place | **High** |
| `originX/Y` | Footprint top-left | **High** |
| `quantity` | Stack count via vtbl+0x260 (was `unaff_retaddr`) | **High** |

---

## 2. Control flow

```text
typeId = *(i32*)(*(item+0xa8) + 0x38)

if typeId in {0x12, 0x14, 0x16, 0x36, 0x38, 0x3a}:
  return 0

if typeId == 4:
  FUN_00566f00(this = grid+0x2c, item)
  item.vtbl+0x158( grid+0x24 )
  return 1

blob = *(host + 0x3c)
sizeX = *(u8*)(blob + 0x406)          // InvSizeX
sizeY = *(u8*)(blob + 0x407)          // InvSizeY

if *(grid+4) == 4:
  if sizeX == 0: sizeX = 2
  if sizeY == 0: sizeY = 2

if !CanPlace(sizeX, sizeY, originX, originY, null):   // FUN_00570840
  return 0

item.vtbl+0x158( grid+0x24 )
item.vtbl+0x24c( originX, originY )
item.vtbl+0x40( 1 )

if (item+0x17c >> 6) & 1:
  gfx path (scale 1.0f, +0xfc)

item.vtbl+0x260( quantity )

// stamp — asm-sealed
for dx in 0 .. sizeX-1:
  for dy in 0 .. sizeY-1:
    idx = *(grid+0xc) * (originX + dx) + (originY + dy)
    cells[idx].lo = item+0x160
    cells[idx].hi = item+0x164

FUN_00566f00(grid+0x2c, item)
item+0x17c |= 0x10
FUN_00512670(item)
FUN_005706d0(grid)
return 1
```

---

## 3. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `param_2[0x2a]` | `item+0xa8` type host | **High** |
| `+0x406` / `+0x407` | **InvSizeX / InvSizeY** | **Confirmed** |
| Stamp `+0x160/+0x164` | COID lo/hi | **High** |
| `unaff_SI` | **sizeX** outer stamp bound | **High** (asm) |
| `unaff_retaddr` | **quantity** stack3 | **High** (asm) |
| Index `height*(sizeY+row)+…` | **WRONG** — real: `height*(ox+dx)+(oy+dy)` | **High** (asm falsifies raw) |
| `FUN_00566f00(item)` | **`this=grid+0x2c`**, item stack | **High** |
| vtbl `+0x24c(sizeX,ox)` | **`(originX, originY)`** | **High** |
| Flag `\| 0x10` | inventory-resident | **Probable** name; store **Confirmed** |
| `0x3f800000` | float **1.0f** | **Confirmed** |

### Index expression (bytes @ stamp core ~`0x005717b0`)

```c
idx = *(int*)(grid + 0x0c) * (originX + dx) + (originY + dy);
*(i32*)(cells + idx*8)     = coidLo;
*(i32*)(cells + idx*8 + 4) = coidHi;
```

Key opcodes: `8B 57 0C` / `0F AF 54 24 14` / `03 D0` / `03 54 24 18` / `89 2C D3` / `89 6C D3 04`.  
Matches CanPlace / FindFreeSlot: `height * x + y`.

---

## 4. Side-effect order

1. Type gates (no write on reject).
2. Type-4 early: list op + bind vfunc + return.
3. CanPlace (read cells).
4. Item vfuncs (state/graphics) + quantity.
5. **Multi-cell stores** to `grid+0x28`.
6. List op, flag or, item helper, grid helper.
7. Return 1.

---

## 5. Field map

| Location | Role |
|---|---|
| `grid+0x04` | Inventory kind (4 → store min size 2×2) |
| `grid+0x0c` | Height (index stride) |
| `grid+0x24` | Bind arg for vtbl+0x158 |
| `grid+0x28` | Cell array (stamp target) |
| `grid+0x2c` | List subobject (`FUN_00566f00` this) |
| `clone+0x406/407` | Footprint size |
| `item+0x160/0x164` | COID written into cells |
| `item+0x17c` | Flags; bit6 gfx, bit4 placed |

---

## 6. Confidence / open

| Area | Level |
|---|---|
| Multi-cell COID stamp | **Confirmed** (asm) |
| InvSize offsets | **Confirmed** |
| Exact loop index formula | **Confirmed** (`read_memory` opcodes 2026-07-29) |
| Stack ABI | **Confirmed** (`RET 0x10` epilogue bytes) |
| Type-id reject list (constants) | **Confirmed** |
| Type-id English names | **Tentative** / open |
| Runtime cell dump | **Open** |
