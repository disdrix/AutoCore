// =============================================================================
// FUN_009888b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009888b0
// Address:   0x009888b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009888b0 @ 0x009888b0
// Stable ID: aa_009888b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0044f2e0, FUN_00988630, FUN_009887a0, FUN_009888b0.
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

void __thiscall FUN_009888b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t local_34 [8];

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_10 = 0xffffffff;

  local_c = 0xffffffff;

  local_14 = param_3;

  local_8 = DAT_00d1f01c;

  local_4 = DAT_00d1f020;

  if (*(int *)(param_1 + 0xc) != 0) {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00988630();

    local_2c = *puVar1;

    local_28 = puVar1[1];

    local_24 = puVar1[2];

    local_20 = puVar1[3];

    local_1c = puVar1[4];

    FUN_009887a0();

    local_c = local_24;

    local_10 = local_28;

    local_14 = local_2c;

    local_8 = local_20;

    local_4 = local_1c;

  }

  local_18 = param_2;

  FUN_0044f2e0(local_34);

  return;

}
