// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00723120
// -----------------------------------------------------------------------------
// Stable ID: aa_00723120
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00723120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004406e0, FUN_0071e570, FUN_00723120.
//  - Return sites: 1.

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

void Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00723120(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

                 uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10)



{

  void *pvVar1;

  

  pvVar1 = operator_new(0x150);

  if (pvVar1 != (void *)0x0) {

    FUN_0071e570(param_2,param_3,param_4,param_5,param_8,param_9,param_10);

  }

  FUN_004406e0();

  return;

}
