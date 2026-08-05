// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083abf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083abf0
// Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
// Address:   0x0083abf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00427d20, FUN_0083ab90, FUN_0083abf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083abf0(int param_1,int param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  int iVar5;

  

  iVar2 = (int)param_3;

  if (((((-1 < param_2) && (*(int *)((int)param_3 + 0x508) != 0)) && (-1 < param_1)) &&

      ((param_1 < 5 && (iVar1 = *(int *)((int)param_3 + 0x50c + param_1 * 4), iVar1 != 0)))) &&

     (*(int *)(*(int *)((int)param_3 + 0x508) + 0x50) != 0)) {

    param_3 = (int *)0x0;

    cVar4 = FUN_00427d20(param_2,&param_3);

    piVar3 = param_3;

    if (((cVar4 != '\0') && (param_3 != (int *)0x0)) &&

       ((iVar5 = (**(code **)(*param_3 + 0x1d4))(), iVar5 != 0 &&

        ((*(int *)(iVar1 + 0x508) == 0 ||

         (iVar1 = *(int *)(iVar1 + 0x50c), iVar5 = (**(code **)(*piVar3 + 0x1d4))(), iVar1 != iVar5)

         ))))) {

      (**(code **)(*piVar3 + 0x1d4))();

      FUN_0083ab90(iVar2);

    }

  }

  return;

}
