# Raw capture: FUN_0044bcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044bcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044bcc0` |
| **Canonical name** | `FUN_0044bcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0044bcc0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10), iVar1 != 0))
  {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}
```
