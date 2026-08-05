// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_0042bdf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042bdf0
// Callee of Mission_Received_Connect_Request_8x (+1 other named callers)
// Address:   0x0042bdf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Received_Connect_Request_8x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0042bdf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x (+1 other named callers)
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

void Named_CalleeOf_Mission_Received_Connect_Request_8x_0042bdf0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  

  *in_EAX = &PTR_LAB_00a9b1dc;

  puVar2 = (uint32_t /* width from decompiler */ *)in_EAX[1];

  while (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar2[2];

    *puVar2 = 0;

    puVar2[1] = 0;

    puVar2[2] = 0;

    puVar2 = puVar1;

  }

  return;

}
