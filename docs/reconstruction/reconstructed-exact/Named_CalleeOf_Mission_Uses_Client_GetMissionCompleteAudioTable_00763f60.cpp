// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00763f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00763f60
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00763f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004380f0, FUN_00763740, FUN_00763f60, FUN_00968110, FUN_0096aec0, FUN_0096d7a0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00763f60(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b0ac6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_00a9da8c;

  local_4 = 5;

  FUN_00763740();

  local_4._0_1_ = 4;

  FUN_004380f0();

  local_4._0_1_ = 3;

  FUN_00968110(param_1 + 0x37);

  if ((void *)param_1[0x34] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x34]);

  }

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  if ((void *)param_1[0x30] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x30]);

  }

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0096aec0(param_1 + 0x26);

  local_4 = 0xffffffff;

  FUN_0096d7a0();

  ExceptionList = local_c;

  return;

}
