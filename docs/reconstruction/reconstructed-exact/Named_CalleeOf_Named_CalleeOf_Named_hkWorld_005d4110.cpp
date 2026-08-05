// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005d4110
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4110
// Callee of Named_CalleeOf_Named_hkWorld
// Address:   0x005d4110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SQRT×2, FUN_005d4110.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_hkWorld
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_hkWorld_005d4110(int param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint8_t local_30 [4];

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  

  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))(&DAT_00af4f90,0,local_30);

  iVar1 = *(int *)(param_1 + 0x3c);

  fVar2 = (fStack_34 + fStack_24) * DAT_00a0f298 - *(float *)(iVar1 + 0x28);

  fVar3 = (fStack_38 + fStack_28) * DAT_00a0f298 - *(float *)(iVar1 + 0x24);

  fVar4 = (fStack_3c + fStack_2c) * DAT_00a0f298 - *(float *)(iVar1 + 0x20);

  *(float *)(iVar1 + 0xc) =

       SQRT(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2) +

       SQRT((fStack_2c - fStack_3c) * (fStack_2c - fStack_3c) +

            (fStack_28 - fStack_38) * (fStack_28 - fStack_38) +

            (fStack_24 - fStack_34) * (fStack_24 - fStack_34)) * DAT_00a0f298;

  return;

}
