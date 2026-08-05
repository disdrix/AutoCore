// =============================================================================
// CLoadNode__initAnim
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7400
// Address:   0x005c7400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CLoadNode__initAnim @ 0x005c7400
// Stable ID: aa_005c7400
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_initAnim"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_005c6ad0, FUN_005c7290, CLoadNode__initAnim, FUN_0076cf00.
//  - Strings: "CLoadNode::_initAnim".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CLoadNode::_initAnim"
 * Domain alias of FUN_005c7400 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall CLoadNode__initAnim(int param_1,int *param_2,char param_3)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e14;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initAnim");

  local_4 = 0;

  if (param_3 == '\0') {

    iVar1 = FUN_005c6ad0(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x138);

    if (iVar1 == 3) {

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 3;

    }

  }

  else {

    FUN_005c7290(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x138);

  }

  *(uint8_t *)(param_1 + 0x61) = 0;

  (**(code **)(*param_2 + 0x20))();

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
