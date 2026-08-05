// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_004bfb20
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfb20
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x004bfb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004bfb20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_004bfb20(int param_1,int param_2)



{

  if (param_2 == 9) {

    return *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x54) +

           *(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x30) +

           *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0xc);

  }

  return *(int *)(param_1 + (param_2 * 3 + 3) * 4);

}
