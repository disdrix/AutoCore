// READABILITY (auto CF):
//  - Body size: ~226 non-empty decompiler lines.
//  - Control keywords: do×16, while×16, if×14, for×5, goto×2, return×2, switch×1.
//  - Notable callees: FUN_007a69d0×3, fclose×2, fopen×2, strstr×2, CreateFileA, FUN_007669d0, FUN_0076cec0, FormatMessageA.
//  - Strings: ".ogg"; ".dds"; "File open error <%s> - %s"; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_stoFileOSFile_007669d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007669d0
// Address:   0x007669d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoFileOSFile"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_stoFileOSFile_007669d0(int param_1,LPCSTR param_2,uint32_t /* width from decompiler */ param_3,DWORD param_4)



{

  char cVar1;

  uint8_t uVar2;

  int iVar3;

  char *pcVar4;

  FILE *pFVar5;

  char *pcVar6;

  char *pcVar7;

  DWORD DVar8;

  HANDLE pvVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint uVar11;

  DWORD dwCreationDisposition;

  undefined **ppuVar12;

  code *pcVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ *puVar15;

  uint32_t /* width from decompiler */ *puVar16;

  int local_204;

  CHAR local_200 [2];

  uint32_t /* width from decompiler */ local_1fe [127];

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = param_3;

  local_204 = param_1;

  iVar3 = FUN_007a69d0();

  pcVar13 = strstr_exref;

  if (*(int *)(iVar3 + 0x2c) != 0) {

    puVar15 = &DAT_00d206c8;

    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar15 = 0;

      puVar15 = puVar15 + 1;

    }

    pcVar4 = strstr(param_2,".ogg");

    if (pcVar4 == (char *)0x0) {

      pcVar4 = strstr(param_2,".dds");

      if (pcVar4 != (char *)0x0) {

        puVar15 = &DAT_00d206c8;

        for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar15 = 0;

          puVar15 = puVar15 + 1;

        }

        ppuVar12 = &PTR_DAT_00b01838;

        do {

          iVar3 = (*pcVar13)(param_2,*ppuVar12);

          if (iVar3 != 0) {

            pcVar4 = param_2;

            do {

              cVar1 = *pcVar4;

              pcVar4[(int)&DAT_00d206c8 - (int)param_2] = cVar1;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            pcVar4 = param_2;

            do {

              cVar1 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            pcVar6 = *ppuVar12;

            pcVar7 = pcVar6 + 1;

            do {

              cVar1 = *pcVar6;

              pcVar6 = pcVar6 + 1;

            } while (cVar1 != '\0');

            (&DAT_00d206c4)[(int)(pcVar4 + (-((int)pcVar6 - (int)pcVar7) - (int)(param_2 + 1)))] = 0

            ;

            iVar3 = FUN_007a69d0();

            iVar3 = *(int *)(iVar3 + 0x2c);

            if (iVar3 == 1) {

              puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

              do {

                pcVar4 = (char *)((int)puVar15 + 1);

                puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

              } while (*pcVar4 != '\0');

              *puVar15 = DAT_00a9d99c;

            }

            else if (iVar3 == 2) {

              puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

              do {

                pcVar4 = (char *)((int)puVar15 + 1);

                puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

              } while (*pcVar4 != '\0');

              *puVar15 = DAT_00a9d998;

            }

            else if (iVar3 == 3) {

              puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

              do {

                pcVar4 = (char *)((int)puVar15 + 1);

                puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

              } while (*pcVar4 != '\0');

              *puVar15 = DAT_00a9d9a0;

            }

            pcVar4 = *ppuVar12;

            pcVar7 = pcVar4;

            do {

              cVar1 = *pcVar7;

              pcVar7 = pcVar7 + 1;

            } while (cVar1 != '\0');

            pcVar6 = (char *)0xd206c7;

            do {

              pcVar14 = pcVar6 + 1;

              pcVar6 = pcVar6 + 1;

            } while (*pcVar14 != '\0');

            pcVar14 = pcVar4;

            for (uVar11 = (uint)((int)pcVar7 - (int)pcVar4) >> 2; uVar11 != 0; uVar11 = uVar11 - 1)

            {

              *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar14;

              pcVar14 = pcVar14 + 4;

              pcVar6 = pcVar6 + 4;

            }

            for (uVar11 = (int)pcVar7 - (int)pcVar4 & 3; uVar2 = DAT_00a2c540, uVar11 != 0;

                uVar11 = uVar11 - 1) {

              *pcVar6 = *pcVar14;

              pcVar14 = pcVar14 + 1;

              pcVar6 = pcVar6 + 1;

            }

            puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

            do {

              puVar16 = puVar15;

              puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar16 + 1);

            } while (*(char *)((int)puVar16 + 1) != '\0');

            *(uint32_t /* width from decompiler */ *)((int)puVar16 + 1) = DAT_00a2c53c;

            *(uint8_t *)((int)puVar16 + 5) = uVar2;

            pFVar5 = fopen((char *)&DAT_00d206c8,"rb");

            if (pFVar5 != (FILE *)0x0) {

              fclose(pFVar5);

              goto LAB_00766cb3;

            }

          }

          ppuVar12 = ppuVar12 + 1;

          pcVar13 = strstr_exref;

        } while ((int)ppuVar12 < 0xb0184c);

      }

    }

    else {

      pcVar4 = param_2;

      do {

        cVar1 = *pcVar4;

        pcVar4[(int)&DAT_00d206c8 - (int)param_2] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      pcVar4 = param_2;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      (&DAT_00d206c4)[(int)pcVar4 - (int)(param_2 + 1)] = 0;

      iVar3 = FUN_007a69d0();

      iVar3 = *(int *)(iVar3 + 0x2c);

      if (iVar3 == 1) {

        puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

        do {

          pcVar4 = (char *)((int)puVar15 + 1);

          puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

        } while (*pcVar4 != '\0');

        *puVar15 = DAT_00a9d99c;

      }

      else if (iVar3 == 2) {

        puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

        do {

          pcVar4 = (char *)((int)puVar15 + 1);

          puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

        } while (*pcVar4 != '\0');

        *puVar15 = DAT_00a9d998;

      }

      else if (iVar3 == 3) {

        puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

        do {

          pcVar4 = (char *)((int)puVar15 + 1);

          puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

        } while (*pcVar4 != '\0');

        *puVar15 = DAT_00a9d9a0;

      }

      uVar2 = DAT_00a9d9a8;

      puVar15 = (uint32_t /* width from decompiler */ *)0xd206c7;

      do {

        puVar16 = puVar15;

        puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar16 + 1);

      } while (*(char *)((int)puVar16 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar16 + 1) = DAT_00a9d9a4;

      *(uint8_t *)((int)puVar16 + 5) = uVar2;

      pFVar5 = fopen((char *)&DAT_00d206c8,"rb");

      if (pFVar5 != (FILE *)0x0) {

        fclose(pFVar5);

LAB_00766cb3:

        param_2 = (LPCSTR)&DAT_00d206c8;

      }

    }

  }

  DVar8 = 0;

  dwCreationDisposition = 3;

  switch(param_3) {

  case 0:

    goto switchD_00766cc9_caseD_0;

  case 1:

    DVar8 = 0x20001;

    break;

  case 3:

    DVar8 = 0x20007;

    break;

  case 6:

    dwCreationDisposition = 2;

  case 2:

    DVar8 = 0x20006;

  }

  pvVar9 = CreateFileA(param_2,DVar8,1,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,param_4,

                       (HANDLE)0x0);

  *(HANDLE *)(local_204 + 8) = pvVar9;

  if (pvVar9 != (HANDLE)0xffffffff) {

    return 0;

  }

  DVar8 = GetLastError();

  local_200[0] = '\0';

  local_200[1] = '\0';

  puVar15 = local_1fe;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar15 = 0;

    puVar15 = puVar15 + 1;

  }

  *(uint16_t *)puVar15 = 0;

  DVar8 = FormatMessageA(0x1000,(LPCVOID)0x0,DVar8,0,local_200,0x200,(va_list *)0x0);

  if (DVar8 != 0) {

    uVar10 = FUN_0076cec0(&local_204,"File open error <%s> - %s",param_2,local_200);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",0xb9,2,uVar10);

  }

switchD_00766cc9_caseD_0:

  return 0xffffffff;

}
