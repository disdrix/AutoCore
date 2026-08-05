# Raw capture: FUN_0080cbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080cbf0` |
| **Canonical name** | `FUN_0080cbf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0080cbf0(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  FUN_007fef20(0x39,1,0);
  if (*(int **)(param_1 + 0x1114) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x1114) + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_0086d580(*(undefined4 *)(unaff_ESI + 0x10),*(undefined4 *)(unaff_ESI + 8),
                   *(undefined4 *)(unaff_ESI + 0xc),unaff_ESI + 0x14,unaff_ESI + 0x1c,
                   unaff_ESI + 0x30);
    }
  }
  return;
}
```
