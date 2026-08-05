// =============================================================================
// FUN_0072cbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072cbc0
// Address:   0x0072cbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072cbc0 @ 0x0072cbc0
// Stable ID: aa_0072cbc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_0072cbc0, SQRT.
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

void __fastcall FUN_0072cbc0(float *param_1,int param_2,float param_3,float *param_4)



{

  uint uVar1;

  float *in_EAX;

  uint uVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  uVar1 = (uint)param_3;

  fVar4 = 0.0;

  uVar2 = 0;

  param_3 = 0.0;

  if (3 < (int)uVar1) {

    iVar3 = (uVar1 - 4 >> 2) + 1;

    uVar2 = iVar3 * 4;

    do {

      fVar5 = (*param_1 - *in_EAX) * (*param_1 - *in_EAX) +

              (param_1[2] - in_EAX[2]) * (param_1[2] - in_EAX[2]) +

              (param_1[1] - in_EAX[1]) * (param_1[1] - in_EAX[1]);

      if (fVar4 < fVar5) {

        fVar4 = fVar5;

      }

      fVar7 = param_1[2] - *(float *)((int)in_EAX + param_2 + 8);

      fVar5 = *param_1 - *(float *)((int)in_EAX + param_2);

      fVar6 = param_1[1] - *(float *)((int)in_EAX + param_2 + 4);

      fVar5 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;

      if (fVar4 < fVar5) {

        fVar4 = fVar5;

      }

      fVar7 = param_1[2] - *(float *)((int)in_EAX + param_2 * 2 + 8);

      fVar5 = *param_1 - *(float *)((int)in_EAX + param_2 * 2);

      fVar6 = param_1[1] - *(float *)((int)in_EAX + param_2 * 2 + 4);

      fVar5 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;

      if (fVar4 < fVar5) {

        fVar4 = fVar5;

      }

      fVar7 = param_1[2] - *(float *)((int)in_EAX + param_2 * 3 + 8);

      fVar5 = *param_1 - *(float *)((int)in_EAX + param_2 * 3);

      fVar6 = param_1[1] - *(float *)((int)in_EAX + param_2 * 3 + 4);

      in_EAX = in_EAX + param_2;

      fVar5 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;

      if (fVar4 < fVar5) {

        fVar4 = fVar5;

      }

      iVar3 = iVar3 + -1;

      param_3 = fVar4;

    } while (iVar3 != 0);

  }

  if (uVar2 < uVar1) {

    iVar3 = uVar1 - uVar2;

    do {

      fVar4 = (*param_1 - *in_EAX) * (*param_1 - *in_EAX) +

              (param_1[2] - in_EAX[2]) * (param_1[2] - in_EAX[2]) +

              (param_1[1] - in_EAX[1]) * (param_1[1] - in_EAX[1]);

      if (param_3 < fVar4) {

        param_3 = fVar4;

      }

      in_EAX = (float *)((int)in_EAX + param_2);

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  *param_4 = SQRT(param_3);

  return;

}
