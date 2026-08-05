// =============================================================================
// FUN_00962220
// -----------------------------------------------------------------------------
// Stable ID: aa_00962220
// Address:   0x00962220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962220 @ 0x00962220
// Stable ID: aa_00962220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CloseHandle, FUN_00962220.
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

uint32_t /* width from decompiler */ FUN_00962220(int *param_1)



{

  char cVar1;

  BOOL BVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x20))();

  if (cVar1 != '\0') {

    BVar2 = CloseHandle((HANDLE)param_1[2]);

    if (BVar2 == 0) {

      (**(code **)*param_1)(1);

      return 0xffffffff;

    }

  }

  param_1[2] = -1;

  (**(code **)*param_1)(1);

  return 0;

}
