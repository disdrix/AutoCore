// =============================================================================
// FUN_005e2110
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2110
// Address:   0x005e2110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e2110 @ 0x005e2110
// Stable ID: aa_005e2110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005e2110, FUN_005e7600.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005e2110(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  FUN_005e7600(param_2);

  fVar1 = g_flOne;

  *param_1 = &PTR_FUN_009dc8e4;

  param_1[0x5d] = 0;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = fVar1;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  uVar2 = DAT_00aaa690;

  param_1[100] = fVar1;

  param_1[0x5c] = uVar2;

  param_1[0x5d] = DAT_00afdf40;

  param_1[0x5e] = DAT_00afdf44;

  param_1[0x5f] = DAT_00afdf48;

  param_1[0x60] = DAT_00afdf4c;

  param_1[0x61] = DAT_00afdf40;

  param_1[0x62] = DAT_00afdf44;

  param_1[99] = DAT_00afdf48;

  param_1[100] = DAT_00afdf4c;

  return param_1;

}
