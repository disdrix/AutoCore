// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00782bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00782bb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00782bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, goto×3, while×2, return×2, do×1.
//  - Notable callees: FUN_00782bb0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00782bb0(void)



{

  int *piVar1;

  int *in_EAX;

  int iVar2;

  int *unaff_EBX;

  int unaff_EDI;

  

  if (in_EAX != (int *)0x0) goto LAB_00782bc0;

  piVar1 = (int *)unaff_EBX[1];

  do {

    while( true ) {

      in_EAX = piVar1;

      if (in_EAX == (int *)0x0) goto LAB_00782bd9;

LAB_00782bc0:

      iVar2 = (**(code **)(*in_EAX + 4))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14));

      if (iVar2 < 1) break;

      piVar1 = (int *)in_EAX[3];

      if ((int *)in_EAX[3] == (int *)0x0) {

        in_EAX[3] = unaff_EDI;

        goto LAB_00782bd9;

      }

    }

    if (-1 < iVar2) {

      return 0;

    }

    piVar1 = (int *)in_EAX[2];

  } while ((int *)in_EAX[2] != (int *)0x0);

  in_EAX[2] = unaff_EDI;

LAB_00782bd9:

  *(int **)(unaff_EDI + 0x10) = in_EAX;

  if (in_EAX == (int *)0x0) {

    unaff_EBX[1] = unaff_EDI;

  }

  *unaff_EBX = *unaff_EBX + 1;

  *(int **)(unaff_EDI + 4) = unaff_EBX;

  return 1;

}
