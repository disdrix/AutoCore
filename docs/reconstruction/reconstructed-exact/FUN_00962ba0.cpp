// =============================================================================
// FUN_00962ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00962ba0
// Address:   0x00962ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962ba0 @ 0x00962ba0
// Stable ID: aa_00962ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00962ba0×4.
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

void __fastcall FUN_00962ba0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009abf4b;

  local_c = ExceptionList;

  local_4 = 0;

  piVar3 = (int *)param_1[2];

  ExceptionList = &local_c;

  if (piVar3 != (int *)0x0) {

    ExceptionList = &local_c;

    FUN_00962ba0();

    *piVar3 = (int)DAT_00d21908;

    DAT_00d21908 = piVar3;

  }

  param_1[2] = 0;

  piVar3 = (int *)param_1[1];

  if (piVar3 != (int *)0x0) {

    FUN_00962ba0();

    *piVar3 = (int)DAT_00d21908;

    DAT_00d21908 = piVar3;

  }

  param_1[1] = 0;

  piVar3 = (int *)*param_1;

  if (piVar3 != (int *)0x0) {

    FUN_00962ba0();

    *piVar3 = (int)DAT_00d21908;

    DAT_00d21908 = piVar3;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x10];

  *param_1 = 0;

  piVar3 = DAT_00d2191c;

  if (puVar2 != (uint32_t /* width from decompiler */ *)param_1[0x11]) {

    do {

      piVar1 = (int *)*puVar2;

      if (piVar1 != (int *)0x0) {

        *piVar1 = (int)piVar3;

        piVar3 = piVar1;

        DAT_00d2191c = piVar1;

      }

      puVar2 = puVar2 + 1;

    } while (puVar2 != (uint32_t /* width from decompiler */ *)param_1[0x11]);

  }

  if ((void *)param_1[0x10] == (void *)0x0) {

    param_1[0x10] = 0;

    param_1[0x11] = 0;

    param_1[0x12] = 0;

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x10]);

}
