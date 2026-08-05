// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007ff9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ff9c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x007ff9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "i_g_2d_wnd_screen_cover.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_g_2d_wnd_screen_cover.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0, FUN_007ff9c0.
//  - Strings: "i_g_2d_wnd_screen_cover.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007ff9c0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  void *pvVar2;

  int *piVar3;

  int unaff_ESI;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b32b5;

  pvStack_c = ExceptionList;

  iVar1 = *(int *)(unaff_ESI + 0x1148);

  ExceptionList = &pvStack_c;

  if (((iVar1 != 0) && (ExceptionList = &pvStack_c, *(int *)(iVar1 + 0x2b0) != 0)) &&

     (ExceptionList = &pvStack_c, *(int **)(unaff_ESI + 0xf38) != (int *)0x0)) {

    ExceptionList = &pvStack_c;

    (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0xb0))(iVar1,param_1);

  }

  if (*(int *)(unaff_ESI + 0x1148) == 0) {

    pvVar2 = operator_new(0x488);

    uStack_4 = 0;

    if (pvVar2 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_007b5dd0(pvVar2,0);

    }

    uStack_4 = 0xffffffff;

    *(int **)(unaff_ESI + 0x1148) = piVar3;

    (**(code **)(*piVar3 + 0x28))("i_g_2d_wnd_screen_cover.xml",pvVar2);

  }

  if (**(int **)(unaff_ESI + 0xf40) != 0) {

    (**(code **)(*(int *)**(int **)(unaff_ESI + 0xf40) + 0xa8))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1148))

    ;

  }

  if (unaff_EDI != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x1148) + 0x154))(0);

    (**(code **)(**(int **)(unaff_ESI + 0x1148) + 0x34c))();

  }

  ExceptionList = pvStack_c;

  return;

}
