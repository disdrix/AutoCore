// =============================================================================
// FUN_0094e920
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e920
// Address:   0x0094e920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094e920 @ 0x0094e920
// Stable ID: aa_0094e920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0094e920.
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

uint32_t /* width from decompiler */ __fastcall FUN_0094e920(int param_1)



{

  int iVar1;

  char cVar2;

  

  *(bool *)(param_1 + 0x9d) = *(char *)(param_1 + 0x9d) == '\0';

  if (*(int **)(param_1 + 0x1168) != (int *)0x0) {

    iVar1 = **(int **)(param_1 + 0x1168);

    cVar2 = (**(code **)(iVar1 + 0xd0))();

    (**(code **)(iVar1 + 4))(cVar2 == '\0');

  }

  return 1;

}
