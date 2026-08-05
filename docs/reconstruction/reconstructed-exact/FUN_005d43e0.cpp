// =============================================================================
// FUN_005d43e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d43e0
// Address:   0x005d43e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d43e0 @ 0x005d43e0
// Stable ID: aa_005d43e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d43e0.
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

void __fastcall FUN_005d43e0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint uVar2;

  

  piVar1 = DAT_00b05060;

  uVar2 = param_1[4] * 4 + 0xfU & 0xfffffff0;

  if ((uVar2 == 0) || ((param_1[3] != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar2;

    piVar1[3] = piVar1[3] + uVar2;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(param_1[3],uVar2);

  }

  if (-1 < (int)param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] * 4,0x12);

  }

  return;

}
