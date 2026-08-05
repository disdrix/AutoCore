// =============================================================================
// FUN_0048eef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048eef0
// Address:   0x0048eef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048eef0 @ 0x0048eef0
// Stable ID: aa_0048eef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0048eef0, FUN_0079db80.
//  - Return sites: 3.

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

void __thiscall FUN_0048eef0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(int *)(param_1 + 0xb8) == 0) {

    DAT_00b04820 = (uint8_t)param_2;

    return;

  }

  if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0) {

    FUN_0079db80(param_2);

    DAT_00b04820 = (uint8_t)param_2;

    return;

  }

  DAT_00b04820 = (uint8_t)param_2;

  return;

}
