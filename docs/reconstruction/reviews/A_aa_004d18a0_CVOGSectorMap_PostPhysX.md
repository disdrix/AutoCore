# Review A (reconstruction fidelity): `aa_004d18a0` CVOGSectorMap_PostPhysX

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d18a0` |
| **VA** | `0x004d18a0` |
| **Canonical name** | `CVOGSectorMap_PostPhysX` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d18a0_CVOGSectorMap_PostPhysX.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **post-physics** (`PostPhysX`). If physics manager `DAT_00b037f0+4` live: optional camera/pos snapshot from `map+0xe890` into `DAT_00b03618..24`, calls **`CPhysXBase_RenderResults` (`FUN_004b50f0`)**, then delayed ops `FUN_00590a80` / `FUN_00594290`, `FUN_004cfd50`, and fluids `FUN_0049b940` on `map+0xe890`. Load/sim tail after PhysX step — not net pack.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d18a0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d18a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_PostPhysX.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d18a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls CPhysXBase_RenderResults FUN_004b50f0 | High | Callee |
| Delayed operations plate string | High | Body |
| Fluids path on +0xe890 | High | Body |
| Guard DAT_00b037f0+4 | High | Body |
| FUN_00590a80 identity | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if phys live: snapshot → RenderResults → delayed → fluids | Yes |

---

## 5. Gaps / open

1. Name delayed-op managers.
2. Order relative to CPhysXBase_Step.

**Verdict:** **accept-with-gaps**
