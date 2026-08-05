// =============================================================================
// FUN_00653db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00653db0
// Address:   0x00653db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653db0 @ 0x00653db0
// Stable ID: aa_00653db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0055e3c0, FUN_0055e9b0, FUN_00652320, FUN_006523f0, FUN_00653db0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00653db0(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = param_1 + 5;

  *param_1 = &PTR_FUN_009e5d00;

  param_1[2] = &PTR_LAB_009e5cf8;

  *puVar1 = &PTR_FUN_009e5cec;

  if (param_1[3] != 0) {

    FUN_0055e3c0(puVar1);

    FUN_00652320(0);

    if (param_1[3] != 0) {

      FUN_0055e9b0(puVar1);

    }

  }

  FUN_006523f0();

  if ((param_2 & 1) != 0) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 1),0xc);

  }

  return param_1;

}
