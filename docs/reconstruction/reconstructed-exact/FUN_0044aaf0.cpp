// =============================================================================
// FUN_0044aaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044aaf0
// Address:   0x0044aaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044aaf0 @ 0x0044aaf0
// Stable ID: aa_0044aaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004371c0, FUN_0044aaf0.
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

void FUN_0044aaf0(void)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  int *piVar4;

  int *unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befeb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar3 = operator_new(0x14);

  local_4 = 0;

  if (pvVar3 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_004371c0(pvVar3);

  }

  local_4 = 0xffffffff;

  if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {

    (**(code **)(*piVar4 + 4))();

  }

  piVar2 = (int *)*unaff_EDI;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *unaff_EDI = (int)piVar4;

  ExceptionList = pvStack_c;

  return;

}
