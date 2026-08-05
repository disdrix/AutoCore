# Review A (reconstruction fidelity): `aa_004da630` CVOGCombat_OnDeathAwardKillXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da630` |
| **VA** | `0x004da630` |
| **Canonical name** | `CVOGCombat_OnDeathAwardKillXp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004da630_CVOGCombat_OnDeathAwardKillXp.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Death/loot handler: resolve killer character, build participation (XPPercent×share×convoy), award kill XP solo or up to 4 in-range convoy members via `CalculateAndAwardKillXP`, then credits/loot side paths when local flag allows. Large multi-phase unit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004da630_CVOGCombat_OnDeathAwardKillXp.md` |
| Annotated | `docs/reconstruction/raw/aa_004da630_CVOGCombat_OnDeathAwardKillXp.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCombat_OnDeathAwardKillXp.cpp` |
| Function record | `docs/reconstruction/functions/aa_004da630_CVOGCombat_OnDeathAwardKillXp.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Early return if killer object null` | **High** | param_2 gate |
| `Template kind 0x0e vehicle / 0x12 creature` | **High** | type switch |
| `Solo path convoyCount=0 when no convoy flag` | **High** | Plate/algorithm |
| `Convoy: distance gate SQRT < DAT_00aaa8a8 (~300f), up to 4 members` | **High** | Loop + constant |
| `Mult uses template XPPercent @+0x500` | **High** | Product into CalculateAndAward |
| `Credits/loot after XP block when +0xf6 clear` | **Probable** | Large tail; many FUN_* |
| `Calls CalculateAndAwardKillXP` | **High** | Central award |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Killer resolve + victim snapshot | **Yes** |
| Type switch + award branches | **Yes** |
| Credits/loot tail present | **Yes** |
| No modernization of loot tables | **Yes** |

---

## 5. Gaps / open

1. Full loot/credit formula FUN_* surface still open.
2. Damage-share computation exact inputs.
3. List path TFID @+0x158 vs convoy flag dual paths.
4. Runtime multi-member convoy capture.

**Verdict:** **accept-with-gaps**
