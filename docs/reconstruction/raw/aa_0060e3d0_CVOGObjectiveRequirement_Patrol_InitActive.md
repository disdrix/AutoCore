# Raw capture: CVOGObjectiveRequirement_Patrol_InitActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060e3d0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_InitActive` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGObjectiveRequirement_Patrol_InitActive(int param_1,int param_2)

{
  void *pvVar1;
  CVOGHBBase *pAction;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009a83eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004de760(param_2,0);
  if ((*(char *)(param_1 + 0x18) != '\0') &&
     (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0')) {
    pvVar1 = operator_new(0x40);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      pAction = (CVOGHBBase *)0x0;
    }
    else {
      pAction = (CVOGHBBase *)FUN_00650d30(param_2,param_1);
    }
    local_4 = 0xffffffff;
    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) +
                                 0xe4ec),pAction);
    CVOGHBBase_Start(pAction);
  }
  ExceptionList = local_c;
  return;
}
```
