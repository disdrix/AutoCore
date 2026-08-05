# Raw capture: FUN_007fb8f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb8f0` |
| **Canonical name** | `FUN_007fb8f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fb8f0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x115c);
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x2b0) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);
  }
  iVar1 = *(int *)(unaff_ESI + 0x1160);
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x2b0) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);
  }
  if (*(undefined4 **)(unaff_ESI + 0x115c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x115c))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x115c) = 0;
  if (*(undefined4 **)(unaff_ESI + 0x1160) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x1160))(1);
  }
  *(undefined4 *)(unaff_ESI + 0x1160) = 0;
  return;
}
```
