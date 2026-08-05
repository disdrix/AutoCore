// =============================================================================
// FUN_00771600
// -----------------------------------------------------------------------------
// Stable ID: aa_00771600
// Address:   0x00771600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771600 @ 0x00771600
// Stable ID: aa_00771600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1, for×1.
//  - Notable callees: FUN_00770490, FUN_00770820, FUN_00770850, FUN_00771600.
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

int FUN_00771600(int *param_1,uint param_2,int *param_3)



{

  int iVar1;

  uint *puVar2;

  int iVar3;

  uint *puVar4;

  

  if ((param_3[1] < *param_1 + 1) && (iVar1 = FUN_00770490(), iVar1 != 0)) {

    return iVar1;

  }

  if (param_1[2] != 1) {

    iVar1 = *param_3;

    iVar3 = *param_1;

    puVar4 = (uint *)param_3[3];

    puVar2 = (uint *)param_1[3];

    if (((iVar3 == 1) && (*puVar2 <= param_2)) || (iVar3 == 0)) {

      if (iVar3 == 1) {

        param_2 = param_2 - *puVar2;

      }

      *puVar4 = param_2;

      iVar3 = 1;

      puVar4 = puVar4 + 1;

      param_3[2] = 1;

      *param_3 = 1;

    }

    else {

      param_3[2] = 0;

      *param_3 = *param_1;

      param_2 = *puVar2 - param_2;

      *puVar4 = param_2;

      *puVar4 = param_2 & 0xfffffff;

      iVar3 = 1;

      puVar4 = puVar4 + 1;

      if (1 < *param_1) {

        do {

          puVar2 = puVar2 + 1;

          param_2 = *puVar2 + ((int)param_2 >> 0x1f);

          *puVar4 = param_2;

          *puVar4 = param_2 & 0xfffffff;

          iVar3 = iVar3 + 1;

          puVar4 = puVar4 + 1;

        } while (iVar3 < *param_1);

      }

    }

    if (iVar3 < iVar1) {

      for (iVar1 = iVar1 - iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

    }

    FUN_00770820();

    return 0;

  }

  param_1[2] = 0;

  iVar1 = FUN_00770850(param_2,param_3);

  param_3[2] = 1;

  param_1[2] = 1;

  return iVar1;

}
