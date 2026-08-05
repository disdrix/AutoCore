# Dual A/B report — W37-D OWN `aa_005b2ba0` + `aa_00972cc0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-D  
**Scope:** VAs `0x005b2ba0`, `0x00972cc0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` + `read_memory` + `analyze_function_complete` (callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b2ba0` GuardedVector_Dtor_Inferred | **accept-with-gaps** — ECX storage-dtor CF/ABI/page+map free sealed; decompiler post-delete zero miss corrected by bytes; product English open |
| `aa_00972cc0` Xform_Ctor_Inferred | **accept-with-gaps** — leaf 0xC0 identity init CF/ABI/globals sealed; EAX returns this; secondary field product English open |

**Terminal coverage claim:** **false** (agent dual only; no parent ledger merge).

---

## VA `0x005b2ba0` — sealed facts

1. **Body:** `0x005b2ba0`–`0x005b2c05` inclusive (**102 B** / `0x66`; pad `CC`).
2. **ABI:** **ECX** = `GuardedVectorHeader*`; 0 stack formals; plain **`RET`**; void.
3. **Semantics:**
   - Drain **`size` (`+0x10`)** to 0; when size hits 0, **`begin` (`+0x0c`) = 0**.
   - For **`i = capacity … 1`**: `page = pages[i-1]`; if non-null → **`operator_delete(page)`**.
   - If **`pages` non-null** → **`operator_delete(pages)`**.
   - **Always** **`capacity = 0`**, **`pages = 0`** (bytes; decompiler drops these on non-null map path due to false “does not return” on `operator_delete`).
4. **Layout (family):** `+0x04` pages**, `+0x08` capacity (page count), `+0x0c` begin, `+0x10` size. Header object itself is **not** freed.
5. **Classification:** worker (storage dtor / clear-free).
6. **Callees:** `operator_delete` @ **`0x00489822`** (×2).
7. **Callers (28):** AssPreloader locals (`FUN_00971640` family, `FUN_00971700` / `717a0` / `71820` / `71900` / `71a20`), multi-clear paths (`FUN_004ed1a0`, `FUN_004f26e0`), `FUN_0052c780`, `FUN_0043d4a0`, `FUN_0043e490`, … Related thunk/copy body @ `0x0043d640` **not owned**.
8. **Name:** `GuardedVector_Dtor_Inferred` (Ghidra `FUN_005b2ba0`; **Inferred** structural family). **Reject** scaffold `Named_CalleeOf_Named_stoPackOSFile_005b2ba0`.
9. **Decompile ≡ CF** for drain/free shape; **bytes refine** always-zero of capacity/pages.  
   Full hex: `53568bf133db395e10741eeb038d49008b46103bc3740d83c0ff3bc38946107503895e0c395e1075e7578b7e083bfb761b8b46048b44b8fc83ef013bc3740950e83d6cedff83c4043bfb77e58b46043bc35f740950e8286cedff83c404895e08895e045e5bc3`

### Gaps

- Product/PDB class English.  
- Callers that store owning non-POD in pages must destroy elements separately.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b2ba0_GuardedVector_Dtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b2ba0_GuardedVector_Dtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b2ba0.cpp` |
| Function | `docs/reconstruction/functions/aa_005b2ba0_FUN_005b2ba0.md` |
| Function named | `docs/reconstruction/functions/aa_005b2ba0_GuardedVector_Dtor_Inferred.md` |

---

## VA `0x00972cc0` — sealed facts

1. **Body:** `0x00972cc0`–`0x00972d6a` inclusive (**171 B** / `0xAB`; pad `CC`).
2. **ABI:** **ECX** = `XformBlock*` (0xC0); returns **this in EAX** (`MOV EAX,ECX` preserved); plain **`RET`**. Leaf.
3. **Semantics:**
   - Load **`g_flOne`** (`0x00a0f2a0` = 1.0f); zero via **`XORPS`**.
   - **`REP MOVSD` ×16** from **`DAT_00afdf70`** (identity mat4) → `self+0x00`.
   - Same copy → `self+0x40`.
   - **`+0x80..+0x8c`** = `(0,0,0,1)` quat identity.
   - **`+0x90..+0x98`** = `(0,0,0)` translation; **`+0x9c..+0xb0`** unit floats (scale xyz at `+0x9c` per `FUN_0044b440` + extra triple).
   - **`+0xb4=0`**, **`+0xb8=0` (byte)**, **`+0xbc=0`** (version / nonuniform / dirty).
4. **Size:** writes **`0x00..0xBF`** (**0xC0**); matches `_aligned_malloc(0xC0,0x10)` ensure sites and `eh_vector_constructor_iterator` element ctor.
5. **Classification:** leaf (ctor/init).
6. **Callees:** none. **Globals:** `g_flOne`, `DAT_00afdf70` (identity confirmed by `read_memory`).
7. **Callers (29):** `FUN_0075ceb0` (GfxView), `FUN_005b35a0` (EnvironmentReflect `+0x90`), `FUN_00439a80`, `FUN_0044b4f0` / `0044b540`, many gfx ensure paths.
8. **Name:** `Xform_Ctor_Inferred` (Ghidra `FUN_00972cc0`; **Inferred**; `Xform_*` family). **Reject** scaffold exclusive `Named_CalleeOf_Named_gfxView_00972cc0`.
9. **Decompile ≡ store CF**; bytes seal **EAX return this** (decompiler `void` incomplete).  
   Full hex: `f30f1005a0f2a0000f57c98bc15657b910000000be70dfaf008bf8f3a58d7840b910000000be70dfaf00f3a5f30f118880000000f30f118884000000f30f118888000000f30f11808c000000f30f118890000000f30f118894000000f30f118898000000f30f11809c000000f30f1180a0000000f30f1180a400000033c9f30f1180a8000000f30f1180ac000000f30f1180b00000005f8988b40000008888b80000008988bc0000005ec3`

### Gaps

- Product/PDB class English for 0xC0 block.  
- Secondary mat `+0x40` and extra triple `+0xa8` product roles.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00972cc0_Xform_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00972cc0_Xform_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Xform_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00972cc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00972cc0_FUN_00972cc0.md` |
| Function named | `docs/reconstruction/functions/aa_00972cc0_Xform_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005b2ba0` | Port as **GuardedVector storage dtor**: ECX header; drain size/begin; `delete` each page then the map; always zero capacity+pages. Do **not** free the header; do **not** run element dtors. Prefer bytes over decompile for final zeros. |
| `00972cc0` | Port as **0xC0 Xform default ctor**: ECX self, return this; dual identity mat4; identity quat; zero pos; unit scale; clean dirty/version. Pair with aligned `0xC0` alloc. Do **not** treat as view-only. |
| Shared | High-traffic nested helpers under AssPreloader / gfx ensure paths; safe to call from many owners once layout contracts above are respected. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA with inspected evidence.  
- Scaffold raw bodies preserved; W37-D re-verify **appended**.  
- No invented product plates; `_Inferred` names from structural families + sealed CF.  
- Rejected scaffold callee-of product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / typed headers / `XformBlock`).
