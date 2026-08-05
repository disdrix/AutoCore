# Review A (reconstruction fidelity): `aa_007cc470` LoadQuestCreditsLookupFromWad

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc470` |
| **VA** | `0x007cc470` |
| **Canonical name** | `LoadQuestCreditsLookupFromWad` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cc470_LoadQuestCreditsLookupFromWad.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Parse `//tQuestCreditsLookup/row` from wad.xml into credits-index lookup table. Columns: **IDQuestCreditsIndex**, **rlLevelCredits**. Retail curve comment: index 0→0, 1→0.2 … 5→1.0 … 10→2.0. Feeds `Mission_ComputeObjectiveCredits` scaler path (CreditsIndex on mission). Data load at boot/init — not per-objective math.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cc470_LoadQuestCreditsLookupFromWad.md` (or `aa_007cc470_FUN_007cc470.md`) |
| Annotated | `docs/reconstruction/raw/aa_007cc470_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LoadQuestCreditsLookupFromWad.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cc470_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `WAD path tQuestCreditsLookup/row` | High | Plate string/xpath |
| `Columns index + rlLevelCredits` | High | Plate |
| `Retail sample curve 0..10` | High | Plate comment |
| `Pairs ComputeObjectiveCredits` | High | Mission credits system |
| `MSXML/COM residual types` | Medium | IUnknown locals |
| `Full row count / clamp` | Medium | Body large COM |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Open wad rows → fill lookup | Yes |
| No runtime award | Yes |

---

## 5. Gaps / open

1. Exact in-memory table address/layout.
2. Whether server loads same wad table.

**Verdict:** **accept-with-gaps**
