// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00763740
// -----------------------------------------------------------------------------
// Stable ID: aa_00763740
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00763740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00437cd0, FUN_00437ce0, FUN_0044aaf0, FUN_0044aeb0, FUN_00745ea0, FUN_0074b510, FUN_00763370, FUN_00763400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00763740(int *param_1)



{

  int *piVar1;

  

  if (param_1[0x24] != 0) {

    FUN_00745ea0();

    param_1[0x24] = 0;

  }

  piVar1 = (int *)FUN_00437cd0();

  param_1[0x23] = *piVar1;

  FUN_00763400();

  FUN_00763370();

  FUN_0096ae70();

  param_1[0x2e] = -1;

  FUN_00437ce0();

  if ((uint32_t /* width from decompiler */ *)param_1[0x25] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x25])(1);

  }

  param_1[0x25] = 0;

  FUN_0096d6d0();

  FUN_0074b510();

  FUN_0044aaf0();

  FUN_0044aeb0();

  param_1[0x1e] = 0;

  (**(code **)(*param_1 + 0x30))(3);

  return;

}
