// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_007839b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007839b0
// Callee of Mission_Received_Connect_Request_8x (+1 other named callers)
// Address:   0x007839b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Received_Connect_Request_8x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0077c610, FUN_0077cc20, FUN_007839b0.
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

void Named_CalleeOf_Mission_Received_Connect_Request_8x_007839b0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  unaff_ESI[1] = 0;

  unaff_ESI[2] = 0;

  *unaff_ESI = &PTR_LAB_00a9b28c;

  FUN_0077cc20();

  unaff_ESI[7] = *unaff_EDI;

  unaff_ESI[8] = unaff_EDI[1];

  unaff_ESI[9] = unaff_EDI[2];

  unaff_ESI[10] = unaff_EDI[3];

  unaff_ESI[3] = *unaff_EDI;

  unaff_ESI[4] = unaff_EDI[1];

  unaff_ESI[5] = unaff_EDI[2];

  unaff_ESI[6] = unaff_EDI[3];

  FUN_0077c610(unaff_ESI + 3,unaff_ESI + 0x17,unaff_ESI + 0x1b);

  unaff_ESI[0x9c] = 0;

  return;

}
