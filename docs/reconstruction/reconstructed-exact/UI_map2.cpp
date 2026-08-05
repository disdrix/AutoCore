// =============================================================================
// UI_map2
// -----------------------------------------------------------------------------
// Stable ID: aa_008b1ed0
// Address:   0x008b1ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_map2 @ 0x008b1ed0
// Stable ID: aa_008b1ed0
// Embedded strings (evidence for future rename):
//   - "i_d_map2.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0085ba60, FUN_0087b890, FUN_008b12d0, FUN_008b1c80, UI_map2.
//  - Strings: "i_d_map2.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_map2.xml"
 * Domain alias of FUN_008b1ed0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_map2(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6543;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a49844;

  param_1[0x13f] = 9;

  param_1[0x140] = 2;

  FUN_008b12d0();

  *(uint8_t *)(param_1 + 0x124) = 0;

  FUN_008b1c80("i_d_map2.xml");

  pvVar1 = operator_new(0x6b0);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0085ba60(pvVar1,1);

  }

  param_1[0x14e] = uVar2;

  ExceptionList = local_c;

  return param_1;

}
