// =============================================================================
// FUN_005feb50
// -----------------------------------------------------------------------------
// Stable ID: aa_005feb50
// Address:   0x005feb50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005feb50 @ 0x005feb50
// Stable ID: aa_005feb50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00516720, FUN_005cb520, FUN_005feb50.
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

void __thiscall FUN_005feb50(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_005cb520(param_2,param_3,param_4);

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xdc);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe0);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe8);

    FUN_00516720(param_2 + 0xf0);

    *(uint16_t *)(param_1 + -0x14) = *(uint16_t *)(param_2 + 0x154);

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =

         *(uint32_t /* width from decompiler */ *)(param_2 + 0xec);

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =

         *(uint32_t /* width from decompiler */ *)(param_2 + 0xec);

  }

  return;

}
