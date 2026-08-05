# Review A (reconstruction fidelity): `aa_004d7640` CVOGObject_EvalInteractStateFromChildren

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d7640` |
| **VA** | `0x004d7640` |
| **Canonical name** | `CVOGObject_EvalInteractStateFromChildren` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d7640_CVOGObject_EvalInteractStateFromChildren.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Aggregate NPC interact state from child dialog/give-mission reaction entries (object type must be **0x12**). Child types include GiveMission 0x1e (state 6/7), active objective 0x1f (state 4), deliver/use 0x25; picks highest priority (complete=8 wins).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d7640_CVOGObject_EvalInteractStateFromChildren.md` |
| Annotated | `docs/reconstruction/raw/aa_004d7640_CVOGObject_EvalInteractStateFromChildren.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalInteractStateFromChildren.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d7640_CVOGObject_EvalInteractStateFromChildren.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Non-type-0x12 returns 1 early` | **High** | Body |
| `Walks child list; type byte @ child+0x1d1` | **High** | Body |
| `GiveMission 0x1e → states 6/7 via completion checks` | **High** | Body start of loop |
| `Priority aggregation (complete 8 wins)` | **Probable** | Plate + loop structure |
| `Exception/SEH frame present` | **High** | Decomp artifact |
| `Register residuals unaff_EBP/ESI` | **Tentative** | Decomp noise |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Type gate + child walk + type switches | **Yes** |
| Full priority matrix | **Open — large body** |

---

## 5. Gaps / open

1. Full state priority table not line-sealed in this review.
2. Helper FUN_ offsets open.

**Verdict:** **accept-with-gaps**
