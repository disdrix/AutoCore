# Raw capture: Client_EnqueueCombatFloater_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402620` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00402620` |
| **Canonical name** | `Client_EnqueueCombatFloater_INFERRED` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_EnqueueCombatFloater_INFERRED
   
   INFERRED: queues a combat floater message on the local vehicle.
   XP path builds stack blob with type field = CombatFloaterType::XP (3).
   Also used by kill-award success path.
   Dependency of session XP RE only — full floater layout not fully typed. */

void __thiscall Client_EnqueueCombatFloater_INFERRED(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x38) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x38))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_00404600(iVar1,1,param_2,param_1,param_2);
    *(int *)(param_1 + 8) = iVar1 + 0x38;
    return;
  }
  FUN_00402e20(&param_2,*(undefined4 *)(param_1 + 8),param_2);
  return;
}
```
