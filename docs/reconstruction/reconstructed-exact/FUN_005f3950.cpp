// =============================================================================
// FUN_005f3950
// -----------------------------------------------------------------------------
// Stable ID: aa_005f3950
// Address:   0x005f3950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f3950 @ 0x005f3950
// Stable ID: aa_005f3950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT31, FUN_00560ec0, FUN_005d4240, FUN_005e1c80, FUN_005f3950, FUN_006c7970.
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

void FUN_005f3950(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ *local_e4;

  int iStack_dc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint8_t uStack_34;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a7947;

  pvStack_1c = ExceptionList;

  local_f0 = param_5;

  local_ec = param_6;

  local_e8 = param_7;

  local_e4 = (uint32_t /* width from decompiler */ *)0x0;

  ExceptionList = &pvStack_1c;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

  *(uint16_t *)(iVar1 + 4) = 0x20;

  pvStack_1c = (void *)0x0;

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_006c7970(&stack0xffffff08,DAT_00af58a0);

  pvStack_1c = (void *)0xffffffff;

  FUN_005e1c80();

  uStack_c8 = param_2;

  uStack_c4 = param_3;

  uStack_c0 = param_4;

  uStack_34 = 7;

  uStack_bc = 0;

  pvStack_1c = (void *)0x1;

  local_e4 = puVar2;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar1 + 4) = 0xa0;

  uStack_24._0_1_ = 2;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005d4240(&local_f0);

  uStack_24 = CONCAT31(uStack_24._1_3_,1);

  FUN_00560ec0(puVar3);

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    (**(code **)*puVar3)(1);

  }

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  if (*(short *)((int)puVar2 + 6) == 0) {

    (**(code **)*puVar2)(1);

  }

  uStack_24 = 0xffffffff;

  if (-1 < iStack_dc) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_e4,iStack_dc * 8,0x12);

  }

  ExceptionList = pvStack_2c;

  return;

}
