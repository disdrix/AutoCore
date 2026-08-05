// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_0058e930
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e930
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x0058e930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0058e930.
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

void __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_0058e930(int param_1,char param_2)



{

  int *piVar1;

  int iVar2;

  

  *(byte *)(param_1 + 0x90e) =

       *(byte *)(param_1 + 0x90e) ^ (param_2 * '\x04' ^ *(byte *)(param_1 + 0x90e)) & 4;

  if (((*(byte *)(param_1 + 0x90f) & 2) != 0) && (*(int *)(param_1 + 0x91c) != 0)) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x91c) + 0x8c);

    piVar1 = (int *)(iVar2 + 0xdc);

    *piVar1 = *piVar1 + 1;

    *(char *)(iVar2 + 0xd0) = param_2;

  }

  return;

}
