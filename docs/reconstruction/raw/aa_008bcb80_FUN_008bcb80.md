# Raw capture: FUN_008bcb80

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bcb80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bcb80` |
| **Canonical name** | `FUN_008bcb80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008bcb80(int param_1,undefined4 param_2)

{
  float10 fVar1;
  
  FUN_007916e0(param_2);
  if (((char)param_2 != '\0') && (*(int *)(param_1 + 0x524) != 0)) {
    fVar1 = (float10)(**(code **)(**(int **)(param_1 + 0x524) + 0x3c4))();
    if ((float10)g_flZero == fVar1) {
      (**(code **)(**(int **)(param_1 + 0x524) + 0xcc))(0);
      if (*(int *)(param_1 + 0x520) != 0) {
                    /* WARNING: Could not recover jumptable at 0x008bcbe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(param_1 + 0x520) + 0xcc))();
        return;
      }
    }
  }
  return;
}
```
