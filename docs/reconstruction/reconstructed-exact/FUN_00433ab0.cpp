// =============================================================================
// FUN_00433ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ab0
// Address:   0x00433ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433ab0 @ 0x00433ab0
// Stable ID: aa_00433ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00433ab0, malloc.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00433ab0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  param_1[1] = 0;

  param_1[2] = 0;

  *param_1 = &PTR_LAB_009d7b00;

  param_1[4] = 0x5dc;

  pvVar1 = malloc(0x5dc);

  param_1[3] = pvVar1;

  param_1[0xb] = param_1[4] * 8;

  param_1[0xc] = param_1[4] * 8;

  param_1[6] = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  param_1[0xd] = 0;

  *(uint8_t *)(param_1 + 5) = 1;

  *param_1 = &PTR_LAB_009d7b94;

  return param_1;

}
