# Function record: EffTextureImpl_ReleaseGpu_Unaccount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096c8e0` |
| **Canonical name** | `EffTextureImpl_ReleaseGpu_Unaccount_Inferred` |
| **Ghidra name** | `FUN_0096c8e0` |
| **Address** | `0x0096c8e0`–`0x0096ca5a` exclusive (**378 B** / `0x17A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics Effects — effTextureImpl GPU release / stats unaccount |
| **Completion status** | **Dual sealed** W38-AB — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Tear down GPU resources on an `effTextureImpl` and subtract memory/count from optional global stats `DAT_00d1f614`:

1. If primary D3D object `+0x10` is live, unaccount by flag/type bank (mirror of create account in `FUN_0096cad0`).
2. `IUnknown::Release` + null on `+0x10` (texture), `+0x14` (RT surface), `+0x18` (depth stencil).

Used by device-reset pre-release walks, create/recreate entry, and environment/buffered-view helpers.

## Signature

```c
// __thiscall ECX=self; plain RET (C3); void
void EffTextureImpl_ReleaseGpu_Unaccount_Inferred(EffTextureImpl* self);
```

## Related

| VA | Role |
|---|---|
| `0x0096cad0` | Create/recreate — calls this first; account path inverse |
| `0x0096e8e0` | Factory ReCreate (W38-AB pair) — create path uses this |
| `0x0075eff0` | `GfxDevice_Reset` — pre-release DEFAULT-pool list walk |
| `0x0096c730` / `0x0096c810` | Size helpers (EDI/this vs explicit this) |
| `0x0096bb20` | Depth-surface byte size (ESI=this) |
| `DAT_00d1f614` | Optional stats host |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096c8e0_FUN_0096c8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096c8e0_FUN_0096c8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTextureImpl_ReleaseGpu_Unaccount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096c8e0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0096c8e0_FUN_0096c8e0.md` |
| A/B | `docs/reconstruction/reviews/A_aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0096c8e0-0096e8e0-w38ab-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Thiscall / 378 B / Release trio | **Confirmed** |
| Stats banks mirror create | **Confirmed** |
| Type nibble cube/volume/2D | **High** |
| Flag `0x1000` product English | **Open** |
| Runtime | **Open** |
