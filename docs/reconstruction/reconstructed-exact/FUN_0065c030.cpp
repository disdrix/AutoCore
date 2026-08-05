// =============================================================================
// FUN_0065c030
// -----------------------------------------------------------------------------
// Stable ID: aa_0065c030
// Address:   0x0065c030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065c030 @ 0x0065c030
// Stable ID: aa_0065c030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0065bd70, FUN_0065c030.
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

int __fastcall FUN_0065c030(int param_1)



{

  float fVar1;

  

  FUN_0065bd70();

  *(uint8_t *)(param_1 + 0x9c) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  fVar1 = g_flOne;

  *(float *)(param_1 + 0xa0) = g_flOne;

  *(float *)(param_1 + 0xb4) = fVar1;

  *(float *)(param_1 + 200) = fVar1;

  return param_1;

}
