// =============================================================================
// FUN_005c6590
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6590
// Address:   0x005c6590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6590 @ 0x005c6590
// Stable ID: aa_005c6590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005c6590, fclose.
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

void __fastcall FUN_005c6590(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009d9ea4;

  if ((FILE *)param_1[1] != (FILE *)0x0) {

    fclose((FILE *)param_1[1]);

  }

  *param_1 = &PTR_LAB_009d9e6c;

  return;

}
