// =============================================================================
// FUN_005f4ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f4ee0
// Address:   0x005f4ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f4ee0 @ 0x005f4ee0
// Stable ID: aa_005f4ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_005d4240, FUN_005e1c80, FUN_005f2900, FUN_005f4ee0.
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

uint32_t /* width from decompiler */ FUN_005f4ee0(uint32_t /* width from decompiler */ param_1,float param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t auStack_e8 [8];

  uint8_t local_e0 [4];

  uint32_t /* width from decompiler */ local_dc;

  int iStack_d4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  float local_a4;

  float local_40;

  uint8_t local_2c;

  void *pvStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7ac7;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_005e1c80();

  local_14 = 0;

  if (param_2 == 0.0) {

    local_2c = 7;

  }

  else {

    local_40 = param_2;

    FUN_005f2900(param_1,param_2,local_e0);

  }

  local_a8 = 0;

  local_ac = 0;

  local_b0 = 0;

  local_a4 = g_flOne;

  local_c0 = *param_3;

  local_bc = param_3[1];

  local_b8 = param_3[2];

  local_b4 = param_3[3];

  local_dc = param_1;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar1 + 4) = 0xa0;

  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,1);

  uVar2 = FUN_005d4240(auStack_e8);

  pvStack_1c = (void *)0xffffffff;

  if (-1 < iStack_d4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_dc,iStack_d4 * 8,0x12);

  }

  ExceptionList = pvStack_24;

  return uVar2;

}
