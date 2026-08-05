// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004a9800
// -----------------------------------------------------------------------------
// Stable ID: aa_004a9800
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004a9800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: do×13, while×13, for×6, if×4, return×3.
//  - Notable callees: FUN_004a8c80, FUN_004a9800.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004a9800(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,char *param_4)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  char local_40 [64];

  

  *param_4 = '\0';

  FUN_004a8c80(param_3,local_40);

  pcVar3 = local_40;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if ((pcVar3 != local_40 + 1) &&

     (pcVar3 = *(char **)(*(int *)(*(int *)(param_1 + 0x340) + 0xe4f8) + 0x334),

     pcVar3 != (char *)0x0)) {

    pcVar6 = param_4;

    if (param_2 == 0) {

      do {

        cVar1 = *pcVar3;

        *pcVar6 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      pcVar3 = param_4 + -1;

      do {

        pcVar6 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar6 != '\0');

      *(uint16_t *)pcVar3 = DAT_009caf60;

      pcVar3 = local_40;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)local_40;

      pcVar3 = param_4 + -1;

      do {

        pcVar6 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar6 != '\0');

      pcVar6 = local_40;

      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; pcVar2 = param_4 + -1, uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        pcVar3 = pcVar3 + 1;

      }

      do {

        pcVar3 = pcVar2;

        pcVar2 = pcVar3 + 1;

      } while (pcVar3[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar3 + 1) = s__skybox_dds_009caf48._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar3 + 5) = s__skybox_dds_009caf48._4_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar3 + 9) = s__skybox_dds_009caf48._8_4_;

    }

    else {

      if (param_2 == 1) {

        *(uint32_t /* width from decompiler */ *)param_4 = DAT_009caf64;

        *(uint32_t /* width from decompiler */ *)(param_4 + 4) = DAT_009caf68;

        param_4[8] = DAT_009caf6c;

        pcVar3 = local_40;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uVar4 = (int)pcVar3 - (int)local_40;

        pcVar3 = param_4 + -1;

        do {

          pcVar6 = pcVar3 + 1;

          pcVar3 = pcVar3 + 1;

        } while (*pcVar6 != '\0');

        pcVar6 = local_40;

        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar3 = pcVar3 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar3 = pcVar3 + 1;

        }

        pcVar3 = param_4 + -1;

        do {

          pcVar6 = pcVar3 + 1;

          pcVar3 = pcVar3 + 1;

        } while (*pcVar6 != '\0');

        *(uint16_t *)pcVar3 = DAT_009caf60;

        pcVar3 = param_4 + -1;

        do {

          pcVar6 = pcVar3;

          pcVar3 = pcVar6 + 1;

        } while (pcVar6[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s_clouds_dds_009caf54._0_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s_clouds_dds_009caf54._4_4_;

        *(uint16_t *)(pcVar6 + 9) = s_clouds_dds_009caf54._8_2_;

        pcVar6[0xb] = s_clouds_dds_009caf54[10];

        return;

      }

      if (param_2 == 2) {

        *(uint32_t /* width from decompiler */ *)param_4 = DAT_009caf70;

        param_4[4] = DAT_009caf74;

        pcVar3 = local_40;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uVar4 = (int)pcVar3 - (int)local_40;

        pcVar3 = param_4 + -1;

        do {

          pcVar6 = pcVar3 + 1;

          pcVar3 = pcVar3 + 1;

        } while (*pcVar6 != '\0');

        pcVar6 = local_40;

        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar3 = pcVar3 + 4;

        }

        for (uVar4 = uVar4 & 3; pcVar2 = param_4 + -1, uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar3 = pcVar3 + 1;

        }

        do {

          pcVar3 = pcVar2;

          pcVar2 = pcVar3 + 1;

        } while (pcVar3[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar3 + 1) = DAT_00a2c53c;

        pcVar3[5] = DAT_00a2c540;

        return;

      }

    }

  }

  return;

}
