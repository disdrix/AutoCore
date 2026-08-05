// =============================================================================
// FUN_0060f8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060f8a0
// Address:   0x0060f8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060f8a0 @ 0x0060f8a0
// Stable ID: aa_0060f8a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×19, return×6, do×2, while×2, for×1.
//  - Notable callees: FUN_00525ba0, FUN_0060f8a0.
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __thiscall FUN_0060f8a0(int param_1,float param_2)



{

  char cVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  uint *puVar5;

  float10 fVar6;

  int local_8;

  int local_4;

  

  puVar5 = *(uint **)(param_1 + 0x14);

  if ((puVar5 == (uint *)0x0) || (*(int *)(param_1 + 0x18) - (int)puVar5 >> 2 == 0)) {

    iVar4 = *(int *)(param_1 + 0x20);

    if (iVar4 == 0) {

      return (float10)g_flOne;

    }

    if (*(char *)(param_1 + 0x24) != '\0') {

      if (*(int *)((int)param_2 + 0x574) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)((int)param_2 + 0x578) - *(int *)((int)param_2 + 0x574) >> 2;

      }

      fVar6 = (float10)iVar3;

      if (iVar3 < 0) {

        fVar6 = fVar6 + (float10)_DAT_00aaa5dc;

      }

      if (fVar6 / (float10)iVar4 < (float10)g_flOne) {

        if (*(int *)((int)param_2 + 0x574) == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)((int)param_2 + 0x578) - *(int *)((int)param_2 + 0x574) >> 2;

        }

        fVar6 = (float10)iVar3;

        if (iVar3 < 0) {

          fVar6 = fVar6 + (float10)_DAT_00aaa5dc;

        }

        return fVar6 / (float10)iVar4;

      }

      return (float10)g_flOne;

    }

    param_2 = (float)*(int *)(*(int *)((int)param_2 + 0x538) + 0xc) / (float)iVar4;

    if (g_flOne <= param_2) {

      param_2 = g_flOne;

    }

    return (float10)param_2;

  }

  local_8 = 0;

  local_4 = 0;

  if (puVar5 != *(uint **)(param_1 + 0x18)) {

    do {

      local_4 = local_4 + 1;

      if (*(char *)(param_1 + 0x24) == '\0') {

        for (iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_2 + 0x538) + 0x10) +

                                      (*(uint *)(*(int *)((int)param_2 + 0x538) + 8) & *puVar5) * 4)

                             + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {

          if (*puVar5 == *(uint *)(iVar4 + 0x10)) {

            if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {

              local_8 = local_8 + 1;

            }

            break;

          }

        }

      }

      else {

        cVar1 = FUN_00525ba0(*puVar5);

        if ((cVar1 != '\0') && (0 < *(int *)(param_1 + 0x20))) {

          puVar2 = *(uint **)((int)param_2 + 0x574);

          iVar4 = 0;

          if (puVar2 != *(uint **)((int)param_2 + 0x578)) {

            do {

              if (*puVar2 == *puVar5) {

                iVar4 = iVar4 + 1;

              }

              puVar2 = puVar2 + 1;

            } while (puVar2 != *(uint **)((int)param_2 + 0x578));

          }

          if (*(int *)(param_1 + 0x20) <= iVar4) {

            local_8 = local_8 + 1;

          }

        }

      }

      puVar5 = puVar5 + 1;

    } while (puVar5 != *(uint **)(param_1 + 0x18));

    if (local_4 != 0) {

      param_2 = (float)local_8 / (float)local_4;

      if (g_flOne <= param_2) {

        param_2 = g_flOne;

      }

      return (float10)param_2;

    }

  }

  return (float10)g_flOne;

}
