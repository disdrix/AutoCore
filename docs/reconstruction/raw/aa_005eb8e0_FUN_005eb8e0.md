# Raw capture: FUN_005eb8e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb8e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eb8e0` |
| **Canonical name** | `FUN_005eb8e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005eb8e0(int param_1,int *param_2)

{
  short *psVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_3c;
  int *piStack_38;
  int iStack_34;
  undefined1 auStack_30 [44];
  
  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;
  local_3c = param_1;
  uVar5 = (**(code **)(*param_2 + 0x14))();
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x54) = uVar5;
  psVar1 = (short *)((int)puVar2 + 6);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    (**(code **)*puVar2)(1);
  }
  *(int **)(param_1 + 0xc) = param_2;
  piStack_38 = *(int **)(*(int *)(param_1 + 8) + 0xcc);
  iVar3 = *(int *)(param_1 + 0xc4);
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc0) + iVar3 * 8);
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc0) + iVar3 * 8) + 0x14))();
    iStack_34 = *piStack_38;
    puVar4 = (undefined4 *)puVar2[1];
    iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
    iVar7 = (**(code **)(*(int *)*puVar4 + 0x14))();
    uVar5 = (**(code **)(iStack_34 + 0x18c + (iVar6 * 0x20 + iVar7) * 4))
                      (local_3c + 0xc,puVar4,piStack_38,0);
    *puVar2 = uVar5;
    param_1 = local_3c;
  }
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(*param_2 + 0x18))
              (param_1 + 0x80,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),auStack_30
              );
    FUN_00634450(&local_3c);
  }
  return;
}
```
