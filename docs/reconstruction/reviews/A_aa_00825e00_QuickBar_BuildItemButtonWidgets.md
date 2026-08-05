# Review A (reconstruction fidelity): `aa_00825e00` QuickBar_BuildItemButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825e00` |
| **VA** | `0x00825e00` |
| **Canonical name** | `QuickBar_BuildItemButtonWidgets` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00825e00_QuickBar_BuildItemButtonWidgets.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Builds item QuickBar button chrome: bg, icon, keynum, cooldown gauge, click hitbox. Loads XML widgets via vfunc **+0x404**: `i_d_qb_2d_btn_quickbar_bg.xml` @ **+0x540**, icon @ **+0x544**, keynum @ **+0x548**, plus CD gauge path sibling to skill buttons. Increments child counters at **+0x68/+0x70/+0x74**. Sibling of `QuickBar_BuildSkillButtonWidgets` for item slots.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00825e00_QuickBar_BuildItemButtonWidgets.md` (or `aa_00825e00_FUN_00825e00.md`) |
| Annotated | `docs/reconstruction/raw/aa_00825e00_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_BuildItemButtonWidgets.cpp` |
| Function record | `docs/reconstruction/functions/aa_00825e00_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Loads bg/icon/keynum XML widgets` | High | String paths + vfunc+0x404 |
| `Stores at +0x540/+0x544/+0x548` | High | Body |
| `Child count +0x68 pattern` | High | Repeated CF |
| `Item QB chrome only` | High | Name + strings |
| `Full hitbox/gauge attach map` | Medium | Tail residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Init → load widgets → bump counters | Yes |
| No invent inventory transfer | Yes |

---

## 5. Gaps / open

1. Seal remaining widget slots (gauge/hitbox offsets).
2. Diff vs BuildSkillButtonWidgets.

**Verdict:** **accept-with-gaps**
