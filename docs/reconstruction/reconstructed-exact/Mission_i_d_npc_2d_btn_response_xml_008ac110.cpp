// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_0079c860, FUN_008aa560, FUN_008ac110.
//  - Strings: "i_d_npc_2d_btn_response.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_npc_2d_btn_response_xml_008ac110
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac110
// Address:   0x008ac110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_npc_2d_btn_response.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_i_d_npc_2d_btn_response_xml_008ac110(void)



{

  int iVar1;

  int iVar2;

  int unaff_EBP;

  int *piVar3;

  int iVar4;

  int *unaff_EDI;

  char cVar5;

  int local_28;

  int local_24;

  void *local_20;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b63f9;

  local_c = ExceptionList;

  if (unaff_EDI[0x130] != 0) {

    ExceptionList = &local_c;

    FUN_008aa560();

    if (unaff_EDI[400] < 1) {

      unaff_EDI[400] = 1;

    }

    iVar2 = 0;

    if (0 < unaff_EDI[0x144]) {

      piVar3 = unaff_EDI + 0x1c2;

      do {

        local_24 = iVar2 / unaff_EDI[400];

        iVar4 = iVar2 - unaff_EDI[400] * local_24;

        local_28 = iVar4;

        local_20 = operator_new(0x4cc);

        iVar1 = 0;

        local_4 = 0;

        if (local_20 != (void *)0x0) {

          iVar1 = FUN_0079c860();

          iVar4 = local_28;

        }

        local_4 = 0xffffffff;

        *piVar3 = iVar1;

        (**(code **)(*unaff_EDI + 0xa8))();

        cVar5 = (char)((uint)iVar1 >> 0x18);

        (**(code **)(*(int *)*piVar3 + 0x28))("i_d_npc_2d_btn_response.xml");

        (**(code **)(*(int *)*piVar3 + 0x74))(iVar2 + 0x9c46);

        local_28 = (int)((float)unaff_EDI[0x173] * (float)DAT_00d1e818 * DAT_00aaa67c);

        local_24 = (int)((float)unaff_EDI[0x174] * (float)DAT_00d1e81c * DAT_00aaa678);

        (**(code **)(*(int *)*piVar3 + 8))(&local_28);

        if (cVar5 == '\0') {

          iVar1 = unaff_EDI[0x171];

        }

        else {

          iVar1 = unaff_EDI[0x16d];

        }

        iVar1 = unaff_EDI[0x175] * iVar4 + iVar1;

        if (cVar5 == '\0') {

          iVar4 = unaff_EDI[0x172];

        }

        else {

          iVar4 = unaff_EDI[0x16e];

        }

        iVar4 = unaff_EDI[0x176] * unaff_EBP + iVar4;

        if ((unaff_EDI[0x192] == 0) || (unaff_EDI[0x192] == 3)) {

          iVar1 = iVar1 + unaff_EDI[0x16f];

          iVar4 = iVar4 + unaff_EDI[0x170];

        }

        local_24 = (int)((float)DAT_00d1e818 * (float)iVar1 * DAT_00aaa67c);

        local_20 = (void *)(int)((float)DAT_00d1e81c * (float)iVar4 * DAT_00aaa678);

        (**(code **)(*(int *)*piVar3 + 0x118))(&local_24);

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 1;

      } while (iVar2 < unaff_EDI[0x144]);

    }

  }

  ExceptionList = local_c;

  return;

}
