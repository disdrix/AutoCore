# Review A (reconstruction fidelity): `aa_004ec7b0` Phy_CollectAllPhysicsPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ec7b0` |
| **VA** | `0x004ec7b0` |
| **Canonical name** | `Phy_CollectAllPhysicsPreloads` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ec7b0_Phy_CollectAllPhysicsPreloads.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Collects physics preloads for an asset (plate `CollectAllPhysicsPreloads`). Builds path `%S%s` from **this+0x3c** (+0x40a wchar base) + suffix `DAT_009cb318`. If file exists (`FUN_007b6730`), opens via `FUN_00989e00` + `FUN_0043d670`. Always `FUN_004eb3b0()`. If **this+0x88** non-null, `FUN_004a04f0(param_2,0,0,1)`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ec7b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004ec7b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CollectAllPhysicsPreloads.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ec7b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Path snprintf from +0x3c+0x40a | High | Body |
| Optional file load + FUN_004eb3b0 | High | Body |
| +0x88 gate extra FUN_004a04f0 | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| build path → maybe load → eb3b0 → maybe a04f0 | Yes |

---

## 5. Gaps / open

1. Name FUN_004eb3b0 / 004a04f0 / 0043d670.
2. Document DAT_009cb318 extension string.

**Verdict:** **accept-with-gaps**
