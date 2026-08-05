// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004278d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004278d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice (+1 other named callers)
// Address:   0x004278d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004278d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004278d0(int param_1,int param_2)



{

  ushort *in_EAX;

  int iVar1;

  int iVar2;

  int *unaff_EBX;

  

  iVar2 = param_2 - param_1 >> 3;

  if (0 < iVar2) {

    do {

      iVar1 = iVar2 / 2;

      if (*(ushort *)(param_1 + 6 + iVar1 * 8) < *in_EAX) {

        param_1 = param_1 + 8 + iVar1 * 8;

        iVar1 = iVar2 + (-1 - iVar1);

      }

      iVar2 = iVar1;

    } while (0 < iVar1);

  }

  *unaff_EBX = param_1;

  return;

}
