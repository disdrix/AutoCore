# Review A (reconstruction fidelity): `aa_004a9750` VehicleEngine_torqueCurve2D

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a9750` |
| **VA** | `0x004a9750` |
| **Canonical name** | `VehicleEngine_torqueCurve2D` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004a9750_VehicleEngine_torqueCurve2D.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

2D byte-indexed torque curve lookup for AA vehicle engine (no stock hkDefaultEngine). Called from `VehicleAction_calcWheelTorque`: `torqueCurve2D(rpm, throttle)` → normalized torque factor **[0..1]**. Layout: **+0x0c** enabled (0 → return **1.0** `DAT_00a0f2a0`); **+0x18** RPM range scale; **+0x10/+0x14** rows/cols; **+0x3dc** byte table; **+0x344** float[8] (index = byte&7; 0 = default/OOR). Bins: `iX = int((rpm - range*0.5) * (1/range))`, same form for throttle axis.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a9750_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004a9750_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEngine_torqueCurve2D.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a9750_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `AA torque curve replaces hk engine` | High | Framework plate |
| `Enabled gate → 1.0` | High | Body |
| `Byte table + float[8] decode` | High | Plate |
| `Caller calcWheelTorque` | High | Xref |
| `Exact bin edge / clamp behavior` | Medium | Boundary residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| disabled → 1.0; else 2D table → float[8] | Yes |
| No invent hk engine path | Yes |

---

## 5. Gaps / open

1. Seal out-of-range bin clamp vs float[0] default.
2. Live-diff torque vs throttle/RPM samples.

**Verdict:** **accept-with-gaps**
