# Review A (reconstruction fidelity): `aa_0052a9b0` Vehicle_GetSkillCooldownModifier

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a9b0` |
| **VA** | `0x0052a9b0` |
| **Canonical name** | `Vehicle_GetSkillCooldownModifier` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052a9b0_Vehicle_GetSkillCooldownModifier.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return float cooldown scale for cast-again duration / hotbar recharge UI. Looks up category scale map (`Map_LowerBoundFindByIntKey` at this+**0xc70**); if vehicle present at character+**0x250** and power plant at vehicle+**0x268**, scale multiplies plant field **+0xCC**. Used by `CVOGHBOKToCastAgain_ctor` / QB recharge. Default category scale often **1.0**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052a9b0_Vehicle_GetSkillCooldownModifier.md` (or `aa_0052a9b0_FUN_0052a9b0.md`) |
| Annotated | `docs/reconstruction/raw/aa_0052a9b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_GetSkillCooldownModifier.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052a9b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Category map at this+0xc70` | High | Body |
| `Power plant at vehicle+0x268` | High | Body |
| `Plant scale field +0xCC` | High | Plate |
| `Used by cast-again / QB UI` | High | Plate |
| `Exact map miss default` | Medium | Decomp incomplete return path |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Map lookup → optional plant multiply → return scale | Yes |
| No invent CD insert | Yes |

---

## 5. Gaps / open

1. Seal full return when map miss / no plant.
2. Clean decompile of multiply (current clean truncated?).

**Verdict:** **accept-with-gaps**
