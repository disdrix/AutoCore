# Function record (named): WaterPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005769c0` |
| **Semantic name** | `WaterPhase_Ctor_Inferred` |
| **Ghidra name** | `FUN_005769c0` |
| **Address** | `0x005769c0`–`0x00576a07` exclusive (**71 B** / `0x47`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector water phase |
| **Naming basis** | Factory water singleton `new(0x20)` + view; `VOGEnvironmentSector.cpp` water fail string on peer init; vtbl near `RTTextureExt` |
| **Status** | Dual sealed W32-S (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_005769c0_FUN_005769c0.md`.

## Signature

```c
void *__thiscall WaterPhase_Ctor_Inferred(void *self, void *view);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-S.
