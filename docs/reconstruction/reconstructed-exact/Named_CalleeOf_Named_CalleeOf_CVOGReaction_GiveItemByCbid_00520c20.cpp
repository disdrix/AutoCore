// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00520c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00520c20
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x00520c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00520c20, InventoryGrid_SetOwnerFlag_Inferred, InventoryGrid_ctor_Inferred.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00520c20(int param_1)



{

  void *pvVar1;

  void *unaff_EBX;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a37d0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xcbc) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xcbc))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcbc) = 0;

  pvVar1 = operator_new(0x68);

  uStack_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = InventoryGrid_ctor_Inferred(pvVar1,6,0x34,4);

  }

  uStack_4 = 0xffffffff;

  *(void **)(param_1 + 0xcbc) = pvVar1;

  InventoryGrid_SetOwnerFlag_Inferred(pvVar1,3);

  (**(code **)(**(int **)(param_1 + 0xcbc) + 0x14))

            (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));

  (**(code **)(**(int **)(param_1 + 0xcbc) + 0x18))

            (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

  ExceptionList = unaff_EBX;

  return;

}
