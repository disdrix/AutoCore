# Function record: Client_Camera_ApplyLookOffset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a5f0` |
| **Canonical name** | `Client_Camera_ApplyLookOffset` |
| **Address** | `0x0091a5f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` (camera / look apply) |
| **Completion status** | **Human-refined dual A/B seal 2026-07-29** — CF High; product names / ESI type residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual review** | A/B `reviews/A_aa_0091a5f0_*` / `reviews/B_aa_0091a5f0_*` — **accept-with-gaps** |

## Alias

| Name | Status |
|------|--------|
| `FUN_0091a5f0` | Ghidra auto / prior scaffold |
| `Named_CalleeOf_Client_Input_DriveControlTick_0091a5f0` | Auto xref seed (superseded) |
| `Client_Camera_ApplyLookOffset` | **Canonical** (this dual) |

## Purpose

Apply **look scale + look vector** from `Client_Input_DriveControlTick` onto the active look-helper object (ESI). When scale ≠ 1.0, derive pitch from object orientation vs world axes and build/apply an orientation update; always classify scale into mode byte `+0x14c`; when look vector xz active (or sticky `+0x304`), compose world offset `pos + R*lookVec` and apply. **Not** a drive-axis writer.

## Signature (decompiler + callers)

```c
// Stack args: lookScale, lookVec*
// ESI: look-helper object* (DCT piStack_a8)
void Client_Camera_ApplyLookOffset(float lookScale, float *lookVec);
```

## Sealed facts (High CF unless noted)

1. **Callers only DCT** — sites `0x0092278b` `(local_d4,&local_d0)` and `0x00922f13` `(1.0,&fStack_a0)`.
2. **Gate** — `ESI != 0 && *(ESI+8) != 0`.
3. **Scale≠1 branch** — rb quat `*( *(ESI+8)+0x3c ) + 0x30`; forward extract `FUN_004e8a40`; pitch = acos(clamp(forward·worldZ)); hemisphere wrap with **2π** if forward·worldX < 0; fold scale about 1.0; acos; half-angle quat via `FUN_00567ce0` (0.5); `FUN_00404dc0`.
4. **Mode byte `ESI+0x14c`** — `< ≈0.99999 → 1`; in deadband → `0`; `> ≈1.00001 → 0xFF`.
5. **Look vector path** — if `lookVec[0]|lookVec[2]` or `ESI+0x304`; type id 6 special active; pos/quat from rb or entity-local fallbacks (`+0xb0/+0x30` vs `+0x84/+0x94`); `FUN_004e8bf0` then `FUN_004c3a40`; zero-xz → scale basis `*0.2` + early return; else sticky `+0x304=1`.
6. **Constants** — see dual A table (`25`, `2π`, `−1`, deadband, `0.2`, half `0.5`).
7. **Separation** — no stores to drive axes `+0x614/+0x618/+0x61c`.

## Gaps

- ESI C++ type; lookVec component names; lookScale product meaning; full `FUN_00567ce0` stack wiring; `DAT_00d09874+0x30` field name; runtime/diff.

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0091a5f0_FUN_0091a5f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0091a5f0_FUN_0091a5f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Camera_ApplyLookOffset.cpp` |
| Scaffold clean (legacy) | `docs/reconstruction/reconstructed-exact/FUN_0091a5f0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0091a5f0_Client_Camera_ApplyLookOffset.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0091a5f0_Client_Camera_ApplyLookOffset.md` |
| Parent system | `docs/reconstruction/systems/input-drive-control.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Callers / non-steer role | **High** |
| Constant values (`read_memory`) | **High** |
| Basis extract roles | **High** (verified siblings) |
| Parameter product names | Probable / Tentative |
| ESI type | Tentative |
| Runtime / bit-exact | Open |
