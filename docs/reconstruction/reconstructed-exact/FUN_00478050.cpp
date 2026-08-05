// =============================================================================
// FUN_00478050
// -----------------------------------------------------------------------------
// Stable ID: aa_00478050
// Address:   0x00478050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00478050 @ 0x00478050
// Stable ID: aa_00478050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, do×1, return×1.
//  - Notable callees: FUN_00478050.
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

char * FUN_00478050(void)



{

  char *pcVar1;

  uint uVar2;

  uint in_EAX;

  char *pcVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  int unaff_EDI;

  char local_12;

  char local_11;

  uint local_10;

  char *local_c;

  uint local_8;

  

  local_10 = *(uint *)(unaff_EDI + 0x74);

  uVar2 = *(uint *)(unaff_EDI + 100);

  pcVar8 = *(char **)(unaff_EDI + 0x70);

  pcVar4 = (char *)(*(int *)(unaff_EDI + 0x30) + uVar2);

  if (*(int *)(unaff_EDI + 0x24) - 0x106U < uVar2) {

    local_8 = (uVar2 - *(int *)(unaff_EDI + 0x24)) + 0x106;

  }

  else {

    local_8 = 0;

  }

  local_12 = pcVar4[(int)(pcVar8 + -1)];

  local_11 = pcVar4[(int)pcVar8];

  pcVar1 = pcVar4 + 0x102;

  if (*(char **)(unaff_EDI + 0x84) <= pcVar8) {

    local_10 = local_10 >> 2;

  }

  pcVar3 = *(char **)(unaff_EDI + 0x6c);

  local_c = *(char **)(unaff_EDI + 0x88);

  if (pcVar3 < *(char **)(unaff_EDI + 0x88)) {

    local_c = pcVar3;

  }

  do {

    pcVar7 = (char *)(*(int *)(unaff_EDI + 0x30) + in_EAX);

    if ((((pcVar7[(int)pcVar8] == local_11) && (pcVar7[(int)(pcVar8 + -1)] == local_12)) &&

        (*pcVar7 == *pcVar4)) && (pcVar7[1] == pcVar4[1])) {

      pcVar7 = pcVar7 + 2;

      pcVar5 = pcVar4 + 2;

      while (((((pcVar6 = pcVar5 + 1, pcVar5[1] == pcVar7[1] &&

                (pcVar6 = pcVar5 + 2, pcVar5[2] == pcVar7[2])) &&

               ((pcVar6 = pcVar5 + 3, pcVar5[3] == pcVar7[3] &&

                ((pcVar6 = pcVar5 + 4, pcVar5[4] == pcVar7[4] &&

                 (pcVar6 = pcVar5 + 5, pcVar5[5] == pcVar7[5])))))) &&

              (pcVar6 = pcVar5 + 6, pcVar5[6] == pcVar7[6])) &&

             (pcVar6 = pcVar5 + 7, pcVar5[7] == pcVar7[7]))) {

        pcVar6 = pcVar5 + 8;

        pcVar7 = pcVar7 + 8;

        if ((pcVar5[8] != *pcVar7) || (pcVar5 = pcVar6, pcVar1 <= pcVar6)) break;

      }

      pcVar7 = pcVar6 + (0x102 - (int)pcVar1);

      if ((int)pcVar8 < (int)pcVar7) {

        *(uint *)(unaff_EDI + 0x68) = in_EAX;

        if ((int)local_c <= (int)pcVar7) break;

        local_12 = pcVar4[(int)(pcVar6 + (0x101 - (int)pcVar1))];

        local_11 = pcVar4[(int)pcVar7];

        pcVar8 = pcVar7;

      }

    }

    pcVar7 = pcVar8;

    in_EAX = (uint)*(ushort *)

                    (*(int *)(unaff_EDI + 0x38) + (*(uint *)(unaff_EDI + 0x2c) & in_EAX) * 2);

    if (in_EAX <= local_8) break;

    local_10 = local_10 - 1;

    pcVar8 = pcVar7;

  } while (local_10 != 0);

  if (pcVar7 <= pcVar3) {

    pcVar3 = pcVar7;

  }

  return pcVar3;

}
