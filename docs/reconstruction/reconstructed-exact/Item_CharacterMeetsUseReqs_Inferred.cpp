// =============================================================================
// Item_CharacterMeetsUseReqs_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Return whether a character meets an item's use/equip requirements
//           (race/faction wildcards, level cap 80, accuracy/perception/theory/
//           tech floors, optional powerplant capacity, optional special-mode
//           presence when flag!=0).
//
// Address:  0x00514390  (autoassault.exe, image base 0x400000)
// Body:     0x00514390–0x005145a3 (532 bytes)
// Stable:   aa_00514390
// System:   inventory / equip / use gates
// Ghidra:   FUN_00514390
//
// ABI:      __thiscall  uint32_t Item_CharacterMeetsUseReqs(Item *item, void *ch, uint32_t flag)
//           ECX=item, stack ch + flag; RET 8; AL = 0/1
//
// Exactness: CF mirrors authoritative raw decompile; sealed callee names applied.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W20-O seal).
// =============================================================================

#include <cstdint>

typedef unsigned char byte;
typedef unsigned int uint;

// Sealed / named callees
short FUN_004c4070(void);                       // Object_GetTargetAccuracyBase (thiscall ch)
short FUN_004c41c0(void);                       // Creature_GetPerception
short FUN_004c4140(void);                       // Creature_GetTheory
int   Character_GetTechForPoolCalcs(void *character);
int   FUN_0052ada0(uint32_t /* width from decompiler */ powerplantKey);
void  FUN_00402c40(void);
int   FUN_00411900(void *iterState);

/* Item_CharacterMeetsUseReqs_Inferred — CF from Ghidra raw (authoritative). */

uint32_t __thiscall Item_CharacterMeetsUseReqs_Inferred(int param_1, void *param_2,
                                                         uint32_t param_3)
{
  byte bVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;

  if ((0 < *(int *)((int)param_2 + 0x6b4)) ||
      (*(int *)(*(int *)(param_1 + 0xa8) + 0x38) == 0x1a)) {
    return 1;
  }
  iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x14))();
  if (((iVar5 == -1) ||
       (bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xac +
                                           (int)param_2) +
                          0x3c) +
                0x532),
        uVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x14))(),
        uVar6 == bVar1)) &&
      ((uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3e0),
        uVar6 == 0xffffffff ||
            (uVar6 ==
             *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xac +
                                        (int)param_2) +
                       0x3c) +
              0x531))))) {
    iVar7 = (int)*(short *)(param_1 + 0xe8) + (int)*(short *)(param_1 + 0xea);
    iVar5 = 0x50;
    if (iVar7 < 0x51) {
      iVar5 = iVar7;
    }
    iVar7 =
        (**(code **)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2) +
                     0x27c))();
    if ((((((short)iVar5 <= iVar7) &&
           (sVar2 = *(short *)(param_1 + 0xec), sVar4 = FUN_004c4070(), sVar2 <= sVar4)) &&
          (sVar2 = *(short *)(param_1 + 0xee), sVar4 = FUN_004c41c0(), sVar2 <= sVar4)) &&
         ((sVar2 = *(short *)(param_1 + 0xf2), sVar4 = FUN_004c4140(), sVar2 <= sVar4 &&
           (sVar2 = *(short *)(param_1 + 0xf0),
            iVar5 = Character_GetTechForPoolCalcs(param_2), sVar2 <= (short)iVar5)))) &&
        ((((*(uint *)(param_1 + 0x17c) >> 0x13 & 1) == 0 ||
           ((iVar5 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c), iVar5 == 0 ||
             (*(int *)(iVar5 + 0x4ac) < 0)))) ||
          (iVar5 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c), iVar7 = *(int *)(iVar5 + 0x4b0),
           iVar5 = FUN_0052ada0(*(uint32_t *)(iVar5 + 0x4ac)), iVar7 <= iVar5)))) {
      if ((((char)param_3 != '\0') &&
           ((*(byte *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3f2) & 0x80) != 0)) &&
          ((iVar5 = *(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xa8 + (int)param_2),
            *(char *)(iVar5 + 0xf5) != '\0' || (*(char *)(iVar5 + 0xf6) != '\0')))) {
        param_3 = 0;
        FUN_00402c40();
        bVar3 = false;
        iVar5 = FUN_00411900(&param_3);
        while (iVar5 != 0) {
          if (*(int *)(iVar5 + 0x62c) == 0x26) {
            bVar3 = true;
            break;
          }
          iVar5 = FUN_00411900(&param_3);
        }
        *(uint8_t *)(*(int *)(param_1 + 0x70) + 0x1d) = 0;
        if (!bVar3) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}
