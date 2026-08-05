// =============================================================================
// FUN_005a85c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a85c0
// Address:   0x005a85c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a85c0 @ 0x005a85c0
// Stable ID: aa_005a85c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a85c0, FUN_005cb480, _eh_vector_destructor_iterator_.
//  - Return sites: 2.

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

void __fastcall FUN_005a85c0(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0x160) = &PTR_FUN_009d86b8;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x15c) + 4) + -0x15c + param_1) = &PTR_LAB_009d83f4;

  iVar1 = *(int *)(*(int *)(param_1 + -0x15c) + 4);

  *(int *)(iVar1 + -0x160 + param_1) = iVar1 + -0x15c;

  (**(code **)(*(int *)(param_1 + -0x160) + 4))();

  _eh_vector_destructor_iterator_((void *)(param_1 + -0x30),0x10,2,FUN_00691630);

  if (*(void **)(param_1 + -0x3c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x3c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x34) = 0;

  FUN_005cb480();

  return;

}
