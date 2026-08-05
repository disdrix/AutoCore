# Raw capture: operator_delete__

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048981c` |
| **Canonical name** | `operator_delete__` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0048981c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(param_1);
  return;
}
```
