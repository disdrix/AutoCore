// =============================================================================
// FUN_005cb480
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb480
// Address:   0x005cb480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb480 @ 0x005cb480
// Stable ID: aa_005cb480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00582b00, FUN_005cb480.
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

void __fastcall FUN_005cb480(int param_1)



{

  int iVar1;

  void *pvVar2;

  

  *(undefined ***)(param_1 + -0xc0) = &PTR_FUN_009da3d0;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) = &PTR_LAB_009da10c;

  iVar1 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

  *(int *)(iVar1 + -0xc0 + param_1) = iVar1 + -0xbc;

  pvVar2 = *(void **)(param_1 + -0x44);

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

  pvVar2 = *(void **)(param_1 + -0x40);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x44) = 0;

  if (pvVar2 == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x40) = 0;

    FUN_00582b00();

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
