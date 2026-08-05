# Raw capture: CVOGObjective_MatchTargetEvaluators

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d9c0` |
| **VA** | `0x0059d9c0` |
| **Canonical name** | `CVOGObjective_MatchTargetEvaluators` |
| **Prior** | `FUN_0059d9c0` |

## Raw

```c
undefined4 __thiscall FUN_0059d9c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x158);
  if (puVar2 != *(undefined4 **)(param_1 + 0x15c)) {
    do {
      cVar1 = (**(code **)(*(int *)*puVar2 + 0x40))(param_2,param_3);
      if (cVar1 != '\0') {
        return 1;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x15c));
  }
  return 0;
}
```
