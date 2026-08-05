// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_008a0210
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0210
// Callee of Client_Input_PollBoundActions (+1 other named callers)
// Address:   0x008a0210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_Input_PollBoundActions (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×12, goto×6, while×4, return×2, do×1.
//  - Notable callees: FUN_00826780×2, FUN_0089fef0, FUN_008a0210, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions (+1 other named callers)
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

uint Named_CalleeOf_Client_Input_PollBoundActions_008a0210(char param_1)



{

  int iVar1;

  uint uVar2;

  int *piVar3;

  int *piVar4;

  int unaff_EBX;

  int iVar5;

  int iVar6;

  

  piVar4 = (int *)(unaff_EBX + 0x63c);

  iVar6 = 0;

  piVar3 = piVar4;

  do {

    if ((*piVar3 != 0) && (*(char *)(*piVar3 + 0x4fc) != '\0')) {

      iVar5 = iVar6;

      if (param_1 == '\0') goto joined_r0x008a027f;

      goto joined_r0x008a024b;

    }

    iVar6 = iVar6 + 1;

    piVar3 = piVar3 + 1;

  } while (iVar6 < 10);

  goto LAB_008a02c9;

  while( true ) {

    if (9 < iVar5) {

      iVar5 = 0;

    }

    iVar1 = *(int *)(unaff_EBX + 0x63c + iVar5 * 4);

    piVar3 = (int *)0x0;

    if (((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 0x548), piVar3 != (int *)0x0)) &&

       (piVar3 != (int *)0x6)) break;

joined_r0x008a024b:

    iVar5 = iVar5 + 1;

    if (iVar5 == iVar6) goto LAB_008a02c9;

  }

  goto LAB_008a02ad;

  while( true ) {

    if (iVar5 < 0) {

      iVar5 = 9;

    }

    iVar1 = *(int *)(unaff_EBX + 0x63c + iVar5 * 4);

    piVar3 = (int *)0x0;

    if (((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 0x548), piVar3 != (int *)0x0)) &&

       (piVar3 != (int *)0x6)) break;

joined_r0x008a027f:

    iVar5 = iVar5 + -1;

    if (iVar5 == iVar6) goto LAB_008a02c9;

  }

LAB_008a02ad:

  FUN_00826780(0);

  piVar3 = (int *)FUN_00826780(1);

LAB_008a02c9:

  if (iVar6 == 10) {

    uVar2 = 0;

    while (((*piVar4 == 0 || (iVar6 = *(int *)(*piVar4 + 0x548), iVar6 == 0)) || (iVar6 == 6))) {

      uVar2 = uVar2 + 1;

      piVar4 = piVar4 + 1;

      if (9 < (int)uVar2) {

        return uVar2 & 0xffffff00;

      }

    }

    iVar6 = *(int *)(unaff_EBX + 0x63c + uVar2 * 4);

    piVar3 = *(int **)(iVar6 + 0x548);

    if ((piVar3 != (int *)0x0) && (piVar3 != (int *)0x6)) {

      __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x88),0,&gfxUIWindow::RTTI_Type_Descriptor,

                      &CDlgQuickBar::RTTI_Type_Descriptor,0);

      piVar3 = (int *)FUN_0089fef0();

      if (*(int **)(iVar6 + 0x56c) != (int *)0x0) {

        piVar3 = (int *)(**(code **)(**(int **)(iVar6 + 0x56c) + 4))(1);

      }

      *(uint32_t /* width from decompiler */ *)(&DAT_00d1da38 + *(int *)(iVar6 + 0x504) * 4) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x500);

      *(uint8_t *)(iVar6 + 0x4fc) = 1;

    }

  }

  return (uint)piVar3 & 0xffffff00;

}
