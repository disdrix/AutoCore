// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_0090f8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090f8e0
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali (+1 other named callers)
// Address:   0x0090f8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0076f5f0×3, FUN_0040cf90, FUN_0040d1a0, FUN_0076e970, FUN_0090f8e0, FUN_00972580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_0090f8e0(float param_1,float param_2,float param_3,float param_4,float param_5,

                 float param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  uint8_t local_60 [16];

  uint32_t /* width from decompiler */ local_50 [19];

  

  local_90 = param_4 - param_1;

  local_8c = param_5 - param_2;

  local_88 = param_6 - param_3;

  local_84 = local_90;

  local_80 = local_8c;

  local_7c = local_88;

  FUN_0076f5f0(&local_90,&local_90);

  local_84 = local_8c * 0.0 - local_88 * DAT_00aaa668;

  local_80 = local_88 * 0.0 - local_90 * 0.0;

  local_7c = local_90 * DAT_00aaa668 - local_8c * 0.0;

  fVar4 = local_88;

  fVar5 = local_8c;

  fVar6 = local_90;

  local_78 = local_84;

  local_74 = local_80;

  local_70 = local_7c;

  local_6c = local_84;

  local_68 = local_80;

  local_64 = local_7c;

  FUN_0076f5f0(&local_84,&local_84);

  local_78 = local_7c * fVar5 - local_80 * fVar4;

  local_74 = fVar4 * local_84 - local_7c * fVar6;

  local_70 = local_80 * fVar6 - fVar5 * local_84;

  local_6c = local_78;

  local_68 = local_74;

  local_64 = local_70;

  FUN_0076f5f0(&local_78,&local_78);

  puVar2 = &DAT_00afdf70;

  puVar3 = local_50;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  FUN_00972580(&local_90,&local_78);

  FUN_0076e970();

  FUN_0040d1a0(local_60);

  FUN_0040cf90(&param_1);

  return;

}
