// =============================================================================
// Named_i_w_tut_2d_wnd_message_simple
// -----------------------------------------------------------------------------
// Stable ID: aa_0097a6f0
// Address:   0x0097a6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_w_tut_2d_wnd_message_simple @ 0x0097a6f0
// Stable ID: aa_0097a6f0
// Embedded strings (evidence for future rename):
//   - "i_w_tut_2d_wnd_message.xml"
//   - "i_w_tut_2d_wnd_message_simple.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×4, goto×1, return×1.
//  - Notable callees: FUN_00755ab0, FUN_00792600, FUN_007b5dd0, FUN_00979d80, Named_i_w_tut_2d_wnd_message_simple.
//  - Strings: "i_w_tut_2d_wnd_message.xml"; "i_w_tut_2d_wnd_message_simple.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_w_tut_2d_wnd_message_simple.xml"
 * Domain alias of FUN_0097a6f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_i_w_tut_2d_wnd_message_simple(int *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  int iStack_34;

  void *pvStack_30;

  char *pcStack_2c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b33e5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pcStack_2c = (char *)0x97a71b;

  pcStack_2c = operator_new(0x488);

  local_4 = 0;

  if (pcStack_2c == (char *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvStack_30 = (void *)0x97a736;

    pvVar1 = (void *)FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x140] = (int)pvVar1;

  pcStack_2c = (char *)0x97a753;

  (**(code **)(*param_1 + 0xa8))();

  if ((char)param_1[0x150] == '\0') {

    pcStack_2c = "i_w_tut_2d_wnd_message.xml";

    pvStack_30 = (void *)0x97a778;

    (**(code **)(*(int *)param_1[0x140] + 0x28))();

  }

  else {

    pcStack_2c = "i_w_tut_2d_wnd_message_simple.xml";

    pvStack_30 = (void *)0x97a76c;

    (**(code **)(*(int *)param_1[0x140] + 0x28))();

  }

  pvStack_30 = (void *)0x9c41;

  iStack_34 = 0x97a788;

  (**(code **)(*(int *)param_1[0x140] + 0x74))();

  iVar3 = *(int *)param_1[0x140];

  iStack_34 = 1;

  uVar2 = (**(code **)(*param_1 + 0x1dc))(1);

  (**(code **)(iVar3 + 0x1d8))(uVar2);

  iVar3 = (**(code **)(*(int *)param_1[0x140] + 0x1dc))();

  if (iVar3 != 0) {

    iVar3 = (**(code **)(*(int *)param_1[0x140] + 0x1b8))();

    if ((iVar3 != 0) && ((char)param_1[0x150] != '\0')) {

      (**(code **)(*(int *)param_1[0x140] + 0x1b8))();

      (**(code **)(*(int *)param_1[0x140] + 0x1dc))();

      FUN_00755ab0(&iStack_34);

      pcStack_2c = (char *)(iStack_34 + 8);

      pvVar1 = pvStack_30;

      (**(code **)(*(int *)param_1[0x140] + 300))(&pcStack_2c);

      goto LAB_0097a86e;

    }

  }

  piVar4 = (int *)(**(code **)(*(int *)param_1[0x140] + 0x140))(&iStack_34,1);

  iStack_34 = *piVar4;

  pvStack_30 = (void *)0x0;

  (**(code **)(*(int *)param_1[0x140] + 300))(&iStack_34);

  (**(code **)(*(int *)param_1[0x140] + 0x13c))();

LAB_0097a86e:

  FUN_00979d80();

  param_1[0x14b] = 0;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
