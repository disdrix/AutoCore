// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, return×2, for×1.
//  - Notable callees: FUN_00411900×6, FUN_008f8200×6, FUN_00402c40×3, Mission×3, sprintf×3, CONCAT22, FUN_00954670, Objective.
//  - Strings: "DEBUG"; "Mission(%d)(%S) Objective(%d)(%d)(%S)"; "Mission(%d)(%S)"; "Instanced Completed Missions:".
//  - Return sites: 2.

// =============================================================================
// Mission_Mission_d_S_Objective_d_d_S
// -----------------------------------------------------------------------------
// Stable ID: aa_00954670
// Address:   0x00954670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Mission(%d)(%S) Objective(%d)(%d)(%S)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ __thiscall Mission_Mission_d_S_Objective_d_d_S(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ local_1004;

  char local_1000 [4];

  char local_ffc [4];

  char local_ff8 [4];

  char local_ff4 [4];

  uint32_t /* width from decompiler */ local_ff0 [1019];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x95467a;

  iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                          &CDlgChatLog::RTTI_Type_Descriptor,0);

  if ((*(int *)(param_1 + 0xe98) != 0) && (iVar1 != 0)) {

    pcVar2 = strtok((char *)0x0,param_3);

    if (pcVar2 == (char *)0x0) {

      local_ff8[0] = s_Current_Missions__00a28b84[8];

      local_ff8[1] = s_Current_Missions__00a28b84[9];

      local_ff8[2] = s_Current_Missions__00a28b84[10];

      local_ff8[3] = s_Current_Missions__00a28b84[0xb];

      local_1000[0] = s_Current_Missions__00a28b84[0];

      local_1000[1] = s_Current_Missions__00a28b84[1];

      local_1000[2] = s_Current_Missions__00a28b84[2];

      local_1000[3] = s_Current_Missions__00a28b84[3];

      local_ffc[0] = s_Current_Missions__00a28b84[4];

      local_ffc[1] = s_Current_Missions__00a28b84[5];

      local_ffc[2] = s_Current_Missions__00a28b84[6];

      local_ffc[3] = s_Current_Missions__00a28b84[7];

      local_ff4[0] = s_Current_Missions__00a28b84[0xc];

      local_ff4[1] = s_Current_Missions__00a28b84[0xd];

      local_ff4[2] = s_Current_Missions__00a28b84[0xe];

      local_ff4[3] = s_Current_Missions__00a28b84[0xf];

      local_ff0[0] = CONCAT22(local_ff0[0]._2_2_,s_Current_Missions__00a28b84._16_2_);

      FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

      local_1004 = 0;

      FUN_00402c40();

      iVar3 = FUN_00411900(&local_1004);

      while (iVar3 != 0) {

        sprintf(local_1000,"Mission(%d)(%S) Objective(%d)(%d)(%S)",**(uint32_t /* width from decompiler */ **)(iVar3 + 0x14c),

                *(uint32_t /* width from decompiler */ **)(iVar3 + 0x14c) + 1,(uint)*(byte *)(iVar3 + 0x14),

                *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10),iVar3 + 0x16);

        FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

        iVar3 = FUN_00411900(&local_1004);

      }

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 0xe98) + 0x548) + 0x1d) = 0;

      return 1;

    }

    pcVar2 = strstr(pcVar2,"in");

    if (pcVar2 == (char *)0x0) {

      local_ff8[0] = s_Completed_Missions__00a28b0c[8];

      local_ff8[1] = s_Completed_Missions__00a28b0c[9];

      local_ff8[2] = s_Completed_Missions__00a28b0c[10];

      local_ff8[3] = s_Completed_Missions__00a28b0c[0xb];

      local_1000[0] = s_Completed_Missions__00a28b0c[0];

      local_1000[1] = s_Completed_Missions__00a28b0c[1];

      local_1000[2] = s_Completed_Missions__00a28b0c[2];

      local_1000[3] = s_Completed_Missions__00a28b0c[3];

      local_ffc[0] = s_Completed_Missions__00a28b0c[4];

      local_ffc[1] = s_Completed_Missions__00a28b0c[5];

      local_ffc[2] = s_Completed_Missions__00a28b0c[6];

      local_ffc[3] = s_Completed_Missions__00a28b0c[7];

      local_ff4[0] = s_Completed_Missions__00a28b0c[0xc];

      local_ff4[1] = s_Completed_Missions__00a28b0c[0xd];

      local_ff4[2] = s_Completed_Missions__00a28b0c[0xe];

      local_ff4[3] = s_Completed_Missions__00a28b0c[0xf];

      local_ff0[0]._0_1_ = s_Completed_Missions__00a28b0c[0x10];

      local_ff0[0]._1_1_ = s_Completed_Missions__00a28b0c[0x11];

      local_ff0[0]._2_1_ = s_Completed_Missions__00a28b0c[0x12];

      local_ff0[0]._3_1_ = s_Completed_Missions__00a28b0c[0x13];

      FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

      local_1004 = 0;

      FUN_00402c40();

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00411900(&local_1004);

      while (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        sprintf(local_1000,"Mission(%d)(%S)",*puVar4,puVar4 + 1);

        FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00411900(&local_1004);

      }

      iVar1 = *(int *)(*(int *)(param_1 + 0xe98) + 0x538);

    }

    else {

      pcVar2 = "Instanced Completed Missions:";

      pcVar5 = local_1000;

      for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar2;

        pcVar2 = pcVar2 + 4;

        pcVar5 = pcVar5 + 4;

      }

      *(uint16_t *)pcVar5 = *(uint16_t *)pcVar2;

      FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

      local_1004 = 0;

      FUN_00402c40();

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00411900(&local_1004);

      while (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        sprintf(local_1000,"Mission(%d)(%S)",*puVar4,puVar4 + 1);

        FUN_008f8200(iVar1,6,"DEBUG",local_1000,0);

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00411900(&local_1004);

      }

      iVar1 = *(int *)(*(int *)(param_1 + 0xe98) + 0x53c);

    }

    *(uint8_t *)(iVar1 + 0x1d) = 0;

  }

  return 1;

}
