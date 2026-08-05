// =============================================================================
// FUN_006809c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006809c0
// Address:   0x006809c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006809c0 @ 0x006809c0
// Stable ID: aa_006809c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_00680490×7, FUN_005a2850, FUN_00673070, FUN_006807e0, FUN_006809c0, SBORROW4.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ * __thiscall FUN_006809c0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00680490(param_2,1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

    return param_2;

  }

  piVar1 = *(int **)(param_1 + 4);

  if (param_3 == (int *)*piVar1) {

    if (*param_4 < param_3[3]) {

      FUN_00680490(param_2,1,param_3,param_4);

      return param_2;

    }

  }

  else if (param_3 == piVar1) {

    if (*(int *)(piVar1[2] + 0xc) < *param_4) {

      FUN_00680490(param_2,0,piVar1[2],param_4);

      return param_2;

    }

  }

  else {

    iVar2 = *param_4;

    iVar3 = param_3[3];

    iVar4 = iVar3 - iVar2;

    if (iVar2 < iVar3) {

      FUN_005a2850();

      if (param_3[3] < iVar2) {

        if (*(char *)(param_3[2] + 0x15) != '\0') {

          FUN_00680490(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_00680490(param_2,1,param_3,param_4);

        return param_2;

      }

      iVar3 = param_3[3];

      iVar4 = iVar3 - iVar2;

    }

    if (SBORROW4(iVar3,iVar2) != iVar4 < 0) {

      FUN_00673070();

      if ((param_3 == *(int **)(param_1 + 4)) || (iVar2 < param_3[3])) {

        if (*(char *)(param_3[2] + 0x15) != '\0') {

          FUN_00680490(param_2,0,param_3,param_4);

          return param_2;

        }

        FUN_00680490(param_2,1,param_3,param_4);

        return param_2;

      }

    }

  }

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_006807e0(local_8,param_4);

  *param_2 = *puVar5;

  return param_2;

}
