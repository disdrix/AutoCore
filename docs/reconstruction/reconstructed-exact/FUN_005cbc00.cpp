// =============================================================================
// FUN_005cbc00
// -----------------------------------------------------------------------------
// Stable ID: aa_005cbc00
// Address:   0x005cbc00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cbc00 @ 0x005cbc00
// Stable ID: aa_005cbc00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_005cbc00, FUN_005d48f0.
//  - Return sites: 5.

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

void __fastcall FUN_005cbc00(int param_1)



{

  int iVar1;

  void *pvVar2;

  

  *(undefined ***)(param_1 + -0x110) = &PTR_FUN_009da70c;

  *(undefined ***)(param_1 + -0xd0) = &PTR_FUN_009da6d0;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) = &PTR_LAB_009da40c;

  iVar1 = *(int *)(*(int *)(param_1 + -0x10c) + 4);

  *(int *)(iVar1 + -0x110 + param_1) = iVar1 + -0x10c;

  pvVar2 = *(void **)(param_1 + -0x40);

  if (pvVar2 != (void *)0x0) {

    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar2 + 4));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(param_1 + -0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x40) = 0;

  if (pvVar2 == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3c) = 0;

    FUN_005d48f0();

    return;

  }

  if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)((int)pvVar2 + 4));

  }

  *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
