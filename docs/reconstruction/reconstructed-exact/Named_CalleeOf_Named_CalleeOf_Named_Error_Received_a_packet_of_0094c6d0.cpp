// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094c6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c6d0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d (+1 other named callers)
// Address:   0x0094c6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007fca10×3, FUN_0094c6d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094c6d0(void)



{

  char cVar1;

  int in_EAX;

  

  cVar1 = (**(code **)(**(int **)(in_EAX + 0x1090) + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_007fca10();

  }

  cVar1 = (**(code **)(**(int **)(in_EAX + 0x106c) + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_007fca10();

  }

  cVar1 = (**(code **)(**(int **)(in_EAX + 0x1038) + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_007fca10();

  }

  return;

}
