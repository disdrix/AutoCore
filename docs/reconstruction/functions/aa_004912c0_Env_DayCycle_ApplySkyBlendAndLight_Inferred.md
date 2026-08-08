# Function record: Env_DayCycle_ApplySkyBlendAndLight_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004912c0` |
| **Canonical name** | `Env_DayCycle_ApplySkyBlendAndLight_Inferred` |
| **Ghidra symbol** | `FUN_004912c0` |
| **Address** | `0x004912c0`–`0x0049146a` exclusive (**426 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | environment / sky / day-cycle |
| **Completion status** | **Dual sealed (WQ9G-F)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Env-host day-cycle consumer of dualed world-clock leaves: load stored sky blend (`+0x15c`), remap quarter phase by mode (`+0x154`) into a day-phase scalar for light helpers, and when dirty push `fBlendAmount` into SkyBox material family (optional texture commit when blend ≥ 1).

## Signature

```c
void __thiscall Env_DayCycle_ApplySkyBlendAndLight_Inferred(void *env /*ECX*/, float dt /*stack, unread*/);
// ret 4
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.md`
- Annotated: `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Env_DayCycle_ApplySkyBlendAndLight_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004912c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_004912c0_FUN_004912c0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (1) | `FUN_00942e20` @ `0x00942e75` | frame tick; ECX = env; pushes float dt |
| Callee | `WorldClock_GetSkyBlendAmount_Inferred` (`0x00553cd0`) | dualed WQ9F-J |
| Callee | `WorldClock_GetQuarterPhase01_Inferred` (`0x00553dd0`) | dualed |
| Callee | `FUN_00490af0` | sky `fBlendAmount` apply |
| Callee | `FUN_00490820` | sky DiffuseTexture when blend ≥ 1 |
| Callee | `FUN_0079a110`, `FUN_0074e690`, `FUN_0074e910` | light curve (undualed) |

## Confidence

| Claim | Level |
|---|---|
| Body size + `ret 4` + ECX=env | **Confirmed** (bytes) |
| Consumes dualed clock getters; sky blend → materials | **Confirmed** / **High** |
| Mode 0..3 day-phase remap with 1/3 and 2/3 | **Confirmed** (bytes + CF) |
| Product env class English | **Tentative** (`_Inferred`) |
| Stack dt meaning | **Tentative** (unread) |
