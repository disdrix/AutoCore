# Dual A/B report — W37-AE OWN `aa_0074e0d0` + `aa_0073bc50`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AE (overflow; exclusive ownership, not on main map table)  
**Scope:** VAs `0x0074e0d0`, `0x0073bc50` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `get_function_by_address` + `get_function_xrefs` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave37 overflow W37-AE (report-only; no partition-map edit required).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074e0d0` LightMgr_SetActiveSlot3c_Refcount_Inferred | **accept** — 55 B / RET4 / +0x3c swap / AddRef-then-Release / 3 light-domain callers sealed |
| `aa_0073bc50` GlyphCache_GetOrCreate_ByFontKey_Inferred | **accept-with-gaps** — 503 B / RET12 / GlyphCache 0xB8 get-or-create / Arial fallback / gfxFont sole caller sealed; map-helper dual open |

---

## VA `0x0074e0d0` — sealed facts

1. **Body:** `0x0074e0d0`–`0x0074e107` exclusive (**55 B** / `0x37`; Ghidra listing end `0074e106`). Pad `CC`.
2. **ABI:** `__thiscall` **ECX = host\***; stack **`new_obj*`**; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:**
   - If `new_obj != null`: `new_obj[+4]++`; if became **1**, `vtbl[+4]()`.
   - `old = host[+0x3c]`; if non-null: `old[+4]--`; if **0**, `vtbl[+8]()`.
   - `host[+0x3c] = new_obj`.
   - AddRef **before** Release (safe if same pointer).
4. **Classification:** **worker** (active-slot setter).
5. **Callers (3 CODE):**
   - `FUN_0048f370` @ `0x0048f3f9` — `PalantirEnv_RebuildDefaultLights_Inferred` (attach Direction light).
   - `FUN_0048eb10` @ `0x0048eb54` — `PalantirEnv_TearDefaultLights_Inferred` (**`push 0`** clear).
   - `FUN_00792600` @ `0x00792784` — host Directional light attach (`"Directional"` path).
6. **Callees:** virtual only (`vtbl[+4]`, `vtbl[+8]`).
7. **Name:** `LightMgr_SetActiveSlot3c_Refcount_Inferred` (Ghidra `FUN_0074e0d0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e0d0`.
8. **Family:** peer of list-register `FUN_0074e310` / unregister `FUN_0074e260` (W34-T residual closed for this unit’s contract).
9. **Decompile ≡ bytes** for CF/ABI/slot. Full hex:  
   `568b74240885f6578bf9741183460401837e040175078b068bceff50048b4f3c85c9740b834104ff75058b11ff520889773c5f5ec20400`

### Gaps

- Product C++ class English for light manager host.  
- Exact product type of `+0x3c` pointees (peers pass `light+0x8c`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LightMgr_SetActiveSlot3c_Refcount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074e0d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0074e0d0_FUN_0074e0d0.md` |
| Function named | `docs/reconstruction/functions/aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` |

---

## VA `0x0073bc50` — sealed facts

1. **Body:** `0x0073bc50`–`0x0073be47` exclusive (**503 B** / `0x1F7`; Ghidra listing end `0073be46`). Final **`C2 0C 00`** (`RET 12`); pad `CC` then `FUN_0073be50`. SEH `LAB_009b11c0`.
2. **ABI:** ECX + **3 stack formals**; returns **`GlyphCache*`** (null on fail); **`RET 12`**.
3. **Semantics:**
   - Build font key (`basic_string` face name + size/style dwords).
   - `FUN_00463c40(map, &it)` — lower_bound.
   - **Miss** (`it == map.sentinel[+8]`): `operator_new(0xB8)` + `GlyphCache_PlacementCtor` (`FUN_00754ee0`, W35-H); `FUN_00754a10(face)` then **`"Arial"`** @ `0x00aa267c` fallback; fail → scalar dtor + **null**; success → AddRef + `FUN_004638c0` insert.
   - **Hit:** return `*(it + 0x2c)`.
4. **Classification:** **worker** (get-or-create factory).
5. **Callers (1 CODE):** `FUN_0099ed40` @ `0x0099ed4e` — product  
   `C:\vog\1_code\palantir\palantir\graphics\gfxFont.cpp` + `"Failed to create font: %s"`. Map site **`DAT_00d1f628`**.
6. **Callees:** `FUN_00463c40`, `operator_new`, `FUN_00754ee0`, `FUN_00754a10`, `FUN_004638c0`, IAT `basic_string`.
7. **Name:** `GlyphCache_GetOrCreate_ByFontKey_Inferred` (Ghidra `FUN_0073bc50`; **Inferred** + product GlyphCache / gfxFont evidence). **Reject** scaffold `Named_CalleeOf_Named_gfxFont_0073bc50`.
8. **Family:** sole factory caller of W35-H `GlyphCache_PlacementCtor`; NestedHashBag nest inside GlyphCache (W34-G).
9. **Decompile ≡ CF** for map/miss/hit/Arial/fail; formal product labels residual. Full 503 B hex in raw W37-AE append.

### Gaps

- Full dual of map helpers `FUN_00463c40` / `FUN_004638c0` and node layout beyond value `+0x2c`.  
- Product English for ECX vs second key dword (size/weight/style).  
- `FUN_00754a10` full GDI contract (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0073bc50_FUN_0073bc50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_GetOrCreate_ByFontKey_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073bc50.cpp` |
| Function | `docs/reconstruction/functions/aa_0073bc50_FUN_0073bc50.md` |
| Function named | `docs/reconstruction/functions/aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074e0d0` | Port as **thiscall host method**: set `host[+0x3c]` with **AddRef-then-Release** (refcount at `obj+4`; activate `vtbl[+4]` on 0→1; release `vtbl[+8]` on →0). Accept **null** to clear. Pair with TearDefaultLights / RebuildDefaultLights; do **not** merge with list unregister `FUN_0074e260`. |
| `0073bc50` | Port as **font-key map get-or-create** returning **GlyphCache\*** (size **0xB8** via W35-H placement ctor). Include **Arial** fallback and fail→scalar dtor. Hit returns `node[+0x2c]` **without** AddRef (wrapper `0099ed40` AddRefs). Do **not** treat as `gfxFontImpl` ctor or ECX-this map method. |

Shared: both use the same refcount idiom (`+4` / vtbl[+4]/[+8]). Co-owned only by W37-AE partition assignment; different subsystems (lights vs fonts).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits; **report only** (no partition-map append).  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product class English without evidence; `_Inferred` structural names; caller/body strings used where sealed.  
- Rejected scaffold VOG / bare gfxFont plates; kept light-slot structural plate and GlyphCache product from W35-H + gfxFont path.
