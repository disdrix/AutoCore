# Review A (reconstruction fidelity): `aa_005127f0` Experience_EnsureQuestXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005127f0` |
| **VA** | `0x005127f0` |
| **Canonical name** | `Experience_EnsureQuestXpTableLoaded_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005127f0_Experience_EnsureQuestXpTableLoaded_INFERRED.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

INFERRED **lazy loader** for `tQuestXPLookup` map (`g_pQuestXpLookupMap_INFERRED`) used by mission XP fraction lookups. Sequence: `FUN_007e1d80` → `FUN_007cc0d0(&map)` (plate `Mission_tQuestXPLookup` / `//tQuestXPLookup/row`) → `FUN_007b7df0`; fail → `VOG_DEBUG_STOP`. Third twin of the XP Ensure family.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005127f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005127f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_EnsureQuestXpTableLoaded_INFERRED.cpp` |
| Function record | `docs/reconstruction/functions/aa_005127f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls FUN_007cc0d0 quest XP loader | High | Clean |
| Quest XP map global | High | Clean arg |
| Same ensure pattern as level/creature | High | Family |
| Ready-flag write site | Medium | Not in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bookend → load quest map → bookend → optional stop | Yes |

---

## 5. Gaps / open

1. Find call sites that consume tQuestXPLookup (mission complete XP).
2. Seal rlLevelXP field offset in map rows.

**Verdict:** **accept-with-gaps**
