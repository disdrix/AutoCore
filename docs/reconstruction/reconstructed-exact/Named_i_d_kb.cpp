// =============================================================================
// Named_i_d_kb
// -----------------------------------------------------------------------------
// Stable ID: aa_008bce40
// Address:   0x008bce40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_kb @ 0x008bce40
// Stable ID: aa_008bce40
// Embedded strings (evidence for future rename):
//   - "i_d_kb.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_008bc5c0, Named_i_d_kb, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_kb.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_kb.xml"
 * Domain alias of FUN_008bce40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_i_d_kb(int *param_1)



{

  char cVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b683b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a45e94;

  param_1[0x13f] = 3;

  param_1[0x140] = 2;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x149] = 0;

  param_1[0x148] = 0;

  *(uint8_t *)(param_1 + 0x143) = 0;

  param_1[0x144] = 0;

  *(uint8_t *)(param_1 + 0x145) = 0;

  NDUIWindow_ReloadInterface("i_d_kb.xml");

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    *(uint8_t *)(param_1 + 0x145) = 0;

    FUN_008bc5c0();

  }

  ExceptionList = local_c;

  return param_1;

}
