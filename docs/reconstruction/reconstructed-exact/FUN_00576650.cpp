// =============================================================================
// FUN_00576650
// -----------------------------------------------------------------------------
// Stable ID: aa_00576650
// Address:   0x00576650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00576650 @ 0x00576650
// Stable ID: aa_00576650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00576650, FUN_00756c50, FUN_00756d40, FUN_00758460, FUN_00758c80, FUN_00759090, FUN_00759860.
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

uint32_t /* width from decompiler */ __fastcall FUN_00576650(int param_1)



{

  int iVar1;

  int iVar2;

  void *local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a50cb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_14 = operator_new(0xb8);

  local_4 = 0;

  if (local_14 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00759860();

  }

  *(int *)(param_1 + 0x1c) = iVar2;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x78) = 10;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x7c) = 10;

  iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x80);

  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x84);

  local_14 = (void *)((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);

  local_10 = (void *)((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);

  local_4 = 0xffffffff;

  (**(code **)(**(int **)(param_1 + 0x1c) + 8))(&local_14);

  FUN_00758c80();

  iVar2 = *(int *)(param_1 + 0x18);

  FUN_00758460(0,0,(float)((int)(*(int *)(iVar2 + 0x80) + (*(int *)(iVar2 + 0x80) >> 0x1f & 3U)) >>

                          2),

               (float)((int)(*(int *)(iVar2 + 0x84) + (*(int *)(iVar2 + 0x84) >> 0x1f & 3U)) >> 2),

               iVar2 + 0xb8,0,DAT_00afdf0c,0,0,0,&DAT_00d1ecac);

  FUN_00759090();

  FUN_00756c50(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c));

  FUN_00756d40();

  ExceptionList = local_10;

  return 0;

}
