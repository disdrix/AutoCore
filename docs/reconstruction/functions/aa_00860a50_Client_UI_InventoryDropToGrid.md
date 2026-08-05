# Function record: Client_UI_InventoryDropToGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **Canonical name** | `Client_UI_InventoryDropToGrid` |
| **Address** | `0x00860a50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual residual 2026-07-29 **sealed** (Y formula + ucTypeTo); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

UI drop validator + C2S send: normal grid drop (`0x2036` / size `0x20`) or store-sell (`0x2027` / size `0x40`). Trade rejects customized / non-tradable. Does not place footprint.

## Signature (decompiler-derived)

```c
uint32_t Client_UI_InventoryDropToGrid(void); // client/window this in EAX/ESI
```

Type gate: class-4 blocked when target ∉{1,3}; 5 trade checks; 4 store path. Not an exclusive allow-list of only 1/3.

## Behavioral summary

Resolve drop coords → type gates → busy soft-success → build packet → `Client_SendSectorPacket` → set busy / return 1; failures toast + return 0.

### Grid packet written fields (decompile + pack-site asm 2026-07-29)

| Off | Field | Source |
|---:|---|---|
| `+0x00` | opcode `0x2036` | `mov dword …, 0x00002036` |
| `+0x04` | *(unwritten)* | — |
| `+0x08/+0x0c` | item COID | held `+0x160/+0x164` |
| `+0x10` | item global | held `+0x168` |
| `+0x18` | **locX** | `FUN_0085f220` out (`local_106`) |
| `+0x19` | **locY** | **`pageH * pageIdx + cellY`** (sealed) |
| `+0x1a` | **ucTypeTo** | `*(typeHost+4)` (sealed; EDX live) |
| `+0x1c` | *(not written)* | no `lQuantity` on grid path |

**Y formula (asm-sealed):**

```text
typeHost = *(window + 0x56c)
pageH    = FUN_0085f1d0(window) = typeHost ? *(typeHost+0x1c) : 0
pageIdx  = *(i8*)(window + 0x564)   // dword index 0x159
cellY    = hit-test Y (local_105)
wireY    = (i8)(pageH * pageIdx + cellY)
```

**ucTypeTo:** pack prelude `mov edx,[esi+0x56c]`; grid fallthrough; `mov dl,[edx+4]` → `+0x1a` (same host as Grab type-from / type gates).

Destination place: DropResponse `aa_00813730` switch on `inventoryType@+0x1a`.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | Probable (EAX/ESI this) |
| Control flow | High |
| Opcode/size (grid) | **Confirmed** |
| Packet X / COID / global | **Confirmed** / High |
| Packet Y formula | **High** (asm; was Tentative) |
| Packet type@+0x1a | **Confirmed** (asm) |
| Naming | High (dual-opcode caveat) |
| Side effects | High |
| Overall | Probable — dual residual sealed; runtime open |

## Open questions

- Runtime multi-page (pageIdx≠0) round-trip
- Full 0x40 store layout
- typeHost object English vs InventoryGrid identity (offset use sealed)
- Callers / portable signature

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| Annotated | `raw/aa_00860a50_Client_UI_InventoryDropToGrid.annotated.md` |
| Clean | `reconstructed-exact/Client_UI_InventoryDropToGrid.cpp` |
| Dual A | `reviews/A_aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| Dual B | `reviews/B_aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| Residual A | `reviews/A_aa_00860a50_Client_UI_InventoryDropToGrid_residual.md` |
| Residual B | `reviews/B_aa_00860a50_Client_UI_InventoryDropToGrid_residual.md` |
| DropResponse switch | `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md` |
