// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_00857ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00857ca0
// Callee of Named_CalleeOf_Drive_SIZE_VEHICLES
// Address:   0x00857ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_SIZE_VEHICLES: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: return×6, if×5, do×2, while×2.
//  - Notable callees: FUN_0096efd0×5, FUN_00857ca0.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_SIZE_VEHICLES
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_00857ca0(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  pvVar1 = *(void **)(param_1 + 0x5cc);

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x5d0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d0) = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5d4);

  iVar2 = 0x14;

  do {

    pvVar1 = (void *)*puVar3;

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x624);

  iVar2 = 9;

  do {

    pvVar1 = (void *)*puVar3;

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  pvVar1 = *(void **)(param_1 + 0x648);

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x648) = 0;

  return;

}
