# Raw capture: CVOGObjectiveRequirement_Patrol_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e120` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060e120` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_Action` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __thiscall
CVOGObjectiveRequirement_Patrol_Action(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xd0) * *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    return (float10)g_flOne;
  }
  param_3 = *(float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4) / (float)iVar1;
  if (g_flOne <= param_3) {
    param_3 = g_flOne;
  }
  return (float10)param_3;
}
```
