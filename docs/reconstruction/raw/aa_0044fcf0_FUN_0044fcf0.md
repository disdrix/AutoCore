# Raw capture: FUN_0044fcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044fcf0` |
| **Canonical name** | `FUN_0044fcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0044fcf0(int param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  
  for (; param_1 != 0; param_1 = param_1 + -1) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *param_2;
      *(undefined2 *)(in_EAX + 1) = *(undefined2 *)(param_2 + 1);
    }
    in_EAX = (undefined4 *)((int)in_EAX + 6);
  }
  return;
}
```
