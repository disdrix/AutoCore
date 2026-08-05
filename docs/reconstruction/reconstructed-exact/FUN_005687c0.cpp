// =============================================================================
// FUN_005687c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005687c0
// Address:   0x005687c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005687c0 @ 0x005687c0
// Stable ID: aa_005687c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, goto×2, return×2.
//  - Notable callees: CONCAT31, CoTaskMemFree, FUN_004eb010, FUN_005687c0, FUN_005694a0.
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

void __fastcall FUN_005687c0(int param_1)



{

  uint uVar1;

  void **ppvVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a4c83;

  pvStack_c = ExceptionList;

  iVar4 = 0;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  ppvVar2 = &pvStack_c;

  if (0 < *(int *)(param_1 + 0xc)) {

    do {

      uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + iVar4 * 4);

      iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b047ac + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(DAT_00b047ac + 0xf10) + 8) & uVar1) * 4) + 4);

      if (iVar3 == 0) {

LAB_0056882a:

        iVar3 = 0;

      }

      else {

        do {

          if (uVar1 == *(uint *)(iVar3 + 0x10)) {

            if (iVar3 == 0) goto LAB_0056882a;

            iVar3 = *(int *)(iVar3 + 8);

            goto LAB_00568831;

          }

          iVar3 = *(int *)(iVar3 + 0xc);

        } while (iVar3 != 0);

        iVar3 = 0;

      }

LAB_00568831:

      if (iVar3 != 0) {

        FUN_004eb010();

      }

      iVar4 = iVar4 + 1;

      ppvVar2 = ExceptionList;

    } while (iVar4 < *(int *)(param_1 + 0xc));

  }

  ExceptionList = ppvVar2;

  CoTaskMemFree(*(LPVOID *)(param_1 + 0x10));

  piVar5 = (int *)**(int **)(param_1 + 4);

  if (piVar5 != *(int **)(param_1 + 4)) {

    do {

      if ((void *)piVar5[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar5[2]);

      }

      piVar5[2] = 0;

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 4));

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_005694a0(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x24),*(uint32_t /* width from decompiler */ **)(param_1 + 0x24));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x24));

}
