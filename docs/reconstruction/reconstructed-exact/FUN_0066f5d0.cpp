// =============================================================================
// FUN_0066f5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f5d0
// Address:   0x0066f5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066f5d0 @ 0x0066f5d0
// Stable ID: aa_0066f5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0066f5d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0066f5d0(int param_1,byte param_2,uint8_t param_3)



{

  if ((*(int *)(param_1 + 0x1f8) != 0) && (param_2 < *(byte *)(param_1 + 0x14))) {

    *(uint8_t *)((uint)param_2 + *(int *)(param_1 + 0x1f8)) = param_3;

    return 0;

  }

  return 0xffffffff;

}
