// =============================================================================
// FUN_0047fc90
// -----------------------------------------------------------------------------
// Stable ID: aa_0047fc90
// Address:   0x0047fc90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047fc90 @ 0x0047fc90
// Stable ID: aa_0047fc90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~242 non-empty decompiler lines.
//  - Control keywords: if×29, do×9, while×9, return×5, goto×4, for×2.
//  - Notable callees: CONCAT11×3, CONCAT21, CONCAT22, CONCAT31, FUN_0047fc90.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */

FUN_0047fc90(int param_1,int param_2,uint param_3,int *param_4,uint *param_5,ushort *param_6)



{

  short *psVar1;

  short sVar2;

  ushort uVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  byte bVar7;

  int *piVar8;

  int iVar9;

  short sVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  byte bVar14;

  uint uVar15;

  uint uVar16;

  ushort *puVar17;

  uint32_t /* width from decompiler */ local_78;

  uint local_74;

  uint local_70;

  int local_68;

  ushort *local_64;

  uint local_60;

  int local_5c;

  ushort *local_58;

  ushort *local_54;

  uint local_50;

  uint local_4c;

  uint32_t /* width from decompiler */ local_40;

  ushort local_3c [30];

  

  uVar5 = 0;

  local_40 = 0;

  local_3c[0] = 0;

  local_3c[1] = 0;

  local_3c[2] = 0;

  local_3c[3] = 0;

  local_3c[4] = 0;

  local_3c[5] = 0;

  local_3c[6] = 0;

  local_3c[7] = 0;

  local_3c[8] = 0;

  local_3c[9] = 0;

  local_3c[10] = 0;

  local_3c[0xb] = 0;

  local_3c[0xc] = 0;

  local_3c[0xd] = 0;

  if (param_3 != 0) {

    do {

      psVar1 = (short *)((int)&local_40 + (uint)*(ushort *)(param_2 + uVar5 * 2) * 2);

      *psVar1 = *psVar1 + 1;

      uVar5 = uVar5 + 1;

    } while (uVar5 < param_3);

  }

  uVar5 = 0xf;

  do {

    if (*(short *)((int)&local_40 + uVar5 * 2) != 0) break;

    uVar5 = uVar5 - 1;

  } while (uVar5 != 0);

  local_74 = *param_5;

  if (uVar5 < *param_5) {

    local_74 = uVar5;

  }

  if (uVar5 == 0) {

    return 0xffffffff;

  }

  local_70 = 1;

  do {

    if (*(short *)((int)&local_40 + local_70 * 2) != 0) break;

    if (*(short *)((int)&local_40 + local_70 * 2 + 2) != 0) {

      local_70 = local_70 + 1;

      break;

    }

    if (local_3c[local_70] != 0) {

      local_70 = local_70 + 2;

      break;

    }

    if (local_3c[local_70 + 1] != 0) {

      local_70 = local_70 + 3;

      break;

    }

    if (local_3c[local_70 + 2] != 0) {

      local_70 = local_70 + 4;

      break;

    }

    local_70 = local_70 + 5;

  } while (local_70 < 0x10);

  if (local_74 < local_70) {

    local_74 = local_70;

  }

  iVar11 = 1;

  uVar6 = 1;

  do {

    iVar11 = iVar11 * 2 - (uint)*(ushort *)((int)&local_40 + uVar6 * 2);

    if (iVar11 < 0) {

      return 0xffffffff;

    }

    uVar6 = uVar6 + 1;

  } while (uVar6 < 0x10);

  if ((0 < iVar11) && ((param_1 == 0 || (param_3 - (local_40 & 0xffff) != 1)))) {

    return 0xffffffff;

  }

  local_3c[0xf] = 0;

  uVar6 = 2;

  do {

    sVar10 = *(short *)((int)local_3c + uVar6 + 0x1c) + *(short *)((int)&local_40 + uVar6);

    sVar2 = *(short *)((int)&local_40 + uVar6 + 2);

    *(short *)((int)local_3c + uVar6 + 0x1e) = sVar10;

    *(short *)((int)local_3c + uVar6 + 0x20) = sVar2 + sVar10;

    uVar6 = uVar6 + 4;

  } while (uVar6 < 0x1e);

  uVar6 = 0;

  if (param_3 != 0) {

    do {

      if (*(short *)(param_2 + uVar6 * 2) != 0) {

        param_6[local_3c[*(ushort *)(param_2 + uVar6 * 2) + 0xe]] = (ushort)uVar6;

        local_3c[*(ushort *)(param_2 + uVar6 * 2) + 0xe] =

             local_3c[*(ushort *)(param_2 + uVar6 * 2) + 0xe] + 1;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < param_3);

  }

  if (param_1 == 0) {

    local_54 = param_6;

    local_5c = 0x13;

    local_58 = param_6;

  }

  else if (param_1 == 1) {

    local_54 = (ushort *)&DAT_00a27916;

    local_58 = (ushort *)&DAT_00a27956;

    local_5c = 0x100;

  }

  else {

    local_54 = (ushort *)&DAT_00a27b98;

    local_58 = (ushort *)&DAT_00a27bd8;

    local_5c = -1;

  }

  local_68 = *param_4;

  bVar7 = (byte)local_74;

  local_60 = 1 << (bVar7 & 0x1f);

  uVar16 = 0;

  uVar15 = 0;

  uVar6 = local_60 - 1;

  local_4c = 0xffffffff;

  if ((param_1 != 1) || (local_60 < 0x506)) {

    local_64 = param_6;

    local_50 = local_60;

LAB_0047fef0:

    do {

      bVar14 = (byte)uVar15;

      bVar4 = (char)local_70 - bVar14;

      uVar3 = *local_64;

      if ((int)(uint)uVar3 < local_5c) {

        local_78 = (uint)CONCAT21(uVar3,bVar4) << 8;

      }

      else if (local_5c < (int)(uint)uVar3) {

        local_78 = CONCAT22(local_54[*local_64],CONCAT11(bVar4,(char)local_58[*local_64]));

      }

      else {

        local_78 = CONCAT31((uint3)bVar4,0x60);

      }

      iVar11 = 1 << ((char)local_70 - bVar14 & 0x1f);

      piVar8 = (int *)(local_68 + ((uVar16 >> (bVar14 & 0x1f)) + local_50) * 4);

      uVar12 = local_50;

      do {

        uVar12 = uVar12 - iVar11;

        piVar8 = piVar8 + -iVar11;

        *piVar8 = local_78;

      } while (uVar12 != 0);

      for (uVar12 = 1 << ((char)local_70 - 1U & 0x1f); (uVar16 & uVar12) != 0; uVar12 = uVar12 >> 1)

      {

      }

      if (uVar12 == 0) {

        uVar16 = 0;

      }

      else {

        uVar16 = (uVar12 - 1 & uVar16) + uVar12;

      }

      local_64 = local_64 + 1;

      psVar1 = (short *)((int)&local_40 + local_70 * 2);

      *psVar1 = *psVar1 + -1;

      if (*(short *)((int)&local_40 + local_70 * 2) == 0) {

        if (local_70 == uVar5) {

          local_78._0_2_ = CONCAT11((char)local_70 - bVar14,0x40);

          local_78 = (uint)(ushort)local_78;

          goto joined_r0x004800c3;

        }

        local_70 = (uint)*(ushort *)(param_2 + (uint)*local_64 * 2);

      }

    } while ((local_70 <= local_74) || (uVar12 = uVar6 & uVar16, uVar12 == local_4c));

    local_68 = local_68 + local_50 * 4;

    if (uVar15 == 0) {

      uVar15 = local_74;

    }

    iVar9 = local_70 - uVar15;

    uVar13 = uVar15 + iVar9;

    iVar11 = 1 << ((byte)iVar9 & 0x1f);

    if (uVar13 < uVar5) {

      puVar17 = (ushort *)((int)&local_40 + uVar13 * 2);

      do {

        uVar3 = *puVar17;

        if ((int)(iVar11 - (uint)uVar3) < 1) break;

        uVar13 = uVar13 + 1;

        iVar9 = iVar9 + 1;

        puVar17 = puVar17 + 1;

        iVar11 = (iVar11 - (uint)uVar3) * 2;

      } while (uVar13 < uVar5);

    }

    local_50 = 1 << ((byte)iVar9 & 0x1f);

    local_60 = local_60 + local_50;

    if ((param_1 != 1) || (local_60 < 0x506)) {

      *(byte *)(*param_4 + uVar12 * 4) = (byte)iVar9;

      *(byte *)(*param_4 + 1 + uVar12 * 4) = bVar7;

      *(short *)(*param_4 + 2 + uVar12 * 4) = (short)(local_68 - *param_4 >> 2);

      local_4c = uVar12;

      goto LAB_0047fef0;

    }

  }

  return 1;

joined_r0x004800c3:

  if (uVar16 == 0) {

LAB_00480125:

    *param_4 = *param_4 + local_60 * 4;

    *param_5 = local_74;

    return 0;

  }

  if ((uVar15 != 0) && ((uVar6 & uVar16) != local_4c)) {

    local_68 = *param_4;

    uVar15 = 0;

    local_78._0_2_ = CONCAT11(bVar7,(uint8_t)local_78);

    local_78 = (uint)(ushort)local_78;

    local_70 = local_74;

  }

  *(uint *)(local_68 + (uVar16 >> ((byte)uVar15 & 0x1f)) * 4) = local_78;

  for (uVar5 = 1 << ((char)local_70 - 1U & 0x1f); (uVar16 & uVar5) != 0; uVar5 = uVar5 >> 1) {

  }

  if (uVar5 == 0) goto LAB_00480125;

  uVar16 = (uVar5 - 1 & uVar16) + uVar5;

  goto joined_r0x004800c3;

}
