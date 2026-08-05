// =============================================================================
// FUN_008c6630
// -----------------------------------------------------------------------------
// Stable ID: aa_008c6630
// Address:   0x008c6630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c6630 @ 0x008c6630
// Stable ID: aa_008c6630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×1, while×1.
//  - Notable callees: FUN_006a3db0, FUN_008c6630.
//  - Return sites: 3.

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

void __thiscall FUN_008c6630(int *param_1,float param_2)



{

  int iVar1;

  void *pvVar2;

  uint8_t uVar3;

  char cVar4;

  int *piVar5;

  int *piVar6;

  

  piVar5 = *(int **)param_1[0x123];

  if (piVar5 != (int *)param_1[0x123]) {

    do {

      *(float *)(piVar5[2] + 0x1c) = *(float *)(piVar5[2] + 0x1c) - param_2;

      iVar1 = piVar5[2];

      *(float *)(iVar1 + 8) = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x2c) * param_2;

      *(float *)(iVar1 + 4) = *(float *)(iVar1 + 4) + *(float *)(iVar1 + 0x28) * param_2;

      *(float *)(iVar1 + 0xc) = *(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x30) * param_2;

      iVar1 = piVar5[2];

      if (*(float *)(iVar1 + 0x20) != g_flZero) {

        uVar3 = FUN_006a3db0();

        *(uint8_t *)(iVar1 + 0x27) = uVar3;

      }

      if (0.0 < (float)((uint32_t /* width from decompiler */ *)piVar5[2])[7]) {

        piVar6 = (int *)*piVar5;

      }

      else {

        pvVar2 = *(void **)piVar5[2];

        if (pvVar2 != (void *)0x0) {

          operator_delete__(pvVar2);

        }

        *(uint32_t /* width from decompiler */ *)piVar5[2] = 0;

        if ((void *)piVar5[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)piVar5[2]);

        }

        piVar5[2] = 0;

        piVar6 = (int *)*piVar5;

        if (piVar5 != (int *)param_1[0x123]) {

          *(int **)piVar5[1] = piVar6;

          *(int *)(*piVar5 + 4) = piVar5[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar5);

        }

      }

      (**(code **)(*param_1 + 0xe0))(1);

      piVar5 = piVar6;

    } while (piVar6 != (int *)param_1[0x123]);

  }

  (**(code **)(*param_1 + 500))(param_2);

  cVar4 = (**(code **)(*param_1 + 0xf8))();

  if (cVar4 != '\0') {

    (**(code **)(*param_1 + 0x348))(param_2);

  }

  if (param_1[0xad] != 0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(param_2);

  }

  return;

}
