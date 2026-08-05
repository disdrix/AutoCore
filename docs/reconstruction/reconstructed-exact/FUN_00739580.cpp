// =============================================================================
// FUN_00739580
// -----------------------------------------------------------------------------
// Stable ID: aa_00739580
// Address:   0x00739580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739580 @ 0x00739580
// Stable ID: aa_00739580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00414b60×2, FUN_00414c20, FUN_004376e0, FUN_004451c0, FUN_00738bc0, FUN_00739580, FUN_00746b00.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00739580(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint8_t local_24 [20];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2e61;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0xc4);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_004376e0(pvVar1,param_1);

  }

  local_4 = 0xffffffff;

  puVar2[0x2c] = 0;

  FUN_004451c0(local_24,*(int *)(param_1 + 0x14) + 0x24);

  local_4 = 1;

  FUN_00746b00();

  puVar2[0x2f] = puVar2[0x2f] | 1;

  if (*(int *)(param_1 + 0x14) == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  iVar4 = FUN_00414c20(uVar3,local_24,0x22,0);

  if (-1 < iVar4) {

    FUN_00738bc0();

    FUN_00414b60();

    ExceptionList = local_c;

    return puVar2;

  }

  (**(code **)*puVar2)(1);

  FUN_00414b60();

  ExceptionList = pvStack_10;

  return (uint32_t /* width from decompiler */ *)0x0;

}
