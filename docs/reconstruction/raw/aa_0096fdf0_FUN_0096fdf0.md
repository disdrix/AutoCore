# Raw capture: FUN_0096fdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096fdf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096fdf0` |
| **Canonical name** | `FUN_0096fdf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0096fdf0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 4))) {
    iVar1 = FUN_0073df30(DAT_00d1f61c,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0043ed00();
    FUN_0043ee30();
    return 1;
  }
  return 0;
}
```
