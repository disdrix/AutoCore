# Raw capture: FUN_0042acc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042acc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042acc0` |
| **Canonical name** | `FUN_0042acc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0042acc0(int param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  
  for (; param_1 != 0; param_1 = param_1 + -1) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *param_2;
      in_EAX[1] = param_2[1];
      in_EAX[2] = param_2[2];
    }
    in_EAX = in_EAX + 3;
  }
  return;
}
```
