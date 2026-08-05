// =============================================================================
// FUN_00646360
// -----------------------------------------------------------------------------
// Stable ID: aa_00646360
// Address:   0x00646360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646360 @ 0x00646360
// Stable ID: aa_00646360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00646360.
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

void __thiscall FUN_00646360(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = **(int **)(param_1 + 0xc);

  uVar2 = (**(code **)(*param_2 + 0x14))();

  (**(code **)(iVar1 + 4))(param_2,uVar2);

  return;

}
