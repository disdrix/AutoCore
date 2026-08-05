// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00520ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00520ce0
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x00520ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00520ce0, InventoryGrid_SetOwnerFlag_Inferred, InventoryGrid_ctor_Inferred.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00520ce0(int param_1)



{

  void *this;

  void *this_00;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a37e5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xce0) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xce0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xce0) = 0;

  this = operator_new(0x68);

  uStack_4 = 0;

  if (this == (void *)0x0) {

    this_00 = (void *)0x0;

  }

  else {

    this_00 = InventoryGrid_ctor_Inferred(this,6,4,1);

  }

  uStack_4 = 0xffffffff;

  *(void **)(param_1 + 0xce0) = this_00;

  InventoryGrid_SetOwnerFlag_Inferred(this_00,5);

  (**(code **)(**(int **)(param_1 + 0xce0) + 0x14))

            (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));

  ExceptionList = this;

  return;

}
