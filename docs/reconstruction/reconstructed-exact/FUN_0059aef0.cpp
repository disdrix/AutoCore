// =============================================================================
// FUN_0059aef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0059aef0
// Address:   0x0059aef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059aef0 @ 0x0059aef0
// Stable ID: aa_0059aef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, return×2, do×1.
//  - Notable callees: FUN_0059aef0, FUN_0059d5e0, FUN_0059d620.
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

void __fastcall FUN_0059aef0(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a5b88;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d5710;

  local_4 = 1;

  if ((void *)param_1[0x146] != (void *)0x0) {

    operator_delete__((void *)param_1[0x146]);

  }

  param_1[0x146] = 0;

  piVar4 = *(int **)param_1[0x148];

  if (piVar4 != (int *)param_1[0x148]) {

    do {

      if ((void *)piVar4[5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar4[5]);

      }

      piVar4[5] = 0;

      piVar4[6] = 0;

      piVar4[7] = 0;

      if (*(char *)((int)piVar4 + 0x21) == '\0') {

        piVar2 = (int *)piVar4[2];

        if (*(char *)((int)piVar2 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          piVar4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x21);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x21);

          piVar3 = (int *)piVar4[1];

          piVar2 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x21);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

          }

        }

      }

    } while (piVar4 != (int *)param_1[0x148]);

  }

  FUN_0059d5e0(*(uint32_t /* width from decompiler */ *)(param_1[0x148] + 4));

  *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 4) = param_1[0x148];

  param_1[0x149] = 0;

  *(uint32_t /* width from decompiler */ *)param_1[0x148] = param_1[0x148];

  *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 8) = param_1[0x148];

  local_4 = local_4 & 0xffffff00;

  FUN_0059d620(local_10,*(uint32_t /* width from decompiler */ *)param_1[0x148],(uint32_t /* width from decompiler */ *)param_1[0x148]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x148]);

}
