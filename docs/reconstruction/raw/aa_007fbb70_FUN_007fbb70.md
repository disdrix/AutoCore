# Raw capture: FUN_007fbb70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fbb70` |
| **Canonical name** | `FUN_007fbb70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007fbb70(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  if (((param_2 == 0) || (*(int *)(in_EAX + 0x309c) == 0)) ||
     (param_2 == *(int *)(*(int *)(in_EAX + 0x309c) + 0x518))) {
    *(undefined1 *)(in_EAX + 0x30b4) = 1;
    *(undefined1 *)(in_EAX + 0x30b5) = 0;
    if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
    }
  }
  return;
}
```
