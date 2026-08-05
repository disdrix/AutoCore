// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: ABS, FUN_0061b570, FUN_007a4480.
//  - Return sites: 3.

// =============================================================================
// Skill_Creature_d_I64d_0_2f_0_2f_tried_to_cast_skill_d__0061b570
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b570
// Address:   0x0061b570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Creature %d %I64d %0.2f %0.2f, tried to cast skill %d without being activated"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Skill_Creature_d_I64d_0_2f_0_2f_tried_to_cast_skill_d__0061b570(int *param_1,int param_2)



{

  int iVar1;

  float fVar2;

  int *piVar3;

  float *pfVar4;

  int iVar5;

  float10 fVar6;

  

  if (*(char *)(param_2 + 0x20) != '\0') {

    piVar3 = (int *)(**(code **)(*param_1 + 0x214))();

    if ((piVar3 == (int *)0x0) || (iVar1 = piVar3[0x94], iVar1 == 0)) {

      fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(piVar3[1] + 4) + 0xac + (int)piVar3) + 0x3c) +

                        0x4d4);

      fVar6 = (float10)(**(code **)(*piVar3 + 0x58))();

      if ((float10)DAT_00a0f298 < ABS((float10)fVar2 - fVar6)) {

        return 9;

      }

    }

    else if ((*(int *)(iVar1 + 0x1a0) == 0) || (*(int *)(*(int *)(iVar1 + 0x1a0) + 4) == 0)) {

      if (*(int *)(iVar1 + 8) == 0) {

        iVar5 = *(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1;

      }

      else {

        iVar5 = *(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0;

      }

      if (*(int *)(iVar1 + 8) == 0) {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

      }

      else {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

      }

      iVar1 = *(int *)(piVar3[1] + 4);

      FUN_007a4480(0,"Creature %d %I64d %0.2f %0.2f, tried to cast skill %d without being activated"

                   ,*(uint32_t /* width from decompiler */ *)(*(int *)((int)piVar3 + iVar1 + 0xac) + 0x34),

                   *(uint32_t /* width from decompiler */ *)((int)piVar3 + iVar1 + 0x164),

                   *(uint32_t /* width from decompiler */ *)((int)piVar3 + iVar1 + 0x168),(double)*pfVar4,

                   (double)*(float *)(iVar5 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc));

      return 3;

    }

  }

  return 0;

}
