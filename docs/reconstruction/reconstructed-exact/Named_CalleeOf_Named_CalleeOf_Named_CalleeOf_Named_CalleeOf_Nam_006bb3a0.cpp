// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bb3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bb3a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bb3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00645a70, FUN_006bb3a0.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bb3a0(int *param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  float *pfVar13;

  int iVar14;

  int iVar15;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  local_40 = *param_2;

  uStack_2c = param_2[1];

  uStack_18 = param_2[2];

  local_20 = 0;

  uStack_1c = 0;

  uStack_14 = 0;

  iVar14 = 0;

  uStack_3c = 0;

  uStack_38 = 0;

  uStack_34 = 0;

  local_30 = 0;

  uStack_28 = 0;

  uStack_24 = 0;

  if (0 < param_1[1]) {

    iVar15 = 0;

    do {

      uVar2 = *(uint32_t /* width from decompiler */ *)(*param_1 + iVar15);

      iVar11 = *param_1 + iVar15;

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar11 + 4);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar11 + 8);

      FUN_00645a70(&local_40);

      puVar12 = (uint32_t /* width from decompiler */ *)(*param_1 + iVar15);

      *puVar12 = uVar2;

      puVar12[1] = uVar3;

      puVar12[2] = uVar4;

      puVar12[3] = 0;

      pfVar1 = (float *)(*param_1 + iVar15);

      fVar5 = pfVar1[1];

      fVar6 = pfVar1[2];

      fVar7 = pfVar1[3];

      fVar8 = param_3[1];

      fVar9 = param_3[2];

      fVar10 = param_3[3];

      pfVar13 = (float *)(*param_1 + iVar15);

      *pfVar13 = *pfVar1 + *param_3;

      pfVar13[1] = fVar5 + fVar8;

      pfVar13[2] = fVar6 + fVar9;

      pfVar13[3] = fVar7 + fVar10;

      iVar14 = iVar14 + 1;

      iVar15 = iVar15 + 0x10;

    } while (iVar14 < param_1[1]);

  }

  return;

}
