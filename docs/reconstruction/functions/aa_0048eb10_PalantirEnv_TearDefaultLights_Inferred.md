# Function record: PalantirEnv_TearDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048eb10` |
| **Canonical name** | `PalantirEnv_TearDefaultLights_Inferred` |
| **Ghidra name** | `FUN_0048eb10` |
| **Address** | `0x0048eb10` |
| **Body range** | `0x0048eb10`–`0x0048eb99` exclusive (**137 B** / `0x89`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir env default lights |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/slots/callers sealed; manager product English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md`, `reviews/B_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` (2026-07-29 W34-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0048eb10`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0048eb10` (**reject** — login-callback long name; unit is env light teardown)
- Host: Palantir env / `CVOGEnvironmentSector` method (**High** via peer slots + Sector dtor vtbl)

## Purpose

Destroy the default light pair on the Palantir env host (rebuild-safe prelude):

1. If `env+0x104` (hemispheric) non-null: `FUN_0074e260(mgr=env+4, *(light+0x8c))`; scalar dtor(1); null slot.
2. If `env+0x108` (directional) non-null: `FUN_0074e0d0(mgr, 0)`; same unregister/dtor/null.
3. If `env+0xC4` (Reflect) non-null: tail to `FUN_005b3580(reflect)` (tears `reflect+0x150`).

## Signature

```c
void __thiscall PalantirEnv_TearDefaultLights_Inferred(void *env);
// ECX=env*; bare RET; void
```

## Algorithm

```
mgr = *(env+4)
if *(env+0x104): unregister core; dtor(1); null
if *(env+0x108): clear attach(0); unregister core; dtor(1); null
if *(env+0xC4):  FUN_005b3580(reflect); return
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0048eb10_FUN_0048eb10.md`
- Annotated: `docs/reconstruction/raw/aa_0048eb10_FUN_0048eb10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PalantirEnv_TearDefaultLights_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0048eb10.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0048eb10_FUN_0048eb10.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0078caf0-0048eb10-w34t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x0074e260` | effect-core unregister/release (mgr thiscall) |
| Callee | `0x0074e0d0` | mgr attach clear (arg 0) |
| Callee | `0x005b3580` | Reflect `+0x150` tear |
| Caller | `0x0048f370` @ `0x0048f38d` | `PalantirEnv_RebuildDefaultLights_Inferred` prelude |
| Caller | `0x00492be0` @ `0x00492c16` | `CVOGEnvironmentSector` dtor path |
| Caller | `0x0091e1d7` | orphan site; ECX=`[client+…]+0xE894` env |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes + bare RET | **Confirmed** |
| thiscall ECX=env | **Confirmed** |
| Slots +0x104 hemi / +0x108 dir / +0xC4 Reflect | **Confirmed** (W32-R / W33-T peers) |
| Manager this = env+4 | **Confirmed** (bytes) |
| Product English for 0074e* ops | **Open** |
| Runtime / differential | **Open** |
