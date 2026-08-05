# Review A (reconstruction fidelity): `aa_0052dec0` Experience_XpToReachRelativeLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dec0` |
| **VA** | `0x0052dec0` |
| **Canonical name** | `Experience_XpToReachRelativeLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052dec0_Experience_XpToReachRelativeLevel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Compute **XP delta to reach relative level** for a character: `__thiscall(this, nLevelDelta) → int`. `curLevel = vtbl+0x27c` GetLevel; if `curLevel + delta < 1` return **0**. Else `thr = GetCumulativeThreshold(curLevel+delta-1)`; return `(int)(thr / flPersonalXpGain@+0xc54) - nTotalXp@+0x730 + 1`. Used by reaction SetLevel / relative-level helpers and mission min-level awards (`CVOGCharacter_CheckMissionPrerequisites`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052dec0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0052dec0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_XpToReachRelativeLevel.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052dec0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| GetLevel via vtbl +0x27c | High | Clean |
| Early-out when target level < 1 | High | Clean |
| Threshold key = cur+delta-1 | High | Clean + XP.md |
| Divide by personal gain float +0xc54 | High | Clean |
| Subtract total XP +0x730 then +1 | High | Clean |
| Negative result allowed (de-level) | High | Plate notes |
| Exact multi-inherit iface walk | Medium | Raw this+4 chain |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| level = GetLevel; if level+delta<1 → 0 | Yes |
| thr(level+delta-1)/gain - totalXp + 1 | Yes |

---

## 5. Gaps / open

1. Seal +0xc54 personal gain default when unset.
2. Confirm +0x730 is total XP not current-level XP.
3. Bit-exact float→int truncation mode.

**Verdict:** **accept-with-gaps**
