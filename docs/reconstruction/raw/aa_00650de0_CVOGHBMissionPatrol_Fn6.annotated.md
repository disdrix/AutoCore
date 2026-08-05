# Annotated low-level: CVOGHBMissionPatrol_Fn6

| Field | Value |
|---|---|
| Stable ID | `aa_00650de0` |
| VA | `0x00650de0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00650de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
