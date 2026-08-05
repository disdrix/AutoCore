// =============================================================================
// FUN_00644eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00644eb0
// Address:   0x00644eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00644eb0 @ 0x00644eb0
// Stable ID: aa_00644eb0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, switch×1, return×1.
//  - Notable callees: FUN_006436e0×3, CVOGReaction_RandomUnitScalar, FUN_004a8d40, FUN_00643a50, FUN_00643ee0, FUN_00643fc0, FUN_006441b0, FUN_00644eb0.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 1.

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

void __thiscall FUN_00644eb0(int *param_1,int param_2,float param_3,float param_4,char param_5)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  

  fVar8 = g_flOne / *(float *)(param_2 + 0x18);

  uVar2 = (uint)(fVar8 * param_3);

  uVar4 = (uint)(fVar8 * param_4);

  param_3 = (float)(uVar2 & ((int)uVar2 < 1) - 1);

  uVar2 = *(int *)(param_2 + 0x10) - 1;

  if ((int)uVar2 <= (int)param_3) {

    param_3 = (float)uVar2;

  }

  uVar2 = *(int *)(param_2 + 0x14) - 1;

  uVar4 = ((int)uVar4 < 1) - 1 & uVar4;

  if ((int)uVar4 < (int)uVar2) {

    uVar2 = uVar4;

  }

  uVar5 = (int)param_3 - param_1[1] / 2;

  uVar5 = ((int)uVar5 < 1) - 1 & uVar5;

  uVar4 = uVar2 - param_1[1] / 2;

  uVar4 = ((int)uVar4 < 1) - 1 & uVar4;

  switch(param_1[2]) {

  case 0:

    FUN_006436e0(uVar5,uVar4,param_2);

    break;

  case 1:

    FUN_006436e0(uVar5,uVar4,param_2);

    break;

  case 2:

    FUN_006441b0(uVar5,uVar4,param_3,uVar2,param_2);

    break;

  case 3:

    FUN_00643fc0(uVar5,uVar4,param_2);

    break;

  case 4:

    FUN_006436e0(uVar5,uVar4,param_2);

    iVar6 = 0;

    param_1[2] = 4;

    if (0 < param_1[1]) {

      do {

        iVar7 = 0;

        if (0 < param_1[1]) {

          do {

            iVar3 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar3 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

            }

            uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

            *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

            iVar3 = param_1[1] * iVar7;

            iVar7 = iVar7 + 1;

            *(float *)(*param_1 + (iVar3 + iVar6) * 4) =

                 ((float)uVar1 * DAT_00aaa638 - DAT_00a0f298) * (float)param_1[4] *

                 g_flLevelUpUiBase_Inferred;

          } while (iVar7 < param_1[1]);

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < param_1[1]);

    }

    FUN_00643ee0(param_1[3]);

    break;

  case 5:

    FUN_00643a50(uVar5,uVar4,param_2);

    break;

  default:

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (param_5 != '\0') {

    FUN_004a8d40(uVar5 - 2,uVar4 - 2,param_1[1] + 2 + uVar5,param_1[1] + 2 + uVar4);

  }

  return;

}
