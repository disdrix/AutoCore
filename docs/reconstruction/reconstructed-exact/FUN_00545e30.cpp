// =============================================================================
// FUN_00545e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00545e30
// Address:   0x00545e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00545e30 @ 0x00545e30
// Stable ID: aa_00545e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_00545e30.
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

void __fastcall FUN_00545e30(int param_1)



{

  if (*(void **)(param_1 + 0x14c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x14c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = 0;

  if (*(void **)(param_1 + 0x150) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x150));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

  if (*(void **)(param_1 + 0x154) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x154));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = 0;

  if (*(void **)(param_1 + 0x158) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x158));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = 0;

  if (*(void **)(param_1 + 0x15c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x15c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  if (*(void **)(param_1 + 0x160) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x160));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = 0;

  if (*(void **)(param_1 + 0x164) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x164));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = 0;

  if (*(void **)(param_1 + 0x148) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x148));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  return;

}
