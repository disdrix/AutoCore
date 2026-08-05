# Raw capture: CVOGObjectiveRequirement_Patrol_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e0f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060e0f0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_Eval` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_Patrol_Eval(int param_1,undefined4 param_2,int param_3)

{
  if ((float)(*(int *)(param_1 + 0xd0) * *(int *)(param_1 + 0x24)) <=
      *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4)) {
    return 1;
  }
  return 0;
}
```
