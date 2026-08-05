// =============================================================================
// FUN_006343a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006343a0
// Address:   0x006343a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006343a0 @ 0x006343a0
// Stable ID: aa_006343a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006343a0.
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

void __thiscall FUN_006343a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(uint *)(param_1 + 0x40) == (*(uint *)(param_1 + 0x44) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x3c),4);

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x40) * 4) = param_2;

  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;

  return;

}
