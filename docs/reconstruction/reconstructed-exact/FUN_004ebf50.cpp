// =============================================================================
// FUN_004ebf50
// -----------------------------------------------------------------------------
// Stable ID: aa_004ebf50
// Address:   0x004ebf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ebf50 @ 0x004ebf50
// Stable ID: aa_004ebf50
// Embedded strings (evidence for future rename):
//   - "CollectAllSoundPreloads"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004a04f0, FUN_004eb3b0, FUN_004ebf50, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CollectAllSoundPreloads".
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

void __thiscall FUN_004ebf50(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a27cf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CollectAllSoundPreloads");

  local_4 = 0;

  FUN_004eb3b0();

  if (*(int *)(param_1 + 0x88) != 0) {

    FUN_004a04f0(param_2,0,1,0);

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
