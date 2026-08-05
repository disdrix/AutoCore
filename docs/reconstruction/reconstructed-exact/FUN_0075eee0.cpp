// =============================================================================
// FUN_0075eee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075eee0
// Address:   0x0075eee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075eee0 @ 0x0075eee0
// Stable ID: aa_0075eee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, for×1.
//  - Notable callees: FUN_0073bad0, FUN_0073bf60, FUN_0073c270, FUN_0073dc40, FUN_0075eee0, FUN_009658e0, FUN_009667b0, FUN_00967400.
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

uint32_t /* width from decompiler */ FUN_0075eee0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *unaff_EDI;

  

  pvVar1 = (void *)unaff_EDI[0x1e8];

  if (pvVar1 != (void *)0x0) {

    FUN_009658e0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  unaff_EDI[0x1e8] = 0;

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EDI[0x1db] + 8);

  for (puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_EDI[0x1db] + 4); puVar4 != puVar2; puVar4 = puVar4 + 1) {

    (**(code **)(*(int *)*puVar4 + 0x14))();

  }

  FUN_0073c270();

  FUN_00986130();

  FUN_0073bf60();

  FUN_00967400(unaff_EDI[0x1d7]);

  FUN_0073dc40(unaff_EDI[0x1d9]);

  FUN_00986760(unaff_EDI[0x1d3]);

  FUN_00985800(unaff_EDI[0x1d4]);

  FUN_0073bad0();

  FUN_0096e710();

  pvVar1 = (void *)unaff_EDI[0x1e7];

  if (pvVar1 == (void *)0x0) {

    unaff_EDI[0x1e7] = 0;

    piVar3 = (int *)unaff_EDI[3];

    if (piVar3 != (int *)0x0) {

      (**(code **)(*piVar3 + 8))(piVar3);

    }

    unaff_EDI[3] = 0;

    piVar3 = (int *)unaff_EDI[2];

    if (piVar3 != (int *)0x0) {

      (**(code **)(*piVar3 + 8))(piVar3);

    }

    unaff_EDI[2] = 0;

    piVar3 = (int *)*unaff_EDI;

    if (piVar3 != (int *)0x0) {

      (**(code **)(*piVar3 + 8))(piVar3);

    }

    *unaff_EDI = 0;

    piVar3 = (int *)unaff_EDI[1];

    if (piVar3 != (int *)0x0) {

      (**(code **)(*piVar3 + 8))(piVar3);

    }

    unaff_EDI[1] = 0;

    return 0;

  }

  FUN_009667b0(pvVar1);

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
