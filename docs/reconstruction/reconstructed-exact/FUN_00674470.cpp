// =============================================================================
// FUN_00674470
// -----------------------------------------------------------------------------
// Stable ID: aa_00674470
// Address:   0x00674470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00674470 @ 0x00674470
// Stable ID: aa_00674470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00674470, FUN_00675fc0, FUN_00676b20.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_00674470(int param_1,uint8_t param_2)



{

  uint8_t uVar1;

  int local_34 [3];

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_18 [4];

  uint8_t local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4;

  

  uVar1 = param_2;

  local_28 = DAT_00d1a6c0;

  local_24 = DAT_00d1a6c4;

  local_20 = DAT_00d1a6c8;

  FUN_00675fc0(local_34,&param_2);

  if (local_34[0] == *(int *)(param_1 + 0x164)) {

    local_10 = local_28;

    local_c = local_24;

    local_18[0] = uVar1;

    local_14 = 1;

    local_8 = local_20;

    local_4 = uVar1;

    FUN_00676b20(local_34,local_18);

    return 0;

  }

  return 0xffffffff;

}
