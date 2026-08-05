// =============================================================================
// FUN_0072a4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072a4d0
// Address:   0x0072a4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072a4d0 @ 0x0072a4d0
// Stable ID: aa_0072a4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0046d4b0, FUN_0072a4d0.
//  - Return sites: 3.

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

void __fastcall FUN_0072a4d0(int param_1)



{

  int *piVar1;

  void *pvVar2;

  int *piVar3;

  

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x10) != *(uint32_t /* width from decompiler */ **)(param_1 + 0x14)) {

    pvVar2 = (void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

    piVar3 = *(int **)((int)pvVar2 + 0x20);

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

    FUN_0046d4b0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  if (*(void **)(param_1 + 0x10) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x10));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint8_t *)(param_1 + 9) = 0;

  return;

}
