// =============================================================================
// FUN_006e4100
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4100
// Address:   0x006e4100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4100 @ 0x006e4100
// Stable ID: aa_006e4100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006e4100.
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

FUN_006e4100(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ *param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ *param_10,float param_11)



{

  *param_1 = param_2;

  param_1[2] = param_4;

  param_1[1] = param_3;

  param_1[4] = param_6;

  param_1[3] = param_5;

  param_1[6] = param_9;

  param_1[5] = param_7;

  param_1[8] = *param_8;

  param_1[9] = param_8[1];

  param_1[10] = param_8[2];

  param_1[0xb] = param_8[3];

  param_1[0xc] = *param_10;

  param_1[0xd] = param_10[1];

  param_1[0xe] = param_10[2];

  param_1[0xf] = param_10[3];

  param_1[0x18] = param_11;

  param_1[0x19] = 0x3c23d70a;

  param_1[0x10] = param_11 + (float)param_1[8];

  param_1[0x11] = param_11 + (float)param_1[9];

  param_1[0x12] = param_11 + (float)param_1[10];

  param_1[0x13] = param_11 + (float)param_1[0xb];

  param_1[0x14] = param_11 + (float)param_1[0xc];

  param_1[0x15] = param_11 + (float)param_1[0xd];

  param_1[0x16] = param_11 + (float)param_1[0xe];

  param_1[0x17] = param_11 + (float)param_1[0xf];

  return;

}
