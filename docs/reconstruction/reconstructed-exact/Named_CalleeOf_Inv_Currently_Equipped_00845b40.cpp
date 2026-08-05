// =============================================================================
// Named_CalleeOf_Inv_Currently_Equipped_00845b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00845b40
// Callee of Inv_Currently_Equipped
// Address:   0x00845b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_Currently_Equipped: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, switch×1.
//  - Notable callees: FUN_00845b40.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Inv_Currently_Equipped
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

uint32_t /* width from decompiler */ Named_CalleeOf_Inv_Currently_Equipped_00845b40(void)



{

  short sVar1;

  int iVar2;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    iVar2 = unaff_ESI[0x2a];

    switch(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x38)) {

    case 6:

      sVar1 = *(short *)(*(int *)(iVar2 + 0x3c) + 0x3f4);

      if ((sVar1 != 0xb) && (sVar1 != 10)) {

        return 0;

      }

    case 10:

    case 0xc:

    case 0xe:

    case 0x1c:

      if ((((0 < *(short *)(*(int *)(iVar2 + 0x3c) + 0x4b4)) ||

           (iVar2 = (**(code **)(*unaff_ESI + 0x60))(), iVar2 != 0)) || (DAT_00d1791c != '\0')) ||

         (((uint)unaff_ESI[0x5f] >> 0x13 & 1) != 0)) {

        return 1;

      }

    }

  }

  return 0;

}
