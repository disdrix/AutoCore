# Raw capture: FUN_0068add0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068add0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068add0` |
| **Canonical name** | `FUN_0068add0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_0068add0(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aa27b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_4 = 0;
  FUN_00445bc0(param_3,0);
  iVar1 = 0;
  if (0 < param_3) {
    do {
      *(undefined1 *)(iVar1 + param_1[2]) = *(undefined1 *)(iVar1 + param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  ExceptionList = local_c;
  return param_1;
}
```
