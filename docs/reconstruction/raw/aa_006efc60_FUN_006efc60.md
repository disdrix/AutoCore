# Raw capture: FUN_006efc60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006efc60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006efc60` |
| **Canonical name** | `FUN_006efc60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006efc60(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 local_30 [5];
  undefined4 local_1c;
  
  local_1c = param_4[1];
  pcVar5 = (char *)(**(code **)(*param_1 + 0x20))((int)&uStack_34 + 3,param_2,local_30);
  if (*pcVar5 != '\0') {
    iVar1 = *(int *)(param_3 + 8);
    fVar4 = uStack_34 * *(float *)(iVar1 + 0x40);
    fVar3 = uStack_34 * *(float *)(iVar1 + 0x44);
    fVar2 = fStack_3c * *(float *)(iVar1 + 0x24);
    uStack_34 = fStack_3c * *(float *)(iVar1 + 0x28) +
                fStack_38 * *(float *)(iVar1 + 0x38) + uStack_34 * *(float *)(iVar1 + 0x48);
    local_30[0] = 0;
    fStack_3c = fStack_3c * *(float *)(iVar1 + 0x20) + fStack_38 * *(float *)(iVar1 + 0x30) + fVar4;
    fStack_38 = fVar2 + fStack_38 * *(float *)(iVar1 + 0x34) + fVar3;
    (**(code **)*param_4)(param_3,&fStack_3c);
  }
  return;
}
```
