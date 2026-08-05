# Review A (reconstruction fidelity): `aa_0064f510` hkDefaultTransmission_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f510` |
| **VA** | `0x0064f510` |
| **Canonical name** | `hkDefaultTransmission_update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064f510_hkDefaultTransmission_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

WI-MOV-003b/004: transmission child tick. Writes RPM→**+0x18** from wheel+0x8c; torque factor→**+0x1c** = finalDrive*gearRatio*(fw+0x1c+0xc); axle **[+0x20][i]=frac[i]*+0x1c**. Reverse via fw+0x14+0x19. **Does NOT** write wheel+0x20/28. WI-MOV-004: **+0x1c / axle array NOT consumed** by postTickApplyForces or calcWheelTorque (no hkDefaultEngine). ~165-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064f510_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064f510_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultTransmission_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064f510_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `RPM +0x18 / factor +0x1c / axle fracs` | High | Plate |
| `Does not feed postTick drive` | High | WI-MOV-004 |
| `No wheel+0x20/28 writes` | High | Correction |
| `Reverse flag path` | High | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| update rpm/factor/axle; no wheel torque write | Yes |
| No invent engine consumption of +0x1c | Yes |

---

## 5. Gaps / open

1. Document any non-drive consumers of +0x1c (audio/UI).

**Verdict:** accept-with-gaps
