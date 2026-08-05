// READABILITY (auto CF):
//  - Body size: ~519 non-empty decompiler lines.
//  - Control keywords: if×76, do×10, while×10, goto×5, for×4, return×2.
//  - Notable callees: Weapon×7, FUN_007a6de0×5, CONCAT13×4, FUN_00519d20×2, FUN_0051f550, FUN_007a69d0, FUN_0087d2f0, FUN_008800e0.
//  - Strings: "Vehicle"; "%s - \""; "Garage"; "Shield Kit".
//  - Return sites: 2.

// =============================================================================
// Drive_Vehicle_008801b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008801b0
// Address:   0x008801b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Vehicle"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Drive_Vehicle_008801b0(int *param_1)



{

  byte bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  uint uVar8;

  int *piVar9;

  char *pcVar10;

  char *pcVar11;

  uint16_t *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint8_t auStack_108 [3];

  uint32_t /* width from decompiler */ uStack_105;

  uint8_t auStack_100 [6];

  char acStack_fa [8];

  char acStack_f2 [242];

  

  FUN_007a69d0();

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 == '\0') {

    return;

  }

  if ((param_1[0x145] == 0) || (DAT_00d1b6d8 == 0)) {

    if (param_1[0x161] != 0) {

      uStack_105._1_1_ = 0;

      if (param_1[0x144] == 0) {

        pcVar6 = auStack_108 + 3;

        do {

          pcVar5 = pcVar6;

          pcVar6 = pcVar5 + 1;

        } while (pcVar5[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s_Vehicle___00a57d60._0_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s_Vehicle___00a57d60._4_4_;

        *(uint16_t *)(pcVar5 + 9) = s_Vehicle___00a57d60._8_2_;

        pcVar5[0xb] = s_Vehicle___00a57d60[10];

      }

      else if (param_1[0x144] == 1) {

        pcVar6 = auStack_108 + 3;

        do {

          pcVar5 = pcVar6;

          pcVar6 = pcVar5 + 1;

        } while (pcVar5[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s_Garage___00a57d54._0_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s_Garage___00a57d54._4_4_;

        *(uint16_t *)(pcVar5 + 9) = s_Garage___00a57d54._8_2_;

      }

      pcVar6 = auStack_108 + 3;

      do {

        pcVar5 = pcVar6;

        pcVar6 = pcVar5 + 1;

      } while (pcVar5[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s__No_Vehicle_Selected__00a57d3c._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s__No_Vehicle_Selected__00a57d3c._4_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 9) = s__No_Vehicle_Selected__00a57d3c._8_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 0xd) = s__No_Vehicle_Selected__00a57d3c._12_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 0x11) = s__No_Vehicle_Selected__00a57d3c._16_4_;

      *(uint16_t *)(pcVar5 + 0x15) = s__No_Vehicle_Selected__00a57d3c._20_2_;

      (**(code **)(*(int *)param_1[0x161] + 0x1d8))((int)&uStack_105 + 1,1,1);

    }

    if (param_1[0x168] != 0) {

      (**(code **)(*(int *)param_1[0x168] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x168] + 4))(0);

    }

    if (param_1[0x169] != 0) {

      (**(code **)(*(int *)param_1[0x169] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x169] + 4))(0);

    }

    if (param_1[0x16a] != 0) {

      (**(code **)(*(int *)param_1[0x16a] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x16a] + 4))(0);

    }

    if (param_1[0x162] != 0) {

      (**(code **)(*(int *)param_1[0x162] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x162] + 4))(0);

    }

    if (param_1[0x163] != 0) {

      (**(code **)(*(int *)param_1[0x163] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x163] + 4))(0);

    }

    if (param_1[0x164] != 0) {

      (**(code **)(*(int *)param_1[0x164] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x164] + 4))(0);

    }

    if (param_1[0x165] != 0) {

      (**(code **)(*(int *)param_1[0x165] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x165] + 4))(0);

    }

    if (param_1[0x166] != 0) {

      (**(code **)(*(int *)param_1[0x166] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x166] + 4))(0);

    }

    if (param_1[0x167] != 0) {

      (**(code **)(*(int *)param_1[0x167] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x167] + 4))(0);

    }

    if (param_1[0x151] != 0) {

      (**(code **)(*(int *)param_1[0x151] + 4))(0);

    }

    if (param_1[0x152] != 0) {

      (**(code **)(*(int *)param_1[0x152] + 4))(0);

    }

    if (param_1[0x153] != 0) {

      (**(code **)(*(int *)param_1[0x153] + 4))(0);

    }

    if (param_1[0x14b] != 0) {

      (**(code **)(*(int *)param_1[0x14b] + 4))(0);

    }

    if (param_1[0x14c] != 0) {

      (**(code **)(*(int *)param_1[0x14c] + 4))(0);

    }

    if (param_1[0x14d] != 0) {

      (**(code **)(*(int *)param_1[0x164] + 4))(0);

    }

    if (param_1[0x14e] != 0) {

      (**(code **)(*(int *)param_1[0x165] + 4))(0);

    }

    if (param_1[0x14f] != 0) {

      (**(code **)(*(int *)param_1[0x166] + 4))(0);

    }

    if (param_1[0x150] != 0) {

      (**(code **)(*(int *)param_1[0x167] + 4))(0);

    }

    if (param_1[0x16b] != 0) {

      (**(code **)(*(int *)param_1[0x16b] + 4))(0);

    }

    if (param_1[0x155] != 0) {

      (**(code **)(*(int *)param_1[0x155] + 4))(0);

    }

    if (param_1[0x156] != 0) {

      (**(code **)(*(int *)param_1[0x156] + 4))(0);

    }

    uVar4 = 0;

    goto LAB_008810be;

  }

  if (param_1[0x161] != 0) {

    uStack_105._1_1_ = 0;

    if (param_1[0x144] == 0) {

      uVar4 = FUN_007a6de0("Vehicle",0xffffffff);

LAB_0088024c:

      sprintf((char *)((int)&uStack_105 + 1),"%s - \"",uVar4);

    }

    else if (param_1[0x144] == 1) {

      uVar4 = FUN_007a6de0("Garage",0xffffffff);

      goto LAB_0088024c;

    }

    pcVar5 = (char *)(param_1[0x145] + 0x1b0);

    pcVar6 = pcVar5;

    do {

      cVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

    pcVar11 = auStack_108 + 3;

    do {

      pcVar10 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar10 != '\0');

    pcVar10 = pcVar5;

    for (uVar8 = (uint)((int)pcVar6 - (int)pcVar5) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar10;

      pcVar10 = pcVar10 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar8 = (int)pcVar6 - (int)pcVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar11 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      pcVar11 = pcVar11 + 1;

    }

    puVar12 = (uint16_t *)(auStack_108 + 3);

    do {

      pcVar6 = (char *)((int)puVar12 + 1);

      puVar12 = (uint16_t *)((int)puVar12 + 1);

    } while (*pcVar6 != '\0');

    piVar9 = (int *)param_1[0x161];

    *puVar12 = DAT_00a2faa8;

    (**(code **)(*piVar9 + 0x1d8))((int)&uStack_105 + 1,1,1);

  }

  if (param_1[0x14e] != 0) {

    uStack_105._1_1_ = 0;

    pcVar6 = auStack_108 + 3;

    do {

      pcVar5 = pcVar6;

      pcVar6 = pcVar5 + 1;

    } while (pcVar5[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s_i_d_v_2d_icon_race_00a57e70._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s_i_d_v_2d_icon_race_00a57e70._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 9) = s_i_d_v_2d_icon_race_00a57e70._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 0xd) = s_i_d_v_2d_icon_race_00a57e70._12_4_;

    *(uint16_t *)(pcVar5 + 0x11) = s_i_d_v_2d_icon_race_00a57e70._16_2_;

    pcVar5[0x13] = s_i_d_v_2d_icon_race_00a57e70[0x12];

    pcVar5 = (char *)FUN_0051f550(*(uint8_t *)

                                   (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                      0xac + DAT_00d1b6d8) + 0x3c) + 0x532),

                                  0xffffffff);

    pcVar6 = pcVar5;

    do {

      cVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

    pcVar11 = auStack_108 + 3;

    do {

      pcVar10 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar10 != '\0');

    pcVar10 = pcVar5;

    for (uVar8 = (uint)((int)pcVar6 - (int)pcVar5) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar10;

      pcVar10 = pcVar10 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar8 = (int)pcVar6 - (int)pcVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar11 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      pcVar11 = pcVar11 + 1;

    }

    puVar2 = (uint32_t /* width from decompiler */ *)(auStack_108 + 3);

    do {

      puVar13 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

    } while (*(char *)((int)puVar13 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar13 + 1) = DAT_00a2c53c;

    piVar9 = (int *)param_1[0x14e];

    *(uint8_t *)((int)puVar13 + 5) = DAT_00a2c540;

    iVar7 = *piVar9;

    uVar4 = (**(code **)(*piVar9 + 0x2c8))(0);

    (**(code **)(iVar7 + 0x50))((int)&uStack_105 + 1,uVar4);

  }

  if (param_1[0x165] != 0) {

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                       DAT_00d1b6d8) + 0x3c) + 0x532);

    if (cVar3 == '\0') {

      pcVar6 = "Shield Kit";

LAB_0088041f:

      iVar7 = *(int *)param_1[0x165];

    }

    else if (cVar3 == '\x01') {

      iVar7 = *(int *)param_1[0x165];

      pcVar6 = "HEART Kit";

    }

    else {

      if (cVar3 != '\x02') {

        pcVar6 = "Internal Kit";

        goto LAB_0088041f;

      }

      iVar7 = *(int *)param_1[0x165];

      pcVar6 = "Hazard Kit";

    }

    uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

    (**(code **)(iVar7 + 0x308))(uVar4);

  }

  if (param_1[0x163] != 0) {

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x145] + 4) + 4) + 0xac +

                                       param_1[0x145]) + 0x3c) + 0x714);

    if (cVar3 == '\x01') {

      pcVar6 = "Turret Mount Weapon (Small)";

LAB_008804a2:

      iVar7 = *(int *)param_1[0x163];

    }

    else if (cVar3 == '\x02') {

      iVar7 = *(int *)param_1[0x163];

      pcVar6 = "Turret Mount Weapon (Medium)";

    }

    else {

      if (cVar3 != '\x03') {

        pcVar6 = "Turret Mount Weapon (Any Size)";

        goto LAB_008804a2;

      }

      iVar7 = *(int *)param_1[0x163];

      pcVar6 = "Turret Mount Weapon (Large)";

    }

    uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

    (**(code **)(iVar7 + 0x308))(uVar4);

  }

  if (param_1[0x162] != 0) {

    bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x145] + 4) + 4) + 0xac +

                                       param_1[0x145]) + 0x3c) + 0x714);

    if (bVar1 == 1) {

      iVar7 = *(int *)param_1[0x162];

      pcVar6 = "Front Mount Weapon (Small)";

    }

    else if ((bVar1 < 2) || (3 < bVar1)) {

      iVar7 = *(int *)param_1[0x162];

      pcVar6 = "Front Mount Weapon (Any Size)";

    }

    else {

      iVar7 = *(int *)param_1[0x162];

      pcVar6 = "Front Mount Weapon (Medium)";

    }

    uVar4 = FUN_007a6de0(pcVar6,0xffffffff);

    (**(code **)(iVar7 + 0x308))(uVar4);

    if ((param_1[0x162] != 0) && (param_1[0x14b] != 0)) {

      iVar7 = **(int **)(param_1[0x145] + 0x260);

      if (iVar7 != 0) {

        iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

      }

      (**(code **)(*(int *)param_1[0x162] + 0x3b0))(iVar7);

      iVar7 = (**(code **)(*(int *)param_1[0x162] + 0x3ac))();

      if (iVar7 == 0) {

        (**(code **)(*(int *)param_1[0x162] + 0x1d8))(&DAT_00a1419b,1,1);

        (**(code **)(*(int *)param_1[0x162] + 0x31c))(1);

        (**(code **)(*(int *)param_1[0x14b] + 4))(1);

      }

      else {

        (**(code **)(*(int *)param_1[0x162] + 0x31c))(0);

        (**(code **)(*(int *)param_1[0x14b] + 4))(0);

      }

      (**(code **)(*(int *)param_1[0x162] + 4))(1);

    }

  }

  if ((param_1[0x163] != 0) && (param_1[0x14c] != 0)) {

    iVar7 = *(int *)(*(int *)(param_1[0x145] + 0x260) + 4);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x163] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x163] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x163] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x163] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x14c] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x163] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x14c] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x163] + 4))(1);

  }

  if ((param_1[0x164] != 0) && (param_1[0x14d] != 0)) {

    iVar7 = *(int *)(*(int *)(param_1[0x145] + 0x260) + 8);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x164] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x164] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x164] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x164] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x14d] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x164] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x14d] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x164] + 4))(1);

  }

  if ((param_1[0x165] != 0) && (param_1[0x14e] != 0)) {

    iVar7 = *(int *)(param_1[0x145] + 0x270);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x165] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x165] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x165] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x165] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x14e] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x165] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x14e] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x165] + 4))(1);

  }

  if ((param_1[0x166] != 0) && (param_1[0x14f] != 0)) {

    iVar7 = *(int *)(param_1[0x145] + 0x26c);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x166] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x166] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x166] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x166] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x14f] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x166] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x14f] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x166] + 4))(1);

  }

  if ((param_1[0x167] != 0) && (param_1[0x150] != 0)) {

    iVar7 = *(int *)(param_1[0x145] + 0x264);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x167] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x167] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x167] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x167] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x150] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x167] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x150] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x167] + 4))(1);

  }

  if ((param_1[0x168] != 0) && (param_1[0x151] != 0)) {

    iVar7 = *(int *)(param_1[0x145] + 0x268);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x168] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x168] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x168] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x168] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x151] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x168] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x151] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x168] + 4))(1);

  }

  if (param_1[0x169] != 0) {

    if (((param_1[0x152] == 0) || (iVar7 = *(int *)(param_1[0x145] + 600), iVar7 == 0)) ||

       (*(char *)(iVar7 + 0xcc) != '\0')) {

      if (param_1[0x169] == 0) goto LAB_00880b02;

      (**(code **)(*(int *)param_1[0x169] + 0x3b0))(0);

      (**(code **)(*(int *)param_1[0x169] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x169] + 0x31c))(1);

      piVar9 = (int *)param_1[0x152];

    }

    else {

      (**(code **)(*(int *)param_1[0x169] + 0x3b0))(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7);

      iVar7 = (**(code **)(*(int *)param_1[0x169] + 0x3ac))();

      if (iVar7 == 0) {

        (**(code **)(*(int *)param_1[0x169] + 0x1d8))(&DAT_00a1419b,1,1);

        (**(code **)(*(int *)param_1[0x169] + 0x31c))(1);

        (**(code **)(*(int *)param_1[0x152] + 4))(1);

        piVar9 = (int *)param_1[0x169];

      }

      else {

        (**(code **)(*(int *)param_1[0x169] + 0x31c))(0);

        (**(code **)(*(int *)param_1[0x152] + 4))(0);

        piVar9 = (int *)param_1[0x169];

      }

    }

    (**(code **)(*piVar9 + 4))(1);

  }

LAB_00880b02:

  if ((param_1[0x16a] != 0) && (param_1[0x153] != 0)) {

    iVar7 = *(int *)(param_1[0x145] + 0x254);

    if (iVar7 != 0) {

      iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;

    }

    (**(code **)(*(int *)param_1[0x16a] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x16a] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x16a] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x16a] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x153] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x16a] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x153] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x16a] + 4))(1);

  }

  if ((param_1[0x16b] != 0) && (param_1[0x154] != 0)) {

    if (param_1[0x145] == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(*(int *)(param_1[0x145] + 4) + 4) + 4 + param_1[0x145];

    }

    (**(code **)(*(int *)param_1[0x16b] + 0x3b0))(iVar7);

    iVar7 = (**(code **)(*(int *)param_1[0x16b] + 0x3ac))();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x16b] + 0x1d8))(&DAT_00a1419b,1,1);

      (**(code **)(*(int *)param_1[0x16b] + 0x31c))(1);

      (**(code **)(*(int *)param_1[0x154] + 4))(1);

    }

    else {

      (**(code **)(*(int *)param_1[0x16b] + 0x31c))(0);

      (**(code **)(*(int *)param_1[0x154] + 4))(0);

    }

    (**(code **)(*(int *)param_1[0x16b] + 4))(1);

  }

  _auStack_108 = 0xffffffff;

  if (param_1[0x155] != 0) {

    _auStack_108 = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(param_1[0x145] + 0x1a8));

    cVar3 = (**(code **)(*(int *)param_1[0x155] + 0xf8))();

    if (cVar3 == '\0') {

      _auStack_108 = CONCAT13(0xfe,auStack_108);

    }

    else {

      iVar7 = (**(code **)(*(int *)param_1[0x155] + 0x164))(0);

      _auStack_108 = CONCAT13(*(uint8_t *)(iVar7 + 3),auStack_108);

    }

    (**(code **)(*(int *)param_1[0x155] + 0x15c))(0,auStack_108);

    (**(code **)(*(int *)param_1[0x155] + 4))(1);

    (**(code **)(*(int *)param_1[0x155] + 0x34c))();

  }

  if (param_1[0x156] != 0) {

    _auStack_108 = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(param_1[0x145] + 0x1ac));

    cVar3 = (**(code **)(*(int *)param_1[0x156] + 0xf8))();

    if (cVar3 == '\0') {

      _auStack_108 = CONCAT13(0xfe,auStack_108);

    }

    else {

      iVar7 = (**(code **)(*(int *)param_1[0x156] + 0x164))(0);

      _auStack_108 = CONCAT13(*(uint8_t *)(iVar7 + 3),auStack_108);

    }

    (**(code **)(*(int *)param_1[0x156] + 0x15c))(0,auStack_108);

    (**(code **)(*(int *)param_1[0x156] + 4))(1);

    (**(code **)(*(int *)param_1[0x156] + 0x34c))();

  }

  uVar4 = 1;

LAB_008810be:

  FUN_0087d2f0(uVar4);

  FUN_008800e0();

  return;

}
