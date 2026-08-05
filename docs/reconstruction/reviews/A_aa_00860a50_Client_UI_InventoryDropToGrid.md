# Review A (reconstruction fidelity): `aa_00860a50` Client_UI_InventoryDropToGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **VA** | `0x00860a50` |
| **Canonical name** | `Client_UI_InventoryDropToGrid` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw/annotated) |
| **Counterpart** | `reviews/B_aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| **Prior dual** | `aa_00860a50_reconstruction_review.md` / `aa_00860a50_skeptical_review.md` |
| **Live re-decompile** | Ghidra MCP `batch_decompile` 2026-07-29 — matches raw capture |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI drop-to-grid (and store-like) C2S builder: multi-gate validation (null host, hit-test, class/type, trade strings), busy short-circuit, then either grid drop packet **`0x2036` size `0x20`** or alternate **`0x2027` size `0x40`**, via `Client_SendSectorPacket`; fail toast returns 0. Does **not** place footprint.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| Annotated | `raw/aa_00860a50_Client_UI_InventoryDropToGrid.annotated.md` (refined 2026-07-29) |
| Clean | `reconstructed-exact/Client_UI_InventoryDropToGrid.cpp` |
| Function record | `functions/aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| Prior dual | `reviews/aa_00860a50_*` |
| System / wire | `systems/inventory-transfer.md`, `docs/inventory-cargo-wire-re.md` |
| Packet docs | `Documentation/PACKET STRUCTURES.md` § InventoryDrop Size=0x20 |
| Server | `InventoryDropPacket.cs` (`X@0x18`, `Y@0x19`, `Type@0x1a`) |
| DropResponse | `raw/aa_00813730_*.annotated.md` inventoryType switch |
| Live Ghidra | `0x00860a50` re-decompile confirms dual opcode paths |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-gate early fails → 0 | **High** | Null host, hit-test, trade strings |
| Busy `DAT_00d1a8f6` → return 1 no send | **High** | Shared with grab |
| Grid opcode LE `0x2036` size `0x20` | **Confirmed** | `'6'+' '` packing; re-decompile |
| Alternate opcode `0x2027` size `0x40` | **High** CF; store semantics **Probable** |
| Type from `in_EAX[0x15b]+4` (`window+0x56c`) | **High** | Matches grab type host |
| Grid fields COID@+8, X@+0x18, Y@+0x19, type@+0x1a | **High** | Decompile + server Read |
| Trade type 5 reject strings | **High** | Literal strings in body |
| XY scale formula understood | **High** (residual) | pageH×pageIdx+cellY asm; see residual A/B |
| “Early allows only types 1 and 3” | **Overstated** | Class-4 conjunct only |
| Formal signature complete | **Tentative** | `in_EAX` this |
| Places into grid | **Falsified** | No `FUN_00571620`; DropResponse places |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null `DAT_00d1b6d8` / hit-test fail → 0 | **Yes** |
| Class-4 block when type∉{1,3} | **Yes** |
| Trade type-5 dual rejects | **Yes** |
| Busy soft-return 1 | **Yes** |
| Vendor mode-4 shortcut → 0x2027/0x40 | **Yes** |
| Store type-4 path + “store does not want” | **Yes** |
| Else grid 0x2036/0x20 + XY pack | **Yes** |
| `Client_SendSectorPacket` + set busy | **Yes** |
| Fail toast `FUN_007fdfb0` → 0 | **Yes** |

CONCAT packing left as scaffold (correct fidelity). Clean plate documents offsets without inventing sealed Y math.

---

## 5. Packet field map — grid path (decompile-sealed)

| Offset | Write | Source | Retail / server |
|---:|---|---|---|
| `+0x00` | `'6''\0\0'` chars | opcode **`0x2036`** | `GameOpcode.InventoryDrop` |
| `+0x04` | *(none)* | — | (docs txn id unused here) |
| `+0x08` | item+0x160/164 | COID | `ItemCoid` |
| `+0x10` | item+0x168 | global | `ItemGlobal` |
| `+0x18` | `local_106` | locX | `InventoryPositionX` |
| `+0x19` | scaled `local_105` | locY | `InventoryPositionY` |
| `+0x1a` | `*(extraout_EDX+4)` | typeTo | `InventoryType` |
| `+0x1c` | *(none on grid path)* | — | struct has `lQuantity`; client may leave garbage |

---

## 6. Link to DropResponse `inventoryType` switch

C2S Drop `ucTypeTo@+0x1a` is the same enum DropResponse switches on:

| Type | DropResponse grid (annotated) |
|---:|---|
| 1 | Cargo via vehicle `+0x2b0` |
| 3 | Locker `char+0xcbc` |
| 5 | Trade `char+0xce0` |
| 6 | Other object inventory |
| 2 / default | Invalid for place (equip is separate) |

Evidence: `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md`, `systems/inventory-transfer.md`, `docs/inventory-cargo-wire-re.md` (locker case 3 + `FUN_00571620`).

---

## 7. Gaps / open

1. EAX this layout / callers.
2. ~~Precise Y encoding~~ → **sealed residual** (`pageH×pageIdx+cellY`; typeHost EDX).
3. Full 0x40 store packet identity vs other store opcodes.
4. Runtime cargo/locker multi-page drop round-trip.
5. Whether server requires `lQuantity@+0x1c` (client grid path does not write it).

**Verdict:** **accept-with-gaps.** Dual residual sealed Y/type; grid opcode/size/fields sealed for server parity on X/Y/type/COID. See `A_aa_00860a50_…_residual.md`.
