// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0089c330
// -----------------------------------------------------------------------------
// Stable ID: aa_0089c330
// Callee of Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x0089c330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×29, goto×5, return×4.
//  - Notable callees: FUN_0089bf50×2, CNDHash_LookupByKey, FUN_00522060, FUN_0089c330, sprintf.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryAddItem
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0089c330(void)



{

  char cVar1;

  void *pvVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  int local_10;

  char local_c [12];

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (DAT_00d1b570 == 0) {

    return;

  }

  local_10 = 0;

  pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),*(uint *)(unaff_ESI + 0x5ec));

  if ((pvVar2 == (void *)0x0) ||

     (FUN_00522060(pvVar2,&local_10,*(uint8_t *)(unaff_ESI + 0x528),

                   *(uint8_t *)(unaff_ESI + 0x538)), local_10 == 0)) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x524) = 0;

    if (*(int **)(unaff_ESI + 0x608) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x608) + 0x3ac))(&DAT_00a32460);

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x608) + 0xd8))();

      if (cVar1 == '\x01') {

        (**(code **)(**(int **)(unaff_ESI + 0x608) + 0xd4))(0);

      }

      (**(code **)(**(int **)(unaff_ESI + 0x608) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x5f0) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0xd4))(0);

      (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x5f4) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0xd4))(0);

      (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x5f8) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0xd4))(0);

      (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x5fc) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0xd4))(0);

      (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0x34c))();

      FUN_0089bf50();

      return;

    }

    goto LAB_0089c6b1;

  }

  if (local_10 < *(int *)(unaff_ESI + 0x524)) {

    *(int *)(unaff_ESI + 0x524) = local_10;

  }

  else if (*(int *)(unaff_ESI + 0x524) < 1) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x524) = 1;

  }

  if (*(int *)(unaff_ESI + 0x608) != 0) {

    sprintf(local_c,"%d",*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x524));

    (**(code **)(**(int **)(unaff_ESI + 0x608) + 0x3ac))(local_c);

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x608) + 0xd8))();

    if (cVar1 == '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x608) + 0xd4))(1);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x608) + 0x34c))();

  }

  if (*(int **)(unaff_ESI + 0x5f0) != (int *)0x0) {

    if (*(int *)(unaff_ESI + 0x524) == 1) {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0xd8))();

      if (cVar1 == '\x01') {

        (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0x34c))();

      }

      else if (*(int *)(unaff_ESI + 0x524) != 1) goto LAB_0089c54a;

    }

    else {

LAB_0089c54a:

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0xd8))();

      if (cVar1 == '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0xd4))(1);

        (**(code **)(**(int **)(unaff_ESI + 0x5f0) + 0x34c))();

      }

    }

  }

  if (*(int **)(unaff_ESI + 0x5fc) != (int *)0x0) {

    if (*(int *)(unaff_ESI + 0x524) == 1) {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0xd8))();

      if (cVar1 == '\x01') {

        (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0x34c))();

      }

      else if (*(int *)(unaff_ESI + 0x524) != 1) goto LAB_0089c5bf;

    }

    else {

LAB_0089c5bf:

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0xd8))();

      if (cVar1 == '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0xd4))(1);

        (**(code **)(**(int **)(unaff_ESI + 0x5fc) + 0x34c))();

      }

    }

  }

  if (*(int **)(unaff_ESI + 0x5f4) != (int *)0x0) {

    if ((*(int *)(unaff_ESI + 0x524) == local_10) &&

       (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0xd8))(), cVar1 == '\x01')) {

      uVar3 = 0;

    }

    else {

      if ((*(int *)(unaff_ESI + 0x524) == local_10) ||

         (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0xd8))(), cVar1 != '\0'))

      goto LAB_0089c64f;

      uVar3 = 1;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0xd4))(uVar3);

    (**(code **)(**(int **)(unaff_ESI + 0x5f4) + 0x34c))();

  }

LAB_0089c64f:

  if (*(int **)(unaff_ESI + 0x5f8) != (int *)0x0) {

    if ((*(int *)(unaff_ESI + 0x524) < local_10) ||

       (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0xd8))(), cVar1 != '\x01')) {

      if ((*(int *)(unaff_ESI + 0x524) == local_10) ||

         (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0xd8))(), cVar1 != '\0'))

      goto LAB_0089c6b1;

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0xd4))(uVar3);

    (**(code **)(**(int **)(unaff_ESI + 0x5f8) + 0x34c))();

  }

LAB_0089c6b1:

  FUN_0089bf50();

  return;

}
