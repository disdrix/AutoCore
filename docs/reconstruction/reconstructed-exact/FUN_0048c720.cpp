// =============================================================================
// FUN_0048c720
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c720
// Address:   0x0048c720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c720 @ 0x0048c720
// Stable ID: aa_0048c720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0048c360, FUN_0048c670, FUN_0048c720.
//  - Return sites: 2.

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

int __fastcall FUN_0048c720(int param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a059b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x50);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0048c360(*(int *)(param_1 + 0x20) + 8);

  }

  local_4 = 0xffffffff;

  if (iVar2 == 0) {

    ExceptionList = local_c;

    return 0;

  }

  FUN_0048c670(iVar2);

  ExceptionList = local_c;

  return iVar2;

}
