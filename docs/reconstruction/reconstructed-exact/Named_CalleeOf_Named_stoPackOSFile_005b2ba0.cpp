// =============================================================================
// Named_CalleeOf_Named_stoPackOSFile_005b2ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2ba0
// Callee of Named_stoPackOSFile (+3 other named callers)
// Address:   0x005b2ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_stoPackOSFile: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_stoPackOSFile (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×2.
//  - Notable callees: FUN_005b2ba0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_stoPackOSFile (+3 other named callers)
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

void __fastcall Named_CalleeOf_Named_stoPackOSFile_005b2ba0(int param_1)



{

  void *pvVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x10);

  while (iVar2 != 0) {

    if ((*(int *)(param_1 + 0x10) != 0) &&

       (iVar2 = *(int *)(param_1 + 0x10) + -1, *(int *)(param_1 + 0x10) = iVar2, iVar2 == 0)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    }

    iVar2 = *(int *)(param_1 + 0x10);

  }

  iVar2 = *(int *)(param_1 + 8);

  while (iVar2 != 0) {

    pvVar1 = *(void **)(*(int *)(param_1 + 4) + -4 + iVar2 * 4);

    iVar2 = iVar2 + -1;

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

  }

  if (*(void **)(param_1 + 4) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
