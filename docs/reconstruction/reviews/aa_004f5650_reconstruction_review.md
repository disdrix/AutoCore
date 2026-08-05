# Reconstruction review: `aa_004f5650` VehicleEntity_SetLongitudinalInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **Canonical name** | `VehicleEntity_SetLongitudinalInput` |
| **Address** | `0x004f5650` |
| **Reviewer role** | Reconstruction faithfulness (clean C++ vs raw/sibling package) |
| **Date** | 2026-07-23 |
| **Verdict** | **Accept-with-gaps** — gate+store match sibling evidence; runtime/diff open |

## Artifacts inspected

| Artifact | Path |
|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` |
| Annotated | `docs/reconstruction/raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.annotated.md` |
| Exact C++ | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` |
| Sibling unit | `aa_004f5620` SetSteerInput package + reviews |
| Prior verified | `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md` |

## Primary claims checked

1. **Same gate as SetSteerInput** — three-step pointer chain to `wobj`; allow write if `wobj == null` or `(flags_at_+0xb4 & 0xC7) == 0`.
2. **Store target only differs** — clean writes `this+0x614` (f32), not `+0x618`.
3. **No clamps / no extra side effects** in this body.
4. **Types cleaned** — clean uses `float` / `uint8_t` mask, not raw `undefined4` as sole type style.

## Evidence summary

- Raw pseudocode stores `*(undefined4*)(param_1 + 0x614) = param_2` under the same `iVar1 == 0 || (byte & 199) == 0` condition as SetSteerInput.
- Clean maps `199` → `kInputAxisSuppressMask = 0xC7u` and store offset `kOffLongitudinalInput = 0x614`.
- Pointer chain layout matches the reviewed SetSteerInput clean (`+4`, `+4`, entity-relative `+0xb0`).
- DriveControlTick caller contract (Accelerate → `-1.0f`, Reverse → `+1.0f`) is plate/comment only; not enforced in body — correct.

## Gaps / uncertainty

| Item | Status |
|---|---|
| Runtime observation of suppress bits | Open |
| Differential vs retail EXE | Deferred |
| Per-bit meaning of `0xC7` | Unresolved (shared with SetSteerInput) |
| Function record still says partial scaffold | Should be promoted after dual review acceptance |

## Verdict rationale

Clean is a faithful, non-scaffold rewrite of the gated longitudinal store. Accept for static gate+store claims only. Do not claim full system completeness for input-drive-control.

## Related

Cross-check: `reviews/aa_004f5620_reconstruction_review.md` (same gate, different store).
