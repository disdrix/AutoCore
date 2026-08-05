// =============================================================================
// FUN_009147a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009147a0
// Address:   0x009147a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009147a0 @ 0x009147a0
// Stable ID: aa_009147a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGHBList_Enqueue×2, CVOGHBBase_Start, FUN_005081d0, FUN_00599550, FUN_009147a0, Vehicle_CreateWeaponTrackAction.
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

void FUN_009147a0(void)



{

  void *pvVar1;

  CVOGHBBase *pAction;

  int iVar2;

  int unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abcec;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x44);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pAction = (CVOGHBBase *)0x0;

  }

  else {

    pAction = (CVOGHBBase *)FUN_00599550(*(uint32_t /* width from decompiler */ *)(DAT_00d1b6d8 + 0x250),DAT_00d1b644);

  }

  local_4 = 0xffffffff;

  *(CVOGHBBase **)(unaff_ESI + 0xc70) = pAction;

  CVOGHBList_Enqueue(DAT_00d1b578,pAction);

  FUN_005081d0(pvVar1);

  pvVar1 = operator_new(0x28);

  local_4 = 1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = Vehicle_CreateWeaponTrackAction(*(uint32_t /* width from decompiler */ *)(DAT_00d1b6d8 + 0x250));

  }

  local_4 = 0xffffffff;

  *(int *)(unaff_ESI + 0xc74) = iVar2;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = 1;

  CVOGHBList_Enqueue(DAT_00d1b578,*(CVOGHBBase **)(unaff_ESI + 0xc74));

  CVOGHBBase_Start(*(CVOGHBBase **)(unaff_ESI + 0xc74));

  ExceptionList = local_c;

  return;

}
