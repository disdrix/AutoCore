// =============================================================================
// FUN_005f4420
// -----------------------------------------------------------------------------
// Stable ID: aa_005f4420
// Address:   0x005f4420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f4420 @ 0x005f4420
// Stable ID: aa_005f4420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005f4230, FUN_005f4420, FUN_00646d90, FUN_00646dd0.
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

uint32_t /* width from decompiler */ FUN_005f4420(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a79f2;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00d030f0 + 8))(param_1);

  FUN_00646d90(puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  puStack_8 = (uint8_t *)0x0;

  uVar2 = FUN_005f4230(&stack0xffffffe0,param_2,param_3);

  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

  if (*(short *)((int)puVar1 + 6) == 0) {

    (**(code **)*puVar1)(1);

  }

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_00646dd0();

  ExceptionList = pvStack_10;

  return uVar2;

}
