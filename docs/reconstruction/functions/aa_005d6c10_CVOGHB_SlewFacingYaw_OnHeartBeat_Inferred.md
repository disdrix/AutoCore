# Function record: CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c10` |
| **Canonical name** | `CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred` |
| **Ghidra name** | `FUN_005d6c10` |
| **Address** | `0x005d6c10`–`0x005d6c37` (**0x28 / 40 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / creature facing |
| **Wave** | W30-T |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
uint32_t *__thiscall CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred(
    void *self, uint32_t *pOutStatus);
```

## Role

Period tick for secondary facing-slew HB (size 0x28, vtbl `009daee8`): re-slew raw owner by pulse ms, then reschedule.

## Related duals

- Ctor sibling: `CVOGHB_SlewFacingYaw_ctor_Inferred` (`0x005d6b80`, W28-K)
- Slew callee: `CVOGCreature_SlewFacingYaw_Inferred` (`0x004c7bd0`, W22-J)
- Base: `CVOGHBBase_RescheduleAfterFire` (`0x00508350`)
- Factory: `Object_EnsurePrimaryHBAI_FromAIProfile` secondary path (`0x004c9430`)

## Artifacts

See `aa_005d6c10_FUN_005d6c10.md`.
