# Raw capture: CVOGHBMissionPatrol_Fn6

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00650de0` |
| **Canonical name** | `CVOGHBMissionPatrol_Fn6` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGHBMissionPatrol_Fn6(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *this;
  int iVar1;
  
  this = (void *)__RTDynamicCast(*(undefined4 *)(param_1 + 0x18),0,
                                 &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGCharacter::RTTI_Type_Descriptor,0);
  if (this != (void *)0x0) {
    iVar1 = CVOGReaction_ResolveObjectTarget
                      (0,*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
    if (iVar1 != 0) {
      CVOGCharacter_EvaluatePendingObjectives(this,0xb,0,0,0);
    }
  }
  FUN_005083f0(param_2,param_3);
  return;
}
```
