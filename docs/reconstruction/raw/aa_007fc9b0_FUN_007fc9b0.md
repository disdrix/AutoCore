# Raw capture: FUN_007fc9b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc9b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fc9b0` |
| **Canonical name** | `FUN_007fc9b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fc9b0(void)

{
  char cVar1;
  int in_EAX;
  int *unaff_EDI;
  
  if ((*(int *)(in_EAX + 0xf40) != 0) && (unaff_EDI != (int *)0x0)) {
    cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_007fc970();
      *(undefined1 *)(in_EAX + 0x30b4) = 1;
      *(undefined1 *)(in_EAX + 0x30b5) = 0;
      if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {
        (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
      }
      FUN_007fb990();
      (**(code **)(*unaff_EDI + 0xfc))(0,0x3f000000);
    }
  }
  return;
}
```
