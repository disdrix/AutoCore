// =============================================================================
// FUN_0090c9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c9a0
// Address:   0x0090c9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090c9a0 @ 0x0090c9a0
// Stable ID: aa_0090c9a0
// Embedded strings (evidence for future rename):
//   - "i_d_a_2d_btn_achievement.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_007b5dd0, FUN_0090c9a0.
//  - Strings: "i_d_a_2d_btn_achievement.xml".
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

void FUN_0090c9a0(void)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  float *pfVar5;

  int *piVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  int unaff_EBX;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar9;

  float fVar10;

  uint32_t /* width from decompiler */ *puStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  int iStack_164;

  char *pcStack_160;

  int iStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint8_t *puStack_154;

  uint8_t *puStack_150;

  char *pcStack_14c;

  int iStack_148;

  uint8_t local_13c [4];

  char acStack_138 [4];

  uint8_t auStack_134 [20];

  uint8_t auStack_120 [216];

  void *pvStack_48;

  char cStack_34;

  uint8_t *puStack_24;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3aab;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_13c = (uint8_t  [4])operator_new(0x488);

  local_4 = 0;

  if (local_13c == (uint8_t  [4])0x0) {

    iStack_148 = 0;

  }

  else {

    iStack_148 = 0x90c9e2;

    iStack_148 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  unaff_ESI[unaff_EBX + 0x150] = iStack_148;

  pcStack_14c = (char *)0x90ca05;

  (**(code **)(*unaff_ESI + 0xa8))();

  pcStack_14c = "i_d_a_2d_btn_achievement.xml";

  puStack_150 = (uint8_t *)0x90ca16;

  (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x28))();

  puStack_150 = auStack_120;

  puStack_154 = (uint8_t *)0x90ca38;

  iVar4 = (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x134))();

  puStack_154 = local_13c;

  fVar10 = (float)DAT_00d1e81c * (float)(((int)*(float *)(iVar4 + 4) + 0x1f) * (unaff_EBX / 3)) *

           DAT_00aaa678;

  uStack_158 = 0x90ca73;

  pfVar5 = (float *)(**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x134))();

  pcStack_14c = (char *)(int)((float)DAT_00d1e818 * (float)(((int)*pfVar5 + 0x28) * (unaff_EBX % 3))

                             * DAT_00aaa67c);

  uStack_158 = 0;

  iStack_15c = 1;

  pcStack_160 = acStack_138;

  iStack_164 = 0x90cab5;

  iVar4 = (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x120))();

  iVar4 = *(int *)(iVar4 + 4);

  iStack_164 = 0;

  uStack_168 = 1;

  puStack_16c = (uint32_t /* width from decompiler */ *)local_13c;

  piVar6 = (int *)(**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x120))();

  pcStack_160 = (char *)(*piVar6 + iStack_164);

  *(uint8_t *)(unaff_EBX + 0x510 + (int)unaff_ESI) = *puStack_24;

  pcVar7 = *(char **)(puStack_24 + 0x10);

  iVar2 = -(int)pcVar7;

  do {

    cVar1 = *pcVar7;

    pcVar7[(int)(acStack_138 + iVar2)] = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  puVar3 = (uint32_t /* width from decompiler */ *)(local_13c + 3);

  do {

    puVar9 = puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

  } while (*(char *)((int)puVar9 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a2c53c;

  *(uint8_t *)((int)puVar9 + 5) = DAT_00a2c540;

  iStack_15c = iVar4 + (int)fVar10;

  (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x50))(acStack_138,0,0);

  (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x118))(&puStack_16c);

  (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x34c))();

  (**(code **)(*(int *)unaff_ESI[unaff_EBX + 0x150] + 0x74))(unaff_EBX + 0x9c43);

  if (cStack_34 == '\0') {

    iVar4 = *(int *)unaff_ESI[unaff_EBX + 0x150];

    uVar8 = (**(code **)(iVar4 + 0x164))(2);

    (**(code **)(iVar4 + 0x154))(0,uVar8);

  }

  ExceptionList = pvStack_48;

  return;

}
