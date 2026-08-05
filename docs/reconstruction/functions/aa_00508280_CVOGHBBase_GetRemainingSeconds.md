# Function record: CVOGHBBase_GetRemainingSeconds

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508280` |
| **Canonical name** | `CVOGHBBase_GetRemainingSeconds` |
| **Address** | `0x00508280` |
| **Body range** | `0x00508280`–`0x005082b5` (54 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-actions |
| **Completion status** | **Sealed** — dual A/B accept; body/offsets/constants High (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Return **float seconds** remaining until next heartbeat fire for UI tooltips / overlays / client readiness. Pure read of HB timing fields + client tick; no schedule mutation.

## Signature (machine-sealed)

```c
float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *this); /* ECX=this, ST0=seconds */
```

### Formula

```
base  = max(0, *(this+0x14) - g_dwClientTickMs + *(this+0x08))
remMs = (*(this+0x10) - 1) * *(this+0x08) + base
return signed_int_to_float(remMs) * 0.001f
```

### Field binds

| Off | Name | Role in this fn |
|---|---|---|
| +0x08 | `nPeriodMs` | real period (ms) |
| +0x10 | `nPeriodCounter` | multi-period residual |
| +0x14 | `dwLastFireTickMs` | last fire tick |
| *(not read)* +0x0C | `nPeriodSentinel` | SetPeriodAndCounter / Reschedule domain |

### Globals

| VA | Name | Value |
|---|---|---|
| `0x00b041cc` | `g_dwClientTickMs` | client tick ms |
| `0x00aaa5dc` | `_DAT_00aaa5dc` | `2^32` float |
| `0x00a0f72c` | `g_flMsToSeconds_Inferred` | `0.001f` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00508280_CVOGHBBase_GetRemainingSeconds.md`
- Annotated: `docs/reconstruction/raw/aa_00508280_CVOGHBBase_GetRemainingSeconds.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_GetRemainingSeconds.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00508280_CVOGHBBase_GetRemainingSeconds.md`
- Review B: `docs/reconstruction/reviews/B_aa_00508280_CVOGHBBase_GetRemainingSeconds.md`

## Callers / callees

- **Callees:** none (leaf)
- **Callers (named):** `FUN_00578550`, `FUN_005b2830`, `FUN_00618180`, `FUN_00618bf0`, `FUN_00625b00`, `FUN_0083b920`, `FUN_00955eb0` (+ additional CALL sites; 15 total xrefs)

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes | **High** |
| Field offsets +0x08/+0x10/+0x14 | **High** |
| Constants 0.001 / 2^32 | **High** |
| UI-only / non-schedule authority | **High** |
| Full caller semantic names | Probable / partial |
