# Raw capture: FUN_0090efa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090efa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090efa0` |
| **Canonical name** | `FUN_0090efa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0090efa0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined1 auStack_60 [16];
  undefined4 auStack_50 [19];
  
  if (param_2 == 0) {
    return 0x80004005;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xa20) + 0xc))();
  fVar5 = *(float *)(iVar1 + 0x90);
  fVar6 = *(float *)(iVar1 + 0x94);
  fVar7 = *(float *)(iVar1 + 0x98);
  fStack_90 = fVar5;
  fStack_8c = fVar6;
  fStack_88 = fVar7;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xa24) + 0xc))();
  fStack_84 = *(float *)(iVar1 + 0x90);
  fStack_80 = *(float *)(iVar1 + 0x94);
  fStack_7c = *(float *)(iVar1 + 0x98);
  fStack_90 = fStack_84 - fStack_90;
  fStack_8c = fStack_80 - fStack_8c;
  fStack_88 = fStack_7c - fStack_88;
  fStack_78 = fStack_90;
  fStack_74 = fStack_8c;
  fStack_70 = fStack_88;
  fStack_6c = fVar5;
  fStack_68 = fVar6;
  fStack_64 = fVar7;
  FUN_0076f5f0(&fStack_90,&fStack_90);
  fStack_84 = fStack_8c * 0.0 - fStack_88 * DAT_00aaa668;
  fStack_80 = fStack_88 * 0.0 - fStack_90 * 0.0;
  fStack_7c = fStack_90 * DAT_00aaa668 - fStack_8c * 0.0;
  fVar5 = fStack_88;
  fVar6 = fStack_8c;
  fVar7 = fStack_90;
  fStack_78 = fStack_84;
  fStack_74 = fStack_80;
  fStack_70 = fStack_7c;
  FUN_0076f5f0(&fStack_84,&fStack_84);
  fStack_78 = fStack_7c * fVar6 - fStack_80 * fVar5;
  fVar4 = fStack_80 * fVar7;
  fStack_80 = fVar5 * fStack_84 - fStack_7c * fVar7;
  fStack_7c = fVar4 - fVar6 * fStack_84;
  fStack_84 = fStack_78;
  fStack_74 = fStack_80;
  fStack_70 = fStack_7c;
  FUN_0076f5f0(&fStack_84,&fStack_84);
  puVar2 = &DAT_00afdf70;
  puVar3 = auStack_50;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00972580(&fStack_90,&fStack_84);
  FUN_0076e970();
  FUN_0040d1a0(auStack_60);
  FUN_0040cf90(&fStack_6c);
  return 0;
}
```
