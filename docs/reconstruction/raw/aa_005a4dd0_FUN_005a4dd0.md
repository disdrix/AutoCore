# Raw capture: FUN_005a4dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a4dd0` |
| **Canonical name** | `FUN_005a4dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005a4dd0(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_005a4c30(&local_4,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
```
