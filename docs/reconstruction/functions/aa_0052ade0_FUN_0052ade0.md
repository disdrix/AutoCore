# Function record: FUN_0052ade0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ade0` |
| **Canonical name** | `FUN_0052ade0` |
| **Proposed name** | `CVOGCharacter_SetMissionCounterMax_Inferred` |
| **Address** | `0x0052ade0`–`0x0052ae21` inclusive (**66 B** / `0x42`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` (**mission-adjacent**) |
| **Completion status** | **Dual complete (accept-with-gaps)** — W37-P 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

On character Val12 map @ **`+0x584`**, find by int key; on **hit only**, write **`node+0x10`** to `value` clamped so it does not exceed **`node+0x14`**, then dirty **`char+0x634 |= 0x40`**. **Miss is a no-op** (no insert). Mission-adjacent: same map as Set/Add/Get mission counters; sole CODE caller is debug slash optional "max" path.

## Signature (byte-sealed)

```c
void __thiscall CVOGCharacter_SetMissionCounterMax_Inferred(
    int character /*ECX*/, uint32_t key, int32_t value); /* ret 8 */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.md` (+ W37-P append)
- Annotated: `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetMissionCounterMax_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0052ade0.cpp`
- Dual A/B: `reviews/A|B_aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md`
- Named record: `functions/aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller (1) | `Client_DebugCmd_AddDisciplinePoints` | `0x0094e530` @ `0x0094e5de` |
| Callee | `FUN_00418b80` (map lower_bound) | `0x00418b80` |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI ret 8 + map offsets | **High** |
| Hit-only +0x10 write + clamp to +0x14 | **High** |
| Dirty `+0x634 \|= 0x40` | **High** |
| Name "Max" English | **Inferred** (slash help) |
| Dual-field product policy | **Open** |
| Runtime / differential | **Open** |
