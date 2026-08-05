// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_00406420, FUN_00406fc0, FUN_00416e80.
//  - Strings: "HashError:Destructor, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00406420
// -----------------------------------------------------------------------------
// Stable ID: aa_00406420
// Address:   0x00406420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_00406420(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009beaf7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a2c2b0;

  local_4 = 0;

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:Destructor, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  FUN_00406fc0();

  local_4 = 0xffffffff;

  FUN_00416e80(param_1 + 8);

  ExceptionList = local_c;

  return;

}
