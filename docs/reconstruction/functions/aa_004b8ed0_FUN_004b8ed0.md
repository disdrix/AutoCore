# Function record: FUN_004b8ed0 (alias of NDSpecialFX_HostTick_Inferred)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **Canonical name** | `FUN_004b8ed0` (alias → `NDSpecialFX_HostTick_Inferred`) |
| **Preferred name** | `NDSpecialFX_HostTick_Inferred` |
| **Address** | `0x004b8ed0` |
| **Body span** | `004b8ed0`–`004b9240` (880 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Completion status** | **partial** — dual A/B sealed 2026-07-29 W24-C |
| **Dual A/B** | `reviews/A_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md`, `reviews/B_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Preferred: `NDSpecialFX_HostTick_Inferred`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004b8ed0` (rejected as role label)

## Purpose

NDSpecialFX host tick / deactivate path — see named record.

## Signature (decompiler-derived)

```c
undefined4 __thiscall FUN_004b8ed0(byte *param_1, undefined4 *param_2);
// ABI sealed: ret 4; AL 0/1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.md`
- Annotated: `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004b8ed0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_HostTick_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI ret 4 | **Confirmed** |
| Parameter semantic names | **Probable** |
| Product symbol | **Inferred** |
