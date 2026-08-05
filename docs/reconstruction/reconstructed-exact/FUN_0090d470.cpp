// =============================================================================
// FUN_0090d470
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d470
// Address:   0x0090d470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090d470 @ 0x0090d470
// Stable ID: aa_0090d470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007f7060, FUN_0090d470.
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

void __thiscall FUN_0090d470(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  if ((char)param_2 == '\0') {

    cVar1 = (**(code **)(*param_1 + 0x1cc))();

    if (cVar1 != '\0') {

      FUN_007f7060();

    }

  }

  *(char *)((int)param_1 + 0xc1) = (char)param_2;

  if ((int *)param_1[0xac] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xac] + 0x1c8))(param_2);

  }

  return;

}
