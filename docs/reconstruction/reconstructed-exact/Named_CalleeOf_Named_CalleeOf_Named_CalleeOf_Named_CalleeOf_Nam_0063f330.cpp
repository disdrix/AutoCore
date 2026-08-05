// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0063f330
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f330
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld
// Address:   0x0063f330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0063f330.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_hkWorld
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

float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0063f330(int param_1,int *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint8_t local_30 [4];

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  

  if (param_2 != (int *)0x0) {

    (**(code **)(*param_2 + 0x18))(&DAT_00af4f90,0,local_30);

    fVar2 = (fStack_28 - fStack_38) * DAT_00a0f298;

    fVar1 = (fStack_2c - fStack_3c) * DAT_00a0f298;

    fVar3 = (fStack_24 - fStack_34) * DAT_00a0f298;

    *(float *)(param_1 + 8) = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;

    return (float10)*(float *)(param_1 + 8);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = DAT_00aaa668;

  return (float10)*(float *)(param_1 + 8);

}
