// =============================================================================
// FUN_00601ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00601ce0
// Address:   0x00601ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00601ce0 @ 0x00601ce0
// Stable ID: aa_00601ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: strncpy×2, FUN_00601ce0.
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

int __thiscall

FUN_00601ce0(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3,char *param_4,char *param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ *param_9,

            uint16_t param_10,uint32_t /* width from decompiler */ param_11,uint16_t param_12,uint16_t param_13,

            uint16_t param_14,uint16_t param_15,uint32_t /* width from decompiler */ param_16,uint32_t /* width from decompiler */ param_17,

            uint32_t /* width from decompiler */ param_18)



{

  float fVar1;

  

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = param_6;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = param_8;

  *(uint16_t *)(param_1 + 0x84) = param_10;

  *(uint8_t *)(param_1 + 0x10) = param_3;

  *(uint16_t *)(param_1 + 0x8e) = param_13;

  *(float *)(param_1 + 4) = fVar1;

  *(uint16_t *)(param_1 + 0x90) = param_14;

  *(uint16_t *)(param_1 + 0x8c) = param_12;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = param_16;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = param_17;

  *(uint16_t *)(param_1 + 0x92) = param_15;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = param_7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = param_11;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = param_18;

  strncpy((char *)(param_1 + 0x11),param_4,0x32);

  strncpy((char *)(param_1 + 0x44),param_5,0x20);

  *(uint8_t *)(param_1 + 0x43) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *param_9;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = param_9[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = param_9[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = param_9[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = param_9[4];

  return param_1;

}
