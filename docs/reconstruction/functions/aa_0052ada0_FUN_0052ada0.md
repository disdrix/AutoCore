# Function record: CVOGCharacter_GetResourceBalanceByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ada0` |
| **Canonical name** | `CVOGCharacter_GetResourceBalanceByType` (proposed; product English open) |
| **Ghidra / prior** | `FUN_0052ada0`; `Named_CalleeOf_CVOGCharacter_CheckMissionRequirements_0052ada0` |
| **Address** | `0x0052ada0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` (shared resource map; also item-cost / UI) |
| **Completion status** | **Partial** — dual A/B sealed CF/ABI/map (2026-07-29); product name + runtime open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Lookup character resource/currency **balance by type id** in ordered map at `char+0x584`. Returns balance at `node+0x10`, or **`-1`** if type missing (end sentinel `char+0x588`).

Mission consumer: `CheckMissionRequirements` Discipline gate (`+0x104` type / `+0x108` threshold).

## Signature (asm-sealed)

```c
int __thiscall CVOGCharacter_GetResourceBalanceByType(void* character /*ECX*/, int typeId);
// RET 4; missing → -1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052ada0_FUN_0052ada0.md`
- Annotated: `docs/reconstruction/raw/aa_0052ada0_FUN_0052ada0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0052ada0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0052ada0_CVOGCharacter_GetResourceBalanceByType.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0052ada0_CVOGCharacter_GetResourceBalanceByType.md`
- Scratch: `docs/reconstruction/tmp/a_0052ada0.md`

## Callers / callees

- **Callee:** `FUN_00418b80` (ordered-map find) @ `0x00418b80`
- **Callers:** `CVOGCharacter_CheckMissionRequirements` @ `0x00546373` + many item-cost / tooltip sites (see xrefs)

## Layout

| Offset | Role |
|--------|------|
| char `+0x584` | map header |
| char `+0x588` | end sentinel |
| node `+0x10` | balance value |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High** (dual 2026-07-29) |
| Map offsets | **High** |
| Product method English | **Open** |
| Parameter semantic names | **High** (role); English tentative |
