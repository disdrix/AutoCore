# Function record: CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ccff0` |
| **Canonical name** | `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` |
| **Ghidra name** | `FUN_005ccff0` |
| **Address** | `0x005ccff0`–`0x005cd220` (**560 B / 0x230**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CVOGHB AI |
| **Wave** | W29-L |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
void __thiscall CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred(void *hbai);
```

## Role

Engage-path retarget: resolve owner TFID, promote direct candidate or LinkedDeath partner; clear mode on resolve fail.

## Related duals

- `Object_SetMode278_SelectFromTFID228_Inferred` (`0x004c3c80`, W28-L)
- `Object_SetSelectedTarget` (`0x005172d0`)
- `Object_ResolveFromTFID` (`0x004bb950`)
- `LockedList_TryAdvanceIterator_Inferred` (`0x004022a0`)
- Caller plate: `CVOGHBAICreatureBase_OnHeartBeat`

## Artifacts

See `aa_005ccff0_FUN_005ccff0.md`.
