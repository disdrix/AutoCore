// =============================================================================
// FUN_00679960
// -----------------------------------------------------------------------------
// Stable ID: aa_00679960
// Address:   0x00679960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679960 @ 0x00679960
// Stable ID: aa_00679960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00679960.
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

void __thiscall FUN_00679960(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  param_1[1] = param_2;

  *param_1 = &PTR_LAB_009e84f4;

  param_1[2] = 0;

  param_1[3] = 0;

  *(uint8_t *)(param_1 + 5) = 0;

  *(uint8_t *)((int)param_1 + 0x15) = 0;

  *(uint8_t *)((int)param_1 + 0x16) = 0;

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  *(uint16_t *)(param_1 + 10) = 0xbe;

  *(uint16_t *)((int)param_1 + 0x2a) = 300;

  return;

}
