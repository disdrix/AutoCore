# Function record: NDSpecialFX_StopFinalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba0a0` |
| **Canonical name** | `NDSpecialFX_StopFinalize_Inferred` |
| **Ghidra name** | `FUN_004ba0a0` |
| **Address** | `0x004ba0a0`–`0x004ba26d` |
| **Module** | `autoassault.exe` |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Completion status** | **dual-sealed** 2026-07-29 W27-D |
| **Dual A/B** | `reviews/A_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md`, `reviews/B_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` |

## Purpose

NDSpecialFX host **stop/finalize** for manager prune paths. Distinct from HostTick-driven `DeactivateClear`.

```c
uint8_t __fastcall NDSpecialFX_StopFinalize_Inferred(void *fx_host);
// 1 = manager may free (default); 0 = early-clear polarity
```

## Artifacts

- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_StopFinalize_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004ba0a0.cpp`
- Raw / annotated under `aa_004ba0a0_FUN_004ba0a0*`

## Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_005179e0` | `0x00517a1d` | `+9==0` and non-zero → delete fx |
| `FUN_00514d80` | `0x00514d9a` | type 0xF path |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI sealed | **Confirmed** |
| Role vs DeactivateClear | **High** |
| Product English | **Inferred** |
