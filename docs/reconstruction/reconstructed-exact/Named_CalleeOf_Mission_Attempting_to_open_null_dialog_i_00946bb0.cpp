// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00946bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00946bb0
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x00946bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_005742a0, FUN_007246d0, FUN_00801c50, FUN_00943fb0, FUN_00946bb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00946bb0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  Client_GetMissionCompleteAudioTable();

  FUN_007246d0();

  if (*(int *)(in_EAX + 0x31ec) != 0) {

    FUN_005742a0();

  }

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0) != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0);

    for (iVar1 = 0x82; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    **(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0) = 0xffffffff;

  }

  FUN_00801c50(in_EAX);

  FUN_00943fb0();

  return;

}
