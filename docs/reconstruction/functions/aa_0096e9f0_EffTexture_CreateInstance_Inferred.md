# Function record (named): EffTexture_CreateInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e9f0` |
| **Semantic name** | `EffTexture_CreateInstance_Inferred` |
| **Ghidra name** | `FUN_0096e9f0` |
| **Address** | `0x0096e9f0`–`0x0096ea5a` exclusive (**106 B** / `0x6A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics Effects — effTexture factory |
| **Naming basis** | Factory for effect-texture instances; freelist+ctor+`effTextureImpl` init; callers under `effTexture.cpp` create-or-assign path |
| **Status** | Dual sealed W38-O (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0096e9f0_FUN_0096e9f0.md`.

## Signature

```c
// EBX=dims[2]*; 5 stack dwords; RET 0x14; object* or null
void* __stdcall EffTexture_CreateInstance_Inferred(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W38-O.
