# Dual A/B report — W35-D OWN `aa_00438c40` + `aa_00438ca0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-D  
**Scope:** VAs `0x00438c40`, `0x00438ca0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + atexit thunk bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00438c40` Sto_UnserialFactoryMapA_GetInstance_Inferred | **accept-with-gaps** — ABI/once/static NestedHash/atexit-no-op/exclusive Sto callers sealed; tag-domain English open |
| `aa_00438ca0` Sto_UnserialFactoryMapB_GetInstance_Inferred | **accept-with-gaps** — twin of MapA sealed; separate bag/flag/callers; product B domain English open |

---

## VA `0x00438c40` — sealed facts

1. **Body:** `0x00438c40`–`0x00438c99` (**90 B** / `0x5A`; pad `CC` then twin).
2. **ABI:** **cdecl** getter; **no stack args**; plain **`RET`** after `ADD ESP,0xC`; returns **bag\* in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - If **`(DAT_00d1fd40 & 1) == 0`**: set bit0; **`FUN_00457ac0(&DAT_00d1fd18)`** (NestedHash 0x10 ctor); **`_atexit(LAB_009c3310)`**.
   - Always **`return &DAT_00d1fd18`**.
4. **Static:** NestedHash span **0x28** at `DAT_00d1fd18`; once-flag immediately after at `DAT_00d1fd40`.
5. **Classification:** worker (Meyers singleton getter).
6. **Callers (2 functions / 5 sites):** `FUN_004449b0` (Sto AbstractUnserializationFactory insert; plate `stoAbstractUnserializationFactory.h`); `FUN_00437b00` (lookup/invoke).
7. **Callees:** `FUN_00457ac0` (`NestedHash_Ctor_Sentinel0x10_Inferred`, W34-E), `_atexit`.
8. **atexit:** `LAB_009c3310` = `MOV EAX,&DAT_00d1fd18; JMP 0x004493eb` → **`RET 4`** (no NestedHash free).
9. **Name:** `Sto_UnserialFactoryMapA_GetInstance_Inferred` (Ghidra `FUN_00438c40`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*_gfxBody_*`.
10. **Decompile ≡ bytes** for once-flag, ctor call, atexit, return imm.  
    Full hex: `64a1000000006aff684dcc9b0050b801000000840540fdd100648925000000007525090540fdd1006818fdd100c744240c00000000e846ee01006810339c00e8520c050083c4048b0c24b818fdd10064890d0000000083c40cc3`

### Gaps

- Product/PDB English for creator-node / tag domain A.  
- Unowned map ops on caller paths (`FUN_0046c1b0`, `FUN_0046bf90`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.md` |
| Annotated | `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapA_GetInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438c40.cpp` |
| Function | `docs/reconstruction/functions/aa_00438c40_FUN_00438c40.md` |
| Function named | `docs/reconstruction/functions/aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` |

---

## VA `0x00438ca0` — sealed facts

1. **Body:** `0x00438ca0`–`0x00438cf9` (**90 B** / `0x5A`; pad `CC`).
2. **ABI:** **cdecl** getter; **no stack args**; plain **`RET`**; returns **bag\* in EAX**.
3. **Semantics:**
   - If **`(DAT_00d1fd14 & 1) == 0`**: set bit0; **`FUN_00457ac0(&DAT_00d1fcec)`**; **`_atexit(LAB_009c3300)`**.
   - Always **`return &DAT_00d1fcec`**.
4. **Static:** NestedHash span **0x28** at `DAT_00d1fcec`; once-flag `DAT_00d1fd14` immediately after bag.
5. **Classification:** worker (Meyers singleton getter).
6. **Callers (2 functions / 5 sites):** `FUN_00444a40` (sibling Sto insert); `FUN_00437c90` (sibling lookup).
7. **Callees:** `FUN_00457ac0`, `_atexit`.
8. **atexit:** `LAB_009c3300` → same **`0x004493eb` RET 4** no-op as MapA.
9. **Name:** `Sto_UnserialFactoryMapB_GetInstance_Inferred` (Ghidra `FUN_00438ca0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*_gfxBody_*`.
10. **Twin:** body shape byte-identical to MapA except SEH/flag/static/atexit immediates + call relocs.  
    Full hex: `64a1000000006aff682dcc9b0050b801000000840514fdd100648925000000007525090514fdd10068ecfcd100c744240c00000000e8e6ed01006800339c00e8f20b050083c4048b0c24b8ecfcd10064890d0000000083c40cc3`

### Gaps

- Product distinction of map B vs A domains.  
- Unowned map-op callees.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.md` |
| Annotated | `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_GetInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438ca0.cpp` |
| Function | `docs/reconstruction/functions/aa_00438ca0_FUN_00438ca0.md` |
| Function named | `docs/reconstruction/functions/aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00438c40` | Port as **Meyers GetInstance** for NestedHash map A (`DAT_00d1fd18`, once bit0 `DAT_00d1fd40`). Ctor = W34-E NestedHash **0x10**. Do **not** free bag on atexit (retail no-op). Callers own insert/lookup. |
| `00438ca0` | **Separate** map B (`DAT_00d1fcec` / once `DAT_00d1fd14`). Same ctor. Never share storage with MapA or sibling bag C (`DAT_00d1fcc0` / `FUN_0044fee0`). |
| Shared | Both 90 B cdecl Meyers getters; both call sealed `FUN_00457ac0`; both atexit → RET4. BSS packs bagC/flagC/bagB/flagB/bagA/flagA contiguously. Pair with W34-E NestedHash ctor; W35-E owns third static getter. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + atexit thunk `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (raw rewritten with original body + W35-D section).  
- No invented product plates; `_Inferred` names from NestedHash family + exclusive Sto factory callers.  
- Rejected scaffold gfxBody callee-of chains.  
- Avoided bare `undefined4` in clean (`uint32_t` / NestedHash struct).
