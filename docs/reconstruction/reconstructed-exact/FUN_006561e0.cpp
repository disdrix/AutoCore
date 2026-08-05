// =============================================================================
// FUN_006561e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006561e0
// Address:   0x006561e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006561e0 @ 0x006561e0
// Stable ID: aa_006561e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00641940×2, FUN_00567d20, FUN_006561e0.
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

void FUN_006561e0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint8_t local_50 [16];

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_60 = param_1[0xc];

  local_5c = param_1[0xd];

  local_58 = param_1[0xe];

  local_54 = param_1[0xf];

  local_40 = *param_1;

  local_3c = param_1[1];

  local_38 = param_1[2];

  local_34 = param_1[3];

  local_30 = param_1[4];

  local_2c = param_1[5];

  local_28 = param_1[6];

  local_24 = param_1[7];

  local_20 = param_1[8];

  local_1c = param_1[9];

  local_18 = param_1[10];

  local_14 = param_1[0xb];

  FUN_00567d20(&local_40);

  FUN_00641940(&local_60,3);

  FUN_00641940(local_50,4);

  return;

}
