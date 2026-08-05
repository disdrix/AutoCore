// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0076e970
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e970
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0076e970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: SQRT×2, FUN_0076e970.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0076e970(float *param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float *in_EAX;

  uint uVar4;

  float fVar5;

  float fVar6;

  float local_18;

  float local_14;

  float local_10;

  float *local_c [3];

  

  fVar5 = param_1[10] + *param_1 + param_1[5];

  if (fVar5 <= 0.0) {

    uVar4 = (uint)(*param_1 <= param_1[5] && param_1[5] != *param_1);

    if (param_1[uVar4 * 5] <= param_1[10] && param_1[10] != param_1[uVar4 * 5]) {

      uVar4 = 2;

    }

    iVar2 = *(int *)(&DAT_00b017ec + uVar4 * 4);

    iVar3 = *(int *)(&DAT_00b017ec + iVar2 * 4);

    local_c[0] = &local_18;

    local_c[1] = &local_14;

    local_c[2] = &local_10;

    fVar5 = SQRT(((param_1[uVar4 * 5] - param_1[iVar2 * 5]) - param_1[iVar3 * 5]) + g_flOne);

    fVar6 = DAT_00a0f298 / fVar5;

    *local_c[uVar4] = fVar5 * DAT_00a0f298;

    fVar5 = param_1[iVar2 + iVar3 * 4];

    fVar1 = param_1[iVar3 + iVar2 * 4];

    *local_c[iVar2] = (param_1[uVar4 + iVar2 * 4] + param_1[iVar2 + uVar4 * 4]) * fVar6;

    *local_c[iVar3] = (param_1[uVar4 + iVar3 * 4] + param_1[iVar3 + uVar4 * 4]) * fVar6;

    fVar6 = (fVar5 - fVar1) * fVar6;

  }

  else {

    fVar5 = SQRT(fVar5 + g_flOne);

    fVar6 = fVar5 * DAT_00a0f298;

    fVar5 = DAT_00a0f298 / fVar5;

    local_18 = (param_1[9] - param_1[6]) * fVar5;

    local_14 = (param_1[2] - param_1[8]) * fVar5;

    local_10 = (param_1[4] - param_1[1]) * fVar5;

  }

  *in_EAX = 0.0 - local_18;

  in_EAX[1] = 0.0 - local_14;

  in_EAX[2] = 0.0 - local_10;

  in_EAX[3] = fVar6;

  return;

}
