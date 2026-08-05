// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00450d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00450d70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF
// Address:   0x00450d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00450d70, FUN_00450e00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGSpecGlowF
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00450d70(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar2 = in_EAX;

  while( true ) {

    iVar3 = iVar2 * 2 + 2;

    if (param_2 <= iVar3) break;

    piVar1 = *(int **)(param_1 + -4 + iVar3 * 4);

    fVar4 = (float10)(**(code **)(**(int **)(param_1 + iVar3 * 4) + 8))();

    fVar5 = (float10)(**(code **)(*piVar1 + 8))();

    if ((float10)(float)fVar4 < fVar5) {

      iVar3 = iVar2 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 4);

    iVar2 = iVar3;

  }

  if (iVar3 == param_2) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_2 * 4);

  }

  FUN_00450e00(param_1,in_EAX,param_3,param_4);

  return;

}
