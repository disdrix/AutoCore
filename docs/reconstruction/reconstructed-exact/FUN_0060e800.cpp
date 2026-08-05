// =============================================================================
// FUN_0060e800
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e800
// Address:   0x0060e800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060e800 @ 0x0060e800
// Stable ID: aa_0060e800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, goto×1.
//  - Notable callees: CONCAT31, CVOGReaction_FailMission, FUN_0060e800, SQRT.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall FUN_0060e800(int param_1,int param_2,int param_3,float *param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  int iVar6;

  int *in_stack_0000001c;

  

  if (param_4 == (float *)0xc) {

    if (*(char *)(param_1 + 0x18) != '\0') {

      uVar5 = CVOGReaction_FailMission(**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0x14c));

      return uVar5 & 0xffffff00;

    }

  }

  else if ((param_4 == (float *)0xb) && (in_stack_0000001c != (int *)0x0)) {

    param_4 = (float *)(int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

    if ((int)param_4 < *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0xd0)) {

      iVar6 = (int)param_4 % *(int *)(param_1 + 0xd0);

      param_4 = (float *)in_stack_0000001c[0x58];

      if ((param_4 == *(float **)(param_1 + 0x30 + iVar6 * 8)) &&

         (in_stack_0000001c[0x59] == *(int *)(param_1 + 0x34 + iVar6 * 8))) {

        (**(code **)(*in_stack_0000001c + 0x144))();

        fVar2 = (float)in_stack_0000001c[0x20];

        fVar3 = (float)in_stack_0000001c[0x21];

        fVar4 = (float)in_stack_0000001c[0x22];

        param_4 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2)

                                       + 0x1a0))();

        fVar2 = SQRT((fVar2 - *param_4) * (fVar2 - *param_4) +

                     (fVar3 - param_4[1]) * (fVar3 - param_4[1]) +

                     (fVar4 - param_4[2]) * (fVar4 - param_4[2]));

        if ((*(char *)(param_1 + 0x10) != '\0') &&

           (fVar2 < *(float *)(param_1 + 0x14) + DAT_00aaa688)) {

          pfVar1 = (float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

          *pfVar1 = *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4) + g_flOne;

          return CONCAT31((int3)((uint)pfVar1 >> 8),1);

        }

        if (*(char *)(param_1 + 0x18) != '\0') {

          if (fVar2 <= *(float *)(param_1 + 0x1c) - DAT_00aaa688) {

            param_4 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 +

                                                    param_2) + 0x198))();

            if ((char)param_4 == '\0') goto LAB_0060e9c8;

          }

          param_4 = (float *)CVOGReaction_FailMission

                                       (**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0x14c));

        }

      }

    }

  }

LAB_0060e9c8:

  return (uint)param_4 & 0xffffff00;

}
