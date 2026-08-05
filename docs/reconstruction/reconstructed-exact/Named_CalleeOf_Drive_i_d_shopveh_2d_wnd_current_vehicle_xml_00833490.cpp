// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_00833490
// -----------------------------------------------------------------------------
// Stable ID: aa_00833490
// Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
// Address:   0x00833490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_current_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00755c30×2, FUN_0040d1a0, FUN_00833490.
//  - Return sites: 2.

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

void Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_00833490(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_10 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x590);

  local_c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x594);

  local_8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x598);

  local_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x59c);

  piVar1 = (int *)FUN_00755c30();

  piVar2 = piVar1;

  if (piVar1 != (int *)0x0) {

    do {

      puVar3 = &local_10;

      (**(code **)(*piVar2 + 0x10))(3,puVar3);

      FUN_0040d1a0(puVar3);

      piVar2 = (int *)FUN_00755c30();

      if (piVar2 == (int *)0x0) {

        return;

      }

    } while (piVar2 != piVar1);

  }

  return;

}
