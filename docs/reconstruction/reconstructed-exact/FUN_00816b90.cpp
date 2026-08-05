// =============================================================================
// FUN_00816b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00816b90
// Address:   0x00816b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00816b90 @ 0x00816b90
// Stable ID: aa_00816b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00816b90.
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

uint32_t /* width from decompiler */ FUN_00816b90(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(in_EAX + 0x708) == 0) {

    return 0xffffffff;

  }

                    /* WARNING: Could not recover jumptable at 0x00816ba5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(**(int **)(in_EAX + 0x708) + 0x464))();

  return uVar1;

}
