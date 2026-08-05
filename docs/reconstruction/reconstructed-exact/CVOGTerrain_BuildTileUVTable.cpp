// READABILITY (auto CF):
//  - Body size: ~221 non-empty decompiler lines.
//  - Control keywords: if×19, do×7, while×7, for×2, return×1.
//  - Notable callees: CVOGTerrain_BuildTileUVTable, Ra, base, corner, indices, mask, r.
//  - Return sites: 1.

// =============================================================================
// CVOGTerrain_BuildTileUVTable
// -----------------------------------------------------------------------------
// Stable ID: aa_005bedd0
// Address:   0x005bedd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* CVOGTerrain::BuildTileUVTable. Startup-generated LUT at 0xb45520: for every combo of 4 corner

   tile indices (8^4 = 4096, index = a*512+b*64+c*8+d for corners a=(x,y) b=(x+1,y) c=(x,y+1)

   d=(x+1,y+1)), computes the 4 texture-stage atlas UVs per corner (0x80 bytes: 16 floats U then 16

   floats V). Distinct corner tiles sorted ascending; LOWEST tile = solid base (atlas column 4) at

   stage 3, higher tiles alpha-blend on top at stages 2..0. Per non-base layer: 4-bit corner-equal

   mask (bit0=a, bit1=c, bit2=b, bit3=d) -> column LUT 0xaf3fc8 [4,0,0,1,0,1,3,2,0,3,1,2,1,2,2,4]

   (0=corner,1=edge,2=three,3=diagonal,4=solid) and rotation LUT 0xaf4008

   [0,0,3,3,1,0,1,0,2,0,2,3,1,1,2,0] (cyclic 90-degree UV rotation; sample art at Ra^r(f),

   Ra(x,y)=(y,1-x)). Atlas cell UV = cell*0.125 + 0.0078125 + local*0.109375 (2-texel inset). Atlas

   layout: row = tile layer 0-7, column = pattern 0-3 / solid variants 4-7. */



void CVOGTerrain_BuildTileUVTable(void)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  uint *puVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  byte local_38 [12];

  float local_2c;

  undefined *local_28;

  int local_24;

  uint local_20;

  uint local_1c;

  uint local_18;

  uint local_14;

  uint local_10 [4];

  

  local_20 = 0;

  local_1c = 0;

  local_18 = 0;

  fVar13 = DAT_00a110c0;

  fVar16 = DAT_00a11080;

  fVar17 = DAT_009d9ca4;

  do {

    local_14 = 0;

    local_24 = (local_1c + (local_18 + local_20 * 8) * 8) * 8;

    do {

      uVar7 = local_14;

      local_10[0] = 0xff;

      if ((int)local_20 < 0xff) {

        local_10[0] = local_20;

      }

      if ((int)local_1c < (int)local_10[0]) {

        local_10[0] = local_1c;

      }

      if ((int)local_18 < (int)local_10[0]) {

        local_10[0] = local_18;

      }

      if ((int)local_14 < (int)local_10[0]) {

        local_10[0] = local_14;

      }

      local_10[1] = 0;

      local_10[2] = 0;

      local_10[3] = 0;

      local_28 = &DAT_00b45520 + (local_24 + local_14) * 0x80;

      iVar9 = 1;

      puVar6 = local_10;

      do {

        uVar2 = *puVar6;

        uVar8 = 0xff;

        if (((int)uVar2 < (int)local_20) && ((int)local_20 < 0xff)) {

          uVar8 = local_20;

        }

        if (((int)uVar2 < (int)local_1c) && ((int)local_1c < (int)uVar8)) {

          uVar8 = local_1c;

        }

        if (((int)uVar2 < (int)local_18) && ((int)local_18 < (int)uVar8)) {

          uVar8 = local_18;

        }

        if (((int)uVar2 < (int)local_14) && ((int)local_14 < (int)uVar8)) {

          uVar8 = local_14;

        }

        if (uVar8 == 0xff) break;

        puVar6[1] = uVar8;

        iVar9 = iVar9 + 1;

        puVar6 = puVar6 + 1;

      } while (iVar9 < 4);

      uVar2 = 0;

      iVar5 = 0;

      local_38[4] = 0;

      local_38[5] = 0;

      local_38[6] = 0;

      local_38[7] = 0;

      local_38[8] = 0;

      local_38[9] = 0;

      local_38[10] = 0;

      local_38[0xb] = 0;

      if (0 < iVar9) {

        do {

          uVar2 = local_10[iVar5];

          uVar8 = (uint)(local_20 == uVar2);

          if (local_1c == uVar2) {

            uVar8 = uVar8 | 2;

          }

          if (local_18 == uVar2) {

            uVar8 = uVar8 | 4;

          }

          if (uVar7 == uVar2) {

            uVar8 = uVar8 | 8;

          }

          bVar1 = *(byte *)(uVar8 * 4 + 0xaf3fc8);

          local_38[iVar5 + 8] = *(byte *)(uVar8 * 4 + 0xaf4008);

          local_38[iVar5 + 4] = (char)uVar2 << 4 | bVar1;

          iVar5 = iVar5 + 1;

        } while (iVar5 < iVar9);

        uVar2 = (uint)local_38[4];

      }

      local_10[3] = uVar2 & 0xf0 | _DAT_00af4004;

      local_10[2] = (uint)local_38[5];

      local_38[3] = local_38[8];

      local_38[2] = local_38[9];

      local_38[1] = local_38[10];

      local_10[1] = (uint)local_38[6];

      local_10[0] = (uint)local_38[7];

      iVar5 = 4 - iVar5;

      local_38[0] = local_38[0xb];

      if (iVar5 < 4) {

        puVar6 = local_10;

        iVar3 = iVar5;

        do {

          *puVar6 = local_10[iVar3];

          local_38[iVar3 - iVar5] = local_38[iVar3];

          iVar3 = iVar3 + 1;

          puVar6 = puVar6 + 1;

          local_38[0xb] = local_38[0];

        } while (iVar3 < 4);

      }

      if ((((byte)local_10[0] & 0xf) == 4) && (iVar9 == 1)) {

        local_10[1] = local_10[0];

        local_38[1] = local_38[0xb];

        local_10[2] = local_10[0];

        local_38[2] = local_38[0xb];

        local_10[3] = local_10[0];

        local_38[3] = local_38[0xb];

      }

      iVar9 = 0;

      pfVar4 = (float *)(local_28 + 0xc);

      do {

        bVar1 = local_38[iVar9];

        fVar10 = (float)(local_10[iVar9] & 0xf) * fVar13 + fVar16;

        fVar11 = (float)((int)local_10[iVar9] >> 4) * fVar13 + fVar16;

        fVar14 = fVar10 + fVar17;

        fVar18 = fVar11 + fVar17;

        pfVar4[-3] = fVar10;

        pfVar4[-2] = fVar14;

        pfVar4[-1] = fVar10;

        *pfVar4 = fVar14;

        pfVar4[0xd] = fVar11;

        pfVar4[0xe] = fVar11;

        pfVar4[0xf] = fVar18;

        pfVar4[0x10] = fVar18;

        if (bVar1 != 0) {

          uVar7 = (uint)local_38[iVar9];

          fVar17 = fVar10;

          fVar16 = fVar14;

          fVar12 = fVar18;

          local_2c = fVar11;

          do {

            fVar20 = local_2c;

            fVar19 = fVar12;

            local_2c = fVar11;

            fVar15 = fVar16;

            fVar13 = fVar14;

            fVar16 = fVar17;

            fVar12 = fVar18;

            fVar17 = fVar10;

            uVar7 = uVar7 - 1;

            fVar10 = fVar13;

            fVar18 = fVar20;

            fVar14 = fVar15;

            fVar11 = fVar19;

          } while (uVar7 != 0);

          pfVar4[-1] = fVar13;

          pfVar4[-3] = fVar17;

          fVar13 = DAT_00a110c0;

          pfVar4[-2] = fVar16;

          fVar16 = DAT_00a11080;

          pfVar4[0xd] = fVar19;

          fVar17 = DAT_009d9ca4;

          *pfVar4 = fVar15;

          pfVar4[0xe] = local_2c;

          pfVar4[0xf] = fVar12;

          pfVar4[0x10] = fVar20;

        }

        iVar9 = iVar9 + 1;

        pfVar4 = pfVar4 + 4;

      } while (iVar9 < 4);

      local_14 = local_14 + 1;

    } while ((int)local_14 < 8);

    local_18 = local_18 + 1;

    if (7 < (int)local_18) {

      local_1c = local_1c + 1;

      if ((int)local_1c < 8) {

        local_18 = 0;

      }

      else {

        local_20 = local_20 + 1;

        if (7 < (int)local_20) {

          return;

        }

        local_1c = 0;

        local_18 = 0;

      }

    }

  } while( true );

}
