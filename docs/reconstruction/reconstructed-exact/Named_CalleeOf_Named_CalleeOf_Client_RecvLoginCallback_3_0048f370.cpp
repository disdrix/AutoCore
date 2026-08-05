// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f370
// Callee of Named_CalleeOf_Client_RecvLoginCallback_3 (+1 other named callers)
// Address:   0x0048f370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvLoginCallback_3: auth/session helper. Evidence string: "Direction". Supports parent flow (not a free-standing entry point). Named_CalleeOf_Client_RecvLoginCallback_3 (+1 other named callers).
// Embedded strings (evidence):
//   - "Direction"
//   - "Color"
//   - "Hemispheric"
//   - "ColorTop"
//   - "ColorBottom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_009733d0×3, FUN_0074e310×2, FUN_0096e430×2, FUN_0096e4b0×2, FUN_0048eb10, FUN_0048f370, FUN_005b3520, FUN_0074e0d0.
//  - Strings: "Direction"; "Color"; "Hemispheric"; "ColorTop".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvLoginCallback_3 (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370(int param_1)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  void *unaff_ESI;

  void *pvStack_4c;

  uint32_t /* width from decompiler */ *puStack_48;

  char *pcVar5;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0822;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0048eb10();

  puStack_48 = (uint32_t /* width from decompiler */ *)0x48f39c;

  pvVar3 = operator_new(0x94);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_0096e4b0();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = uVar4;

  puStack_48 = (uint32_t /* width from decompiler */ *)0x48f3d4;

  FUN_0096e430();

  puStack_48 = (uint32_t /* width from decompiler */ *)0x48f3e9;

  FUN_0074e310();

  puStack_48 = (uint32_t /* width from decompiler */ *)0x48f3fe;

  FUN_0074e0d0();

  DAT_00b03530 = DAT_00aaa6d4;

  DAT_00b03534 = DAT_00aaa6cc;

  puStack_48 = &DAT_00b03530;

  DAT_00b03538 = g_flOne;

  pvStack_4c = (void *)0x48f43d;

  FUN_0076f5f0();

  iVar2 = *(int *)(param_1 + 0x108);

  pcVar5 = "Direction";

  puStack_48 = (uint32_t /* width from decompiler */ *)0x48f456;

  pvStack_4c = (void *)(**(code **)(**(int **)(iVar2 + 0x8c) + 0x40))();

  puStack_48 = &DAT_00b03530;

  (**(code **)(**(int **)(iVar2 + 0x8c) + 0x50))();

  FUN_009733d0(&stack0xffffffc0);

  DAT_00aef974 = uStack_34;

  DAT_00aef97c = uStack_2c;

  iVar2 = *(int *)(param_1 + 0x108);

  DAT_00aef970 = unaff_EBX;

  DAT_00aef978 = pvVar3;

  uVar4 = (**(code **)(**(int **)(iVar2 + 0x8c) + 0x40))("Color");

  (**(code **)(**(int **)(iVar2 + 0x8c) + 0x4c))(uVar4,&DAT_00aef970);

  iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0x8c);

  piVar1 = (int *)(iVar2 + 0xdc);

  *piVar1 = *piVar1 + 1;

  *(uint8_t *)(iVar2 + 0xd0) = 1;

  pvStack_4c = (void *)0xff707b8f;

  FUN_009733d0(&pvStack_4c);

  DAT_00aef980 = pcVar5;

  puStack_48 = (uint32_t /* width from decompiler */ *)0xff3e2f2d;

  DAT_00aef984 = 0xffd1a56d;

  DAT_00aef988 = unaff_ESI;

  DAT_00aef98c = unaff_EBX;

  FUN_009733d0(&puStack_48);

  DAT_00aef990 = uStack_34;

  DAT_00aef998 = uStack_2c;

  DAT_00aef99c = uStack_28;

  DAT_00aef994 = pvVar3;

  pvStack_4c = operator_new(0x94);

  if (pvStack_4c == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_0096e4b0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = uVar4;

  FUN_0096e430("Hemispheric");

  iVar2 = *(int *)(param_1 + 0x104);

  uVar4 = (**(code **)(**(int **)(iVar2 + 0x8c) + 0x40))("ColorTop");

  (**(code **)(**(int **)(iVar2 + 0x8c) + 0x4c))(uVar4,&DAT_00aef980);

  iVar2 = *(int *)(param_1 + 0x104);

  uVar4 = (**(code **)(**(int **)(iVar2 + 0x8c) + 0x40))("ColorBottom");

  (**(code **)(**(int **)(iVar2 + 0x8c) + 0x4c))(uVar4,&DAT_00aef990);

  FUN_0074e310(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x104) + 0x8c));

  iVar2 = *(int *)(*(int *)(param_1 + 0x104) + 0x8c);

  piVar1 = (int *)(iVar2 + 0xdc);

  *piVar1 = *piVar1 + 1;

  *(uint8_t *)(iVar2 + 0xd0) = 1;

  if (*(int *)(param_1 + 0xc4) != 0) {

    FUN_005b3520();

  }

  ExceptionList = unaff_ESI;

  return;

}
