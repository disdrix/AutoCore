// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_0074c8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c8a0
// Callee of Named_gfxGeometryPiece
// Address:   0x0074c8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_0074c700, FUN_0074c8a0, FUN_00972fa0, SQRT.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPiece
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_gfxGeometryPiece_0074c8a0(int param_1,int param_2,float *param_3,float *param_4,float *param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_c;

  float local_8;

  float local_4;

  

  if (*(char *)(param_1 + 0x2c) != '\0') {

    return 0;

  }

  if (*(char *)(param_2 + 0xb8) != '\0') {

    uVar1 = FUN_0074c700(param_4,param_5);

    return uVar1;

  }

  FUN_00972fa0(param_1);

  fVar3 = local_c - *param_3;

  fVar4 = local_8 - param_3[1];

  fVar5 = local_4 - param_3[2];

  fVar6 = *(float *)(param_2 + 0x9c) * *(float *)(param_1 + 0xc);

  fVar2 = fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5;

  fVar6 = fVar6 * fVar6;

  fVar3 = param_4[1] * fVar4 + param_4[2] * fVar5 + *param_4 * fVar3;

  if (((fVar2 < fVar6) || (0.0 <= fVar3)) && (fVar6 = fVar6 - (fVar2 - fVar3 * fVar3), 0.0 <= fVar6)

     ) {

    if (param_5 != (float *)0x0) {

      *param_5 = fVar3 - SQRT(fVar6);

    }

    return 1;

  }

  return 0;

}
