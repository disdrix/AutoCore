// =============================================================================
// FUN_00794850
// -----------------------------------------------------------------------------
// Stable ID: aa_00794850
// Address:   0x00794850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00794850 @ 0x00794850
// Stable ID: aa_00794850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×15, goto×5, return×4, do×1, while×1, for×1.
//  - Notable callees: LeaveCriticalSection×3, FUN_00423f40×2, FUN_00423fe0×2, FUN_004294f0×2, FUN_00797d70×2, FUN_00794850.
//  - Return sites: 4.

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

void FUN_00794850(int param_1,int *param_2)



{

  char cVar1;

  char *pcVar2;

  void *pvVar3;

  int *piVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  char *pcVar10;

  

  uVar9 = (uint)param_2;

  if (*(int *)(param_1 + 0x20c) != 0) {

    param_2 = (int *)0x0;

    FUN_004294f0();

    iVar5 = FUN_00423f40(&param_2);

    if (iVar5 == 0) {

LAB_00794894:

      piVar4 = param_2;

      if (param_2 == (int *)0x0) goto LAB_007948dd;

      if (((*param_2 != 1) || (pcVar2 = (char *)param_2[1], pcVar2 == (char *)0x0)) ||

         (*pcVar2 == '\0')) {

        if ((*param_2 == 0xc) && (param_2[1] != 0)) {

          if (uVar9 == 0) {

            if (*(char *)(param_1 + 0x210) != '\0') {

              *(uint8_t *)(param_1 + 0x210) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1ec));

            }

            FUN_00423fe0(piVar4);

            pvVar3 = *(void **)(param_1 + 0x28c);

            if (pvVar3 == (void *)0x0) {

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

              return;

            }

            FUN_00797d70(pvVar3);

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar3);

          }

          uVar9 = uVar9 - 1;

        }

        goto LAB_007948dd;

      }

      pcVar6 = pcVar2;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      uVar7 = (int)pcVar6 - (int)(pcVar2 + 1);

      if (uVar7 <= uVar9) {

        uVar9 = uVar9 - uVar7;

        goto LAB_007948dd;

      }

      if (uVar9 < uVar7 - 1) {

        pcVar6 = pcVar2 + uVar9;

        iVar8 = (uVar7 - 1) - uVar9;

        pcVar10 = pcVar6;

        for (iVar5 = iVar8; pcVar6 = pcVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

          *pcVar10 = *pcVar6;

          pcVar10 = pcVar10 + 1;

        }

        uVar9 = iVar8 + uVar9;

      }

      pcVar2[uVar9] = '\0';

      pvVar3 = *(void **)(param_1 + 0x28c);

      if (pvVar3 != (void *)0x0) {

        FUN_00797d70(pvVar3);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

      if (uVar9 == 0) {

        if (*(char *)(param_1 + 0x210) != '\0') {

          *(uint8_t *)(param_1 + 0x210) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1ec));

        }

        FUN_00423fe0(param_2);

        FUN_004294f0();

      }

    }

LAB_007948f1:

    if (*(char *)(param_1 + 0x210) != '\0') {

      *(uint8_t *)(param_1 + 0x210) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1ec));

    }

  }

  return;

LAB_007948dd:

  iVar5 = FUN_00423f40(&param_2);

  if (iVar5 != 0) goto LAB_007948f1;

  goto LAB_00794894;

}
