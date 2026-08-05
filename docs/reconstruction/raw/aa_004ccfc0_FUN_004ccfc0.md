# Raw capture: FUN_004ccfc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ccfc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ccfc0` |
| **Canonical name** | `FUN_004ccfc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 FUN_004ccfc0(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_005c9c50();
  iVar1 = *(int *)(iVar2 + 4);
  if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(iVar2 + 8) - iVar1 >> 2))) {
    return *(undefined1 *)(iVar1 + 2 + param_1 * 4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_004ccf30();
}
```
