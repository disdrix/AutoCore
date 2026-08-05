# Function record: AssPreloader_RetireStaleNeverLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970e50` |
| **Canonical name** | `AssPreloader_RetireStaleNeverLoaded_Inferred` |
| **Ghidra name** | `FUN_00970e50` |
| **Address** | `0x00970e50`–`0x00970fb8` (**360 B** / `0x168`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W33-O 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

For each tracked preload-map entry older than `maxAge`, release the never-loaded asset, log product retire text, enqueue a PodU32U8 into `self+0xAC`, and erase the map node. Always emits a summary retire count log.

## Signature

```c
// stack (AssPreloader* self, float maxAge); RET 8; void
void AssPreloader_RetireStaleNeverLoaded_Inferred(void* self /*stack*/,
                                                  float maxAge /*stack*/);
```

## Host offsets (sealed)

| Off | Role |
|-----|------|
| `+0x10` / `+0x14` | map base / end sentinel |
| node `+0x0C` | key (assId via `FUN_0096a630`) |
| node `+0x10` | owned object* (optional vtbl[0](1)) |
| node `+0x14` | float timestamp |
| `+0xAC` | GuardedVector locked stride-2 U32U8 retire ring |

## Product evidence

| Line | String |
|------|--------|
| `0x2A8` | `Preloaded asset <%s> never loaded. Retiring and removing.` |
| `0x2B7` | `Retired %d preload blocks from pool.` |
| file | `...\palantir\assets\assPreloader.cpp` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.md`
- Annotated: `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_RetireStaleNeverLoaded_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00970e50.cpp`
- FUN record: `docs/reconstruction/functions/aa_00970e50_FUN_00970e50.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-0075d3c0-00970e50-w33o-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI (RET 8) + age polarity + product logs | **High** |
| AssPreloader family | **High** |
| Product method English | **Inferred** |
| Nested map erase / key type dual | **Open** |
| Runtime / bit-exact | **Open** |
