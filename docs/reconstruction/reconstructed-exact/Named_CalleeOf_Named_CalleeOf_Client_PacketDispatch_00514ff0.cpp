// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00514ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00514ff0
// Callee of Named_CalleeOf_Client_PacketDispatch (+2 other named callers)
// Address:   0x00514ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_PacketDispatch (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00514ff0×2, FUN_004e2600.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch (+2 other named callers)
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00514ff0(int param_1)



{

  if (*(char *)(param_1 + 0x25) != '\0') {

    FUN_004e2600(&LAB_00512eb0,&stack0x00000004,0);

  }

  if (*(int *)(param_1 + 0xac) != 0) {

    Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00514ff0(0);

  }

  return;

}
