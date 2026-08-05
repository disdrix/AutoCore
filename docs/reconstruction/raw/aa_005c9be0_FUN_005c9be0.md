# Raw capture: FUN_005c9be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c9be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c9be0` |
| **Canonical name** | `FUN_005c9be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_005c9be0(int param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a6f6b;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0xd0) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      *(undefined4 *)((int)pvVar1 + 8) = 0;
      *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    }
    *(void **)(param_1 + 0xd0) = pvVar1;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(param_1 + 0xd0);
}
```
