// =============================================================================
// FUN_00456500
// -----------------------------------------------------------------------------
// Stable ID: aa_00456500
// Address:   0x00456500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00456500 @ 0x00456500
// Stable ID: aa_00456500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00456500.
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

int * FUN_00456500(int *param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *unaff_EDI;

  int in_XMM0_Da;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc5a8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  local_4 = 0;

  param_1[1] = in_XMM0_Da;

  param_1[2] = param_2;

  if (unaff_EDI != (int *)0x0) {

    unaff_EDI[1] = unaff_EDI[1] + 1;

    if (unaff_EDI[1] == 1) {

      (**(code **)(*unaff_EDI + 4))();

    }

    piVar2 = (int *)*param_1;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

  }

  *param_1 = (int)unaff_EDI;

  ExceptionList = local_c;

  return param_1;

}
