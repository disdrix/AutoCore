// =============================================================================
// FUN_006bda60
// -----------------------------------------------------------------------------
// Stable ID: aa_006bda60
// Address:   0x006bda60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bda60 @ 0x006bda60
// Stable ID: aa_006bda60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_006bda60.
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

int * __thiscall FUN_006bda60(int *param_1,int *param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  

  uVar1 = param_1[2] & 0x7fffffff;

  if ((int)uVar1 < param_2[1]) {

    if (-1 < param_1[2]) {

      (**(code **)(*DAT_00b05060 + 0x14))(*param_1,uVar1 << 3,0x12);

    }

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[1] << 3,0x12);

    *param_1 = iVar2;

    param_1[2] = param_2[1];

  }

  puVar3 = (uint32_t /* width from decompiler */ *)*param_1;

  param_1[1] = param_2[1];

  iVar2 = param_2[1];

  if (0 < iVar2) {

    iVar5 = *param_2 - (int)puVar3;

    do {

      *puVar3 = *(uint32_t /* width from decompiler */ *)(iVar5 + (int)puVar3);

      puVar3[1] = *(uint32_t /* width from decompiler */ *)(iVar5 + 4 + (int)puVar3);

      puVar3 = puVar3 + 2;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  piVar4 = param_1 + 3;

  iVar2 = 0x80;

  do {

    *piVar4 = *(int *)(((int)param_2 - (int)param_1) + (int)piVar4);

    piVar4[1] = *(int *)(((int)param_2 - (int)param_1) + 4 + (int)piVar4);

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return param_1;

}
