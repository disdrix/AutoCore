# Dual A/B report — W38-E OWN `aa_004372a0` + `aa_004373b0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-E  
**Scope:** VAs `0x004372a0`, `0x004373b0` only. Trio + dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site `get_assembly_context` + callee decompile + vtbl `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004372a0` Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred | **accept-with-gaps** — EDI slot + stack reader + RET 4 + CPDG/phy sealed; English name + ctor +0x08 open |
| `aa_004373b0` Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred | **accept-with-gaps** — EBX host+4 + stack reader + RET 4 + MWGT/gfx sealed; English name + host node type open |

---

## VA `0x004372a0` — sealed facts

1. **Body:** `0x004372a0`–`0x0043733e` exclusive (**158 B** / `0x9E`; pad `CC`).
2. **ABI:** **EDI=`T**` out slot**; stack **`stoChunkReader* reader`**; **`RET 4`**; **EAX=status**. Decompiler `undefined4 (void)` + `unaff_EDI` incomplete — **bytes win**.
3. **Semantics:**
   - SEH (`LAB_009befeb`) around `operator_new(0x14)` + `FUN_004371c0` ctor (vtbl `PTR_FUN_00a9da68`).
   - **OOM:** return **`-1`**, **do not** write `*EDI`.
   - Else: AddRef `@+4`; if first → `vtbl[+4]` (nop `FUN_0056f570`); release old `*EDI` via `--refcount` / `vtbl[+8]` destroy; `*EDI=new`; hybrid call `FUN_00989850` (stack=obj, **EBX=reader**).
4. **Product evidence (callee):** `FUN_00989850` strings — `phyCPDefinition.cpp`, tag **`CPDG`** (`0x43504447`), "phyCPDefinitionGroupImpl".
5. **Layout (0x14):** vtbl@0, refcount@4, unk@8 (ctor unset), container@0xc (`FUN_004933f0`), zero@0x10.
6. **Classification:** worker.
7. **Callers (3 fn / 4 sites):** `FUN_00765740` @ `007658c0`/`00765d18`; `FUN_0095e3e0` @ `0095e495`; `FUN_009615c0` @ `00961e26`. Pattern: set EDI slot, `PUSH reader`, `CALL`, `OR ESI,EAX`.
8. **Callees:** `operator_new`, `FUN_004371c0`, `FUN_00989850`, indirect vtbl+4/+8.
9. **Name:** `Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred` (**Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_004372a0`.
10. **Decompile ≡ CF**; **bytes win** on EDI/stack/RET4/OOM.  
    Full hex: raw W38-E append (158 B).

### Gaps

- Product/PDB English method name.  
- Ctor field `+0x08` residual.  
- Unowned dual of `FUN_00989850` / `FUN_004371c0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004372a0_FUN_004372a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004372a0_FUN_004372a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004372a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004372a0_FUN_004372a0.md` |
| Function named | `docs/reconstruction/functions/aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` |

---

## VA `0x004373b0` — sealed facts

1. **Body:** `0x004373b0`–`0x00437419` exclusive (**105 B** / `0x69`; pad `CC`).
2. **ABI:** **EBX=`host*`** with refcounted slot at **`+4`**; stack **reader**; **`RET 4`**; **EAX=status** (decompiler `void` wrong). **Bytes win**.
3. **Semantics:**
   - No SEH. `operator_new(0x1c)`; inline ctor: vtbl=`PTR_FUN_00aa2f48`, refcount0, +8..+0x18 zero.
   - AddRef / first-ref `vtbl[+4]` (nop); release old `*(host+4)` via `vtbl[+8]`.
   - `*(host+4)=new` **even if null**; always call `FUN_0073efc0` (ECX=reader, stack=obj).
4. **Product evidence (callee):** `FUN_0073efc0` strings — `gfxMorphWeightArrayImpl.cpp`, tag **`MWGT`** (`0x4D574754`), version 1.
5. **Layout (0x1c):** vtbl@0, refcount@4, zeros@8..0x10, count@0x14 / token@0x18 (unserialize writes).
6. **Classification:** worker.
7. **Callers (3 fn / 5 sites):** `FUN_00765740` @ `00765b31`/`00765f11` (loop `ADD EBX,8`); `FUN_00739c80` @ `00739d6d`/`00739e4c`; `FUN_0095f560` @ `0095f678`. Pattern: set EBX host, `PUSH reader`, `CALL`, often `OR reg,EAX`.
8. **Callees:** `operator_new`, inline ctor, `FUN_0073efc0`, indirect vtbl+4/+8.
9. **Name:** `Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred` (**Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_004373b0`.
10. **Decompile ≡ CF**; **bytes win** on EBX+4/stack/RET4/return/OOM.  
    Full hex: raw W38-E append (105 B).

### Gaps

- Product/PDB English method name.  
- Host node product type (stride 8 in gfxBody loop).  
- Unowned dual of `FUN_0073efc0`.  
- Field English for +8..+0x10 pre-fill.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004373b0_FUN_004373b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004373b0_FUN_004373b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004373b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004373b0_FUN_004373b0.md` |
| Function named | `docs/reconstruction/functions/aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004372a0` | Port as **phy CPDG group factory**: **EDI=out slot**, push **reader**, **RET 4**. Size **0x14**, shared refcount vtbl protocol. **OOM preserves old slot** and returns `-1`. Unserialize hybrid: obj on stack, reader in EBX-equivalent. |
| `004373b0` | Port as **gfx MWGT array factory**: **EBX=host**, slot at **`host+4`**, push **reader**, **RET 4**, status in EAX. Size **0x1c**, vtbl `0x00aa2f48`. **OOM nulls slot and still unserializes**. Loop hosts step **+8**. |
| Shared | Same refcount protocol (count@+4, vtbl+4 first-ref often nop, vtbl+8 destroy `0x00464890`). Parallel pattern but **different domains** (physics CPDG vs graphics MWGT) and **different OOM/slot binding** (EDI `T**` vs host+4). Do not merge ABIs. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004371c0` | phyCPDefinitionGroupImpl ctor |
| `0x00989850` | CPDG unserialize (phyCPDefinition.cpp) |
| `0x0073efc0` | MWGT unserialize (gfxMorphWeightArrayImpl.cpp) |
| `0x00437150` | RefCountedSlot_ReleaseAndClear |
| `0x0056f570` | shared first-ref nop |
| `0x00464890` | shared destroy |
| `0x00765740` | common gfxBody multi-chunk load caller |
| `0x00a9da68` | phy group vtbl |
| `0x00aa2f48` | morph weight array vtbl |

Closes W38-E OWN pair: **physics CPDG slot alloc-replace-unserialize** + **graphics MWGT host-slot alloc-replace-unserialize**.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref/call-site helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; W38-E re-verify **appended** only.  
- No invented product names; `_Inferred` structural names from callee path/tag strings.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished OOM policies and slot ABIs between the two VAs.  
- Terminal coverage: **false** always.
