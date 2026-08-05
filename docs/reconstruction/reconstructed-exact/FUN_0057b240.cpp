// =============================================================================
// FUN_0057b240
// -----------------------------------------------------------------------------
// Stable ID: aa_0057b240
// Address:   0x0057b240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057b240 @ 0x0057b240
// Stable ID: aa_0057b240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, do×1, while×1.
//  - Notable callees: FUN_005801e0×2, FUN_0057b240.
//  - Return sites: 6.

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

void __fastcall FUN_0057b240(int param_1)



{

  void *pvVar1;

  int *piVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a52d3;

  local_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &local_c;

  if (*(void **)(param_1 + 4) != (void *)0x0) {

    ExceptionList = &local_c;

    operator_delete__(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xc) != *(uint32_t /* width from decompiler */ **)(param_1 + 0x10)) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  FUN_005801e0(0,0);

  piVar2 = *(int **)(param_1 + 0x1c);

  if (piVar2 != *(int **)(param_1 + 0x20)) {

    do {

      operator_delete__(*(void **)(*piVar2 + 8));

      pvVar1 = (void *)*piVar2;

      if (pvVar1 != (void *)0x0) {

        if (*(void **)((int)pvVar1 + 0x10) == (void *)0x0) {

          *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x10) = 0;

          *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x14) = 0;

          *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x18) = 0;

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)pvVar1 + 0x10));

      }

      piVar2 = piVar2 + 1;

    } while (piVar2 != *(int **)(param_1 + 0x20));

  }

  FUN_005801e0(0,0);

  if (*(void **)(param_1 + 0x1c) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    if (*(void **)(param_1 + 0xc) == (void *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

      ExceptionList = local_c;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xc));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x1c));

}
