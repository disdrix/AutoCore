// =============================================================================
// FUN_006f3d90
// -----------------------------------------------------------------------------
// Stable ID: aa_006f3d90
// Address:   0x006f3d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f3d90 @ 0x006f3d90
// Stable ID: aa_006f3d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×2, while×2, do×1.
//  - Notable callees: FUN_006f3d90.
//  - Return sites: 4.

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

void __thiscall FUN_006f3d90(int *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  fVar1 = *(float *)(param_2 + 0xc);

  iVar4 = *param_1 + -1;

  if (3 < *param_1) {

    do {

      iVar2 = *(int *)(param_1[2] + iVar4 * 4);

      if ((iVar2 == 0) || (fVar1 <= *(float *)(iVar2 + 0xc))) goto LAB_006f3eae;

      *(int *)(param_1[2] + iVar4 * 4 + 4) = iVar2;

      iVar2 = *(int *)(param_1[2] + -4 + iVar4 * 4);

      if ((iVar2 == 0) || (fVar1 <= *(float *)(iVar2 + 0xc))) {

        *(int *)(param_1[2] + 4 + (iVar4 + -1) * 4) = param_2;

        *param_1 = *param_1 + 1;

        return;

      }

      *(int *)(param_1[2] + iVar4 * 4) = iVar2;

      iVar2 = *(int *)(param_1[2] + -8 + iVar4 * 4);

      if ((iVar2 == 0) || (fVar1 <= *(float *)(iVar2 + 0xc))) {

        *(int *)(param_1[2] + 4 + (iVar4 + -2) * 4) = param_2;

        *param_1 = *param_1 + 1;

        return;

      }

      *(int *)(param_1[2] + -4 + iVar4 * 4) = iVar2;

      iVar2 = *(int *)(param_1[2] + -0xc + iVar4 * 4);

      if ((iVar2 == 0) || (fVar1 <= *(float *)(iVar2 + 0xc))) {

        iVar4 = iVar4 + -3;

        goto LAB_006f3eae;

      }

      *(int *)(param_1[2] + -8 + iVar4 * 4) = iVar2;

      iVar4 = iVar4 + -4;

    } while (2 < iVar4);

  }

  if (-1 < iVar4) {

    while( true ) {

      iVar3 = *(int *)(param_1[2] + iVar4 * 4);

      iVar2 = iVar4 * 4;

      if ((iVar3 == 0) || (fVar1 <= *(float *)(iVar3 + 0xc))) break;

      iVar4 = iVar4 + -1;

      *(int *)(param_1[2] + iVar2 + 4) = iVar3;

      if (iVar4 < 0) {

        *(int *)(param_1[2] + 4 + iVar4 * 4) = param_2;

        *param_1 = *param_1 + 1;

        return;

      }

    }

  }

LAB_006f3eae:

  *(int *)(param_1[2] + 4 + iVar4 * 4) = param_2;

  *param_1 = *param_1 + 1;

  return;

}
