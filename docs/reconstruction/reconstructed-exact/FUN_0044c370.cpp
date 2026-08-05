// =============================================================================
// FUN_0044c370
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c370
// Address:   0x0044c370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c370 @ 0x0044c370
// Stable ID: aa_0044c370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0044c370, FUN_0044ec90.
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

uint32_t /* width from decompiler */ FUN_0044c370(uint param_1,uint param_2)



{

  int *piVar1;

  int unaff_ESI;

  int local_4;

  

  local_4 = FUN_0044ec90();

  if (((local_4 == *(int *)(unaff_ESI + 4)) || (param_2 < *(uint *)(local_4 + 0x14))) ||

     ((piVar1 = &local_4, param_2 == *(uint *)(local_4 + 0x14) &&

      (piVar1 = &local_4, param_1 < *(uint *)(local_4 + 0x10))))) {

    piVar1 = (int *)&param_1;

  }

  if (*piVar1 == *(int *)(unaff_ESI + 4)) {

    return 0;

  }

  return *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x18);

}
