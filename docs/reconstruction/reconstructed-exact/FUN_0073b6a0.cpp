// =============================================================================
// FUN_0073b6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b6a0
// Address:   0x0073b6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b6a0 @ 0x0073b6a0
// Stable ID: aa_0073b6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×6, while×1.
//  - Notable callees: FUN_00464580×2, FUN_00449a90, FUN_0073b2d0, FUN_0073b6a0, FUN_0074ecf0.
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

void __fastcall FUN_0073b6a0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int *piVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvStack_c = ExceptionList;

  puStack_8 = &LAB_009b0817;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa42ec;

  local_4 = 1;

  iVar1 = param_1[5];

  param_1[1] = 0;

  while( true ) {

    if (iVar1 == 0) {

      FUN_00464580();

      FUN_00449a90(9);

      param_1[0xe] = 1;

      param_1[0xf] = 1;

      if ((void *)param_1[0xb] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)param_1[0xb]);

      }

      param_1[0xb] = 0;

      param_1[0xc] = 0;

      param_1[0xd] = 0;

      FUN_00464580();

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[8]);

    }

    piVar2 = *(int **)param_1[4];

    FUN_0073b2d0(piVar2 + 2);

    pvVar3 = (void *)piVar2[5];

    if (pvVar3 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    if ((void *)piVar2[7] != (void *)0x0) break;

    piVar2[7] = 0;

    piVar2[8] = 0;

    piVar2[9] = 0;

    if (piVar2 != (int *)param_1[4]) {

      *(int *)piVar2[1] = *piVar2;

      *(int *)(*piVar2 + 4) = piVar2[1];

      if ((void *)piVar2[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar2[7]);

      }

      piVar2[7] = 0;

      piVar2[8] = 0;

      piVar2[9] = 0;

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar2);

    }

    iVar1 = param_1[5];

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)piVar2[7]);

}
