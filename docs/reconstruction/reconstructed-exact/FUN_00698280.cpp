// =============================================================================
// FUN_00698280
// -----------------------------------------------------------------------------
// Stable ID: aa_00698280
// Address:   0x00698280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00698280 @ 0x00698280
// Stable ID: aa_00698280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×10, return×5, while×2, do×1, for×1.
//  - Notable callees: FUN_00698280, FUN_0069c4f0, FUN_006a1ec0, _eh_vector_destructor_iterator_.
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

void __fastcall FUN_00698280(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int local_4;

  

  if (*(char *)(param_1 + 0x21) != '\0') {

    pvVar1 = *(void **)(param_1 + 0x58);

    if (pvVar1 != (void *)0x0) {

      FUN_0069c4f0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    local_4 = 0;

    if (0 < *(int *)(param_1 + 0xb4)) {

      iVar3 = 0;

      do {

        uVar4 = 0;

        if (*(int *)(param_1 + 200) != 0) {

          while( true ) {

            iVar5 = *(int *)(iVar3 + 4 + *(int *)(param_1 + 200));

            if ((iVar5 == 0) ||

               ((uint)(*(int *)(iVar3 + *(int *)(param_1 + 200) + 8) - iVar5 >> 2) <= uVar4)) break;

            puVar2 = *(uint32_t /* width from decompiler */ **)(iVar5 + uVar4 * 4);

            if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

              (**(code **)*puVar2)(1);

            }

            *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 4 + *(int *)(param_1 + 200)) + uVar4 * 4) = 0;

            uVar4 = uVar4 + 1;

          }

          pvVar1 = *(void **)(*(int *)(param_1 + 200) + 4 + iVar3);

          iVar5 = *(int *)(param_1 + 200) + iVar3;

          if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar5 + 8) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

        }

        local_4 = local_4 + 1;

        iVar3 = iVar3 + 0x10;

      } while (local_4 < *(int *)(param_1 + 0xb4));

    }

    pvVar1 = *(void **)(param_1 + 200);

    if (pvVar1 != (void *)0x0) {

      _eh_vector_destructor_iterator_(pvVar1,0x10,*(int *)((int)pvVar1 + -4),FUN_00691630);

      operator_delete__((void *)((int)pvVar1 + -4));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0;

    for (uVar4 = 0;

        (iVar3 = *(int *)(param_1 + 100), iVar3 != 0 &&

        (uVar4 < (uint)(*(int *)(param_1 + 0x68) - iVar3 >> 2))); uVar4 = uVar4 + 1) {

      pvVar1 = *(void **)(iVar3 + uVar4 * 4);

      if (pvVar1 != (void *)0x0) {

        FUN_006a1ec0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 100) + uVar4 * 4) = 0;

    }

    if (*(void **)(param_1 + 100) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 100));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

    *(uint8_t *)(param_1 + 0x21) = 0;

  }

  return;

}
