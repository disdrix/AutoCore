# Raw capture: Deliver CargoReady (INFERRED)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00610f20` |
| **VA** | `0x00610f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` |

## Raw

```c
undefined4 __thiscall FUN_00610f20(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x18) == param_2) && (*(int *)(*(int *)(param_3 + 0x250) + 0x2b0) != 0)) {
    iVar1 = FUN_005711c0(*(undefined4 *)(param_1 + 0x10),0);
    if ((*(int *)(param_1 + 0x14) <= iVar1) || (*(char *)(param_1 + 0x23) == '\0')) {
      return 1;
    }
  }
  return 0;
}
```
