# Review A (reconstruction fidelity): `aa_007cc0d0` Mission_tQuestXPLookup

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc0d0` |
| **VA** | `0x007cc0d0` |
| **Canonical name** | `Mission_tQuestXPLookup` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cc0d0_Mission_tQuestXPLookup.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tQuestXPLookup/row` (mission XPIndex → `rlLevelXP` fraction). Called from `Experience_EnsureQuestXpTableLoaded` as `FUN_007cc0d0`. Same DBReader family as other `//t*` loaders. Required for mission complete XP fraction of level span (docs/XP.md).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cc0d0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007cc0d0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_tQuestXPLookup.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cc0d0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tQuestXPLookup row loader | High | Embedded string |
| EnsureQuestXpTableLoaded callee | High | Caller |
| rlLevelXP fraction semantics | High | XP.md |
| Full column map sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read quest XP rows into map | Yes |

---

## 5. Gaps / open

1. Seal XPIndex key + rlLevelXP float offset.
2. List mission complete consumers.

**Verdict:** **accept-with-gaps**
