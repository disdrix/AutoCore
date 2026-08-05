// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_00833390
// -----------------------------------------------------------------------------
// Stable ID: aa_00833390
// Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
// Address:   0x00833390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_current_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004e8320, FUN_00833390.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
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

void Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_00833390(void)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint8_t auStack_c [12];

  

  if (((in_EAX != 0) && (*(int *)(in_EAX + 0x48) != 0)) && (*(int *)(in_EAX + 0x3a0) != 0)) {

    iVar2 = *(int *)(in_EAX + 4);

    local_18 = *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(in_EAX + 0xac + *(int *)(iVar2 + 4)) + 0x3c) + 0x4f4);

    local_14 = *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(in_EAX + 0xac + *(int *)(iVar2 + 4)) + 0x3c) + 0x4f8);

    local_10 = *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(in_EAX + 0xac + *(int *)(iVar2 + 4)) + 0x3c) + 0x4fc);

    if (*(int **)(in_EAX + 0x48) == (int *)0x0) {

      puVar4 = &DAT_00afdfec;

    }

    else {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x48) + 0xc))();

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

    }

    if (*(int **)(in_EAX + 0x48) == (int *)0x0) {

      puVar3 = &DAT_00d1a6c0;

    }

    else {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x48) + 0xc))();

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

    }

    FUN_004e8320(puVar3,puVar4,&local_18,auStack_c);

    (**(code **)(**(int **)(in_EAX + 0x3a0) + 0x18))(auStack_c);

    piVar1 = *(int **)(in_EAX + 0x3a0);

    iVar2 = (**(code **)(**(int **)(in_EAX + 0x48) + 0xc))();

    (**(code **)(*piVar1 + 0x14))(iVar2 + 0x80);

  }

  return;

}
