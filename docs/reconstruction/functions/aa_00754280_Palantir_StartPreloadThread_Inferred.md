# Function record: Palantir_StartPreloadThread_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754280` |
| **Canonical name** | `Palantir_StartPreloadThread_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00754280` |
| **Address** | `0x00754280`–`0x007542e8` (**105 B** / `0x69`) |
| **Module** | `autoassault.exe` |
| **System** | Palantir / thrThread preload |
| **Status** | Dual A/B sealed W31-F 2026-07-29 — **accept-with-gaps** |

## Purpose

Worker that allocates and starts the Palantir preload thrThread once on host `+0xd4`. Idempotent fail path logs `"Preload thread already runnning."` (Palantir.cpp:0x1fd). Complements preloading enable/disable toggle (`FUN_00934420`) and AssManager bootstrap (`FUN_007b75b0`).

## Signature

```c
// Retail: EDI=host; plain RET; AL 0/1
uint8_t Palantir_StartPreloadThread_Inferred(void* host /*EDI*/);
```

## Layout

| Off | Object | Role |
|-----|--------|------|
| host `+0xd4` | Palantir | preload thrThread* |
| thr `+0x00` | thrThread | vftable |
| thr `+0x04` | thrThread | thread id |
| thr `+0x08` | thrThread | HANDLE |
| thr `+0x0c` | thrThread | context (`DAT_00d1f050+0x6c`) |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00754280_FUN_00754280.md` |
| Annotated | `docs/reconstruction/raw/aa_00754280_FUN_00754280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_StartPreloadThread_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754280.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00754280_FUN_00754280.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_00754280_Palantir_StartPreloadThread_Inferred.md`, `B_…` |
| Scratch | `docs/reconstruction/tmp/a_00754280.md` |

## Related

- W30-D: `AssManager_InitPrecompileAndResolvers_Inferred` calls this after precompile path publish.
- `FUN_0071aef0` thrThread CreateThread (thrThread.cpp).
- `FUN_00934420` Preloading enabled/disabled toggle.
