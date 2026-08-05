// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Used_for_mission_00439dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00439dd0
// Callee of Named_CalleeOf_Mission_Used_for_mission
// Address:   0x00439dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Used_for_mission: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00439dd0, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Used_for_mission
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

void * __thiscall Named_CalleeOf_Named_CalleeOf_Mission_Used_for_mission_00439dd0(void *param_1,void *param_2)



{

  size_t _Size;

  int in_EAX;

  void *pvVar1;

  

  _Size = (in_EAX - (int)param_1 >> 2) * 4;

  pvVar1 = memmove(param_2,param_1,_Size);

  return (void *)((int)pvVar1 + _Size);

}
