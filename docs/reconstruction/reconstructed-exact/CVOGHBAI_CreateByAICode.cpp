// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: switch×2, if×2, goto×2, return×1.
//  - Notable callees: ABS×3, AICode, CVOGHBAIBase_Default_ctor, CVOGHBAIBot_ctor, CVOGHBAICharacterOrMine_ctor, CVOGHBAICreatureBase_ctor, CVOGHBAIDriver_ctor, CVOGHBAIWalkingCreatureTurreted_ctor.
//  - Return sites: 1.

// =============================================================================
// CVOGHBAI_CreateByAICode
// -----------------------------------------------------------------------------
// Purpose:  Factory: allocate and construct the HBAI subclass for a creature AICode
//           from tCreatureAI. AICode is an int switch (decomp shows float
//           bit-patterns 1.4e-45 = 1, etc.).
//
// Address:  0x005d3d10  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d3d10
// System:   npc-ai / HBAI
//
// Args: AICode (int), allocator/context, profile float table (param_3).
//
// AICode -> class (alloc size in paren):
//   1 Character  -> CharacterOrMine (0x110)  [with val-based redirect to Creature]
//   2 Creature   -> CreatureBase (0x100)
//   3 Bot        -> Bot (0x100)
//   4 Mine       -> CharacterOrMine (0x110)
//   5 Driver     -> Driver (0x110)
//   6 WalkingTurreted -> WalkingCreatureTurreted (0xD0)
//   default      -> Base_Default (0xD0)
//
// Post-ctor (except AICode 6): vtbl+0x2c / +0x3c / +0x1c init from profile.
// Allocator: DAT_00b05060 vtbl+0x10(size, 0x29).
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* Factory: switch on AICode (int as float bit pattern). 1 Character, 2 CreatureBase, 3 Bot, 4 Mine,
   5 Driver, 6 WalkingTurreted?, default Base. Profiles from tCreatureAI (AIID->AICode). */
int * CVOGHBAI_CreateByAICode(float param_1,uint32_t /* width from decompiler */ param_2,float *param_3)
{
  float fVar1;
  float fVar2;
  uint32_t /* width from decompiler */ in_EAX;
  int iVar3;
  int *piVar4;
  uint32_t /* width from decompiler */ unaff_EDI;
  float local_8;
  
  fVar2 = param_1;
  switch(param_1) {
  case 1.4013e-45:
    fVar1 = param_3[5];
    param_1 = param_3[10];
    local_8 = *param_3;
    if ((param_1 + fVar1 + local_8) * g_flMultiKillCountBlend <=
        ABS(local_8 - fVar1) + ABS(local_8 - param_1) + ABS(fVar1 - param_1)) goto LAB_005d3d48;
    goto LAB_005d3e15;
  case 2.8026e-45:
LAB_005d3e15:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x100,0x29);
    *(uint16_t *)(iVar3 + 4) = 0x100;
    piVar4 = (int *)CVOGHBAICreatureBase_ctor(unaff_EDI,in_EAX);
    break;
  case 4.2039e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x100,0x29);
    *(uint16_t *)(iVar3 + 4) = 0x100;
    piVar4 = (int *)CVOGHBAIBot_ctor(unaff_EDI,in_EAX);
    break;
  case 5.60519e-45:
LAB_005d3d48:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x110,0x29);
    *(uint16_t *)(iVar3 + 4) = 0x110;
    piVar4 = (int *)CVOGHBAICharacterOrMine_ctor(unaff_EDI,in_EAX);
    break;
  case 7.00649e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x110,0x29);
    *(uint16_t *)(iVar3 + 4) = 0x110;
    piVar4 = (int *)CVOGHBAIDriver_ctor(unaff_EDI,in_EAX);
    break;
  case 8.40779e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);
    *(uint16_t *)(iVar3 + 4) = 0xd0;
    piVar4 = (int *)CVOGHBAIWalkingCreatureTurreted_ctor(unaff_EDI,in_EAX);
    break;
  default:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);
    *(uint16_t *)(iVar3 + 4) = 0xd0;
    piVar4 = (int *)CVOGHBAIBase_Default_ctor(unaff_EDI,in_EAX);
  }
  if (fVar2 != 8.40779e-45) {
    (**(code **)(*piVar4 + 0x2c))(param_3);
    (**(code **)(*piVar4 + 0x3c))(param_1);
    (**(code **)(*piVar4 + 0x1c))(local_8);
  }
  return piVar4;
}
