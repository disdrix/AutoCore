// =============================================================================
// FUN_005f5190
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5190
// Address:   0x005f5190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f5190 @ 0x005f5190
// Stable ID: aa_005f5190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005f5190.
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

int * __thiscall FUN_005f5190(int *param_1,uint param_2)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7ae8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = -0x80000000;

  piVar2 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  local_4 = 0;

  uVar3 = param_2 * 2 + 0xf & 0xfffffff0;

  if (*piVar1 < (int)uVar3) {

    iVar4 = (**(code **)(*DAT_00b05060 + 0x24))(uVar3);

  }

  else {

    iVar4 = DAT_00b05060[2];

    DAT_00b05060[2] = iVar4 + uVar3;

    piVar2[3] = *piVar1 - uVar3;

  }

  *param_1 = iVar4;

  param_1[3] = iVar4;

  param_1[2] = param_2 | 0x80000000;

  param_1[4] = param_2;

  ExceptionList = local_c;

  return param_1;

}
