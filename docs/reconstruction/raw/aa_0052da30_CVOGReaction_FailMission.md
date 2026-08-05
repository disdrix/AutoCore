# Raw capture: CVOGReaction_FailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052da30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052da30` |
| **Canonical name** | `CVOGReaction_FailMission` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall CVOGReaction_FailMission(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2;
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x540) + 0x10) +
                           (*(uint *)(*(int *)(param_1 + 0x540) + 8) & param_2) * 4) + 4);
  if (iVar2 != 0) {
    while (param_2 != *(uint *)(iVar2 + 0x10)) {
      iVar2 = *(int *)(iVar2 + 0xc);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {
      iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_007a4480(0,"Player %I64d failed mission %d",*(undefined4 *)(iVar2 + 0x164 + param_1),
                   *(undefined4 *)(iVar2 + 0x168 + param_1),param_2);
      param_2 = uVar1;
      CVOGReaction_FailMissionNotify(&param_2);
      *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x10;
      return 1;
    }
  }
  return 0;
}
```
