// =============================================================================
// FUN_00962780
// -----------------------------------------------------------------------------
// Stable ID: aa_00962780
// Address:   0x00962780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962780 @ 0x00962780
// Stable ID: aa_00962780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0072a5a0, FUN_00746400, FUN_00962780.
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

uint32_t /* width from decompiler */ FUN_00962780(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af7c8;

  local_c = ExceptionList;

  if (DAT_00d1a604 != 0) {

    return 1;

  }

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x20);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0072a5a0(pvVar1);

  }

  local_4 = 0xffffffff;

  DAT_00d1a604 = iVar2;

  if (iVar2 == 0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  *(uint8_t *)(iVar2 + 5) = 1;

  *(code **)(iVar2 + 0x1c) = FUN_00469560;

  uVar3 = FUN_00746400(iVar2);

  ExceptionList = local_c;

  return uVar3;

}
