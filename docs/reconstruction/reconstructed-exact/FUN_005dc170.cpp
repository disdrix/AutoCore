// =============================================================================
// FUN_005dc170
// -----------------------------------------------------------------------------
// Stable ID: aa_005dc170
// Address:   0x005dc170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dc170 @ 0x005dc170
// Stable ID: aa_005dc170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×6, if×5.
//  - Notable callees: FUN_005d48f0, FUN_005dc170.
//  - Return sites: 6.

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

void __fastcall FUN_005dc170(int param_1)



{

  int iVar1;

  

  *(undefined ***)(param_1 + -0x1c0) = &PTR_LAB_009db924;

  *(undefined ***)(param_1 + -0x180) = &PTR_FUN_009db8e8;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x1bc + param_1) = &PTR_LAB_009db624;

  iVar1 = *(int *)(*(int *)(param_1 + -0x1bc) + 4);

  *(int *)(iVar1 + -0x1c0 + param_1) = iVar1 + -0x1bc;

  (**(code **)(*(int *)(param_1 + -0x1c0) + 4))();

  if (*(void **)(param_1 + -0x20) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x20));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x18) = 0;

  if (*(void **)(param_1 + -0x58) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x58));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x50) = 0;

  if (*(void **)(param_1 + -0x78) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x78));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x70) = 0;

  if (*(void **)(param_1 + -0x88) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x88));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x80) = 0;

  if (*(void **)(param_1 + -0x98) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x98));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x90) = 0;

  FUN_005d48f0();

  return;

}
