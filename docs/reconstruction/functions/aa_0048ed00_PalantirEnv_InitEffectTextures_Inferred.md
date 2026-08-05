# Function record (named): PalantirEnv_InitEffectTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048ed00` |
| **Semantic name** | `PalantirEnv_InitEffectTextures_Inferred` |
| **Ghidra name** | `FUN_0048ed00` |
| **Address** | `0x0048ed00`–`0x0048ed81` exclusive (**129 B** / `0x81`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir env effect textures |
| **Naming basis** | Method on Palantir env; sole callee path of InitPhases; `FUN_0096f0e0` = `effTexture.cpp` texture instance create/bind; dual full/half dim slots |
| **Status** | Dual sealed W32-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0048ed00_FUN_0048ed00.md`.

## Signature

```c
void __thiscall PalantirEnv_InitEffectTextures_Inferred(void *env);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W32-R.
