// =============================================================================
// FUN_00787310
// -----------------------------------------------------------------------------
// Stable ID: aa_00787310
// Address:   0x00787310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787310 @ 0x00787310
// Stable ID: aa_00787310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00429800, FUN_00787310.
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

void __thiscall FUN_00787310(int param_1,int *param_2)



{

  FUN_00429800();

  *param_2 = param_1;

  if (*(code **)(param_1 + 0x10) != (code *)0x0) {

    (**(code **)(param_1 + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_2[3]);

  }

  if ((code *)param_2[1] != (code *)0x0) {

    (*(code *)param_2[1])(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_2[3]);

  }

  return;

}
