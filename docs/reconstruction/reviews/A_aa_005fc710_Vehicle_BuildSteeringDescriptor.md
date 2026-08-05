# Review A (reconstruction fidelity): `aa_005fc710` Vehicle_BuildSteeringDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc710` |
| **VA** | `0x005fc710` |
| **Canonical name** | `Vehicle_BuildSteeringDescriptor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fc710_Vehicle_BuildSteeringDescriptor.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill steering descriptor for Tank/Default steering ctors. Output layout: **+0x00** u8 wheel count (`FUN_004f5560`); **+0x04** maxSteerA = clonebase+**0x594** × entity+**0x208**; **+0x08** maxSteerB = clonebase+**0x598** × entity+**0x20c**; **+0x0c** per-wheel flag array (`FUN_005b3300`); **+0x10** length; **+0x14** capacity. Per-wheel flag: if i < tankSteerCount@chassis+**0x4cc** then `(clonebase+0x5f0>>2)&1` else `(>>3)&1`. Chassis secondary at vehicle+**0x258**. Clonebase path via nested `+4/+4/+0xac/+0x3c`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fc710_Vehicle_BuildSteeringDescriptor.md` (or `aa_005fc710_FUN_005fc710.md`) |
| Annotated | `docs/reconstruction/raw/aa_005fc710_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_BuildSteeringDescriptor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fc710_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `maxSteerA/B from cb+0x594/598 × entity+0x208/20c` | High | Plate VERIFIED |
| `Per-wheel flag from +0x5f0 bits 2/3` | High | Plate |
| `tankSteerCount chassis+0x4cc` | High | Plate |
| `Output layout +0x00..+0x14` | High | Plate |
| `Called from buildHavokVehicleFramework` | High | Call graph |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Wheel count → grow flags → write max angles | Yes |
| No invented thr | Yes |

---

## 5. Gaps / open

1. Confirm tankSteerCount source object always +0x258.
2. Document maxSteerA vs B semantic (front/rear?).

**Verdict:** **accept-with-gaps**
