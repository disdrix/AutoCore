// =============================================================================
// FUN_0075b4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b4f0
// Address:   0x0075b4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075b4f0 @ 0x0075b4f0
// Stable ID: aa_0075b4f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0075b4f0.
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

void __thiscall

FUN_0075b4f0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint8_t *param_5,uint32_t /* width from decompiler */ param_6)



{

  undefined **local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint8_t local_58 [84];

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  local_2 = 0xff;

  local_3 = 0xff;

  local_4 = 0xff;

  local_1 = 0xff;

  if (param_5 == (uint8_t *)0x0) {

    param_5 = local_58;

  }

  local_60 = param_4;

  local_5c = param_3;

  local_64 = &PTR_LAB_00a9edc0;

  (**(code **)(*param_1 + 0x10))(param_2,param_6,param_5,&local_64);

  return;

}
