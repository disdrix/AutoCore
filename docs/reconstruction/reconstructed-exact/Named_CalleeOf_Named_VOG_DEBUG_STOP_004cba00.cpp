// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00
// -----------------------------------------------------------------------------
// Stable ID: aa_004cba00
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x004cba00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cb4b0, FUN_004cba00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00(int param_1,int *param_2,uint *param_3)



{

  int iVar1;

  

  iVar1 = FUN_004cb4b0(param_3);

  if (iVar1 != *(int *)(param_1 + 4)) {

    if ((*(int *)(iVar1 + 0x14) <= (int)param_3[1]) &&

       ((*(int *)(iVar1 + 0x14) < (int)param_3[1] || (*(uint *)(iVar1 + 0x10) <= *param_3)))) {

      *param_2 = iVar1;

      return;

    }

  }

  *param_2 = *(int *)(param_1 + 4);

  return;

}
