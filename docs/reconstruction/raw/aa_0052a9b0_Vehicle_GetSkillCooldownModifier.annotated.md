# Annotated low-level: Vehicle_GetSkillCooldownModifier

| Field | Value |
|---|---|
| Stable ID | `aa_0052a9b0` |
| VA | `0x0052a9b0` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052a9b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_GetSkillCooldownModifier
   
   Parameters:
     this           - character/vehicle context (thiscall)
     categoryScale  - base category scale (default g_flOne=1.0 if unmapped)
   
   Algorithm:
     look up category scale map entry
     if vehicle has power plant at +0x268: scale *= plant+0xCC
   
   Returns: float10 cooldown scale for cast-again duration
   
   Used by CVOGHBOKToCastAgain_ctor / hotbar recharge UI. */

float10 * __thiscall
Vehicle_GetSkillCooldownModifier(void *this,float10 *__return_storage_ptr__,float flCategoryScale)

{
  float10 *pfVar1;
  int *unaff_ESI;
  void *pCategoryIt;
  
  pCategoryIt = this;
  Map_LowerBoundFindByIntKey
            ((void *)((int)this + 0xc70),&pCategoryIt,&__return_storage_ptr__,unaff_ESI);
  pfVar1 = (float10 *)0x0;
  if (*(int *)((int)this + 0x250) != 0) {
    pfVar1 = *(float10 **)(*(int *)((int)this + 0x250) + 0x268);
  }
  return pfVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
