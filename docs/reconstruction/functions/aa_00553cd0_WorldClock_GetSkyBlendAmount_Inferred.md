# Function record: WorldClock_GetSkyBlendAmount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553cd0` |
| **Canonical name** | `WorldClock_GetSkyBlendAmount_Inferred` |
| **Ghidra name** | `FUN_00553cd0` |
| **Address** | `0x00553cd0`–`0x00553cd6` inclusive (**7 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | environment / world clock / sky blend |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-J OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf getter: return `*(float*)(clock+0x15c)` on x87 ST0. Sibling of dualed `WorldClock_GetQuarterPhase01_Inferred` on the same clock host. Sole static consumer is env day-cycle tick `FUN_004912c0`, which applies the value as sky material **`fBlendAmount`** (`FUN_00490af0` / SkyBox family).

## Signature (byte-sealed)

```c
float __fastcall WorldClock_GetSkyBlendAmount_Inferred(void *clock /*ECX*/);
// bare ret; result on x87 ST0 via fld [ecx+0x15c]
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00553cd0_FUN_00553cd0.md`
- Annotated: `docs/reconstruction/raw/aa_00553cd0_FUN_00553cd0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/WorldClock_GetSkyBlendAmount_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00553cd0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_00553cd0_FUN_00553cd0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_004912c0` @ `0x004912e5` | sole; env light/sky day-cycle |
| Callee | *(none)* | pure load |
| Sibling | `WorldClock_GetQuarterPhase01_Inferred` @ `0x00553dd0` | same host; phase math |

## Confidence

| Claim | Level |
|---|---|
| `fld [ecx+0x15c]; ret` body | **Confirmed** |
| Same clock host as quarter-phase getter | **High** |
| Sole env consumer; sky `fBlendAmount` use | **High** (role via caller) |
| Product/PDB English | Open (`_Inferred`) |
| Runtime / image diff | Open |
