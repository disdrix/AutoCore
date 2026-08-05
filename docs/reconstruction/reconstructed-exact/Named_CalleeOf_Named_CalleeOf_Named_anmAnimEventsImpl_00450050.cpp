// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmAnimEventsImpl_00450050
// -----------------------------------------------------------------------------
// Stable ID: aa_00450050
// Callee of Named_CalleeOf_Named_anmAnimEventsImpl
// Address:   0x00450050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmAnimEventsImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00450050, FUN_00450130, FUN_004501d0, FUN_00987560.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmAnimEventsImpl
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_anmAnimEventsImpl_00450050(uint param_1)



{

  uint uVar1;

  int iVar2;

  int unaff_EDI;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bed18;

  local_c = ExceptionList;

  local_4 = 0;

  iVar2 = *(int *)(unaff_EDI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x1c;

  }

  local_10 = param_1;

  if (uVar1 < param_1) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x1c;

    }

    ExceptionList = &local_c;

    FUN_004501d0(unaff_EDI,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),param_1 - iVar2,&stack0x00000004);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar2 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)((*(int *)(unaff_EDI + 8) - iVar2) / 0x1c))) {

      ExceptionList = &local_c;

      FUN_00450130(unaff_EDI,&local_10,iVar2 + param_1 * 0x1c,*(int *)(unaff_EDI + 8));

    }

  }

  local_4 = 0xffffffff;

  FUN_00987560();

  ExceptionList = local_c;

  return;

}
