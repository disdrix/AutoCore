# Raw capture: FUN_0074ecd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ecd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074ecd0` |
| **Canonical name** | `FUN_0074ecd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0074ecd0(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = FUN_00963950(in_EAX);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  FUN_0074eaa0();
  return 0;
}
```
