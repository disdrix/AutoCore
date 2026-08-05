# Dual A/B report — W35-F OWN `aa_0098fef0` + `aa_00542e20`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-F  
**Scope:** VAs `0x0098fef0`, `0x00542e20` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0098fef0` GfxMesh_BuildNonInteriorEdgeIB_Inferred | **accept-with-gaps** — RET8/2-arg/return clone/edge filter/NestedHash0x10 sealed; product mesh English + vtable dispatch + write-loop register open |
| `aa_00542e20` Host_DrainPendingNfxEventQueue_Inferred | **accept-with-gaps** — ECX host + RET4 + queue/hash/NFX branches sealed; stack-arg body use + product host English open |

---

## VA `0x0098fef0` — sealed facts

1. **Body:** Ghidra `0x0098fef0`–`0x0099042a`; byte-confirmed success epilogue through **RET 8** ~`0x0099049c`–`0x0099049e` then `CC` (catalog range truncates tail).
2. **ABI:** stack **`ctx*`** + **`mesh*`**; **`RET 0x8`**; fail **EAX=0**; success **EAX=ESI clone**. Not ECX-thiscall.
3. **Semantics:**
   - Gate: mesh null or face type `mesh+0xac` ∉ {4,5,6} → 0.
   - `FUN_00457ac0(stack)` — NestedHash **0x10** bag (W34-E).
   - `FUN_0044b610` — GetTriangleVertexSteps (gfxFirst.h).
   - Lock source IB (`FUN_00743be0`, flags **0x810**); per face pack 3 undirected edges `min<<16|max`; find/insert NestedHash; **refcount++**.
   - Unlock (gfxDeviceIB.cpp:0xca string path).
   - Collect edges with **refcount != 2** into u32 vector; if empty tidy→0.
   - Else clone via `vtbl+0x7c`; attach `ctx+0x28` resource; set type **2**, flags **\|0x20**; setup/lock dest IB **0x800**; write u16s; unlock; return clone.
4. **Classification:** worker (indirect/vtable likely; **0** static xrefs).
5. **Callees:** `FUN_00457ac0`, `FUN_0044b610`, `FUN_00743be0`, `FUN_0046c1b0`, `FUN_0046bf90`, `FUN_004073a0`, `FUN_0044b9c0`, log/abort, `operator_delete`.
6. **Name:** `GfxMesh_BuildNonInteriorEdgeIB_Inferred` (Ghidra `FUN_0098fef0`; **Inferred**). **Reject** scaffold `Named_gfxDeviceIB_0098fef0`.
7. **Decompile caveats:** false noreturn on `operator_delete`; `unaff_ESI` on write loop — **bytes win** on RET8 / ESI return.

### Gaps

- Product/PDB mesh class English + vtable slot ownership.  
- Ghidra body-end vs true success epilogue.  
- Full dest write-loop register recovery.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxMesh_BuildNonInteriorEdgeIB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fef0.cpp` |
| Function | `docs/reconstruction/functions/aa_0098fef0_FUN_0098fef0.md` |
| Function named | `docs/reconstruction/functions/aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |

---

## VA `0x00542e20` — sealed facts

1. **Body:** `0x00542e20`–`0x00543050` (**561 B** / `0x231`; pad `CC` after final `RET 4`).
2. **ABI:** **ECX=host** (`MOV EBX,ECX`); stack **sessionField**; **`RET 0x4`**.
3. **Semantics:**
   - Gate `host+0xf2c`; list head `**(host+0xf28)`.
   - `FUN_004ed310(node+0x44, +0x40, +0x3c)` readiness; break on 0.
   - Hash lookup key `node+0x2c` in table `host+0xf0c`.
   - Miss → unlink + `FUN_00545500` + `operator_delete`.
   - Hit + unbound (`+0x58==0`) → `FUN_004a16d0` FOR_EVENT; resolve TFIDs; `vtbl+0x238` fire; unlink+delete.
   - Hit + bound → optional strip `"_nfx.xml"` + `FUN_004a6390` LoadMasterFromXML; clear bound; `FUN_0043d650(0)`; reset cursors; `FUN_004a04f0`.
   - After break: if `node+0x40==0`, `FUN_00971820(node+0x44)`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0094b520` @ `0x0094b7de` area — `ECX=[DAT_00b041fc]`, push `*(session+0xe4e8)`.
6. **Callees:** `FUN_004ed310`, `FUN_004a16d0`, `Object_ResolveFromTFID`, `FUN_00545500`, `FUN_004a6390`, `FUN_0043d650`, `FUN_004a04f0`, `FUN_00971820`, `operator_delete`, `strstr`.
7. **Name:** `Host_DrainPendingNfxEventQueue_Inferred` (Ghidra `FUN_00542e20`; **Inferred**). **Reject** scaffold `Named_nfx_00542e20`.
8. **Decompile ≡ bytes** for ECX host walk; **bytes win** on RET 4 + caller push (decompiler drops stack formal).

### Gaps

- Product host English for `DAT_00b041fc` / node layout.  
- Stack sessionField body use (if any).  
- Unowned callee full contracts.  
- Runtime / bit-exact / differential.  
- Note: `Client_AppFrameTick` clean currently models only the stack push — must pass global host in ECX.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00542e20_FUN_00542e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00542e20_FUN_00542e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_DrainPendingNfxEventQueue_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00542e20.cpp` |
| Function | `docs/reconstruction/functions/aa_00542e20_FUN_00542e20.md` |
| Function named | `docs/reconstruction/functions/aa_00542e20_Host_DrainPendingNfxEventQueue_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0098fef0` | Port as **2-arg RET 8** builder returning **clone mesh\*** or null. Depends on NestedHash0x10 + triangle edge multiset (count≠2). Do **not** wire as gfxDeviceIB unlock. Zero static xrefs — find vtable later. |
| `00542e20` | Port as **ECX host + stack arg RET 4**. Frame tick must load `DAT_00b041fc` into ECX. Queue at +0xf28/+0xf2c; map at +0xf0c. NFX reload path strips `_nfx.xml` then LoadMasterFromXML. |
| Shared | No shared callee ownership conflict within W35-F; NestedHash0x10 ctor is prior W34-E seal (caller-only here). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).
