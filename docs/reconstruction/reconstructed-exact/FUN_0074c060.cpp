// =============================================================================
// FUN_0074c060
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c060
// Address:   0x0074c060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074c060 @ 0x0074c060
// Stable ID: aa_0074c060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: SQRT×3, FUN_0076f5f0×2, FUN_00972fa0×2, FUN_009732d0×2, FUN_0074c060.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_0074c060(float *param_1,float *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  float *pfVar2;

  int unaff_EBX;

  int unaff_ESI;

  float fVar3;

  float fVar4;

  float fVar5;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  uint8_t local_18 [24];

  

  local_30 = *(float *)(unaff_EBX + 0x90) - *(float *)(unaff_ESI + 0x90);

  local_2c = *(float *)(unaff_EBX + 0x94) - *(float *)(unaff_ESI + 0x94);

  local_28 = *(float *)(unaff_EBX + 0x98) - *(float *)(unaff_ESI + 0x98);

  local_3c = *param_1;

  local_38 = param_1[1];

  local_34 = param_1[2];

  uVar1 = FUN_00972fa0(param_2);

  pfVar2 = (float *)FUN_009732d0(local_18,uVar1);

  local_48 = *pfVar2 - local_3c;

  local_44 = pfVar2[1] - local_38;

  local_40 = pfVar2[2] - local_34;

  FUN_0076f5f0(&local_48,&local_48);

  fVar5 = param_1[3];

  local_48 = *(float *)(unaff_EBX + 0x9c) * local_48 * fVar5;

  local_24 = *param_2;

  local_44 = *(float *)(unaff_EBX + 0xa0) * local_44 * fVar5;

  local_20 = param_2[1];

  local_1c = param_2[2];

  local_40 = *(float *)(unaff_EBX + 0xa4) * local_40 * fVar5;

  uVar1 = FUN_00972fa0(param_1);

  pfVar2 = (float *)FUN_009732d0(local_18,uVar1);

  local_3c = *pfVar2 - local_24;

  local_38 = pfVar2[1] - local_20;

  local_34 = pfVar2[2] - local_1c;

  FUN_0076f5f0(&local_3c,&local_3c);

  fVar5 = param_2[3];

  fVar3 = *(float *)(unaff_ESI + 0x9c) * local_3c * fVar5;

  fVar4 = *(float *)(unaff_ESI + 0xa0) * local_38 * fVar5;

  fVar5 = *(float *)(unaff_ESI + 0xa4) * local_34 * fVar5;

  if (SQRT(local_30 * local_30 + local_2c * local_2c + local_28 * local_28) <

      SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5) +

      SQRT(local_48 * local_48 + local_44 * local_44 + local_40 * local_40)) {

    return 1;

  }

  return 0;

}
