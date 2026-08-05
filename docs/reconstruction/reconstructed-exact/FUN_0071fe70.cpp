// =============================================================================
// FUN_0071fe70
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fe70
// Address:   0x0071fe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071fe70 @ 0x0071fe70
// Stable ID: aa_0071fe70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: EnterCriticalSection, FUN_0071fe70, LeaveCriticalSection.
//  - Return sites: 3.

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

void FUN_0071fe70(void)



{

  int unaff_ESI;

  

  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x170));

  if (*(void **)(unaff_ESI + 0x44) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x44));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c) = 0;

  if (*(void **)(unaff_ESI + 0x54) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x54));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5c) = 0;

  *(uint8_t *)(unaff_ESI + 0x13) = 0;

  *(uint8_t *)(unaff_ESI + 0x14) = 0;

  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x170));

  return;

}
