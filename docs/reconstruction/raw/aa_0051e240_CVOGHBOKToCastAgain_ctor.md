# Raw capture: CVOGHBOKToCastAgain_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e240` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051e240` |
| **Canonical name** | `CVOGHBOKToCastAgain_ctor` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBOKToCastAgain_ctor
   
   Parameters:
     this           - cast-again heartbeat object
     pSkillRuntime  - skill runtime (esetCoolDown at +0x10, category at +0x5E8)
     nChargeDelayMs - skill charge delay (esetCharge)
   
   Algorithm:
     durationMs = ceil(skill+0x10 * Vehicle_GetSkillCooldownModifier) + chargeDelay
     insert category into cooldown map unless category == -1
     type field = 8; attach skill as owner
   
   Returns: this
   
   Hotbar reads remaining via category map or skill cast flags. */

void * __thiscall CVOGHBOKToCastAgain_ctor(void *this,void *pSkillRuntime,int nChargeDelayMs)

{
  int nTemp;
  void *this_00;
  uint nDurationClamped;
  float unaff_EBX;
  float10 extraout_ST0;
  float10 flEquipModifier;
  double dVar1;
  float10 *__return_storage_ptr__;
  undefined8 uVar2;
  float flCategoryScale;
  void *local_1c;
  uint uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3738;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_1c = this;
  CVOGHBBase_ctor(this);
  local_4 = 0;
  *(void ***)this = &g_pVtbl_CVOGHBOKToCastAgain;
  CVOGHBBase_SetPeriodAndCounter(this,1,true);
  flCategoryScale = 0.0;
  nTemp = (**(code **)(*(int *)pSkillRuntime + 0x210))();
  if (nTemp == 0) {
    flEquipModifier = (float10)unaff_EBX;
  }
  else {
    __return_storage_ptr__ = *(float10 **)((int)pSkillRuntime + 0x5ec);
    this_00 = (void *)(**(code **)(*(int *)pSkillRuntime + 0x210))(0);
    Vehicle_GetSkillCooldownModifier(this_00,__return_storage_ptr__,flCategoryScale);
    flEquipModifier = extraout_ST0;
  }
  dVar1 = ceil((double)((float10)*(int *)((int)pSkillRuntime + 0x10) * flEquipModifier));
                    /* durationMs = ceil(skill.cooldownMs * equipModifier) + chargeDelay; stored at
                       HB+0x8 */
  *(int *)((int)this + 8) = (int)ROUND((float)dVar1) + nChargeDelayMs;
  nTemp = (**(code **)(*(int *)pSkillRuntime + 0x1dc))();
  if (nTemp != 0) {
    nTemp = (**(code **)(*(int *)pSkillRuntime + 0x1dc))();
    if (0 < *(int *)(nTemp + 0x6b4)) {
      nDurationClamped = *(uint *)((int)this + 8);
      if (499 < nDurationClamped) {
        nDurationClamped = 500;
      }
      *(uint *)((int)this + 8) = nDurationClamped;
    }
  }
  if (*(void **)((int)pSkillRuntime + 0x5e8) != (void *)0xffffffff) {
    uStack_14 = *(undefined4 *)((int)this + 8);
    uStack_18 = g_dwClientTickMs;
    uVar2 = CONCAT44(&local_1c,&stack0xffffffd8);
    local_1c = *(void **)((int)pSkillRuntime + 0x5e8);
    Skill_GetCategoryCooldownMap(pSkillRuntime);
    Skill_CategoryCooldownMap_Insert(uVar2);
  }
  CVOGHBBase_AttachOwnerObject(this,pSkillRuntime);
  *(void **)((int)this + 0x24) = pSkillRuntime;
  *(undefined4 *)((int)this + 0x1c) = 8;
  ExceptionList = pvStack_10;
  return this;
}
```
---

## Versioned append — 2026-07-29 dual residual asm seal (do not rewrite raw body above)

Authority: machine code + `read_memory` (not Ghidra plate formals). Scratch: `reviews/a_0051e240.md`.

| Fact | Evidence |
|------|----------|
| `RET 0xC` | epilogue `0051e38b` — **3** stack dwords |
| Signature | `(thisHb, pOwnerEntity, pSkillRuntime, nChargeDelayMs)` |
| Regs | ESI=this, EDI=owner (stack0), EBX=skill (stack1) |
| Vtbl | `mov [esi], 0x009ce1c4` |
| Period | `SetPeriodAndCounter(this, 1, 1)` |
| No-vehicle mod | `g_flOne` @ `0x00a0f2a0` = `00 00 80 3f` (1.0f) — **not** unaff_EBX |
| Vehicle/pool vfuncs | **owner**.vtbl+0x210 / +0x1dc (not skill) |
| Duration | ROUND(ceil(skill+0x10 × mod)) + charge → HB+0x8 |
| Clamp | if pool+0x6b4≥1 and duration≥500 → 500 (`0x1F4`) |
| Category insert | if skill+0x5e8≠-1: `{key, DAT_00b041cc, HB+0x8}` via GetMap(**owner**)+Insert |
| Attach | `AttachOwnerObject(hb, **owner**)` |
| Skill / type | HB+0x24=skill; HB+0x1c=8 |

Corrected prototype:

```c
void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb, void* pOwnerEntity, void* pSkillRuntime, int nChargeDelayMs);
// RET 0xC
```

Dual residual: `reviews/A|B_aa_0051e240_*`, function record, clean plate.
