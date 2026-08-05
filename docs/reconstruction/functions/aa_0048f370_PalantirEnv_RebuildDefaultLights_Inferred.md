# Function record (named): PalantirEnv_RebuildDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f370` |
| **Semantic name** | `PalantirEnv_RebuildDefaultLights_Inferred` |
| **Ghidra name** | `FUN_0048f370` |
| **Address** | `0x0048f370`–`0x0048f65f` exclusive (**751 B** / `0x2EF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir env default lights |
| **Naming basis** | Method on Palantir env host (factory slot `parent+0xE894`); strings Direction/Color/Hemispheric/ColorTop/ColorBottom; rebuild via `FUN_0048eb10` + dual `new(0x94)` lights |
| **Status** | Dual sealed W32-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0048f370_FUN_0048f370.md`.

## Signature

```c
void __thiscall PalantirEnv_RebuildDefaultLights_Inferred(void *env);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-R.
