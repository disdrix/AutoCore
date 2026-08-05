# Review A (reconstruction fidelity): `aa_00570600` InventoryGrid_SetOwnerFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570600` |
| **VA** | `0x00570600` |
| **Canonical name** | `InventoryGrid_SetOwnerFlag_Inferred` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00570600_InventoryGrid_SetOwnerFlag_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Trivial inventory grid **owner flag setter**: writes int `nFlag` to grid **+0x4**. Cargo create always passes **1** after ctor. Clean scaffold omitted body; annotated raw has `*(this+4)=nFlag`. Name INFERRED from call site.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00570600_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00570600_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetOwnerFlag_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00570600_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Writes +0x4 | High | Annotated raw |
| Cargo path nFlag=1 | High | Plate |
| No other side effects | High | Body |
| Clean body empty residual | Medium | Scaffold drift vs raw |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| * (this+4) = nFlag; return | Yes (raw) |

---

## 5. Gaps / open

1. Repair clean.cpp to match annotated write.
2. Meaning of non-1 flag values if any.

**Verdict:** **accept-with-gaps**
