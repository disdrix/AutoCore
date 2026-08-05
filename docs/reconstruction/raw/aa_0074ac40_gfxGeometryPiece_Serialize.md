# Raw capture: gfxGeometryPiece_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ac40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074ac40` |
| **Canonical name** | `gfxGeometryPiece_Serialize` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0074ad67) */
/* WARNING: Removing unreachable block (ram,0x0074ad81) */
/* WARNING: Removing unreachable block (ram,0x0074ad87) */
/* gfxGeometryPiece::Serialize  [palantir\graphics\gfxGeometryPiece.cpp]
   Writes a GPCE (file bytes "ECPG") chunk, version 10. One GPCE per mesh section, direct child of
   the GBOD ("DOBG") root. Children written in order: has-effect byte, EFCT ("TCFE") effect (fx name
   ISTR + PARM params incl. DiffuseTexture/NormalMapTexture/MatColor*), INDX, VERT, BBOX ("XOBB"),
   then name strings + USDA ("ADSU") key/value tail (key "LODLevel" = piece LOD).
   VERT and INDX are paired by GPCE siblinghood - exactly one of each per piece. */

uint __thiscall gfxGeometryPiece_Serialize(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined1 local_24 [4];
  undefined2 *local_20;
  int local_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b2420;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  stoChunkWriter_BeginChunk(0x47504345,10);
  local_4 = 0;
  uVar1 = FUN_004399a0();
  uVar2 = FUN_0096f890(param_1 + 8);
  if (param_1[3] == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = gfxIndexBufferImpl_Serialize(param_2);
  }
  if (param_1[7] == 0) {
    if (param_1[5] == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = gfxVertexBufferImpl_Serialize(param_2);
    }
  }
  else {
    FUN_004451c0(local_24,param_1[7] + 0x24);
    local_4._0_1_ = 1;
    for (; local_20 != (undefined2 *)(local_1c + -8); local_20 = local_20 + 4) {
      *local_20 = 0;
    }
    FUN_00746910();
    FUN_00747390();
    local_4._0_1_ = 2;
    if (param_1[5] == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(param_1[5] + 0x18);
    }
    FUN_00414c20(uVar4,local_24,8,0);
    FUN_0044bbc0(param_1 + 4,0,0);
    FUN_0044bbc0(param_1 + 6,0,0);
    uVar5 = 1;
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_00414b60();
  }
  if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {
    (**(code **)(*param_1 + 0x5c))();
  }
  uVar6 = FUN_0074bda0();
  puVar11 = (undefined *)param_1[0x16];
  if ((undefined *)param_1[0x16] == (undefined *)0x0) {
    puVar11 = PTR_DAT_00afa2bc;
  }
  if (param_2[7] == 0) {
    uVar7 = FUN_00436f80(param_2,puVar11);
    param_2[1] = param_2[1] | uVar7;
  }
  else {
    uVar7 = FUN_00767160(&DAT_00a9d6f8,puVar11);
    param_2[1] = param_2[1] | uVar7;
    uVar7 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);
    param_2[8] = 0;
    param_2[1] = uVar7 | param_2[1];
  }
  uVar7 = param_2[1];
  uVar8 = FUN_00439810();
  uVar9 = FUN_00439870();
  puVar11 = (undefined *)param_1[0x24];
  if ((undefined *)param_1[0x24] == (undefined *)0x0) {
    puVar11 = PTR_DAT_00afa2bc;
  }
  if (param_2[7] == 0) {
    uVar10 = FUN_00436f80(param_2,puVar11);
    param_2[1] = param_2[1] | uVar10;
  }
  else {
    uVar10 = FUN_00767160(&DAT_00a9d6f8,puVar11);
    param_2[1] = param_2[1] | uVar10;
    uVar10 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);
    param_2[8] = 0;
    param_2[1] = uVar10 | param_2[1];
  }
  uVar10 = param_2[1];
  puVar11 = (undefined *)param_1[0x25];
  if ((undefined *)param_1[0x25] == (undefined *)0x0) {
    puVar11 = PTR_DAT_00afa2bc;
  }
  if (param_2[7] == 0) {
    uVar12 = FUN_00436f80(param_2,puVar11);
    param_2[1] = param_2[1] | uVar12;
  }
  else {
    uVar12 = FUN_00767160(&DAT_00a9d6f8,puVar11);
    param_2[1] = param_2[1] | uVar12;
    uVar12 = (**(code **)(*(int *)*param_2 + 0x18))(&DAT_00a97b84,2);
    param_2[8] = 0;
    param_2[1] = uVar12 | param_2[1];
  }
  uVar12 = param_2[1];
  uVar13 = FUN_00748800(param_1);
  uVar14 = FUN_00439870();
  uVar15 = FUN_00439810();
  uVar16 = FUN_00439870();
  local_4 = 0xffffffff;
  stoChunkWriter_EndChunk();
  ExceptionList = pvStack_c;
  return uVar16 | uVar1 | uVar2 | uVar3 | uVar5 | uVar6 | uVar8 | uVar7 | uVar9 | uVar10 |
                  uVar13 | uVar12 | uVar14 | uVar15;
}
```
