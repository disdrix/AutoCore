// =============================================================================
// FUN_00938380
// -----------------------------------------------------------------------------
// Stable ID: aa_00938380
// Address:   0x00938380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00938380 @ 0x00938380
// Stable ID: aa_00938380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×1, while×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×21, FUN_00597eb0×4, FUN_004f5560×2, FUN_00727440×2, FUN_00938380.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_00938380(int param_1)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  float local_4;

  

  iVar2 = param_1;

  if (*(char *)(param_1 + 0x9e6) != '\0') {

    if (((*(int *)(param_1 + 0xe04) == 0) || (*(int *)(*(int *)(param_1 + 0xe04) + 0xe4e8) == 0)) ||

       (*(int *)(param_1 + 0xe98) == 0)) {

      uVar10 = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x30);

      uVar7 = 0;

      uVar8 = Client_GetMissionCompleteAudioTable(0,uVar10);

      FUN_00727440(uVar8,uVar7,uVar10);

      return 0;

    }

    uVar10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x508);

    uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c);

    iVar4 = Client_GetMissionCompleteAudioTable();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c0) = uVar10;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c4) = uVar8;

    iVar4 = Client_GetMissionCompleteAudioTable();

    *(uint8_t *)(iVar4 + 0x2f7) = 0;

    iVar4 = Client_GetMissionCompleteAudioTable();

    *(uint8_t *)(iVar4 + 0x2f9) = 0;

    piVar1 = (int *)(param_1 + 0xe98);

    param_1._0_1_ = 0;

    if (*piVar1 != 0) {

      iVar4 = *(int *)(*piVar1 + 0x250);

      if (((iVar4 == 0) || (*(int **)(iVar4 + 0x1a0) == (int *)0x0)) ||

         ((**(int **)(iVar4 + 0x1a0) == 0 || (iVar5 = FUN_00597eb0(), iVar5 == 0)))) {

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x302) = 1;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x301) = 0;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2fc) = 0;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x2f8) = 0;

      }

      else {

        local_4 = 0.0;

        iVar5 = 0;

        cVar3 = FUN_004f5560();

        if ('\0' < cVar3) {

          iVar9 = 0;

          param_1._0_1_ = 0;

          do {

            iVar6 = FUN_00597eb0();

            if (local_4 < *(float *)(*(int *)(*(int *)(iVar6 + 0xc) + 0x28) + iVar5 * 4)) {

              iVar6 = FUN_00597eb0();

              local_4 = *(float *)(*(int *)(*(int *)(iVar6 + 0xc) + 0x80) + 0x94 + iVar9);

            }

            if (*(char *)((char)iVar5 + 0xf4 + *(int *)(iVar4 + 600)) != '\0') {

              param_1._0_1_ = 1;

            }

            iVar5 = iVar5 + 1;

            iVar9 = iVar9 + 0xc0;

            cVar3 = FUN_004f5560();

          } while (iVar5 < cVar3);

        }

        iVar5 = FUN_00597eb0();

        cVar3 = *(char *)(*(int *)(iVar5 + 0x20) + 0x14);

        if (*(float *)(iVar4 + 0x614) == g_flZero) {

          iVar5 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar5 + 0x2f7) = 0;

        }

        else {

          iVar5 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar5 + 0x2f7) = 1;

          DAT_00d1f074 = 1;

          iVar5 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar5 + 0x2f8) = 0;

        }

        if ((*(float *)(iVar4 + 0x614) == g_flZero) && (DAT_00d1f074 != 0)) {

          iVar5 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar5 + 0x2f8) = 1;

          DAT_00d1f074 = 0;

          iVar5 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar5 + 0x2f7) = 0;

        }

        if (*(float *)(iVar4 + 0x138) <= DAT_00a110d8) {

          iVar4 = Client_GetMissionCompleteAudioTable();

          *(uint8_t *)(iVar4 + 0x2f8) = 0;

        }

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x302) = (uint8_t)param_1;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(bool *)(iVar4 + 0x301) = cVar3 != '\0';

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(float *)(iVar4 + 0x2fc) = local_4;

      }

      if (*(char *)(*(int *)(iVar2 + 0xe98) + 0x6b9) != '\0') {

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x302) = 0;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint8_t *)(iVar4 + 0x301) = 0;

        iVar4 = Client_GetMissionCompleteAudioTable();

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2fc) = 0;

      }

      uVar10 = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x30);

      uVar8 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0xe04) + 0xe4e8);

      uVar7 = Client_GetMissionCompleteAudioTable(uVar8,uVar10);

      FUN_00727440(uVar7,uVar8,uVar10);

    }

  }

  return 0;

}
