# Review A (reconstruction fidelity): `aa_0064bc70` hkVehicleFramework_postTickApplyForces

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064bc70` |
| **VA** | `0x0064bc70` |
| **Canonical name** | `hkVehicleFramework_postTickApplyForces` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064bc70_hkVehicleFramework_postTickApplyForces.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

WI-MOV-004: framework **postTick** (vtbl+0x18 from tickSubsystems). Applies **drive impulse from wheels+0x28[i]** (calcWheelTorque outputs), **not** transmission **+0x1c**. `this=hkVehicleFramework`; arg dt vec. Per wheel (fw+0xc wheels, stride 0xC0 @ +0x80): force along contact normal (fw+0x28)+0x34[i]*dt*wheel dirs → chassis RB vtbl; longitudinal drive from wheel torque slot; friction solver path. ~1013-line clean — largest framework tick body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064bc70_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064bc70_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFramework_postTickApplyForces.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064bc70_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Drive impulse from wheel+0x28 not transm+0x1c` | High | WI-MOV-004 |
| `Called as postTick after children` | High | tickSubsystems order |
| `Per-wheel stride 0xC0` | High | Body |
| `Full friction integration bit-exact` | Medium | Huge residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| per-wheel normal force + drive impulse → RB | Yes |
| No invent transm torque as drive source | Yes |

---

## 5. Gaps / open

1. Seal RB vtbl force/impulse slots.
2. Split friction vs drive sub-blocks for readability.

**Verdict:** accept-with-gaps
