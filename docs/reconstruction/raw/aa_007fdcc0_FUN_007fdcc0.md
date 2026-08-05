# Raw capture: FUN_007fdcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fdcc0` |
| **Canonical name** | `FUN_007fdcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fdcc0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *_Dst;
  int *piVar3;
  char cVar4;
  
  if ((((*(int **)(param_1 + 0xf40) == (int *)0x0) ||
       (iVar2 = **(int **)(param_1 + 0xf40), iVar2 == 0)) ||
      (iVar2 = *(int *)(iVar2 + 0x4c0), iVar2 == 0)) || (*(char *)(iVar2 + 0x1d) == '\0')) {
    iVar2 = *(int *)(param_1 + 0x1148);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x2b0) != 0)) && (*(int *)(param_1 + 0xf38) != 0)) {
      (**(code **)(**(int **)(param_1 + 0xf38) + 0xb0))(iVar2);
    }
    if ((*(int *)(param_1 + 0x3078) != 0) &&
       (*(int *)(param_1 + 0x307c) - *(int *)(param_1 + 0x3078) >> 2 != 0)) {
      _Dst = *(int **)(param_1 + 0x3078);
      piVar1 = *(int **)(param_1 + 0x307c);
      while (_Dst != piVar1) {
        piVar1 = (int *)*_Dst;
        if (piVar1 != (int *)0x0) {
          piVar3 = (int *)piVar1[0xac];
          cVar4 = (**(code **)(*piVar1 + 0x3d8))();
          if (cVar4 != '\0') {
            (**(code **)(*piVar1 + 0x440))();
          }
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 0xb0))(piVar1);
          }
          (**(code **)*piVar1)(1);
        }
        memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x307c) - (int)(_Dst + 1) >> 2) * 4);
        *(int *)(param_1 + 0x307c) = *(int *)(param_1 + 0x307c) + -4;
        piVar1 = *(int **)(param_1 + 0x307c);
      }
      FUN_00418690(0);
    }
  }
  return;
}
```
