# Review A (reconstruction fidelity): `aa_007cd150` Mission_tCreatureExperienceLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cd150` |
| **VA** | `0x007cd150` |
| **Canonical name** | `Mission_tCreatureExperienceLevel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007cd150_Mission_tCreatureExperienceLevel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tCreatureExperienceLevel/row` into `DAT_00b04270` map. Called from `Experience_EnsureCreatureXpTableLoaded` as `FUN_007cd150`. Supplies kill-base XP for `Experience_GetCreatureXpForLevel` / LevelDiffBaseXp. ~293-line DBReader.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007cd150_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007cd150_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_tCreatureExperienceLevel.cpp` |
| Function record | `docs/reconstruction/functions/aa_007cd150_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tCreatureExperienceLevel loader | High | Embedded string |
| EnsureCreatureXpTableLoaded callee | High | Caller |
| Map DAT_00b04270 target | High | Ensure arg |
| Full column map sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read creature level XP rows | Yes |

---

## 5. Gaps / open

1. Seal IDCreatureLevel key + intExperience +0x10.
2. Row count ~126 parity.

**Verdict:** **accept-with-gaps**
