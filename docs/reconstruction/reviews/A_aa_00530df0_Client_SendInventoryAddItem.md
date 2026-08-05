# Review A (reconstruction fidelity): `aa_00530df0` Client_SendInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530df0` |
| **VA** | `0x00530df0` |
| **Canonical name** | `Client_SendInventoryAddItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00530df0_Client_SendInventoryAddItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S / local-optimistic InventoryAddItem builder: clear item flag bit 2, heap-allocate `0x20` packet with opcode **`0x2047`**, fill via `Inventory_SerializeAddItemPacket`, optional type-4 LogicUi notify, then either:

- **`addToExisting@+0x12 == 0`**: local `FUN_00571620` PlaceItemFootprint (X/Y from packet, qty from item vtbl `+0x25c`); bind host or world-drop on fail; or
- **`addToExisting != 0`**: merge via `FUN_00571830`; residual check `FUN_00570710` fail → `"INVENTORY FAILURE…"` log.

Always frees the heap packet (`operator_delete`; Ghidra noreturn noise).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00530df0_Client_SendInventoryAddItem.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendInventoryAddItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_00530df0_Client_SendInventoryAddItem.md` |
| Serialize dual review | `aa_004fadb0_*` reviews |
| System map | `docs/reconstruction/systems/inventory-transfer.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clear `pItem[0x5f] &= ~4` | **High** | Raw + clean |
| `operator_new(0x20)`; zero; `*pkt = 0x2047` | **High** | Explicit |
| `Inventory_SerializeAddItemPacket(pkt, item, &iterOut)` | **High** | Named callee; dual-reviewed sibling |
| Serialize fail → delete packet | **High** | |
| Type-4 special LogicUi (`Client_SendLogicUiPacket`) when clone type 4 | **High** | COID + code `0xc` |
| Branch on `pkt+0x12` addToExisting | **High** | New-slot vs merge |
| New-slot: `FUN_00571620(item, X@+0x10, Y@+0x11, qty)` | **High** | |
| Place fail → optional `FUN_004d2820` world path | **High** | Gates on host flags |
| Place ok → item vtbl `+0x158` bind + `+0xb4` | **High** | |
| Merge: `FUN_00571830` + `FUN_004d4790` + residual `FUN_00570710` | **High** | |
| Failure log format string | **High** | Present in body |
| `__thiscall (host, item, mergeContext)` | **Probable** | Plate + clean; ECX host |
| `operator_delete` truly noreturn | **Tentative** | Ghidra artifact; treat as free + return |
| When/who sends packet on wire | **Tentative** | Serialize fills; send may be inside Serialize or side path — not re-proven here |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Flag clear + alloc + opcode | **Yes** |
| Serialize + fail delete | **Yes** |
| Type-4 LogicUi | **Yes** |
| New-slot place / fail / bind | **Yes** |
| Merge + residual log | **Yes** |
| Delete on all success edges | **Yes** (modulo noreturn noise) |

---

## 5. Gaps / open

1. Whether Serialize itself transmits or only fills (sibling review owns field map).
2. `mergeContext` exact meaning for `FUN_00571830`.
3. Noreturn `operator_delete` edges need return-path cleanup if ported literally.
4. Runtime / differential open.

**Verdict:** Clean faithfully scaffolds AddItem builder CF. **accept-with-gaps.**
