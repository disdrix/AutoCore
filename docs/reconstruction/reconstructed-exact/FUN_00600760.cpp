// =============================================================================
// FUN_00600760
// -----------------------------------------------------------------------------
// Stable ID: aa_00600760
// Address:   0x00600760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600760 @ 0x00600760
// Stable ID: aa_00600760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00600760, FUN_00601ce0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_00600760(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,

            uint32_t /* width from decompiler */ param_13,uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16,

            uint32_t /* width from decompiler */ param_17,uint32_t /* width from decompiler */ param_18,uint32_t /* width from decompiler */ param_19,uint32_t /* width from decompiler */ param_20,

            uint32_t /* width from decompiler */ param_21,uint32_t /* width from decompiler */ param_22,uint32_t /* width from decompiler */ param_23,uint16_t param_24,

            uint32_t /* width from decompiler */ param_25,uint32_t /* width from decompiler */ *param_26,uint32_t /* width from decompiler */ *param_27,uint32_t /* width from decompiler */ *param_28,

            uint32_t /* width from decompiler */ *param_29,uint16_t param_30,uint16_t param_31,uint32_t /* width from decompiler */ param_32,

            uint32_t /* width from decompiler */ param_33,uint16_t param_34)



{

  FUN_00601ce0(param_3,param_4,param_7,param_8,param_6,param_5,param_2,param_9,param_10,param_11,

               param_12,param_13,param_14,param_15,param_16,param_17,param_18);

  param_1[0x28] = param_21;

  param_1[0x29] = param_22;

  param_1[0x2a] = param_20;

  param_1[0x2b] = param_25;

  param_1[0x2c] = param_23;

  param_1[0x41] = param_32;

  *(uint16_t *)((int)param_1 + 0xb6) = param_30;

  *(uint16_t *)(param_1 + 0x2d) = param_24;

  param_1[0x42] = param_33;

  *param_1 = &PTR_LAB_009de0ec;

  *(uint16_t *)(param_1 + 0x40) = param_31;

  *(uint16_t *)(param_1 + 0x43) = param_34;

  param_1[1] = param_19;

  if (param_26 == (uint32_t /* width from decompiler */ *)0x0) {

    param_1[0x2e] = 0;

    param_1[0x2f] = 0;

    param_1[0x30] = 0;

    param_1[0x31] = 0;

    param_1[0x32] = 0;

    param_1[0x33] = 0;

  }

  else {

    param_1[0x2e] = *param_26;

    param_1[0x2f] = param_26[1];

    param_1[0x30] = param_26[2];

    param_1[0x31] = param_26[3];

    param_1[0x32] = param_26[4];

    param_1[0x33] = param_26[5];

  }

  if (param_27 == (uint32_t /* width from decompiler */ *)0x0) {

    param_1[0x34] = 0;

    param_1[0x35] = 0;

    param_1[0x36] = 0;

    param_1[0x37] = 0;

    param_1[0x38] = 0;

    param_1[0x39] = 0;

  }

  else {

    param_1[0x34] = *param_27;

    param_1[0x35] = param_27[1];

    param_1[0x36] = param_27[2];

    param_1[0x37] = param_27[3];

    param_1[0x38] = param_27[4];

    param_1[0x39] = param_27[5];

  }

  if (param_28 == (uint32_t /* width from decompiler */ *)0x0) {

    param_1[0x3a] = 0;

    param_1[0x3b] = 0;

    param_1[0x3c] = 0;

  }

  else {

    param_1[0x3a] = *param_28;

    param_1[0x3b] = param_28[1];

    param_1[0x3c] = param_28[2];

  }

  if (param_29 != (uint32_t /* width from decompiler */ *)0x0) {

    param_1[0x3d] = *param_29;

    param_1[0x3e] = param_29[1];

    param_1[0x3f] = param_29[2];

    return param_1;

  }

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  return param_1;

}
