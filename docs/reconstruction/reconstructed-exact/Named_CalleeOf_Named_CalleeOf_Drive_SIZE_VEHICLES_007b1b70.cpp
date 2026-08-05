// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_007b1b70
// -----------------------------------------------------------------------------
// Stable ID: aa_007b1b70
// Callee of Named_CalleeOf_Drive_SIZE_VEHICLES
// Address:   0x007b1b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_SIZE_VEHICLES: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0096efd0×2, FUN_007b1b70, FUN_0096f3e0, FUN_00989e00.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Drive_SIZE_VEHICLES_007b1b70(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint8_t local_4 [4];

  

  pvVar1 = (void *)*unaff_ESI;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *unaff_ESI = 0;

  puVar2 = operator_new(4);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar2 = 0;

  }

  *unaff_ESI = puVar2;

  FUN_00989e00(local_4,param_1);

  iVar3 = FUN_0096f3e0(local_4,0);

  if (iVar3 < 0) {

    pvVar1 = (void *)*unaff_ESI;

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *unaff_ESI = 0;

  }

  return;

}
