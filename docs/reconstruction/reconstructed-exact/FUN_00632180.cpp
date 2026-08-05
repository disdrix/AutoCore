// =============================================================================
// FUN_00632180
// -----------------------------------------------------------------------------
// Stable ID: aa_00632180
// Address:   0x00632180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00632180 @ 0x00632180
// Stable ID: aa_00632180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005b3300, FUN_00632180, FUN_006380a0.
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

int __thiscall FUN_00632180(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = *(int **)(param_1 + 8);

  iVar2 = piVar1[1];

  iVar4 = iVar2 - *(int *)(param_1 + 0xc);

  if (iVar4 < param_3) {

    iVar4 = (iVar2 - iVar4) + param_3;

    iVar2 = iVar4 + 1;

    if ((int)(piVar1[2] & 0x7fffffffU) < iVar2) {

      iVar3 = (piVar1[2] & 0x7fffffffU) * 2;

      if (iVar3 <= iVar2) {

        iVar3 = iVar2;

      }

      FUN_005b3300(piVar1,iVar3,1);

    }

    *(int *)(*(int *)(param_1 + 8) + 4) = iVar4;

    *(uint8_t *)(iVar4 + **(int **)(param_1 + 8)) = 0;

  }

  else if (iVar2 < (int)(piVar1[2] & 0x7fffffffU)) {

    *(uint8_t *)(iVar2 + *piVar1) = 0;

  }

  FUN_006380a0(**(int **)(param_1 + 8) + *(int *)(param_1 + 0xc),param_2,param_3);

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;

  return param_3;

}
