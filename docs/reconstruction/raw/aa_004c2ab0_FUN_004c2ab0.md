# Raw capture: FUN_004c2ab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2ab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c2ab0` |
| **Canonical name** | `FUN_004c2ab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004c2ab0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *_Dst;
  
  _Dst = *(int **)(param_1 + 500);
  if (_Dst != *(int **)(param_1 + 0x1f8)) {
    while ((*(int *)*_Dst != param_2 || (((int *)*_Dst)[1] != param_3))) {
      _Dst = _Dst + 1;
      if (_Dst == *(int **)(param_1 + 0x1f8)) {
        return;
      }
    }
    iVar2 = *(int *)(param_1 + 0x1e4);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(param_1 + 0x1ec) - iVar2 >> 2) <=
        (uint)(*(int *)(param_1 + 0x1e8) - iVar2 >> 2))) {
      FUN_004c2bb0(*(undefined4 *)(param_1 + 0x1e8),1,_Dst);
    }
    else {
      piVar1 = *(int **)(param_1 + 0x1e8);
      *piVar1 = *_Dst;
      *(int **)(param_1 + 0x1e8) = piVar1 + 1;
    }
    iVar2 = FUN_004c22a0(*(undefined4 *)(param_1 + 0x1d8),*(undefined4 *)(param_1 + 0x1dc));
    iVar3 = FUN_004c22a0(*(undefined4 *)*_Dst,((undefined4 *)*_Dst)[1]);
    if ((((iVar2 != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) < 3)) &&
       (1 < *(int *)(iVar2 + 0x24))) {
      *(undefined4 *)(iVar3 + 0x24) = 1;
    }
    memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1f8) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + -4;
  }
  return;
}
```
