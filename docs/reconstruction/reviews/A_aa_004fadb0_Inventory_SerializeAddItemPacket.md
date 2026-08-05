# Review A (reconstruction fidelity): `aa_004fadb0` Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **VA** | `0x004fadb0` |
| **Canonical name** | `Inventory_SerializeAddItemPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fadb0_Inventory_SerializeAddItemPacket.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill InventoryAddItem packet (**opcode 0x2047**, size **0x20**) for cargo place. Requires vehicle cargo grid **`+0x2b0`**. Writes item COID lo/hi at packet **`+0x08/+0x0c`** (from item **`+0x160/+0x164`**, NOT grid XY); cargo X/Y at **`+0x10/+0x11`**; `bAddToExisting` **`+0x12`**; `wasAdded` **`+0x18`**. Merge path: same CBID (`clonebase+0x34`), flag bit clear at **`+0x17c`**, quantity-compatible — then wasAdded=1, addToExisting=1, X=Y=0. Corrects older wrong plate that put XY at +8. Returns 1 if filled.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fadb0_Inventory_SerializeAddItemPacket.md` (or `aa_004fadb0_FUN_004fadb0.md`) |
| Annotated | `docs/reconstruction/raw/aa_004fadb0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Inventory_SerializeAddItemPacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fadb0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Opcode 0x2047 size 0x20` | High | Plate + PACKET STRUCTURES |
| `COID at +0x08/+0x0c not XY` | High | Plate correction |
| `XY at +0x10/+0x11` | High | Plate |
| `Merge path CBID + flags` | High | Plate |
| `Cargo grid +0x2b0 required` | High | Plate |
| `Quantity vfunc residual` | Medium | +0x25c |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null grid fail → merge or free slot fill | Yes |
| No invented equip hardpoint | Yes |

---

## 5. Gaps / open

1. Exact quantity-compat helper FUN_0040abf0.
2. Caller send path after fill.

**Verdict:** **accept-with-gaps**
