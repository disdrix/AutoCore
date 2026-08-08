# Function record: Client_CycleHostileTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943340` |
| **Canonical name** | `Client_CycleHostileTarget_Inferred` |
| **Ghidra name** | `FUN_00943340` |
| **Address** | `0x00943340`–`0x009434fc` (**0x1BD** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / client-input / target selection |
| **Classification** | worker |
| **Dual verdict** | **accept-with-gaps** (A∩B WQ9R-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Cycle hostile targets in range for the client: `Skill_GatherTargetsInArea` mode **2**, max **50**, view-sort, step `client+0x3048` by next/prev, apply with `FUN_0093e120`.

## Signature

```c
// EAX = ClientShell*; stdcall RET 8
void Client_CycleHostileTarget_Inferred(float range, char stepDir);
// stepDir 0 = next (+1); nonzero = prev (-1)
```

## Sealed facts

1. Sole caller `Client_Input_PollBoundActions` @ 110.0f with stepDir 0/1 when `DAT_00d1d888 != 0`.
2. Early-out player `+0x4f1`.
3. Gather mode 2 hostile; score −1.0f; max 50.
4. Selection apply path sets `client+0x3048` (via `FUN_0093e120`).

## Gaps

- Product key action names.
- `FUN_00930360` product plate (view-sort Probable).
- player `+0x4f1` English.
- Runtime confirmation.

## Artifacts

See `aa_00943340_FUN_00943340.md` for full artifact list.
