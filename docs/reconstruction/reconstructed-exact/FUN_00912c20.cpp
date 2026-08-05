// =============================================================================
// FUN_00912c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00912c20
// Address:   0x00912c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00912c20 @ 0x00912c20
// Stable ID: aa_00912c20
// Embedded strings (evidence for future rename):
//   - "Directional"
//   - "Direction"
//   - "Color"
//   - "Hemispheric"
//   - "ColorTop"
//   - "ColorBottom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0074e310×2, FUN_0096d830×2, FUN_0096e430×2, FUN_0076f5f0, FUN_00912a50, FUN_00912c20.
//  - Strings: "Directional"; "Direction"; "Color"; "Hemispheric".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00912c20(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *local_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  void *pvStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af0dd;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00912a50();

  puVar4 = operator_new(0x94);

  local_4 = 0;

  local_5c = puVar4;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0096d830(puVar4);

    puVar4[0x23] = 0;

    *puVar4 = &PTR_FUN_00aa0394;

    puVar4[0x24] = 0;

  }

  local_4 = 0xffffffff;

  param_1[0x2be] = (int)puVar4;

  FUN_0096e430("Directional");

  uVar6 = *(uint32_t /* width from decompiler */ *)(param_1[0x2be] + 0x8c);

  (**(code **)(*param_1 + 0x1a8))();

  FUN_0074e310(uVar6);

  piVar2 = *(int **)(param_1[0x2be] + 0x8c);

  iVar5 = (**(code **)(*param_1 + 0x1a8))();

  iVar5 = *(int *)(iVar5 + 4);

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar3 = *(int **)(iVar5 + 0x3c);

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  fStack_58 = DAT_00aaa6d4;

  *(int **)(iVar5 + 0x3c) = piVar2;

  fStack_54 = (float)DAT_00aaa6cc;

  fStack_50 = g_flOne;

  FUN_0076f5f0(&fStack_58,&fStack_58);

  iVar5 = param_1[0x2be];

  uVar6 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Direction");

  (**(code **)(**(int **)(iVar5 + 0x8c) + 0x50))(uVar6,&local_5c);

  iVar5 = param_1[0x2be];

  fStack_58 = DAT_00b017e8 * _DAT_00aaaa74;

  fStack_54 = DAT_00b017e8 * _DAT_00aaaa70;

  fStack_50 = DAT_00b017e8 * _DAT_00aaaa6c;

  fStack_4c = DAT_00b017e8 * DAT_00aaa6f8;

  fStack_48 = fStack_58;

  fStack_44 = fStack_54;

  fStack_40 = fStack_50;

  pvStack_3c = (void *)fStack_4c;

  uVar6 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("Color");

  (**(code **)(**(int **)(iVar5 + 0x8c) + 0x4c))(uVar6,&fStack_4c);

  fStack_2c = DAT_00b017e8;

  iVar5 = *(int *)(param_1[0x2be] + 0x8c);

  piVar2 = (int *)(iVar5 + 0xdc);

  *piVar2 = *piVar2 + 1;

  *(uint8_t *)(iVar5 + 0xd0) = 1;

  fStack_44 = fStack_2c * _DAT_00aaaa68;

  fStack_40 = fStack_2c * _DAT_00aaaa64;

  pvStack_3c = (void *)(fStack_2c * _DAT_00aaaa60);

  fStack_34 = fStack_2c * _DAT_00aaaa5c;

  fStack_38 = fStack_2c * DAT_00aaa6f8;

  fStack_30 = fStack_2c * _DAT_00aaaa58;

  fStack_2c = fStack_2c * _DAT_00aaa7c0;

  fStack_28 = fStack_38;

  puVar4 = operator_new(0x94);

  uStack_1c = 3;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0096d830(puVar4);

    puVar4[0x23] = 0;

    *puVar4 = &PTR_FUN_00aa0394;

    puVar4[0x24] = 0;

  }

  uStack_1c = 0xffffffff;

  param_1[0x2bf] = (int)puVar4;

  FUN_0096e430("Hemispheric");

  iVar5 = param_1[0x2bf];

  uVar6 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("ColorTop");

  (**(code **)(**(int **)(iVar5 + 0x8c) + 0x4c))(uVar6,&fStack_48);

  iVar5 = param_1[0x2bf];

  uVar6 = (**(code **)(**(int **)(iVar5 + 0x8c) + 0x40))("ColorBottom");

  (**(code **)(**(int **)(iVar5 + 0x8c) + 0x4c))(uVar6,&fStack_44);

  uVar6 = *(uint32_t /* width from decompiler */ *)(param_1[0x2bf] + 0x8c);

  (**(code **)(*param_1 + 0x1a8))();

  FUN_0074e310(uVar6);

  iVar5 = *(int *)(param_1[0x2bf] + 0x8c);

  piVar2 = (int *)(iVar5 + 0xdc);

  *piVar2 = *piVar2 + 1;

  *(uint8_t *)(iVar5 + 0xd0) = 1;

  ExceptionList = pvStack_3c;

  return;

}
