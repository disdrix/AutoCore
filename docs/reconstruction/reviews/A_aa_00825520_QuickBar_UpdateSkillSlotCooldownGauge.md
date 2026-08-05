# Review A (reconstruction fidelity): `aa_00825520` QuickBar_UpdateSkillSlotCooldownGauge

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825520` |
| **VA** | `0x00825520` |
| **Canonical name** | `QuickBar_UpdateSkillSlotCooldownGauge` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00825520_QuickBar_UpdateSkillSlotCooldownGauge.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Update quickbar skill button cooldown gauge UI. Early-out if global `DAT_00d1b6d8` null or both **`+0x6b8/+0x6b9`** clear; requires **`button+0x550`** skill binding. If **`skill+0x628`** (casting/charge path): gauge from skill **`+0x178/+0x14/+0x10`** floats; else `Skill_GetCategoryCooldownRemaining(skill+0x5e8)`. Drives `i_d_qb_2d_btn_quickbar_cooldown.xml`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00825520_QuickBar_UpdateSkillSlotCooldownGauge.md` (or `aa_00825520_FUN_00825520.md`) |
| Annotated | `docs/reconstruction/raw/aa_00825520_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_UpdateSkillSlotCooldownGauge.cpp` |
| Function record | `docs/reconstruction/functions/aa_00825520_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `button+0x550 skill binding required` | High | Plate |
| `skill+0x628 selects charge path` | High | Plate |
| `Charge fields +0x178/+0x14/+0x10` | High | Plate |
| `Else category CD via +0x5e8` | High | Callee |
| `Cooldown XML asset` | High | String |
| `Global DAT gate` | Medium | DAT_00d1b6d8 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gates → pick CD source → set gauge | Yes |
| No cast request | Yes |

---

## 5. Gaps / open

1. Exact gauge fill formula 0..1.
2. DAT_00d1b6d8 identity.

**Verdict:** **accept-with-gaps**
