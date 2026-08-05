// =============================================================================
// FUN_0082a590
// -----------------------------------------------------------------------------
// Stable ID: aa_0082a590
// Address:   0x0082a590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082a590 @ 0x0082a590
// Stable ID: aa_0082a590
// Embedded strings (evidence for future rename):
//   - "i_d_q_2d_btn_mission_btn.xml"
//   - "i_d_q_2d_btn_mission_active.xml"
//   - "i_d_q_2d_btn_mission_expand.xml"
//   - "i_d_q_2d_btn_mission_title.xml"
//   - "i_d_q_2d_btn_mission_status.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_0079c860×2, FUN_007b5dd0×2, FUN_00792600, FUN_00829fa0, FUN_0082a590.
//  - Strings: "i_d_q_2d_btn_mission_btn.xml"; "i_d_q_2d_btn_mission_active.xml"; "i_d_q_2d_btn_mission_expand.xml"; "i_d_q_2d_btn_mission_title.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_0082a590(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  int iVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b4364;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 == '\0') {

    FUN_00792600();

    pvVar2 = operator_new(0x4cc);

    uStack_4 = 0;

    if (pvVar2 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_0079c860();

    }

    uStack_4 = 0xffffffff;

    (**(code **)(*param_1 + 0xa8))(piVar3);

    (**(code **)(*piVar3 + 0x74))(60000);

    (**(code **)(*piVar3 + 0x28))("i_d_q_2d_btn_mission_btn.xml");

    (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

    iVar4 = param_1[0x1a] + 1;

    param_1[0x149] = (int)piVar3;

    param_1[0x1a] = iVar4;

    param_1[0x1d] = (int)(float)-iVar4;

    if (param_1[0x1c] < iVar4) {

      param_1[0x1c] = iVar4;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

    if (*(char *)((int)param_1 + 0x4fd) != '\0') {

      pvVar2 = operator_new(0x4cc);

      if (pvVar2 == (void *)0x0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = (int *)FUN_0079c860();

      }

      (**(code **)(*param_1 + 0xa8))(piVar3);

      (**(code **)(*piVar3 + 0x74))(0xea62);

      if ((char)param_1[0x13f] == '\0') {

        (**(code **)(*piVar3 + 0x28))("i_d_q_2d_btn_mission_active.xml");

      }

      else {

        (**(code **)(*piVar3 + 0x28))("i_d_q_2d_btn_mission_expand.xml");

      }

      (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

      iVar4 = param_1[0x1a] + 1;

      param_1[0x14a] = (int)piVar3;

      param_1[0x1a] = iVar4;

      param_1[0x1d] = (int)(float)-iVar4;

      if (param_1[0x1c] < iVar4) {

        param_1[0x1c] = iVar4;

      }

      (**(code **)(*param_1 + 0x3f4))(1);

    }

    pvVar2 = operator_new(0x488);

    if (pvVar2 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_007b5dd0(pvVar2,0);

    }

    (**(code **)(*param_1 + 0xa8))(piVar3);

    (**(code **)(*piVar3 + 0x28))("i_d_q_2d_btn_mission_title.xml");

    (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

    param_1[0x14b] = (int)piVar3;

    if ((char)param_1[0x13f] == '\0') {

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = (int *)FUN_007b5dd0(pvVar2,0);

      }

      (**(code **)(*param_1 + 0xa8))(piVar3);

      (**(code **)(*piVar3 + 0x28))("i_d_q_2d_btn_mission_status.xml");

      (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

      param_1[0x14c] = (int)piVar3;

    }

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar4 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar4;

    if (param_1[0x1c] < iVar4) {

      param_1[0x1c] = iVar4;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar4 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar4;

    if (param_1[0x1c] < iVar4) {

      param_1[0x1c] = iVar4;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar4 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar4;

    if (param_1[0x1c] < iVar4) {

      param_1[0x1c] = iVar4;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

    FUN_00829fa0();

    (**(code **)(*param_1 + 0x34c))();

  }

  ExceptionList = pvStack_c;

  return;

}
