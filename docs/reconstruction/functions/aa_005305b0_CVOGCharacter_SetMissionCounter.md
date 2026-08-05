# Function record: CVOGCharacter_SetMissionCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005305b0` |
| **Canonical name** | `CVOGCharacter_SetMissionCounter` (proposed; product English open) |
| **Ghidra** | `FUN_005305b0` |
| **Address** | `0x005305b0`–`0x00530603` exclusive (**83** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed** W30-I 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Absolute-set a character map entry by key into Val12 mapped second dword (`node+0x14`). Miss path get-or-insert via `StdTree_OperatorIndex_Val12` and seeds `{0, value}`. Sibling `CVOGCharacter_AddMissionCounter` (`0x00530610`) adds on hit.

## Signature

```c
void __thiscall CVOGCharacter_SetMissionCounter(void* character, uint32_t key, int32_t value);
// RET 8
```

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_005305b0_FUN_005305b0.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetMissionCounter.cpp`
- Dual A/B under `docs/reconstruction/reviews/A|B_aa_005305b0_CVOGCharacter_SetMissionCounter.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Name English | **Inferred** (mirrors sealed AddMissionCounter sibling) |
