// =============================================================================
// FUN_00714590
// -----------------------------------------------------------------------------
// Stable ID: aa_00714590
// Address:   0x00714590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714590 @ 0x00714590
// Stable ID: aa_00714590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×23, while×4, do×3, goto×2, return×1.
//  - Notable callees: FUN_00714590.
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

void FUN_00714590(int *param_1,int param_2,int *param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int local_8;

  int local_4;

  

  iVar6 = 0;

  local_4 = 0;

  iVar3 = 1;

  iVar2 = *param_1;

  local_8 = iVar2;

  if (iVar2 < 0) {

    iVar4 = 2;

    piVar5 = param_1 + 3;

    do {

      if (param_2 < iVar4 + 3) {

        if (iVar2 < 0) {

          piVar5 = param_1 + iVar3;

          goto LAB_0071465e;

        }

        break;

      }

      iVar1 = piVar5[-2];

      if (iVar2 < iVar1) {

        iVar2 = iVar1;

        iVar6 = iVar3;

      }

      if (iVar1 < local_8) {

        local_8 = iVar1;

        local_4 = iVar3;

      }

      iVar1 = piVar5[-1];

      if (iVar2 < iVar1) {

        iVar2 = iVar1;

        iVar6 = iVar4;

      }

      if (iVar1 < local_8) {

        local_8 = iVar1;

        local_4 = iVar4;

      }

      iVar1 = *piVar5;

      if (iVar2 < iVar1) {

        iVar6 = iVar4 + 1;

        iVar2 = iVar1;

      }

      if (iVar1 < local_8) {

        local_4 = iVar4 + 1;

        local_8 = iVar1;

      }

      iVar1 = piVar5[1];

      if (iVar2 < iVar1) {

        iVar6 = iVar4 + 2;

        iVar2 = iVar1;

      }

      if (iVar1 < local_8) {

        local_4 = iVar4 + 2;

        local_8 = iVar1;

      }

      iVar3 = iVar3 + 4;

      piVar5 = piVar5 + 4;

      iVar4 = iVar4 + 4;

    } while (iVar2 < 0);

  }

  goto LAB_00714686;

  while( true ) {

    iVar4 = *piVar5;

    if (iVar2 < iVar4) {

      iVar2 = iVar4;

      iVar6 = iVar3;

    }

    if (iVar4 < local_8) {

      local_8 = iVar4;

      local_4 = iVar3;

    }

    iVar3 = iVar3 + 1;

    piVar5 = piVar5 + 1;

    if (-1 < iVar2) break;

LAB_0071465e:

    if (param_2 <= iVar3) break;

  }

LAB_00714686:

  if (iVar3 + 4 <= param_2) {

    piVar5 = param_1 + iVar3 + 2;

    iVar4 = iVar3;

    iVar1 = iVar3 + 4;

    do {

      iVar3 = iVar1;

      if (iVar2 < piVar5[-2]) {

        iVar2 = piVar5[-2];

        iVar6 = iVar4;

      }

      if (iVar2 < piVar5[-1]) {

        iVar6 = iVar4 + 1;

        iVar2 = piVar5[-1];

      }

      if (iVar2 < *piVar5) {

        iVar6 = iVar4 + 2;

        iVar2 = *piVar5;

      }

      if (iVar2 < piVar5[1]) {

        iVar6 = iVar4 + 3;

        iVar2 = piVar5[1];

      }

      piVar5 = piVar5 + 4;

      iVar4 = iVar3;

      iVar1 = iVar3 + 4;

    } while (iVar3 + 4 <= param_2);

  }

  if (iVar3 < param_2) {

    param_1 = param_1 + iVar3;

    do {

      if (iVar2 < *param_1) {

        iVar2 = *param_1;

        iVar6 = iVar3;

      }

      iVar3 = iVar3 + 1;

      param_1 = param_1 + 1;

    } while (iVar3 < param_2);

  }

  param_2 = iVar2;

  if (iVar2 < 0) {

    iVar6 = local_4;

    param_2 = local_8;

  }

  *param_3 = iVar6;

  *param_4 = param_2;

  return;

}
