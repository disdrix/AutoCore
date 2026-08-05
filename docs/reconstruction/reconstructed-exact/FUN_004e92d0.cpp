// =============================================================================
// FUN_004e92d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e92d0
// Address:   0x004e92d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e92d0 @ 0x004e92d0
// Stable ID: aa_004e92d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e8dc0, FUN_004e92d0.
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

uint32_t /* width from decompiler */ FUN_004e92d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  local_20 = *param_1;

  local_1c = param_1[1];

  local_18 = param_1[2];

  local_2c = param_2[1];

  local_28 = param_2[2];

  local_24 = param_2[3];

  local_30 = *param_2;

  FUN_004e8dc0(&local_20,&local_30);

  *param_2 = local_30;

  param_2[1] = local_2c;

  param_2[2] = local_28;

  param_2[3] = local_24;

  return 1;

}
