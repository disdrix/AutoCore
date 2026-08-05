// =============================================================================
// FUN_0048ad40
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ad40
// Address:   0x0048ad40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ad40 @ 0x0048ad40
// Stable ID: aa_0048ad40
// Embedded strings (evidence for future rename):
//   - "&#x%02X;"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, goto×1, return×1.
//  - Notable callees: FUN_0048aa20×2, CONCAT31, FUN_0048ad40, _snprintf.
//  - Strings: "&#x%02X;".
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

void FUN_0048ad40(int *param_1)



{

  byte bVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  char *pcVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  int iVar10;

  char local_20 [32];

  

  piVar3 = param_1;

  piVar6 = (int *)*param_1;

  iVar7 = *piVar6;

  iVar8 = 0;

  if (0 < iVar7) {

    do {

      bVar1 = *(byte *)((int)piVar6 + iVar8 + 8);

      iVar4 = (int)piVar6 + iVar8 + 8;

      if (bVar1 == 0x26) {

        pcVar9 = PTR_s__amp__00aef8cc;

        iVar10 = DAT_00aef8d0;

        if (((iVar7 + -2 <= iVar8) || (*(char *)((int)piVar6 + iVar8 + 9) != '#')) ||

           (*(char *)((int)piVar6 + iVar8 + 10) != 'x')) goto LAB_0048ae5c;

        iVar10 = iVar8;

        if (iVar8 < iVar7 + -1) {

          do {

            FUN_0048aa20(iVar4,1);

            piVar6 = (int *)*piVar3;

            iVar8 = iVar10 + 1;

            iVar4 = (int)piVar6 + iVar10 + 9;

            if (*(char *)((int)piVar6 + iVar10 + 9) == ';') break;

            iVar10 = iVar8;

          } while (iVar8 < *piVar6 + -1);

        }

      }

      else {

        pcVar9 = PTR_DAT_00aef8d8;

        iVar10 = DAT_00aef8dc;

        if ((((bVar1 != 0x3c) && (pcVar9 = PTR_DAT_00aef8e4, iVar10 = DAT_00aef8e8, bVar1 != 0x3e))

            && (pcVar9 = PTR_s__quot__00aef8f0, iVar10 = DAT_00aef8f4, bVar1 != 0x22)) &&

           (pcVar9 = PTR_s__apos__00aef8fc, iVar10 = DAT_00aef900, bVar1 != 0x27)) {

          if (bVar1 < 0x20) {

            _snprintf(local_20,0x20,"&#x%02X;",(uint)bVar1);

            pcVar5 = local_20;

            do {

              cVar2 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar2 != '\0');

            pcVar9 = local_20;

            iVar10 = (int)pcVar5 - (int)(local_20 + 1);

          }

          else {

            param_1 = (int *)CONCAT31(param_1._1_3_,bVar1);

            iVar10 = 1;

            pcVar9 = (char *)&param_1;

          }

        }

LAB_0048ae5c:

        FUN_0048aa20(pcVar9,iVar10);

        iVar8 = iVar8 + 1;

      }

      piVar6 = (int *)*piVar3;

      iVar7 = *piVar6;

    } while (iVar8 < iVar7);

  }

  return;

}
