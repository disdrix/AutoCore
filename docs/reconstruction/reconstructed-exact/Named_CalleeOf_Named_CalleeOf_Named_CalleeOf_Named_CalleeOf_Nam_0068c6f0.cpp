// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068c6f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068c6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004490a0×3, FUN_005971e0×3, FUN_0068c6f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c6f0(int param_1,float *param_2)



{

  int iVar1;

  float *pfVar2;

  float local_c;

  float local_8;

  float local_4;

  

  local_4 = param_2[1];

  local_c = -*param_2;

  local_8 = param_2[2];

  iVar1 = *(int *)(param_1 + 100);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x6c) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0x68) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x68),1,&local_c);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0x68);

    *pfVar2 = local_c;

    *(float **)(param_1 + 0x68) = pfVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 100);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x6c) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0x68) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x68),1,&local_8);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0x68);

    *pfVar2 = local_8;

    *(float **)(param_1 + 0x68) = pfVar2 + 1;

  }

  iVar1 = *(int *)(param_1 + 100);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0x6c) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0x68) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x68),1,&local_4);

  }

  else {

    pfVar2 = *(float **)(param_1 + 0x68);

    *pfVar2 = local_4;

    *(float **)(param_1 + 0x68) = pfVar2 + 1;

  }

  if ((*(char *)(param_1 + 8) != '\0') && (*(int *)(param_1 + 0x14) == 1)) {

    FUN_005971e0(&local_c);

    FUN_005971e0(&local_8);

    FUN_005971e0(&local_4);

  }

  return;

}
