# Annotated low-level: Skill_GetCategoryCooldownRemaining

| Field | Value |
|---|---|
| Stable ID | `aa_00519150` |
| VA | `0x00519150` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00519150`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Skill_GetCategoryCooldownRemaining(nCategoryId, bAsSeconds)
   
   Parameters:
     nCategoryId - skill+0x5e8 category key
     bAsSeconds  - nonzero returns remaining as float seconds (ms * g_flMsToSeconds)
   
   Algorithm: map lookup; entry +0x10 start, +0x14 duration; erase if expired.
   Returns: remaining (float10) or 0 if none.
   
   VERIFIED against quickbar consumers. */

float10 * Skill_GetCategoryCooldownRemaining
                    (float10 *__return_storage_ptr__,int nCategoryId,char bAsSeconds)

{
  float10 *pfVar1;
  uint nDeadline;
  void *in_ECX;
  void **ppvVar2;
  float10 **ppfVar3;
  void *pMapIt;
  int *pTmp;
  
  ppfVar3 = &__return_storage_ptr__;
  ppvVar2 = &pMapIt;
  pMapIt = in_ECX;
  Skill_GetCategoryCooldownMap(in_ECX);
  FUN_00418b80(ppvVar2,ppfVar3);
  pfVar1 = Skill_GetCategoryCooldownMap(in_ECX);
  if (pMapIt != *(void **)((int)pfVar1 + 4)) {
    __return_storage_ptr__ = *(float10 **)((int)pMapIt + 0x14);
    nDeadline = *(int *)((int)pMapIt + 0x10) + (int)__return_storage_ptr__;
    if (g_dwClientTickMs < nDeadline) {
      pfVar1 = (float10 *)(nDeadline - g_dwClientTickMs);
      if ((char)nCategoryId != '\0') {
        return pfVar1;
      }
      return pfVar1;
    }
    pTmp = &nCategoryId;
    Skill_GetCategoryCooldownMap(in_ECX);
    pfVar1 = (float10 *)FUN_004188e0(pTmp,pMapIt);
  }
  return pfVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
