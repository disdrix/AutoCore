// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attr_008cf8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf8a0
// Callee of Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
// Address:   0x008cf8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_008cf8a0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
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

void Named_CalleeOf_Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attr_008cf8a0(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int unaff_EBX;

  int *unaff_ESI;

  int *unaff_EDI;

  int iVar6;

  int iStack_18;

  float fStack_14;

  float fStack_10;

  

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x34c))();

    if ((unaff_EDI == (int *)0x0) || (iVar2 = (**(code **)(*unaff_EDI + 0x1b8))(), iVar2 == 0)) {

      (**(code **)(*unaff_ESI + 0xd4))(0);

      (**(code **)(*unaff_ESI + 4))(0);

      return;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EDI + 0x140))(&iStack_18,1);

    fStack_10 = (float)*puVar3;

    iVar2 = puVar3[1];

    (**(code **)(*unaff_EDI + 0x204))(&iStack_18);

    if (iVar2 < iStack_18) {

      (**(code **)(*unaff_ESI + 0xd4))(1);

      (**(code **)(*unaff_ESI + 4))(1);

      piVar4 = (int *)(**(code **)(*unaff_EDI + 0x1b8))();

      iVar2 = ((*(int *)(*piVar4 + 0x7c) - iVar2) + -1 + unaff_EBX) / *(int *)(*piVar4 + 0x7c);

      if (iVar2 < 1) {

        iVar2 = 1;

      }

      cVar1 = (**(code **)(*unaff_ESI + 0xd0))();

      if (cVar1 == '\0') {

        (**(code **)(*unaff_ESI + 0xfc))(1,0x3f000000);

      }

      fStack_10 = (float)iVar2;

      (**(code **)(*unaff_ESI + 0x460))(g_flOne / fStack_10);

      iVar6 = *unaff_ESI;

      iVar5 = (**(code **)(*unaff_EDI + 0x218))(0);

      (**(code **)(iVar6 + 0x454))((float)iVar5 / fStack_14);

      if (param_1 != (int *)0x0) {

        *param_1 = iVar2;

        return;

      }

    }

    else {

      (**(code **)(*unaff_ESI + 0xd4))(0);

      (**(code **)(*unaff_ESI + 4))(0);

    }

  }

  return;

}
