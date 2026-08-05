// =============================================================================
// FUN_004ca9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ca9f0
// Address:   0x004ca9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ca9f0 @ 0x004ca9f0
// Stable ID: aa_004ca9f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004ca9f0, FUN_0055ff20, FUN_00581220, FUN_0058e0b0.
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

void __fastcall FUN_004ca9f0(int *param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uStack_64;

  int iStack_5c;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [4];

  void *pvStack_2c;

  int iStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a1dc5;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x144))();

  FUN_0058e0b0();

  piVar1 = *(int **)(*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) + 0xe8a0);

  uStack_14 = 0;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x1d8))();

  }

  (**(code **)(*param_1 + 0x4c))(auStack_40,auStack_30);

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x90,0x2c);

  *(uint16_t *)(iVar2 + 4) = 0x90;

  iStack_24._0_1_ = 1;

  iVar2 = FUN_00581220(&stack0xffffff90);

  param_1[0x95] = iVar2;

  iStack_24 = (uint)iStack_24._1_3_ << 8;

  FUN_0055ff20(iVar2);

  iStack_24 = 0xffffffff;

  if (-1 < iStack_5c) {

    (**(code **)(*DAT_00b05060 + 0x14))(uStack_64,iStack_5c * 8,0x12);

  }

  ExceptionList = pvStack_2c;

  return;

}
