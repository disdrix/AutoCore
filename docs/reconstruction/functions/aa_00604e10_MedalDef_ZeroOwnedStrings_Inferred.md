# Function record: MedalDef_ZeroOwnedStrings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e10` |
| **Canonical name** | `MedalDef_ZeroOwnedStrings_Inferred` |
| **Address** | `0x00604e10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | N/A (trivial) |

## Alias

- Ghidra: `FUN_00604e10`

## Purpose

Zero four owned string pointer slots (`+0x04`..`+0x10`) on a 0x1c MedalDef after `operator_new`; returns this.

## Signature

```c
MedalDef* __fastcall MedalDef_ZeroOwnedStrings(MedalDef *this);
```

## Artifacts

- Dual A/B under `reviews/A_aa_00604e10_*` / `B_aa_00604e10_*`
- Raw / clean scaffold present
