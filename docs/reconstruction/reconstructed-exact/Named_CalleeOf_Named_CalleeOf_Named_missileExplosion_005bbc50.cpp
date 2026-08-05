// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbc50
// -----------------------------------------------------------------------------
// Stable ID: aa_005bbc50
// Callee of Named_CalleeOf_Named_missileExplosion
// Address:   0x005bbc50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_missileExplosion: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×1, while×1.
//  - Notable callees: FUN_005b8340×5, FUN_005bbc50, FUN_005be2b0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_missileExplosion
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbc50(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a6bad;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_005b8340();

  pvVar1 = *(void **)(param_1 + 0x308);

  if (pvVar1 != (void *)(param_1 + 0x14)) {

    FUN_005b8340();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  FUN_005b8340();

  if (*(char *)(param_1 + 0x7fc) != '\0') {

    pvVar1 = *(void **)(param_1 + 0x6ec);

    if (pvVar1 != (void *)(param_1 + 0x3f8)) {

      FUN_005b8340();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    FUN_005b8340();

  }

  piVar3 = (int *)**(int **)(param_1 + 0xa24);

  if (piVar3 != *(int **)(param_1 + 0xa24)) {

    do {

      FUN_005be2b0(piVar3[2]);

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0xa24));

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xa24);

  pvVar1 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0xa24) + 4) = *(int *)(param_1 + 0xa24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa28) = 0;

  if (pvVar1 != *(void **)(param_1 + 0xa24)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xa24);

  pvVar1 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0xa24) + 4) = *(int *)(param_1 + 0xa24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa28) = 0;

  if (pvVar1 != *(void **)(param_1 + 0xa24)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0xa24));

}
