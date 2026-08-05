// =============================================================================
// FUN_00967400
// -----------------------------------------------------------------------------
// Stable ID: aa_00967400
// Address:   0x00967400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00967400 @ 0x00967400
// Stable ID: aa_00967400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2.
//  - Notable callees: FUN_00414b60×2, FUN_00967150×2, FUN_00967400.
//  - Return sites: 4.

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

void FUN_00967400(int param_1)



{

  void *pvVar1;

  int *piVar2;

  

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x14) == *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 4) == *(uint32_t /* width from decompiler */ **)(param_1 + 8)) {

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      return;

    }

    pvVar1 = (void *)**(uint32_t /* width from decompiler */ **)(param_1 + 4);

    piVar2 = *(int **)((int)pvVar1 + 0x10);

    if (piVar2 == (int *)0x0) {

      FUN_00967150(pvVar1);

      piVar2 = *(int **)((int)pvVar1 + 0x10);

      if (piVar2 == (int *)0x0) goto LAB_00967477;

    }

    (**(code **)(*piVar2 + 8))(piVar2);

LAB_00967477:

    FUN_00414b60();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = (void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  piVar2 = *(int **)((int)pvVar1 + 0x10);

  if (piVar2 == (int *)0x0) {

    FUN_00967150(pvVar1);

    piVar2 = *(int **)((int)pvVar1 + 0x10);

    if (piVar2 == (int *)0x0) goto LAB_00967434;

  }

  (**(code **)(*piVar2 + 8))(piVar2);

LAB_00967434:

  FUN_00414b60();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
