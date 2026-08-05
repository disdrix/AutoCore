// =============================================================================
// FUN_00428e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00428e90
// Address:   0x00428e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00428e90 @ 0x00428e90
// Stable ID: aa_00428e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00428e90, FUN_004291f0, free.
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

void FUN_00428e90(void)



{

  int in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

  FUN_004291f0();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x10) != (uint32_t /* width from decompiler */ *)0x0) {

    free((void *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x10));

    operator_delete__(*(void **)(in_EAX + 0x10));

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

  }

  return;

}
