# Dual A/B report — W38-U OWN `aa_0043b800` + `aa_0073be50`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-U  
**Scope:** VAs `0x0043b800`, `0x0073be50` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + twin/callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-U).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043b800` Gfx_DepthStencilFormat_ToBpp_Inferred | **accept** — EAX depth D3DFMT → bpp leaf; JT/IDX sealed; 49 B |
| `aa_0073be50` GlyphCacheList_ForEach_OnDeviceReset_Inferred | **accept-with-gaps** — EBX circular walk; ESI payload→`00755820`; sole GfxDevice_Reset caller; manager product English open |

---

## VA `0x0043b800` — sealed facts

1. **Body:** `0x0043b800`–`0x0043b831` exclusive (**49 B** / `0x31`); after body: align `8D 49 00`, jump-table @ `0x0043b834` (5×DWORD), index U8×10 @ `0x0043b848`, then `CC` / unrelated tiny writer.
2. **ABI:** **EAX = format in**, **EAX = bpp out**, no stack/ECX; plain **`RET`** (`C3` on all exits). Decompiler `in_EAX` switch ≡ jump-table.
3. **Semantics:** Leaf **depth/stencil `D3DFORMAT` → bits-per-pixel**:
   - Range: `format - 0x47`; if `> 9` → return **0**.
   - Table: `0x47→32`, `0x49→15`, `0x4B/0x4D/0x4F→24`, `0x50→16`; band holes (`0x48/4A/4C/4E`) → **0**.
   - Exact D3D9 match: **D32 / D15S1 / D24S8 / D24X8 / D24X4S4 / D16**.
4. **Twin:** `FUN_0040ead0` maps **color/texture** D3DFMT (0x14/0x15/…) → bpp — **do not merge**.
5. **Classification:** leaf utility (9 CODE xrefs / 7 caller funcs).
6. **Callers:** `FUN_0096bb20` (surface byte-size), `FUN_0096cad0`, `FUN_0075eff0` GfxDevice_Reset (×2 mem-acct), `FUN_0075fc40`, `FUN_0075ebd0` Clear Z-flag, `FUN_00735c90` (×2), `FUN_00735410` adapter score.
7. **Callees:** none.
8. **Name:** `Gfx_DepthStencilFormat_ToBpp_Inferred` (Ghidra `FUN_0043b800`; **Inferred** + D3DFMT enum match). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0043b800`.
9. **Decompile ≡ bytes** for CF/ABI; jump-table is implementation detail of the same switch. Full hex in raw W38-U append.

### Gaps

- Product/PDB English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043b800_FUN_0043b800.md` |
| Annotated | `docs/reconstruction/raw/aa_0043b800_FUN_0043b800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_DepthStencilFormat_ToBpp_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043b800.cpp` |
| Function | `docs/reconstruction/functions/aa_0043b800_FUN_0043b800.md` |
| Function named | `docs/reconstruction/functions/aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` |

---

## VA `0x0073be50` — sealed facts

1. **Body:** `0x0073be50`–`0x0073be74` exclusive (**36 B** / `0x24`); pad `CC` after. Sibling factory `FUN_0073bc50` GlyphCache_GetOrCreate ends just before (W37-AE).
2. **ABI:** **EBX = list container**; no stack formals; returns **0** always; plain **`RET`**. Per-node: **ESI = `*(node+0x2c)`** into `FUN_00755820`. Decompiler `unaff_EBX` / bare callee call incomplete — **bytes win**.
3. **Semantics:** Walk **circular list** sentinel at `container+8`:
   - `for (node = sentinel->next; node != sentinel; node = node->next)`
   - `FUN_00755820(*(node+0x2c))` — GlyphCache* family payload (same +0x2c as W37-AE map node).
   - Empty list: skip loop, return 0.
4. **Classification:** worker (device-reset broadcast).
5. **Callers (1 site):** `FUN_0075eff0` GfxDevice_Reset @ `0x0075f36d` — success path: `MOV EBX,[device+0x758]; CALL 0073be50` after factory re-init / `FUN_00968680`.
6. **Callees:** `FUN_00755820` (unowned per-cache reset hook; ESI object).
7. **Name:** `GlyphCacheList_ForEach_OnDeviceReset_Inferred` (Ghidra `FUN_0073be50`; **Inferred** from Reset site + GlyphCache payload family). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0073be50`.
8. **Decompile CF spine OK**; **bytes win** on EBX/ESI ABI and return-0. Full hex in raw W38-U append.

### Gaps

- Product class name for manager at `device+0x758`.  
- Full dual of `FUN_00755820` / `FUN_00755100` (unowned).  
- NestedHash intrusive vs dedicated registry.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073be50_FUN_0073be50.md` |
| Annotated | `docs/reconstruction/raw/aa_0073be50_FUN_0073be50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCacheList_ForEach_OnDeviceReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073be50.cpp` |
| Function | `docs/reconstruction/functions/aa_0073be50_FUN_0073be50.md` |
| Function named | `docs/reconstruction/functions/aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043b800` | Port as pure **`depthStencilFormatToBpp(D3DFORMAT)`** (or switch on 0x47/49/4B/4D/4F/50). ABI: **EAX in/out**, no this. Callers compute depth surface bytes as `(bpp * w * h) >> 3` into mem counters (`+0x3b0`). **Do not** use for color formats — use twin `0040ead0` for texture/backbuffer bpp (`+0x3ac`). |
| `0073be50` | Port as **for-each GlyphCache on device reset**: EBX = manager with circular sentinel @+8; each node payload @+0x2c → per-cache rebuild hook (`00755820`). Always returns 0. Call only on Reset **success** path after device-dependent factories re-init. |
| Shared | Both under GfxDevice_Reset / graphics memory path, but **unrelated roles** (format bpp leaf vs GlyphCache list walk). Co-owned only as W38-U partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0040ead0` | Color/texture D3DFMT → bpp twin |
| `0x0075eff0` | GfxDevice_Reset — primary consumer of both units |
| `0x0075ebd0` | gfxDevice Clear — uses bpp non-zero + separate stencil-bit table |
| `0x0096bb20` | Surface byte-size helper using depth bpp |
| `0x0073bc50` | GlyphCache_GetOrCreate_ByFontKey (W37-AE) — sibling factory |
| `0x00754ee0` | GlyphCache_PlacementCtor (W35-H) |
| `0x00755820` | Per-GlyphCache device-reset hook (ESI) |
| `0x00d1f614` | Graphics mem-acct host (`+0x3ac` color / `+0x3b0` depth) |
| `device+0x758` | GlyphCache list manager live-in for `0073be50` |

Closes W38-U OWN pair: **depth-stencil format bpp** leaf used by device reset mem-acct + **GlyphCache list for-each** on successful device reset.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only; D3DFMT labels are public enum matches not PDB plates.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).  
- Distinguished depth bpp mapper from color twin `0040ead0`.  
- Distinguished list walk from GlyphCache factory `0073bc50`.  
- Terminal coverage: **false** always.
