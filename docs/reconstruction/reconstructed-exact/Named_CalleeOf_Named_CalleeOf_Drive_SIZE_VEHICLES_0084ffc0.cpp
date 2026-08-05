// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_0084ffc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084ffc0
// Callee of Named_CalleeOf_Drive_SIZE_VEHICLES
// Address:   0x0084ffc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_SIZE_VEHICLES: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: return×7, if×6, do×2, while×2.
//  - Notable callees: FUN_0096efd0×6, FUN_0084ffc0.
//  - Return sites: 7.

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

void Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_0084ffc0(void)



{

  void *pvVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  pvVar1 = *(void **)(in_EAX + 0x5a0);

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(in_EAX + 0x5a4);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a0) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(in_EAX + 0x5a8);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a4) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(in_EAX + 0x5ac);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a8) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ac) = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x5b0);

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

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x600);

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

  return;

}
