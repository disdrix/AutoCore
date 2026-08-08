# Dual A/B report — WQ9R-H OWN-ONLY (`0x0051b230`, `0x0051b2a0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ9R-H  
**Scope:** VAs `0x0051b230`, `0x0051b2a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / skills-abilities parent tables / NAMING_REGISTRY / VERIFICATION_MATRIX / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `get_assembly_context` (+ callee decompile for context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-H**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b230` Object_CreateFromEmbeddedCbid_Inferred | **accept-with-gaps** — thiscall factory / GiveItem(cbid,0) / init chain / RTTI consumers sealed; product English + descriptor type open |
| `aa_0051b2a0` Object_LazyFillMatColorVecFromMesh_Inferred | **accept-with-gaps** — empty vec guard / vtbl+0x1CC / FUN_00519280 / RET 0x10 sealed; product English + probe type open |

---

## VA `0x0051b230` — sealed facts

1. **Body:** `0x0051b230`–`0x0051b298` exclusive (**104 B** / `0x68`). Final **`C3`**; pad `CC` to `0x0051b2a0`.
2. **ABI:** **`__thiscall`**; ECX=`self*`; no stack formals; returns **object\*** in EAX; bare RET.
3. **Semantics:** virtual factory on cloned-object hierarchy:
   - `cbid = *(*(self+0xA8)+0x34)`
   - `obj = CVOGReaction_GiveItemByCbid(cbid, 0)` — **two** cdecl args (`ADD ESP,8`)
   - On success: `vtbl+8(cbid, *(self+0xA4), 1)`; `vtbl+0xB8(*(self+0xB8))`; `FUN_00516720(obj, *(self+0x158))`; `*(obj+0xC4)=*(self+0xC4)`
   - On factory NULL: return NULL (no init)
4. **Classification:** worker (virtual factory method).
5. **Callers (code):** `FUN_004c8f00` @ `0x004c8f23` → `dynamic_cast<CVOGCreature*>`; `FUN_0056b0a0` @ `0x0056b0c2` → `dynamic_cast<CVOGWeapon*>`. RTTI pushes belong to `__RTDynamicCast` (`0x004898a4`), not this VA.
6. **Xrefs:** 23 (2 code + ~21 vtable DATA).
7. **Related:** sibling `AllocateNewObjectFromCbid` (`0x004cf120`); factory `CVOGReaction_GiveItemByCbid` (`0x0051a170`); name helper `FUN_00516720` (`0x00516720`).
8. **Name:** `Object_CreateFromEmbeddedCbid_Inferred` (Ghidra `FUN_0051b230`). No product plate.
9. **Decompile ≡ raw CF** after thiscall / GiveItem-arity / FUN_00516720-thiscall trap fixes; sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for virtual slot.  
- Concrete type of `*(self+0xA8)` descriptor.  
- Field English for `+0xB8` / `+0xC4` (weapon path may reinterpret `+0xC4`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b230_FUN_0051b230.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b230_FUN_0051b230.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CreateFromEmbeddedCbid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b230.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b230_FUN_0051b230.md` |
| Function named | `docs/reconstruction/functions/aa_0051b230_Object_CreateFromEmbeddedCbid_Inferred.md` |

---

## VA `0x0051b2a0` — sealed facts

1. **Body:** `0x0051b2a0`–`0x0051b302` exclusive (**98 B** / `0x62`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX=`self*`; **4 stack dwords**; **`RET 0x10`**.
3. **Semantics:** lazy material-color bank fill:
   - If `*(self+0x148)==0` **or** `(*(self+0x14C)-*(self+0x148))>>4 == 0` (empty stride-16 vector): continue; else return.
   - `probe = self->vtbl+0x1CC()`
   - If `probe && *(probe+8)`: `FUN_00519280(*(probe+8), self+0x144, c0,c1,c2,c3)`
   - Callee walks mesh mats and appends **MatDiffuse / MatAmbient / MatEmissive** float4 records into bank at `self+0x144` (vector begin/end/cap at +0x148/+0x14C/+0x150).
4. **Classification:** worker (lazy virtual filler).
5. **Callers:** `FUN_004c5480` @ `0x004c54b7` (then optional second bank fill); pure thunk `0x004f3740` (`CALL` + `RET 0x10`).
6. **Xrefs:** 25 (code + vtable DATA).
7. **Related:** `FUN_00519280` (`0x00519280`, partition **WQ9R-E** — not dualed here); wrapper `FUN_004c5480`.
8. **Name:** `Object_LazyFillMatColorVecFromMesh_Inferred` (Ghidra `FUN_0051b2a0`). Material English from callee strings, not local plate.
9. **Decompile ≡ raw CF**; empty guard / probe / RET 0x10 sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for virtual slot.  
- Exact type returned by vtbl+0x1CC.  
- Semantic packing of four stack color dwords.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b2a0_FUN_0051b2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b2a0_FUN_0051b2a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LazyFillMatColorVecFromMesh_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b2a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b2a0_FUN_0051b2a0.md` |
| Function named | `docs/reconstruction/functions/aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051b230` | Port as **virtual method** on CVOGClonedObjectBase-like host: spawn via GiveItemByCbid from embedded cbid; run init chain; return base pointer. **Do not** embed RTDynamicCast here — callers cast to Creature/Weapon. Keep distinct from `AllocateNewObjectFromCbid` (sector-map host + template path). |
| `0051b2a0` | Port as **lazy** mat-color ensure: no-op if bank non-empty; else mesh probe vtbl+0x1CC → FUN_00519280. **RET 0x10**. Keep distinct from dual-bank wrapper `FUN_004c5480` and from `FUN_00519280` body (WQ9R-E). |
| Pair with | GiveItemByCbid `0x0051a170`, AllocateNewObjectFromCbid `0x004cf120`, FUN_00516720 `0x00516720`, FUN_00519280 `0x00519280`, creature clone `FUN_004c8f00`, weapon clone `FUN_0056b0a0`. |

---

## Process

- OWN VAs only (`0x0051b230`, `0x0051b2a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Trio: raw + annotated + clean (named + FUN twin).  
- No invented product plates; `_Inferred` structural names only (RTTI consumers + material callee strings).  
- Neighbor VAs (`0x00519280`, `0x0051b310`, …) referenced for context only — not dual-owned.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
