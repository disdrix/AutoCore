# Review A (reconstruction fidelity): `aa_0040a600` SkillSet_Vector_UninitializedCopy_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a600` |
| **VA** | `0x0040a600`–`0x0040a664` inclusive (**101 B** / `0x65`) |
| **Canonical name** | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` |
| **Ghidra symbol** | `FUN_0040a600` |
| **Prior scaffold** | `FUN_0040a600` / `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600` |
| **Rejected misname** | `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600` |
| **Review date** | `2026-08-05` (MEGA-055 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md` |
| **System** | skills-abilities / STL SkillSet vector |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory` + callee `00412b10` / callers `00412730` / `00412a80`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **vector uninitialized_copy** (`_Ucopy`) for **0x18-byte** SkillSet entries: copy `[src_first, src_end)` into `dest` via per-element `FUN_00412b10` (6-dword construct); return destination end pointer. Invoked from SkillSet vector insert/reallocate and a thin trampoline.

```text
SkillSet_Vector_UninitializedCopy_0x18_Inferred(end, first, dest) -> dest_end
  SEH install (LAB_009bd090)
  for first..end step 0x18:
    FUN_00412b10(dest=EAX, src=ECX=first)   // 6 dwords if dest != null
    dest += 0x18
  SEH unlink
  return dest
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-055 re-verify) | `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedCopy_0x18_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0040a600.cpp` |
| Retired Named_CalleeOf | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600.cpp` |
| Function records | `docs/reconstruction/functions/aa_0040a600_*` |
| Body bytes | `read_memory` @ `0x0040a600` — ends **`C3`** (`RET`) |
| Call sites | `get_assembly_context` @ `0x00412946`, `0x004129ad`, `0x00412a90` |
| Element copy | `FUN_00412b10` disasm — 6 dword stores, null-dest guard |
| Stride peer | dualed `SkillSet_GetEntryCount` (`0x00402d80`) |
| Fill sibling | dualed `SkillSet_Vector_UninitializedFillN_0x18_Inferred` (`0x00406f00`) |
| Leaf twin (different) | dualed `SkillSet_UninitializedCopy_0x18` (`0x00442b00`) |

---

## 3. Signature (sealed)

```c
// ECX=src_end; stack src_first, dest; EAX=dest_end; RET (cdecl)
// Callers also push 2 extra unused dwords then ADD ESP,0x10
NPCSkillSetEntry* SkillSet_Vector_UninitializedCopy_0x18_Inferred(
    NPCSkillSetEntry* src_end /*ECX*/,
    NPCSkillSetEntry* src_first,
    NPCSkillSetEntry* dest);
```

| Formal | Source | Conf |
|---|---|---|
| src_end | ECX → EBX | **Confirmed** |
| src_first | stack `[EBP+0x8]` → ESI | **Confirmed** |
| dest | stack `[EBP+0xc]` → EDI | **Confirmed** |
| extra stack slots | pushed ×2 beyond first/dest | **Confirmed unused by body** |
| return | EAX = EDI after loop | **Confirmed** |
| cleanup | `RET` (`C3`); caller `ADD ESP,0x10` | **Confirmed** |
| element copy | `CALL FUN_00412b10` with EAX=dest, ECX=src | **Confirmed** |
| stride | `ADD ESI/EDI, 0x18` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH install FS:[0] / `LAB_009bd090` | bytes | **Confirmed** |
| EH state 0 during loop / −1 on exit | `[EBP-4]` stores | **Confirmed** |
| Empty range: first==end → return dest | `CMP/JZ` | **Confirmed** |
| Per element: copy then +0x18 both cursors | loop body | **Confirmed** |
| Stack first/dest rewritten each iter (EH) | `MOV [EBP+8/0xc]` | **Confirmed** |
| Return dest_end; unlink SEH | epilog | **Confirmed** |
| Decompile ≡ raw CF (modulo ABI labels) | live 2026-08-05 | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (vector Ucopy) |
| External callers | **2** functions / **3** UNCONDITIONAL_CALL |
| Sites | `FUN_00412730` @ `0x00412946`, `0x004129ad`; `FUN_00412a80` @ `0x00412a90` |
| Site role | SkillSet vector insert/reallocate range relocate + trampoline |
| Callees | `FUN_00412b10` only |
| Parent stores return | `[vector+0x8] = EAX` at `0x004129b2` (new end) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Stride 0x18 + 6-dword element copy | **Yes** |
| Same insert parent as dualed Ufill `00406f00` + count `00402d80` | **Yes** |
| Distinct from leaf Ucopy `00442b00` (register ABI, no SEH) | **Yes** |
| Product / PDB demangle `_Ucopy` English | **No** → `_Inferred` |
| Skill combat / Uses_SkillSet product logic | **No** (container helper only) |

**Decision:** promote **`SkillSet_Vector_UninitializedCopy_0x18_Inferred`**. Retire Named_CalleeOf scaffold.

---

## 7. Gaps

1. Product / MSVC demangled helper name.  
2. Full `NPCSkillSetEntry` field plate.  
3. Parent insert `FUN_00412730` and trampoline `FUN_00412a80` undualed.  
4. Exact purpose of 2 extra caller-pushed stack slots (body-unused sealed).  
5. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/stride/call-family with honest `_Inferred` and parent/PDB residual → **accept-with-gaps**.
