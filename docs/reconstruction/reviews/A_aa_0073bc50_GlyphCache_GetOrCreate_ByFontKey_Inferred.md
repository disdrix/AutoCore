# Review A (reconstruction fidelity): `aa_0073bc50` GlyphCache_GetOrCreate_ByFontKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073bc50` |
| **VA** | `0x0073bc50`–`0x0073be47` exclusive (**503 B**) |
| **Canonical name** | `GlyphCache_GetOrCreate_ByFontKey_Inferred` |
| **Ghidra name** | `FUN_0073bc50` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AE) |
| **Counterpart** | `reviews/B_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` |
| **System** | GlyphCache / gfxFont map get-or-create |
| **Evidence pass** | Live Ghidra `decompile_function` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (503 B body + `"Arial"`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Font-key map **get-or-create** returning a **GlyphCache\*** (`0xB8` host), with `"Arial"` fallback on rasterize failure.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AE append) | `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_GetOrCreate_ByFontKey_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0073bc50.cpp` |
| Function records | `functions/aa_0073bc50_FUN_0073bc50.md`, `functions/aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` |
| Placement peer | W35-H `GlyphCache_PlacementCtor` @ `0x00754ee0` |
| Live | decompile ≡ raw CF; 503 B; sole CODE xref `0099ed40` |

---

## 3. Signature (sealed)

```c
// RET 12; returns GlyphCache*
GlyphCache* __thiscall GlyphCache_GetOrCreate_ByFontKey_Inferred(
    int size_or_style /*ECX*/,
    void* map /*stack*/,
    const char* face_name /*stack*/,
    int key_dword_b /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| cleanup | `ADD ESP,0x88; RET 12` (`C2 0C 00`) | **High** |
| map | stack formal → `FUN_00463c40` / sentinel `map+8` | **High** |
| face_name | string assign + `"Arial"` retry path | **High** |
| ECX size/style | stored into key; passed to `FUN_00754a10` | **Medium** (product English open) |
| key_dword_b | packed into insert key | **Medium** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009b11c0
basic_string key = face_name; pack size dwords
FUN_00463c40(map, &it)
if (it == map.sentinel[+8]):  // miss
  p = new(0xB8); if (p) p = GlyphCache_PlacementCtor(p)
  if FUN_00754a10(name)<0 && FUN_00754a10("Arial")<0:
    if (p) p->vtbl[0](1); return null
  AddRef p (ref++ / vtbl+4 on 0→1)
  insert key node via FUN_004638c0
else:  // hit
  p = *(it + 0x2c)
return p
```

| Stage | Match | Conf |
|---|---|---|
| Miss vs hit sentinel | decompile + `map+8` | **High** |
| new 0xB8 + W35-H ctor | `68 B8 00 00 00` + call `00754ee0` | **High** |
| Arial fallback | imm `0x00aa267c` | **High** |
| Hit load +0x2c | decompile | **High** |
| RET 12 | epilogue bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **503 B**; epilogue `81 C4 88 00 00 00 C2 0C 00`; pad `CC` then `FUN_0073be50`.  
Full hex: raw W37-AE append.

**Decompile ≡ CF** for map/miss/hit/Arial/fail; formal product labels residual.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (get-or-create factory) |
| Callers | `FUN_0099ed40` @ `0x0099ed4e` only (CODE) |
| Product path | `gfxFont.cpp` / `"Failed to create font: %s"` |
| Map site | `DAT_00d1f628` |

---

## 7. Gaps

1. Full dual of map helpers `FUN_00463c40` / `FUN_004638c0` and node layout beyond `+0x2c` value.  
2. Product English for ECX / second key dword (size vs weight/style).  
3. `FUN_00754a10` full GDI contract (unowned).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — get-or-create CF, GlyphCache product, Arial fallback, RET 12, sole gfxFont caller sealed High; map-helper duals and key-field English open.
