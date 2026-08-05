// =============================================================================
// FUN_00656690
// -----------------------------------------------------------------------------
// Stable ID: aa_00656690
// Address:   0x00656690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656690 @ 0x00656690
// Stable ID: aa_00656690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005d6ae0×2, FUN_005eaf20×2, FUN_005b3300, FUN_00656690.
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

void __thiscall FUN_00656690(int param_1,int *param_2)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  uint8_t local_40 [60];

  

  fVar1 = *(float *)(param_1 + 0x94);

  fVar2 = *(float *)(param_1 + 0x90);

  iVar5 = *(int *)(param_1 + 0x9c);

  FUN_005eaf20(param_1 + 0x60,*(uint32_t /* width from decompiler */ *)(param_1 + 0x90));

  local_54 = *(float *)(param_1 + 0x98);

  local_60 = *(float *)(param_1 + 0x70) * local_54;

  local_5c = *(float *)(param_1 + 0x74) * local_54;

  local_58 = *(float *)(param_1 + 0x78) * local_54;

  local_54 = *(float *)(param_1 + 0x7c) * local_54;

  FUN_005d6ae0(local_40,&local_60);

  local_60 = local_60 + *(float *)(param_1 + 0x80);

  local_5c = *(float *)(param_1 + 0x84) + local_5c;

  local_58 = *(float *)(param_1 + 0x88) + local_58;

  local_54 = *(float *)(param_1 + 0x8c) + local_54;

  FUN_005eaf20(param_1 + 0x60,(fVar1 - fVar2) / (float)iVar5);

  iVar5 = *(int *)(param_1 + 0x9c) + 2;

  if ((int)(param_2[2] & 0x7fffffffU) < iVar5) {

    iVar4 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar4 <= iVar5) {

      iVar4 = iVar5;

    }

    FUN_005b3300(param_2,iVar4,0x10);

  }

  pfVar3 = (float *)*param_2;

  param_2[1] = iVar5;

  *pfVar3 = local_60;

  pfVar3[1] = local_5c;

  pfVar3[2] = local_58;

  iVar5 = 0;

  pfVar3[3] = local_54;

  if (-1 < *(int *)(param_1 + 0x9c)) {

    local_64 = 0;

    do {

      local_50 = local_60 - *(float *)(param_1 + 0x80);

      local_4c = local_5c - *(float *)(param_1 + 0x84);

      local_48 = local_58 - *(float *)(param_1 + 0x88);

      local_44 = local_54 - *(float *)(param_1 + 0x8c);

      FUN_005d6ae0(local_40,&local_50);

      local_5c = *(float *)(param_1 + 0x84) + local_4c;

      local_60 = local_50 + *(float *)(param_1 + 0x80);

      iVar4 = *param_2;

      local_58 = *(float *)(param_1 + 0x88) + local_48;

      local_54 = *(float *)(param_1 + 0x8c) + local_44;

      *(float *)(local_64 + 0x10 + iVar4) = local_60;

      *(float *)(local_64 + 0x14 + iVar4) = local_5c;

      iVar4 = local_64 + 0x10 + iVar4;

      *(float *)(iVar4 + 8) = local_58;

      *(float *)(iVar4 + 0xc) = local_54;

      iVar5 = iVar5 + 1;

      local_64 = local_64 + 0x10;

    } while (iVar5 <= *(int *)(param_1 + 0x9c));

  }

  return;

}
