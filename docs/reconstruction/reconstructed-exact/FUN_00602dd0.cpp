// =============================================================================
// FUN_00602dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00602dd0
// Address:   0x00602dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602dd0 @ 0x00602dd0
// Stable ID: aa_00602dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×9, while×6, do×3, return×1.
//  - Notable callees: FUN_004073a0, FUN_00602dd0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00602dd0(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  

  piVar7 = *(int **)(param_2 + 4);

  if (piVar7 != *(int **)(param_2 + 8)) {

    do {

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x34);

      if (*(char *)((int)puVar6[1] + 0x29) == '\0') {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar6[1];

        do {

          if (*piVar7 < (int)puVar3[3]) {

            puVar4 = (uint32_t /* width from decompiler */ *)*puVar3;

            puVar6 = puVar3;

          }

          else {

            puVar4 = (uint32_t /* width from decompiler */ *)puVar3[2];

          }

          puVar3 = puVar4;

        } while (*(char *)((int)puVar4 + 0x29) == '\0');

      }

      puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x34);

      if (*(char *)((int)puVar3[1] + 0x29) == '\0') {

        puVar4 = (uint32_t /* width from decompiler */ *)puVar3[1];

        do {

          if ((int)puVar4[3] < *piVar7) {

            puVar5 = (uint32_t /* width from decompiler */ *)puVar4[2];

          }

          else {

            puVar5 = (uint32_t /* width from decompiler */ *)*puVar4;

            puVar3 = puVar4;

          }

          puVar4 = puVar5;

        } while (*(char *)((int)puVar5 + 0x29) == '\0');

      }

      while (puVar3 != puVar6) {

        if ((int)puVar3[9] <= param_3) {

          iVar2 = *(int *)(param_4 + 4);

          if ((iVar2 == 0) ||

             ((uint)(*(int *)(param_4 + 0xc) - iVar2 >> 2) <=

              (uint)(*(int *)(param_4 + 8) - iVar2 >> 2))) {

            FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_4 + 8),1,puVar3 + 8);

          }

          else {

            puVar4 = *(uint32_t /* width from decompiler */ **)(param_4 + 8);

            *puVar4 = puVar3[8];

            *(uint32_t /* width from decompiler */ **)(param_4 + 8) = puVar4 + 1;

          }

        }

        if (*(char *)((int)puVar3 + 0x29) == '\0') {

          puVar4 = (uint32_t /* width from decompiler */ *)puVar3[2];

          if (*(char *)((int)puVar4 + 0x29) == '\0') {

            cVar1 = *(char *)((int)*puVar4 + 0x29);

            puVar3 = puVar4;

            puVar4 = (uint32_t /* width from decompiler */ *)*puVar4;

            while (cVar1 == '\0') {

              cVar1 = *(char *)((int)*puVar4 + 0x29);

              puVar3 = puVar4;

              puVar4 = (uint32_t /* width from decompiler */ *)*puVar4;

            }

          }

          else {

            cVar1 = *(char *)((int)puVar3[1] + 0x29);

            puVar5 = (uint32_t /* width from decompiler */ *)puVar3[1];

            puVar4 = puVar3;

            while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (uint32_t /* width from decompiler */ *)puVar3[2]))) {

              cVar1 = *(char *)((int)puVar3[1] + 0x29);

              puVar5 = (uint32_t /* width from decompiler */ *)puVar3[1];

              puVar4 = puVar3;

            }

          }

        }

      }

      piVar7 = piVar7 + 1;

    } while (piVar7 != *(int **)(param_2 + 8));

  }

  return 1;

}
