// =============================================================================
// FUN_00659d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00659d90
// Address:   0x00659d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659d90 @ 0x00659d90
// Stable ID: aa_00659d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×17, while×3, return×3, for×1, goto×1.
//  - Notable callees: FUN_00638180×8, FUN_006380a0×2, FUN_006381a0×2, FUN_005b3300, FUN_00659d90.
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

uint32_t /* width from decompiler */ FUN_00659d90(int *param_1)



{

  int *piVar1;

  char cVar2;

  uint uVar3;

  char *in_EAX;

  int iVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  

  while( true ) {

    for (; (((cVar2 = *in_EAX, cVar2 == ' ' || (cVar2 == '\t')) || (cVar2 == '\n')) ||

           (cVar2 == '\r')); in_EAX = in_EAX + 1) {

    }

    cVar2 = *in_EAX;

    pcVar8 = in_EAX;

    if (cVar2 == '\0') {

      return 0;

    }

    while (cVar2 != '=') {

      if (cVar2 == '\0') {

        return 1;

      }

      cVar2 = pcVar8[1];

      pcVar8 = pcVar8 + 1;

    }

    DAT_00d02c6c = DAT_00d02c6c + 2;

    iVar9 = (int)pcVar8 - (int)in_EAX;

    iVar4 = FUN_006381a0(iVar9);

    FUN_006380a0(iVar4 + 0xc,in_EAX,iVar9);

    *(uint8_t *)(iVar9 + iVar4 + 0xc) = 0;

    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;

    DAT_00d02c6c = DAT_00d02c6c + -1;

    if (DAT_00d02c6c < 0) {

      FUN_00638180();

    }

    piVar1 = (int *)(iVar4 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    if (pcVar8[1] != '\"') break;

    pcVar7 = pcVar8 + 2;

    cVar2 = pcVar8[2];

    pcVar8 = pcVar7;

    while (cVar2 != '\"') {

      pcVar8 = pcVar8 + 1;

      if (cVar2 == '\0') goto LAB_00659f36;

      cVar2 = *pcVar8;

    }

    iVar10 = (int)pcVar8 - (int)pcVar7;

    iVar9 = FUN_006381a0(iVar10);

    FUN_006380a0(iVar9 + 0xc,pcVar7,iVar10);

    *(uint8_t *)(iVar10 + iVar9 + 0xc) = 0;

    *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;

    DAT_00d02c6c = DAT_00d02c6c + -1;

    if (DAT_00d02c6c < 0) {

      FUN_00638180();

    }

    piVar1 = (int *)(iVar9 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    uVar3 = param_1[1];

    uVar5 = param_1[2] & 0x7fffffff;

    if (uVar3 == uVar5) {

      iVar10 = uVar3 * 2;

      if (uVar3 == 0) {

        iVar10 = 1;

      }

      if ((int)uVar5 < iVar10) {

        iVar6 = uVar5 * 2;

        if ((int)(uVar5 * 2) <= iVar10) {

          iVar6 = iVar10;

        }

        FUN_005b3300(param_1,iVar6,8);

      }

    }

    param_1[1] = uVar3 + 1;

    piVar1 = (int *)(*param_1 + uVar3 * 8);

    if (piVar1 != (int *)0x0) {

      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;

      *piVar1 = iVar4 + 0xc;

      *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;

      piVar1[1] = iVar9 + 0xc;

    }

    in_EAX = pcVar8 + 1;

    piVar1 = (int *)(iVar9 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    piVar1 = (int *)(iVar4 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

  }

LAB_00659f36:

  DAT_00d02c6c = DAT_00d02c6c + -1;

  if (DAT_00d02c6c < 0) {

    FUN_00638180();

  }

  piVar1 = (int *)(iVar4 + 8);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  return 1;

}
