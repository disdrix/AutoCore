# Raw capture: FUN_004cb3a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb3a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb3a0` |
| **Canonical name** | `FUN_004cb3a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_004cb3a0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  if (((-1 < iVar1) && (iVar1 < 0x13)) && (*(int *)(param_1 + 0x2c + iVar1 * 4) != 0)) {
    return 1;
  }
  return 0;
}
```
