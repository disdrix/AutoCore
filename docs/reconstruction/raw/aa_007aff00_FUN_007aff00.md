# Raw capture: FUN_007aff00

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aff00` |
| **Canonical name** | `FUN_007aff00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aff00(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0x20c) != 0) {
    pvVar1 = *(void **)(param_1 + 0x28c);
    if (pvVar1 != (void *)0x0) {
      FUN_00797d70(pvVar1);
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + 0x28c) = 0;
  }
  FUN_00424060();
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  return;
}
```
