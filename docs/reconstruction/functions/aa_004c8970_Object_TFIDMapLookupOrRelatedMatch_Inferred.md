# Function record: Object_TFIDMapLookupOrRelatedMatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8970` |
| **Canonical name** | `Object_TFIDMapLookupOrRelatedMatch_Inferred` |
| **Ghidra name** | `FUN_004c8970` |
| **Address** | `0x004c8970`–`0x004c8a58` (**0xE9 / 233 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | creature / TFID map / engage gate |
| **Wave** | W30-T |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
uint32_t __thiscall Object_TFIDMapLookupOrRelatedMatch_Inferred(
    void *self,
    uint32_t tfidLo, uint32_t tfidHi, uint32_t tfidW2, uint32_t tfidW3);
```

## Role

Engage-path TFID map lookup / related-object match gate. Non-zero → caller early-return before LinkedDeath partner promote.

## Related duals

- Caller: `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` (`0x005ccff0`, W29-L)
- Leaf: `TFID_EqualsObjectId` (`0x00404aa0`)
- Map helper: `FUN_004cb4b0` (not OWN this wave)
- Creature map head install: `CVOGCreature_ctor` (`+0x158`)

## Artifacts

See `aa_004c8970_FUN_004c8970.md`.
