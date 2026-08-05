# Raw capture: FUN_007aec70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aec70` |
| **Canonical name** | `FUN_007aec70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aec70(int *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)param_1[0xa5];
  if (pvVar1 != (void *)0x0) {
    if (*(char *)((int)param_1 + 0xbb) != '\0') {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    param_1[0xa5] = 0;
    *(undefined1 *)((int)param_1 + 0xbb) = 0;
    (**(code **)(*param_1 + 0x2b4))(&DAT_00a1419b);
  }
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  return;
}
```
