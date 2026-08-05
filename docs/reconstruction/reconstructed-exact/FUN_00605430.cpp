// =============================================================================
// FUN_00605430
// -----------------------------------------------------------------------------
// Stable ID: aa_00605430
// Address:   0x00605430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605430 @ 0x00605430
// Stable ID: aa_00605430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00582b00, FUN_00605430.
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

void __fastcall FUN_00605430(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0xc0) = &PTR_FUN_009de430;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) = &PTR_LAB_009de16c;

  iVar1 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

  *(int *)(iVar1 + -0xc0 + param_1) = iVar1 + -0xbc;

  if (*(void **)(param_1 + -0x30) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x30));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = 0;

  FUN_00582b00();

  return;

}
