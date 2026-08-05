// =============================================================================
// FUN_00766690
// -----------------------------------------------------------------------------
// Stable ID: aa_00766690
// Address:   0x00766690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00766690 @ 0x00766690
// Stable ID: aa_00766690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CloseHandle, FUN_00766690.
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

uint32_t /* width from decompiler */ FUN_00766690(void)



{

  char cVar1;

  BOOL BVar2;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x20))();

  if (cVar1 != '\0') {

    BVar2 = CloseHandle((HANDLE)unaff_ESI[2]);

    if (BVar2 == 0) {

      return 0xffffffff;

    }

  }

  unaff_ESI[2] = -1;

  return 0;

}
