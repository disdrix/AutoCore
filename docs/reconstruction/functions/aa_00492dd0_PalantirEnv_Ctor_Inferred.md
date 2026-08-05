# Function record (named): PalantirEnv_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00492dd0` |
| **Semantic name** | `PalantirEnv_Ctor_Inferred` |
| **Ghidra name** | `FUN_00492dd0` |
| **Address** | `0x00492dd0`–`0x004930ab` exclusive (**731 B** / `0x2DB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir env host |
| **Naming basis** | Sole factory arm of `Client_InitPalantirViewBundle_Inferred` stores result at `parent+0xE894` (`sizeof 0x198`); structural env host for subsequent phase init |
| **Status** | Dual sealed W31-P (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_00492dd0_FUN_00492dd0.md`.

## Signature

```c
void *__thiscall PalantirEnv_Ctor_Inferred(void *self, uint32_t arg0, void *parent);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W31-P.
