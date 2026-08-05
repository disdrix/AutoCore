# Review A (reconstruction fidelity): `aa_004d3980` CVOGSectorMap_StepTriggers

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3980` |
| **VA** | `0x004d3980` |
| **Canonical name** | `CVOGSectorMap_StepTriggers` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d3980_CVOGSectorMap_StepTriggers.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **trigger step** (`StepTriggers`). Walks trigger container via `FUN_00404bc0(0x38)` / `FUN_004022a0` iterator; for active `(char)obj[0x58]` calls vtbl **+0x50**. Uses `CVOGReaction_ResolveObjectTarget` family and `FUN_004e3330` follow-on. Critical for combat/mission trigger volumes during map step.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d3980_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d3980_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_StepTriggers.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d3980_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Plate StepTriggers sealed | High | String |
| Active flag at +0x58 gates vtbl+0x50 | High | Body |
| Iterator FUN_004022a0 loop | High | Body |
| Critical section leave if +0x28 | High | Body |
| Full trigger type dispatch | Medium | FUN residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| lock/iter → active fire vtbl+0x50 → unlock → post FUN_004e3330 | Yes |

---

## 5. Gaps / open

1. Name vtbl+0x50 fire method.
2. Relate to server Trigger system docs.

**Verdict:** **accept-with-gaps**
