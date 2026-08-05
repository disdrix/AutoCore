// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00696ee0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00696ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00696ee0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696ee0(int param_1,float *param_2,int param_3)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  float local_18 [6];

  

  fVar1 = *(float *)(param_1 + 0x14);

  local_18[5] = *(float *)(param_3 + 0x14);

  if ((int)fVar1 < (int)*(float *)(param_3 + 0x14)) {

    local_18[5] = fVar1;

  }

  local_18[4] = 0.0;

  local_18[3] = 0.0;

  local_18[2] = 0.0;

  local_18[1] = 0.0;

  local_18[0] = 0.0;

  if (5 < (int)local_18[5]) {

    local_18[5] = 7.00649e-45;

  }

  iVar6 = 0;

  if (3 < (int)fVar1) {

    pfVar3 = (float *)(param_3 + 4);

    pfVar4 = (float *)(param_1 + 0xc);

    do {

      iVar6 = iVar6 + 4;

      pfVar2 = pfVar3 + 4;

      *(float *)(&stack0xffffffd8 + iVar6 * 4) = pfVar4[-3] - pfVar3[-1];

      *(float *)((int)pfVar3 + ((int)local_18 - param_3)) =

           *(float *)((param_1 - param_3) + -0x10 + (int)pfVar2) - *pfVar3;

      *(float *)(&stack0xffffffdc + -param_3 + (int)pfVar2) = pfVar4[-1] - pfVar3[1];

      *(float *)(&stack0xffffffe0 + -param_3 + (int)pfVar2) = *pfVar4 - pfVar3[2];

      pfVar3 = pfVar2;

      pfVar4 = pfVar4 + 4;

    } while (iVar6 < (int)fVar1 + -3);

  }

  if (iVar6 < (int)fVar1) {

    iVar5 = (int)fVar1 - iVar6;

    pfVar3 = (float *)(param_3 + iVar6 * 4);

    do {

      iVar5 = iVar5 + -1;

      *(float *)((int)pfVar3 + ((int)local_18 - param_3)) =

           *(float *)((int)pfVar3 + (param_1 - param_3)) - *pfVar3;

      pfVar3 = pfVar3 + 1;

    } while (iVar5 != 0);

  }

  *param_2 = local_18[0];

  param_2[1] = local_18[1];

  param_2[2] = local_18[2];

  param_2[3] = local_18[3];

  param_2[4] = local_18[4];

  param_2[5] = local_18[5];

  return;

}
