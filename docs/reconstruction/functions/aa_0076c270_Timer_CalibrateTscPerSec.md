# Function record: Timer_CalibrateTscPerSec

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c270` |
| **Canonical name** | `Timer_CalibrateTscPerSec` |
| **Prior / Ghidra name** | `FUN_0076c270` |
| **Address** | `0x0076c270`–`0x0076c322` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `timer` / util (cross-cutting) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W18-N OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0076c270`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_assManager_0076c270`
- Sibling timer leaf name family: `Timer_GetTimeSeconds_Rdtsc` (`aa_0076c330`)

## Purpose

One-shot **TSC frequency calibration**:

1. Sample `QueryPerformanceFrequency` and start QPC + `rdtsc`.
2. Spin until QPC advances by `freq >> 4` (~1/16 second), re-sampling `rdtsc`.
3. Compute `scale = (Δtsc * freq) / Δqpc` (64-bit via `__allmul` / `__aulldiv`).
4. Store scale to `DAT_00d1a538:DAT_00d1a53c`; set ready flag `DAT_00d1a530 = 1`.

Downstream `Timer_GetTimeSeconds_Rdtsc` divides later `rdtsc` values by this scale to yield seconds.

## Signature (sealed)

```c
// Nullary; plain RET; void return (globals only)
void Timer_CalibrateTscPerSec(void);
```

## Globals

| VA | Type | Role |
|---|---|---|
| `0x00d1a530` | u8 | ready flag (0 = need calibrate) |
| `0x00d1a538` | u32 | scale lo (TSC ticks / sec) |
| `0x00d1a53c` | u32 | scale hi |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076c270_FUN_0076c270.md` |
| Annotated | `docs/reconstruction/raw/aa_0076c270_FUN_0076c270.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Timer_CalibrateTscPerSec.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_0076c270.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Function alias | `docs/reconstruction/functions/aa_0076c270_FUN_0076c270.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `QueryPerformanceFrequency` | IAT `[0x009c61b4]` |
| Callee | `QueryPerformanceCounter` | IAT `[0x009c61b0]` |
| Callee | `rdtsc` | intrinsic |
| Callee | `__allmul` | `0x006a3fb0` |
| Callee | `__aulldiv` | `0x009a0370` |
| Caller | `Timer_GetTimeSeconds_Rdtsc` / `FUN_0076c330` | call @ `0x0076c33c` when flag==0 |
| Caller | `FUN_0076c500` | call @ `0x0076c52f` when flag==0 |

## Confidence

| Claim | Level |
|---|---|
| CF: QPF → QPC+rdtsc → spin ~1/16s → mul/div → store scale+flag | **High** |
| Nullary plain RET | **High** |
| scale = TSC Hz | **High** |
| Wait = freq>>4 QPC ticks | **High** |
| Product English name | **Probable** |
| Thread-safe init | **Open** (no lock) |
| Runtime / bit-exact | **Open** |
