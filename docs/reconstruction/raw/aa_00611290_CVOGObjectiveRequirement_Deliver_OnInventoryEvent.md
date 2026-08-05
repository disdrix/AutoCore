# Raw capture: Deliver OnInventoryEvent (INFERRED)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611290` |
| **VA** | `0x00611290` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` |
| **Prior** | `FUN_00611290` |
| **Note** | Prior wave: type family Deliver (not Collect); cargo count readiness |

## Raw pseudocode

```c
undefined4 __thiscall
FUN_00611290(int param_1,int param_2,int *param_3,int param_4,float param_5,undefined4 param_6,
            undefined4 param_7,int param_8)

{
  int iVar1;
  // ...
  if (param_4 == 4) {
    if (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0) {
      iVar1 = FUN_005711c0(*(undefined4 *)(param_1 + 0x10),0);
      if (((int)param_5 == *(int *)(param_1 + 0x18)) &&
         ((*(int *)(param_1 + 0x14) <= iVar1 || (*(char *)(param_1 + 0x23) == '\0')))) {
        param_3[*(byte *)(param_1 + 8) + 1] = (int)g_flOne;
        if (*(char *)(param_1 + 0x22) != '\0') {
          // BuildTextParams toast with char COID + NPC TFID
          CVOGReaction_BuildTextParams(&local_30);
        }
        return 1;
      }
    }
  }
  return 0;
}
```
