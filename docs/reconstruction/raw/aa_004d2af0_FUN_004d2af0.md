# Raw capture: FUN_004d2af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d2af0` |
| **Canonical name** | `FUN_004d2af0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004d2af0(int param_1,int *param_2)

{
  char cVar1;
  float *pfVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 local_18 [8];
  undefined1 auStack_10 [12];
  size_t sStack_4;
  
  pfVar2 = (float *)(**(code **)(*param_2 + 0x40))(local_18);
  uVar9 = (uint)(*pfVar2 / *(float *)(param_1 + 0xe7c0));
  iVar3 = (**(code **)(*param_2 + 0x40))(auStack_10);
  uVar7 = *(int *)(param_1 + 0xe7b8) - 1;
  uVar8 = (uint)(*(float *)(iVar3 + 8) / *(float *)(param_1 + 0xe7c4));
  uVar9 = ((int)uVar9 < 0) - 1 & uVar9;
  if ((int)uVar9 <= (int)uVar7) {
    uVar7 = uVar9;
  }
  uVar9 = *(int *)(param_1 + 0xe7bc) - 1;
  uVar8 = ((int)uVar8 < 0) - 1 & uVar8;
  if ((int)uVar8 <= (int)uVar9) {
    uVar9 = uVar8;
  }
  cVar1 = (**(code **)(*param_2 + 0x28))();
  if (cVar1 == '\x02') {
    iVar3 = (*(int *)(param_1 + 0xe7b8) * uVar9 + uVar7) * 0x20;
    pvVar5 = *(void **)(iVar3 + 0x18 + *(int *)(param_1 + 0xe7b4));
    iVar3 = iVar3 + 0x10 + *(int *)(param_1 + 0xe7b4);
    puVar4 = (undefined4 *)
             FUN_0049c5f0(&stack0xffffffdc,*(undefined4 *)(iVar3 + 4),pvVar5,&sStack_4);
    if ((void *)*puVar4 == pvVar5) goto LAB_004d2c3a;
    sStack_4 = (*(int *)(iVar3 + 8) - (int)pvVar5 >> 2) * 4;
    pvVar5 = memmove((void *)*puVar4,pvVar5,sStack_4);
    iVar6 = (int)pvVar5 + sStack_4;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0xe7b8) * uVar9 + uVar7) * 0x20 + *(int *)(param_1 + 0xe7b4);
    pvVar5 = *(void **)(iVar3 + 8);
    puVar4 = (undefined4 *)
             FUN_0049c5f0(&stack0xffffffdc,*(undefined4 *)(iVar3 + 4),pvVar5,&sStack_4);
    if ((void *)*puVar4 == pvVar5) goto LAB_004d2c3a;
    sStack_4 = (*(int *)(iVar3 + 8) - (int)pvVar5 >> 2) * 4;
    pvVar5 = memmove((void *)*puVar4,pvVar5,sStack_4);
    iVar6 = (int)pvVar5 + sStack_4;
  }
  *(int *)(iVar3 + 8) = iVar6;
LAB_004d2c3a:
  if (*(int *)(param_1 + 0xe894) != 0) {
    FUN_00491140(param_2);
  }
  return;
}
```
