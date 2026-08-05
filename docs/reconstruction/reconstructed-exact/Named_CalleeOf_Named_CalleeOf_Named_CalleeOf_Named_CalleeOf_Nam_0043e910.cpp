// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043e910
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e910
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0043e910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0043e910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043e910(int param_1,uint param_2,int param_3,uint param_4,uint32_t /* width from decompiler */ *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  

  for (; (param_1 != param_3 || (param_2 != param_4)); param_2 = param_2 + 1) {

    uVar3 = param_2 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(param_1 + 8) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(param_1 + 8);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) + (param_2 + iVar2) * 4);

    if (puVar1 != param_5) {

      *puVar1 = *param_5;

    }

  }

  return;

}
