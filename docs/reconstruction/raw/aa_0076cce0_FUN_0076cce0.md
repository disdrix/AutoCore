# Raw capture: FUN_0076cce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076cce0` |
| **Canonical name** | `FUN_0076cce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0076cce0(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ab8dc;
  local_c = ExceptionList;
  local_4 = 0;
  for (puVar2 = *(undefined4 **)(param_1 + 0x40); puVar2 != *(undefined4 **)(param_1 + 0x44);
      puVar2 = puVar2 + 1) {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      ExceptionList = &local_c;
      FUN_0076cce0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(param_1 + 0x40) != (void *)0x0) {
    ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + 0x40));
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}
```
