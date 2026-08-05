// =============================================================================
// FUN_004835f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004835f0
// Address:   0x004835f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004835f0 @ 0x004835f0
// Stable ID: aa_004835f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×11, while×5, do×2, for×1, return×1.
//  - Notable callees: FUN_00483580, FUN_004835f0.
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

void FUN_004835f0(void)



{

  int *piVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  uint uVar9;

  int iVar10;

  int iVar11;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar12;

  int local_114;

  int local_110;

  char local_100 [256];

  

  iVar4 = *(int *)(unaff_ESI + 0x20);

  iVar5 = *(int *)(unaff_ESI + 0x24);

  iVar6 = *(int *)(unaff_ESI + 0x28);

  FUN_00483580();

  iVar11 = *(int *)(unaff_ESI + 0x54) + 1;

  if (-1 < iVar11) {

    puVar12 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x278);

    for (iVar10 = *(int *)(unaff_ESI + 0x54) + 2; iVar10 != 0; iVar10 = iVar10 + -1) {

      *puVar12 = 0;

      puVar12 = puVar12 + 1;

    }

  }

  iVar10 = 0;

  local_114 = 0;

  if (0 < *(int *)(unaff_ESI + 0x54)) {

    iVar7 = *(int *)(unaff_ESI + 0x54);

    do {

      local_100[iVar10] = (char)iVar10;

      iVar10 = iVar10 + 1;

    } while (iVar10 < iVar7);

  }

  iVar10 = 0;

  local_110 = 0;

  if (0 < *(int *)(unaff_ESI + 0x44)) {

    do {

      cVar3 = local_100[1];

      iVar7 = *(int *)(iVar4 + local_110 * 4) + -1;

      if (iVar7 < 0) {

        iVar7 = iVar7 + *(int *)(unaff_ESI + 0x44);

      }

      cVar2 = *(char *)(*(byte *)(iVar7 + iVar5) + 0x158 + unaff_ESI);

      if (local_100[0] == cVar2) {

        local_114 = local_114 + 1;

      }

      else {

        if (0 < local_114) {

          uVar9 = local_114 - 1;

          while( true ) {

            if ((uVar9 & 1) == 0) {

              *(uint16_t *)(iVar6 + iVar10 * 2) = 0;

              *(int *)(unaff_ESI + 0x278) = *(int *)(unaff_ESI + 0x278) + 1;

            }

            else {

              *(uint16_t *)(iVar6 + iVar10 * 2) = 1;

              *(int *)(unaff_ESI + 0x27c) = *(int *)(unaff_ESI + 0x27c) + 1;

            }

            iVar10 = iVar10 + 1;

            if ((int)uVar9 < 2) break;

            uVar9 = (int)(uVar9 - 2) / 2;

          }

          local_114 = 0;

        }

        local_100[1] = local_100[0];

        pcVar8 = local_100 + 1;

        local_100[0] = cVar3;

        while (cVar2 != local_100[0]) {

          pcVar8 = pcVar8 + 1;

          cVar3 = *pcVar8;

          *pcVar8 = local_100[0];

          local_100[0] = cVar3;

        }

        *(short *)(iVar6 + iVar10 * 2) = (short)((int)pcVar8 - (int)local_100) + 1;

        iVar10 = iVar10 + 1;

        piVar1 = (int *)(unaff_ESI + 0x27c + ((int)pcVar8 - (int)local_100) * 4);

        *piVar1 = *piVar1 + 1;

      }

      local_110 = local_110 + 1;

    } while (local_110 < *(int *)(unaff_ESI + 0x44));

    if (0 < local_114) {

      uVar9 = local_114 - 1;

      while( true ) {

        if ((uVar9 & 1) == 0) {

          *(uint16_t *)(iVar6 + iVar10 * 2) = 0;

          *(int *)(unaff_ESI + 0x278) = *(int *)(unaff_ESI + 0x278) + 1;

        }

        else {

          *(uint16_t *)(iVar6 + iVar10 * 2) = 1;

          *(int *)(unaff_ESI + 0x27c) = *(int *)(unaff_ESI + 0x27c) + 1;

        }

        iVar10 = iVar10 + 1;

        if ((int)uVar9 < 2) break;

        uVar9 = (int)(uVar9 - 2) / 2;

      }

    }

  }

  *(short *)(iVar6 + iVar10 * 2) = (short)iVar11;

  piVar1 = (int *)(unaff_ESI + 0x278 + iVar11 * 4);

  *piVar1 = *piVar1 + 1;

  *(int *)(unaff_ESI + 0x274) = iVar10 + 1;

  return;

}
