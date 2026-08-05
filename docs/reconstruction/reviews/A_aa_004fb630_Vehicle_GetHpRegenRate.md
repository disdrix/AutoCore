# Review A (reconstruction fidelity): `aa_004fb630` Vehicle_GetHpRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb630` |
| **VA** | `0x004fb630` |
| **Canonical name** | `Vehicle_GetHpRegenRate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fb630_Vehicle_GetHpRegenRate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin combat-pool getter: return equipped race-item HP regen rate (points per pool pulse) for `CVOGHBRegeneration_OnHeartBeat` / `VehicleCombatPool_OnTick`. Walk: vehicle **+0x270** race-item* → dual-base offset via vtbl→clonebase **+0xAC** → subrecord **+0x3C** → **short @ +0x3FA**. Null race-item → **0**. Sibling `Vehicle_GetShieldRegenRate` uses short **+0x4B6**. Creature path: `Creature_GetHpRegenFromEquippedRaceItem` delegates here when creature **+0x250** vehicle present.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fb630_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004fb630_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_GetHpRegenRate.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fb630_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `HP regen from race-item short +0x3FA` | High | Clean + combat-pool map |
| `Race item pointer vehicle+0x270` | High | Plate + clean |
| `Dual-base walk race→clonebase+0xAC→sub+0x3C` | High | Body |
| `Null race-item returns 0` | High | Early out |
| `Sibling shield uses +0x4B6` | High | Paired clean |
| `Exact dual-base RTTI/offset identity` | Medium | Inferred dual-base walk |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null race → 0; else short@sub+0x3FA | Yes |
| No invented plant / armor terms | Yes |

---

## 5. Gaps / open

1. Seal dual-base field names in type plate.
2. Live-diff race-item table values vs UI regen display scale.

**Verdict:** **accept**
