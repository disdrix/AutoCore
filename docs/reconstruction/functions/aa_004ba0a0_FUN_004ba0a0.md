# Function record: FUN_004ba0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba0a0` |
| **Canonical name** | `FUN_004ba0a0` |
| **Preferred inferred** | `NDSpecialFX_StopFinalize_Inferred` |
| **Address** | `0x004ba0a0` |
| **Body span** | `004ba0a0`–`004ba26d` (461 B / `0x1CD`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Completion status** | **dual-sealed** 2026-07-29 W27-D |
| **Dual A/B** | `reviews/A_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md`, `reviews/B_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Preferred: `NDSpecialFX_StopFinalize_Inferred`
- **Rejected:** `Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0` (keyword-only from one callee)

## Purpose

Manager-facing **stop/finalize** for NDSpecialFX host: re-entry on `+8`, type-gated early clear, tear down attachment lists, clear `+0x10`, return free polarity.

## Signature (decompiler-derived)

```c
char __fastcall FUN_004ba0a0(int param_1);
// ECX = fx host; plain ret; AL 0|1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ba0a0_FUN_004ba0a0.md`
- Annotated: `docs/reconstruction/raw/aa_004ba0a0_FUN_004ba0a0.annotated.md`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004ba0a0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_StopFinalize_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `0x005179e0` @ `0x00517a1d` | free if `+9==0` and return ≠0 |
| Caller | `0x00514d80` @ `0x00514d9a` | type `+0x28==0xF` batch |
| Callee | `0x004b6a80` | List1e0_AnyFlag10 (case 4) |
| Callee | `0x00723b20` | StopMatchingSounds |
| Callee | `0x004b9af0`, `0x004b9270`, `0x005b8340`, `0x00593e10`, `0x00498a90`, `0x00498ab0` | teardown helpers |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI plain RET + AL 0\|1 | **Confirmed** |
| NDSpecialFX layout family | **High** |
| Product method name | **Inferred** |
| Nested helper English | **Open** |
| Runtime / differential | **Open** |
