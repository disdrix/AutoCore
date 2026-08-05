// =============================================================================
// FUN_007a7630
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7630
// Address:   0x007a7630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a7630 @ 0x007a7630
// Stable ID: aa_007a7630
// Embedded strings (evidence for future rename):
//   - "[$/l]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, goto×1, for×1, return×1.
//  - Notable callees: FUN_007a7630, _strnicmp, sscanf, strncmp.
//  - Strings: "[$/l]".
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

void __thiscall FUN_007a7630(int *param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (param_2 != (char *)0x0) {

    pcVar3 = param_2;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    local_14 = (int)pcVar3 - (int)(param_2 + 1);

    pcVar3 = operator_new__(local_14 + 1);

    iVar5 = 0;

    iVar6 = 0;

    if (*param_2 != '\0') {

      do {

        if ((param_2[iVar5] == '[') && (param_2[iVar5 + 1] == '$')) {

          if (0 < iVar6) {

            pcVar3[iVar6] = '\0';

            (**(code **)(*param_1 + 0x250))(pcVar3);

            iVar6 = 0;

          }

          iVar4 = _strnicmp(param_2 + iVar5,&DAT_00a96c30,4);

          if (iVar4 != 0) {

            pcVar3[iVar6] = param_2[iVar5];

            goto LAB_007a77b2;

          }

          do {

            pcVar1 = param_2 + iVar5;

            pcVar3[iVar6] = param_2[iVar5];

            iVar6 = iVar6 + 1;

            iVar5 = iVar5 + 1;

          } while (*pcVar1 != ']');

          local_18 = 0;

          local_8 = 0;

          local_4 = 0;

          local_10 = 0;

          local_c = 0;

          pcVar3[iVar6] = '\0';

          iVar4 = sscanf(pcVar3,&DAT_00a96c40,&local_18,&local_8,&local_10);

          if (iVar4 == 3) {

            iVar6 = 0;

            for (; (((param_2[iVar5] != '[' || (param_2[iVar5 + 1] != '$')) ||

                    (iVar4 = strncmp(param_2 + iVar5,"[$/l]",5), iVar4 != 0)) &&

                   (iVar5 < local_14 + -1)); iVar5 = iVar5 + 1) {

              pcVar3[iVar6] = param_2[iVar5];

              iVar6 = iVar6 + 1;

            }

            pcVar3[iVar6] = '\0';

            iVar5 = iVar5 + 5;

            (**(code **)(*param_1 + 0x27c))

                      (param_1,local_18,local_8,local_4,local_10,local_c,pcVar3);

            iVar6 = 0;

          }

        }

        else {

          pcVar3[iVar6] = param_2[iVar5];

LAB_007a77b2:

          iVar6 = iVar6 + 1;

          iVar5 = iVar5 + 1;

        }

      } while (param_2[iVar5] != '\0');

      if (iVar6 != 0) {

        pcVar3[iVar6] = '\0';

        (**(code **)(*param_1 + 0x250))(pcVar3);

      }

    }

    if (pcVar3 != (char *)0x0) {

      operator_delete__(pcVar3);

    }

  }

  return;

}
