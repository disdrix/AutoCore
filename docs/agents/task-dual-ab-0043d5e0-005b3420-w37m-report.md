# Dual A/B report — W37-M OWN `aa_0043d5e0` + `aa_005b3420`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-M  
**Scope:** VAs `0x0043d5e0`, `0x005b3420` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave37.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d5e0` StdMap_FindEq_UintKey_Val12 | **accept** — ECX/EBX/EAX register ABI + Val12 exact-find + RET sealed (90 B); product map English residual only |
| `aa_005b3420` CVOGEnvironmentReflect_InitBufferedViewChild_Inferred | **accept-with-gaps** — ECX Reflect + gfxBufferedView RTTI/size/slot/near-far/256² + sole Enable caller sealed (249 B); nested helper English residual |

---

## VA `0x0043d5e0` — sealed facts

1. **Body:** `0x0043d5e0`–`0x0043d63a` exclusive (**90 B** / `0x5A`; final `C3` @ `0x0043d639`; pad `CC`).
2. **ABI:** **ECX=map** (`MOV ESI,ECX`); **EBX=`const uint32_t* key`**; **EAX=`node** out_it`**; plain **`RET`** (`C3`). No stack formals. Bytes win over decompiler `in_EAX` / `unaff_EBX` phantoms.
3. **Semantics:** MSVC-style **`_Tree` exact find** on Val12 nodes:
   - `head = *(map+4)`; root = `head->parent`.
   - Walk: if `node.key < *key` go right else remember + go left; stop on **isnil@`+0x19`**.
   - Gate: `cand != head && cand.key <= *key` → hit; else end.
   - Combined lower_bound + gate ⇒ **equality** for unsigned keys (not pure lower_bound).
4. **Layout:** L`+0` / P`+4` / R`+8` / key-u32`+0x0C` / isnil`+0x19` (Val12 family).
5. **Classification:** **leaf** (no callees).
6. **Callers (8):** `FUN_0072a660` (gfxSubPhaseMap load), `FUN_00750260`, `FUN_0075d230`, `FUN_0075d330`, `FUN_00970c00`, `FUN_00971640`, `FUN_00971a20`, `FUN_00971ea0`.
7. **Name:** `StdMap_FindEq_UintKey_Val12` (Ghidra `FUN_0043d5e0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_gfxSubPhaseMap_0043d5e0`.
8. **Decompile ≡ bytes** for full CF; **bytes win** on register ABI.  
   Full hex: `83ec08568bf18b56048b4a04807919007518578b3b39790c73058b4908eb048bd18b098079190074ec5f8b4e043bd18954240474148b333b720c720d8d4c24048b0989085e83c408c3894c24088d4c24088b0989085e83c408c3`

### Gaps

- Product/PDB map / value_type English.  
- Runtime / bit-exact.  
- Caller-specific key domain (hash vs id) beyond uint32.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FindEq_UintKey_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d5e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d5e0_FUN_0043d5e0.md` |
| Function named | `docs/reconstruction/functions/aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md` |

---

## VA `0x005b3420` — sealed facts

1. **Body:** `0x005b3420`–`0x005b3519` exclusive (**249 B** / `0xF9`; final `C3` @ `0x005b3518`; pad `CC` then `FUN_005b3520`).
2. **ABI:** **ECX=`CVOGEnvironmentReflect*`** (`MOV ESI,ECX`); no stack formals; void; SEH + **`ADD ESP,0x18`** + plain **`RET`**.
3. **Semantics:** Install **gfxBufferedView** child on Reflect host:
   - `operator_new(0x198)` → `FUN_00968a50` ctor (null → 0).
   - Store at **`self+0x158`**; **`child+4 = self`** parent link.
   - `GfxView_SetNear_Inferred` (`0x0075b3b0`, W31-O) with **`0x3f000000` (0.5f)**.
   - `FUN_0075bf40(DAT_00afdf08)` (DiffuseTexture-path bind; live dword **`0xFFFF0000`**).
   - Zero `child+0x180`; `FUN_0075b450`; SetFar-style `FUN_0075b390(**0x47c35000` = 100000.0f)**.
   - Zero `+0xec`; dirty bytes `+0x48=1`, `+0xcc=1`.
   - **`child->vtbl[+0x18](&{0x100,0x100})`** (256×256 bring-up).
   - Zero `+0x108`; byte `+0x190=1`.
4. **Child RTTI (Confirmed):** vtbl `PTR_FUN_00aa22a8` → COL `0x00aba3bc` → type_info `0x00b025e8` → **`.?AVgfxBufferedView@@`**.
5. **Classification:** **worker** (post-ctor child install).
6. **Callers (1):** `CVOGEnvironmentReflect_Enable_Inferred` (`FUN_005b39a0`, W33-T) after `HostBase_EnsureAuxPtrs` + `FUN_005b3520`.
7. **Name:** `CVOGEnvironmentReflect_InitBufferedViewChild_Inferred` (Ghidra `FUN_005b3420`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_005b3420`. Not a fog type (fog resolve is sibling `FUN_005b3520`).
8. **Decompile ≡ bytes** for full CF (live 2026-08-04 ≡ raw 2026-07-23).  
   Full hex: `6aff68db679a0064a100000000506489250000000083ec0c56b8000100005768980100008bf18944241089442414e83f64edff83c4048944240833ff3bc7897c241c74098bc8e8e5553b00eb0233c08986580100008970048b8e58010000680000003fc7442420ffffffffe8207f1a00a108dfaf008b8e5801000050e89f8a1a008b8e5801000089b9800100008b8e58010000e8987f1a008b8e58010000680050c347e8c87e1a008b865801000089b8ec000000c6404801c680cc000000018b8e580100008b118d44240c50ff52188b8e5801000089b9080100008b96580100008b4c24145fc68290010000015e64890d0000000083c418c3`

### Gaps

- Product English for `FUN_0075bf40` / `FUN_0075b450` / vtbl+`0x18`.  
- `DAT_00afdf08` asset vs handle identity.  
- OOM path (assign `child+4` without null check — matches raw).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3420.cpp` |
| Function | `docs/reconstruction/functions/aa_005b3420_FUN_005b3420.md` |
| Function named | `docs/reconstruction/functions/aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d5e0` | Port as **Val12 uint-key exact find**: **ECX=map** (head@`+4`), **EBX=key\***, **EAX=out node\*\***, plain **RET**. Equality gate required — do **not** treat as pure lower_bound. Do **not** invent `RET 4`/`RET 8` stack formals. Do **not** mix with TFID isnil29 / char-key / signed-int map helpers. |
| `005b3420` | Port as **Reflect Enable nested install**: **ECX=CVOGEnvironmentReflect\***, `new gfxBufferedView(0x198)` → **`+0x158`**, near **0.5**, far **1e5**, vtbl+**0x18**(256,256). Do **not** name as fog class (sibling `FUN_005b3520`). Do **not** merge with `ParticleFluidPhase_InitFluidBumpChild` (same ctor size, different slot/params). Closes W33-T nested alloc residual. |

Shared: unrelated systems co-owned only by partition assignment (STL map leaf vs Reflect buffered-view child). Trio (raw/annotated/clean) + dual A/B filed per VA.

### Enable path (sealed relative order)

```
PalantirEnv_InitPhases:
  reflect = new(0x170) + CVOGEnvironmentReflect_ctor(parent@env+0xB8)
  env+0xC4 = reflect
  CVOGEnvironmentReflect_Enable(reflect, 1)     // W33-T 005b39a0
    → HostBase_EnsureAuxPtrs(reflect, 1)
    → FUN_005b3520(reflect)                     // fog/slot resolve residual
    → InitBufferedViewChild(reflect)            // this dual 005b3420
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`StdMap_FindEq_UintKey_Val12` from Val12 family + exact gate; `CVOGEnvironmentReflect_InitBufferedViewChild_Inferred` from host RTTI + child `.?AVgfxBufferedView@@`).  
- Rejected scaffold gfxSubPhaseMap / Drive_NDRiver_fx names.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
