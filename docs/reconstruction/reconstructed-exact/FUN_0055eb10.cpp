// =============================================================================
// FUN_0055eb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0055eb10
// Address:   0x0055eb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055eb10 @ 0x0055eb10
// Stable ID: aa_0055eb10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055eb10, FUN_005b3370, FUN_0062a780.
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

void __thiscall FUN_0055eb10(int param_1,int param_2)



{

  if (*(uint *)(param_1 + 0x18) == (*(uint *)(param_1 + 0x1c) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x14),4);

  }

  *(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * 4) = param_2;

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + *(int *)(param_2 + 0x24) * 4) =

       *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + -4 + *(int *)(param_1 + 0xc) * 4);

  *(int *)(*(int *)(*(int *)(param_1 + 8) + *(int *)(param_2 + 0x24) * 4) + 0x24) =

       *(int *)(param_2 + 0x24);

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

  *(int *)(param_2 + 0x24) = *(int *)(param_1 + 0x18) + -1;

  *(uint8_t *)(param_2 + 0x29) = 0;

  FUN_0062a780(param_1,param_2);

  return;

}
