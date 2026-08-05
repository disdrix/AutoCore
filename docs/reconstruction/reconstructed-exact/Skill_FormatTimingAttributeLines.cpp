// READABILITY (auto CF):
//  - Body size: ~515 non-empty decompiler lines.
//  - Control keywords: do×44, while×44, if×27, for×23, goto×4, return×2.
//  - Notable callees: FUN_0054f970×13, FUN_00552180.
//  - Strings: "maintained on target)\n"; "cast_time = instant)\n"; "cast_time] (seconds)\n"; "power_cost]\n".
//  - Return sites: 2.

// =============================================================================
// Skill_FormatTimingAttributeLines
// -----------------------------------------------------------------------------
// Purpose:  Emit skill timing/attribute debug or tooltip lines for cast_time, cooldown, duration, pulse_period/count/duration, power_cost, range, and tether_range (including instant and infinite special cases).
//
// Address:  0x00552180  (autoassault.exe, image base 0x400000)
// Stable:   aa_00552180
// System:   skills-abilities
//
// Evidence strings (from raw decompile):
//   - "cast_time = instant)\n"
//   - "cast_time] (seconds)\n"
//   - "cooldown] (seconds)\n"
//   - "duration] (seconds)\n"
//   - "pulse_period] (seconds)\n"
//   - "power_cost]\n"
//   - "range] (meters)\n"
//   - "tether_range] (meters)\n"
//
// Notable callees:
//   - FUN_0054f970
//
// Notes:    Paired with Skill_FormatCooldownDurationRangeLines and Skill_ParseTimingAttributeToken.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

uint32_t /* width from decompiler */ __thiscall Skill_FormatTimingAttributeLines(int param_1,char *param_2,int param_3)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  int iVar4;

  char *pcVar5;

  uint16_t *puVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  float fVar9;

  uint32_t /* width from decompiler */ uVar10;

  

  if ((*(byte *)(param_1 + 0x614) & 2) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_self__009d2430._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_self__009d2430._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_self__009d2430._8_4_;

    *(uint16_t *)(pcVar7 + 0xd) = s_targets_self__009d2430._12_2_;

    pcVar7[0xf] = s_targets_self__009d2430[0xe];

  }

  if ((*(byte *)(param_1 + 0x614) & 4) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_ally__009d2420._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_ally__009d2420._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_ally__009d2420._8_4_;

    *(uint16_t *)(pcVar7 + 0xd) = s_targets_ally__009d2420._12_2_;

    pcVar7[0xf] = s_targets_ally__009d2420[0xe];

  }

  if ((*(byte *)(param_1 + 0x615) & 0x20) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_convoy_member__009d2408._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_convoy_member__009d2408._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_convoy_member__009d2408._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_convoy_member__009d2408._12_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x11) = s_targets_convoy_member__009d2408._16_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x15) = s_targets_convoy_member__009d2408._20_4_;

  }

  if ((*(byte *)(param_1 + 0x614) & 8) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_enemy__009d23f8._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_enemy__009d23f8._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_enemy__009d23f8._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_enemy__009d23f8._12_4_;

  }

  if ((*(byte *)(param_1 + 0x614) & 0x10) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_minion__009d23e4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_minion__009d23e4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_minion__009d23e4._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_minion__009d23e4._12_4_;

    pcVar7[0x11] = s_targets_minion__009d23e4[0x10];

  }

  if ((*(byte *)(param_1 + 0x614) & 0x20) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_ground__009d23d0._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_ground__009d23d0._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_ground__009d23d0._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_ground__009d23d0._12_4_;

    pcVar7[0x11] = s_targets_ground__009d23d0[0x10];

  }

  if ((*(byte *)(param_1 + 0x615) & 2) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    puVar8 = (uint32_t /* width from decompiler */ *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar8 + 1);

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    } while (*pcVar2 != '\0');

    pcVar2 = "maintained on target)\n";

    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar8 = *(uint32_t /* width from decompiler */ *)pcVar2;

      pcVar2 = pcVar2 + 4;

      puVar8 = puVar8 + 1;

    }

    *(uint16_t *)puVar8 = *(uint16_t *)pcVar2;

    *(char *)((int)puVar8 + 2) = pcVar2[2];

  }

  if ((*(byte *)(param_1 + 0x615) & 8) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_selection__009d23a4._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_selection__009d23a4._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_selection__009d23a4._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_selection__009d23a4._12_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x11) = s_targets_selection__009d23a4._16_4_;

  }

  if ((*(byte *)(param_1 + 0x615) & 4) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_targets_remains__009d2390._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_targets_remains__009d2390._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_targets_remains__009d2390._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_targets_remains__009d2390._12_4_;

    *(uint16_t *)(pcVar7 + 0x11) = s_targets_remains__009d2390._16_2_;

  }

  if ((*(byte *)(param_1 + 0x615) & 0x40) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_requires_stealth__009d237c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_requires_stealth__009d237c._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s_requires_stealth__009d237c._8_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s_requires_stealth__009d237c._12_4_;

    *(uint16_t *)(pcVar7 + 0x11) = s_requires_stealth__009d237c._16_2_;

    pcVar7[0x13] = s_requires_stealth__009d237c[0x12];

  }

  if ((*(byte *)(param_1 + 0x615) & 1) != 0) {

    puVar6 = (uint16_t *)(param_3 + -1);

    do {

      pcVar2 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar2 != '\0');

    *puVar6 = DAT_00a393e4;

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar7 = (char *)(param_3 + -1);

    do {

      pcVar5 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = param_2;

    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

    pcVar2 = (char *)(param_3 + -1);

    do {

      pcVar7 = pcVar2;

      pcVar2 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_passive__009d2284._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s_passive__009d2284._4_4_;

    *(uint16_t *)(pcVar7 + 9) = s_passive__009d2284._8_2_;

    goto LAB_0055288e;

  }

  if (*(short *)(param_1 + 0x14) == 0) {

    FUN_0054f970(param_3,param_2,"cast_time = instant)\n",0);

  }

  else {

    FUN_0054f970(param_3,param_2,"cast_time] (seconds)\n",1);

  }

  if (*(short *)(param_1 + 8) != 0) {

    FUN_0054f970(param_3,param_2,"power_cost]\n",1);

  }

  if (*(int *)(param_1 + 0x10) != 0) {

    FUN_0054f970(param_3,param_2,"cooldown] (seconds)\n",1);

  }

  iVar4 = *(int *)(param_1 + 0x18);

  if (iVar4 == 0) {

LAB_00552797:

    if (0 < *(int *)(param_1 + 0x1c)) {

      uVar10 = 1;

      pcVar2 = "duration] (seconds)\n";

      goto LAB_005527f3;

    }

  }

  else {

    if (iVar4 == -1000) {

LAB_005527ad:

      if (0 < *(int *)(param_1 + 0x1c)) {

        FUN_0054f970(param_3,param_2,"pulse_period] (seconds)\n",1);

      }

      uVar10 = 0;

      pcVar2 = "infinite duration/pulse count)\n";

    }

    else {

      if ((iVar4 == 0) || (iVar4 < 2)) goto LAB_00552797;

      if (iVar4 == -1000) goto LAB_005527ad;

      FUN_0054f970(param_3,param_2,"pulse_count]\n",1);

      FUN_0054f970(param_3,param_2,"pulse_period] (seconds)\n",1);

      uVar10 = 1;

      pcVar2 = "pulse_duration] (seconds)\n";

    }

LAB_005527f3:

    FUN_0054f970(param_3,param_2,pcVar2,uVar10);

  }

  if (*(short *)(param_1 + 10) != 0) {

    FUN_0054f970(param_3,param_2,"power_per_pulse]\n",1);

  }

LAB_0055288e:

  fVar9 = 0.0;

  if (*(float *)(param_1 + 0x28) != 0.0) {

    if ((*(float *)(param_1 + 0x2c) == 0.0) ||

       (*(float *)(param_1 + 0x2c) == *(float *)(param_1 + 0x28))) {

      pcVar2 = "range] (meters)\n";

    }

    else {

      pcVar2 = "range_min2max] (meters)\n";

    }

    FUN_0054f970(param_3,param_2,pcVar2,1);

  }

  if (fVar9 < *(float *)(param_1 + 0x30)) {

    FUN_0054f970(param_3,param_2,"tether_range] (meters)\n",1);

  }

  if (fVar9 < *(float *)(param_1 + 0x38)) {

    FUN_0054f970(param_3,param_2,"splash_radius] (meters)\n",1);

  }

  if (*(float *)(param_1 + 0xe4) != fVar9) {

    FUN_0054f970(param_3,param_2,"success_chance] (percent)\n",1);

  }

  if (*(int *)(param_1 + 0x5f0) != 0) {

    uVar10 = (**(code **)(**(int **)(param_1 + 0x5f0) + 0x38))(param_1,param_2,param_3);

    return uVar10;

  }

  return 0;

}
