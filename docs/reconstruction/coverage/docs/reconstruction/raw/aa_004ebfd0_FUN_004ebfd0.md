# Raw capture: FUN_004ebfd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ebfd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ebfd0` |
| **Canonical name** | `FUN_004ebfd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004ebfd0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x88);
  if (pvVar1 != (void *)0x0) {
    FUN_004a2670();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  FUN_004eb3b0();
  return;
}
```
