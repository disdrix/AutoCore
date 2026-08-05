# Raw capture: FUN_007fddd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fddd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fddd0` |
| **Canonical name** | `FUN_007fddd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fddd0(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *_Dst;
  int unaff_EDI;
  int *local_4;
  
  _Dst = *(int **)(unaff_EDI + 0x3068);
  if (_Dst != *(int **)(unaff_EDI + 0x306c)) {
    local_4 = _Dst + 1;
    do {
      piVar1 = (int *)*_Dst;
      if (piVar1 == (int *)0x0) {
        _Dst = _Dst + 1;
        local_4 = local_4 + 1;
      }
      else {
        memmove(_Dst,local_4,(*(int *)(unaff_EDI + 0x306c) - (int)local_4 >> 2) * 4);
        *(int *)(unaff_EDI + 0x306c) = *(int *)(unaff_EDI + 0x306c) + -4;
        piVar2 = (int *)piVar1[0xac];
        cVar3 = (**(code **)(*piVar1 + 0x3d8))();
        if (cVar3 != '\0') {
          (**(code **)(*piVar1 + 0x440))();
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0xb0))(piVar1);
        }
        (**(code **)*piVar1)(1);
      }
    } while (_Dst != *(int **)(unaff_EDI + 0x306c));
  }
  FUN_00418690(0);
  return;
}
```
