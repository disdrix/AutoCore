// =============================================================================
// FUN_00617ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00617ad0
// Address:   0x00617ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00617ad0 @ 0x00617ad0
// Stable ID: aa_00617ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005788d0, FUN_00617ad0.
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

FUN_00617ad0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  FUN_005788d0(param_2,param_3,param_4,param_5,param_6,param_7);

  *param_1 = &PTR_FUN_009d0f1c;

  if (*(float *)(param_3 + 0x4c) != g_flZero) {

    *(uint8_t *)(param_1 + 0x1b1) = 1;

    param_1[0x1b0] = (int)*(float *)(param_3 + 0x4c);

    return param_1;

  }

  *(uint8_t *)(param_1 + 0x1b1) = 0;

  return param_1;

}
