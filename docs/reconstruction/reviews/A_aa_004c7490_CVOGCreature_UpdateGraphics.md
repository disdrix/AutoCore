# Review A (reconstruction fidelity): `aa_004c7490` CVOGCreature_UpdateGraphics

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7490` |
| **VA** | `0x004c7490` |
| **Canonical name** | `CVOGCreature_UpdateGraphics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c7490_CVOGCreature_UpdateGraphics.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Creature **graphics refresh** (`CVOGCreature::UpdateGraphics`). `__fastcall` ~249 lines; callees `FUN_0053e0b0`, `FUN_004e87d0` / `FUN_004e8830` / `FUN_004e8860` / `FUN_004e88e0`, `FUN_00567ce0`, `FUN_005d5360`. Client visual path — not combat XP or net serialize. Domain alias of FUN_004c7490.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c7490_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004c7490_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_UpdateGraphics.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c7490_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| UpdateGraphics plate string | High | Embedded |
| Graphics/visual refresh role | High | Name + callees |
| Not net CreateSimpleObject | High | Distinct |
| Full visual state machine sealed | Medium | FUN residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| graphics update branches → visual helpers | Yes |

---

## 5. Gaps / open

1. Name FUN_004e87* visual helpers.
2. When called relative to create/load pipeline.

**Verdict:** **accept-with-gaps**
