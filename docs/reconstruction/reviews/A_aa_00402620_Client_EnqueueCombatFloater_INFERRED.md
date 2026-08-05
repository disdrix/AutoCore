# Review A (reconstruction fidelity): `aa_00402620` Client_EnqueueCombatFloater_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402620` |
| **VA** | `0x00402620` |
| **Canonical name** | `Client_EnqueueCombatFloater_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00402620_Client_EnqueueCombatFloater_INFERRED.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_EnqueueCombatFloater_INFERRED.cpp` |
| Raw | `docs/reconstruction/raw/aa_00402620_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Append one combat-floater entry to growable vector-like queue. Element size 0x38. Fast path construct-in-place when size<cap; else grow FUN_00402e20. Callers include XP GiveXP path (type CombatFloaterType::XP=3). Name INFERRED; full element layout open.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Queue +0x04 begin / +0x08 end / +0x0C capacity | High | Body |
| Element size 0x38 | High | end += 0x38 |
| Fast path FUN_00404600 when room | High | Body |
| Slow path FUN_00402e20 grow | High | Body |
| XP floater type = 3 at callers | High | AwardKillExperience plate |
| Name/layout INFERRED | Tentative | Plate tag |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if begin && size<cap: construct + bump end; else grow | Yes |

---

## 4. Gaps

1. Full 0x38-byte floater field map.
2. Which queue host pointer AwardKillExperience uses.

**Verdict:** **accept-with-gaps**
