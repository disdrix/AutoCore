// =============================================================================
// FUN_00632210
// -----------------------------------------------------------------------------
// Stable ID: aa_00632210
// Address:   0x00632210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632210 @ 0x00632210
// Stable ID: aa_00632210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1.
//  - Notable callees: FUN_005b3300, FUN_00632210.
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

uint32_t /* width from decompiler */ __thiscall FUN_00632210(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = param_2;

  if (param_3 != 0) {

    if (param_3 == 1) {

      iVar5 = *(int *)(param_1 + 0xc) + param_2;

    }

    else {

      iVar5 = *(int *)(param_1 + 0xc);

      if (param_3 == 2) {

        iVar5 = *(int *)(*(int *)(param_1 + 8) + 4) - param_2;

      }

    }

  }

  if (-1 < iVar5) {

    piVar2 = *(int **)(param_1 + 8);

    if (piVar2[1] < iVar5) {

      iVar4 = piVar2[1];

      iVar1 = iVar5 + 1;

      if (iVar4 < iVar1) {

        if ((int)(piVar2[2] & 0x7fffffffU) < iVar1) {

          iVar3 = (piVar2[2] & 0x7fffffffU) * 2;

          if (iVar3 <= iVar1) {

            iVar3 = iVar1;

          }

          FUN_005b3300(piVar2,iVar3,1);

        }

        for (; iVar4 < iVar1; iVar4 = iVar4 + 1) {

          *(uint8_t *)(iVar4 + *piVar2) = 0;

        }

      }

      piVar2[1] = iVar1;

      *(int *)(*(int *)(param_1 + 8) + 4) = iVar5;

    }

    *(int *)(param_1 + 0xc) = iVar5;

    return 0;

  }

  return 1;

}
