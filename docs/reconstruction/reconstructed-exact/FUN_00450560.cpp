// =============================================================================
// FUN_00450560
// -----------------------------------------------------------------------------
// Stable ID: aa_00450560
// Address:   0x00450560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450560 @ 0x00450560
// Stable ID: aa_00450560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00444100, FUN_00450560.
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

void __fastcall FUN_00450560(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  void *local_10;

  uint8_t *puStack_c;

  uint8_t local_8;

  undefined3 uStack_7;

  

  puStack_c = &LAB_009be761;

  local_10 = ExceptionList;

  uStack_7 = 0;

  ExceptionList = &local_10;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    local_8 = 1;

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = &PTR_FUN_009d4828;

      param_3[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

      param_3[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

      FUN_00444100(param_3 + 3);

    }

    param_3 = param_3 + 7;

  }

  ExceptionList = local_10;

  return;

}
