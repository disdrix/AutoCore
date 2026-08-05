# Review A (reconstruction fidelity): `aa_004fb600` Vehicle_GetShieldRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb600` |
| **VA** | `0x004fb600` |
| **Canonical name** | `Vehicle_GetShieldRegenRate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fb600_Vehicle_GetShieldRegenRate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin combat-pool getter: race-item shield regen rate (points per pulse after empty-shield debounce). Same dual-base walk as `GetHpRegenRate` but returns **short @ sub+0x4B6**. Null race-item at vehicle **+0x270** → **0**. Used by combat-pool OnTick after shield-empty debounce arm.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fb600_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004fb600_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_GetShieldRegenRate.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fb600_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Shield regen short +0x4B6` | High | Clean + combat-pool map |
| `Same +0x270 race-item / dual-base walk as HP` | High | Body twin |
| `Null → 0` | High | Early out |
| `No plant path` | High | No pPowerPlant read |
| `Debounce is caller-side` | High | OnTick owns debounce |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null → 0; else short@+0x4B6 | Yes |
| Twin of GetHpRegenRate walk | Yes |

---

## 5. Gaps / open

1. Name race-item shield field in type plate.
2. Document empty-shield debounce vs this getter.

**Verdict:** **accept**
