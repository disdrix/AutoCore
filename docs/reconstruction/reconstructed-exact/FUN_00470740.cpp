// =============================================================================
// FUN_00470740
// -----------------------------------------------------------------------------
// Stable ID: aa_00470740
// Address:   0x00470740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470740 @ 0x00470740
// Stable ID: aa_00470740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×11, for×6, return×5, do×3, while×3.
//  - Notable callees: FUN_00477740×3, FUN_00477710×2, FUN_00470740, FUN_00476d60.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ FUN_00470740(int param_1,int param_2,int param_3,int param_4)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  int *piVar9;

  int *piVar10;

  uint uVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int local_4;

  

  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == 0)) {

    return 0;

  }

  iVar7 = *(int *)(param_2 + 0x30) + param_4;

  iVar3 = *(int *)(param_2 + 0x34);

  if (iVar3 < iVar7) {

    puVar13 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x38);

    if (puVar13 == (uint32_t /* width from decompiler */ *)0x0) {

      *(int *)(param_2 + 0x34) = param_4 + 8;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = 0;

      iVar7 = FUN_00477740();

      *(int *)(param_2 + 0x38) = iVar7;

      if (iVar7 == 0) {

        return 1;

      }

      *(byte *)(param_2 + 0xb9) = *(byte *)(param_2 + 0xb9) | 0x40;

    }

    else {

      *(int *)(param_2 + 0x34) = iVar7 + 8;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00477740();

      *(uint32_t /* width from decompiler */ **)(param_2 + 0x38) = puVar4;

      if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

        FUN_00477710();

        return 1;

      }

      for (uVar6 = (uint)(iVar3 << 4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *puVar4 = *puVar13;

        puVar13 = puVar13 + 1;

        puVar4 = puVar4 + 1;

      }

      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

        *(uint8_t *)puVar4 = *(uint8_t *)puVar13;

        puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      }

      FUN_00477710();

    }

  }

  local_4 = 0;

  if (0 < param_4) {

    puVar13 = (uint32_t /* width from decompiler */ *)(param_3 + 8);

    do {

      pcVar5 = (char *)puVar13[-1];

      piVar10 = (int *)(*(int *)(param_2 + 0x30) * 0x10 + *(int *)(param_2 + 0x38));

      if (pcVar5 != (char *)0x0) {

        pcVar1 = pcVar5 + 1;

        do {

          cVar2 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar2 != '\0');

        uVar6 = (int)pcVar5 - (int)pcVar1;

        if ((int)puVar13[-2] < 1) {

          pcVar5 = (char *)*puVar13;

          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

            uVar11 = 0;

            *piVar10 = -1;

          }

          else {

            pcVar1 = pcVar5 + 1;

            do {

              cVar2 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar2 != '\0');

            uVar11 = (int)pcVar5 - (int)pcVar1;

            *piVar10 = puVar13[-2];

          }

          puVar4 = (uint32_t /* width from decompiler */ *)FUN_00477740();

          piVar10[1] = (int)puVar4;

          if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

            return 1;

          }

          puVar12 = (uint32_t /* width from decompiler */ *)puVar13[-1];

          for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

            *puVar4 = *puVar12;

            puVar12 = puVar12 + 1;

            puVar4 = puVar4 + 1;

          }

          for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

            *(uint8_t *)puVar4 = *(uint8_t *)puVar12;

            puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

            puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

          }

          *(uint8_t *)(uVar6 + piVar10[1]) = 0;

          puVar4 = (uint32_t /* width from decompiler */ *)(uVar6 + 1 + piVar10[1]);

          piVar10[2] = (int)puVar4;

          if (uVar11 != 0) {

            puVar12 = (uint32_t /* width from decompiler */ *)*puVar13;

            for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

              *puVar4 = *puVar12;

              puVar12 = puVar12 + 1;

              puVar4 = puVar4 + 1;

            }

            for (uVar6 = uVar11 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

              *(uint8_t *)puVar4 = *(uint8_t *)puVar12;

              puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

              puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

            }

          }

          *(uint8_t *)(piVar10[2] + uVar11) = 0;

          piVar10[3] = uVar11;

          piVar9 = (int *)(*(int *)(param_2 + 0x30) * 0x10 + *(int *)(param_2 + 0x38));

          *piVar9 = *piVar10;

          piVar9[1] = piVar10[1];

          piVar9[2] = piVar10[2];

          piVar9[3] = piVar10[3];

          *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;

        }

        else {

          FUN_00476d60();

        }

      }

      local_4 = local_4 + 1;

      puVar13 = puVar13 + 4;

    } while (local_4 < param_4);

  }

  return 0;

}
