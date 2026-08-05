// =============================================================================
// FUN_00975760
// -----------------------------------------------------------------------------
// Stable ID: aa_00975760
// Address:   0x00975760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00975760 @ 0x00975760
// Stable ID: aa_00975760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, while×3, return×1.
//  - Notable callees: FUN_00425340, FUN_00975760.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00975760(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  iVar2 = unaff_ESI[0x79];

  *unaff_ESI = &PTR_LAB_00a9ba4c;

  while (iVar2 != 0) {

    piVar3 = (int *)unaff_ESI[0x79];

    unaff_ESI[0x79] = piVar3[2];

    (**(code **)(*(int *)*piVar3 + 0x20))();

    piVar4 = (int *)*piVar3;

    if (piVar4 != (int *)0x0) {

      piVar1 = piVar4 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar4 + 8))();

      }

    }

    _DAT_00afdc70 = _DAT_00afdc70 + -1;

    *piVar3 = (int)DAT_00afdc78;

    DAT_00afdc78 = piVar3;

    iVar2 = unaff_ESI[0x79];

  }

  iVar2 = unaff_ESI[0x76];

  while (iVar2 != 0) {

    piVar3 = (int *)unaff_ESI[0x76];

    unaff_ESI[0x76] = piVar3[2];

    (**(code **)(*(int *)*piVar3 + 0x20))();

    piVar4 = (int *)*piVar3;

    if (piVar4 != (int *)0x0) {

      piVar1 = piVar4 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar4 + 8))();

      }

    }

    _DAT_00afdc70 = _DAT_00afdc70 + -1;

    *piVar3 = (int)DAT_00afdc78;

    DAT_00afdc78 = piVar3;

    iVar2 = unaff_ESI[0x76];

  }

  iVar2 = unaff_ESI[0x74];

  while (iVar2 != 0) {

    piVar3 = (int *)unaff_ESI[0x74];

    unaff_ESI[0x74] = piVar3[2];

    (**(code **)(*(int *)*piVar3 + 0x20))();

    piVar4 = (int *)*piVar3;

    if (piVar4 != (int *)0x0) {

      piVar1 = piVar4 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar4 + 8))();

      }

    }

    _DAT_00afdc70 = _DAT_00afdc70 + -1;

    *piVar3 = (int)DAT_00afdc78;

    DAT_00afdc78 = piVar3;

    iVar2 = unaff_ESI[0x74];

  }

  FUN_00425340();

  return;

}
