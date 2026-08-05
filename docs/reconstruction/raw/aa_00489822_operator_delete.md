# Raw capture: operator_delete

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489822` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00489822` |
| **Canonical name** | `operator_delete` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00489822. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}
```
