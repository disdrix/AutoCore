# Review A (reconstruction fidelity): `aa_00501f60` Vehicle_RecalcCombatPools

| Field | Value |
|---|---|
| **Stable ID** | `aa_00501f60` |
| **VA** | `0x00501f60` |
| **Canonical name** | `Vehicle_RecalcCombatPools` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00501f60_Vehicle_RecalcCombatPools.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Recompute max HP after equip changes. Skip if special flag **+0x2ac**; require owner context **+0xb0**. Dirty **+0x180 |= 0x80**; pre-hooks vfunc **+0x23c/+0x244**; `maxHp = Vehicle_CalcMaxHitPoints(this)`; set max vfunc **+0x248**; scale current HP via vfunc **+0x240**(max×ratio). Optional kill-XP weapon bonus if owner char@**+0xa8** via `CVOGCharacter_WeaponAllowsKillXpBonus`. Callers: `Vehicle_SetEquippedArmor`, `Vehicle_SetEquippedRaceItem`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00501f60_Vehicle_RecalcCombatPools.md` (or `aa_00501f60_FUN_00501f60.md`) |
| Annotated | `docs/reconstruction/raw/aa_00501f60_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_RecalcCombatPools.cpp` |
| Function record | `docs/reconstruction/functions/aa_00501f60_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Skip +0x2ac special` | High | Body |
| `CalcMaxHitPoints then set max` | High | Callee |
| `Dirty +0x180 |= 0x80` | High | Body |
| `Scale current HP with ratio` | High | Plate |
| `Callers armor/race equip` | High | Plate |
| `Exact ratio source ESI` | Medium | INFERRED |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gate special → dirty → calc max → scale current | Yes |
| No invent heat | Yes |

---

## 5. Gaps / open

1. Seal HP ratio source.
2. Whether shield/power also recalc here (name says pools but body HP-focused).

**Verdict:** **accept-with-gaps**
