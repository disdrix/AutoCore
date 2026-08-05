# Review A (reconstruction fidelity): `aa_005128f0` Experience_EnsureCreatureXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128f0` |
| **VA** | `0x005128f0` |
| **Canonical name** | `Experience_EnsureCreatureXpTableLoaded_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005128f0_Experience_EnsureCreatureXpTableLoaded_INFERRED.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

INFERRED **lazy loader** for `tCreatureExperienceLevel` map (`DAT_00b04270`) used by `Experience_GetCreatureXpForLevel`. Sequence: `FUN_007e1d80` → `FUN_007cd150(&DAT_00b04270)` (plate `Mission_tCreatureExperienceLevel` / `//tCreatureExperienceLevel/row`) → `FUN_007b7df0`; fail → `VOG_DEBUG_STOP`. Parallel shape to level/quest ensures.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005128f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005128f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_EnsureCreatureXpTableLoaded_INFERRED.cpp` |
| Function record | `docs/reconstruction/functions/aa_005128f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls FUN_007cd150 creature XP loader | High | Clean |
| Map root DAT_00b04270 | High | Clean arg |
| Same bookend / debug-stop pattern | High | Family match |
| Ready-flag write site | Medium | Not in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bookend → load creature map → bookend → optional stop | Yes |

---

## 5. Gaps / open

1. Seal ready-flag for g_nCreatureXpTableReady.
2. Confirm DAT_00b04270 is only consumer map for kill base.

**Verdict:** **accept-with-gaps**
