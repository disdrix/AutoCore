// =============================================================================
// FUN_0068ed20
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ed20
// Address:   0x0068ed20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068ed20 @ 0x0068ed20
// Stable ID: aa_0068ed20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0068ed20, _eh_vector_destructor_iterator_.
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

void __fastcall FUN_0068ed20(int param_1)



{

  void *pvVar1;

  

  operator_delete__(*(void **)(param_1 + 0x20));

  operator_delete__(*(void **)(param_1 + 0x24));

  pvVar1 = *(void **)(param_1 + 0x2c);

  if (pvVar1 != (void *)0x0) {

    _eh_vector_destructor_iterator_(pvVar1,0x44,*(int *)((int)pvVar1 + -4),FUN_0068e800);

    operator_delete__((void *)((int)pvVar1 + -4));

  }

  operator_delete__(*(void **)(param_1 + 0x18));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  return;

}
