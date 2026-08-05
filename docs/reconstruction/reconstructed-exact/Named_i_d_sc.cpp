// =============================================================================
// Named_i_d_sc
// -----------------------------------------------------------------------------
// Stable ID: aa_0088b860
// Address:   0x0088b860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_sc @ 0x0088b860
// Stable ID: aa_0088b860
// Embedded strings (evidence for future rename):
//   - "i_d_sc.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00411f10, FUN_0087b890, FUN_0088a990, Named_i_d_sc, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_sc.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_sc.xml"
 * Domain alias of FUN_0088b860 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_i_d_sc(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b59c2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a53bcc;

  FUN_00411f10(param_1 + 0x148);

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  local_4 = CONCAT31((int3)((uint)local_4 >> 8),2);

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  param_1[0x143] = 0;

  FUN_0088a990();

  NDUIWindow_ReloadInterface("i_d_sc.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
