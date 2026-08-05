// =============================================================================
// FUN_005ef3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ef3d0
// Address:   0x005ef3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ef3d0 @ 0x005ef3d0
// Stable ID: aa_005ef3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×2.
//  - Notable callees: FUN_005d68f0×2, FUN_005ef3d0, FUN_006454c0, FUN_00645e80.
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

uint32_t /* width from decompiler */ FUN_005ef3d0(int *param_1,float *param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar3 = 0;

  local_54 = 0.0;

  local_58 = 0.0;

  local_5c = 0.0;

  local_60 = 0.0;

  local_68 = 0.0;

  local_64 = 0.0;

  if (0 < param_1[1]) {

    iVar2 = *param_1;

    iVar4 = 0;

    do {

      FUN_005d68f0(iVar4 + 0x50 + iVar2,iVar4 + 0x10 + iVar2);

      iVar2 = *param_1;

      fVar5 = *(float *)(iVar4 + 4 + iVar2);

      local_60 = local_50 * fVar5 + local_60;

      local_5c = local_4c * fVar5 + local_5c;

      local_58 = local_48 * fVar5 + local_58;

      local_68 = fVar5 + local_68;

      local_54 = local_44 * fVar5 + local_54;

      local_64 = *(float *)(iVar4 + iVar2) + local_64;

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x90;

    } while (iVar3 < param_1[1]);

    if (0.0 < local_68) {

      fVar5 = g_flOne / local_68;

      param_2[4] = fVar5 * local_60;

      param_2[5] = local_5c * fVar5;

      param_2[6] = local_58 * fVar5;

      param_2[7] = local_54 * fVar5;

      param_2[1] = local_68;

      *param_2 = local_64;

      param_2[0xb] = 0.0;

      param_2[10] = 0.0;

      param_2[9] = 0.0;

      param_2[8] = 0.0;

      param_2[0xf] = 0.0;

      param_2[0xe] = 0.0;

      param_2[0xd] = 0.0;

      param_2[0xc] = 0.0;

      iVar3 = 0;

      param_2[0x13] = 0.0;

      param_2[0x12] = 0.0;

      param_2[0x11] = 0.0;

      param_2[0x10] = 0.0;

      local_64 = 0.0;

      if (0 < param_1[1]) {

        do {

          local_40 = *(float *)(*param_1 + 0x20 + iVar3);

          iVar2 = *param_1 + iVar3;

          local_3c = *(float *)(iVar2 + 0x24);

          local_38 = *(float *)(iVar2 + 0x28);

          local_34 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c);

          local_30 = *(float *)(iVar2 + 0x30);

          local_2c = *(float *)(iVar2 + 0x34);

          local_28 = *(float *)(iVar2 + 0x38);

          local_24 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);

          local_20 = *(float *)(iVar2 + 0x40);

          local_1c = *(float *)(iVar2 + 0x44);

          local_18 = *(float *)(iVar2 + 0x48);

          local_14 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c);

          FUN_00645e80(iVar2 + 0x50);

          FUN_005d68f0(iVar3 + *param_1 + 0x50,iVar3 + *param_1 + 0x10);

          local_4c = local_4c - local_5c * fVar5;

          local_48 = local_48 - local_58 * fVar5;

          local_50 = local_50 - fVar5 * local_60;

          fVar1 = *(float *)(iVar3 + 4 + *param_1);

          local_40 = (local_4c * local_4c + local_48 * local_48) * fVar1 + local_40;

          local_18 = (local_50 * local_50 + local_4c * local_4c) * fVar1 + local_18;

          local_3c = local_3c - local_4c * local_50 * fVar1;

          local_2c = (local_50 * local_50 + local_48 * local_48) * fVar1 + local_2c;

          local_28 = local_28 - local_48 * local_4c * fVar1;

          local_38 = local_20 - local_48 * local_50 * fVar1;

          local_30 = local_3c;

          local_20 = local_38;

          local_1c = local_28;

          FUN_006454c0(&local_40);

          local_64 = (float)((int)local_64 + 1);

          iVar3 = iVar3 + 0x90;

        } while ((int)local_64 < param_1[1]);

      }

      return 0;

    }

  }

  return 1;

}
