// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8370
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8370
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x005b8370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005b8370.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8370(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int *piVar1;

  

  if (-1 < param_2) {

    piVar1 = operator_new(0x1c);

    if (piVar1 != (int *)0x0) {

      piVar1[4] = param_5;

      piVar1[2] = param_2;

      *piVar1 = 0;

      piVar1[1] = 0;

      piVar1[3] = 0;

      piVar1[5] = param_4 - param_5;

      piVar1[6] = param_3;

      piVar1[1] = (int)param_1;

      *piVar1 = *param_1;

      *(int **)(*param_1 + 4) = piVar1;

      *param_1 = (int)piVar1;

      return;

    }

    _DAT_00000000 = *param_1;

    piRam00000004 = param_1;

    *(uint32_t /* width from decompiler */ *)(*param_1 + 4) = 0;

    *param_1 = 0;

  }

  return;

}
