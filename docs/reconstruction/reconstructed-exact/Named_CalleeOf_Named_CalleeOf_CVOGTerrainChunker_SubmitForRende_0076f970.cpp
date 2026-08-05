// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_0076f970
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f970
// Callee of Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering
// Address:   0x0076f970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×14, for×7, return×1.
//  - Notable callees: FUN_00412d80×8, FUN_0076eb00×3, FUN_0076e6b0, FUN_0076f970.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_0076f970(float *param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ *param_4,int param_5,

            uint32_t /* width from decompiler */ *param_6)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  float *in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *local_280;

  uint8_t *local_27c;

  uint8_t *local_278;

  uint32_t /* width from decompiler */ *local_274;

  uint32_t /* width from decompiler */ *local_270;

  uint8_t *local_26c;

  uint32_t /* width from decompiler */ *local_268;

  uint32_t /* width from decompiler */ *local_264;

  uint8_t local_260 [16];

  uint32_t /* width from decompiler */ local_250 [12];

  float local_220;

  float local_21c;

  float local_218;

  uint32_t /* width from decompiler */ local_210 [12];

  float local_1e0;

  float local_1dc;

  float local_1d8;

  uint32_t /* width from decompiler */ local_1d0 [12];

  uint32_t /* width from decompiler */ local_1a0;

  uint32_t /* width from decompiler */ local_19c;

  uint32_t /* width from decompiler */ local_198;

  uint32_t /* width from decompiler */ local_190 [5];

  uint32_t /* width from decompiler */ local_17c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_150 [12];

  float local_120;

  float local_11c;

  float local_118;

  uint32_t /* width from decompiler */ local_110 [12];

  float local_e0;

  float local_dc;

  float local_d8;

  uint8_t local_d0 [64];

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  local_280 = (uint32_t /* width from decompiler */ *)0x0;

  local_264 = (uint32_t /* width from decompiler */ *)0x0;

  if (in_EAX != (float *)0x0) {

    fVar1 = *in_EAX;

    puVar4 = &DAT_00afdf70;

    puVar5 = local_210;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_1dc = in_EAX[1];

    local_1d8 = in_EAX[2];

    puVar4 = &DAT_00afdf70;

    puVar5 = local_150;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_120 = 0.0 - *in_EAX;

    local_11c = 0.0 - in_EAX[1];

    local_280 = local_210;

    local_264 = local_150;

    local_118 = 0.0 - in_EAX[2];

    local_1e0 = fVar1;

  }

  local_27c = (uint8_t *)0x0;

  local_26c = (uint8_t *)0x0;

  if (param_3 != 0) {

    FUN_0076eb00(local_d0,param_3);

    FUN_0076e6b0(local_260,param_3);

    FUN_0076eb00(local_90,local_260);

    local_27c = local_d0;

    local_26c = local_90;

  }

  local_274 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

    uVar2 = *param_4;

    puVar4 = &DAT_00afdf70;

    puVar5 = local_190;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_190[0] = uVar2;

    local_17c = param_4[1];

    local_274 = local_190;

    local_168 = param_4[2];

  }

  local_270 = (uint32_t /* width from decompiler */ *)0x0;

  local_268 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_1 != (float *)0x0) {

    fVar1 = *param_1;

    puVar4 = &DAT_00afdf70;

    puVar5 = local_110;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_e0 = fVar1;

    local_dc = param_1[1];

    local_d8 = param_1[2];

    puVar4 = &DAT_00afdf70;

    puVar5 = local_250;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_220 = 0.0 - *param_1;

    local_21c = 0.0 - param_1[1];

    local_218 = 0.0 - param_1[2];

    local_270 = local_110;

    local_268 = local_250;

  }

  local_278 = (uint8_t *)0x0;

  if (param_5 != 0) {

    FUN_0076eb00(local_50,param_5);

    local_278 = local_50;

  }

  puVar4 = &DAT_00afdf70;

  iVar3 = 0x10;

  if (param_6 != (uint32_t /* width from decompiler */ *)0x0) {

    uVar2 = *param_6;

    puVar5 = local_1d0;

    for (; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    local_1a0 = uVar2;

    local_19c = param_6[1];

    local_198 = param_6[2];

    puVar4 = local_1d0;

  }

  puVar5 = param_2;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  if (local_270 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00412d80(param_2,local_270,param_2);

  }

  if (local_278 != (uint8_t *)0x0) {

    FUN_00412d80(param_2,local_278,param_2);

  }

  if (local_268 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00412d80(param_2,local_268,param_2);

  }

  if (local_280 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00412d80(param_2,local_280,param_2);

  }

  if (local_27c != (uint8_t *)0x0) {

    FUN_00412d80(param_2,local_27c,param_2);

  }

  if (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00412d80(param_2,local_274,param_2);

  }

  if (local_26c != (uint8_t *)0x0) {

    FUN_00412d80(param_2,local_26c,param_2);

  }

  if (local_264 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00412d80(param_2,local_264,param_2);

  }

  return param_2;

}
