# Review A (reconstruction fidelity): `aa_008151a0` Client_RecvInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_008151a0` |
| **VA** | `0x008151a0` |
| **Canonical name** | `Client_RecvInventoryAddItem` |
| **Review date** | `2026-07-23` |
| **Residual pass** | `2026-07-29` — see `reviews/a_008151a0.md` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008151a0_Client_RecvInventoryAddItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **`0x2047`** add-item notify: resolve item by COID/TFID, optionally post a “Received Loot” combat-log line (optional `Broken:` prefix and `xN` quantity), optionally notify loot UI, then either **merge qty** into an existing cargo stack (`FUN_00571830`) when `bAddToExistingItem@+0x12` and item already in grid, or **re-find / full place** (`FUN_00945540`). Ends with inventory-widget + mission-related UI refresh.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008151a0_Client_RecvInventoryAddItem.md` |
| Annotated | `docs/reconstruction/raw/aa_008151a0_Client_RecvInventoryAddItem.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvInventoryAddItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_008151a0_Client_RecvInventoryAddItem.md` |
| Residual scratch | `docs/reconstruction/reviews/a_008151a0.md` |
| System map | `docs/reconstruction/systems/inventory-transfer.md` |
| Wire RE | `docs/inventory-cargo-wire-re.md` |
| Packet docs | `Documentation/PACKET STRUCTURES.md` (0x2047 layout) |
| Dispatch | raw/clean `Client_PacketDispatch` case `0x2047` |
| Sibling C2S | `Client_SendInventoryAddItem` / `Inventory_SerializeAddItemPacket` |
| Helpers (2026-07-29 re-decompile) | `0x00571010`, `0x00571830`, `0x00945540`, `0x00513e70` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `FUN_007a69d0` first | **High** | Raw + clean + live re-decompile |
| Resolve COID via `CVOGReaction_ResolveObjectTarget(1, +0x08, +0x0c)` | **High** | Prologue loads `[ebx+8]/[ebx+0xc]` |
| Early return if resolve null | **High** | |
| Success/apply byte `@+0x18 == 0` → return | **High** | Gate after resolve; wire `bWasSuccessful` |
| Loot line only when `DAT_00d1b8dc != 0` | **High** | Chat host global |
| Qty `< 2` **or** `FUN_00513e70==0` → no `xN`; else `… x%d` with qty `@+0x14` | **High** | Dual sprintf paths |
| Broken prefix bit on `item[0x5f]` bit 19 | **High** | `>> 0x13 & 1` |
| Name via item vtbl `+0x15c` | **High** | |
| Channel `0x17` via `FUN_008f8200` | **High** constant; product name Probable |
| Optional loot UI at `client+0xf38` when visible | **High** | Nested `+0xcb8` vcall `+0x3ac(item)` |
| Place vs re-find gate on `@+0x12` + char/vehicle + `FUN_00571010` | **High** | CF order preserved |
| Re-find when flag0 **or** no char/vehicle **or** not in grid | **High** | `FUN_00945540` |
| Place `FUN_00571830(qty, lo, hi)` when flag set and in-grid | **High** | Role = **qty merge** (helper body) |
| Trailing `FUN_0089c6c0` / `FUN_0092ce90` UI | **High** | |
| Packet in **EBX**; stack formal = **client** | **High** | Prologue + field uses (residual Seal 2) |
| Opcode is S2C **`0x2047`** | **High** | PacketDispatch only; not body immediate |
| XY `@+0x10/+0x11` used for placement | **Falsified for this body** | Never loaded; re-find owns slots |
| Plate “skip place when `@+0x12` non-zero” | **Falsified** | Non-zero → merge place when in-grid |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Helper + resolve + success `@+0x18` | **Yes** |
| Loot formatting branches | **Yes** |
| Loot UI optional path | **Yes** |
| Place vs re-find compound if | **Yes** |
| Widget + mission refresh | **Yes** |
| No invented modernizations | **Yes** |
| Live re-decompile 2026-07-29 ≡ frozen raw | **Yes** |

---

## 5. Gaps / open

1. `FUN_00571830` thiscall `this` (grid) at Recv call site — decompiler residual only.
2. `FUN_00945540` item in EDI — register residual from parent.
3. Product name of channel `0x17` (constant sealed).
4. Runtime / differential / bit-exact open.

**Closed by residual (2026-07-29):** opcode binding; EBX/stack framing; `@+0x12` polarity; helper roles; XY non-use by body.

**Verdict:** Clean faithfully scaffolds add-item CF. **accept-with-gaps.**
