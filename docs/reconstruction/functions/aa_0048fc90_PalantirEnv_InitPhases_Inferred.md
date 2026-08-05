# Function record (named): PalantirEnv_InitPhases_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048fc90` |
| **Semantic name** | `PalantirEnv_InitPhases_Inferred` |
| **Ghidra name** | `FUN_0048fc90` |
| **Address** | `0x0048fc90`–`0x0048fed0` exclusive (**576 B** / `0x240`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector phases |
| **Naming basis** | Method on env host from Palantir factory; source `VOGEnvironmentSector.cpp` water/distort fail strings; multi-phase bootstrap not just NDRiver.fx |
| **Status** | Dual sealed W31-P (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0048fc90_FUN_0048fc90.md`.

## Signature

```c
uint32_t __thiscall PalantirEnv_InitPhases_Inferred(void *env, void *flag);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W31-P.
