# Review A (reconstruction fidelity): `aa_0085f1d0` Client_UI_InventoryWindow_GetPageHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f1d0` |
| **VA** | `0x0085f1d0` |
| **Canonical name** | `Client_UI_InventoryWindow_GetPageHeight` (inferred; Ghidra still `FUN_0085f1d0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0085f1d0_Client_UI_InventoryWindow_GetPageHeight.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first modern A/B pair; supersedes Partial scaffold function record) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **page-height getter** for inventory UI windows that host a type/layout object at `window+0x56c`.

```text
typeHost = *(this + 0x56c)
return typeHost ? *(i32*)(typeHost + 0x1c) : 0
```

Used as the **page height (pageH)** factor when:

1. Packing drop wire **locY** in `Client_UI_InventoryDropToGrid` (`aa_00860a50`):  
   `wireY = (i8)(pageH * pageIdx + cellY)` at packet `+0x19`.
2. Scaling hit-test / CanPlace Y bands in `FUN_0085f220` (four call sites).

Does **not** compute page geometry, allocate grids, or send packets. Pure load + null gate.

**Calling convention:** sole object pointer in **EAX** (`in_EAX`); no stack args; returns **EAX** (`undefined4` / `uint32_t`). Leaf (no callees).

| Slot | Role | Evidence |
|------|------|----------|
| `this` (EAX) | Inventory UI window / drop host | Callers pass window; body loads `+0x56c` |
| return | page height cells, or **0** if type host null | Raw + bytes + Drop residual |

**Side effects:** none (read-only).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085f1d0_FUN_0085f1d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0085f1d0_FUN_0085f1d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085f1d0.cpp` (+ named twin) |
| Function record | `docs/reconstruction/functions/aa_0085f1d0_FUN_0085f1d0.md` |
| Parent drop | `aa_00860a50` dual residual A/B (Y formula sealed via this unit) |
| Grid pageH producers | `aa_00570720` Allocate (`+0x1c` write), Find/Can consumers |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x0085f1d0` (2026-07-29) — **matches raw** |
| Live bytes | Ghidra MCP `read_memory` @ `0x0085f1d0` length 32 |
| Callers | `FUN_0085f220` ×4; `Client_UI_InventoryDropToGrid` ×1 |
| Sibling | `FUN_0085f1f0` @ `0x0085f1f0` — same host, load `+0x18` |

**Not performed:** `disassemble_bytes`, Launcher, runtime heap dump, bit-exact diff.

---

## 3. Body: clean ≡ raw ≡ live decompile ≡ bytes

### 3.1 Pseudocode (authoritative)

```c
uint32_t Client_UI_InventoryWindow_GetPageHeight(/* this in EAX */)
{
  int typeHost = *(int *)(this + 0x56c);
  if (typeHost != 0) {
    return *(uint32_t *)(typeHost + 0x1c);
  }
  return 0;
}
```

### 3.2 Machine bytes @ `0x0085f1d0` (`read_memory`)

| VA | Bytes | Meaning |
|----|-------|---------|
| `0085f1d0` | `8B 80 6C 05 00 00` | `mov eax, [eax+0x56c]` |
| `0085f1d6` | `85 C0` | `test eax, eax` |
| `0085f1d8` | `74 04` | `jz` → xor path |
| `0085f1da` | `8B 40 1C` | `mov eax, [eax+0x1c]` |
| `0085f1dd` | `C3` | `ret` |
| `0085f1de` | `33 C0` | `xor eax, eax` |
| `0085f1e0` | `C3` | `ret` |

No stack frame; no callees; return width **32-bit** (not void — decompiler completeness warning on `undefined` is **false** for void; value is in EAX).

### 3.3 CF checklist

| Stage | Match |
|---|---|
| Load `*(this+0x56c)` | **Yes** |
| Null → return 0 | **Yes** |
| Non-null → return `*(host+0x1c)` | **Yes** |
| No writes / no calls | **Yes** |

---

## 4. Layout / semantics

| Offset | On | Role | Confidence |
|--------|-----|------|------------|
| `+0x56c` | UI window (`this`) | Pointer to type/layout host | **High** (body + Drop/Grab) |
| `+0x1c` | type host | **Page height** in cells | **High** CF; English via Allocate/Find/Can + Drop residual |
| `+0x18` | type host | Sibling load (`FUN_0085f1f0`) — width-family | Cross-unit (not this body) |
| `+0x04` | type host | Inventory type byte/dword for wire `ucTypeTo` | Parent unit (Drop); same host pointer |

### Page-height algebra (producer, not this unit)

From `InventoryGrid_AllocateCellArray_Inferred` (`aa_00570720`):

```text
pageH@grid+0x1c = (nTotal / pages) / width
// cargo: w=6, h=pages*13 → pageH = 13
```

This getter **reads** that field through the window’s host pointer; it does not recompute it.

---

## 5. Caller evidence (Drop Y role)

| Caller | Sites | Role of return |
|--------|-------|----------------|
| `Client_UI_InventoryDropToGrid` `0x00860a50` | `0x00860d43` | Pack: `imul [esi+0x564]` (pageIdx) + cellY → packet `+0x19` |
| `FUN_0085f220` `0x0085f220` | `0x0085f372`, `0x0085f45a`, `0x0085f46a`, `0x0085f496` | Hit-test Y scale / clamp vs pageH; CanPlace Y product with pageIdx |

### Pack-site seal (parent residual; depends on this unit)

```text
typeHost = *(window + 0x56c)
pageH    = FUN_0085f1d0(window)     // this unit
pageIdx  = *(i8*)(window + 0x564)   // dword index 0x159
cellY    = hit-test Y
wireY    = (i8)(pageH * pageIdx + cellY)   // 0x2036 packet +0x19
```

Asm (pack after call @ `0x00860d43`): `imul byte ptr [esi+0x564]` → `add al,[esp+0xb]` → `mov [esp+0x29], al`.

Semantic shape matches FindFree page window `pageH * pageIndex` (`aa_005713a0`).

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF / bytes / raw match | **High / Confirmed** | Live 2026-07-29 |
| `this` in EAX | **High** | `in_EAX`; no ECX use; callers set EAX/ESI window |
| `+0x56c` type host pointer | **High** | Body + Drop/Grab |
| Return `*(host+0x1c)` or 0 | **High** | Bytes |
| Semantic = **page height** for Drop Y / page bands | **High** | Consumers + Allocate write |
| type host **is** InventoryGrid* | **Probable** | Same `+0x1c` pageH; `+4` type; English object not PDB-sealed |
| Retail symbol | **Inferred only** | `Client_UI_InventoryWindow_GetPageHeight` |
| Runtime multi-page wire golden | **Open** | pageIdx≠0 capture |
| Bit-exact / diff | **Open** | Project deferred |

---

## 7. Gaps (do not claim complete)

1. Runtime cargo/locker drop with `pageIdx ≠ 0` proving wireY algebra end-to-end.
2. PDB / retail symbol.
3. Hard proof type host RTTI is exactly `InventoryGrid` vs binder sharing offsets.
4. Formal portable C++ `thiscall` plate (MSVC may use EAX for some UI methods in this binary).

**Verdict:** static dual for leaf pageH helper **sealed** at **accept-with-gaps**. Package **not complete** (runtime/diff open).
