// =============================================================================
// FUN_008f8c60
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8c60
// Address:   0x008f8c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f8c60 @ 0x008f8c60
// Stable ID: aa_008f8c60
// Embedded strings (evidence for future rename):
//   - "i_d_chatlog_2d_sb.xml"
//   - "i_d_chatlog_2d_wnd_chat.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0078f890, FUN_00792600, FUN_008678c0, FUN_008f8c60.
//  - Strings: "i_d_chatlog_2d_sb.xml"; "i_d_chatlog_2d_wnd_chat.xml".
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

void __fastcall FUN_008f8c60(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uStack_38;

  void *pvStack_34;

  char *pcStack_30;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ba913;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pcStack_30 = (char *)0x8f8c8c;

  pvVar1 = operator_new(0x954);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0078f890();

  }

  local_4 = 0xffffffff;

  pcStack_30 = (char *)0x8f8cbe;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_30 = "i_d_chatlog_2d_sb.xml";

  pvStack_34 = (void *)0x8f8cca;

  (**(code **)(*piVar2 + 0x28))();

  pvStack_34 = (void *)0x9c41;

  uStack_38 = 0x8f8cd6;

  (**(code **)(*piVar2 + 0x74))();

  uStack_38 = 0x8f8ce0;

  (**(code **)(*piVar2 + 0x43c))();

  uStack_38 = 0;

  (**(code **)(*piVar2 + 0xcc))();

  param_1[0x3a0] = (int)piVar2;

  (**(code **)(*piVar2 + 0xd4))(0);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvStack_34 = operator_new(0x53c);

  if (pvStack_34 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_008678c0(pvStack_34);

  }

  (**(code **)(*piVar2 + 0x28))("i_d_chatlog_2d_wnd_chat.xml");

  piVar4 = (int *)(**(code **)(*piVar2 + 0x140))(&uStack_38,1);

  piVar5 = (int *)(**(code **)(*piVar2 + 0x120))(&uStack_38,1,0);

  iVar3 = *piVar5;

  param_1[0x438] = iVar3;

  param_1[0x43a] = *piVar4 + iVar3;

  iVar3 = piVar5[1];

  param_1[0x439] = iVar3;

  param_1[0x43b] = piVar4[1] + iVar3;

  (**(code **)*piVar2)(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
