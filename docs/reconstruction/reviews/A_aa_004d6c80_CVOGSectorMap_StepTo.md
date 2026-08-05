# Review A (reconstruction fidelity): `aa_004d6c80` CVOGSectorMap_StepTo

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d6c80` |
| **VA** | `0x004d6c80` |
| **Canonical name** | `CVOGSectorMap_StepTo` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d6c80_CVOGSectorMap_StepTo.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **dt orchestrator** (`StepTo`). Calls `FUN_004d3420(dt)` first. If `map+0x7d==0`: clamps dt by `g_flMultiKillCountBlend`, converts to int step count via `floor(dt * DAT_009cc798)+1`, loops that many times: `FUN_00561910`, `FUN_00561b60`, **`StepCreatures` (004d4da0)**; then **`StepTriggers` (004d3980)**. Else branch: StepCreatures + `FUN_00562bf0`. Master client load/sim step entry.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d6c80_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d6c80_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_StepTo.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d6c80_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Orchestrates StepCreatures + StepTriggers | High | Direct calls |
| Substep count from dt * DAT_009cc798 | High | Body |
| map+0x7d selects branch | High | Body |
| FUN_004d3420 pre-step | High | Body |
| DAT_009cc798 == 30 or similar | Medium | Need read_memory |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| pre → (substep loop creatures) → triggers OR alt branch | Yes |

---

## 5. Gaps / open

1. read_memory DAT_009cc798 / g_flMultiKillCountBlend.
2. Name FUN_00561910 / 00561b60.

**Verdict:** **accept-with-gaps**
