# Raw capture: FUN_008c8fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c8fa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008c8fa0` |
| **Canonical name** | `FUN_008c8fa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008c8fa0(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x590);
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)((int)piVar1 + 0x489) = 0;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);
    piVar1[0x8b] = *piVar2;
  }
  piVar1 = *(int **)(unaff_ESI + 0x594);
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)((int)piVar1 + 0x489) = 0;
    piVar2 = (int *)(**(code **)(*piVar1 + 0x170))(3);
    piVar1[0x8b] = *piVar2;
  }
  if (*(int *)(unaff_ESI + 0x564) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x564) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x56c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x56c) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x570) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x570) + 0xd4))(1);
  }
  if (*(int *)(unaff_ESI + 0x568) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0xd4))(1);
  }
  return;
}
```
