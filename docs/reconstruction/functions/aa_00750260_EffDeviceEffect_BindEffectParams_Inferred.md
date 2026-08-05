# Function record: EffDeviceEffect_BindEffectParams_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00750260` |
| **Canonical name** | `EffDeviceEffect_BindEffectParams_Inferred` (**Inferred** structural + source path) |
| **Ghidra name** | `FUN_00750260` |
| **Scaffold alias** | `Named_effDeviceEffect` / `Named_effDeviceEffect_00750260` |
| **Address** | `0x00750260`–`0x0075184F` (**5616 B** / `0x15F0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir `graphics/Effects/effDeviceEffect.cpp` |
| **Completion status** | **Dual-reviewed** W34-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred); clean is structural not line-faithful |

## Purpose

Post-`D3DXCreateEffect` parameter bind/parse for the device effect object: walks the effect COM interface, resolves light/matrix/texture semantics by product name table, fills per-pass records (stride `0xD4`), and returns success/`-1`.

## Signature

```c
// Stack object* at [EBP+8]; call site also pushes path/name string*.
// Returns int: 0 success, 0xFFFFFFFF fail. EBP frame + SEH LAB_009b1b66.
int EffDeviceEffect_BindEffectParams_Inferred(void* device_effect /*, path? */);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | sole `FUN_00751890` @ `0x00751963` (fallback effect path) |
| Callees (key) | `FUN_00416410` (operator+ string), `FUN_0074f3c0`, `FUN_0074f600`, `FUN_005ae2b0`, `FUN_007462e0`, `FUN_0076cec0`, `FUN_00964bc0`, `FUN_0096a630`, `vog_LogMessage`, `_stricmp`, `strstr`, `_aligned_malloc`, effect helpers `004454c0`–`00448180`, string CRT |

## Product strings

`LightCount_`, `LightSupport_`, `WorldView`, `InvWorldViewProjection`, `WorldArray`, `MorphArray`, `World`, `InvWorldScale`, `InvWorld`, `CylBillboard`, `SphBillboard`, `NormalizingCubeMap`, `Diffuse`, `Ambient`, `Emissive`, source path `...\Effects\effDeviceEffect.cpp`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00750260_FUN_00750260.md`
- Annotated: `docs/reconstruction/raw/aa_00750260_FUN_00750260.annotated.md`
- Clean (structural): `docs/reconstruction/reconstructed-exact/EffDeviceEffect_BindEffectParams_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00750260.cpp` / `Named_effDeviceEffect_00750260.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00750260_FUN_00750260.md`
- Review A: `docs/reconstruction/reviews/A_aa_00750260_EffDeviceEffect_BindEffectParams_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00750260_EffDeviceEffect_BindEffectParams_Inferred.md`
- Nested dual peer: `aa_00416410` StdString_OperatorPlus_String (W33-F)

## Confidence

| Claim | Level |
|---|---|
| Body bounds 0x15F0 | **High** |
| Product file / effect-bind role | **High** |
| String semantic table | **High** |
| Stack object* + int return | **High** |
| Full type recovery / 2nd formal | **Low–Med** (decompiler type-prop failed; call site 2nd arg present) |
| Nested callee semantics | **Open** (unowned) |
| Runtime | **Open** |
