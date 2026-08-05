// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0089a260
// -----------------------------------------------------------------------------
// Stable ID: aa_0089a260
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem
// Address:   0x0089a260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper. Evidence string: "[0] %s, %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "[0] %s, %s"
//   - "[0] %s"
//   - "[%i] %s, %s"
//   - "[%i] %s"
//   - "Salvaged"
//   - "Patched"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~884 non-empty decompiler lines.
//  - Control keywords: if×93, goto×48, while×38, do×37, for×20, return×12, switch×1.
//  - Notable callees: FUN_007a6de0×7, sprintf×7, FUN_007a69d0×5, FUN_00402d50×3, free×3, strtok×3, FUN_005190c0×2, FUN_0052d450.
//  - Strings: "[0] %s, %s"; "[0] %s"; "[%i] %s, %s"; "[%i] %s".
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_0089a260(int param_1,int param_2,char *param_3)



{

  char cVar1;

  byte bVar2;

  bool bVar3;

  void **ppvVar4;

  void *this;

  int *extraout_EAX;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  byte *pbVar7;

  byte *pbVar8;

  int iVar9;

  uint uVar10;

  uint uVar11;

  int *piVar12;

  char *pcVar13;

  byte *pbVar14;

  char *pcVar15;

  int *unaff_EDI;

  char *pcVar16;

  bool bVar17;

  uint8_t *pMap;

  uint32_t /* width from decompiler */ local_8b0;

  byte *local_8ac;

  int local_8a8;

  uint8_t local_8a4 [4];

  char local_8a0 [2];

  uint32_t /* width from decompiler */ local_89e [31];

  char local_821;

  char local_820 [2];

  uint32_t /* width from decompiler */ local_81e [32];

  uint8_t *local_79c;

  uint8_t local_798 [128];

  byte local_718 [2];

  uint32_t /* width from decompiler */ local_716 [31];

  char cStack_699;

  byte local_698 [2];

  uint32_t /* width from decompiler */ auStack_696 [2];

  char local_68c [115];

  char cStack_619;

  byte local_618 [2];

  uint32_t /* width from decompiler */ auStack_616 [2];

  char local_60c [115];

  char cStack_599;

  byte local_598 [2];

  uint32_t /* width from decompiler */ auStack_596 [2];

  char local_58c [115];

  char cStack_519;

  byte local_518 [2];

  uint32_t /* width from decompiler */ auStack_516 [31];

  char cStack_499;

  byte local_498 [2];

  uint32_t /* width from decompiler */ auStack_496 [31];

  char cStack_419;

  byte local_418 [2];

  uint32_t /* width from decompiler */ auStack_416 [31];

  char cStack_399;

  byte local_398 [2];

  uint32_t /* width from decompiler */ auStack_396 [31];

  char local_318 [2];

  uint32_t /* width from decompiler */ local_316 [31];

  char cStack_299;

  byte local_298 [2];

  uint32_t /* width from decompiler */ auStack_296 [31];

  char cStack_219;

  byte local_218 [2];

  uint32_t /* width from decompiler */ auStack_216 [2];

  char local_20c [115];

  char cStack_199;

  byte local_198 [2];

  uint32_t /* width from decompiler */ uStack_196;

  char local_190 [119];

  char cStack_119;

  byte local_118 [2];

  uint32_t /* width from decompiler */ auStack_116 [31];

  char cStack_99;

  byte local_98 [2];

  uint32_t /* width from decompiler */ auStack_96 [2];

  char local_8c [120];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009ac5a9;

  local_14 = ExceptionList;

  if (param_2 == 0) {

    return;

  }

  local_8a8 = *(int *)(param_2 + 0x3c);

  if (local_8a8 == 0) {

    return;

  }

  ppvVar4 = &local_14;

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x52c)) {

  case 1:

    ppvVar4 = &local_14;

    if ((int)param_3 < 1) {

      return;

    }

    break;

  case 2:

    ppvVar4 = &local_14;

    if (*(char *)(local_8a8 + 0x4c8) != '\0') {

      return;

    }

    break;

  case 3:

    ppvVar4 = &local_14;

    if (*(char *)(local_8a8 + 0x4c8) != '\x01') {

      return;

    }

    break;

  case 4:

    ppvVar4 = &local_14;

    if (*(char *)(local_8a8 + 0x4c8) != '\x02') {

      return;

    }

    break;

  case 6:

    ppvVar4 = &local_14;

    if (*(char *)(local_8a8 + 0x4c8) != '\x03') {

      return;

    }

    break;

  case 7:

    if (*(int *)(param_1 + 0x530) == 0) {

      return;

    }

    ExceptionList = &local_14;

    FUN_0052d450(*(int *)(param_1 + 0x530),&local_8ac);

    local_8b0 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x34);

    iVar9 = FUN_005190c0();

    iVar9 = *(int *)(iVar9 + 4);

    puVar5 = &local_8b0;

    pMap = local_8a4;

    this = (void *)FUN_005190c0();

    Map_LowerBoundFindByIntKey(this,pMap,puVar5,unaff_EDI);

    ppvVar4 = ExceptionList;

    if (*extraout_EAX == iVar9) {

      ExceptionList = local_14;

      return;

    }

  }

  ExceptionList = ppvVar4;

  if ((*(int *)(param_1 + 0x52c) == 1) && ((int)param_3 < 1)) {

    ExceptionList = local_14;

    return;

  }

  local_820[0] = '\0';

  local_820[1] = '\0';

  puVar5 = local_81e;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_318[0] = '\0';

  local_318[1] = '\0';

  puVar5 = local_316;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_8a0[0] = '\0';

  local_8a0[1] = '\0';

  puVar5 = local_89e;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_718[0] = 0;

  local_718[1] = 0;

  puVar5 = local_716;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_518[0] = 0;

  local_518[1] = 0;

  puVar5 = auStack_516;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_698[0] = 0;

  local_698[1] = 0;

  puVar5 = auStack_696;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_98[0] = 0;

  local_98[1] = 0;

  puVar5 = auStack_96;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_218[0] = 0;

  local_218[1] = 0;

  puVar5 = auStack_216;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_418[0] = 0;

  local_418[1] = 0;

  puVar5 = auStack_416;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_118[0] = 0;

  local_118[1] = 0;

  puVar5 = auStack_116;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_498[0] = 0;

  local_498[1] = 0;

  puVar5 = auStack_496;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_598[0] = 0;

  local_598[1] = 0;

  puVar5 = auStack_596;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_618[0] = 0;

  local_618[1] = 0;

  puVar5 = auStack_616;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_198[0] = 0;

  local_198[1] = 0;

  puVar5 = &uStack_196;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_298[0] = 0;

  local_298[1] = 0;

  puVar5 = auStack_296;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  local_398[0] = 0;

  local_398[1] = 0;

  puVar5 = auStack_396;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  bVar3 = true;

  bVar17 = false;

  local_8b0 = FUN_007a69d0();

  iVar9 = *(int *)(param_2 + 0x3c);

  local_821 = '\0';

  if ((iVar9 != 0) && (iVar9 != -0x92)) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(iVar9 + 0x92);

    local_c = 0;

    pcVar6 = (char *)FUN_007a6de0(*puVar5,0xffffffff);

    pcVar13 = local_318;

    do {

      cVar1 = *pcVar6;

      *pcVar13 = cVar1;

      pcVar6 = pcVar6 + 1;

      pcVar13 = pcVar13 + 1;

    } while (cVar1 != '\0');

    local_c = 0xffffffff;

    if (local_79c != local_798) {

      free(local_79c);

    }

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_2 + 0x3c) + 0x92);

    local_c = 1;

    pbVar7 = (byte *)FUN_007a6de0(*puVar5,0xffffffff);

    pbVar14 = local_718;

    do {

      bVar2 = *pbVar7;

      *pbVar14 = bVar2;

      pbVar7 = pbVar7 + 1;

      pbVar14 = pbVar14 + 1;

    } while (bVar2 != 0);

    local_c = 0xffffffff;

    if (local_79c != local_798) {

      free(local_79c);

    }

  }

  iVar9 = FUN_007a69d0();

  if (*(int *)(iVar9 + 0x2c) == 1) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_2 + 0x3c) + 0x92);

    local_c = 2;

    pcVar6 = (char *)FUN_007a6de0(*puVar5,0xffffffff);

    pcVar13 = pcVar6;

    do {

      cVar1 = *pcVar13;

      pcVar13 = pcVar13 + 1;

    } while (cVar1 != '\0');

    pcVar16 = &local_821;

    do {

      pcVar15 = pcVar16 + 1;

      pcVar16 = pcVar16 + 1;

    } while (*pcVar15 != '\0');

    pcVar15 = pcVar6;

    for (uVar10 = (uint)((int)pcVar13 - (int)pcVar6) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar16 = *(uint32_t /* width from decompiler */ *)pcVar15;

      pcVar15 = pcVar15 + 4;

      pcVar16 = pcVar16 + 4;

    }

    for (uVar10 = (int)pcVar13 - (int)pcVar6 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

      *pcVar16 = *pcVar15;

      pcVar15 = pcVar15 + 1;

      pcVar16 = pcVar16 + 1;

    }

    local_c = 0xffffffff;

    if (local_79c != local_798) {

      free(local_79c);

    }

    bVar3 = false;

    bVar17 = true;

  }

  local_8ac = (byte *)strtok(local_318," ");

  if (local_8ac == (byte *)0x0) goto LAB_0089afad;

  if (bVar17) {

    if ((int)param_3 < 1) {

      if (bVar3) {

        sprintf(local_8a0,"[0] %s, %s",local_820,local_8ac);

      }

      else {

        sprintf(local_8a0,"[0] %s",local_718);

      }

    }

    else if (bVar3) {

      sprintf(local_8a0,"[%i] %s, %s",param_3,local_820,local_8ac);

    }

    else {

      sprintf(local_8a0,"[%i] %s",param_3,local_718);

    }

    goto LAB_0089afad;

  }

  iVar9 = FUN_007a69d0();

  if ((*(int *)(iVar9 + 0x2c) == 0) || (iVar9 = FUN_007a69d0(), *(int *)(iVar9 + 0x2c) == 3)) {

    pbVar8 = (byte *)FUN_007a6de0("Salvaged",0xffffffff);

    pbVar14 = local_8ac;

    pbVar7 = local_8ac;

    do {

      bVar2 = *pbVar7;

      bVar17 = bVar2 < *pbVar8;

      if (bVar2 != *pbVar8) {

LAB_0089a78c:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089a791;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar7[1];

      bVar17 = bVar2 < pbVar8[1];

      if (bVar2 != pbVar8[1]) goto LAB_0089a78c;

      pbVar7 = pbVar7 + 2;

      pbVar8 = pbVar8 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089a791:

    if (iVar9 != 0) {

      pbVar8 = (byte *)FUN_007a6de0("Patched",0xffffffff);

      pbVar7 = pbVar14;

      do {

        bVar2 = *pbVar7;

        bVar17 = bVar2 < *pbVar8;

        if (bVar2 != *pbVar8) {

LAB_0089a7d4:

          iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

          goto LAB_0089a7d9;

        }

        if (bVar2 == 0) break;

        bVar2 = pbVar7[1];

        bVar17 = bVar2 < pbVar8[1];

        if (bVar2 != pbVar8[1]) goto LAB_0089a7d4;

        pbVar7 = pbVar7 + 2;

        pbVar8 = pbVar8 + 2;

      } while (bVar2 != 0);

      iVar9 = 0;

LAB_0089a7d9:

      if (iVar9 != 0) {

        pbVar8 = (byte *)FUN_007a6de0("Functional",0xffffffff);

        pbVar7 = pbVar14;

        do {

          bVar2 = *pbVar7;

          bVar17 = bVar2 < *pbVar8;

          if (bVar2 != *pbVar8) {

LAB_0089a817:

            iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

            goto LAB_0089a81c;

          }

          if (bVar2 == 0) break;

          bVar2 = pbVar7[1];

          bVar17 = bVar2 < pbVar8[1];

          if (bVar2 != pbVar8[1]) goto LAB_0089a817;

          pbVar7 = pbVar7 + 2;

          pbVar8 = pbVar8 + 2;

        } while (bVar2 != 0);

        iVar9 = 0;

LAB_0089a81c:

        if (iVar9 != 0) {

          pbVar7 = (byte *)FUN_007a6de0("Perfect",0xffffffff);

          do {

            bVar2 = *pbVar14;

            bVar17 = bVar2 < *pbVar7;

            if (bVar2 != *pbVar7) {

LAB_0089a856:

              iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

              goto LAB_0089a85b;

            }

            if (bVar2 == 0) break;

            bVar2 = pbVar14[1];

            bVar17 = bVar2 < pbVar7[1];

            if (bVar2 != pbVar7[1]) goto LAB_0089a856;

            pbVar14 = pbVar14 + 2;

            pbVar7 = pbVar7 + 2;

          } while (bVar2 != 0);

          iVar9 = 0;

LAB_0089a85b:

          if (iVar9 != 0) {

            bVar3 = false;

          }

        }

      }

    }

  }

  pbVar14 = local_8ac;

  iVar9 = FUN_007a69d0();

  if (*(int *)(iVar9 + 0x2c) == 2) {

    pcVar13 = &cStack_699;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Verwertbares_00a4e410._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Verwertbares_00a4e410._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Verwertbares_00a4e410._8_4_;

    pcVar6[0xd] = s_Verwertbares_00a4e410[0xc];

    pcVar13 = &cStack_519;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Verwertbare_00a4e404._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Verwertbare_00a4e404._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Verwertbare_00a4e404._8_4_;

    pcVar13 = &cStack_99;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Verwertbarer_00a4e3f4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Verwertbarer_00a4e3f4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Verwertbarer_00a4e3f4._8_4_;

    pcVar6[0xd] = s_Verwertbarer_00a4e3f4[0xc];

    pcVar13 = &cStack_419;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Aufbereitetes_00a4e3e4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Aufbereitetes_00a4e3e4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Aufbereitetes_00a4e3e4._8_4_;

    *(uint16_t *)(pcVar6 + 0xd) = s_Aufbereitetes_00a4e3e4._12_2_;

    pcVar13 = &cStack_219;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Aufbereitete_00a4e3d4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Aufbereitete_00a4e3d4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Aufbereitete_00a4e3d4._8_4_;

    pcVar6[0xd] = s_Aufbereitete_00a4e3d4[0xc];

    pcVar13 = &cStack_119;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Aufbereiteter_00a4e3c4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Aufbereiteter_00a4e3c4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Aufbereiteter_00a4e3c4._8_4_;

    *(uint16_t *)(pcVar6 + 0xd) = s_Aufbereiteter_00a4e3c4._12_2_;

    pcVar13 = &cStack_599;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Hochwertiges_00a4e3b4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Hochwertiges_00a4e3b4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Hochwertiges_00a4e3b4._8_4_;

    pcVar6[0xd] = s_Hochwertiges_00a4e3b4[0xc];

    pcVar13 = &cStack_499;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Hochwertige_00a4e3a8._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Hochwertige_00a4e3a8._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Hochwertige_00a4e3a8._8_4_;

    pcVar13 = &cStack_619;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Hochwertiger_00a4e398._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Hochwertiger_00a4e398._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s_Hochwertiger_00a4e398._8_4_;

    pcVar6[0xd] = s_Hochwertiger_00a4e398[0xc];

    pcVar13 = &cStack_299;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Perfektes_00a4e38c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Perfektes_00a4e38c._4_4_;

    *(uint16_t *)(pcVar6 + 9) = s_Perfektes_00a4e38c._8_2_;

    pcVar13 = &cStack_199;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Perfekte_00a4e380._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Perfekte_00a4e380._4_4_;

    pcVar6[9] = s_Perfekte_00a4e380[8];

    pcVar13 = &cStack_399;

    do {

      pcVar6 = pcVar13;

      pcVar13 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_Perfekter_00a4e374._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_Perfekter_00a4e374._4_4_;

    *(uint16_t *)(pcVar6 + 9) = s_Perfekter_00a4e374._8_2_;

    pbVar7 = local_98;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ab14:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ab19;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ab14;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ab19:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_698;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ab54:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ab59;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ab54;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ab59:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_518;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ab94:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ab99;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ab94;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ab99:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_118;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089abd4:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089abd9;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089abd4;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089abd9:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_418;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ac14:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ac19;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ac14;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ac19:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_218;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ac54:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ac59;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ac54;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ac59:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_618;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ac94:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ac99;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ac94;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ac99:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_598;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089acd4:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089acd9;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089acd4;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089acd9:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_498;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ad14:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ad19;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ad14;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ad19:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_398;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ad54:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ad59;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ad54;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ad59:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_298;

    pbVar8 = pbVar14;

    do {

      bVar2 = *pbVar8;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089ad94:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089ad99;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar8[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089ad94;

      pbVar8 = pbVar8 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089ad99:

    if (iVar9 == 0) goto LAB_0089ae17;

    pbVar7 = local_198;

    do {

      bVar2 = *pbVar14;

      bVar17 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_0089adca:

        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

        goto LAB_0089adcf;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar14[1];

      bVar17 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_0089adca;

      pbVar14 = pbVar14 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar9 = 0;

LAB_0089adcf:

    if (iVar9 == 0) goto LAB_0089ae17;

    bVar3 = false;

  }

  else {

LAB_0089ae17:

    if ((bVar3) && (pcVar6 = strtok((char *)0x0," "), pcVar13 = pcVar6, pcVar6 != (char *)0x0)) {

      do {

        cVar1 = *pcVar13;

        pcVar13 = pcVar13 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar13 - (int)pcVar6;

      pcVar13 = &local_821;

      do {

        pcVar16 = pcVar13 + 1;

        pcVar13 = pcVar13 + 1;

      } while (*pcVar16 != '\0');

      while( true ) {

        for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar13 = pcVar13 + 4;

        }

        for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar13 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar13 = pcVar13 + 1;

        }

        pcVar6 = strtok((char *)0x0," ");

        if (pcVar6 == (char *)0x0) break;

        pcVar13 = &local_821;

        do {

          pcVar16 = pcVar13 + 1;

          pcVar13 = pcVar13 + 1;

        } while (*pcVar16 != '\0');

        *(uint16_t *)pcVar13 = DAT_00a2a000;

        pcVar13 = pcVar6;

        do {

          cVar1 = *pcVar13;

          pcVar13 = pcVar13 + 1;

        } while (cVar1 != '\0');

        uVar10 = (int)pcVar13 - (int)pcVar6;

        pcVar13 = &local_821;

        do {

          pcVar16 = pcVar13 + 1;

          pcVar13 = pcVar13 + 1;

        } while (*pcVar16 != '\0');

      }

    }

  }

  if ((int)param_3 < 1) {

    if (!bVar3) {

      sprintf(local_8a0,"[0] %s",local_718);

      goto LAB_0089afad;

    }

    param_3 = local_820;

    pcVar13 = "[0] %s, %s";

    pbVar14 = local_8ac;

  }

  else {

    if (bVar3) {

      sprintf(local_8a0,"[%i] %s, %s",param_3,local_820,local_8ac);

      goto LAB_0089afad;

    }

    pcVar13 = "[%i] %s";

    pbVar14 = local_718;

  }

  sprintf(local_8a0,pcVar13,param_3,pbVar14);

LAB_0089afad:

  iVar9 = FUN_00599dd0();

  if (iVar9 < 1) {

    if (*(int *)(local_8a8 + 0x4d0) == -1) {

      ExceptionList = local_14;

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x568) + 0x45c))

              (local_8a0,*(int *)(param_2 + 0x34),*(int *)(param_2 + 0x34) >> 0x1f,1);

    piVar12 = *(int **)(param_1 + 0x568);

  }

  else {

    (**(code **)(**(int **)(param_1 + 0x56c) + 0x45c))

              (local_8a0,*(int *)(param_2 + 0x34),*(int *)(param_2 + 0x34) >> 0x1f,1);

    piVar12 = *(int **)(param_1 + 0x56c);

  }

  (**(code **)(*piVar12 + 0x464))

            (*(int *)(param_2 + 0x34),*(int *)(param_2 + 0x34) >> 0x1f,1,&stack0xfffff740);

  ExceptionList = local_14;

  return;

}
