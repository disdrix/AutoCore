// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00771aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00771aa0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00771aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, for×1, while×1.
//  - Notable callees: FUN_007701d0, FUN_00770710, FUN_00770990, FUN_00770ea0, FUN_00771a00, FUN_00771aa0.
//  - Return sites: 4.

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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00771aa0(void)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int *unaff_EBX;

  uint *unaff_ESI;

  

  iVar3 = *unaff_EBX;

  if (iVar3 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = iVar3 * 0x1c + -0x1c;

    for (uVar2 = *(uint *)(unaff_EBX[3] + -4 + iVar3 * 4); uVar2 != 0; uVar2 = uVar2 >> 1) {

      iVar1 = iVar1 + 1;

    }

  }

  iVar1 = iVar1 % 0x1c;

  if (iVar3 < 2) {

    FUN_007701d0();

    *(uint32_t /* width from decompiler */ *)unaff_ESI[3] = 1;

    iVar1 = 1;

    *unaff_ESI = (uint)(*(int *)unaff_ESI[3] != 0);

  }

  else {

    iVar3 = FUN_00770990(iVar1 + -0x1d + iVar3 * 0x1c);

    if (iVar3 != 0) {

      return iVar3;

    }

  }

  iVar1 = iVar1 + -1;

  while( true ) {

    if (0x1b < iVar1) {

      return 0;

    }

    iVar3 = FUN_00771a00();

    if (iVar3 != 0) break;

    iVar3 = FUN_00770710();

    if ((iVar3 != -1) && (iVar3 = FUN_00770ea0(), iVar3 != 0)) {

      return iVar3;

    }

    iVar1 = iVar1 + 1;

  }

  return iVar3;

}
