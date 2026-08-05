// =============================================================================
// FUN_004c47a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c47a0
// Address:   0x004c47a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c47a0 @ 0x004c47a0
// Stable ID: aa_004c47a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004c47a0, FUN_00580dd0.
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

void __fastcall FUN_004c47a0(int *param_1)



{

  uint8_t auStack_38 [8];

  uint8_t local_30 [16];

  uint8_t local_20 [28];

  

  if (param_1[0x95] != 0) {

    (**(code **)(*param_1 + 0x4c))(local_30,local_20);

    FUN_00580dd0(auStack_38);

  }

  return;

}
