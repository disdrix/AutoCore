// =============================================================================
// FUN_005a6d90
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6d90
// Address:   0x005a6d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6d90 @ 0x005a6d90
// Stable ID: aa_005a6d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a6d90.
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

void __thiscall FUN_005a6d90(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  if (((param_2 < *(char *)(param_1 + 0xb0)) && (-1 < param_2)) && (*(int *)(param_1 + 0xe8) != 0))

  {

    (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + param_2 * 0x14c) + 0x18))(param_3);

    (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + param_2 * 0x14c) + 0x14))(param_3);

  }

  return;

}
