// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482350
// -----------------------------------------------------------------------------
// Stable ID: aa_00482350
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x00482350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00482350.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

uint8_t __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482350(int *param_1)



{

  int *piVar1;

  int iVar2;

  uint8_t uVar3;

  

  uVar3 = 0;

  iVar2 = *(int *)(*param_1 + 0x14);

  while ((iVar2 != 0 && (param_1[0x14] < param_1[0x13]))) {

    **(uint8_t **)(*param_1 + 0x10) = *(uint8_t *)(param_1[0x14] + param_1[0xb]);

    param_1[0x14] = param_1[0x14] + 1;

    *(int *)(*param_1 + 0x14) = *(int *)(*param_1 + 0x14) + -1;

    *(int *)(*param_1 + 0x10) = *(int *)(*param_1 + 0x10) + 1;

    *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) + 1;

    uVar3 = 1;

    if (*(int *)(*param_1 + 0x18) == 0) {

      piVar1 = (int *)(*param_1 + 0x1c);

      *piVar1 = *piVar1 + 1;

    }

    iVar2 = *(int *)(*param_1 + 0x14);

  }

  return uVar3;

}
