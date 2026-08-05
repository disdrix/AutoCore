# Dual A/B report — W38-R OWN `aa_0073eb40` + `aa_00465d70`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-R  
**Scope:** VAs `0x0073eb40`, `0x00465d70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-R).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0073eb40` GfxBodyHolder_ReplaceUnserialize_Inferred | **accept-with-gaps** — 166 B / thiscall RET 4 / SAMB vs GBOD / EAX status sealed; inbound callers open |
| `aa_00465d70` StdVector_Tidy_Stride24_EbxThis_Inferred | **accept** — 64 B / EBX-this / stride 0x24 / delete+zero sealed; product element English residual only |

---

## VA `0x0073eb40` — sealed facts

1. **Body:** `0x0073eb40`–`0x0073ebe6` exclusive (**166 B** / `0xA6`; pad `CC` then next).
2. **ABI:** **thiscall** ECX=`holder*`, stack `reader*`; **`RET 4`**; **EAX = status** from nested unserializer (decompiler void incomplete).
3. **Semantics:**
   - If `holder+4` non-null: scalar deleting dtor (`PUSH 1; CALL [vtbl]`).
   - `operator_new(0x14C)` + `FUN_00764030` GfxBody ctor (or null); store at `+4`.
   - `FUN_0076a900` peek tag with **ESI=reader**.
   - Tag **`SAMB`** `0x424D4153` → `FUN_009615c0(body, reader)` cdecl (`ADD ESP,8`).
   - Else → `FUN_00765740(body, reader)` stdcall **RET 8** (W37-S GBOD).
4. **Classification:** worker.
5. **Callers:** **open** (Ghidra xrefs/callers empty). Role sealed as **sole static caller** of `GfxBody_UnserializeGBOD`.
6. **Callees:** vcall dtor; `operator_new`; `FUN_00764030`; `FUN_0076a900`; `FUN_009615c0`; `FUN_00765740`.
7. **Name:** `GfxBodyHolder_ReplaceUnserialize_Inferred` (Ghidra `FUN_0073eb40`; **Inferred**). **Reject** Named_CalleeOf scaffold aliases.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX status, ESI reader for peek, two-arg SAMB call.  
   Full hex: raw W38-R append (166 B).

### Gaps

- Inbound static / dynamic callers.  
- Product holder/body English.  
- Unowned ctor / SAMB dual depth.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073eb40_FUN_0073eb40.md` |
| Annotated | `docs/reconstruction/raw/aa_0073eb40_FUN_0073eb40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBodyHolder_ReplaceUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073eb40.cpp` |
| Function | `docs/reconstruction/functions/aa_0073eb40_FUN_0073eb40.md` |
| Function named | `docs/reconstruction/functions/aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` |

---

## VA `0x00465d70` — sealed facts

1. **Body:** `0x00465d70`–`0x00465db0` exclusive (**64 B** / `0x40`; next at `0x00465db0`).
2. **ABI:** **EBX=`vector*`**; no stack formals; **`RET`** (`C3`); void.
3. **Semantics:** MSVC-style **vector tidy** stride **0x24**:
   - begin@**+4** end@**+8** cap@**+0xC**.
   - Null begin → zero triple.
   - Else: for each elem `FUN_00481d80` (ESI=elem; free nested @+0x18), `operator_delete(begin)`, zero triple.
4. **Classification:** worker.
5. **Callers / xrefs:** `FUN_00735390` @ `0x007353cd` (CALL); thunk `0x00465c30` (JMP).
6. **Callees:** `FUN_00481d80`; `operator_delete`.
7. **Name:** `StdVector_Tidy_Stride24_EbxThis_Inferred` (Ghidra `FUN_00465d70`; **Inferred**). **Reject** thiscall/ECX mis-ABI.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on post-delete zero (decompiler “noreturn” false).  
   Full hex: raw W38-R append (64 B).

### Gaps

- Product 0x24 element English.  
- Unowned `FUN_00481d80` dual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00465d70_FUN_00465d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00465d70_FUN_00465d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Tidy_Stride24_EbxThis_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00465d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00465d70_FUN_00465d70.md` |
| Function named | `docs/reconstruction/functions/aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0073eb40` | Port as **thiscall holder replace+load**: dtor old body@+4, `new` 0x14C GfxBody, peek tag, **SAMB→master** else **GBOD**. Preserve **EAX status**. RET 4. Do not invent inbound callers. |
| `00465d70` | Port as **EBX-this vector tidy** stride **0x24**: per-elem nested free via ESI helper, delete buffer, zero +4/+8/+0xC. **Not** thiscall. Pair with W37-N Palantir elem dtor (`elem+0x70C`). |
| Shared | Unrelated domains (gfx sto load vs container tidy); co-owned only as W38-R partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00764030` | GfxBody ctor (0x14c) |
| `0x0076a900` | stoChunkReader_PeekChunkTag (ESI) |
| `0x009615c0` | SAMB / gfxBodyMaster unserialize |
| `0x00765740` | GfxBody_UnserializeGBOD_Inferred (W37-S) |
| `0x00481d80` | Elem nested free ESI-this (+0x18) |
| `0x00735390` | PalantirSub10_OwnedElem_CompleteDtor (W37-N) |
| `0x00465c30` | JMP thunk to 00465d70 |
| `0x00964d00` | PalantirSub10_DestroyOwnedPtrVecAndComUninit (W35-J) |

Closes W38-R OWN pair: **GfxBody holder replace+unserialize dispatcher** (sole GBOD consumer) + **0x24-stride vector tidy** used under Palantir elem teardown.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Distinguished EAX status passthrough from decompiler void.  
- Distinguished EBX-this tidy from thiscall ECX vectors.  
- Terminal coverage: **false** always.
