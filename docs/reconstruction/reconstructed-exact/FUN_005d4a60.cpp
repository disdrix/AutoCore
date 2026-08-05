// =============================================================================
// FUN_005d4a60
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4a60
// Address:   0x005d4a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4a60 @ 0x005d4a60
// Stable ID: aa_005d4a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b2520, FUN_005d4a60.
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

void __fastcall FUN_005d4a60(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a70c7;

  pvStack_c = ExceptionList;

  uVar3 = 0;

  ExceptionList = &pvStack_c;

  iVar2 = param_1;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 700))(0);

  pvVar1 = operator_new(0x78);

  puStack_8 = (uint8_t *)0x0;

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_005b2520(uVar3,pvVar1,iVar2);

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -200 + param_1) = uVar3;

  puStack_8 = (uint8_t *)0xffffffff;

  iVar2 = 0;

  if (param_1 != 0xe0) {

    iVar2 = *(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1;

  }

  (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -200 + param_1) + 0x2c))(iVar2);

  ExceptionList = pvVar1;

  return;

}
