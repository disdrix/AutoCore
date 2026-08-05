# Annotated low-level: InventoryGrid_AllocateCellArray_Inferred (`aa_00570720`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **VA** | `0x00570720` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` (capture 2026-07-23) |
| **System** | inventory-transfer |

---

## 1. Corrected signature

```c
// Ghidra: __fastcall with single this in ECX (thiscall-equivalent here)
void __thiscall InventoryGrid_AllocateCellArray_Inferred(InventoryGrid* this);
```

| Name | Width | Role |
|---|---|---|
| `this` | ptr | Grid; reads width/height/pages; writes cell buffer |

Returns: **void**.

---

## 2. Algorithm (integer-width expanded)

```text
// free prior
if (*(void**)(this+0x28) != NULL)
  operator_delete( *(void**)(this+0x28) )

nTotal = *(i32*)(this+0x08) * *(i32*)(this+0x0c)   // width * height
*(u32*)(this+0x28) = 0
*(i32*)(this+0x10) = nTotal

// page geometry
// pageHeight = (nTotal / pages) / width
*(i32*)(this+0x1c) = (nTotal / *(i32*)(this+0x14)) / *(i32*)(this+0x08)
// derived width-like: nTotal / height
*(i32*)(this+0x18) = nTotal / *(i32*)(this+0x0c)

pCell = operator_new(nTotal * 8)     // 8 bytes per cell
*(void**)(this+0x28) = pCell

// dword fill: nTotal*8 / 4 dwords of 0xFFFFFFFF
for (n = (nTotal*8) >> 2; n != 0; --n) {
  *pCell++ = 0xFFFFFFFF
}
// trailing byte residual loop is dead for multiples of 4 (nTotal*8 always divisible by 4)
```

---

## 3. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| Empty sentinel `-1` / `0xffffffff` | **Both COID halves** of each cell = `0xFFFFFFFF` means empty | **Confirmed** |
| Cell stride **8** | Two u32: COID lo @+0, COID hi @+4 | **High** |
| Residual byte fill loop | MSVC memset expansion leftover; **no residual** when `nTotal*8 % 4 == 0` (always) | **High** |
| Division order for `+0x1c` | `(total/pages)/width` → cargo pages=1,w=6,h=78 → **13** | **Confirmed** |

---

## 4. Side-effect order

1. Conditional **delete** of old `this+0x28`.
2. Clear pointer; write `this+0x10` total.
3. Write derived `this+0x1c`, `this+0x18`.
4. **new** `nTotal*8` bytes.
5. Store new pointer; **fill** all dwords with `0xFFFFFFFF`.

No item tree mutation. No locks acquired inside this function (caller may hold CS).

---

## 5. Field map

| Offset | Type | Role in this function |
|---|---|---|
| `+0x08` | i32 | width (read) |
| `+0x0c` | i32 | height (read) |
| `+0x10` | i32 | **total cells** (write) |
| `+0x14` | i32 | pages (read) |
| `+0x18` | i32 | derived (= width when consistent) |
| `+0x1c` | i32 | **page height** in cells (write) |
| `+0x28` | `Cell(*)[ ]` | cell array pointer (free/realloc/fill) |

### Cell layout

```text
struct InventoryCell {   // 8 bytes
  uint32_t coidLo;       // 0xFFFFFFFF if empty
  uint32_t coidHi;       // 0xFFFFFFFF if empty
};
// empty test used by FindFreeSlot:
//   (coidLo & coidHi) == 0xFFFFFFFF
```

---

## 6. Confidence / open

| Area | Level |
|---|---|
| 8-byte cells, empty = all FFs | **Confirmed** |
| Page height formula | **Confirmed** (cargo 13) |
| Exact semantic of `+0x18` beyond width echo | **Probable** |
