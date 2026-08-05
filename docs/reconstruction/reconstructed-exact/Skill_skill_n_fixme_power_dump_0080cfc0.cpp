// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×14, do×8, while×8, return×2, for×1.
//  - Notable callees: sprintf×2, FUN_004bb0d0, FUN_0052ed80, FUN_007a69d0, FUN_007a6de0, FUN_0080cfc0, FUN_008f8200, NDSpecialFX_LoadFromScriptName.
//  - Strings: "Powerdump failed"; "Powerdump successful for: %s"; "skill_n_fixme_power-dump".
//  - Return sites: 2.

// =============================================================================
// Skill_skill_n_fixme_power_dump_0080cfc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080cfc0
// Address:   0x0080cfc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "skill_n_fixme_power-dump"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_skill_n_fixme_power_dump_0080cfc0(void)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  void *pvVar7;

  uint16_t *puVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char local_160 [6];

  char acStack_15a [146];

  char local_c8 [200];

  

  FUN_007a69d0();

  if (DAT_00d1b6d8 != 0) {

    piVar1 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x164 + DAT_00d1b6d8);

    if (((*(int *)(in_EAX + 8) == *piVar1) && (*(int *)(in_EAX + 0xc) == piVar1[1])) &&

       (*(char *)(in_EAX + 0x10) == (char)piVar1[2])) {

      uVar2 = *(uint *)(in_EAX + 4);

      if (uVar2 == 0) {

        sprintf(local_c8,"Powerdump failed");

      }

      else {

        local_160[0] = '\0';

        puVar8 = (uint16_t *)&stack0xfffffe9f;

        do {

          pcVar4 = (char *)((int)puVar8 + 1);

          puVar8 = (uint16_t *)((int)puVar8 + 1);

        } while (*pcVar4 != '\0');

        *puVar8 = DAT_00a6c044;

        if ((uVar2 & 2) != 0) {

          pcVar4 = &stack0xfffffe9f;

          do {

            pcVar9 = pcVar4;

            pcVar4 = pcVar9 + 1;

          } while (pcVar9[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 1) = s_Stunned__00a6c010._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 5) = s_Stunned__00a6c010._4_4_;

          pcVar9[9] = s_Stunned__00a6c010[8];

        }

        if ((uVar2 & 4) != 0) {

          pcVar4 = &stack0xfffffe9f;

          do {

            pcVar9 = pcVar4;

            pcVar4 = pcVar9 + 1;

          } while (pcVar9[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 1) = s_Lockdown__00a6c004._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 5) = s_Lockdown__00a6c004._4_4_;

          *(uint16_t *)(pcVar9 + 9) = s_Lockdown__00a6c004._8_2_;

        }

        if ((uVar2 & 8) != 0) {

          pcVar4 = &stack0xfffffe9f;

          do {

            pcVar9 = pcVar4;

            pcVar4 = pcVar9 + 1;

          } while (pcVar9[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 1) = s_Silence__00a6bff8._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 5) = s_Silence__00a6bff8._4_4_;

          pcVar9[9] = s_Silence__00a6bff8[8];

        }

        if ((uVar2 & 0x10) != 0) {

          pcVar4 = &stack0xfffffe9f;

          do {

            pcVar9 = pcVar4;

            pcVar4 = pcVar9 + 1;

          } while (pcVar9[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 1) = s_No_Fire__00a6bfec._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 5) = s_No_Fire__00a6bfec._4_4_;

          pcVar9[9] = s_No_Fire__00a6bfec[8];

        }

        if ((uVar2 & 0x200) != 0) {

          pcVar4 = &stack0xfffffe9f;

          do {

            pcVar9 = pcVar4;

            pcVar4 = pcVar9 + 1;

          } while (pcVar9[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar9 + 1) = s_Blind__00a6bfe4._0_4_;

          *(uint16_t *)(pcVar9 + 5) = s_Blind__00a6bfe4._4_2_;

          pcVar9[7] = s_Blind__00a6bfe4[6];

        }

        if ((uVar2 & 0x40) != 0) {

          puVar3 = (uint32_t /* width from decompiler */ *)&stack0xfffffe9f;

          do {

            puVar10 = puVar3;

            puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          } while (*(char *)((int)puVar10 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a6bfdc;

          *(uint16_t *)((int)puVar10 + 5) = DAT_00a6bfe0;

        }

        if ((uVar2 & 0x1000) != 0) {

          puVar3 = (uint32_t /* width from decompiler */ *)&stack0xfffffe9f;

          do {

            puVar10 = puVar3;

            puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          } while (*(char *)((int)puVar10 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a6bfd4;

          *(uint16_t *)((int)puVar10 + 5) = DAT_00a6bfd8;

        }

        pcVar4 = strrchr(local_160,0x2c);

        if (pcVar4 != (char *)0x0) {

          pcVar4[0] = '}';

          pcVar4[1] = '\0';

        }

        sprintf(local_c8,"Powerdump successful for: %s",local_160);

      }

      FUN_0052ed80(0,*(uint32_t /* width from decompiler */ *)(in_EAX + 4));

      uVar5 = FUN_007a6de0(local_c8,0xffffffff);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar5,0);

        return;

      }

    }

    else {

      iVar6 = FUN_004bb0d0(in_EAX + 8);

      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x250), iVar6 != 0)) {

        pvVar7 = NDSpecialFX_LoadFromScriptName("skill_n_fixme_power-dump",2,0);

        if (pvVar7 != (void *)0x0) {

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0xf8))(pvVar7,1,0);

        }

      }

    }

  }

  return;

}
