# Annotated low-level: CVOGHBAI_CreateByAICode

| Field | Value |
|---|---|
| Stable ID | a_005d3d10 |
| VA | 0x005d3d10 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

AI factory: construct HB AI by AI code.

## Plate / prior RE notes

`
Factory: switch on AICode (int as float bit pattern). 1 Character, 2 CreatureBase, 3 Bot, 4 Mine,
   5 Driver, 6 WalkingTurreted?, default Base. Profiles from tCreatureAI (AIID->AICode).
`

## Named callees (decompiler)

- CVOGHBAI_CreateByAICode
- CVOGHBAICreatureBase_ctor
- CVOGHBAIBot_ctor
- CVOGHBAICharacterOrMine_ctor
- CVOGHBAIDriver_ctor
- CVOGHBAIWalkingCreatureTurreted_ctor
- CVOGHBAIBase_Default_ctor

## Machine-level notes

- Source: raw capture for a_005d3d10.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
/* Factory: switch on AICode (int as float bit pattern). 1 Character, 2 CreatureBase, 3 Bot, 4 Mine,
   5 Driver, 6 WalkingTurreted?, default Base. Profiles from tCreatureAI (AIID->AICode). */

int * CVOGHBAI_CreateByAICode(float param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined4 in_EAX;
  int iVar3;
  int *piVar4;
  undefined4 unaff_EDI;
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
    *(undefined2 *)(iVar3 + 4) = 0x100;
    piVar4 = (int *)CVOGHBAICreatureBase_ctor(unaff_EDI,in_EAX);
    break;
  case 4.2039e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x100,0x29);
    *(undefined2 *)(iVar3 + 4) = 0x100;
    piVar4 = (int *)CVOGHBAIBot_ctor(unaff_EDI,in_EAX);
    break;
  case 5.60519e-45:
LAB_005d3d48:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x110,0x29);
    *(undefined2 *)(iVar3 + 4) = 0x110;
    piVar4 = (int *)CVOGHBAICharacterOrMine_ctor(unaff_EDI,in_EAX);
    break;
  case 7.00649e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x110,0x29);
    *(undefined2 *)(iVar3 + 4) = 0x110;
    piVar4 = (int *)CVOGHBAIDriver_ctor(unaff_EDI,in_EAX);
    break;
  case 8.40779e-45:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);
    *(undefined2 *)(iVar3 + 4) = 0xd0;
    piVar4 = (int *)CVOGHBAIWalkingCreatureTurreted_ctor(unaff_EDI,in_EAX);
    break;
  default:
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);
    *(undefined2 *)(iVar3 + 4) = 0xd0;
    piVar4 = (int *)CVOGHBAIBase_Default_ctor(unaff_EDI,in_EAX);
  }
  if (fVar2 != 8.40779e-45) {
    (**(code **)(*piVar4 + 0x2c))(param_3);
    (**(code **)(*piVar4 + 0x3c))(param_1);
    (**(code **)(*piVar4 + 0x1c))(local_8);
  }
  return piVar4;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
