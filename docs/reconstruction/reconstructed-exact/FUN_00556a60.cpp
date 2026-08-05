// =============================================================================
// FUN_00556a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00556a60
// Address:   0x00556a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00556a60 @ 0x00556a60
// Stable ID: aa_00556a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00556a60.
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

void __fastcall FUN_00556a60(uint8_t *param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *param_1 = 0;

  param_1[0x108] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x210) = 0;

  param_1[0x10c] = 0;

  param_1[0x214] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c) = 0;

  param_1[0x218] = 0;

  param_1[800] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x428) = 0;

  param_1[0x324] = 0;

  param_1[0x42c] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x434) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x438) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x43c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  param_1[0x440] = 0;

  param_1[0x548] = 0;

  param_1[0x54d] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = 0;

  return;

}
