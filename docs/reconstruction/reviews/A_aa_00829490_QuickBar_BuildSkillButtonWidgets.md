# Review A (reconstruction fidelity): `aa_00829490` QuickBar_BuildSkillButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829490` |
| **VA** | `0x00829490` |
| **Canonical name** | `QuickBar_BuildSkillButtonWidgets` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00829490_QuickBar_BuildSkillButtonWidgets.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct skill quickbar button child widgets: background, icon, name, value, keynum, cooldown gauge (`i_d_qb_2d_btn_quickbar_cooldown.xml`), activate FX. Each child: parent vtable **`+0xa8`** attach, **`+0x28`** load XML, store ptrs at button **`+0x560/+0x564/…`**; Z-order via **`+0x68`** child count and **`+0x74`** depth. Pairs UpdateSkillSlotCooldownGauge.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00829490_QuickBar_BuildSkillButtonWidgets.md` (or `aa_00829490_FUN_00829490.md`) |
| Annotated | `docs/reconstruction/raw/aa_00829490_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_BuildSkillButtonWidgets.cpp` |
| Function record | `docs/reconstruction/functions/aa_00829490_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Child set bg/icon/name/value/keynum/cd/FX` | High | Plate |
| `Cooldown XML path` | High | String |
| `Ptrs at button+0x560 family` | High | Plate |
| `UI construct only` | High | No cast |
| `Full offset table all children` | Medium | Partial |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Allocate/load children → attach → store | Yes |
| No category CD insert | Yes |

---

## 5. Gaps / open

1. Complete child pointer offset map.
2. Rebuild vs refresh rules.

**Verdict:** **accept-with-gaps**
