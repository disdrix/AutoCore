// =============================================================================
// FUN_0048cca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048cca0
// Address:   0x0048cca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048cca0 @ 0x0048cca0
// Stable ID: aa_0048cca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×12, goto×11, switch×1, return×1.
//  - Notable callees: FUN_0048cca0.
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

void __thiscall FUN_0048cca0(int *param_1,byte *param_2,int param_3)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  byte *pbVar4;

  int iVar5;

  int iVar6;

  byte *pbVar7;

  int iVar8;

  

  iVar3 = param_1[3];

  if (0 < iVar3) {

    iVar5 = param_1[1];

    iVar8 = *param_1;

    pbVar7 = (byte *)param_1[2];

joined_r0x0048ccbe:

    pbVar4 = pbVar7;

    if (pbVar4 < param_2) {

      switch((uint)*pbVar4) {

      case 0:

        goto switchD_0048cce6_caseD_0;

      default:

        if (param_3 == 1) {

          iVar6 = *(int *)(&DAT_009c7030 + (uint)*pbVar4 * 4);

          if (iVar6 == 0) {

            iVar6 = 1;

          }

          pbVar7 = pbVar4 + iVar6;

        }

        else {

LAB_0048cd7d:

          pbVar7 = pbVar4 + 1;

        }

        goto LAB_0048cd7e;

      case 9:

        iVar5 = (iVar5 / iVar3 + 1) * iVar3;

        pbVar7 = pbVar4 + 1;

        goto joined_r0x0048ccbe;

      case 10:

        iVar8 = iVar8 + 1;

        iVar5 = 0;

        pbVar7 = pbVar4 + 1;

        if (pbVar4[1] == 0xd) {

          pbVar7 = pbVar4 + 2;

        }

        goto joined_r0x0048ccbe;

      case 0xd:

        iVar8 = iVar8 + 1;

        iVar5 = 0;

        pbVar7 = pbVar4 + 1;

        if (pbVar4[1] == 10) {

          pbVar7 = pbVar4 + 2;

        }

        goto joined_r0x0048ccbe;

      case 0xef:

        goto switchD_0048cce6_caseD_ef;

      }

    }

    *param_1 = iVar8;

    param_1[1] = iVar5;

    param_1[2] = (int)pbVar4;

switchD_0048cce6_caseD_0:

  }

  return;

switchD_0048cce6_caseD_ef:

  if (param_3 != 1) goto LAB_0048cd7d;

  bVar1 = pbVar4[1];

  pbVar7 = pbVar4;

  if ((bVar1 != 0) && (bVar2 = pbVar4[2], bVar2 != 0)) {

    if ((bVar1 == 0xbb) && (bVar2 == 0xbf)) {

      pbVar7 = pbVar4 + 3;

      goto joined_r0x0048ccbe;

    }

    if (bVar1 == 0xbf) {

      if (bVar2 == 0xbe) {

        pbVar7 = pbVar4 + 3;

        goto joined_r0x0048ccbe;

      }

      if (bVar2 == 0xbf) {

        pbVar7 = pbVar4 + 3;

        goto joined_r0x0048ccbe;

      }

    }

    pbVar7 = pbVar4 + 3;

LAB_0048cd7e:

    iVar5 = iVar5 + 1;

  }

  goto joined_r0x0048ccbe;

}
