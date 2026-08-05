# Review A (reconstruction fidelity): `aa_007dd5e0` Mission_tContinentExploredAreas

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dd5e0` |
| **VA** | `0x007dd5e0` |
| **Canonical name** | `Mission_tContinentExploredAreas` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007dd5e0_Mission_tContinentExploredAreas.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tContinentExploredAreas/row` — first-visit area metadata (continent, area id 1..32, name, `intXPLevel`). AutoCore already models fields; geometry is separate (MAP_REVEAL). DBReader family with COM binds. XP-adjacent: area explore awards use `intXPLevel` index.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007dd5e0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007dd5e0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_tContinentExploredAreas.cpp` |
| Function record | `docs/reconstruction/functions/aa_007dd5e0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tContinentExploredAreas loader | High | Embedded string |
| XPLevel column for area awards | High | XP.md |
| DBReader cascade | High | Body shape |
| Full column map sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read explored-area rows | Yes |

---

## 5. Gaps / open

1. Seal column order vs AutoCore ContinentExploredAreas model.
2. Confirm 741 retail row scale.

**Verdict:** **accept-with-gaps**
