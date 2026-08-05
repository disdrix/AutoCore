// =============================================================================
// FUN_00966530
// -----------------------------------------------------------------------------
// Stable ID: aa_00966530
// Address:   0x00966530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00966530 @ 0x00966530
// Stable ID: aa_00966530
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxEffectDetailDisplay.cpp"
//   - "Failed to create font"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_00460da0, FUN_00759860, FUN_0076c4d0, FUN_0076c500, FUN_00966530, FUN_0099ed40, vog_LogMessage.
//  - Strings: ",0x35,

                   3,".
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

int FUN_00966530(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2f1a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076c500(1000);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint8_t *)(param_1 + 0x40) = 0;

  *(uint8_t *)(param_1 + 0x41) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  local_4._0_1_ = 3;

  local_4._1_3_ = 0;

  *(uint8_t *)(param_1 + 0x78) = 0;

  pvVar1 = operator_new(0xb8);

  local_4._0_1_ = 4;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00759860();

  }

  local_4 = CONCAT31(local_4._1_3_,3);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = uVar2;

  iVar3 = FUN_0099ed40(0xc);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxEffectDetailDisplay.cpp",0x35,

                   3,"Failed to create font");

  }

  FUN_0076c4d0();

  FUN_00460da0(8);

  ExceptionList = local_c;

  return param_1;

}
