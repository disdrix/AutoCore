# Skeptical / adversarial review: `VehicleEntity_SetLongitudinalInput` @ `0x004f5650`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **Address** | `0x004f5650` |
| **Role** | Adversarial review — attack overclaim, not rubber-stamp |
| **Date** | 2026-07-23 |
| **Verdict** | **Needs-more-evidence** for full package seal; **gate+store shape acceptable** under static evidence |

**Generic approval is insufficient.** Claims must survive attack against the filed raw, sibling SetSteerInput package, and prior verified notes.

## What was inspected

| Source | Role |
|---|---|
| `raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` | Authoritative brief capture |
| `reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp` | Clean port under attack |
| `functions/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` | Record status claims |
| Sibling raw/clean/reviews for `0x004f5620` | Gate identity claim |
| `physics/verified/fn_004f5620_setSteerInput.md` | Shared gate table |

**Not performed:** live Ghidra re-decompile of `0x004f5650`, CE breakpoints, or instruction-size re-measure this session.

## Attacks and outcomes

### A1 — “Identical gate” is assumed from sibling, not re-proven

- **Attack:** Brief raw may have been authored by analogy to SetSteerInput rather than fresh decompile fidelity.
- **Result:** Capture metadata claims paired decompile with `aa_004f5620`; pseudocode shape matches. Accept as **probable**, not **runtime-proven**.
- **Uncertainty remains:** body size `~0x2b` not re-measured.

### A2 — Sign convention is not a body property

- **Attack:** Comments claim Accelerate → `-1.0f`, Reverse → `+1.0f`.
- **Result:** Body only stores the float argument. Sign polarity is **caller-layer**. Any package claiming body-enforced polarity is **false**.

### A3 — `undefined4` cleaned correctly?

- **Attack:** Prefer no Ghidra placeholder types as sole style in clean.
- **Result:** Clean uses `float longitudinalInput` and `float*` store. **Pass** for type hygiene.

### A4 — Suppress mask semantics overclaimed?

- **Attack:** Calling mask “lock” implies proven lock semantics.
- **Result:** Clean plate says suppress mask; per-bit meanings unresolved. Prefer **write-suppress** wording. Same open issues as SetSteerInput (UF-class).

### A5 — Package completeness

- Function record still labels **Partial scaffold** while clean is non-scaffold quality.
- Dual reviews now exist; promote record status only after matrix row update.
- Runtime / differential still **open**.

## Surviving claims

| Claim | Survives? |
|---|---|
| Gated store to `this+0x614` | Yes (static) |
| Gate mask `0xC7` / 199 | Yes (static, shared with sibling) |
| No clamp in body | Yes |
| Full input-drive-control complete | **No** |
| Bit meanings of `0xC7` | **No** |

## Required follow-ups (not optional for “complete”)

1. Runtime: break `0x004f5650`; force wobj flags; observe `+0x614` retain vs write.
2. Re-decompile or instruction confirm body bounds if sealing bit-for-bit later.
3. Update function record + verification matrix when dual-review status is accepted.

## Verdict

Static reconstruction of the longitudinal gated store is **directionally correct** and type-clean. Package is **not** sealed: evidence for full confidence needs runtime and explicit matrix row. Reject LGTM-without-checks.
