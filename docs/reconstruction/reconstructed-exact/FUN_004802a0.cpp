// =============================================================================
// FUN_004802a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004802a0
// Address:   0x004802a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004802a0 @ 0x004802a0
// Stable ID: aa_004802a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CloseHandle, FUN_004802a0.
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

void FUN_004802a0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if ((void *)unaff_ESI[4] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)unaff_ESI[4]);

  }

  unaff_ESI[4] = 0;

  unaff_ESI[5] = 0;

  unaff_ESI[6] = 0;

  *unaff_ESI = &PTR_FUN_00aa9a18;

  if ((HANDLE)unaff_ESI[2] != (HANDLE)0x0) {

    CloseHandle((HANDLE)unaff_ESI[2]);

    unaff_ESI[1] = 0;

    unaff_ESI[2] = 0;

  }

  return;

}
