// =============================================================================
// FUN_0078c780
// -----------------------------------------------------------------------------
// Stable ID: aa_0078c780
// Address:   0x0078c780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078c780 @ 0x0078c780
// Stable ID: aa_0078c780
// Embedded strings (evidence for future rename):
//   - "Directional"
//   - "Direction"
//   - "Color"
//   - "Hemispheric"
//   - "ColorTop"
//   - "ColorBottom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0074e310×2, FUN_0096d830×2, FUN_0096e430×2, FUN_0075bf40, FUN_0076f5f0, FUN_0078c780, FUN_00968a50.
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

void __fastcall FUN_0078c780(int *param_1)



{

  char *pcVar1;

  int *piVar2;

  char cVar3;

  uint8_t uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  void *unaff_EDI;

  uint8_t auStack_14 [8];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b31ef;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x3b8))();

  puVar5 = operator_new(0x94);

  uStack_4 = 0;

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0096d830(puVar5);

    puVar5[0x23] = 0;

    *puVar5 = &PTR_FUN_00aa0394;

    puVar5[0x24] = 0;

  }

  uStack_4 = 0xffffffff;

  param_1[0xab] = (int)puVar5;

  pvVar6 = operator_new(0x198);

  uStack_4 = 1;

  if (pvVar6 == (void *)0x0) {

    iVar7 = 0;

  }

  else {

    iVar7 = FUN_00968a50();

  }

  uStack_4 = 0xffffffff;

  *(char *)(iVar7 + 0x191) = (char)param_1[0x13e];

  param_1[0xa9] = iVar7;

  *(int *)(iVar7 + 0x180) = param_1[0x123];

  FUN_0075bf40(param_1[0x129]);

  (**(code **)(*param_1 + 0x140))(auStack_14,1);

  (**(code **)(*(int *)param_1[0xa9] + 0x18))(&stack0xffffffdc);

  uVar4 = (**(code **)(*param_1 + 0xd0))();

  *(uint8_t *)(iVar7 + 400) = uVar4;

  FUN_0096e430("Directional");

  FUN_0074e310(*(uint32_t /* width from decompiler */ *)(param_1[0xab] + 0x8c));

  uVar4 = (**(code **)(*param_1 + 0xd0))();

  iVar7 = *(int *)(param_1[0xab] + 0x8c);

  piVar2 = (int *)(iVar7 + 0xdc);

  *piVar2 = *piVar2 + 1;

  piVar2 = param_1 + 0x124;

  *(uint8_t *)(iVar7 + 0xd0) = uVar4;

  FUN_0076f5f0(piVar2,piVar2);

  iVar7 = param_1[0xab];

  uVar8 = (**(code **)(**(int **)(iVar7 + 0x8c) + 0x40))("Direction");

  (**(code **)(**(int **)(iVar7 + 0x8c) + 0x50))(uVar8,piVar2);

  iVar7 = param_1[0xab];

  uVar8 = (**(code **)(**(int **)(iVar7 + 0x8c) + 0x40))("Color");

  (**(code **)(**(int **)(iVar7 + 0x8c) + 0x4c))(uVar8,param_1 + 0x12a);

  if (*(char *)((int)param_1 + 0x4a1) != '\0') {

    puVar5 = operator_new(0x94);

    if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      FUN_0096d830(puVar5);

      puVar5[0x23] = 0;

      *puVar5 = &PTR_FUN_00aa0394;

      puVar5[0x24] = 0;

    }

    param_1[0x127] = (int)puVar5;

    FUN_0096e430("Hemispheric");

    iVar7 = param_1[0x127];

    uVar8 = (**(code **)(**(int **)(iVar7 + 0x8c) + 0x40))("ColorTop");

    (**(code **)(**(int **)(iVar7 + 0x8c) + 0x4c))(uVar8,param_1 + 0x136);

    iVar7 = param_1[0x127];

    uVar8 = (**(code **)(**(int **)(iVar7 + 0x8c) + 0x40))("ColorBottom");

    (**(code **)(**(int **)(iVar7 + 0x8c) + 0x4c))(uVar8,param_1 + 0x13a);

    FUN_0074e310(*(uint32_t /* width from decompiler */ *)(param_1[0x127] + 0x8c));

    iVar7 = *(int *)(param_1[0x127] + 0x8c);

    piVar2 = (int *)(iVar7 + 0xdc);

    *piVar2 = *piVar2 + 1;

    *(uint8_t *)(iVar7 + 0xd0) = 1;

  }

  *(int *)(param_1[0xa9] + 4) = param_1[0xaa];

  iVar7 = (**(code **)(*param_1 + 0x28c))();

  if (iVar7 != 0) {

    pcVar9 = (char *)(**(code **)(*param_1 + 0x28c))();

    pcVar1 = pcVar9 + 1;

    do {

      cVar3 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar3 != '\0');

    if (pcVar9 != pcVar1) {

      iVar7 = *param_1;

      uVar8 = (**(code **)(iVar7 + 0x28c))();

      (**(code **)(iVar7 + 0x3c))(uVar8);

    }

  }

  ExceptionList = unaff_EDI;

  return;

}
