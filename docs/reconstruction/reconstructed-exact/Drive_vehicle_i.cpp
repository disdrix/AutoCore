// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×3, for×3, do×2, while×2, switch×1, goto×1, return×1.
//  - Notable callees: SUB42×2, Client_GetMissionCompleteAudioTable, FUN_005d90a0, FUN_00725bd0, FUN_0076c3c0, FUN_0076cef0, FUN_0076cf00, sprintf.
//  - Strings: "CollisionListener::PlayCollisionSound"; "metal_%i_"; "wood_%i_"; "glass_%i_".
//  - Return sites: 1.

// =============================================================================
// Drive_vehicle_i
// -----------------------------------------------------------------------------
// Stable ID: aa_005d90a0
// Address:   0x005d90a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "vehicle_%i_"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Drive_vehicle_i(uint32_t /* width from decompiler */ param_1,float *param_2,uint32_t /* width from decompiler */ param_3,byte param_4)



{

  char cVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  float fVar9;

  uint32_t /* width from decompiler */ local_12c;

  char acStack_128 [2];

  ushort local_126;

  uint32_t /* width from decompiler */ local_124;

  char local_120 [2];

  uint32_t /* width from decompiler */ local_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a71cb;

  local_14 = ExceptionList;

  local_124 = DAT_00d1f040;

  ExceptionList = &local_14;

  FUN_0076cf00("CollisionListener::PlayCollisionSound");

  local_c = 0;

  uVar2 = FUN_0076c3c0();

  if (0x9c4 < uVar2) {

    thunk_FUN_0076c4d0();

    local_120[0] = '\0';

    local_120[1] = '\0';

    puVar7 = local_11e;

    for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    *(uint16_t *)puVar7 = 0;

    local_126 = 0;

    if (DAT_00aaa688 < *param_2 || DAT_00aaa688 == *param_2) {

      uVar3 = s_large_009db4a4._0_4_;

      acStack_128 = (char  [2])s_large_009db4a4._4_2_;

      if (*param_2 <= DAT_00a0f6a4 && DAT_00a0f6a4 != *param_2) {

        local_126 = (ushort)(byte)s_medium_009db4ac[6];

        uVar3 = s_medium_009db4ac._0_4_;

        acStack_128 = (char  [2])s_medium_009db4ac._4_2_;

      }

      local_12c._0_2_ = (uint16_t)uVar3;

      local_12c._2_2_ = SUB42(uVar3,2);

    }

    else {

      local_12c._0_2_ = (uint16_t)s_small_009db4b4._0_4_;

      local_12c._2_2_ = SUB42(s_small_009db4b4._0_4_,2);

      acStack_128[0] = s_small_009db4b4[4];

      acStack_128[1] = s_small_009db4b4[5];

    }

    switch(param_3) {

    case 1:

      pcVar8 = "metal_%i_";

      break;

    case 2:

      pcVar8 = "wood_%i_";

      break;

    case 3:

      pcVar8 = "glass_%i_";

      break;

    case 4:

      pcVar8 = "stone_%i_";

      break;

    case 5:

      pcVar8 = "vehicle_%i_";

      break;

    case 6:

      pcVar8 = "flesh_%i_";

      break;

    default:

      goto switchD_005d9191_default;

    }

    sprintf(local_120,pcVar8,(uint)param_4);

    pcVar8 = (char *)&local_12c;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    uVar2 = (int)pcVar8 - (int)&local_12c;

    pcVar8 = (char *)((int)&local_124 + 3);

    do {

      pcVar6 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = (char *)&local_12c;

    for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar8 = pcVar8 + 4;

    }

    fVar9 = *param_2;

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *pcVar8 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar8 = pcVar8 + 1;

    }

    pcVar8 = local_120;

    Client_GetMissionCompleteAudioTable(pcVar8,param_1,fVar9);

    FUN_00725bd0(pcVar8,param_1,fVar9);

  }

switchD_005d9191_default:

  local_c = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_14;

  return;

}
