// =============================================================================
// UI_int_btn_generic_0082fc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fc40
// Address:   0x0082fc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_int_btn_generic_0082fc40 @ 0x0082fc40
// Stable ID: aa_0082fc40
// Embedded strings (evidence for future rename):
//   - "i_m_int_2d_btn_generic.xml"
//   - "Trade"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: UI_int_btn_generic_0082fc40.
//  - Strings: "i_m_int_2d_btn_generic.xml"; "Trade".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_m_int_2d_btn_generic.xml"
 * Domain alias of FUN_0082fc40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_int_btn_generic_0082fc40(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  float *pfVar5;

  int unaff_EBX;

  int *unaff_ESI;

  

  if ((*(int *)(unaff_EBX + 0x6b4) < 1) || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

    piVar4 = (int *)(**(code **)(*unaff_ESI + 0x444))

                              ("i_m_int_2d_btn_generic.xml",0,0x11175,0xffffffff);

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 0x1d8))("Trade",1,1);

    }

    unaff_ESI[0x154] = (int)piVar4;

    pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(unaff_EBX + 4) + 4) + 4 + unaff_EBX) +

                                  0x1a0))();

    fVar1 = *pfVar5;

    fVar2 = pfVar5[1];

    fVar3 = pfVar5[2];

    pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    if (((int *)unaff_ESI[0x154] != (int *)0x0) &&

       (DAT_00aaa674 <

        (fVar3 - pfVar5[2]) * (fVar3 - pfVar5[2]) + (fVar2 - pfVar5[1]) * (fVar2 - pfVar5[1]) +

        (fVar1 - *pfVar5) * (fVar1 - *pfVar5))) {

      (**(code **)(*(int *)unaff_ESI[0x154] + 0xd4))(0);

    }

  }

  return;

}
