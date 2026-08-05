# Review A (reconstruction fidelity): `aa_00533c30` CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **VA** | `0x00533c30` |
| **Canonical name** | `CVOGReaction_AddExperience` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |
| **Note** | Prior dual reviews exist as `aa_00533c30_reconstruction_review.md` / `_skeptical_review.md`; this A/B pair restates for the requested naming scheme. |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_AddExperience.cpp` |
| Prior art | `docs/XP.md` § Core apply path |
| Related | `WeaponAllowsKillXpBonus` body now reconstructed |

---

## 2. Signature & CF fidelity

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `__thiscall (amount, isKillPath)` | Present | Present | **Yes** |
| KillPath spree 5s / clamp 5 | Present | Present | **Yes** |
| Optional weapon/mode gate → table scale | Present | Present | **Yes** |
| Personal scalar `+0xc54` | Present | Present | **Yes** |
| Max-level soft cap unless `+0x6b4` | Present | Present | **Yes** |
| `scaled==0` → false | Present | Present | **Yes** |
| `+0x730 += scaled` | Present | Present | **Yes** |
| Level loops only if flag `+0x7e` | Present | Present | **Yes** |
| LevelDown / LevelUp guards | Present | Present | **Yes** |

---

## 3. State mutations

| Offset | Role |
|---|---|
| `+0x734` | Last kill tick (KillPath) |
| `+0x738` | Spree / hint byte |
| `+0x730` | Total XP |
| Level / points | Via LevelUp/LevelDown callees |

---

## 4. Gaps

1. Spree table DAT float values not re-read this pass.
2. `ROUND` implementation approximate in clean helper.
3. Dual level sources (vtable `+0x27c` vs field `+0x6c8`) still dual in body.

**Verdict:** Human-refined clean remains faithful. **accept-with-gaps.**
