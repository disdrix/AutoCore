// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090
// -----------------------------------------------------------------------------
// Stable ID: aa_00916090
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00916090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004e9530, FUN_0055e530, FUN_00916090, SQRT.
//  - Return sites: 2.

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

float10 Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090(float param_1,float param_2,float param_3,float param_4,float param_5,

                    float param_6)



{

  int *unaff_ESI;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_80;

  float local_7c;

  float local_78;

  float local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  uint8_t local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint8_t local_40 [20];

  float local_2c;

  int local_20;

  

  local_70 = param_1;

  local_6c = param_2;

  local_68 = param_3;

  local_60 = param_4;

  local_64 = 0;

  local_5c = param_5;

  local_54 = 0;

  local_50 = 0;

  local_4c = 7;

  local_58 = param_6;

  local_2c = g_flOne;

  local_20 = 0;

  FUN_0055e530(&local_70,local_40);

  if (local_20 != 0) {

    if (unaff_ESI != (int *)0x0) {

      *unaff_ESI = local_20;

    }

    fVar1 = g_flOne - local_2c;

    fVar2 = fVar1 * local_70;

    fVar5 = local_60 * local_2c;

    fVar3 = local_5c * local_2c;

    fVar6 = local_6c * fVar1;

    fVar4 = local_58 * local_2c;

    fVar1 = local_68 * fVar1;

    FUN_004e9530(&local_80,&param_1);

    local_80 = (fVar2 + fVar5) - local_80;

    local_7c = (fVar3 + fVar6) - local_7c;

    local_78 = (fVar4 + fVar1) - local_78;

    return SQRT((float10)local_80 * (float10)local_80 +

                (float10)local_7c * (float10)local_7c + (float10)local_78 * (float10)local_78);

  }

  if (unaff_ESI != (int *)0x0) {

    *unaff_ESI = 0;

  }

  return (float10)g_flZero;

}
