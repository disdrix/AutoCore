// =============================================================================
// FUN_00424dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00424dc0
// Address:   0x00424dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00424dc0 @ 0x00424dc0
// Stable ID: aa_00424dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00424dc0.
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

void __thiscall FUN_00424dc0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4)



{

  param_1[4] = param_3;

  param_1[0xb] = param_3 * 8;

  param_1[3] = param_2;

  param_1[1] = 0;

  param_1[2] = 0;

  *(uint8_t *)(param_1 + 5) = 0;

  *param_1 = &PTR_LAB_009d7b94;

  param_1[0xc] = param_4 * 8;

  param_1[6] = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  param_1[0xd] = 0;

  return;

}
