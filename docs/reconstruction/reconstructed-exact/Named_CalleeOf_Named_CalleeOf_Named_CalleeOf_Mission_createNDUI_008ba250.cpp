// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008ba250
// -----------------------------------------------------------------------------
// Stable ID: aa_008ba250
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008ba250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×15, while×9, do×8, return×2, for×1, goto×1.
//  - Notable callees: FUN_008b96d0, FUN_008ba250, fclose, fgets, fopen, sscanf.
//  - Strings: "%d: ".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008ba250(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  void *pvVar6;

  int iVar7;

  FILE *_File;

  int iVar8;

  int local_300c;

  int local_3008;

  FILE *local_3004;

  char local_3000 [4096];

  char local_2000 [5];

  uint8_t local_1ffb;

  uint8_t local_1f01;

  char local_1000 [4092];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x8ba25a;

  if (param_2 != (char *)0x0) {

    local_3004 = fopen(param_2,"r");

    if (local_3004 == (FILE *)0x0) {

      FUN_008b96d0(param_1);

      return;

    }

    local_300c = -1;

    bVar1 = (byte)local_3004->_flag;

    _File = local_3004;

    while ((bVar1 & 0x10) == 0) {

      local_3000[0] = '\0';

      local_1000[0] = '\0';

      local_2000[0] = '\0';

      pcVar4 = fgets(local_1000,0xfff,_File);

      if ((((pcVar4 != (char *)0x0) && (local_1000[0] != '\0')) &&

          (iVar5 = sscanf(local_1000,"%d: ",&local_300c), iVar5 == 1)) &&

         ((-1 < local_300c + -1 && (local_300c + -1 < 0xf)))) {

        iVar5 = 0;

        do {

          pcVar4 = local_1000 + iVar5;

          if (*pcVar4 == '\0') break;

          iVar5 = iVar5 + 1;

        } while (*pcVar4 != ' ');

        pcVar4 = local_1000 + iVar5;

        iVar5 = -(int)pcVar4;

        do {

          cVar2 = *pcVar4;

          pcVar4[(int)(local_3000 + iVar5)] = cVar2;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        pcVar4 = local_3000;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        iVar5 = (int)pcVar4 - (int)(local_3000 + 1);

        if ((iVar5 != 0) && (local_3000[iVar5 + -1] == '\n')) {

          local_3000[iVar5 + -1] = '\0';

        }

        iVar5 = 0;

        _File = local_3004;

        cVar2 = local_3000[0];

        for (local_3008 = -1;

            ((local_3004 = _File, cVar2 != '\0' && (iVar5 < 0xffe)) && (local_3008 < 5));

            local_3008 = local_3008 + 1) {

          iVar7 = 0;

          if (local_3000[iVar5] != '\0') {

            iVar7 = 0;

            iVar8 = iVar5;

            do {

              iVar5 = iVar8;

              if (0xffd < iVar8) break;

              if (local_3000[iVar8] == ';') {

                iVar5 = iVar8 + 1;

                if (local_3000[iVar8 + 1] != ';') break;

LAB_008ba3df:

                local_2000[iVar7] = local_3000[iVar5];

                iVar7 = iVar7 + 1;

                iVar8 = iVar5;

              }

              else if (local_3000[iVar8] != -0x60) goto LAB_008ba3df;

              iVar5 = iVar8 + 1;

              iVar3 = iVar8 + 1;

              iVar8 = iVar5;

            } while (local_3000[iVar3] != '\0');

          }

          pcVar4 = local_2000;

          local_2000[iVar7] = '\0';

          if (local_3008 < 0) {

            do {

              cVar2 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar2 != '\0');

            iVar7 = (int)pcVar4 - (int)(local_2000 + 1);

            if (5 < iVar7) {

              local_1ffb = 0;

              iVar7 = 5;

            }

            if (*(void **)(&DAT_00d17784 + local_300c * 4) != (void *)0x0) {

              operator_delete__(*(void **)(&DAT_00d17784 + local_300c * 4));

            }

            *(uint32_t /* width from decompiler */ *)(&DAT_00d17784 + local_300c * 4) = 0;

            pvVar6 = operator_new__(iVar7 + 1);

            *(void **)(&DAT_00d17784 + local_300c * 4) = pvVar6;

            pcVar4 = local_2000;

            iVar7 = (int)pvVar6 - (int)pcVar4;

            do {

              cVar2 = *pcVar4;

              pcVar4[iVar7] = cVar2;

              pcVar4 = pcVar4 + 1;

            } while (cVar2 != '\0');

          }

          else {

            do {

              cVar2 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar2 != '\0');

            iVar7 = (int)pcVar4 - (int)(local_2000 + 1);

            if (0xff < iVar7) {

              local_1f01 = 0;

              iVar7 = 0xff;

            }

            if ((void *)(&DAT_00d177b4)[local_3008 + local_300c * 5] != (void *)0x0) {

              operator_delete__((void *)(&DAT_00d177b4)[local_3008 + local_300c * 5]);

            }

            (&DAT_00d177b4)[local_3008 + local_300c * 5] = 0;

            pvVar6 = operator_new__(iVar7 + 1);

            (&DAT_00d177b4)[local_300c * 5 + local_3008] = pvVar6;

            pcVar4 = local_2000;

            iVar7 = (int)pvVar6 - (int)pcVar4;

            do {

              cVar2 = *pcVar4;

              pcVar4[iVar7] = cVar2;

              pcVar4 = pcVar4 + 1;

            } while (cVar2 != '\0');

          }

          cVar2 = local_3000[iVar5];

          _File = local_3004;

        }

      }

      bVar1 = (byte)_File->_flag;

    }

    fclose(_File);

  }

  return;

}
