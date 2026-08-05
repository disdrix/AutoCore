# Dual A/B report — W20-T OWN-ONLY (`0x00517400`, `0x0052db50`)

**Date:** 2026-07-29  
**Agent:** W20-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00517400`, `0x0052db50`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00517400` Object_RefreshSkillHash_Inferred | **accept-with-gaps** — **cdecl hash traverse + inline sibling clear (flag 0) + reevaluate/name sealed; product English open** |
| `aa_0052db50` SkillTree_RemoveBySkillId_Inferred | **accept-with-gaps** — **thiscall+ret4, vector match, SiblingCastClear flag1, delete+erase sealed (decomp incomplete); product English open** |

---

## `aa_00517400` — Object_RefreshSkillHash_Inferred

### Sealed facts

1. **ABI:** `void __cdecl Refresh(void *pHost, char bReloadSkillDef)` — both formals on stack; epilogue bare **`ret` (`c3`)**. Body `0x00517400`–`0x00517675`.

2. **Null host** early return before SEH/work.

3. **Hash:** `pHost+0x70`; lock byte `hash+0x1d`; head `hash+0x14`; next `node+0x14`; skill `node+8`. Strings: `HashError:TraversalLock…`, `HashError:TraverseToNext…`, `VOG_DEBUG_STOP`.

4. **Per skill:**  
   - Gates `vtbl+0x214()` / `vtbl+0x210(0)` and `skill+0x615&1` → **inline** `CNDDoubleList_InvokePredicateAndRemove` on list `*(pHost+0xB0)`, pred `0x00512bb0`, skillId `skill+0x5fc`, TFID `pHost+0x160..`, **flag 0**.  
   - If `bReloadSkillDef≠0`: `FUN_007e26e0` + `FUN_0054a290` family.  
   - Always `Skill_ReevaluateForCurrentRank`.  
   - Always wide→MB then `FUN_0054f430(skill, mb)` → **`skill+0x1a5`**.

5. **End:** unlock; if gates → `FUN_00516a00(0)`.

6. **Caller:** only `FUN_00517df0` (2 call sites).

7. **Name:** structural `Object_RefreshSkillHash_Inferred`. Auto `Named_VOG_DEBUG_STOP_*` **misleading**.

### Gaps

1. Product/PDB symbol.  
2. English for `vtbl+0x210`/`+0x214`.  
3. Wide-name buffer exact origin post-reevaluate.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_RefreshSkillHash_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00517400.cpp` |
| Legacy alias | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_00517400.cpp` |
| Raw | `docs/reconstruction/raw/aa_00517400_FUN_00517400.md` |
| Annotated | `docs/reconstruction/raw/aa_00517400_FUN_00517400.annotated.md` |

---

## `aa_0052db50` — SkillTree_RemoveBySkillId_Inferred

### Sealed facts

1. **ABI:** `void __thiscall Remove(void *pThis, int nSkillId)` — ECX=this; epilogue **`ret 4`**. Body `0x0052db50`–`0x0052dc15`.

2. **Container:** vector begin/end `this+0x550` / `this+0x554`; element stride **12**; skill* at element+0.

3. **Match:** `skill+0x5fc == nSkillId`.

4. **On match (bytes; decomp incomplete):**  
   - `adj = this + *(*(this+4)+4)`; **host = adj+4** for SiblingCastClear.  
   - TFID from `adj+0x164..` ≡ **host+0x160..** (closes prior open gap on this dual).  
   - `Skill_SiblingCastClear(..., flag=1)`.  
   - `operator_delete(skill)` **returns**.  
   - Erase: slide tail if needed; `end -= 0xC`; **do not advance** iterator.  
   - Loop continues (multi-match possible).

5. **Callees:** `FUN_00514e20` / `Skill_SiblingCastClear`, `operator_delete` only.

6. **Caller:** `FUN_00623a20` only — three skillId slots `+0x178/+0x17c/+0x180`; this = `*(ctx+0x18)->vtbl+0x210(0)`.

7. **Name:** structural `SkillTree_RemoveBySkillId_Inferred`.

### Gaps

1. Product/PDB name; class owning `+0x550`.  
2. Element `+4`/`+8` fields.  
3. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillTree_RemoveBySkillId_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0052db50.cpp` |
| Raw | `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.md` |
| Annotated | `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### RefreshSkillHash (`0x00517400`)

- Port as **full hash walk under lock**, not a single-skill update.
- Sibling clear on this path is **flag 0** (no OKToCastAgain arm) and **inlined** — do not route through `Skill_SiblingCastClear` unless CF-identical.
- Always reevaluate + refresh `skill+0x1a5` name; optional def reload is a separate formal.
- After unlock, honor optional `FUN_00516a00(0)` when host gates pass.

### SkillTree_RemoveBySkillId (`0x0052db50`)

- Port as **vector remove** at `+0x550`, stride 12, with **cast clear flag 1** before free.
- Preserve MI this-adjust (`host = adj+4`) so TFID/list land on the correct base.
- Do **not** trust decompiler “noreturn delete” — compact the vector and continue.
- Distinct from hash refresh; both may exist on related objects.
