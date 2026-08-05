// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_A_new_network_client_has_be_00641680
// -----------------------------------------------------------------------------
// Stable ID: aa_00641680
// Callee of Named_CalleeOf_Named_A_new_network_client_has_been_received_hos
// Address:   0x00641680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_A_new_network_client_has_been_received_hos: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00641680.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_A_new_network_client_has_been_received_hos
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_A_new_network_client_has_be_00641680(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[2];

  *param_1 = &PTR_FUN_009e40dc;

  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

  if (*(short *)((int)puVar1 + 6) == 0) {

    (**(code **)*puVar1)(1);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
