// =============================================================================
// FUN_00600fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00600fe0
// Address:   0x00600fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600fe0 @ 0x00600fe0
// Stable ID: aa_00600fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00600fe0, FUN_00601ce0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_00600fe0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,

            uint32_t /* width from decompiler */ param_13,uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16,

            uint32_t /* width from decompiler */ param_17,uint32_t /* width from decompiler */ param_18,uint32_t /* width from decompiler */ param_19,uint32_t /* width from decompiler */ param_20,

            uint32_t /* width from decompiler */ param_21,uint32_t /* width from decompiler */ param_22,uint32_t /* width from decompiler */ param_23,uint32_t /* width from decompiler */ param_24,

            uint32_t /* width from decompiler */ param_25,uint32_t /* width from decompiler */ param_26,uint32_t /* width from decompiler */ param_27,uint32_t /* width from decompiler */ param_28,

            uint32_t /* width from decompiler */ param_29,uint32_t /* width from decompiler */ param_30,uint32_t /* width from decompiler */ param_31,uint32_t /* width from decompiler */ param_32,

            uint32_t /* width from decompiler */ param_33,uint32_t /* width from decompiler */ param_34,uint32_t /* width from decompiler */ param_35,uint32_t /* width from decompiler */ param_36,

            uint32_t /* width from decompiler */ param_37,uint32_t /* width from decompiler */ param_38,uint32_t /* width from decompiler */ param_39,uint32_t /* width from decompiler */ param_40,

            uint32_t /* width from decompiler */ param_41,uint16_t param_42)



{

  FUN_00601ce0(param_3,param_4,param_7,param_8,param_6,param_5,param_2,param_9,param_10,param_11,

               param_12,param_13,param_14,param_15,param_16,param_17,param_18);

  param_1[1] = param_19;

  param_1[0x28] = param_20;

  param_1[0x2a] = param_22;

  param_1[0x2c] = param_24;

  param_1[0x2e] = param_26;

  param_1[0x30] = param_28;

  param_1[0x31] = param_29;

  param_1[0x32] = param_30;

  param_1[0x33] = param_31;

  param_1[0x34] = param_32;

  param_1[0x35] = param_33;

  param_1[0x36] = param_34;

  param_1[0x38] = param_36;

  param_1[0x39] = param_37;

  param_1[0x29] = param_21;

  param_1[0x2b] = param_23;

  param_1[0x3a] = param_38;

  *param_1 = &PTR_LAB_009de11c;

  param_1[0x2d] = param_25;

  param_1[0x2f] = param_27;

  param_1[0x37] = param_35;

  param_1[0x3b] = param_39;

  param_1[0x3c] = param_40;

  param_1[0x3d] = param_41;

  *(uint16_t *)(param_1 + 0x3e) = param_42;

  return param_1;

}
