// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00808ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00808ea0
// Callee of Client_PacketDispatch
// Address:   0x00808ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00808ea0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_00808ea0(void)



{

  char cVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

    if (cVar1 != '\0') {

      Client_LookupObjectByTfid_Inferred

                (*(byte *)(unaff_EDI + 0x10),*(uint *)(unaff_EDI + 8),*(uint *)(unaff_EDI + 0xc));

    }

  }

  return;

}
