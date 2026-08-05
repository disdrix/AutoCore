// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040afb0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0040afb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0040afb0.
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  if (0 < *(int *)(param_1 + 0x34)) {

    piVar2 = *(int **)(param_1 + 0x30);

    do {

      if (*piVar2 == param_3) {

        *param_2 = (*(int **)(param_1 + 0x30))[iVar1 * 2 + 1];

        return;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 2;

    } while (iVar1 < *(int *)(param_1 + 0x34));

  }

  *param_2 = 0;

  return;

}
