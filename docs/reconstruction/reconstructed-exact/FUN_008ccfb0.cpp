// =============================================================================
// FUN_008ccfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ccfb0
// Address:   0x008ccfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ccfb0 @ 0x008ccfb0
// Stable ID: aa_008ccfb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007fdfb0, FUN_008ccfb0.
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

void __fastcall FUN_008ccfb0(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = param_1;

  FUN_007fdfb0(&DAT_00d1a840,

               "Deleting your character is permanent. Are you sure you want to delete this character?  If so, type DELETE into the box below."

               ,0x4e23,1,1);

  return;

}
