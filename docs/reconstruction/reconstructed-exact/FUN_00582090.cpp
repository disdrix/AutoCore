// =============================================================================
// FUN_00582090
// -----------------------------------------------------------------------------
// Stable ID: aa_00582090
// Address:   0x00582090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582090 @ 0x00582090
// Stable ID: aa_00582090
// Embedded strings (evidence for future rename):
//   - "%s.spt"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_005b7250×2, FUN_007a4480×2, FUN_004911f0, FUN_004922f0, FUN_00582090, FUN_00586950, FUN_005b56c0, FUN_005b5b90.
//  - Strings: "%s.spt".
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

uint32_t /* width from decompiler */ __thiscall FUN_00582090(int *param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t *puVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_12c [28];

  char local_110 [248];

  void *pvStack_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a541f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  sprintf(local_110,"%s.spt");

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_12c,local_110);

  local_4 = 0;

  iVar3 = FUN_004911f0();

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_12c);

  if (iVar3 == 0) {

    pvVar4 = operator_new(0x160);

    local_4 = 1;

    if (pvVar4 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_00586950();

    }

    local_4 = 0xffffffff;

    pcVar7 = local_110;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x128) = 0;

    iVar9 = iVar3 - (int)pcVar7;

    do {

      cVar2 = *pcVar7;

      pcVar7[iVar9] = cVar2;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    FUN_004922f0();

  }

  if (*(int *)(iVar3 + 0x128) == 0) {

    pvVar4 = operator_new(0x178);

    local_4 = 2;

    if (pvVar4 == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_005b56c0();

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x124) = uVar5;

    cVar2 = FUN_005b7250();

    if (cVar2 == '\0') {

      FUN_007a4480();

    }

  }

  iVar9 = FUN_005b5b90();

  param_1[8] = iVar9;

  *(int *)(iVar3 + 0x128) = *(int *)(iVar3 + 0x128) + 1;

  cVar2 = FUN_005b7250();

  if (cVar2 == '\0') {

    FUN_007a4480();

  }

  piVar1 = *(int **)(param_1[8] + 8);

  param_1[2] = (int)piVar1;

  (**(code **)(*piVar1 + 0x18))();

  (**(code **)(*(int *)param_1[2] + 0x14))();

  puVar6 = operator_new(0xc);

  *puVar6 = 1;

  *(int *)(puVar6 + 4) = *(int *)(param_1[1] + 4) + 4 + (int)param_1;

  *(uint8_t **)(*(int *)(param_1[8] + 8) + 0x78) = puVar6;

  (**(code **)(*(int *)param_1[2] + 0x4c))();

  FUN_0074b510();

  (**(code **)(*(int *)param_1[2] + 0x4c))();

  FUN_0074ba50();

  puVar8 = (uint32_t /* width from decompiler */ *)param_1[2];

  puVar10 = puVar8 + 0xd;

  for (iVar3 = 0xc; puVar8 = puVar8 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar10 = *puVar8;

    puVar10 = puVar10 + 1;

  }

  *(uint8_t *)((int)param_1 + 0xd) = param_3;

  (**(code **)(*param_1 + 0x18))();

  (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x48))();

  ExceptionList = pvStack_18;

  return 1;

}
