// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_005f2b60
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2b60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x005f2b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005ee860, FUN_005f1ec0, FUN_005f2b60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_005f2b60(uint32_t /* width from decompiler */ param_1,float param_2)



{

  float local_a0;

  float local_9c;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  float local_7c;

  float local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50 [6];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_84 = 0;

  local_88 = 0;

  local_8c = 0;

  local_90 = 0;

  local_74 = 0;

  local_78 = 0.0;

  local_7c = 0.0;

  local_80 = 0.0;

  local_64 = 0;

  local_68 = 0.0;

  local_6c = 0.0;

  local_70 = 0.0;

  local_54 = 0;

  local_58 = 0.0;

  local_5c = 0.0;

  local_60 = 0.0;

  local_9c = 0.0;

  local_a0 = 0.0;

  local_50[3] = 0.0;

  local_50[2] = 0.0;

  local_50[1] = 0.0;

  local_34 = 0;

  local_38 = 0;

  local_50[4] = 0.0;

  local_24 = 0;

  local_2c = 0;

  local_30 = 0;

  local_50[0] = g_flOne;

  local_50[5] = g_flOne;

  local_28 = g_flOne;

  local_14 = 0;

  local_18 = 0;

  local_1c = 0;

  local_20 = 0;

  FUN_005f1ec0(param_1,local_50,&local_a0);

  if (local_a0 != g_flZero) {

    param_2 = param_2 / local_a0;

    local_9c = param_2 * local_9c;

    local_80 = local_80 * param_2;

    local_70 = local_70 * param_2;

    local_60 = local_60 * param_2;

    local_7c = local_7c * param_2;

    local_6c = local_6c * param_2;

    local_5c = local_5c * param_2;

    local_78 = local_78 * param_2;

    local_68 = local_68 * param_2;

    local_58 = local_58 * param_2;

    FUN_005ee860(&local_a0);

  }

  return;

}
