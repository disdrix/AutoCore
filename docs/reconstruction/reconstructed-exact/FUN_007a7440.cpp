// =============================================================================
// FUN_007a7440
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7440
// Address:   0x007a7440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a7440 @ 0x007a7440
// Stable ID: aa_007a7440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a7440.
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

uint __thiscall FUN_007a7440(int *param_1,int param_2)



{

  uint uVar1;

  

  uVar1 = (**(code **)(*param_1 + 0xd8))();

  if (((char)uVar1 != '\0') && (uVar1 = 0, param_1[param_2 + 0x117] != 0)) {

    uVar1 = (**(code **)(*param_1 + 0x32c))(param_1[param_2 + 0x117]);

    return uVar1;

  }

  return uVar1 & 0xffffff00;

}
