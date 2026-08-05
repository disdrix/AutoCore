// =============================================================================
// FUN_00722c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00722c20
// Address:   0x00722c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00722c20 @ 0x00722c20
// Stable ID: aa_00722c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×3, while×3.
//  - Notable callees: DeleteCriticalSection×2, FUN_0071f010, FUN_00722c20.
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

void FUN_00722c20(int *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab6f7;

  pvStack_c = ExceptionList;

  local_4 = 2;

  piVar3 = param_1 + 0x1c;

  local_10 = 100;

  ExceptionList = &pvStack_c;

  do {

    if (*piVar3 != 0) {

      pvVar1 = *(void **)(*piVar3 + 0x104);

      if (pvVar1 != (void *)0x0) {

        FUN_0071f010();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x104) = 0;

      if ((void *)*piVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)*piVar3);

      }

    }

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

    local_10 = local_10 + -1;

    if (local_10 == 0) {

      piVar3 = param_1 + 199;

      iVar4 = 0x30;

      do {

        if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

        }

        *piVar3 = 0;

        piVar3 = piVar3 + 1;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      piVar3 = param_1 + 0xaa;

      iVar4 = 5;

      do {

        if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

        }

        *piVar3 = 0;

        piVar3 = piVar3 + 1;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if ((uint32_t /* width from decompiler */ *)param_1[0xc3] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xc3])(1);

      }

      param_1[0xc3] = 0;

      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));

      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xfe));

      piVar3 = (int *)*param_1;

      if (piVar3 != (int *)0x0) {

        (**(code **)(*piVar3 + 8))(piVar3);

        *param_1 = 0;

      }

      puVar2 = (uint32_t /* width from decompiler */ *)param_1[0xc5];

      pvVar1 = (void *)*puVar2;

      *puVar2 = puVar2;

      *(int *)(param_1[0xc5] + 4) = param_1[0xc5];

      param_1[0xc6] = 0;

      if (pvVar1 != (void *)param_1[0xc5]) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0xc5]);

    }

  } while( true );

}
