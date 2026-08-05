# Function record: SkillTree_RemoveBySkillId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052db50` |
| **Canonical name** | `SkillTree_RemoveBySkillId_Inferred` |
| **Ghidra name** | `FUN_0052db50` |
| **Address** | `0x0052db50` |
| **Body range** | `0x0052db50`–`0x0052dc15` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + erase path sealed from bytes; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md`, `reviews/B_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-T) |

## Alias

- `FUN_0052db50` (Ghidra)
- Scaffold path `functions/aa_0052db50_FUN_0052db50.md` (superseded by this record)

## Purpose

Remove skill(s) with matching id from the 12-byte skill-tree vector at `this+0x550..+0x554`: sibling cast clear with **flag 1**, delete skill object, compact vector.

## Signature

```c
void __thiscall SkillTree_RemoveBySkillId_Inferred(void *pThis, int nSkillId);  // ret 4
```

## Algorithm

1. `it = begin(+0x550)`; if `it == end(+0x554)` return.
2. Loop:
   - If `(*it)->skillId(+0x5fc) == nSkillId`:
     - `adj = this + *(*(this+4)+4)`; `host = adj+4`.
     - `Skill_SiblingCastClear(host, id, *(adj+0x164..), flag=1)`.
     - `operator_delete(*it)`.
     - Slide remaining elements left by 12 bytes if needed; `end -= 0xC`.
     - Keep `it` (no advance).
   - Else `it += 12`.
3. Until `it == end`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.md`
- Annotated: `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/SkillTree_RemoveBySkillId_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0052db50.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00517400-0052db50-w20t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `FUN_00623a20` @ `0x00623a4a`, `0x00623a5c`, `0x00623a6e` — this from `vtbl+0x210(0)` on `*(ctx+0x18)`; skillIds `ctx+0x178/17c/180` |
| **Callees** | `Skill_SiblingCastClear` (`0x00514e20`), `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 4 | **High** |
| Vector + match + delete | **High** |
| Erase/slide after delete | **High** (bytes) |
| Flag 1 + host=adj+4 | **High** |
| TFID host+0x160 resolution | **High** |
| Product/PDB name | Open |

## Related

- `aa_00514e20` Skill_SiblingCastClear (caller site flag **1**)
- `aa_00517400` Object_RefreshSkillHash_Inferred
- `aa_00512bb0` Skill_SiblingCastClearPredicate
