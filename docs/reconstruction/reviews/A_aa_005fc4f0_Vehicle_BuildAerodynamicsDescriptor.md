# Review A (reconstruction fidelity): `aa_005fc4f0` Vehicle_BuildAerodynamicsDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc4f0` |
| **VA** | `0x005fc4f0` |
| **Canonical name** | `Vehicle_BuildAerodynamicsDescriptor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fc4f0_Vehicle_BuildAerodynamicsDescriptor.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill aerodynamics descriptor (6 floats) for `hkDefaultAerodynamics_ctor` (size **0x50**). Copies clonebase fields **+0x5a8, +0x59c, +0x5a0, +0x5a4, +0x5ac, +0x5b0, +0x5b4** via standard clonebase path `*( *( *( *(veh+4)+4 ) +0xac + veh ) +0x3c )`. Thin linear copy — no branches. Called from `buildHavokVehicleFramework` step 8.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fc4f0_Vehicle_BuildAerodynamicsDescriptor.md` (or `aa_005fc4f0_FUN_005fc4f0.md`) |
| Annotated | `docs/reconstruction/raw/aa_005fc4f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_BuildAerodynamicsDescriptor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fc4f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Copies 6 aero floats from clonebase` | High | Body |
| `Offsets 0x59c..0x5b4 family` | High | Body |
| `Feeds hkDefaultAerodynamics 0x50` | High | Framework plate |
| `No CF branches` | High | Body if×0 |
| `Semantic names of each float` | Medium | Unlabeled |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Resolve clonebase → copy 6 dwords → return | Yes |
| No invented suspension | Yes |

---

## 5. Gaps / open

1. Name each aero coefficient (drag/lift/…).
2. Confirm 6 vs 7 field count (plate says 6 floats in ctor notes).

**Verdict:** **accept-with-gaps**
