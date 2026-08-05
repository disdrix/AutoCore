# Raw capture: CVOGObjectiveRequirement_Patrol_GetTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e370` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060e370` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_GetTarget` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_Patrol_GetTarget(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);
  if (*(int *)(param_1 + 0x24) * *(int *)(param_1 + 0xd0) <= iVar1) {
    return 0;
  }
  iVar1 = iVar1 % *(int *)(param_1 + 0xd0);
  param_2[2] = *(undefined4 *)(param_1 + 0x30 + iVar1 * 8);
  param_2[3] = *(undefined4 *)(param_1 + 0x34 + iVar1 * 8);
  *(undefined1 *)((int)param_2 + 0xea) = *(undefined1 *)(param_1 + 0x10);
  param_2[0x3b] = *(undefined4 *)(param_1 + 0x14);
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  return 1;
}
```
