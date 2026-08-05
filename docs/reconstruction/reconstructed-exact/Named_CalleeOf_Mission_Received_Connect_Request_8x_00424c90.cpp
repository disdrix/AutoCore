// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_00424c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00424c90
// Callee of Mission_Received_Connect_Request_8x
// Address:   0x00424c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00424c90.
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

void Named_CalleeOf_Mission_Received_Connect_Request_8x_00424c90(void)



{

  int iVar1;

  int *in_EAX;

  int unaff_ESI;

  

  if (*in_EAX != 0) {

    if (in_EAX[1] == 0) {

      *(int *)(*in_EAX + 4) = in_EAX[2];

    }

    else {

      *(int *)(in_EAX[1] + 8) = in_EAX[2];

    }

    if (in_EAX[2] != 0) {

      *(int *)(in_EAX[2] + 4) = in_EAX[1];

    }

  }

  *in_EAX = unaff_ESI;

  if (unaff_ESI != 0) {

    iVar1 = *(int *)(unaff_ESI + 4);

    in_EAX[2] = iVar1;

    if (iVar1 != 0) {

      *(int **)(iVar1 + 4) = in_EAX;

    }

    in_EAX[1] = 0;

    *(int **)(*in_EAX + 4) = in_EAX;

  }

  return;

}
