// =============================================================================
// FUN_00962400
// -----------------------------------------------------------------------------
// Stable ID: aa_00962400
// Address:   0x00962400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962400 @ 0x00962400
// Stable ID: aa_00962400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004367f0, FUN_00962400.
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

void __fastcall FUN_00962400(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c); puVar2 != puVar1; puVar2 = puVar2 + 1) {

    (**(code **)(*(int *)*puVar2 + 0xc))();

  }

  *(uint8_t *)(param_1 + 0x38) = 0;

  FUN_004367f0(0,0);

  return;

}
