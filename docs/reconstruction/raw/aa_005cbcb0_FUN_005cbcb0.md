# Raw capture: FUN_005cbcb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cbcb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cbcb0` |
| **Canonical name** | `FUN_005cbcb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005cbcb0(int param_1,int *param_2,undefined1 *param_3)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  short sVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  int iStack_8;
  
  piVar3 = param_2;
  if ((param_2 != (int *)0x0) &&
     (FUN_00512160(param_2[0x24],param_2[0x25],(char)param_2[0x26]), param_3 == (undefined1 *)0x2))
  {
    *(int *)(param_1 + -0x30) = piVar3[4];
    *(int *)(param_1 + -0x2c) = piVar3[5];
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) + 0x48))();
    *(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x44 + param_1) = piVar3[9];
    *(int *)(param_1 + -0x28) = piVar3[0x21];
    *(char *)(param_1 + -0x20) = (char)piVar3[0x22];
    *(undefined1 *)(param_1 + -0x1f) = *(undefined1 *)((int)piVar3 + 0x89);
    *(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x48 + param_1) = piVar3[6];
    *(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xfc + param_1) = piVar3[7];
    *(int *)(param_1 + -0x34) = piVar3[8];
    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1);
    *puVar1 = *puVar1 ^ ((uint)*(byte *)((int)piVar3 + 0x8a) << 8 ^ *puVar1) & 0x100;
    *(undefined1 *)(param_1 + -0x1e) = *(undefined1 *)((int)piVar3 + 0xa3);
    *(char *)(param_1 + -0x1d) = (char)piVar3[0x29];
    *(undefined1 *)(param_1 + -0x1c) = *(undefined1 *)((int)piVar3 + 0xa5);
    FUN_00513e30(*(undefined1 *)((int)piVar3 + 0xab));
    *(short *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x74 + param_1) = (short)piVar3[0x2b];
    pcVar6 = (char *)((int)piVar3 + 0xae);
    pcVar7 = (char *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xb + param_1);
    do {
      cVar2 = *pcVar6;
      *pcVar7 = cVar2;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    *(undefined1 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xc + param_1) =
         *(undefined1 *)((int)piVar3 + 0xbf);
    iVar5 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
    iVar9 = iVar5 + -0x10c + param_1;
    puVar1 = (uint *)(iVar9 + 0x17c);
    *puVar1 = *puVar1 ^ ((uint)*(byte *)(piVar3 + 0x2a) * 4 ^ *(uint *)(iVar9 + 0x17c)) & 4;
    FUN_00513de0(CONCAT31((int3)((uint)iVar5 >> 8),*(undefined1 *)((int)piVar3 + 0xa9)));
    iVar9 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
    puVar1 = (uint *)(iVar9 + 0x70 + param_1);
    *puVar1 = *puVar1 ^ ((uint)*(byte *)((int)piVar3 + 0xaa) << 0xf ^
                        *(uint *)(iVar9 + 0x70 + param_1)) & 0x8000;
    param_2 = piVar3 + 0x14;
    iVar9 = 0;
    piVar8 = piVar3 + 10;
    do {
      if (*piVar8 == -1) break;
      puVar10 = &param_3;
      param_3._0_3_ = CONCAT12((char)*param_2,(short)*piVar8);
      FUN_005c9be0(puVar10);
      FUN_005cb3d0(puVar10);
      param_2 = (int *)((int)param_2 + 2);
      iVar9 = iVar9 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar9 < 5);
    *(undefined2 *)(param_1 + -0x38) = *(undefined2 *)((int)piVar3 + 0xc2);
    param_3 = (undefined1 *)((int)piVar3 + 0x5a);
    piVar8 = piVar3 + 0xf;
    *(int *)(param_1 + -0x24) = piVar3[0x34];
    iStack_8 = 0;
    do {
      if (*piVar8 == -1) break;
      param_2._0_3_ = CONCAT12(*param_3,(short)*piVar8);
      iVar5 = FUN_005c9c50();
      iVar9 = *(int *)(iVar5 + 4);
      if ((iVar9 == 0) ||
         ((uint)(*(int *)(iVar5 + 0xc) - iVar9 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar9 >> 2))) {
        FUN_005c9cc0(*(undefined4 *)(iVar5 + 8),1,&param_2);
      }
      else {
        iVar9 = *(int *)(iVar5 + 8);
        FUN_005c96c0(iVar9,1,&param_2,iVar5,param_2);
        *(int *)(iVar5 + 8) = iVar9 + 4;
      }
      param_3 = param_3 + 2;
      iStack_8 = iStack_8 + 1;
      piVar8 = piVar8 + 1;
    } while (iStack_8 < 5);
    if (*piVar3 == 0x2012) {
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) + 100))();
    }
    sVar4 = (short)piVar3[0x31];
    if (0x50 < sVar4) {
      sVar4 = 0x50;
    }
    *(short *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + param_1 + -0x22) = sVar4;
    *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x20 + param_1) =
         *(undefined2 *)((int)piVar3 + 0xc6);
    *(short *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1e + param_1) = (short)piVar3[0x32];
    *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1c + param_1) =
         *(undefined2 *)((int)piVar3 + 0xca);
    *(short *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1a + param_1) = (short)piVar3[0x33];
    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1);
    *puVar1 = *puVar1 | 0x10;
    FUN_00512670();
  }
  return;
}
```
