// =============================================================================
// FUN_00805860
// -----------------------------------------------------------------------------
// Stable ID: aa_00805860
// Address:   0x00805860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805860 @ 0x00805860
// Stable ID: aa_00805860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: DeleteDC, DeleteObject, FUN_00805860.
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

void FUN_00805860(void)



{

  int unaff_ESI;

  

  if (*(void **)(unaff_ESI + 0xc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0xc));

  }

  if (*(HGDIOBJ *)(unaff_ESI + 0x18) != (HGDIOBJ)0x0) {

    DeleteObject(*(HGDIOBJ *)(unaff_ESI + 0x18));

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  if (*(void **)(unaff_ESI + 0x10) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x10));

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  }

  if (*(HDC *)(unaff_ESI + 0x14) != (HDC)0x0) {

    DeleteDC(*(HDC *)(unaff_ESI + 0x14));

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  return;

}
