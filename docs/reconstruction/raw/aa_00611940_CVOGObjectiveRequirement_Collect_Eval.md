# Raw capture: CVOGObjectiveRequirement_Collect_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611940` |
| **VA** | `0x00611940` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Eval` |
| **Prior** | `FUN_00611940` |
| **Capture** | 2026-07-29 Ghidra `batch_decompile` |

## Raw pseudocode

```c
float10 __thiscall FUN_00611940(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return (float10)g_flOne;
  }
  if ((*(int *)(param_2 + 0x250) != 0) && (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0)) {
    iVar1 = FUN_005711c0(*(undefined4 *)(param_1 + 0x10),0);
    fVar2 = g_flOne;
    if ((float)iVar1 / (float)*(int *)(param_1 + 0x14) < g_flOne) {
      iVar1 = FUN_005711c0(*(undefined4 *)(param_1 + 0x10),0);
      fVar2 = (float)iVar1 / (float)*(int *)(param_1 + 0x14);
    }
    return (float10)fVar2;
  }
  return (float10)g_flZero;
}
```

Note: decompiler flattens thiscall on CountItemsByCbid; ECX is cargo grid at runtime.
