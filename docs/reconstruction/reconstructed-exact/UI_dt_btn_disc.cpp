// =============================================================================
// UI_dt_btn_disc
// -----------------------------------------------------------------------------
// Stable ID: aa_008e0410
// Address:   0x008e0410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_dt_btn_disc @ 0x008e0410
// Stable ID: aa_008e0410
// Embedded strings (evidence for future rename):
//   - "i_d_dt_2d_btn_disc.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0082c370, UI_dt_btn_disc.
//  - Strings: "i_d_dt_2d_btn_disc.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_dt_2d_btn_disc.xml"
 * Domain alias of FUN_008e0410 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_dt_btn_disc(void)



{

  int *piVar1;

  char cVar2;

  void *pvVar3;

  int *unaff_ESI;

  int unaff_EDI;

  int iStack_34;

  int iStack_30;

  char *pcStack_2c;

  int iStack_28;

  int iStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b7204;

  local_c = ExceptionList;

  if ((unaff_EDI < 0x11) && (-1 < unaff_EDI)) {

    ExceptionList = &local_c;

    cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

    if (cVar2 != '\0') {

      if (unaff_ESI[unaff_EDI + 0x166] != 0) {

        (**(code **)(*unaff_ESI + 0xbc))();

      }

      pvVar3 = operator_new(0x624);

      uStack_4 = 0;

      if (pvVar3 == (void *)0x0) {

        iStack_28 = 0;

      }

      else {

        iStack_28 = FUN_0082c370();

      }

      uStack_4 = 0xffffffff;

      unaff_ESI[unaff_EDI + 0x166] = iStack_28;

      pcStack_2c = (char *)0x8e04a3;

      (**(code **)(*unaff_ESI + 0xa8))();

      pcStack_2c = "i_d_dt_2d_btn_disc.xml";

      iStack_30 = 0x8e04b4;

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0x28))();

      iStack_30 = 0x8e04c3;

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0x43c))();

      iStack_30 = unaff_EDI + 0x9c43;

      iStack_34 = 0x8e04d6;

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0x74))();

      iStack_34 = 1;

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0xcc))();

      piVar1 = (int *)unaff_ESI[unaff_EDI + 0x166];

      piVar1[0x182] = unaff_ESI[unaff_EDI + 0x155];

      (**(code **)(*piVar1 + 0x448))();

      (**(code **)(*piVar1 + 0x34c))();

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0x140))(&stack0xffffffdc,1);

      iStack_34 = unaff_ESI[0x146] * iStack_14 + unaff_ESI[0x144] +

                  (unaff_ESI[0x146] - (int)pcStack_2c) / 2;

      iStack_30 = unaff_ESI[0x147] * iStack_10 + unaff_ESI[0x145] +

                  (unaff_ESI[0x147] - iStack_28) / 2;

      (**(code **)(*(int *)unaff_ESI[unaff_EDI + 0x166] + 0x110))(&iStack_34);

    }

  }

  ExceptionList = local_c;

  return;

}
