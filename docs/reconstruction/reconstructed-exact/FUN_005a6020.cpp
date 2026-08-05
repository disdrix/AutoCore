// =============================================================================
// FUN_005a6020
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6020
// Address:   0x005a6020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6020 @ 0x005a6020
// Stable ID: aa_005a6020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_005a6020.
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

void __thiscall FUN_005a6020(int param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  

  iVar2 = (param_1 + 0x30) - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar2] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  return;

}
