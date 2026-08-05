// =============================================================================
// FUN_00600be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00600be0
// Address:   0x00600be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600be0 @ 0x00600be0
// Stable ID: aa_00600be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00600be0, FUN_00601ce0.
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

FUN_00600be0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,

            uint32_t /* width from decompiler */ param_13,uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16,

            uint32_t /* width from decompiler */ param_17,uint32_t /* width from decompiler */ param_18,uint32_t /* width from decompiler */ param_19,uint16_t param_20,

            uint16_t param_21,uint16_t param_22,uint16_t param_23,uint32_t /* width from decompiler */ param_24,

            uint32_t /* width from decompiler */ param_25,uint32_t /* width from decompiler */ param_26,uint32_t /* width from decompiler */ param_27)



{

  FUN_00601ce0(param_3,param_4,param_7,param_8,param_6,param_5,param_2,param_9,param_10,param_11,

               param_12,param_13,param_14,param_15,param_16,param_17,param_18);

  param_1[1] = param_19;

  param_1[0x2a] = param_24;

  param_1[0x2b] = param_25;

  *(uint16_t *)(param_1 + 0x28) = param_20;

  param_1[0x2c] = param_26;

  *(uint16_t *)((int)param_1 + 0xa2) = param_21;

  *param_1 = &PTR_LAB_009de110;

  *(uint16_t *)(param_1 + 0x29) = param_22;

  *(uint16_t *)((int)param_1 + 0xa6) = param_23;

  param_1[0x2d] = param_27;

  return param_1;

}
