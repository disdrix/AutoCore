// =============================================================================
// FUN_006380d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006380d0
// Address:   0x006380d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006380d0 @ 0x006380d0
// Stable ID: aa_006380d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: CONCAT11×2, CONCAT22, FUN_006380d0.
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

void FUN_006380d0(uint32_t /* width from decompiler */ *param_1,uint8_t param_2,uint param_3)



{

  uint uVar1;

  

  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *param_1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));

    param_1 = param_1 + 1;

  }

  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {

    *(uint8_t *)param_1 = param_2;

    param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

  }

  return;

}
