# Review A (reconstruction fidelity): `aa_007cc810` LoadQuestBaseCreditsFromWad

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc810` |
| **VA** | `0x007cc810` |
| **Canonical name** | `LoadQuestBaseCreditsFromWad` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cc810_LoadQuestBaseCreditsFromWad.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sibling wad loader for quest **base credits** table (level→base credit amounts). Pairs `LoadQuestCreditsLookupFromWad` (index scaler) and `Mission_ComputeObjectiveCredits` (`ceil(scaler * frac * base)`). Boot/data path; COM/MSXML style similar to lookup loader.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cc810_LoadQuestBaseCreditsFromWad.md` (or `aa_007cc810_FUN_007cc810.md`) |
| Annotated | `docs/reconstruction/raw/aa_007cc810_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LoadQuestBaseCreditsFromWad.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cc810_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Base credits wad load` | High | Name + system |
| `Pairs credits lookup + ComputeObjectiveCredits` | High | Mission credit pipeline |
| `Not per-turn-in award` | High | Loader only |
| `Full schema/xpath sealed` | Medium | Less plate detail than lookup |
| `COM residual` | Medium | Same pattern |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Parse wad → base credit table | Yes |
| No char +0x720 add | Yes |

---

## 5. Gaps / open

1. Exact xpath/table name in wad.
2. Level key vs other index.

**Verdict:** **accept-with-gaps**
