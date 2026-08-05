// =============================================================================
// FUN_0065ab10
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ab10
// Address:   0x0065ab10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065ab10 @ 0x0065ab10
// Stable ID: aa_0065ab10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00659140, FUN_0065ab10.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0065ab10(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e5ee0;

  param_1[2] = param_2;

  if (param_2 != 0) {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

    return param_1;

  }

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,5);

  *(uint16_t *)(iVar1 + 4) = 0xc;

  uVar2 = FUN_00659140();

  param_1[2] = uVar2;

  return param_1;

}
