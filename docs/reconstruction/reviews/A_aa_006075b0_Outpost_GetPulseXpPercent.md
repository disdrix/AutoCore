# Review A (reconstruction fidelity): `aa_006075b0` Outpost_GetPulseXpPercent

| Field | Value |
|---|---|
| **Stable ID** | `aa_006075b0` |
| **VA** | `0x006075b0` |
| **Canonical name** | `Outpost_GetPulseXpPercent` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006075b0_Outpost_GetPulseXpPercent.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Index outpost pulse **fPercentLevelXP** table. `__fastcall(pOutpost)`. `bIsOutpost@+0x220`: non-zero → `DAT_00d029e0` else `DAT_00d029f0`. Row index `+0x23c`; count = `(end-begin)>>4` (stride **0x10**); percent float at row `+0x08`. Invalid index → `g_flZero`. Defensive `FUN_00608620` if second bounds check fails. Sample true-outpost pulse 0 ≈ **0.0006**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006075b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_006075b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_GetPulseXpPercent.cpp` |
| Function record | `docs/reconstruction/functions/aa_006075b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Two tables: outpost vs non-outpost | High | Clean |
| Row stride 0x10, percent +0x08 | High | Plate |
| Index +0x23c bounds check | High | Clean |
| Invalid → 0.0 | High | g_flZero |
| FUN_00608620 rare path | Medium | Defensive |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| select table → bounds → row+0x08 percent else 0 | Yes |

---

## 5. Gaps / open

1. Dump full percent tables for all pulse tiers.
2. Confirm +0x220 meaning (true outpost flag).

**Verdict:** **accept-with-gaps**
