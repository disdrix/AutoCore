// =============================================================================
// Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_005bf920
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf920
// Callee of CVOGTerrainChunk_BuildVertexBuffer
// Address:   0x005bf920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrainChunk_BuildVertexBuffer: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_005bf7d0×4, D3DXVec3Normalize, FUN_005bf920.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGTerrainChunk_BuildVertexBuffer
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_005bf920(int param_1,int param_2,int param_3)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  int local_14;

  int local_10;

  

  iVar5 = param_2;

  iVar2 = *(int *)(param_1 + 0xcc);

  iVar3 = *(int *)(param_2 + 0x14);

  iVar4 = *(int *)(param_2 + 0x18);

  iVar6 = *(int *)(param_2 + 0x1c);

  local_14 = 0;

  param_2 = *(int *)(param_1 + 0xd0) * iVar4;

  if (0 < iVar6) {

    do {

      local_10 = 0;

      iVar9 = iVar2 * iVar4;

      if (0 < iVar6) {

        do {

          pfVar1 = (float *)(iVar3 + (iVar6 * local_14 + local_10) * 0xc);

          uVar7 = FUN_005bf7d0(iVar9 + -1,param_2);

          uVar8 = FUN_005bf7d0(iVar9 + 1,param_2);

          *pfVar1 = (float)(int)((uVar7 & 0xffff) - (uVar8 & 0xffff)) * *(float *)(iVar5 + 0x44);

          pfVar1[1] = *(float *)(iVar5 + 0x3c) * g_flLevelUpUiBase_Inferred;

          uVar7 = FUN_005bf7d0(iVar9,param_2 + 1);

          uVar8 = FUN_005bf7d0(iVar9,param_2 + -1);

          pfVar1[2] = (float)(int)((uVar8 & 0xffff) - (uVar7 & 0xffff)) * *(float *)(iVar5 + 0x44);

          D3DXVec3Normalize(pfVar1,pfVar1);

          iVar6 = *(int *)(iVar5 + 0x1c);

          local_10 = local_10 + param_3;

          iVar9 = iVar9 + param_3;

        } while (local_10 < iVar6);

      }

      iVar6 = *(int *)(iVar5 + 0x1c);

      local_14 = local_14 + param_3;

      param_2 = param_2 + param_3;

    } while (local_14 < iVar6);

  }

  return 0;

}
