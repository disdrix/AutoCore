# Function record: EffTextureFactory_ReCreateDefaultPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e8e0` |
| **Canonical name** | `EffTextureFactory_ReCreateDefaultPool_Inferred` |
| **Ghidra name** | `FUN_0096e8e0` |
| **Address** | `0x0096e8e0`–`0x0096e9e4` exclusive (**260 B** / `0x104`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics Effects — effTextureFactory ReCreate (device reset) |
| **Completion status** | **Dual sealed** W38-AB — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Sole Texture-Factory step of `GfxDevice_Reset`: walk factory list at `+0x8`, and for each `effTextureImpl` with pool/state `+0x30 == 0`:

1. If `(flags & 0x3000)==0`: `FUN_0096cad0` recreate (create body releases via `FUN_0096c8e0` first).
2. Else: `Release` interface at `impl+0x4c`.
3. On `hr < 0`: format `assId` via `FUN_0096a630`, log factory.cpp:0x159, return hr.

## Signature

```c
// stack factory*; RET 0x04; returns hr (0 ok)
int EffTextureFactory_ReCreateDefaultPool_Inferred(EffTextureFactory* factory);
```

## Related

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` — sole caller; factory at device `+0x754` |
| `0x0096cad0` | Create/recreate worker |
| `0x0096c8e0` | Release+unaccount (W38-AB pair) — first step of create |
| `0x0096a630` | `assId: [...]` string builder |
| Family | IB/VB/Effect/BufferedView Reset siblings in `gfxDevice.cpp` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096e8e0_FUN_0096e8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e8e0_FUN_0096e8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTextureFactory_ReCreateDefaultPool_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e8e0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0096e8e0_FUN_0096e8e0.md` |
| A/B | `docs/reconstruction/reviews/A_aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0096c8e0-0096e8e0-w38ab-report.md` |

## Confidence

| Claim | Level |
|---|---|
| RET 4 / factory stack / SEH / strings | **Confirmed** |
| List + DEFAULT gate + recreate/fail CF | **Confirmed** |
| Flag `0x3000` / `+0x4c` product role | **Open** |
| Runtime | **Open** |
