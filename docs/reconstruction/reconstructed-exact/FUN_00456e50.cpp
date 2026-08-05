// =============================================================================
// FUN_00456e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00456e50
// Address:   0x00456e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00456e50 @ 0x00456e50
// Stable ID: aa_00456e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00456e50, memmove.
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

void FUN_00456e50(void *param_1)



{

  uint32_t /* width from decompiler */ *unaff_EBX;

  int unaff_ESI;

  

  memmove(param_1,(void *)((int)param_1 + 4),(*(int *)(unaff_ESI + 8) - ((int)param_1 + 4) >> 2) * 4

         );

  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -4;

  *unaff_EBX = param_1;

  return;

}
