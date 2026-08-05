# Raw capture: FUN_004badb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004badb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004badb0` |
| **Canonical name** | `FUN_004badb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004badb0(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_004bacf0(&local_4,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
```
