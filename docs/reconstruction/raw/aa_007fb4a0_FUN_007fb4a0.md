# Raw capture: FUN_007fb4a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb4a0` |
| **Canonical name** | `FUN_007fb4a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_007fb4a0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(code **)(in_EAX + 0xdd4) == (code *)0x0) {
    return 0;
  }
  uVar1 = (**(code **)(in_EAX + 0xdd4))(0x3f800000,0x3f600000,0x40000000);
  return uVar1;
}
```
