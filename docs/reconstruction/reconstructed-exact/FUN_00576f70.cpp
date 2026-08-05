// =============================================================================
// FUN_00576f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00576f70
// Address:   0x00576f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00576f70 @ 0x00576f70
// Stable ID: aa_00576f70
// Embedded strings (evidence for future rename):
//   - "CVOGPhaseDistort::AddPieceInstance()"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0076cef0×2, CVOGPhaseDistort::AddPieceInstance, FUN_004506a0, FUN_00576f70, FUN_0076cf00.
//  - Strings: "CVOGPhaseDistort::AddPieceInstance()".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_00576f70(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a515c;

  local_c = ExceptionList;

  if (DAT_00b04814 != '\0') {

    return 0;

  }

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGPhaseDistort::AddPieceInstance()");

  local_4 = 0;

  if (*(int *)(*(int *)(param_1 + 4) + 0x108) != 0) {

    local_4 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_c;

    return 0;

  }

  FUN_004506a0(&stack0x00000004);

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 1;

}
