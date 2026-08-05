# Raw capture: FUN_0071fad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071fad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071fad0` |
| **Canonical name** | `FUN_0071fad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0071fad0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x14) != 0) {
    uVar1 = FUN_0071f0f0();
    return uVar1;
  }
  return 0x80004005;
}
```
