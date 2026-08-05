# Review A (reconstruction fidelity): `aa_005f7360` VehicleNet_PostCorrectionEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f7360` |
| **VA** | `0x005f7360` |
| **Canonical name** | `VehicleNet_PostCorrectionEvent` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005f7360_VehicleNet_PostCorrectionEvent.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Ghost hardpoint / equip correction synthesizer called from `VehicleNet_UnpackGhostVehicle` on **delta** hardpoint paths when owner unhappy (`+0x103==0` gate on related object). Builds deferred event blobs and enqueues via `FUN_005b2d70` + spatial `FUN_005a0b30` — does **not** equip wheels same-call. Primary path: `malloc(0x40)` blob with opcode **0x203C** (equip-shaped), fills TFID/slots from param object + ghost `+0x50` spatial words **+0x160..+0x16c**, pushes queue; alternate path `malloc(0x30)` opcode **0x203E**. Object init stamps many -1 sentinels and float 1.0. Pairs TriggerReplay / ReconcilePrediction family. ~411-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f7360_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005f7360_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleNet_PostCorrectionEvent.cpp` |
| Function record | `docs/reconstruction/functions/aa_005f7360_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Synthesizes 0x203C (0x40) / 0x203E (0x30) deferred blobs` | High | Clean body |
| `Enqueue via FUN_005b2d70 + FUN_005a0b30` | High | Body |
| `Not same-call SetWheelset / equip` | High | OWNER_WHEEL_RACE_RE |
| `Gate on related +0x103 / vtbl probe via +0x50` | High | Body head |
| `Full param_2/3 semantic field names` | Medium | Residual widths |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| unhappy → build blob → push → spatial → return | Yes |
| No invent immediate EquipFromCreate | Yes |

---

## 5. Gaps / open

1. Name 0x203C/0x203E consumer handlers fully.
2. Seal equip vs unequip discrimination on param_3 flags.

**Verdict:** accept-with-gaps
