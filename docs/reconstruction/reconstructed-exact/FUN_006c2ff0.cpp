// =============================================================================
// FUN_006c2ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c2ff0
// Address:   0x006c2ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c2ff0 @ 0x006c2ff0
// Stable ID: aa_006c2ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c2ff0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_006c2ff0(int param_1,int param_2,int *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  fVar1 = *(float *)(param_1 + 0x18);

  fVar2 = *(float *)(param_2 + 0x14);

  fVar3 = *(float *)(param_1 + 0x10);

  fVar4 = *(float *)(param_2 + 8);

  iVar7 = *param_3;

  fVar5 = *(float *)(param_1 + 0x14);

  fVar6 = *(float *)(param_2 + 8);

  puVar8 = (uint32_t /* width from decompiler */ *)param_3[1];

  puVar8[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  puVar8[1] = fVar3 * fVar4;

  *puVar8 = 0x41004;

  puVar8[2] = fVar5 * fVar6;

  *param_3 = iVar7 + 0x20;

  param_3[1] = (int)(puVar8 + 4);

  *(float *)(iVar7 + 0x1c) = fVar1 * fVar2;

  return;

}
