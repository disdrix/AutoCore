# Raw capture: Skill_LocalRangeTargetCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553130` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00553130` |
| **Canonical name** | `Skill_LocalRangeTargetCheck` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_LocalRangeTargetCheck(pCaster, pSkill, pInferredArg)
   
   Accuracy/range gate used by Skill_LocalCastValidate and NPC path.
   May start short cast-again on miss (return 0x0f).
   
   Returns: 0 ok, else eSkillResponses-like code
   INFERRED: exact accuracy formula. */

int __thiscall Skill_LocalRangeTargetCheck(void *this,void *pCaster,void *pSkill,void *pInferredArg)

{
  ushort uVar1;
  int iVar2;
  int unaff_EDI;
  float fVar3;
  
  if ((((pCaster != (void *)0x0) && (*(int *)((int)pCaster + 0xa4) != 0)) &&
      (*(float *)((int)this + 0x108) != g_flZero)) &&
     (*(char *)(*(int *)((int)pCaster + 0xa4) + 0x7e) != '\0')) {
    iVar2 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar2 + 0xc)) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
    fVar3 = (float)uVar1 * DAT_00aaa638;
    if (*(float *)((int)this + 0x108) <= fVar3 && fVar3 != *(float *)((int)this + 0x108)) {
      if ((char)pInferredArg == '\0') {
        Skill_StartCastAgainHeartbeat(pCaster,this,*(void **)((int)this + 0x10),unaff_EDI);
      }
      return 0xf;
    }
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x5f0) + 0x1c))(pCaster,this);
  return iVar2;
}
```
