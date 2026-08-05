# Raw capture: Vehicle_GetSkillCooldownModifier

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a9b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052a9b0` |
| **Canonical name** | `Vehicle_GetSkillCooldownModifier` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
