# Dual A/B report — W36-C OWN `aa_00444a40` + `aa_00437c90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-C  
**Scope:** VAs `0x00444a40`, `0x00437c90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + string `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00444a40` Sto_UnserialFactoryMapB_InsertCreator_Inferred | **accept-with-gaps** — map B insert/bind + strings + EBX@+0xC + DSDL/AADL callers sealed; creator type open |
| `aa_00437c90` Sto_UnserialFactoryMapB_LookupInvoke_Inferred | **accept-with-gaps** — peek/find/miss-0/invoke + map B sealed; creator call formals open |

---

## VA `0x00444a40` — sealed facts

1. **Body:** `0x00444a40`–`0x00444ac5` (**134 B** / `0x86`; pad `CC` then next).
2. **ABI:** **cdecl** stack **`uint32_t tag`**; **EBX = creator function pointer** (register formal); plain **`RET`** after `ADD ESP,0x10`; void.
3. **Semantics:**
   - `sentinel = *(FUN_00438ca0()+8)` (MapB bag `DAT_00d1fcec`).
   - Find tag; if present → `vog_LogMessage("..\\arda2/storage/stoAbstractUnserializationFactory.h", 0x24, 2, "Inserting duplicate creator tag to factory")`.
   - Find again; if missing → `FUN_0046bf90` insert pair `{tag, 0}`.
   - Always **`*(node+0x0C) = EBX`** (bind/rebind creator).
4. **Classification:** worker (factory map B insert).
5. **Callers (2 functions / 2 sites):** `FUN_00444910` → tag **`0x4C445344`** FourCC **`DSDL`**; `FUN_00444930` → **`0x4C444141`** FourCC **`AADL`**.
6. **Callees:** `FUN_00438ca0` ×3, `FUN_0046c1b0` ×2, `FUN_0046bf90` ×1, `vog_LogMessage`.
7. **Twin:** MapA insert `FUN_004449b0` (W36-A) — same shape; MapA uses `FUN_00438c40`.
8. **Name:** `Sto_UnserialFactoryMapB_InsertCreator_Inferred` (Ghidra `FUN_00444a40`; **Inferred**). Aliases: plate/registry `Sto_AbstractUnserializationFactory_00444a40`. **Reject** scaffold `Named_CalleeOf_*_Palantir_*`.
9. **Decompile ≡ bytes** for MapB calls, sentinel, find/insert, log immediates, EBX store, RET.  
    Full hex: `83ec105657e85642ffff8b7808e84e42ffff8bf08d4c241c8d442408e84f770200397c2408741668acf7a9006a026a246874f7a900e84623550083c410e81e42ffff8bf08d4c241c8d442408e81f7702008b4424083b460875238b44241c8d4c2408518d542414528bfe89442410c744241400000000e8d57402008b005f89580c5e83c410c3`

### Gaps

- Creator function prototype (EBX target).  
- Full MapB tag domain beyond DSDL/AADL wrappers.  
- Unowned map ops (`FUN_0046c1b0`, `FUN_0046bf90` — W36-B).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.md` |
| Annotated | `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_InsertCreator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00444a40.cpp` |
| Function | `docs/reconstruction/functions/aa_00444a40_FUN_00444a40.md` |
| Function named | `docs/reconstruction/functions/aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` |

---

## VA `0x00437c90` — sealed facts

1. **Body:** `0x00437c90`–`0x00437cce` (**63 B** / `0x3F`; pad `CC` then next).
2. **ABI:** **no stack formals**; entry **`EAX = stoChunkReader*`** (`MOV ESI,EAX`); plain **`RET`** after `ADD ESP,8`; returns **creator result** or **0** in EAX.
3. **Semantics:**
   - `tag = FUN_0076a900()` (PeekChunkTag; ESI = reader).
   - `Find(MapB_Get(), tag)` via `FUN_00438ca0` + `FUN_0046c1b0`.
   - If node ≠ `*(bag+8)`: restore ESI=reader; **`CALL DWORD PTR [node+0x0C]`**; return EAX.
   - Else **`return 0`** (`XOR EAX,EAX`).
4. **Classification:** worker (factory map B lookup/invoke).
5. **Callers (1 function / 1 site):** `FUN_00765740` @ `0x00765cce`.
6. **Callees:** `FUN_0076a900`, `FUN_00438ca0` ×2, `FUN_0046c1b0`.
7. **Twin relation:** MapA lookup `FUN_00437b00` (W36-A) is **not** body-identical (out-param + secondary vcall; miss path different).
8. **Name:** `Sto_UnserialFactoryMapB_LookupInvoke_Inferred` (Ghidra `FUN_00437c90`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*_gfxBody_*`.
9. **Decompile ≡ bytes** for peek/MapB/find/miss-0/invoke site. Creator **stack** arg from decompiler **not** byte-proved.  
    Full hex: `83ec08568bf0e8652c330089442404e8fc0f00008bf08d4c24048d442408e8fd440300e8e80f00008b4c24083b48085e7407ff510c83c408c333c083c408c3`

### Gaps

- Creator calling convention (bare `CALL [mem]`; ESI=reader live; decompiler tag-arg unproved).  
- Product English of sole caller `FUN_00765740`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_LookupInvoke_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00437c90_FUN_00437c90.md` |
| Function named | `docs/reconstruction/functions/aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00444a40` | Port as **MapB insert/bind**: stack FourCC tag + creator fn (retail EBX). Always write `node+0xC`. Log on duplicate but **still rebind**. Use **MapB** GetInstance only (`DAT_00d1fcec` / W35-D) — never MapA. |
| `00437c90` | Port as **MapB lookup/invoke**: entry reader, PeekChunkTag → find → call `node+0xC` or **0**. Do **not** copy MapA lookup miss=`−1` / secondary vcall. Creator formals residual — prefer explicit port API over inventing stack `(tag)`. |
| Shared | Insert writes the slot lookup calls. Pair with W35-D MapB getter and W36-B NestedHash find/insert. Separate from MapA insert/lookup (`004449b0` / `00437b00`, W36-A). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + string memory. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (raw rewritten with original body + W36-C section).  
- No invented product plates beyond header/string evidence; `_Inferred` structural names.  
- Rejected scaffold Palantir/gfxBody callee-of chains.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit pointers).
