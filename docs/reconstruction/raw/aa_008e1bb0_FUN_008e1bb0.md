# Raw capture: FUN_008e1bb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1bb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e1bb0` |
| **Canonical name** | `FUN_008e1bb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008e1bb0(void)

{
  int unaff_ESI;
  char local_100 [256];
  
  if ((*(int *)(unaff_ESI + 0x51c) != 0) && (DAT_00d1b6d8 != 0)) {
    sprintf(local_100,"%i",(int)*(short *)(DAT_00d1b6d8 + 0x580));
    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x1d8))(local_100,1,1);
    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x34c))();
  }
  return;
}
```
