// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043ec50
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ec50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0043ec50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_0043ec50.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043ec50(int *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,

                 uint param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  

  for (; (param_2 != param_4 || (param_3 != param_5)); param_3 = param_3 + 1) {

    uVar6 = param_3 >> 2;

    iVar3 = uVar6 * -4;

    if (*(uint *)(param_2 + 8) <= uVar6) {

      uVar6 = uVar6 - *(uint *)(param_2 + 8);

    }

    uVar5 = param_7 >> 2;

    iVar4 = uVar5 * -4;

    if (*(uint *)(param_6 + 8) <= uVar5) {

      uVar5 = uVar5 - *(uint *)(param_6 + 8);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 4) + uVar6 * 4) + (param_3 + iVar3) * 4);

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_6 + 4) + uVar5 * 4) + (param_7 + iVar4) * 4);

    if (puVar2 != puVar1) {

      *puVar2 = *puVar1;

    }

    param_7 = param_7 + 1;

  }

  *param_1 = param_6;

  param_1[1] = param_7;

  return;

}
