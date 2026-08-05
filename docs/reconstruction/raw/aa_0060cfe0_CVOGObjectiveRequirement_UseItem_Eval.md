# Raw capture: CVOGObjectiveRequirement_UseItem_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060cfe0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_Eval` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_UseItem_Eval(int param_1,undefined4 param_2,int param_3)

{
  if ((float)*(int *)(param_1 + 0x50) <= *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4))
  {
    return 1;
  }
  return 0;
}
```
