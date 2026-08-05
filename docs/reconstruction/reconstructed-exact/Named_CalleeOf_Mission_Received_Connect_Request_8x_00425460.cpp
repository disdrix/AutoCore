// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_00425460
// -----------------------------------------------------------------------------
// Stable ID: aa_00425460
// Callee of Mission_Received_Connect_Request_8x
// Address:   0x00425460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00425460.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x
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

void __fastcall Named_CalleeOf_Mission_Received_Connect_Request_8x_00425460(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *in_EAX;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = in_EAX[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = in_EAX[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = in_EAX[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = in_EAX[4];

  return;

}
