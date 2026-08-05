// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0090e1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e1b0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0090e1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: D3DXVec3Normalize×2, FUN_0090e1b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_0090e1b0(float param_1,float param_2,float param_3)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  float *pfVar9;

  float *pfVar10;

  

  iVar8 = DAT_00d17944;

  pfVar1 = (float *)(DAT_00d17944 + 0x21c);

  fVar4 = *(float *)(DAT_00d17944 + 0x21c);

  pfVar2 = (float *)(DAT_00d17944 + 0x224);

  fVar5 = *(float *)(DAT_00d17944 + 0x220);

  pfVar9 = (float *)(DAT_00d17944 + 0x204);

  *pfVar9 = *(float *)(DAT_00d17944 + 0x220) * param_3 - *(float *)(DAT_00d17944 + 0x224) * param_2;

  *(float *)(iVar8 + 0x208) = *pfVar2 * param_1 - *pfVar1 * param_3;

  *(float *)(iVar8 + 0x20c) = fVar4 * param_2 - fVar5 * param_1;

  D3DXVec3Normalize(pfVar9,pfVar9);

  iVar8 = DAT_00d17944;

  pfVar1 = (float *)(DAT_00d17944 + 0x21c);

  pfVar2 = (float *)(DAT_00d17944 + 0x20c);

  pfVar9 = (float *)(DAT_00d17944 + 0x224);

  pfVar3 = (float *)(DAT_00d17944 + 0x204);

  fVar4 = *(float *)(DAT_00d17944 + 0x204);

  fVar5 = *(float *)(DAT_00d17944 + 0x220);

  fVar6 = *(float *)(DAT_00d17944 + 0x21c);

  fVar7 = *(float *)(DAT_00d17944 + 0x208);

  pfVar10 = (float *)(DAT_00d17944 + 0x210);

  *pfVar10 = *(float *)(DAT_00d17944 + 0x20c) * *(float *)(DAT_00d17944 + 0x220) -

             *(float *)(DAT_00d17944 + 0x224) * *(float *)(DAT_00d17944 + 0x208);

  *(float *)(iVar8 + 0x214) = *pfVar9 * *pfVar3 - *pfVar1 * *pfVar2;

  *(float *)(iVar8 + 0x218) = fVar6 * fVar7 - fVar4 * fVar5;

  D3DXVec3Normalize(pfVar10,pfVar10);

  return;

}
