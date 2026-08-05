// =============================================================================
// FUN_00514050
// -----------------------------------------------------------------------------
// Stable ID: aa_00514050
// Address:   0x00514050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00514050 @ 0x00514050
// Stable ID: aa_00514050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT13, FUN_00514050.
//  - Return sites: 2.

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

void __thiscall FUN_00514050(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_4;

  

  local_4._0_3_ = 0xdcdcdc;

  iVar1 = (**(code **)(*param_1 + 0x60))();

  if (iVar1 != 0) {

    local_4._0_3_ = 0xff00;

  }

  local_4 = CONCAT13(0xff,(undefined3)local_4);

  if (*(int *)(param_1[0x2a] + 0x38) == 4) {

    *param_2 = 0xffff0a0a;

    return;

  }

  *param_2 = local_4;

  return;

}
