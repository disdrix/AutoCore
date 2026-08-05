# Function record: CVOGCharacter_TryClearMissionCounterIfPositive

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530670` |
| **Canonical name** | `CVOGCharacter_TryClearMissionCounterIfPositive` |
| **Ghidra** | `FUN_00530670` |
| **Address** | `0x00530670`–`0x00530708` exclusive (**152 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual sealed** W31-S 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Try-clear a character mission/resource counter by key when the Set-field (`node+0x14`) is strictly positive: zero Get-field (`+0x10`), Set(key,0), dirty bit `0x40` at `char+0x634`, return success bool.

## Signature

```c
bool __thiscall CVOGCharacter_TryClearMissionCounterIfPositive(void *character, uint32_t key);
// RET 4
```

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_00530670_FUN_00530670.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryClearMissionCounterIfPositive.cpp`
- Dual A/B under `docs/reconstruction/reviews/`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Name English | **Inferred** (structural + sole caller context) |
