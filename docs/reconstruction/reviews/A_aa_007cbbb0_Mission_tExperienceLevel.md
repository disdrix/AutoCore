# Review A (reconstruction fidelity): `aa_007cbbb0` Mission_tExperienceLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cbbb0` |
| **VA** | `0x007cbbb0` |
| **Canonical name** | `Mission_tExperienceLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cbbb0_Mission_tExperienceLevel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tExperienceLevel/row` into the cumulative XP map consumed by `Experience_GetCumulativeThreshold`. Large COM/DBReader body (`FUN_004231d0` binds, unreachable-block noise). Called from `Experience_EnsureLevelTableLoaded_INFERRED` as `FUN_007cbbb0(&map)`. Plate-driven name from embedded path string — not a mission UI unit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cbbb0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007cbbb0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_tExperienceLevel.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cbbb0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tExperienceLevel row loader | High | Embedded //tExperienceLevel/row |
| Called by EnsureLevelTableLoaded | High | Caller graph |
| DBReader bind cascade | High | Body shape |
| Full column→field map sealed | Medium | Large residual |
| Unreachable blocks | Medium | Ghidra noise |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open/bind/read rows into map; error paths | Yes |

---

## 5. Gaps / open

1. Seal columns: level key + intExperience +0x10.
2. Ready-flag set after successful load.

**Verdict:** **accept-with-gaps**
