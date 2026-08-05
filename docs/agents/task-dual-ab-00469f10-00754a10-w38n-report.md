# Dual A/B report — W38-N OWN `aa_00469f10` + `aa_00754a10`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-N  
**Scope:** VAs `0x00469f10`, `0x00754a10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00469f10` StdVector_DwordEraseRange_EbxVec_Inferred | **accept** — EBX=vec / EAX=outIt / stack first+last / RET 8 / dword slide sealed |
| `aa_00754a10` GlyphCache_InitGdiFont_Inferred | **accept-with-gaps** — ESI this / ECX style / GDI open+metrics+DIB / RET 8 sealed; one-shot global + method English open |

---

## VA `0x00469f10` — sealed facts

1. **Body:** `0x00469f10`–`0x00469f41` exclusive (**49 B** / `0x31`; pad `CC` then next).
2. **ABI:** **EBX=`vec*`**, **EAX=`outIt*`**, stack **`first`**, **`last`**; **`RET 8`**. Decompiler `unaff_EBX` / `in_EAX` incomplete — **bytes win**.
3. **Semantics:** MSVC-style **`vector<uint32_t>::erase(first, last)`** for POD dword:
   - If `first != last`: dword-copy `[last, end)` → starting at `first`; publish `end = dest` at `vec+8`.
   - Always `*outIt = first`.
   - No dtors, no free, no capacity change, begin `@+4` untouched.
4. **Classification:** leaf.
5. **Callers (1):** `FUN_0044a380` @ `0x0044a3df` (`StdVector_DwordResize_EaxCount_Inferred` shrink; W37-Z).
6. **Callees:** none.
7. **Name:** `StdVector_DwordEraseRange_EbxVec_Inferred` (Ghidra `FUN_00469f10`; **Inferred**). **Reject** scaffold `Named_CalleeOf_…_effVertexDecl_00469f10`.
8. **Twin:** `FUN_00410490` `StdVector_EraseRange_Dword_Inferred` — thiscall `ECX=vec`, stack `outIt/first/last`, **`RET 0xC`**, `memmove`. Same algorithm class; **do not merge**.
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EBX/EAX formals and `RET 8`.  
   Full hex: raw W38-N append (49 B).

### Gaps

- Product/PDB STL mangled English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469f10_FUN_00469f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00469f10_FUN_00469f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordEraseRange_EbxVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469f10.cpp` |
| Function | `docs/reconstruction/functions/aa_00469f10_FUN_00469f10.md` |
| Function named | `docs/reconstruction/functions/aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` |

---

## VA `0x00754a10` — sealed facts

1. **Body:** `0x00754a10`–`0x00754edc` exclusive (**1228 B** / `0x4CC`; pad `CC` then `FUN_00754ee0` GlyphCache_PlacementCtor).
2. **ABI:** **ESI=`GlyphCache* this`**, **ECX=`style`**, stack **`face*`**, **`height`**; **`RET 8`**; EAX **`0` success / `0xFFFFFFFF` fail**. Decompiler `__thiscall` mislabels style as this — **bytes + factory caller win**.
3. **Semantics:** GDI face open into existing GlyphCache (`0xB8`):
   - Optional `FUN_00754970` if `DAT_00d1a548 == 0`.
   - Style tag bits: `1=Bold`, `2=Italic`, `4=Shadow`, `8=Outline` (empty → `"Normal"`).
   - Display name `"%s %i (%s)"` @ `this+0x18`; style @ `+0x34`.
   - `LOGFONTA`: weight 400/700, italic, height, charset `1`, out-precision `8`, quality `5` (or `3` if height `< 0xE`).
   - `CreateFontIndirectA` → `+0xA4`; `CreateCompatibleDC` → `+0xA8`; `GetTextMetricsW` → metrics block.
   - Shadow pad (+1 H, +2 W); Outline pad (+2 H, +3 W).
   - Atlas pow2 from `0x100`, capped by `DAT_00d1f044+0x6C/0x70`; DIB 32bpp top-down via `CreateDIBSection`.
   - Fail: `vog_LogMessage("…\gfxFontImpl.cpp", line, 3, msg)`.
4. **Classification:** worker.
5. **Callers (1 fn, 2 sites):** `FUN_0073bc50` @ `0x0073bd22` (requested face) and `0x0073bd33` (`"Arial"` @ `0x00aa267c` fallback) — W37-AE factory.
6. **Callees:** `FUN_00754970`, `FUN_0076cec0`, `vog_LogMessage`, basic_string ops, Win32 GDI family, `_snprintf`, `strncpy`.
7. **Name:** `GlyphCache_InitGdiFont_Inferred` (Ghidra `FUN_00754a10`; **Inferred**). **Reject** scaffold `Named_gfxFontImpl_00754a10` as product method plate.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on ESI this, RET 8, return codes.  
   Epilogue/anchors: raw W38-N append.

### Gaps

- Product method English beyond path `gfxFontImpl.cpp`.  
- `DAT_00d1a548` / `FUN_00754970` one-shot contract (unowned).  
- GfxDevice field English at cap offsets.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00754a10_FUN_00754a10.md` |
| Annotated | `docs/reconstruction/raw/aa_00754a10_FUN_00754a10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_InitGdiFont_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754a10.cpp` |
| Function | `docs/reconstruction/functions/aa_00754a10_FUN_00754a10.md` |
| Function named | `docs/reconstruction/functions/aa_00754a10_GlyphCache_InitGdiFont_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00469f10` | Port as **dword erase-range**: **EBX=vec**, **EAX=outIt\***, stack **first+last**, **`RET 8`**, dword slide + publish `end`. Do **not** use thiscall/`RET 0xC`/`memmove` twin `00410490` as drop-in. Server needs one correct `List<uint>.RemoveRange` — retail ABI flavor is caller-specific. |
| `00754a10` | **Client-only GDI** GlyphCache face open. Not needed for AutoCore sector/auth servers. If client font parity ever ports: style bits 0–3, quality threshold height `<14`, shadow/outline cell pad, atlas pow2 + device caps, 32bpp DIB. Do **not** treat as texture create. |
| Shared | Pair is **unrelated** domain-wise (STL shrink helper vs font GDI). Co-owned only by W38-N partition. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0044a380` | Sole caller of `00469f10` — dword resize EAX-count (W37-Z) |
| `0x00410490` | Erase-range twin thiscall/`RET 0xC`/memmove (W16-S) |
| `0x00463e30` | InsertN grow sibling of erase (W38-M owned elsewhere) |
| `0x0073bc50` | GlyphCache get-or-create factory (W37-AE) |
| `0x00754ee0` | GlyphCache placement ctor `0xB8` (W35-H) |
| `0x00aa267c` | `"Arial"` fallback string |
| `DAT_00d1f044` | GfxDevice* atlas caps |

Closes W38-N OWN pair: sealed erase-range shrink leaf for NestedHash resize path + sealed GlyphCache GDI face open for font factory miss path.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf / Named_gfxFontImpl scaffold aliases as product plates.  
- Avoided bare `undefined4` in named cleans (`uint32_t` / explicit structs).
