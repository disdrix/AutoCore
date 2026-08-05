// =============================================================================
// FUN_00448f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00448f50
// Address:   0x00448f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00448f50 @ 0x00448f50
// Stable ID: aa_00448f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00448f50, FUN_00448fb0, FUN_00745ea0, NDResource_AcquireInnerObject.
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

void __fastcall FUN_00448f50(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *unaff_EBX;

  int *unaff_EDI;

  

  piVar2 = (int *)*unaff_EBX;

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar3 = (int *)*unaff_EDI;

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  *unaff_EDI = (int)piVar2;

  FUN_00448fb0();

  if (param_1 != 0) {

    NDResource_AcquireInnerObject();

  }

  if (unaff_EDI[1] != 0) {

    FUN_00745ea0();

  }

  unaff_EDI[1] = param_1;

  return;

}
