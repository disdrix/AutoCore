# Function record (named): AssManager_SweepTrackedAssets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075de80` |
| **Semantic name** | `AssManager_SweepTrackedAssets_Inferred` |
| **Ghidra name** | `FUN_0075de80` |
| **Address** | `0x0075de80`–`0x0075e2ce` exclusive (**1358 B** / `0x54E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `assets` / `assManager` |
| **Naming basis** | Path string `assManager.cpp` L`0x1BB`; list walk + mode branches; family with sealed AssManager duals (W29-C RemoveResolver, W30-D InitPrecompileAndResolvers) |
| **Status** | Dual sealed W32-O (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0075de80_FUN_0075de80.md`.

## Signature

```c
void __thiscall AssManager_SweepTrackedAssets_Inferred(
    void *assManager /*ECX*/, int mode, float ageThreshold);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-O.
