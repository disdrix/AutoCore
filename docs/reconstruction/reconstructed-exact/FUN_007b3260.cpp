// =============================================================================
// FUN_007b3260
// -----------------------------------------------------------------------------
// Stable ID: aa_007b3260
// Address:   0x007b3260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b3260 @ 0x007b3260
// Stable ID: aa_007b3260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00755a50, FUN_007b3260.
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

void __thiscall FUN_007b3260(int param_1,int *param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int local_c;

  uint8_t local_8 [8];

  

  iVar4 = 0;

  local_c = 0;

  if (param_3 == 0) {

    param_2[1] = 0;

    *param_2 = 0;

    return;

  }

  piVar6 = *(int **)(param_3 + 0x84);

  if (piVar6 != *(int **)(param_3 + 0x88)) {

    piVar5 = piVar6 + 4;

    do {

      if ((int *)piVar5[6] != (int *)0x0) {

        if (piVar5[4] == 0) {

          iVar2 = *(int *)(*(int *)piVar5[6] + 0x7c);

          iVar3 = 0;

        }

        else {

          piVar1 = (int *)FUN_00755a50(local_8);

          iVar3 = *piVar1;

          iVar2 = piVar1[1];

        }

        iVar3 = *piVar6 + (int)((float)iVar3 * *(float *)(param_1 + 0x130));

        if (iVar4 < iVar3) {

          iVar4 = iVar3;

        }

        iVar3 = piVar5[-3] + (int)((float)iVar2 * *(float *)(param_1 + 0x130));

        if (local_c < iVar3) {

          local_c = iVar3;

        }

      }

      piVar6 = piVar6 + 0x20;

      piVar5 = piVar5 + 0x20;

    } while (piVar6 != *(int **)(param_3 + 0x88));

  }

  *param_2 = iVar4;

  param_2[1] = local_c;

  return;

}
