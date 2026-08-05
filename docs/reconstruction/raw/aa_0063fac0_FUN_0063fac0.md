# Raw capture: FUN_0063fac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063fac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063fac0` |
| **Canonical name** | `FUN_0063fac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0063fac0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x24,0x10);
  *(undefined2 *)(iVar1 + 4) = 0x24;
  FUN_00652790(0xffffffff);
  return;
}
```
