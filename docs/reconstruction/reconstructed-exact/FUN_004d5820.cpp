// =============================================================================
// FUN_004d5820
// -----------------------------------------------------------------------------
// Stable ID: aa_004d5820
// Address:   0x004d5820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d5820 @ 0x004d5820
// Stable ID: aa_004d5820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00492480, FUN_00494010, FUN_004d5820.
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

void __thiscall FUN_004d5820(int param_1,int *param_2)



{

  uint8_t local_18 [8];

  uint8_t auStack_10 [12];

  uint8_t auStack_4 [4];

  

  (**(code **)(*param_2 + 0x40))(local_18);

  (**(code **)(*param_2 + 0x40))(auStack_10);

  (**(code **)(*param_2 + 0x28))();

  FUN_00494010(auStack_4);

  if (*(int *)(param_1 + 0xe894) != 0) {

    FUN_00492480(param_2);

  }

  return;

}
