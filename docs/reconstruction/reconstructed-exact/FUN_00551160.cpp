// =============================================================================
// FUN_00551160
// -----------------------------------------------------------------------------
// Stable ID: aa_00551160
// Address:   0x00551160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00551160 @ 0x00551160
// Stable ID: aa_00551160
// Embedded strings (evidence for future rename):
//   - " Self,"
//   - " Ally,"
//   - " Convoy Member,"
//   - " Enemy,"
//   - " Minion,"
//   - " Ground,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~394 non-empty decompiler lines.
//  - Control keywords: do×30, while×30, for×26, if×16, return×1.
//  - Notable callees: FUN_007a6de0×18, sprintf×6, FUN_00412c60×4, FUN_00551160, FUN_007a69d0.
//  - Strings: " Self,"; " Ally,"; " Convoy Member,"; " Enemy,".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



char __thiscall FUN_00551160(int param_1,char *param_2)



{

  char cVar1;

  short sVar2;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint uVar8;

  char *pcVar9;

  int iVar10;

  char *pcVar11;

  float10 fVar12;

  char local_40d;

  uint32_t /* width from decompiler */ local_404;

  char local_400 [1024];

  

  FUN_007a69d0();

  local_40d = '\0';

  local_400[0] = '\0';

  if ((*(byte *)(param_1 + 0x614) & 2) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Self,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x614) & 4) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Ally,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x615) & 0x20) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Convoy Member,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x614) & 8) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Enemy,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x614) & 0x10) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Minion,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x614) & 0x20) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Ground,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x615) & 8) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Selection,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x615) & 4) != 0) {

    pcVar3 = (char *)FUN_007a6de0(" Remains,",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = (char *)((int)&local_404 + 3);

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  pcVar4 = local_400;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  local_404 = (int)pcVar4 - (int)(local_400 + 1);

  if (local_404 != 0) {

    pcVar3 = (char *)FUN_007a6de0("Targets",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = param_2 + -1;

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; pcVar4 = local_400, uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    uVar7 = (int)pcVar4 - (int)local_400;

    pcVar4 = param_2 + -1;

    do {

      pcVar3 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar3 != '\0');

    pcVar3 = local_400;

    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar7 = uVar7 & 3; pcVar11 = param_2, uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar4 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    }

    do {

      pcVar4 = pcVar11;

      pcVar11 = pcVar4 + 1;

    } while (*pcVar4 != '\0');

    pcVar4[-1] = '\n';

    local_40d = '\x01';

  }

  if ((*(byte *)(param_1 + 0x615) & 2) != 0) {

    pcVar3 = (char *)FUN_007a6de0("Maintained\n",0xffffffff);

    pcVar4 = pcVar3;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar11 = param_2 + -1;

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar3;

    for (uVar7 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar7 = (int)pcVar4 - (int)pcVar3 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  if ((*(byte *)(param_1 + 0x615) & 1) == 0) {

    sVar2 = *(short *)(param_1 + 8);

    if (sVar2 != 0) {

      uVar5 = FUN_007a6de0("Power",0xffffffff);

      sprintf(local_400,"%d %s\n",(int)sVar2,uVar5);

      pcVar4 = local_400;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar7 = (int)pcVar4 - (int)local_400;

      pcVar4 = param_2 + -1;

      do {

        pcVar3 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar3 != '\0');

      pcVar3 = local_400;

      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

        pcVar3 = pcVar3 + 4;

        pcVar4 = pcVar4 + 4;

      }

      local_40d = local_40d + '\x01';

      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

        *pcVar4 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      }

    }

    if (*(short *)(param_1 + 0x14) == 0) {

      uVar5 = FUN_007a6de0("Instant",0xffffffff);

      sprintf(local_400,"%s\n",uVar5);

    }

    else {

      iVar10 = (int)*(short *)(param_1 + 0x14);

      uVar5 = FUN_007a6de0("Charge",0xffffffff);

      if (iVar10 < 86400000) {

        if (iVar10 < 3600000) {

          if (iVar10 < 60000) {

            uVar5 = FUN_007a6de0();

            fVar12 = (float10)FUN_00412c60();

            sprintf(local_400,"%g %s %s\n",(double)fVar12,uVar5);

          }

          else {

            uVar5 = FUN_007a6de0();

            fVar12 = (float10)FUN_00412c60();

            sprintf(local_400,"%g %s %s\n",(double)fVar12,uVar5);

          }

        }

        else {

          uVar5 = FUN_007a6de0();

          fVar12 = (float10)FUN_00412c60();

          sprintf(local_400,"%g %s %s\n",(double)fVar12,uVar5);

        }

      }

      else {

        uVar6 = FUN_007a6de0();

        fVar12 = (float10)FUN_00412c60();

        sprintf(local_400,"%g %s %s\n",(double)fVar12,uVar6,uVar5);

      }

    }

    pcVar4 = local_400;

    pcVar3 = pcVar4;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar7 = (int)pcVar3 - (int)pcVar4;

    param_2 = param_2 + -1;

    do {

      pcVar3 = param_2 + 1;

      param_2 = param_2 + 1;

    } while (*pcVar3 != '\0');

  }

  else {

    pcVar4 = (char *)FUN_007a6de0("Passive\n",0xffffffff);

    pcVar3 = pcVar4;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar7 = (int)pcVar3 - (int)pcVar4;

    param_2 = param_2 + -1;

    do {

      pcVar3 = param_2 + 1;

      param_2 = param_2 + 1;

    } while (*pcVar3 != '\0');

  }

  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)param_2 = *(uint32_t /* width from decompiler */ *)pcVar4;

    pcVar4 = pcVar4 + 4;

    param_2 = param_2 + 4;

  }

  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *param_2 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    param_2 = param_2 + 1;

  }

  return local_40d + '\x01';

}
