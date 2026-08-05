// =============================================================================
// FUN_004141c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004141c0
// Address:   0x004141c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004141c0 @ 0x004141c0
// Stable ID: aa_004141c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: ROUND×2, FUN_004141c0.
//  - Return sites: 2.

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

float * FUN_004141c0(float *param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float *in_EAX;

  int iVar4;

  int *unaff_ESI;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iStack_10;

  int iStack_c;

  uint8_t local_8 [8];

  

  (**(code **)(*unaff_ESI + 0x140))(local_8,1);

  if (*(char *)((int)unaff_ESI + 0x5b9) != '\0') {

    fVar7 = DAT_00af931c;

    if (DAT_00af931c <= DAT_00af9320) {

      fVar7 = DAT_00af9320;

    }

    fVar1 = (float)unaff_ESI[0x140];

    if (iStack_10 < iStack_c) {

      iStack_c = iStack_10;

    }

    if (DAT_00af9320 <= DAT_00af931c) {

      iStack_10 = iStack_c;

      if (DAT_00af9320 < DAT_00af931c) {

        iStack_c = (int)ROUND(((float)iStack_c / DAT_00af931c) * DAT_00af9320);

      }

    }

    else {

      iStack_10 = (int)ROUND(((float)iStack_c / DAT_00af9320) * DAT_00af931c);

    }

    fVar6 = (float)unaff_ESI[0x141];

    fVar8 = *in_EAX / DAT_00af931c;

    iVar2 = unaff_ESI[0x15a];

    iVar5 = 0;

    iVar4 = 0;

    if (DAT_00af9320 <= DAT_00af931c) {

      if (DAT_00af9320 < DAT_00af931c) {

        iVar4 = -(iStack_c / 2);

      }

    }

    else {

      iVar5 = iStack_10 / 2;

    }

    iVar3 = unaff_ESI[0x15c];

    param_1[1] = (float)(unaff_ESI[0x15d] + iVar4) -

                 ((in_EAX[2] / DAT_00af9320) *

                  (float)unaff_ESI[0x141] * (float)iStack_c * (fVar7 / fVar1) -

                 (float)unaff_ESI[0x15b]);

    *param_1 = (float)(iVar3 + iVar5) +

               (fVar8 * fVar6 * (float)iStack_10 * (fVar7 / fVar1) - (float)iVar2);

    return param_1;

  }

  fVar7 = DAT_00af931c;

  if (DAT_00af9320 <= DAT_00af931c) {

    fVar7 = DAT_00af9320;

  }

  fVar1 = (float)unaff_ESI[0x171];

  fVar6 = (*in_EAX / fVar7) * (float)iStack_10 * (float)unaff_ESI[0x141] - (float)unaff_ESI[0x15a];

  fVar8 = (in_EAX[2] / fVar7) * (float)iStack_c * (float)unaff_ESI[0x141] - (float)unaff_ESI[0x15b];

  fVar7 = (float)unaff_ESI[0x16f];

  iVar2 = unaff_ESI[0x15c];

  param_1[1] = (float)unaff_ESI[0x15d] -

               ((0.0 - (float)unaff_ESI[0x16f] * fVar6) - (float)unaff_ESI[0x171] * fVar8);

  *param_1 = (fVar7 * fVar8 - fVar1 * fVar6) + (float)iVar2;

  return param_1;

}
