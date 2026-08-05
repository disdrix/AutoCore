// =============================================================================
// FUN_0075b3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b3e0
// Address:   0x0075b3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075b3e0 @ 0x0075b3e0
// Stable ID: aa_0075b3e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0075b3e0.
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

uint32_t /* width from decompiler */ FUN_0075b3e0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x38);

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x34); puVar2 != puVar3; puVar2 = puVar2 + 1) {

    (**(code **)(*(int *)*puVar2 + 0x10))();

  }

  uVar1 = 0;

  if (*(int *)(param_1 + 4) != 0) {

    uVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(param_1 + 0x10);

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x38);

  for (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x34); puVar3 != puVar2; puVar3 = puVar3 + 1) {

    (**(code **)(*(int *)*puVar3 + 0x18))();

  }

  return uVar1;

}
