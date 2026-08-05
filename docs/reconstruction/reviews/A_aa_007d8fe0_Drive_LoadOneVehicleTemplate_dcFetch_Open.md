# Review A (reconstruction fidelity): `aa_007d8fe0` Drive_LoadOneVehicleTemplate_dcFetch_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007d8fe0` |
| **VA** | `0x007d8fe0` |
| **Canonical name** | `Drive_LoadOneVehicleTemplate_dcFetch_Open` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007d8fe0_Drive_LoadOneVehicleTemplate_dcFetch_Open.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB/WAD fetch-open path for loading one vehicle template (`LoadOneVehicleTemplate::dcFetch::Open` string). Opens reader, pulls template columns via repeated `FUN_004231d0` field gets, copies names (`wcscpy`), touches weapon-group load (`FUN_0041a3e0` / Inv_DbLoadWeaponGroups family). Client/data load — not live drive tick.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007d8fe0_Drive_LoadOneVehicleTemplate_dcFetch_Open.md` (or `aa_007d8fe0_FUN_007d8fe0.md`) |
| Annotated | `docs/reconstruction/raw/aa_007d8fe0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_LoadOneVehicleTemplate_dcFetch_Open.cpp` |
| Function record | `docs/reconstruction/functions/aa_007d8fe0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String LoadOneVehicleTemplate::dcFetch::Open` | High | Evidence |
| `DBReader log format` | High | String |
| `Many column fetch callees` | High | FUN_004231d0×N |
| `Weapon group related load` | High | FUN_0041a3e0 |
| `Not thr/steer writer` | High | Data load |
| `Full column map` | Low | Opaque helpers |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Open → fetch columns → fill template | Yes |
| No invented physics | Yes |

---

## 5. Gaps / open

1. Full vehicle template field schema.
2. Server vs client who loads templates.

**Verdict:** **accept-with-gaps**
