# Review A (reconstruction fidelity): `aa_00945540` Inv_lootpickup

| Field | Value |
|---|---|
| **Stable ID** | `aa_00945540` |
| **VA** | `0x00945540` |
| **Canonical name** | `Inv_lootpickup` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00945540_Inv_lootpickup.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Runtime **loot pickup** path (plate `lootpickup`). ~323 lines — handles player picking world/corpse loot into inventory (validation, transfer, net notify). Distinct from table loaders and GenerateLootItem creation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00945540_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00945540_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inv_lootpickup.cpp` |
| Function record | `docs/reconstruction/functions/aa_00945540_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loot pickup runtime path | High | Plate name |
| Distinct from generate/loaders | High | Role |
| Full validation/net sealed | Medium | Residual body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| pickup request → validate → transfer helpers | Yes |

---

## 5. Gaps / open

1. Seal packet opcode and failure codes.
2. Inventory footprint interaction.

**Verdict:** **accept-with-gaps**
