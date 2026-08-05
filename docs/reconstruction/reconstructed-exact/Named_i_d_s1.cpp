// =============================================================================
// Named_i_d_s1
// -----------------------------------------------------------------------------
// Stable ID: aa_00897040
// Address:   0x00897040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_s1 @ 0x00897040
// Stable ID: aa_00897040
// Embedded strings (evidence for future rename):
//   - "i_d_s.xml"
//   - "i_d_s1.xml"
//   - "i_d_s2.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00896b20×3, NDUIWindow_ReloadInterface×3, FUN_0087b890, FUN_00896040, Named_i_d_s1.
//  - Strings: "i_d_s.xml"; "i_d_s1.xml"; "i_d_s2.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_s1.xml"
 * Domain alias of FUN_00897040 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_i_d_s1(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5de6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a4f62c;

  param_1[0x140] = 1;

  FUN_00896040();

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 9;

  *(uint8_t *)(param_1 + 0x146) = 0;

  NDUIWindow_ReloadInterface("i_d_s.xml");

  FUN_00896b20();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  if (unaff_EDI < 2) {

    param_1[0x147] = 1;

    NDUIWindow_ReloadInterface("i_d_s1.xml");

    FUN_00896b20();

    (**(code **)(*param_1 + 0x448))();

    (**(code **)(*param_1 + 0x34c))();

    param_1[0x13f] = 5;

  }

  else if (1 < unaff_EDI) {

    param_1[0x147] = 2;

    NDUIWindow_ReloadInterface("i_d_s2.xml");

    FUN_00896b20();

    (**(code **)(*param_1 + 0x448))();

    (**(code **)(*param_1 + 0x34c))();

    param_1[0x13f] = 7;

  }

  ExceptionList = local_c;

  return param_1;

}
