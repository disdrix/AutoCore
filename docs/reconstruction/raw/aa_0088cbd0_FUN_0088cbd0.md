# Raw capture: FUN_0088cbd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0088cbd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0088cbd0` |
| **Canonical name** | `FUN_0088cbd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0088cbd0(undefined4 param_1,undefined4 param_2)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x5bc) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x1d8))(param_2,1,1);
                    /* WARNING: Could not recover jumptable at 0x0088cbf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x34c))();
    return;
  }
  return;
}
```
