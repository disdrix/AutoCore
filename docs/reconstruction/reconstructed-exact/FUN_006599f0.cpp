// =============================================================================
// FUN_006599f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006599f0
// Address:   0x006599f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006599f0 @ 0x006599f0
// Stable ID: aa_006599f0
// Embedded strings (evidence for future rename):
//   - "&amp"
//   - "\"quot"
//   - "\'apos"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, while×3, do×2, goto×1.
//  - Notable callees: FUN_00638060, FUN_006599f0, strncmp.
//  - Strings: "<lt"; ">gt"; "&amp"; "\"quot".
//  - Return sites: 4.

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

int FUN_006599f0(char *param_1,char *param_2,char param_3)



{

  char cVar1;

  size_t _MaxCount;

  int iVar2;

  char cVar3;

  char *_Str1;

  int iVar4;

  char **ppcVar5;

  char *pcVar6;

  char *local_20;

  char *local_18 [5];

  uint32_t /* width from decompiler */ local_4;

  

  local_20 = param_1;

  cVar3 = param_3;

  pcVar6 = param_1;

  if (*param_2 != '\0') {

    do {

      cVar1 = *param_2;

      _Str1 = param_2 + 1;

      param_2 = _Str1;

      if ((param_3 == '\0') ||

         (((((cVar1 != ' ' && (cVar1 != '\t')) && (cVar1 != '\n')) &&

           ((cVar1 != '\r' && (cVar1 != '(')))) && ((cVar1 != ')' && (cVar1 != ',')))))) {

        if (cVar1 != '&') {

          cVar3 = '\0';

          *pcVar6 = cVar1;

          goto LAB_00659b07;

        }

        cVar3 = *_Str1;

        while (cVar3 != ';') {

          if (cVar3 == '\0') {

            return -1;

          }

          pcVar6 = param_2 + 1;

          param_2 = param_2 + 1;

          cVar3 = *pcVar6;

        }

        param_2 = param_2 + 1;

        iVar4 = 0;

        ppcVar5 = local_18;

        local_18[0] = "<lt";

        local_18[1] = ">gt";

        local_18[2] = "&amp";

        local_18[3] = "\"quot";

        local_18[4] = "\'apos";

        local_4 = 0;

        do {

          cVar3 = **ppcVar5;

          pcVar6 = *ppcVar5 + 1;

          _MaxCount = FUN_00638060(pcVar6);

          iVar2 = strncmp(_Str1,pcVar6,_MaxCount);

          if (iVar2 == 0) {

            *local_20 = cVar3;

            local_20 = local_20 + 1;

            break;

          }

          ppcVar5 = ppcVar5 + 1;

          iVar4 = iVar4 + 1;

        } while (*ppcVar5 != (char *)0x0);

        if (local_18[iVar4] == (char *)0x0) {

          return -1;

        }

        cVar3 = '\0';

        pcVar6 = local_20;

      }

      else if (cVar3 == '\0') {

        *pcVar6 = ' ';

        cVar3 = '\x01';

LAB_00659b07:

        local_20 = pcVar6 + 1;

        pcVar6 = local_20;

      }

    } while (*param_2 != '\0');

    if ((pcVar6 != param_1) && (cVar3 != '\0')) {

      pcVar6[-1] = '\0';

      return (int)pcVar6 - (int)param_1;

    }

  }

  *pcVar6 = '\0';

  return (int)pcVar6 - (int)param_1;

}
