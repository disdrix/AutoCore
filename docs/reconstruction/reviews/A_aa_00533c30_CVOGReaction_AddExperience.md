# Review A (reconstruction fidelity): `aa_00533c30` CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **VA** | `0x00533c30` |
| **Canonical name** | `CVOGReaction_AddExperience` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00533c30_CVOGReaction_AddExperience.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client XP apply kernel: kill-path spree (5s, clamp 0..5) + optional weapon-bonus table scale; scaled=(int)(amount×flPersonalXpGain@+0xc54); max-level soft cap unless specialMode@+0x6b4; apply to total@+0x730; level-up/down loops only when local flag +0x7e.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.md` |
| Annotated | `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_AddExperience.cpp` |
| Function record | `docs/reconstruction/functions/aa_00533c30_CVOGReaction_AddExperience.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `KillPath updates spree @+0x738 / last tick +0x734 (5s)` | **High** | Clamp spree ≤5 |
| `Weapon bonus table only if WeaponAllowsKillXpBonus` | **High** | ROUND((table[i]+1)*amount) |
| `Personal scalar char+0xc54` | **High** | int cast product |
| `Max-level soft cap via cumulative threshold` | **High** | unless +0x6b4>0 |
| `scaled==0 → return false` | **High** | No total mutate |
| `Total XP += scaled @+0x730` | **High** | Store |
| `Level loops only if +0x7e local flag` | **High** | LevelUp/LevelDown |
| `Packet/mission path isKillPath=0 (no spree)` | **High** | Caller convention |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Kill-path spree/bonus | **Yes** |
| Scale + cap + apply | **Yes** |
| Level loops gated | **Yes** |
| No invented explore XP branch | **Yes** |

---

## 5. Gaps / open

1. Spree table DAT_00aaa7b8/8f4/8f0 exact float values.
2. Index source +0xe818 meaning.
3. LevelUp notify flag conventions.
4. Runtime GiveXP vs kill path capture.

**Verdict:** **accept-with-gaps**
