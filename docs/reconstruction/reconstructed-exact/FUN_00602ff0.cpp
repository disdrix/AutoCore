// =============================================================================
// FUN_00602ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00602ff0
// Address:   0x00602ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602ff0 @ 0x00602ff0
// Stable ID: aa_00602ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, while×2, do×1.
//  - Notable callees: FUN_00602ff0×2, FUN_00604280.
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

void __fastcall FUN_00602ff0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7f41;

  pvStack_c = ExceptionList;

  local_4 = 2;

  iVar5 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x14) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;

    }

    pvVar2 = *(void **)(param_1 + 0x14);

    if (iVar4 <= iVar5) break;

    pvVar2 = *(void **)((int)pvVar2 + iVar5 * 4);

    if (pvVar2 != (void *)0x0) {

      ExceptionList = &pvStack_c;

      FUN_00602ff0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    iVar5 = iVar5 + 1;

  }

  if (pvVar2 != (void *)0x0) {

    ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  ExceptionList = &pvStack_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x24);

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x28);

    if (puVar6 != puVar3) {

      puVar6 = puVar6 + 1;

      do {

        if ((void *)*puVar6 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)*puVar6);

        }

        *puVar6 = 0;

        puVar6[1] = 0;

        puVar6[2] = 0;

        puVar1 = puVar6 + 5;

        puVar6 = puVar6 + 6;

      } while (puVar1 != puVar3);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x24));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  local_4 = 1;

  FUN_00604280(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x34),*(uint32_t /* width from decompiler */ **)(param_1 + 0x34));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x34));

}
