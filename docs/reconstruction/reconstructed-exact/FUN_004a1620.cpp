// =============================================================================
// FUN_004a1620
// -----------------------------------------------------------------------------
// Stable ID: aa_004a1620
// Address:   0x004a1620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a1620 @ 0x004a1620
// Stable ID: aa_004a1620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00439770, FUN_004a1620.
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



uint32_t /* width from decompiler */ * __fastcall FUN_004a1620(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  bool bVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a102b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint8_t *)(param_1 + 1) = 0;

  *(uint8_t *)((int)param_1 + 5) = 0;

  *(uint8_t *)((int)param_1 + 6) = 0;

  pvVar1 = operator_new(0xc);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    iVar2 = FUN_00439770();

    *(int *)((int)pvVar1 + 4) = iVar2;

    *(uint8_t *)(iVar2 + 0x15) = 1;

    *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4);

    *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

  }

  bVar3 = DAT_00b03628 == '\0';

  *param_1 = pvVar1;

  if (bVar3) {

    DAT_00b03628 = '\x01';

    DAT_00b035e4 = 0;

    DAT_00b035e8 = 0;

    _DAT_00b035ec = 0;

    _DAT_00b035f0 = 0;

    _DAT_00b035f4 = 0;

    _DAT_00b035f8 = 0;

  }

  ExceptionList = local_c;

  return param_1;

}
