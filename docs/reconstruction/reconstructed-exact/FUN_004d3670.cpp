// =============================================================================
// FUN_004d3670
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3670
// Address:   0x004d3670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d3670 @ 0x004d3670
// Stable ID: aa_004d3670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×1, return×1.
//  - Notable callees: FUN_004d3670, FUN_004e2880, FUN_004e46f0, FUN_00540060.
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

void __fastcall FUN_004d3670(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  uint8_t local_18 [4];

  int *local_14;

  uint8_t local_10 [12];

  

  *(uint8_t *)(param_1 + 0x40) = 1;

  FUN_004e2880(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x38) + 4));

  *(int *)(*(int *)(param_1 + 0x38) + 4) = *(int *)(param_1 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  *(int *)(*(int *)(param_1 + 0x38) + 8) = *(int *)(param_1 + 0x38);

  iVar4 = FUN_00540060();

  piVar5 = (int *)**(int **)(iVar4 + 4);

  if (piVar5 != *(int **)(iVar4 + 4)) {

    do {

      if (piVar5[3] == *(int *)(param_1 + 0xfc)) {

        local_18[0] = (uint8_t)piVar5[4];

        local_14 = piVar5 + 4;

        FUN_004e46f0(local_10,local_18);

      }

      if (*(char *)((int)piVar5 + 0x7d) == '\0') {

        piVar2 = (int *)piVar5[2];

        if (*(char *)((int)piVar2 + 0x7d) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x7d);

          piVar5 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x7d);

            piVar5 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar5[1] + 0x7d);

          piVar3 = (int *)piVar5[1];

          piVar2 = piVar5;

          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {

            cVar1 = *(char *)(piVar5[1] + 0x7d);

            piVar3 = (int *)piVar5[1];

            piVar2 = piVar5;

          }

        }

      }

    } while (piVar5 != *(int **)(iVar4 + 4));

  }

  return;

}
