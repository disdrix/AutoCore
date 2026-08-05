// =============================================================================
// UI_notify
// -----------------------------------------------------------------------------
// Stable ID: aa_008b0ce0
// Address:   0x008b0ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_notify @ 0x008b0ce0
// Stable ID: aa_008b0ce0
// Embedded strings (evidence for future rename):
//   - "i_d_notify.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0087b890, FUN_008a0370, FUN_008af180, UI_notify, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_notify.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_notify.xml"
 * Domain alias of FUN_008b0ce0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * UI_notify(int *param_1)



{

  char cVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b650c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a49e2c;

  *(uint8_t *)((int)param_1 + 0x56e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56d) = 0xff;

  *(uint8_t *)(param_1 + 0x15b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56f) = 0xff;

  *(uint8_t *)((int)param_1 + 0x572) = 0xff;

  *(uint8_t *)((int)param_1 + 0x571) = 0xff;

  *(uint8_t *)(param_1 + 0x15c) = 0xff;

  *(uint8_t *)((int)param_1 + 0x573) = 0xff;

  *(uint8_t *)((int)param_1 + 0x576) = 0xff;

  *(uint8_t *)((int)param_1 + 0x575) = 0xff;

  *(uint8_t *)(param_1 + 0x15d) = 0xff;

  *(uint8_t *)((int)param_1 + 0x577) = 0xff;

  *(uint8_t *)((int)param_1 + 0x57a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x579) = 0xff;

  *(uint8_t *)(param_1 + 0x15e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x57b) = 0xff;

  param_1[0x152] = 0;

  param_1[0x15d] = DAT_00afdf0c;

  param_1[0x15c] = DAT_00afdf0c;

  param_1[0x15b] = DAT_00afdf0c;

  param_1[0x15e] = DAT_00afdf0c;

  param_1[0x143] = 0x5e;

  param_1[0x144] = 0x5e;

  param_1[0x145] = 0x5e;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x153] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  param_1[0x15f] = 0;

  param_1[0x160] = 0;

  param_1[0x161] = 0;

  param_1[0x162] = 0;

  DAT_00af92d8 = 0xffffffff;

  NDUIWindow_ReloadInterface("i_d_notify.xml");

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_008af180(1);

    if (param_1[0xac] != 0) {

      FUN_008a0370();

    }

  }

  ExceptionList = local_c;

  return param_1;

}
