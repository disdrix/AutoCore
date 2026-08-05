// =============================================================================
// FUN_004b6910
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6910
// Address:   0x004b6910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b6910 @ 0x004b6910
// Stable ID: aa_004b6910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004b6910, FUN_0096daa0.
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

void __fastcall FUN_004b6910(byte *param_1)



{

  int iVar1;

  

  if ((((*param_1 & 2) == 0) && (param_1[0xd4] != 0)) && (*(int **)(param_1 + 0x10) != (int *)0x0))

  {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x1cc))();

    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

      param_1[0xd4] = 0;

      FUN_0096daa0(param_1 + 0xa0,&DAT_00d1eb60);

    }

  }

  return;

}
