# Review A (reconstruction fidelity): `aa_00827ab0` QuickBar_UpdateSlotCooldownOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00827ab0` |
| **VA** | `0x00827ab0` |
| **Canonical name** | `QuickBar_UpdateSlotCooldownOverlay` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00827ab0_QuickBar_UpdateSlotCooldownOverlay.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-frame/cooldown overlay update for QuickBar buttons. Branch on slot type at **button+0x548**: **type=2 item** looks up inventory via `FUN_005710c0` (cargo grid path through character+**0x250**→vehicle+**0x2b0**); **type=1 skill** uses skill ptr at **+0x558**. Same charge vs category-cooldown split as `QuickBar_UpdateSkillSlotCooldownGauge` (skill+**0x628** charge, `Skill_GetCategoryCooldownRemaining`, `Vehicle_GetSkillCooldownModifier`). Clears overlay when no target (`+0x50c←+0x508`, `+0x4fe=0`). Requires gauge widget **+0x570** non-null.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00827ab0_QuickBar_UpdateSlotCooldownOverlay.md` (or `aa_00827ab0_FUN_00827ab0.md`) |
| Annotated | `docs/reconstruction/raw/aa_00827ab0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_UpdateSlotCooldownOverlay.cpp` |
| Function record | `docs/reconstruction/functions/aa_00827ab0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `type 1 skill / 2 item branch at +0x548` | High | Plate + body |
| `Item path cargo lookup FUN_005710c0` | High | Body |
| `Skill path uses +0x558` | High | Body |
| `Shares CD math with UpdateSkillSlotCooldownGauge` | High | Plate + callees |
| `Requires +0x570 gauge widget` | High | Early return |
| `Exact gauge lerp fields` | Medium | UI residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gate widget → type branch → remaining → overlay | Yes |
| No invent cast | Yes |

---

## 5. Gaps / open

1. Seal item inventory CD field offsets.
2. Document charge vs category precedence for items.

**Verdict:** **accept-with-gaps**
