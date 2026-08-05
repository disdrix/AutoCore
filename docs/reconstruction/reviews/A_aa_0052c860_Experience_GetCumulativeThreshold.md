# Review A (reconstruction fidelity): `aa_0052c860` Experience_GetCumulativeThreshold

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052c860` |
| **VA** | `0x0052c860` |
| **Canonical name** | `Experience_GetCumulativeThreshold` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052c860_Experience_GetCumulativeThreshold.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Lookup **cumulative player XP threshold** for level `wLevel` from `tExperienceLevel`. `__cdecl(ushort wLevel) → unsigned`. Lazy-inits via `Experience_EnsureLevelTableLoaded_INFERRED` when `g_nExperienceLevelTableReady==0` (twice). `StdMap_LowerBoundByIntKey` on experience map; returns entry `+0x10` (`intExperience`) or sentinel **0x7FFFFFFF** if missing. Blocks level-up loops in AddExperience / soft max-level. Distinct from creature XP helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052c860_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0052c860_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_GetCumulativeThreshold.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052c860_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cumulative threshold +0x10 | High | Clean + XP.md |
| Missing → 0x7FFFFFFF sentinel | High | Clean default |
| Lazy EnsureLevelTableLoaded | High | Body |
| Uses StdMap_LowerBoundByIntKey family | High | Callee / plate |
| Key is ushort zero-extended | High | Clean local |
| Map root global exact name | Medium | INFERRED |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ensure → lower_bound → +0x10 or 0x7FFFFFFF | Yes |
| Not creature XP table | Yes |

---

## 5. Gaps / open

1. Seal level→threshold table payload for level-up loop tests.
2. Confirm sentinel used by all AddExperience / Outpost callers.

**Verdict:** **accept-with-gaps**
