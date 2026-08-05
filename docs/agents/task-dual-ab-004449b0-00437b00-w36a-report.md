# Dual A/B report — W36-A OWN `aa_004449b0` + `aa_00437b00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-A  
**Scope:** VAs `0x004449b0`, `0x00437b00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + wrapper/creator context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-A).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004449b0` Sto_AbstractUnserializationFactory_InsertCreator_Inferred | **accept-with-gaps** — insert/bind CF, EBX creator, MapA, duplicate log sealed; map-op internals + tag-domain English open |
| `aa_00437b00` Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred | **accept-with-gaps** — peek/lookup/create/vfunc CF, EDI reader, fail `-1` sealed; object-type English + map-op internals open |

---

## VA `0x004449b0` — sealed facts

1. **Body:** `0x004449b0`–`0x00444a35` (**134 B** / `0x86`; pad `CC`).
2. **ABI:** **cdecl** insert helper; stack **FourCC tag**; **EBX** = creator fn\* (register); plain **`RET`** after `ADD ESP,0x10`. Not ECX-thiscall.
3. **Semantics:**
   - MapA GetInstance (`FUN_00438c40`) ×3; NestedHash lookup (`FUN_0046c1b0`) ×2; optional insert (`FUN_0046bf90`).
   - If found ≠ sentinel: `vog_LogMessage` duplicate ("Inserting duplicate creator tag to factory", plate `..\arda2/storage/stoAbstractUnserializationFactory.h`, line `0x24`, level 2).
   - If miss: insert `{tag, 0}`.
   - **Always** `*(node+0xc) = EBX`.
4. **Map:** Map A only (`FUN_00438c40` / W35-D). Not MapB.
5. **Classification:** worker (factory map insert/bind).
6. **Callers (3):** `FUN_004448b0` (`GPCE`→`0x00444d00`), `FUN_004448d0` (`GSKN`→`0x00444d60`), `FUN_004448f0` (`GMPH`→`0x00444dc0`) — each `PUSH EBX; PUSH tag; MOV EBX,creator; CALL; ADD ESP,4; POP EBX`.
7. **Callees:** `FUN_00438c40`, `FUN_0046c1b0`, `FUN_0046bf90`, `vog_LogMessage`.
8. **Name:** `Sto_AbstractUnserializationFactory_InsertCreator_Inferred` (Ghidra `FUN_004449b0`; **Inferred**). **Reject** scaffold Palantir callee-of. Registry plate alias `Sto_AbstractUnserializationFactory` retained as header evidence.
9. **Decompile ≡ bytes** for CF/strings/store; bytes refine map-op register ABI (ESI/EDI/ECX/EAX).  
    Full hex: `83ec105657e88642ffff8b7808e87e42ffff8bf08d4c241c8d442408e8df770200397c2408741668acf7a9006a026a246874f7a900e8d623550083c410e84e42ffff8bf08d4c241c8d442408e8af7702008b4424083b460875238b44241c8d4c2408518d542414528bfe89442410c744241400000000e8657502008b005f89580c5e83c410c3`

### Gaps

- Unowned NestedHash map ops (`FUN_0046c1b0`, `FUN_0046bf90` — W36-B).  
- Product English for tag domain A vs MapB sibling insert (`FUN_00444a40` — W36-C).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_InsertCreator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004449b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004449b0_FUN_004449b0.md` |
| Function named | `docs/reconstruction/functions/aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` |

---

## VA `0x00437b00` — sealed facts

1. **Body:** `0x00437b00`–`0x00437b57` (**88 B** / `0x58`; pad `CC`).
2. **ABI:** **cdecl**; stack **`void** out`**; **EDI** = `stoChunkReader*`; plain **`RET`**. Returns **status in EAX** (or **`0xFFFFFFFF`**).
3. **Semantics:**
   - `ESI = EDI`; `tag = FUN_0076a900()` (`stoChunkReader_PeekChunkTag`).
   - MapA GetInstance ×2 + NestedHash lookup (`FUN_0046c1b0`).
   - Miss (node == sentinel): `obj = 0`.
   - Hit: `obj = call [node+0xc]()` — **0 stack args** (decompiler `creator(tag)` **wrong**).
   - `*out = obj`.
   - If obj: thiscall vfunc `[*(obj+4)+4]` with **this=`obj+4`**, stack arg **EDI reader**; return status.
   - Else: return **`-1`**.
4. **Map:** Map A only. Pair insert = `FUN_004449b0`.
5. **Classification:** worker (lookup/create/unserialize).
6. **Callers (1 function / 4 sites):** `FUN_00765740` @ `00765b93`, `00765c43`, `00765f73`, `00765fe3` (gfxBody unserialize OR-accumulates status).
7. **Callees:** `FUN_0076a900`, `FUN_00438c40`, `FUN_0046c1b0`, indirect creator, indirect vfunc.
8. **Sample creator:** `FUN_00444d00` — `operator_new(0xC4)` + ctor; confirms 0-arg creator.
9. **Name:** `Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred` (Ghidra `FUN_00437b00`; **Inferred**). **Reject** scaffold gfxBody product role.
10. **Decompile ≡ CF**; bytes correct creator/vfunc ABIs.  
    Full hex: `83ec08568bf7e8f52d330089442404e82c1100008bf08d4c24048d442408e88d460300e8181100008b4c24083b48085e7405ff510ceb0233c085c08b4c240c8901740e8b50048d480457ff520483c408c383c8ff83c408c3`

### Gaps

- Concrete created-object / vtable product type.  
- Unowned map lookup internals.  
- MapB twin `FUN_00437c90` (W36-C).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.md` |
| Annotated | `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437b00.cpp` |
| Function | `docs/reconstruction/functions/aa_00437b00_FUN_00437b00.md` |
| Function named | `docs/reconstruction/functions/aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004449b0` | Port as **map A insert/bind**: tag on stack, creator register (EBX), always write `node+0xc`. Duplicate = log + rebind, not hard fail. Use MapA getter only (`FUN_00438c40`). Pair with NestedHash lookup/insert (W36-B). |
| `00437b00` | Port as **peek tag → lookup → create → unserialize**: reader in EDI-equivalent; out pointer on stack; creator **0-arg**; vfunc this=`obj+4` with reader arg; miss/null → `0xFFFFFFFF`. Do **not** return object in EAX. |
| Shared | Both exclusive Map A consumers with W35-D getter. Insert writes creator; lookup invokes it. Sibling MapB pair is `00444a40`/`00437c90` (W36-C) — separate static bag. Avoid bare `undefined4` in clean (`uint32_t` / typed node). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + wrapper/creator context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W36-A sections).  
- No invented product plates; `_Inferred` names from stoAbstractUnserializationFactory plate + sealed CF.  
- Rejected scaffold Palantir/gfxBody callee-of product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / structs).
