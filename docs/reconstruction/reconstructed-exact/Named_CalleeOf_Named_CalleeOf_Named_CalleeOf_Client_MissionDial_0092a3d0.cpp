// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_0092a3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a3d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton
// Address:   0x0092a3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0092a3d0, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_0092a3d0(void)



{

  void *_Src;

  void *pvVar1;

  int unaff_EDI;

  

  if (*(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x11c) != *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x120)) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x11c));

  }

  pvVar1 = *(void **)(unaff_EDI + 0x11c);

  if (pvVar1 != (void *)0x0) {

    _Src = *(void **)(unaff_EDI + 0x120);

    if (((int)_Src - (int)pvVar1 >> 2 != 0) && (pvVar1 != _Src)) {

      pvVar1 = memmove(pvVar1,_Src,0);

      *(void **)(unaff_EDI + 0x120) = pvVar1;

    }

  }

  return 1;

}
