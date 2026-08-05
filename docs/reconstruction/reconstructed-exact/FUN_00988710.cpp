// =============================================================================
// FUN_00988710
// -----------------------------------------------------------------------------
// Stable ID: aa_00988710
// Address:   0x00988710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00988710 @ 0x00988710
// Stable ID: aa_00988710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0044f3c0, FUN_00988710.
//  - Return sites: 1.

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

void __fastcall FUN_00988710(int param_1)



{

  int *piVar1;

  int *piVar2;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ad7cd;

  pvStack_c = ExceptionList;

  local_4 = 1;

  piVar2 = *(int **)(param_1 + 0xc);

  ExceptionList = &pvStack_c;

  local_10 = param_1;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    ExceptionList = &pvStack_c;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  }

  local_4 = local_4 & 0xffffff00;

  piVar2 = *(int **)(param_1 + 0xc);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  local_4 = 0xffffffff;

  FUN_0044f3c0(&local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 4),*(uint32_t /* width from decompiler */ **)(param_1 + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
