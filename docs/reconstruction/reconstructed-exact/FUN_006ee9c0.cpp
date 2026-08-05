// =============================================================================
// FUN_006ee9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ee9c0
// Address:   0x006ee9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ee9c0 @ 0x006ee9c0
// Stable ID: aa_006ee9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006ee9c0.
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

void __thiscall

FUN_006ee9c0(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  float *pfVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  iVar4 = *(int *)(*param_5 + 4);

  local_8 = param_3[2];

  local_4 = param_3;

  local_c = param_3[1];

  local_10 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0xc);

  (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(&local_10,param_2,param_4,param_5);

  piVar2 = (int *)*param_5;

  if (iVar4 < piVar2[1]) {

    iVar3 = iVar4 * 0x30;

    do {

      pfVar1 = (float *)(*piVar2 + 0x10 + iVar3);

      iVar4 = iVar4 + 1;

      *pfVar1 = -*(float *)(*piVar2 + 0x10 + iVar3);

      iVar3 = iVar3 + 0x30;

      pfVar1[1] = -pfVar1[1];

      pfVar1[2] = -pfVar1[2];

      pfVar1[3] = -pfVar1[3];

      piVar2 = (int *)*param_5;

    } while (iVar4 < piVar2[1]);

  }

  return;

}
