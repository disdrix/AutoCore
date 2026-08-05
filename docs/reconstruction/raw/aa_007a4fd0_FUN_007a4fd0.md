# Raw capture: FUN_007a4fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a4fd0` |
| **Canonical name** | `FUN_007a4fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_007a4fd0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *_Dst;
  
  _Dst = *(int **)(param_1 + 8);
  while( true ) {
    if (_Dst == *(int **)(param_1 + 0xc)) {
      return 0;
    }
    iVar1 = *_Dst;
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_2)) &&
       (*(int *)(iVar1 + 0x204) == param_3)) break;
    _Dst = _Dst + 1;
  }
  if ((void *)*_Dst != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)*_Dst);
  }
  memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0xc) - (int)(_Dst + 1) >> 2) * 4);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -4;
  return 1;
}
```
