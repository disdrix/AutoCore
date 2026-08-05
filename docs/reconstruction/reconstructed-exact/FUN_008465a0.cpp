// =============================================================================
// FUN_008465a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008465a0
// Address:   0x008465a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008465a0 @ 0x008465a0
// Stable ID: aa_008465a0
// Embedded strings (evidence for future rename):
//   - "%s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×7, do×4, while×4, return×3, for×2.
//  - Notable callees: FUN_007a6de0×2, sprintf×2, CONCAT22, FUN_005506a0, FUN_007a69d0, FUN_008465a0.
//  - Strings: "%s\n".
//  - Return sites: 3.

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

void FUN_008465a0(int *param_1,int *param_2,char param_3,char param_4)



{

  char cVar1;

  void *pSkillData;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  int *unaff_EBX;

  int local_620;

  int local_618 [4];

  char local_608 [2];

  uint32_t /* width from decompiler */ local_606 [123];

  char acStack_418 [16];

  uint16_t local_408;

  uint32_t /* width from decompiler */ local_406 [256];

  

  iVar2 = FUN_007a69d0();

  if (iVar2 != 0) {

    local_408 = 0;

    puVar4 = local_406;

    for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    local_608[0] = '\0';

    local_608[1] = '\0';

    puVar4 = local_606;

    for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    iVar2 = *(int *)(param_1[0x2a] + 0x3c);

    local_618[0] = *(int *)(iVar2 + 0x3bc);

    local_618[1] = *(int *)(iVar2 + 0x3c0);

    local_618[2] = *(int *)(iVar2 + 0x3c4);

    if (((*(int *)(iVar2 + 0x3bc) != -1) || (*(int *)(iVar2 + 0x3c0) != -1)) ||

       (*(int *)(iVar2 + 0x3c4) != -1)) {

      local_620 = 0;

      do {

        pSkillData = (void *)local_618[local_620];

        if (pSkillData != (void *)0xffffffff) {

          uVar3 = (**(code **)(*param_1 + 0x264))();

          puVar4 = CVOGReaction_ResolveSkillTargets

                             (pSkillData,CONCAT22((short)((uint)uVar3 >> 0x10),(ushort)(byte)uVar3))

          ;

          if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

            if (param_4 != '\0') {

              uVar3 = FUN_007a6de0(puVar4 + 0x61,0xffffffff);

              sprintf(local_608,"%s\n",uVar3);

              (**(code **)(*unaff_EBX + 0x224))(local_608,0xff20ff20);

                    /* WARNING: Subroutine does not return */

              operator_delete(puVar4);

            }

            if ((param_3 == '\0') && (puVar4[0x17c] != 0)) {

              pcVar5 = (char *)&local_408;

              local_408 = local_408 & 0xff00;

              do {

                cVar1 = *pcVar5;

                pcVar5 = pcVar5 + 1;

              } while (cVar1 != '\0');

              iVar2 = (**(code **)(*(int *)puVar4[0x17c] + 0x30))

                                (&local_408,(int)pcVar5 - ((int)&local_408 + 1),puVar4,0);

              *param_2 = *param_2 + iVar2;

            }

            else {

              uVar3 = FUN_007a6de0(puVar4 + 0x61,0xffffffff);

              sprintf(local_608,"%s\n",uVar3);

              pcVar5 = (char *)&local_408;

              do {

                cVar1 = *pcVar5;

                pcVar5 = pcVar5 + 1;

              } while (cVar1 != '\0');

              iVar2 = FUN_005506a0(&local_408,(int)pcVar5 - ((int)&local_408 + 1));

              *param_2 = *param_2 + iVar2;

              (**(code **)(*unaff_EBX + 0x224))(local_608,0xff20ff20);

            }

            pcVar5 = acStack_418;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            if (pcVar5 != acStack_418 + 1) {

              (**(code **)(*unaff_EBX + 0x250))(acStack_418);

              (**(code **)(*unaff_EBX + 0x250))(&DAT_00a15104);

              *param_2 = *param_2 + 1;

              acStack_418[0] = '\0';

            }

                    /* WARNING: Subroutine does not return */

            operator_delete(puVar4);

          }

        }

        local_620 = local_620 + 1;

      } while (local_620 < 3);

    }

  }

  return;

}
