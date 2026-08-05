# Function record: Client_CompileEffectsBootstrap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00948bd0` |
| **Canonical name** | `Client_CompileEffectsBootstrap_Inferred` |
| **Ghidra name** | `FUN_00948bd0` |
| **Address** | `0x00948bd0`–`0x009492c7` (**1784 B** / `0x6F8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / -compileeffects tool path |
| **Wave** | W31-H OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Classification** | worker |

## Purpose

Bootstrap the offline `-compileeffects` path: allocate helper, init AssManager (mode=1), create hidden Auto Assault window, init render engine, preload 36 effect shaders.

## Signature (sealed)

```c
// ESI = client host; bare C3; void
void Client_CompileEffectsBootstrap_Inferred(void* self /*ESI*/);
```

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssManager_InitPrecompileAndResolvers_Inferred` | `0x007b75b0` | nested init mode=1 (W30-D) |
| `AssPackManager_OpenPackFile_Inferred` | `0x00984ee0` | opened inside AssManager batch (this wave) |
| `Client_InitInstance` | `0x0094a6a0` | general game init (not this path) |

## Rejected aliases

- `Drive_NDRiver_fx_00948bd0` — false plate from one FX string.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.md`
- Annotated: `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_CompileEffectsBootstrap_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00948bd0.cpp`
- Function FUN: `docs/reconstruction/functions/aa_00948bd0_FUN_00948bd0.md`
- A: `docs/reconstruction/reviews/A_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_00948bd0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow stages | **High** |
| -compileeffects sole caller | **High** |
| Window/class strings | **High** |
| Nested render/FX product English | **Med** |
| Runtime | **Open** |
