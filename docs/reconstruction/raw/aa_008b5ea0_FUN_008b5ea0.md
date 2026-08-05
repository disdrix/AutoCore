# Raw capture: FUN_008b5ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b5ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008b5ea0` |
| **Canonical name** | `FUN_008b5ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008b5ea0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined8 uVar4;
  char acStack_34 [52];
  
  if ((in_EAX != 0) && (cVar2 = (**(code **)(*param_1 + 0x3d8))(), cVar2 != '\0')) {
    param_1[0x146] = *(int *)(in_EAX + 0x200);
    param_1[0x147] = *(int *)(in_EAX + 0x204);
    param_1[0x148] = *(int *)(in_EAX + 0x1e8);
    param_1[0x149] = *(int *)(in_EAX + 0x1ec);
    __allrem();
    sprintf(acStack_34,"%d");
    (**(code **)(*(int *)param_1[0x151] + 0x1d8))();
    uVar3 = __alldiv(*(undefined4 *)(in_EAX + 0x1e8));
    __allrem(uVar3);
    sprintf(&stack0xffffffc0,"%d");
    (**(code **)(*(int *)param_1[0x152] + 0x1d8))();
    uVar4 = __alldiv(*(undefined4 *)(in_EAX + 0x1e8),*(undefined4 *)(in_EAX + 0x1ec),1000000,0);
    uVar4 = __allrem(uVar4,1000,0);
    sprintf(&stack0xffffffb4,"%d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    (**(code **)(*(int *)param_1[0x153] + 0x1d8))(&stack0xffffffb4,1,1);
    uVar4 = __alldiv(*(undefined4 *)(in_EAX + 0x1e8),*(undefined4 *)(in_EAX + 0x1ec),1000000000,0);
    uVar4 = __allrem(uVar4,1000,0);
    sprintf(&stack0xffffffa8,"%d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    (**(code **)(*(int *)param_1[0x154] + 0x1d8))(&stack0xffffffa8,1,1);
    (**(code **)(*(int *)param_1[0x158] + 0x1d8))(in_EAX + 0x1c2,1,0);
    (**(code **)(*(int *)param_1[0x159] + 0x1d8))();
    (**(code **)(*(int *)param_1[0x15a] + 0x1d8))(in_EAX + 0x32,1,0);
    if ((*(uint *)(in_EAX + 0x1f0) & *(uint *)(in_EAX + 500)) != 0xffffffff) {
      CVOGReaction_ResolveObjectTarget(1,*(uint *)(in_EAX + 0x1f0),*(uint *)(in_EAX + 500));
    }
    FUN_008b5a40();
    piVar1 = (int *)param_1[0x156];
    if (piVar1 != (int *)0x0) {
      if ((((param_1[0x144] & param_1[0x145]) == 0xffffffff) && (param_1[0x149] < 1)) &&
         ((param_1[0x149] < 0 || (param_1[0x148] == 0)))) {
        cVar2 = (**(code **)(*piVar1 + 0xd8))();
        if (cVar2 == '\x01') {
          (**(code **)(*(int *)param_1[0x156] + 0xd4))(0);
          (**(code **)(*(int *)param_1[0x156] + 0x34c))();
          (**(code **)(*param_1 + 0x34c))();
          return;
        }
      }
      else {
        cVar2 = (**(code **)(*piVar1 + 0xd8))();
        if (cVar2 == '\0') {
          (**(code **)(*(int *)param_1[0x156] + 0xd4))(1);
          (**(code **)(*(int *)param_1[0x156] + 0x34c))();
        }
      }
    }
    (**(code **)(*param_1 + 0x34c))();
  }
  return;
}
```
