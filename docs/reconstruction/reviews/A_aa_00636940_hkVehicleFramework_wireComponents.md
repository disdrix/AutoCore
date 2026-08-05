# Review A (reconstruction fidelity): `aa_00636940` hkVehicleFramework_wireComponents

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636940` |
| **VA** | `0x00636940` |
| **Canonical name** | `hkVehicleFramework_wireComponents` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00636940_hkVehicleFramework_wireComponents.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Copies component pointers from setup descriptor into framework slots and sets each ticked component's backpointer **+8** → framework. Slot map: **fw+0x0c**=wheels (desc[1]), **+0x10**=desc[0], **+0x14** steer, **+0x18** wheelCollide, **+0x1c** transmission, **+0x20** brake, **+0x24** suspension, **+0x28** aero, **+0x2c**/+0x30 further (AVD/order note: desc[7]/[8] swap in copy). Used after buildHavokVehicleFramework assembly. No engine slot (AA uses calcWheelTorque). ~107-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636940_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00636940_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFramework_wireComponents.cpp` |
| Function record | `docs/reconstruction/functions/aa_00636940_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Pointer copy + backptr +8` | High | Body |
| `Wheels at fw+0x0c` | High | WI-MOV notes |
| `No hkDefaultEngine slot` | High | Architecture |
| `Exact desc index ↔ slot table complete` | Medium | AVD order residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| copy slots; wire backptrs | Yes |
| No invent engine component | Yes |

---

## 5. Gaps / open

1. Publish final desc[i] table vs buildHavok order.

**Verdict:** accept-with-gaps
