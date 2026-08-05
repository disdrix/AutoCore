// =============================================================================
// FUN_00680460
// -----------------------------------------------------------------------------
// Stable ID: aa_00680460
// Address:   0x00680460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680460 @ 0x00680460
// Stable ID: aa_00680460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00680460, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ __fastcall FUN_00680460(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(char *)(param_1 + 0x2c) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  if (*(char *)(param_1 + 0x2c) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  return uVar1;

}
