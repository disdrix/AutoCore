// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot_00826780
// -----------------------------------------------------------------------------
// Stable ID: aa_00826780
// Callee of Named_CalleeOf_Client_QuickBar_ActivateSlot (+1 other named callers)
// Address:   0x00826780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_QuickBar_ActivateSlot (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00826780, FUN_0089fef0, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_QuickBar_ActivateSlot (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot_00826780(int param_1,char param_2)



{

  int iVar1;

  

  if (param_2 == '\0') {

    if ((*(char *)(param_1 + 0x4fc) != '\0') && (*(int **)(param_1 + 0x56c) != (int *)0x0)) {

      (**(code **)(**(int **)(param_1 + 0x56c) + 4))(0);

    }

    if (*(int **)(param_1 + 0x564) != (int *)0x0) {

      iVar1 = (**(code **)(**(int **)(param_1 + 0x564) + 0x164))(0);

      *(uint8_t *)(iVar1 + 3) = 0xff;

      (**(code **)(**(int **)(param_1 + 0x564) + 0x34c))();

    }

    if (*(int *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) == *(int *)(param_1 + 0x500)) {

      *(uint32_t /* width from decompiler */ *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) = 0xffffffff;

    }

    *(uint8_t *)(param_1 + 0x4fc) = 0;

  }

  else if ((*(int *)(param_1 + 0x548) != 0) && (*(int *)(param_1 + 0x548) != 6)) {

    __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88),0,&gfxUIWindow::RTTI_Type_Descriptor,

                    &CDlgQuickBar::RTTI_Type_Descriptor,0);

    FUN_0089fef0();

    if (*(int **)(param_1 + 0x56c) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x56c) + 4))(1);

    }

    *(uint32_t /* width from decompiler */ *)(&DAT_00d1da38 + *(int *)(param_1 + 0x504) * 4) =

         *(uint32_t /* width from decompiler */ *)(param_1 + 0x500);

    *(char *)(param_1 + 0x4fc) = param_2;

    return;

  }

  return;

}
