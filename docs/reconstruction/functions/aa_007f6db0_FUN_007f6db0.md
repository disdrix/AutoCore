# Function record: FUN_007f6db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **Canonical name** | `FUN_007f6db0` |
| **Named alias** | `ActionMap_FindSlotByKeyMod_Inferred` |
| **Address** | `0x007f6db0`–`0x007f6fa3` (756 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Dual sealed MEGA-018** — raw re-verify + annotated + clean named + A/B |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Named: `ActionMap_FindSlotByKeyMod_Inferred`
- Retired scaffold: `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0`

## Purpose

Leaf ActionMap key+mod slot lookup across four mode groups. Returns pointer to matched slot's key0 field, or NULL.

## Signature (asm-sealed)

```c
// EAX=mode EDI=actionMap SI=keyCode DX=modState; bare RET; EAX out
uint16_t* FUN_007f6db0(uint32_t mode, uint16_t keyCode, uint16_t modState, uint8_t* actionMap);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.md`
- Annotated: `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_007f6db0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/ActionMap_FindSlotByKeyMod_Inferred.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md`
- Report: `docs/agents/task-dual-ab-007f6db0-mega-018-report.md`

## Callers / callees

| Direction | Target |
|---|---|
| Callers (1) | `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` site `0x00911429` |
| Callees | **none** (leaf) |
| Xrefs | 1 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Register ABI EAX/EDI/SI/DX + RET0 | **High** |
| Mode bounds / stride 0x34 / dual lane | **High** |
| Parameter semantic names | **High** (key/mod/mode/map) |
| Mode product English | **Tentative** |
| Runtime | **Open** |
