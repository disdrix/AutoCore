// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007717c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007717c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x007717c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00770440, FUN_007707d0, FUN_00770990, FUN_00770ea0, FUN_007717c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007717c0(void)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int *unaff_EBX;

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = *unaff_EBX;

    if (iVar1 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = iVar1 * 0x1c + -0x1c;

      for (uVar2 = *(uint *)(unaff_EBX[3] + -4 + iVar1 * 4); uVar2 != 0; uVar2 = uVar2 >> 1) {

        iVar3 = iVar3 + 1;

      }

    }

    iVar1 = FUN_00770990(iVar3);

    if (iVar1 == 0) {

      iVar1 = FUN_00770ea0();

    }

    FUN_007707d0();

  }

  return iVar1;

}
