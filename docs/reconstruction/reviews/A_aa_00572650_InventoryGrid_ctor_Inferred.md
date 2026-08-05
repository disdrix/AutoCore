# Review A (reconstruction fidelity): `aa_00572650` InventoryGrid_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572650` |
| **VA** | `0x00572650` |
| **Canonical name** | `InventoryGrid_ctor_Inferred` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00572650_InventoryGrid_ctor_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct in-place **0x68-byte** inventory grid: install vtables, set **width +0x08**, **height +0x0C**, **pages +0x14**, allocate cell array **+0x28**, init CRITICAL_SECTION **+0x30**, RB-tree sentinel **+0x60** / size **+0x64**. Name INFERRED but layout high confidence from body. Foundation for all cargo grids.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00572650_InventoryGrid_ctor_Inferred.md` (or `aa_00572650_FUN_00572650.md`) |
| Annotated | `docs/reconstruction/raw/aa_00572650_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_ctor_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00572650_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Object size 0x68` | High | Plate |
| `width/height/pages offsets` | High | Plate |
| `Cell array +0x28` | High | Plate |
| `CS +0x30` | High | Plate |
| `RB-tree +0x60/+0x64` | High | Plate |
| `Vtable absolute PTR residual` | Medium | ASLR/image |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Field init + allocate cells + CS | Yes |
| No place logic | Yes |

---

## 5. Gaps / open

1. Exact nested object at +0x2C.
2. AllocateCellArray pairing.

**Verdict:** **accept-with-gaps**
