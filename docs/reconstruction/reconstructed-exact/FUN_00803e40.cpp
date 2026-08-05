// =============================================================================
// FUN_00803e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00803e40
// Address:   0x00803e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803e40 @ 0x00803e40
// Stable ID: aa_00803e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_008034c0, FUN_00803e40, GetObjectA.
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

int FUN_00803e40(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *unaff_ESI;

  int *piVar6;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  void *pvStack_30;

  int *apiStack_20 [5];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad0b9;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar2 = operator_new(0x170);

  piVar6 = (int *)0x0;

  local_4 = 0;

  if (pvVar2 != (void *)0x0) {

    piVar6 = (int *)FUN_008034c0();

  }

  local_4 = 0xffffffff;

  uStack_5c = 0x803e8e;

  (**(code **)(*piVar6 + 4))();

  uStack_5c = param_1;

  uStack_60 = 0x803e9d;

  (**(code **)(*piVar6 + 0x80))();

  uStack_60 = 0x803ea4;

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_ESI + 0x14))();

  iVar1 = *piVar6;

  uStack_60 = 0x803eaf;

  iVar4 = (**(code **)(*unaff_ESI + 0x14))();

  uStack_60 = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

  uStack_64 = *puVar3;

  uStack_68 = 0x803ebb;

  (**(code **)(iVar1 + 0xc))();

  uStack_68 = 0x803ec2;

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_ESI + 0x44))();

  iVar1 = *piVar6;

  uStack_68 = 0x803ecd;

  iVar4 = (**(code **)(*unaff_ESI + 0x44))();

  uStack_68 = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

  (**(code **)(iVar1 + 0x3c))(*puVar3);

  iVar1 = *piVar6;

  uVar5 = (**(code **)(*unaff_ESI + 0x28))();

  uVar5 = (**(code **)(*unaff_ESI + 0x24))(uVar5);

  (**(code **)(iVar1 + 0x18))(uVar5);

  (**(code **)(*piVar6 + 0x54))(2);

  GetObjectA((HANDLE)unaff_ESI[0x98],0x3c,&uStack_68);

  (**(code **)(*piVar6 + 0x6c))(&uStack_68);

  unaff_ESI[0x16] = 1;

  iVar1 = unaff_ESI[0xe];

  apiStack_20[0] = piVar6;

  iVar4 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),apiStack_20);

  FUN_00418790();

  *(int *)(iVar1 + 4) = iVar4;

  **(int **)(iVar4 + 4) = iVar4;

  if (unaff_ESI[0x17] == 0) {

    unaff_ESI[0x17] = (int)piVar6;

  }

  ExceptionList = pvStack_30;

  return unaff_ESI[0xf] + -1;

}
