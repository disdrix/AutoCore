// =============================================================================
// UI_int_btn_generic_0082fd50
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fd50
// Address:   0x0082fd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_int_btn_generic_0082fd50 @ 0x0082fd50
// Stable ID: aa_0082fd50
// Embedded strings (evidence for future rename):
//   - "i_m_int_2d_btn_generic.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: UI_int_btn_generic_0082fd50.
//  - Strings: "i_m_int_2d_btn_generic.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_m_int_2d_btn_generic.xml"
 * Domain alias of FUN_0082fd50 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_int_btn_generic_0082fd50(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0x82fd69;

  uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_EBX + 4) + 4) + 4 + unaff_EBX) + 0x160))();

  uStack_14 = 0xffffffff;

  uStack_18 = 0x1117f;

  uStack_1c = 0;

  piVar2 = (int *)(**(code **)(*unaff_EDI + 0x444))("i_m_int_2d_btn_generic.xml");

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 0x1d8))(uVar1,1,1);

  }

  unaff_EDI[0x14f] = (int)piVar2;

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 0xd4))(0);

    if (*(int *)(unaff_EBX + 0x6b4) < 1) {

      uStack_18 = 0xff1ea0b4;

      puVar3 = &uStack_18;

    }

    else {

      uStack_1c = 0xffa01eb4;

      puVar3 = &uStack_1c;

    }

    (**(code **)(*(int *)unaff_EDI[0x14f] + 0x15c))(1,puVar3);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x14f] + 0x170) = 0xfffffffe;

    (**(code **)(*(int *)unaff_EDI[0x14f] + 0x1e4))(1);

  }

  return;

}
