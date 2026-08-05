# Review A (reconstruction fidelity): `aa_00607830` Outpost_ComputePulseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607830` |
| **VA** | `0x00607830` |
| **Canonical name** | `Outpost_ComputePulseXp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00607830_Outpost_ComputePulseXp.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Periodic **outpost / non-outpost pulse XP** amount: if state `this+0x238 < 1` return **0**; else GetLevel (vtbl **+0x27c**), `Experience_GetCumulativeThreshold(level)` and (if level>1) for level-1; `Outpost_GetPulseXpPercent(this)`; `amount = FUN_006a3db0()` = round(levelSpan * percent * scalar@**+0x21c**). x87 stack carries thrHi/thrLo/percent/scalar — decompiler drops explicit FPU args. Callers often gate level≥60; pulse interval **900000 ms**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00607830_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00607830_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_ComputePulseXp.cpp` |
| Function record | `docs/reconstruction/functions/aa_00607830_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate +0x238 < 1 → 0 | High | Clean |
| Uses GetCumulativeThreshold for span | High | Callees |
| Percent via sibling GetPulseXpPercent | High | Clean |
| Scalar at +0x21c inside round helper | Medium | Plate / FPU residual |
| FUN_006a3db0 exact formula sealed | Medium | x87 residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| inactive→0; level; thr hi/lo; percent; round helper | Yes |

---

## 5. Gaps / open

1. Seal FUN_006a3db0 rounding (x87).
2. Confirm level≥60 is call-site only.

**Verdict:** **accept-with-gaps**
