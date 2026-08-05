// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryGrabResponse_00931d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00931d60
// Callee of Named_CalleeOf_Client_RecvInventoryGrabResponse (+1 other named callers)
// Address:   0x00931d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryGrabResponse: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvInventoryGrabResponse (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_008800e0, FUN_0088ef70, FUN_00931d60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryGrabResponse (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryGrabResponse_00931d60(void)



{

  char cVar1;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x1078) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1078) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008800e0();

    }

  }

  if (*(int *)(unaff_EDI + 0x105c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x105c) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_0088ef70();

    }

  }

  return;

}
