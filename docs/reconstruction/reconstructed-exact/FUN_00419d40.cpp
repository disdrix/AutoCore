// =============================================================================
// FUN_00419d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00419d40
// Address:   0x00419d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00419d40 @ 0x00419d40
// Stable ID: aa_00419d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00419d40, FUN_00419dd0, _com_issue_error.
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

void FUN_00419d40(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int iVar2;

  int *unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab4eb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0xc);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00419dd0(param_1);

  }

  local_4 = 0xffffffff;

  *unaff_EBX = iVar2;

  if (iVar2 == 0) {

    _com_issue_error(-0x7ff8fff2);

  }

  ExceptionList = local_c;

  return;

}
