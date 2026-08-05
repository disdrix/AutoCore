# Annotated low-level: InventoryGrid_ctor_Inferred (`aa_00572650`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572650` |
| **VA** | `0x00572650` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00572650_InventoryGrid_ctor_Inferred.md` (capture 2026-07-23) |
| **System** | inventory-transfer |

Name suffix **`_Inferred`**: retail symbol not recovered; behavior is grid construction.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = this
InventoryGrid* __thiscall InventoryGrid_ctor_Inferred(
    InventoryGrid* this,
    int32_t nWidth,
    int32_t nHeight,
    int32_t nPages);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit ptr | address | `ECX` | Object under construction (0x68 bytes) |
| `nWidth` | i32 | signed | stack | Cell columns (cargo = **6**) |
| `nHeight` | i32 | signed | stack | Cell rows (cargo = **pages×13**) |
| `nPages` | i32 | signed | stack | UI/page count; clamped to ≥1 |
| **return** | ptr | address | `EAX` | `this` |

---

## 2. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `void *this` return | Returns **constructed this** | **Confirmed** |
| `100` at `this+100` | Offset **0x64** (decimal 100) — tree size / node count init 0 | **Confirmed** |
| Dim clamps | Each of width/height/pages forced **≥ 1** if `< 1` | **Confirmed** |
| `PTR_FUN_009d3390` | Primary `InventoryGrid` vtable | **High** |
| Nested `+0x2c` vtable dance | CS-related subobject re-vtable after `InitializeCriticalSection` | **High** (MSVC pattern) |

---

## 3. Initialization order (stores / calls)

```text
SEH prolog
this+0x00 = &PTR_FUN_009d3390          // main vtable
this+0x2c = &PTR_FUN_009cb334          // subobject vtable (pre-CS)
this+0x4c = 0
this+0x48 = 0
this+0x50 = 0
this+0x54 = 0 (byte)
InitializeCriticalSection(this+0x30)
this+0x2c = &PTR_FUN_009d3384          // subobject vtable (post-CS)
sentinel = FUN_005ae2b0()              // RB-tree sentinel node alloc
this+0x60 = sentinel
*(u8*)(sentinel+0x19) = 1              // color/header flag
*(sentinel+4) = sentinel               // parent
*sentinel = sentinel                   // left
*(sentinel+8) = sentinel               // right
this+0x64 = 0                          // element count
this+0x0c = nHeight
this+0x04 = 0
this+0x24 = 0
this+0x28 = 0                          // cell array (null until allocate)
this+0x58 = 0
this+0x20..0x22 = 0 (bytes)
this+0x08 = nWidth
this+0x14 = nPages
clamp pages/width/height to ≥1
InventoryGrid_AllocateCellArray_Inferred(this)
SEH epilog
return this
```

---

## 4. Field map (construction)

| Offset | Type | Init | Role |
|---|---|---|---|
| `+0x00` | vptr | `PTR_FUN_009d3390` | InventoryGrid vtable |
| `+0x04` | i32 | 0 | Grid/inventory **type** (set by owner later; cargo path uses 1, store uses 4, …) |
| `+0x08` | i32 | nWidth (≥1) | **Width** in cells |
| `+0x0c` | i32 | nHeight (≥1) | **Height** in cells |
| `+0x14` | i32 | nPages (≥1) | **Page count** |
| `+0x18` | i32 | (by Allocate) | Derived dim (see allocate notes) |
| `+0x1c` | i32 | (by Allocate) | Page height in cells |
| `+0x20..0x22` | u8×3 | 0 | Flags / pad |
| `+0x24` | i32 | 0 | Owner / context id (used by place) |
| `+0x28` | ptr | 0 → allocated | **Cell array** base |
| `+0x2c` | vptr | CS subobject | Nested lock object |
| `+0x30` | CRITICAL_SECTION | init | Grid mutex |
| `+0x48..0x54` | mixed | 0 | CS bookkeeping / flags |
| `+0x58` | i32 | 0 | Unknown secondary state |
| `+0x60` | ptr | sentinel | Item/container **RB-tree** header |
| `+0x64` | i32 | 0 | Tree size |

---

## 5. Side effects

- **Calls:** `InitializeCriticalSection`, `FUN_005ae2b0` (sentinel), `InventoryGrid_AllocateCellArray_Inferred`.
- **No network**, no item placement.
- Leaves cells empty (`0xFFFFFFFF` halves via allocate).

---

## 6. Confidence / open

| Area | Level |
|---|---|
| Width/height/pages layout | **Confirmed** |
| Size 0x68 | **High** (matches vehicle new) |
| Tree at +0x60 as item index | **Probable** |
| Exact `+0x04` type enum | **Probable** (cross-ref place path type 4) |
| Retail class name | **Open** (inferred) |
