// =============================================================================
// FUN_0074ec90
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ec90
// Address:   0x0074ec90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074ec90 @ 0x0074ec90
// Stable ID: aa_0074ec90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00448f50, FUN_0074ec90.
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

void __thiscall FUN_0074ec90(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  FUN_00448f50();

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4); puVar2 != puVar1; puVar2 = puVar2 + 1) {

    (**(code **)(*(int *)*puVar2 + 0x20))(param_2);

  }

  return;

}
