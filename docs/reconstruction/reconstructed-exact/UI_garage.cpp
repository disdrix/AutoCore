// =============================================================================
// UI_garage
// -----------------------------------------------------------------------------
// Stable ID: aa_008826e0
// Address:   0x008826e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_garage @ 0x008826e0
// Stable ID: aa_008826e0
// Embedded strings (evidence for future rename):
//   - "i_d_v.xml"
//   - "i_d_garage.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008801b0×2, NDUIWindow_ReloadInterface×2, FUN_0087b890, FUN_0087d580, UI_garage.
//  - Strings: "i_d_v.xml"; "i_d_garage.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_garage.xml"
 * Domain alias of FUN_008826e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * UI_garage(int *param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5503;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a57644;

  param_1[0x144] = param_2;

  FUN_0087d580();

  if (param_1[0x144] == 0) {

    NDUIWindow_ReloadInterface("i_d_v.xml");

    FUN_008801b0(param_1);

    (**(code **)(*param_1 + 0x34c))();

    param_1[0x13f] = 0xc;

  }

  else if (param_1[0x144] == 1) {

    NDUIWindow_ReloadInterface("i_d_garage.xml");

    FUN_008801b0(param_1);

    (**(code **)(*param_1 + 0x34c))();

    param_1[0x13f] = 0xf;

  }

  param_1[0x140] = 1;

  param_1[0x143] = -1;

  ExceptionList = local_c;

  return param_1;

}
