// =============================================================================
// FUN_00614380
// -----------------------------------------------------------------------------
// Stable ID: aa_00614380
// Address:   0x00614380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00614380 @ 0x00614380
// Stable ID: aa_00614380
// Embedded strings (evidence for future rename):
//   - "Killed"
//   - "%s: %d / %d"
//   - "UNDEFINED FACTION: %i"
//   - " [Vehicles]"
//   - " [Unknown]"
//   - " [Creatures]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~241 non-empty decompiler lines.
//  - Control keywords: if×15, do×14, while×14, for×5, goto×3, return×1.
//  - Notable callees: FUN_007a6de0×11, sprintf×6, free×2, FUN_00402d50, FUN_00403450, FUN_00404d70, FUN_004eb010, FUN_004f1e20.
//  - Strings: "Killed"; "%s: %d / %d"; "UNDEFINED FACTION: %i"; " [Vehicles]".
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

int __thiscall FUN_00614380(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,char *param_4,size_t param_5)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char *pcVar11;

  uint uVar12;

  uint32_t /* width from decompiler */ *puVar13;

  bool bVar14;

  uint8_t local_520 [4];

  uint8_t *local_51c;

  uint8_t local_518 [127];

  char cStack_499;

  char local_498 [128];

  char local_418 [127];

  char local_399;

  char local_398 [511];

  uint8_t local_199;

  uint32_t /* width from decompiler */ local_198 [61];

  uint8_t auStack_a2 [142];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a8615;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  FUN_007a69d0();

  local_199 = 0;

  local_399 = '\0';

  if (*(char *)(param_1 + 0x10) == '\0') {

    if (*(char *)(param_1 + 0x11) == '\0') {

      if (*(char *)(param_1 + 0x12) == '\0') {

        iVar3 = FUN_00404d70(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

        if (iVar3 == 0) {

          uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

          iVar3 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

          uVar7 = FUN_007a6de0("Killed",0xffffffff);

          sprintf(local_398,"%s: %d / %d",uVar7,iVar3,uVar6);

        }

        else {

          bVar14 = *(int *)(iVar3 + 0x3c) == 0;

          if (bVar14) {

            FUN_004f1e20(0,1);

          }

          puVar10 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(iVar3 + 0x3c) + 0x92);

          uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

          iVar3 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

          uStack_c = 1;

          uVar7 = FUN_007a6de0(*puVar10,0xffffffff);

          sprintf(local_398,"%s: %d / %d",uVar7,iVar3,uVar6);

          uStack_c = 0xffffffff;

          if (local_51c != local_518) {

            free(local_51c);

          }

          if (bVar14) {

            FUN_004eb010();

          }

        }

      }

      else {

        piVar5 = (int *)FUN_0051c0e0(local_520,param_1 + 0x14);

        puVar10 = (uint32_t /* width from decompiler */ *)(*piVar5 + 0x10);

        puVar13 = local_198;

        for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar13 = *puVar10;

          puVar10 = puVar10 + 1;

          puVar13 = puVar13 + 1;

        }

        local_51c = local_518;

        uVar6 = (*(code *)PTR_FUN_00af8c9c)();

        FUN_00403450(auStack_a2,uVar6);

        uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

        iVar3 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

        uStack_c = 0;

        uVar7 = FUN_007a6de0(local_51c,0xffffffff);

        sprintf(local_398,"%s: %d / %d",uVar7,iVar3,uVar6);

        uStack_c = 0xffffffff;

        if (local_51c != local_518) {

          free(local_51c);

        }

      }

      goto LAB_006144af;

    }

    piVar5 = (int *)FUN_0051a120(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    if (piVar5 == (int *)0x0) {

      sprintf(local_498,"UNDEFINED FACTION: %i",*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    }

    else {

      pcVar11 = (char *)FUN_007a6de0(piVar5 + 1,0xffffffff);

      pcVar4 = local_498;

      do {

        cVar2 = *pcVar11;

        *pcVar4 = cVar2;

        pcVar11 = pcVar11 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

    }

    iVar3 = *(int *)(param_1 + 0x24);

    if (iVar3 == 0xe) {

      pcVar11 = (char *)FUN_007a6de0(" [Vehicles]",0xffffffff);

      pcVar4 = pcVar11;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      uVar9 = (int)pcVar4 - (int)pcVar11;

      pcVar4 = &cStack_499;

      do {

        pcVar1 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar1 != '\0');

LAB_006147e0:

      for (uVar12 = uVar9 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *pcVar4 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar4 = pcVar4 + 1;

      }

    }

    else {

      if (iVar3 == 0x12) {

        if (piVar5 == (int *)0x0) {

          pcVar11 = (char *)FUN_007a6de0(" [Unknown]",0xffffffff);

          pcVar4 = pcVar11;

          do {

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          uVar9 = (int)pcVar4 - (int)pcVar11;

          pcVar4 = &cStack_499;

          do {

            pcVar1 = pcVar4 + 1;

            pcVar4 = pcVar4 + 1;

          } while (*pcVar1 != '\0');

        }

        else if ((*piVar5 == 9) || (*piVar5 == 10)) {

          pcVar11 = (char *)FUN_007a6de0(" [Creatures]",0xffffffff);

          pcVar4 = pcVar11;

          do {

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          uVar9 = (int)pcVar4 - (int)pcVar11;

          pcVar4 = &cStack_499;

          do {

            pcVar1 = pcVar4 + 1;

            pcVar4 = pcVar4 + 1;

          } while (*pcVar1 != '\0');

        }

        else {

          pcVar11 = (char *)FUN_007a6de0(" [Infantry]",0xffffffff);

          pcVar4 = pcVar11;

          do {

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          uVar9 = (int)pcVar4 - (int)pcVar11;

          pcVar4 = &cStack_499;

          do {

            pcVar1 = pcVar4 + 1;

            pcVar4 = pcVar4 + 1;

          } while (*pcVar1 != '\0');

        }

        goto LAB_006147e0;

      }

      if (iVar3 == 0x14) {

        pcVar11 = (char *)FUN_007a6de0(" [Characters]",0xffffffff);

        pcVar4 = pcVar11;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        uVar9 = (int)pcVar4 - (int)pcVar11;

        pcVar4 = &cStack_499;

        do {

          pcVar1 = pcVar4 + 1;

          pcVar4 = pcVar4 + 1;

        } while (*pcVar1 != '\0');

        goto LAB_006147e0;

      }

    }

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    iVar3 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

    pcVar4 = local_498;

  }

  else {

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    iVar3 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);

    pcVar4 = (char *)FUN_007a6de0("Players",0xffffffff);

  }

  sprintf(local_398,"%s: %d / %d",pcVar4,iVar3,uVar6);

LAB_006144af:

  if (*(char *)(param_1 + 0x2c) != '\0') {

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

    uVar8 = FUN_007a6de0("Level",0xffffffff);

    sprintf(local_418," %s: %d-%d",uVar8,uVar7,uVar6);

    pcVar4 = local_418;

    do {

      cVar2 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    uVar9 = (int)pcVar4 - (int)local_418;

    pcVar4 = &local_399;

    do {

      pcVar11 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar11 != '\0');

    pcVar11 = local_418;

    for (uVar12 = uVar9 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar11;

      pcVar11 = pcVar11 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

      *pcVar4 = *pcVar11;

      pcVar11 = pcVar11 + 1;

      pcVar4 = pcVar4 + 1;

    }

  }

  strncat(param_4,local_398,param_5);

  pcVar4 = local_398;

  do {

    cVar2 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  ExceptionList = local_14;

  return (int)pcVar4 - (int)(local_398 + 1);

}
