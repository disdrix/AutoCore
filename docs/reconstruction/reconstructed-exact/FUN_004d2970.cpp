// =============================================================================
// FUN_004d2970
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2970
// Address:   0x004d2970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2970 @ 0x004d2970
// Stable ID: aa_004d2970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×2, do×1.
//  - Notable callees: FUN_004d2970, FUN_004e28e0, FUN_005a5090.
//  - Return sites: 2.

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

void __fastcall FUN_004d2970(int param_1)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar5 = (int *)**(int **)(param_1 + 0xe514);

  if (piVar5 != *(int **)(param_1 + 0xe514)) {

    do {

      pvVar2 = (void *)piVar5[4];

      if (pvVar2 != (void *)0x0) {

        FUN_005a5090();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      if (*(char *)((int)piVar5 + 0x15) == '\0') {

        piVar3 = (int *)piVar5[2];

        if (*(char *)((int)piVar3 + 0x15) == '\0') {

          cVar1 = *(char *)(*piVar3 + 0x15);

          piVar5 = piVar3;

          piVar3 = (int *)*piVar3;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x15);

            piVar5 = piVar3;

            piVar3 = (int *)*piVar3;

          }

        }

        else {

          cVar1 = *(char *)(piVar5[1] + 0x15);

          piVar4 = (int *)piVar5[1];

          piVar3 = piVar5;

          while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {

            cVar1 = *(char *)(piVar5[1] + 0x15);

            piVar4 = (int *)piVar5[1];

            piVar3 = piVar5;

          }

        }

      }

    } while (piVar5 != *(int **)(param_1 + 0xe514));

  }

  FUN_004e28e0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe514) + 4));

  *(int *)(*(int *)(param_1 + 0xe514) + 4) = *(int *)(param_1 + 0xe514);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe518) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0xe514) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe514);

  *(int *)(*(int *)(param_1 + 0xe514) + 8) = *(int *)(param_1 + 0xe514);

  return;

}
