// =============================================================================
// FUN_004050d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004050d0
// Address:   0x004050d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004050d0 @ 0x004050d0
// Stable ID: aa_004050d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CloseHandle, FUN_004050d0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004050d0; evidence only — no invented semantics):
//  - Entry: `void FUN_004050d0(void)`.
//  - Branches: if ((HANDLE)*unaff_ESI != (HANDLE)0x0).
//  - Returns (1 site(s)): `void`.
//  - Assign `unaff_ESI = 0`.




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

void FUN_004050d0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if ((HANDLE)*unaff_ESI != (HANDLE)0x0) {

    CloseHandle((HANDLE)*unaff_ESI);

    *unaff_ESI = 0;

  }

  return;

}
