# Review A (reconstruction fidelity): `aa_005128b0` Experience_EnsureLevelTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128b0` |
| **VA** | `0x005128b0` |
| **Canonical name** | `Experience_EnsureLevelTableLoaded_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005128b0_Experience_EnsureLevelTableLoaded_INFERRED.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

INFERRED **lazy loader** for `tExperienceLevel` map used by `Experience_GetCumulativeThreshold`. Sequence: `FUN_007e1d80()` → `FUN_007cbbb0(&g_pExperienceLevelMap_INFERRED)` (plate `Mission_tExperienceLevel` / `//tExperienceLevel/row`) → `FUN_007b7df0()`; if load result `<0` call `FUN_007a4480(0,"VOG_DEBUG_STOP")`. Thin wrapper; does not itself set ready flag in clean (flag write may be inside loader).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005128b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005128b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_EnsureLevelTableLoaded_INFERRED.cpp` |
| Function record | `docs/reconstruction/functions/aa_005128b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls Mission_tExperienceLevel-shaped FUN_007cbbb0 | High | Clean + sibling plate |
| Debug-stop on negative load | High | Clean |
| Paired with GetCumulativeThreshold ready check | High | Caller graph |
| Ready-flag write location | Medium | Not in this body |
| FUN_007e1d80 / FUN_007b7df0 identity | Medium | Unnamed bookends |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bookend → load map → bookend → optional VOG_DEBUG_STOP | Yes |

---

## 5. Gaps / open

1. Name FUN_007e1d80 / FUN_007b7df0 (enter/leave critical or stream).
2. Seal where g_nExperienceLevelTableReady is set to non-zero.

**Verdict:** **accept-with-gaps**
