# Function record: ActionMap_FindSlotByKeyMod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **Canonical name** | `ActionMap_FindSlotByKeyMod_Inferred` |
| **Ghidra name** | `FUN_007f6db0` |
| **Address** | `0x007f6db0`–`0x007f6fa3` (756 B / `0x2F4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Jump table** | `0x007f6fa4` → `{0x007f6dbc, 0x007f6e2f, 0x007f6eab, 0x007f6f27}` |
| **Completion status** | **Dual sealed MEGA-018** |
| **Dual verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Scan one ActionMap mode bank for a slot whose primary or alternate DIK equals `keyCode`, with modifier-state agreement (both unbound or both bound) **or** per-slot override flag set. Return address of the slot's primary-key field for the OnKeyDown held/edge path.

## Signature (asm-sealed)

```c
uint16_t* ActionMap_FindSlotByKeyMod_Inferred(
    uint32_t mode,       // EAX  0..3
    uint16_t keyCode,    // SI
    uint16_t modState,   // DX   0 or e.g. 0x2A LSHIFT
    uint8_t* actionMap); // EDI
// return EAX = &slot.key0 or NULL; bare RET (C3)
```

## Mode table

| Mode | Max | key0 base | mod0 cursor |
|---|---|---|---|
| 0 | 5 | +0x06 | +0x30 |
| 1 | 6 | +0x10A | +0x134 |
| 2 | 0x78 | +0x242 | +0x26C |
| 3 | 0x14 | +0x1AA2 | +0x1ACC |

Stride **0x34**. Family-shared with `ActionMap_TrySetSlotBind`.

## Call graph

```
Client_Input_OnKeyDown_MatchAction  0x00911030
  └─ ActionMap_FindSlotByKeyMod_Inferred  0x007f6db0   [mode=0, map=0x00d1b9ac]
       (leaf)
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f6db0_FUN_007f6db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_FindSlotByKeyMod_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f6db0.cpp` |
| Retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |
| Address record | `docs/reconstruction/functions/aa_007f6db0_FUN_007f6db0.md` |
| Report | `docs/agents/task-dual-ab-007f6db0-mega-018-report.md` |

## Gaps

- Mode group product English.
- Override-flag product name.
- Modes 1–3 live callers.
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / bounds / dual-lane | **High** |
| Name (ActionMap family, _Inferred) | **High** structure / **Tentative** product |
| Runtime | **Open** |
