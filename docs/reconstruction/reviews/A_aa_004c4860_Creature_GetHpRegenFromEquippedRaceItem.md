# Review A (reconstruction fidelity): `aa_004c4860` Creature_GetHpRegenFromEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4860` |
| **VA** | `0x004c4860` |
| **Canonical name** | `Creature_GetHpRegenFromEquippedRaceItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c4860_Creature_GetHpRegenFromEquippedRaceItem.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin creature-side HP regen glue for combat-pool owner path: if creature has vehicle at **+0x250**, `return Vehicle_GetHpRegenRate(vehicle)`; else return **1**. Does not walk race-item itself — full formula is vehicle-side. Used by `VehicleCombatPool_OnTick` for owner-creature HP regen.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4860_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4860_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Creature_GetHpRegenFromEquippedRaceItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c4860_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vehicle ptr creature+0x250` | High | Clean body |
| `Delegates to Vehicle_GetHpRegenRate` | High | Direct call |
| `No vehicle → 1` | High | Body |
| `Does not reimplement dual-base walk` | High | Glue only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| vehicle? GetHpRegenRate(veh) : 1 | Yes |
| No invent race walk | Yes |

---

## 5. Gaps / open

1. Confirm all OnTick paths use creature glue vs direct vehicle call.
2. NPC / no-owner vehicle regen path.

**Verdict:** **accept**
