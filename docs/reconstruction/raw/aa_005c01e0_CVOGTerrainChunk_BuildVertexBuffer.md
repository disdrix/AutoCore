# Raw capture: CVOGTerrainChunk_BuildVertexBuffer

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c01e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c01e0` |
| **Canonical name** | `CVOGTerrainChunk_BuildVertexBuffer` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005c047c) */
/* CVOGTerrainChunk::BuildVertexBuffer [VOGTerrainChunker.cpp]. Fills the chunk VB. param_3=LOD step
   (1 = full detail). Per cell: GetCornerData (0x5bf480) fetches {u16 height16, u8 tile(G&7), float
   packedTintColor} for the 4 corners; vertex Y = height16 * heightScale (param_2+0x44 =
   HeightScale/256, i.e. 16-bit height!). The 4 corner tile indices (3 bits each) form a 12-bit
   combo -> UV lookup table at 0xb45520 (combo * 0x80 bytes = u[4 stages][4 corners] then v[4][4])
   giving each of the 4 texture-stage UVs into the 8x8 tileset atlas (tile2_*.dds). When all 4
   corners share one tile, a random (rand&3)*0.125 U offset picks one of the 4 solid variant
   columns. LOD path (param_3>1) instead writes a single continuous UV (far/cheap shader). Blending
   itself is in NDDiffTerrainLayered2.fx: lerp stages by atlas alpha, *2*vertColor. */

int __thiscall
CVOGTerrainChunk_BuildVertexBuffer(int param_1,int param_2,int param_3,float *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float *local_98;
  float *local_94;
  float *local_8c;
  int local_84;
  float local_7c;
  int local_78;
  float local_6c;
  int local_64;
  ushort local_50 [2];
  float local_4c;
  float local_48;
  undefined4 local_38;
  void *local_34;
  ushort local_30;
  byte local_2e;
  float local_2c;
  undefined4 local_28;
  float local_24;
  ushort local_20;
  byte local_1e;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009a6c80;
  local_14 = ExceptionList;
  iVar2 = *(int *)(param_2 + 0x18) / param_3;
  fVar18 = (float)param_3;
  fVar13 = *(float *)(param_2 + 0x3c) * fVar18;
  iVar2 = iVar2 * iVar2 * 6;
  ExceptionList = &local_14;
  FUN_005bf920(param_2,param_3);
  if (param_3 == 1) {
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
    uVar3 = FUN_00414bc0(0x4d2);
    local_c = 0;
    iVar4 = FUN_00414c20(iVar2,uVar3,0x20,0);
    local_c = 0xffffffff;
    local_28 = 0;
    local_24 = 0.0;
    if (local_34 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(local_34);
    }
    if (iVar4 < 0) {
      ExceptionList = local_14;
      return 0;
    }
    iVar4 = *(int *)(param_1 + 0x14);
    if ((*(int *)(iVar4 + 0x10) == 0) ||
       (pfVar5 = (float *)FUN_00746520(*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18),0
                                      ), pfVar5 == (float *)0x0)) {
      if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) == 0) {
        ExceptionList = local_14;
        return 0;
      }
      FUN_007464e0();
      ExceptionList = local_14;
      return 0;
    }
    *(undefined1 *)(param_1 + 0xe8) = 1;
    fVar18 = (float)*(int *)(param_1 + 0xd0) * *(float *)(param_2 + 0x40);
    iVar4 = *(int *)(param_2 + 0x18) + -1;
    local_84 = 0;
    if (-1 < iVar4) {
      do {
        local_6c = (float)*(int *)(param_1 + 0xcc) * *(float *)(param_2 + 0x40);
        if (-1 < iVar4) {
          local_8c = pfVar5 + -0x30;
          local_94 = pfVar5 + -0x10;
          iVar4 = 0;
          local_98 = pfVar5 + 3;
          do {
            iVar8 = *(int *)(param_2 + 0x1c) * local_84 + iVar4;
            iVar7 = local_84 + 1;
            iVar6 = *(int *)(param_2 + 0x1c) * iVar7 + iVar4;
            CVOGTerrainChunk_GetCornerData(&local_38,iVar4,local_84);
            iVar9 = iVar4 + 1;
            CVOGTerrainChunk_GetCornerData(&local_30,iVar9,local_84);
            CVOGTerrainChunk_GetCornerData(&local_28,iVar4,iVar7);
            CVOGTerrainChunk_GetCornerData(&local_20,iVar9,iVar7);
            fVar14 = 0.0;
            iVar4 = ((uint)local_1e +
                    ((uint)local_28._2_1_ + ((uint)local_2e + (uint)local_38._2_1_ * 8) * 8) * 8) *
                    0x80;
            if (((local_38._2_1_ == local_2e) && (local_2e == local_28._2_1_)) &&
               (local_28._2_1_ == local_1e)) {
              iVar7 = CVOGReaction_RandomUnitScalar();
              if (0xfffff < *(int *)(iVar7 + 0xc)) {
                *(undefined4 *)(iVar7 + 0xc) = 0;
              }
              uVar1 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);
              *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
              fVar14 = (float)(uVar1 & 3) * DAT_00a110c0;
            }
            *pfVar5 = local_6c;
            pfVar5[1] = (float)((uint)local_38 & 0xffff) * *(float *)(param_2 + 0x44);
            pfVar5[2] = fVar18;
            pfVar5[8] = *(float *)(&DAT_00b45520 + iVar4) + fVar14;
            pfVar5[9] = *(float *)(&DAT_00b45560 + iVar4);
            pfVar5[10] = *(float *)(&DAT_00b45530 + iVar4) + fVar14;
            pfVar5[0xb] = *(float *)(&DAT_00b45570 + iVar4);
            pfVar5[0xc] = *(float *)(&DAT_00b45540 + iVar4) + fVar14;
            pfVar5[0xd] = *(float *)(&DAT_00b45580 + iVar4);
            pfVar5[0xe] = *(float *)(&DAT_00b45550 + iVar4) + fVar14;
            pfVar5[0xf] = *(float *)(&DAT_00b45590 + iVar4);
            pfVar5[7] = 0.0;
            pfVar10 = (float *)(*(int *)(param_2 + 0x14) + iVar8 * 0xc);
            *local_98 = *pfVar10;
            local_98[1] = pfVar10[1];
            local_98[2] = pfVar10[2];
            pfVar5[6] = (float)local_34;
            pfVar5[0x10] = local_6c;
            pfVar5[0x11] = (float)(local_28 & 0xffff) * *(float *)(param_2 + 0x44);
            pfVar5[0x12] = fVar18 + fVar13;
            pfVar5[0x18] = *(float *)(&DAT_00b45528 + iVar4) + fVar14;
            pfVar5[0x19] = *(float *)(&DAT_00b45568 + iVar4);
            pfVar5[0x1a] = *(float *)(&DAT_00b45538 + iVar4) + fVar14;
            pfVar5[0x1b] = *(float *)(&DAT_00b45578 + iVar4);
            pfVar5[0x1c] = *(float *)(&DAT_00b45548 + iVar4) + fVar14;
            pfVar5[0x1d] = *(float *)(&DAT_00b45588 + iVar4);
            pfVar5[0x1e] = *(float *)(&DAT_00b45558 + iVar4) + fVar14;
            pfVar5[0x1f] = *(float *)(&DAT_00b45598 + iVar4);
            pfVar5[0x17] = 9.14768e-41;
            pfVar10 = (float *)(*(int *)(param_2 + 0x14) + iVar6 * 0xc);
            local_98[0x10] = *pfVar10;
            local_98[0x11] = pfVar10[1];
            local_98[0x12] = pfVar10[2];
            pfVar5[0x16] = local_24;
            local_6c = local_6c + fVar13;
            pfVar5[0x20] = local_6c;
            fVar19 = *(float *)(param_2 + 0x44);
            pfVar5[0x22] = fVar18;
            pfVar5[0x21] = (float)local_30 * fVar19;
            pfVar5[0x28] = *(float *)(&DAT_00b45524 + iVar4) + fVar14;
            pfVar5[0x29] = *(float *)(&DAT_00b45564 + iVar4);
            pfVar5[0x2a] = *(float *)(&DAT_00b45534 + iVar4) + fVar14;
            pfVar5[0x2b] = *(float *)(&DAT_00b45574 + iVar4);
            pfVar5[0x2c] = *(float *)(&DAT_00b45544 + iVar4) + fVar14;
            pfVar5[0x2d] = *(float *)(&DAT_00b45584 + iVar4);
            pfVar5[0x2e] = *(float *)(&DAT_00b45554 + iVar4) + fVar14;
            pfVar5[0x2f] = *(float *)(&DAT_00b45594 + iVar4);
            pfVar5[0x27] = 2.3418052e-38;
            pfVar10 = (float *)(*(int *)(param_2 + 0x14) + (iVar8 * 3 + 3) * 4);
            local_98[0x20] = *pfVar10;
            local_98[0x21] = pfVar10[1];
            local_98[0x22] = pfVar10[2];
            pfVar5[0x26] = local_2c;
            pfVar10 = local_94 + 0x30;
            pfVar11 = pfVar5 + 0x30;
            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *pfVar11 = *pfVar10;
              pfVar10 = pfVar10 + 1;
              pfVar11 = pfVar11 + 1;
            }
            pfVar10 = local_8c + 0x40;
            pfVar11 = pfVar5 + 0x40;
            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *pfVar11 = *pfVar10;
              pfVar10 = pfVar10 + 1;
              pfVar11 = pfVar11 + 1;
            }
            pfVar5[0x50] = local_6c;
            pfVar5[0x51] = (float)local_20 * *(float *)(param_2 + 0x44);
            pfVar5[0x52] = fVar18 + fVar13;
            pfVar5[0x58] = *(float *)(&DAT_00b4552c + iVar4) + fVar14;
            pfVar5[0x59] = *(float *)(&DAT_00b4556c + iVar4);
            pfVar5[0x5a] = *(float *)(&DAT_00b4553c + iVar4) + fVar14;
            pfVar5[0x5b] = *(float *)(&DAT_00b4557c + iVar4);
            pfVar5[0x5c] = *(float *)(&DAT_00b4554c + iVar4) + fVar14;
            pfVar5[0x5d] = *(float *)(&DAT_00b4558c + iVar4);
            local_94 = local_94 + 0x60;
            pfVar5[0x5e] = *(float *)(&DAT_00b4555c + iVar4) + fVar14;
            pfVar5[0x5f] = *(float *)(&DAT_00b4559c + iVar4);
            pfVar5[0x57] = 2.3509528e-38;
            pfVar10 = (float *)(*(int *)(param_2 + 0x14) + (iVar6 * 3 + 3) * 4);
            local_98[0x50] = *pfVar10;
            local_98[0x51] = pfVar10[1];
            local_98[0x52] = pfVar10[2];
            local_8c = local_8c + 0x60;
            pfVar5[0x56] = local_1c;
            pfVar5 = pfVar5 + 0x60;
            iVar4 = iVar9;
            local_98 = local_98 + 0x60;
          } while (iVar9 <= *(int *)(param_2 + 0x18) + -1);
        }
        fVar18 = fVar18 + fVar13;
        local_84 = local_84 + 1;
        iVar4 = *(int *)(param_2 + 0x18) + -1;
      } while (local_84 <= iVar4);
    }
    if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 0) {
      FUN_007464e0();
    }
    *(int *)(param_1 + 0xa8) = iVar2 / 3;
    *(undefined4 *)(param_1 + 0xac) = 4;
    uVar3 = *(undefined4 *)(param_2 + 0x50);
  }
  else {
    fVar14 = *(float *)(param_2 + 100);
    fVar19 = fVar18 * *(float *)(param_2 + 0x68);
    pfVar5 = param_4;
    if (param_4 == (float *)0x0) {
      uVar3 = FUN_00414bc0(0x1d2);
      *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
      local_c = 1;
      iVar4 = FUN_00414c20(iVar2,uVar3,0x20,0);
      local_c = 0xffffffff;
      local_28 = 0;
      local_24 = 0.0;
      if (local_34 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(local_34);
      }
      if (iVar4 < 0) {
        ExceptionList = local_14;
        return 0;
      }
      *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
      iVar4 = *(int *)(param_1 + 0x14);
      if (*(int *)(iVar4 + 0x10) == 0) {
        pfVar5 = (float *)0x0;
      }
      else {
        pfVar5 = (float *)FUN_00746520(*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18),0
                                      );
      }
      if (pfVar5 == (float *)0x0) {
        *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
        if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) == 0) {
          ExceptionList = local_14;
          return 0;
        }
        FUN_007464e0();
        ExceptionList = local_14;
        return 0;
      }
      *(undefined1 *)(param_1 + 0xe8) = 1;
    }
    local_48 = (float)(*(int *)(param_1 + 0xd0) * *(int *)(param_2 + 0x18)) *
               *(float *)(param_2 + 0x68) + *(float *)(param_2 + 0x70);
    local_64 = *(int *)(param_2 + 0x18) - param_3;
    fVar15 = (float)*(int *)(param_1 + 0xd0) * *(float *)(param_2 + 0x40);
    local_78 = 0;
    if (-1 < local_64) {
      do {
        local_7c = (float)*(int *)(param_1 + 0xcc) * *(float *)(param_2 + 0x40);
        local_38 = (float)(*(int *)(param_1 + 0xcc) * *(int *)(param_2 + 0x18)) *
                   *(float *)(param_2 + 100) + *(float *)(param_2 + 0x6c);
        local_84 = 0;
        if (-1 < local_64) {
          iVar4 = param_3 + local_78;
          local_98 = pfVar5 + -0x1e;
          local_94 = pfVar5 + -10;
          fVar16 = local_48 + fVar19;
          pfVar10 = pfVar5 + 3;
          do {
            iVar7 = *(int *)(param_2 + 0x1c);
            CVOGTerrainChunk_GetCornerData(local_50,local_84,local_78);
            *pfVar5 = local_7c;
            pfVar5[1] = (float)local_50[0] * *(float *)(param_2 + 0x44);
            pfVar5[2] = fVar15;
            pfVar5[8] = local_38;
            pfVar5[9] = local_48;
            pfVar11 = (float *)(*(int *)(param_2 + 0x14) + (iVar7 * local_78 + local_84) * 0xc);
            *pfVar10 = *pfVar11;
            pfVar10[1] = pfVar11[1];
            pfVar10[2] = pfVar11[2];
            pfVar5[6] = local_4c;
            iVar7 = *(int *)(param_2 + 0x1c);
            CVOGTerrainChunk_GetCornerData(local_50,local_84,iVar4);
            pfVar5[10] = local_7c;
            pfVar5[0xb] = (float)local_50[0] * *(float *)(param_2 + 0x44);
            pfVar5[0xc] = fVar15 + fVar13;
            pfVar5[0x12] = local_38;
            pfVar5[0x13] = fVar16;
            pfVar11 = (float *)(*(int *)(param_2 + 0x14) + (iVar7 * iVar4 + local_84) * 0xc);
            pfVar10[10] = *pfVar11;
            pfVar10[0xb] = pfVar11[1];
            pfVar10[0xc] = pfVar11[2];
            pfVar5[0x10] = local_4c;
            iVar7 = *(int *)(param_2 + 0x1c);
            iVar9 = local_84 + param_3;
            CVOGTerrainChunk_GetCornerData(local_50,iVar9,local_78);
            local_7c = local_7c + fVar13;
            pfVar5[0x14] = local_7c;
            pfVar5[0x15] = (float)local_50[0] * *(float *)(param_2 + 0x44);
            pfVar5[0x16] = fVar15;
            fVar17 = local_38 + fVar18 * fVar14;
            pfVar5[0x1c] = fVar17;
            pfVar5[0x1d] = local_48;
            pfVar11 = (float *)(*(int *)(param_2 + 0x14) +
                               (iVar7 * local_78 + local_84 + param_3) * 0xc);
            pfVar10[0x14] = *pfVar11;
            pfVar10[0x15] = pfVar11[1];
            pfVar10[0x16] = pfVar11[2];
            pfVar5[0x1a] = local_4c;
            pfVar11 = local_94 + 0x1e;
            pfVar12 = pfVar5 + 0x1e;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *pfVar12 = *pfVar11;
              pfVar11 = pfVar11 + 1;
              pfVar12 = pfVar12 + 1;
            }
            pfVar11 = local_98 + 0x28;
            pfVar12 = pfVar5 + 0x28;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *pfVar12 = *pfVar11;
              pfVar11 = pfVar11 + 1;
              pfVar12 = pfVar12 + 1;
            }
            iVar7 = *(int *)(param_2 + 0x1c);
            CVOGTerrainChunk_GetCornerData(local_50,iVar9,iVar4);
            pfVar5[0x32] = local_7c;
            pfVar5[0x33] = (float)local_50[0] * *(float *)(param_2 + 0x44);
            pfVar5[0x34] = fVar15 + fVar13;
            pfVar5[0x3a] = fVar17;
            pfVar5[0x3b] = fVar16;
            pfVar11 = (float *)(*(int *)(param_2 + 0x14) +
                               (iVar7 * iVar4 + local_84 + param_3) * 0xc);
            pfVar10[0x32] = *pfVar11;
            pfVar10[0x33] = pfVar11[1];
            pfVar10[0x34] = pfVar11[2];
            local_94 = local_94 + 0x3c;
            local_98 = local_98 + 0x3c;
            pfVar10 = pfVar10 + 0x3c;
            pfVar5[0x38] = local_4c;
            pfVar5 = pfVar5 + 0x3c;
            local_84 = iVar9;
            local_38 = fVar17;
          } while (iVar9 <= *(int *)(param_2 + 0x18) - param_3);
        }
        fVar15 = fVar15 + fVar13;
        local_78 = local_78 + param_3;
        local_64 = *(int *)(param_2 + 0x18) - param_3;
        local_48 = local_48 + fVar19;
      } while (local_78 <= local_64);
    }
    if (param_4 != (float *)0x0) {
      ExceptionList = local_14;
      return iVar2;
    }
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
    if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 0) {
      FUN_007464e0();
    }
    *(int *)(param_1 + 0xa8) = iVar2 / 3;
    *(undefined4 *)(param_1 + 0xac) = 4;
    uVar3 = *(undefined4 *)(param_2 + 0x4c);
  }
  FUN_004148e0(uVar3);
  FUN_0096fdf0();
  ExceptionList = local_14;
  return iVar2;
}
```
