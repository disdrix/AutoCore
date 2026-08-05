# Dual A/B report — W38-T OWN `aa_0074e310` + `aa_0040ead0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-T  
**Scope:** VAs `0x0074e310`, `0x0040ead0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + `get_assembly_context` + context callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074e310` LightMgr_ListRegister_PushBack_Inferred | **accept-with-gaps** — 102 B / RET4 / size+1 push-back + AddRef/Release + vtbl+0x30 bind sealed; product host English open |
| `aa_0040ead0` D3dFormat_GetBitsPerPixel_Inferred | **accept** — jump-table leaf; D3DFMT→bpp; callers `shr 3`; `__cdecl` sealed |

---

## VA `0x0074e310` — sealed facts

1. **Body:** `0x0074e310`–`0x0074e375` inclusive (**102 B** / `0x66`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = list host; stack **`(obj*)`**; returns **0**; **`ret 4`** (`c2 04 00`).
3. **Semantics:** Push-back register on host pointer vector:
   - **begin@+8**, **end@+0xC** (same layout as unregister `FUN_0074e260`).
   - `size = (begin==0) ? 0 : (end-begin)>>2`
   - `FUN_00449440` with `edx=host+4`, `ecx=size+1` → `FUN_00449560` **resize to size+1** (append slot).
   - **AddRef** new (`refcount@+4`; 0→1 → `vtbl[+4]`).
   - **Release** prior `*slot` if non-null (`→0` → `vtbl[+8]`).
   - Store new at `end-4`; **`obj->vtbl[+0x30](*host)`** bind; return 0.
4. **Decompiler pitfall:** collapses grow into bare `FUN_00449440()` — **bytes win** for size math.
5. **Classification:** worker (list-register).
6. **Callers (10 sites / 7 funcs):**
   - `PalantirEnv_RebuildDefaultLights` (`0x0048f370`) ×2 — Direction + Hemispheric cores at `light+0x8c`; this = `[env+4]`.
   - `FUN_005b3520` Reflect resolve — hemi core bind via `[self+4]`.
   - `FUN_00755f10` — FourCC `BTLG` (`0x474c5442`) path.
   - `FUN_0058fe90`, `FUN_00792600`, `FUN_0078c780` (×2), `FUN_00912c20` (×2).
7. **Callees:** `FUN_00449440` (+ virtuals).
8. **Name:** `LightMgr_ListRegister_PushBack_Inferred` (Ghidra `FUN_0074e310`; **Inferred**). Peer of `LightMgr_SetActiveSlot3c_Refcount_Inferred` (`0x0074e0d0`). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e310`.
9. **Decompile ≡ bytes** for refcount/store/bind/ABI; grow path requires byte seal. Full hex in raw W38-T append.

### Gaps

- Product class English for host at `env+4`.  
- Payload type of `+0x8c` cores / `vtbl[+0x30]` bind contract.  
- Grow zero-init policy (unowned insert helper).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074e310_FUN_0074e310.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e310_FUN_0074e310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LightMgr_ListRegister_PushBack_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074e310.cpp` |
| Function | `docs/reconstruction/functions/aa_0074e310_FUN_0074e310.md` |
| Function named | `docs/reconstruction/functions/aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md` |

---

## VA `0x0040ead0` — sealed facts

1. **Body:** code `0x0040ead0`–`0x0040eb13` + jump table `0x0040eb14`–`0x0040eb2f` (7 dwords) + index `0x0040eb30`–`0x0040eb90` (**0x61** B); total **193 B** / `0xC1`; pad `CC`.
2. **ABI:** **`__cdecl`** free function; stack **`(format)`**; returns **bits-per-pixel** in EAX; plain **`ret`** (`c3`); callers **`add esp,4`**.
3. **Semantics:** MSVC switch:
   - `fmt -= 0x14`; if `> 0x60` → 0.
   - index table → jump to return stubs: **24 / 32 / 16 / 8 / 64 / 128 / 0**.
   - Core D3DFMT: `0x14`→24, `0x15`/`0x16`→32, `0x17`/`0x19`/`0x1a`→16, `0x1c`→8, `0x23`→32, `0x24`→64, `0x32`→8, `0x33`→16; extended `0x6f`–`0x74`.
4. **Caller proof of bits (not bytes):** e.g. GfxDevice_Reset / veh_paint paths **`shr eax,3`** then `imul` width×height×mips.
5. **Classification:** leaf (0 callees).
6. **Callers (19 sites / 17 funcs):** `FUN_0075eff0` (GfxDevice_Reset), texture/surface helpers, `FUN_00583170` (veh_paint_pallet), asset loaders, etc.
7. **Callees:** none.
8. **Name:** `D3dFormat_GetBitsPerPixel_Inferred` (Ghidra `FUN_0040ead0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0040ead0`.
9. **Decompile ≡ bytes** for full case map. Tables hex in raw W38-T append.

### Gaps

- Product English for extended formats `0x6f`–`0x74`.  
- Sparse map (many classic D3DFMTs → 0 by design).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040ead0_FUN_0040ead0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040ead0_FUN_0040ead0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/D3dFormat_GetBitsPerPixel_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040ead0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040ead0_FUN_0040ead0.md` |
| Function named | `docs/reconstruction/functions/aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074e310` | Port as **thiscall list-register push-back**: resize pointer vector (`begin+8`/`end+0xC`) to `size+1`; AddRef new; Release old slot; store; **`vtbl[+0x30](*host)`** bind; return 0 / RET4. Pair with unregister `0074e260` and single-slot `0074e0d0` — **do not merge**. Prefer **bytes** for grow path over bare decompile. |
| `0040ead0` | Port as **pure format→bpp** table (bits, not bytes). Keep default **0**. Call sites must `bpp >> 3` for byte pitch. Leaf — no device state. |
| Shared | Unrelated domains (light list register vs D3D format bpp). Co-owned only by W38-T partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00449440` / `0x00449560` | Vector resize-to-N used by list push |
| `0x0074e0d0` | `LightMgr_SetActiveSlot3c_Refcount_Inferred` (W37-AE) |
| `0x0074e260` | List unregister peer |
| `0x0048f370` | `PalantirEnv_RebuildDefaultLights_Inferred` — primary multi-call site |
| `0x005b3520` | Reflect resolve light slots (W37-F) |
| `0x0075eff0` | GfxDevice_Reset — bpp consumer |

Closes W38-T OWN pair: light-list push-back register+bind + D3D format bits-per-pixel leaf.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
