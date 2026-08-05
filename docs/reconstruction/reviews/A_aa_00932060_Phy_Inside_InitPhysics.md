# Review A (reconstruction fidelity): `aa_00932060` Phy_Inside_InitPhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_00932060` |
| **VA** | `0x00932060` |
| **Canonical name** | `Phy_Inside_InitPhysics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00932060_Phy_Inside_InitPhysics.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Interior of **initPhysics** (plate `@@inside InitPhysics` / `start initPhysics`). Logs, invokes manager vtbl at **unaff_ESI+0xe04**, `initterrain` via `FUN_004d9cd0`, `FUN_0058e0b0`, seeds float constants from `DAT_00a15868` / `DAT_00aaa9c0`, further init callees `FUN_0055ff20`, `FUN_00581220`, `FUN_00405490`. Companion to Start_ReinitPhysics — bring-up rather than teardown. `unaff_ESI` this residual from decompiler.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00932060_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00932060_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_Inside_InitPhysics.cpp` |
| Function record | `docs/reconstruction/functions/aa_00932060_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| initPhysics interior orchestration | High | Plate strings |
| Terrain init FUN_004d9cd0 | High | Body |
| Manager vtbl at +0xe04 | High | Body |
| unaff_ESI is true this | Medium | Decompiler artifact |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| log → manager → terrain → seed constants → more inits | Yes |

---

## 5. Gaps / open

1. Recover this pointer (unaff_ESI) formally.
2. Order full init vs Start_ReinitPhysics.

**Verdict:** **accept-with-gaps**
