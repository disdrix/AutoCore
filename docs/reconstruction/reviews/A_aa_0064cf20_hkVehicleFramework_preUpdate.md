# Review A (reconstruction fidelity): `aa_0064cf20` hkVehicleFramework_preUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064cf20` |
| **VA** | `0x0064cf20` |
| **Canonical name** | `hkVehicleFramework_preUpdate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064cf20_hkVehicleFramework_preUpdate.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

WI-MOV-003b: framework **preUpdate** (vtbl+0x14), first child stage inside `tickSubsystems`. Writes per-wheel contact hardpoint vectors at **wheel+0x20..+0x2c** (stride 0xC0, base wheels+0x80). **+0x20/+0x28** contact X/Z used later by calcWheelTorque→torqueCurve2D — **not** throttle/RPM writers. Spin speed at **wheel+0x8c**. ~537-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064cf20_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064cf20_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFramework_preUpdate.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064cf20_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hardpoint write wheel+0x20..+0x2c` | High | WI-MOV-003b |
| `Not throttle/RPM store` | High | Correction note |
| `Spin speed wheel+0x8c` | High | Plate |
| `Runs before component updates` | High | tick order |
| `Full world-transform math seal` | Medium | Body residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| preUpdate: transform hardpoints / spin | Yes |
| No invent throttle write | Yes |

---

## 5. Gaps / open

1. Document exact transform chain from chassis RB.

**Verdict:** accept-with-gaps
