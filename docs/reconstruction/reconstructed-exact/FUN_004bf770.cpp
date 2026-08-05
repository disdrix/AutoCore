// =============================================================================
// FUN_004bf770
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf770
// Address:   0x004bf770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bf770 @ 0x004bf770
// Stable ID: aa_004bf770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004bf770.
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

void __thiscall FUN_004bf770(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = operator_new(0x10);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = &PTR_LAB_009cb5d4;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

  }

  puVar1[3] = param_2;

  puVar1[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  puVar1[2] = 0;

  if (*(int *)(param_1 + 4) != 0) {

    *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 8) = puVar1;

  }

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar1;

  return;

}
