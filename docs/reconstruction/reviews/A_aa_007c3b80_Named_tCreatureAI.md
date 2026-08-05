# Review A (reconstruction fidelity): `aa_007c3b80` Named_tCreatureAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c3b80` |
| **VA** | `0x007c3b80` |
| **Canonical name** | `Named_tCreatureAI` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c3b80_Named_tCreatureAI.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB table loader **`tCreatureAI`**. Loads creature AI definition rows (behavior params for HBAI pursue/attack). Feeds `CVOGHBAICreatureBase_DoCreaturePursue` and related AI. Combat AI data plane — not the pursue method itself.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c3b80_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007c3b80_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_tCreatureAI.cpp` |
| Function record | `docs/reconstruction/functions/aa_007c3b80_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tCreatureAI table loader | High | Name |
| DBReader family | High | Callees |
| AI param column map | Medium | 626-line residual |
| Link to HBAI runtime | Medium | Inferred |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → read AI rows → store → close | Yes |

---

## 5. Gaps / open

1. Map AI columns to DoCreaturePursue thresholds.

**Verdict:** **accept-with-gaps**
