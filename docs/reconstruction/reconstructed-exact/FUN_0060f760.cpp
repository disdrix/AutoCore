// =============================================================================
// FUN_0060f760
// -----------------------------------------------------------------------------
// Stable ID: aa_0060f760
// Address:   0x0060f760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060f760 @ 0x0060f760
// Stable ID: aa_0060f760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×16, return×9, while×3, do×2.
//  - Notable callees: FUN_00525ba0, FUN_0060f760.
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

uint32_t /* width from decompiler */ __thiscall FUN_0060f760(int param_1,int param_2)



{

  char cVar1;

  uint *puVar2;

  int iVar3;

  uint *puVar4;

  

  puVar4 = *(uint **)(param_1 + 0x14);

  if ((puVar4 == (uint *)0x0) || (*(int *)(param_1 + 0x18) - (int)puVar4 >> 2 == 0)) {

    if (*(char *)(param_1 + 0x24) == '\0') {

      if (*(int *)(*(int *)(param_2 + 0x538) + 0xc) < *(int *)(param_1 + 0x20)) {

        return 0;

      }

    }

    else {

      if (*(int *)(param_2 + 0x574) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 0x578) - *(int *)(param_2 + 0x574) >> 2;

      }

      if (iVar3 < *(int *)(param_1 + 0x20)) {

        return 0;

      }

    }

  }

  else if (puVar4 != *(uint **)(param_1 + 0x18)) {

    do {

      if (*(char *)(param_1 + 0x24) == '\0') {

        iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0x538) + 0x10) +

                                 (*(uint *)(*(int *)(param_2 + 0x538) + 8) & *puVar4) * 4) + 4);

        if (iVar3 == 0) {

          return 0;

        }

        while (*puVar4 != *(uint *)(iVar3 + 0x10)) {

          iVar3 = *(int *)(iVar3 + 0xc);

          if (iVar3 == 0) {

            return 0;

          }

        }

        if (iVar3 == 0) {

          return 0;

        }

        if (*(int *)(iVar3 + 8) == 0) {

          return 0;

        }

      }

      else {

        cVar1 = FUN_00525ba0(*puVar4);

        if (cVar1 == '\0') {

          return 0;

        }

        if (0 < *(int *)(param_1 + 0x20)) {

          puVar2 = *(uint **)(param_2 + 0x574);

          iVar3 = 0;

          if (puVar2 != *(uint **)(param_2 + 0x578)) {

            do {

              if (*puVar2 == *puVar4) {

                iVar3 = iVar3 + 1;

              }

              puVar2 = puVar2 + 1;

            } while (puVar2 != *(uint **)(param_2 + 0x578));

          }

          if (iVar3 < *(int *)(param_1 + 0x20)) {

            return 0;

          }

        }

      }

      puVar4 = puVar4 + 1;

    } while (puVar4 != *(uint **)(param_1 + 0x18));

  }

  return 1;

}
