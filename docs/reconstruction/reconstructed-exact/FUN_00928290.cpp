// =============================================================================
// FUN_00928290
// -----------------------------------------------------------------------------
// Stable ID: aa_00928290
// Address:   0x00928290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928290 @ 0x00928290
// Stable ID: aa_00928290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00928290.
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

uint32_t /* width from decompiler */ FUN_00928290(void)



{

  int in_EAX;

  

  (**(code **)(*DAT_00d17748 + 0x90))

            (DAT_00d17748,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x114),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x118),0x15,0,

             &DAT_00d17750,0);

  return 1;

}
