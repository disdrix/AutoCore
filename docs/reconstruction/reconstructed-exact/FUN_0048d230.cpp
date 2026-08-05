// =============================================================================
// FUN_0048d230
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d230
// Address:   0x0048d230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d230 @ 0x0048d230
// Stable ID: aa_0048d230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×13, return×9, while×3, goto×1, do×1.
//  - Notable callees: strchr×2, FUN_0048cb80, FUN_0048d230, strncmp.
//  - Return sites: 9.

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

char * FUN_0048d230(char *param_1,char *param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined **ppuVar6;

  int iVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a06d8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  cVar1 = param_1[1];

  if ((cVar1 != '\0') && (cVar1 == '#')) {

    if (param_1[2] != '\0') {

      iVar4 = 0;

      iVar5 = 1;

      if (param_1[2] == 'x') {

        if (((param_1[3] != '\0') && (pcVar2 = strchr(param_1 + 3,0x3b), pcVar2 != (char *)0x0)) &&

           (*pcVar2 != '\0')) {

          iVar7 = (int)pcVar2 - (int)param_1;

          cVar1 = pcVar2[-1];

          while (cVar1 != 'x') {

            if ((cVar1 < '0') || ('9' < cVar1)) {

              if ((cVar1 < 'a') || ('f' < cVar1)) {

                if (cVar1 < 'A') {

                  ExceptionList = local_c;

                  return (char *)0x0;

                }

                if ('F' < cVar1) {

                  ExceptionList = local_c;

                  return (char *)0x0;

                }

                iVar3 = cVar1 + -0x37;

              }

              else {

                iVar3 = cVar1 + -0x57;

              }

            }

            else {

              iVar3 = cVar1 + -0x30;

            }

            iVar4 = iVar4 + iVar3 * iVar5;

            iVar5 = iVar5 << 4;

            cVar1 = pcVar2[-2];

            pcVar2 = pcVar2 + -1;

          }

LAB_0048d313:

          if (param_4 == 1) {

            FUN_0048cb80(iVar4,param_2,param_3);

            ExceptionList = local_c;

            return param_1 + iVar7 + 1;

          }

          *param_2 = (char)iVar4;

          *param_3 = 1;

          ExceptionList = local_c;

          return param_1 + iVar7 + 1;

        }

      }

      else {

        pcVar2 = strchr(param_1 + 2,0x3b);

        if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {

          iVar7 = (int)pcVar2 - (int)param_1;

          cVar1 = pcVar2[-1];

          while (cVar1 != '#') {

            if (cVar1 < '0') {

              ExceptionList = local_c;

              return (char *)0x0;

            }

            if ('9' < cVar1) {

              ExceptionList = local_c;

              return (char *)0x0;

            }

            iVar4 = iVar4 + (cVar1 + -0x30) * iVar5;

            iVar5 = iVar5 * 10;

            cVar1 = pcVar2[-2];

            pcVar2 = pcVar2 + -1;

          }

          goto LAB_0048d313;

        }

      }

      ExceptionList = local_c;

      return (char *)0x0;

    }

  }

  iVar4 = 0;

  ppuVar6 = &PTR_s__amp__00aef8cc;

  do {

    iVar5 = strncmp(*ppuVar6,param_1,(size_t)ppuVar6[1]);

    if (iVar5 == 0) {

      *param_2 = (&DAT_00aef8d4)[iVar4 * 0xc];

      *param_3 = 1;

      ExceptionList = local_c;

      return param_1 + (&DAT_00aef8d0)[iVar4 * 3];

    }

    ppuVar6 = ppuVar6 + 3;

    iVar4 = iVar4 + 1;

  } while ((int)ppuVar6 < 0xaef908);

  *param_2 = *param_1;

  ExceptionList = local_c;

  return param_1 + 1;

}
