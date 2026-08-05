// =============================================================================
// FUN_00995f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00995f60
// Address:   0x00995f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00995f60 @ 0x00995f60
// Stable ID: aa_00995f60
// Embedded strings (evidence for future rename):
//   - ".ogg"
//   - ".dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~259 non-empty decompiler lines.
//  - Control keywords: if×24, do×16, while×16, return×5, for×4.
//  - Notable callees: FUN_00745d70×3, FUN_007a69d0×3, FUN_00983d40×3, strstr×3, FUN_00989e00×2, FUN_00995f60.
//  - Strings: ".ogg"; ".dds".
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ * __thiscall

FUN_00995f60(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  uint8_t uVar2;

  undefined *puVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  uint uVar8;

  undefined **ppuVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint8_t auStack_14 [4];

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009afa95;

  pvStack_c = ExceptionList;

  local_10 = (uint32_t /* width from decompiler */ *)0x0;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 4) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    param_2 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 4))(&param_2,param_2);

  }

  pcVar6 = *(char **)param_2;

  param_2 = pcVar6;

  iVar4 = FUN_007a69d0();

  if (*(int *)(iVar4 + 0x2c) != 0) {

    puVar10 = &DAT_00d20a78;

    for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    pcVar5 = pcVar6;

    if (pcVar6 == (char *)0x0) {

      pcVar5 = PTR_DAT_00afa2bc;

    }

    pcVar5 = strstr(pcVar5,".ogg");

    puVar3 = PTR_DAT_00afa2bc;

    if (pcVar5 == (char *)0x0) {

      if (pcVar6 == (char *)0x0) {

        pcVar6 = PTR_DAT_00afa2bc;

      }

      pcVar6 = strstr(pcVar6,".dds");

      if (pcVar6 != (char *)0x0) {

        puVar10 = &DAT_00d20a78;

        for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar10 = 0;

          puVar10 = puVar10 + 1;

        }

        ppuVar9 = &PTR_DAT_00b02520;

        pcVar6 = param_2;

        do {

          pcVar5 = pcVar6;

          if (pcVar6 == (char *)0x0) {

            pcVar5 = PTR_DAT_00afa2bc;

          }

          pcVar5 = strstr(pcVar5,*ppuVar9);

          puVar3 = PTR_DAT_00afa2bc;

          if (pcVar5 != (char *)0x0) {

            pcVar6 = param_2;

            if (param_2 == (char *)0x0) {

              pcVar6 = PTR_DAT_00afa2bc;

            }

            iVar4 = (int)&DAT_00d20a78 - (int)pcVar6;

            do {

              cVar1 = *pcVar6;

              pcVar6[iVar4] = cVar1;

              pcVar6 = pcVar6 + 1;

            } while (cVar1 != '\0');

            pcVar6 = param_2;

            if (param_2 == (char *)0x0) {

              pcVar6 = puVar3;

            }

            pcVar5 = pcVar6 + 1;

            do {

              cVar1 = *pcVar6;

              pcVar6 = pcVar6 + 1;

            } while (cVar1 != '\0');

            pcVar7 = *ppuVar9;

            pcVar11 = pcVar7 + 1;

            do {

              cVar1 = *pcVar7;

              pcVar7 = pcVar7 + 1;

            } while (cVar1 != '\0');

            (&DAT_00d20a74)[(int)(pcVar6 + (-((int)pcVar7 - (int)pcVar11) - (int)pcVar5))] = 0;

            iVar4 = FUN_007a69d0();

            iVar4 = *(int *)(iVar4 + 0x2c);

            if (iVar4 == 1) {

              puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

              do {

                pcVar6 = (char *)((int)puVar10 + 1);

                puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

              } while (*pcVar6 != '\0');

              *puVar10 = DAT_00a9d99c;

            }

            else if (iVar4 == 2) {

              puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

              do {

                pcVar6 = (char *)((int)puVar10 + 1);

                puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

              } while (*pcVar6 != '\0');

              *puVar10 = DAT_00a9d998;

            }

            else if (iVar4 == 3) {

              puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

              do {

                pcVar6 = (char *)((int)puVar10 + 1);

                puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

              } while (*pcVar6 != '\0');

              *puVar10 = DAT_00a9d9a0;

            }

            pcVar6 = *ppuVar9;

            pcVar5 = pcVar6;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            pcVar11 = (char *)0xd20a77;

            do {

              pcVar7 = pcVar11 + 1;

              pcVar11 = pcVar11 + 1;

            } while (*pcVar7 != '\0');

            pcVar7 = pcVar6;

            for (uVar8 = (uint)((int)pcVar5 - (int)pcVar6) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

              *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar7;

              pcVar7 = pcVar7 + 4;

              pcVar11 = pcVar11 + 4;

            }

            for (uVar8 = (int)pcVar5 - (int)pcVar6 & 3; uVar2 = DAT_00a2c540, uVar8 != 0;

                uVar8 = uVar8 - 1) {

              *pcVar11 = *pcVar7;

              pcVar7 = pcVar7 + 1;

              pcVar11 = pcVar11 + 1;

            }

            puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

            do {

              puVar12 = puVar10;

              puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

            } while (*(char *)((int)puVar12 + 1) != '\0');

            *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a2c53c;

            *(uint8_t *)((int)puVar12 + 5) = uVar2;

            FUN_00989e00(auStack_14,&DAT_00d20a78);

            iVar4 = FUN_00983d40(param_1 + 8);

            pcVar6 = param_2;

            if (iVar4 != 0) {

              puVar10 = operator_new(0x40);

              uStack_4 = 1;

              if (puVar10 == (uint32_t /* width from decompiler */ *)0x0) {

                ExceptionList = pvStack_c;

                return (uint32_t /* width from decompiler */ *)0x0;

              }

              param_2 = (char *)puVar10;

              FUN_00745d70(puVar10,auStack_14,param_4);

              puVar10[0xf] = iVar4;

              *puVar10 = &PTR_FUN_00aa1f38;

              ExceptionList = pvStack_c;

              return puVar10;

            }

          }

          ppuVar9 = ppuVar9 + 1;

        } while ((int)ppuVar9 < 0xb02534);

      }

    }

    else {

      pcVar5 = pcVar6;

      if (pcVar6 == (char *)0x0) {

        pcVar5 = PTR_DAT_00afa2bc;

      }

      iVar4 = (int)&DAT_00d20a78 - (int)pcVar5;

      do {

        cVar1 = *pcVar5;

        pcVar5[iVar4] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      if (pcVar6 == (char *)0x0) {

        pcVar6 = puVar3;

      }

      pcVar5 = pcVar6 + 1;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      (&DAT_00d20a74)[(int)pcVar6 - (int)pcVar5] = 0;

      iVar4 = FUN_007a69d0();

      iVar4 = *(int *)(iVar4 + 0x2c);

      if (iVar4 == 1) {

        puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

        do {

          pcVar6 = (char *)((int)puVar10 + 1);

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

        } while (*pcVar6 != '\0');

        *puVar10 = DAT_00a9d99c;

      }

      else if (iVar4 == 2) {

        puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

        do {

          pcVar6 = (char *)((int)puVar10 + 1);

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

        } while (*pcVar6 != '\0');

        *puVar10 = DAT_00a9d998;

      }

      else if (iVar4 == 3) {

        puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

        do {

          pcVar6 = (char *)((int)puVar10 + 1);

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

        } while (*pcVar6 != '\0');

        *puVar10 = DAT_00a9d9a0;

      }

      uVar2 = DAT_00a9d9a8;

      puVar10 = (uint32_t /* width from decompiler */ *)0xd20a77;

      do {

        puVar12 = puVar10;

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

      } while (*(char *)((int)puVar12 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a9d9a4;

      *(uint8_t *)((int)puVar12 + 5) = uVar2;

      FUN_00989e00(auStack_14,&DAT_00d20a78);

      iVar4 = FUN_00983d40(param_1 + 8);

      if (iVar4 != 0) {

        puVar10 = operator_new(0x40);

        uStack_4 = 0;

        if (puVar10 == (uint32_t /* width from decompiler */ *)0x0) {

          ExceptionList = pvStack_c;

          return (uint32_t /* width from decompiler */ *)0x0;

        }

        param_2 = (char *)puVar10;

        FUN_00745d70(puVar10,auStack_14,param_4);

        puVar10[0xf] = iVar4;

        *puVar10 = &PTR_FUN_00aa1f38;

        ExceptionList = pvStack_c;

        return puVar10;

      }

    }

  }

  iVar4 = FUN_00983d40(param_1 + 8);

  if (iVar4 != 0) {

    puVar10 = operator_new(0x40);

    uStack_4 = 2;

    if (puVar10 == (uint32_t /* width from decompiler */ *)0x0) {

      local_10 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      local_10 = puVar10;

      FUN_00745d70(puVar10,&param_2,param_4);

      *puVar10 = &PTR_FUN_00aa1f38;

      puVar10[0xf] = iVar4;

      local_10 = puVar10;

    }

  }

  ExceptionList = pvStack_c;

  return local_10;

}
