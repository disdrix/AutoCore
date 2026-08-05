# Raw capture: FUN_007a3cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a3cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a3cb0` |
| **Canonical name** | `FUN_007a3cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007a3cb0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xd4) != 0) {
    FUN_00970a90();
    if (*(undefined4 **)(in_EAX + 0xd4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_EAX + 0xd4))(1);
    }
    *(undefined4 *)(in_EAX + 0xd4) = 0;
    *(undefined4 *)(in_EAX + 0xd4) = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x2b8));
  if (*(undefined4 **)(in_EAX + 0x128) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0x128))(1);
  }
  *(undefined4 *)(in_EAX + 0x128) = 0;
  FUN_0079e3e0();
  FUN_007544f0(in_EAX);
  return;
}
```
