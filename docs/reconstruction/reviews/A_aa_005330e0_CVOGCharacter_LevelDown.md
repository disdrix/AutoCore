# Review A (reconstruction fidelity): `aa_005330e0` CVOGCharacter_LevelDown

| Field | Value |
|---|---|
| **Stable ID** | `aa_005330e0` |
| **VA** | `0x005330e0` |
| **Canonical name** | `CVOGCharacter_LevelDown` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005330e0_CVOGCharacter_LevelDown.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reverse one character level: lookup **current** tExperienceLevel row by nLevel@+0x6c8, dirty|0x80, decrement level, subtract skill/attrib grants (clamp ≥0), optional odd-level base-stat nudge, vehicle pool recalc, SearchAutoMissions if local (+0x7e). Research pool **not** reversed.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005330e0_CVOGCharacter_LevelDown.md` |
| Annotated | `docs/reconstruction/raw/aa_005330e0_CVOGCharacter_LevelDown.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_LevelDown.cpp` |
| Function record | `docs/reconstruction/functions/aa_005330e0_CVOGCharacter_LevelDown.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Lookup CURRENT level before decrement` | **High** | LowerBound on +0x6c8 |
| `Dirty dual-base +0x180 |= 0x80` | **High** | Body store |
| `nLevel-- then subtract row+0x14 skill / +0x16 attrib` | **High** | Clamp pools ≥ 0 |
| `Odd post-dec level → base-stat helpers −1` | **High** | MSVC oddness idiom |
| `Vehicle_RecalcCombatPools if +0x250` | **High** | Optional |
| `No research (+0x580) reverse` | **High** | No store in body; LevelUp contrast |
| `Local +0x7e → SearchAutoMissions` | **High** | End gate |
| `Bail if map end / no row` | **High** | No mutation if missing |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Table ensure + lower_bound | **Yes** |
| Dirty/level/pools | **Yes** |
| Odd-level + vehicle + local missions | **Yes** |
| No invented research reverse | **Yes** |

---

## 5. Gaps / open

1. Exact tExperienceLevel row layout beyond +0x14/+0x16.
2. FUN_004c2ef0 family base-stat semantics.
3. vtable +0x5c refresh identity.
4. Runtime negative-XP de-level capture.

**Verdict:** **accept-with-gaps**
