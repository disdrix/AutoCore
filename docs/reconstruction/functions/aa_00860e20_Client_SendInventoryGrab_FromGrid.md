# Function record: Client_SendInventoryGrab_FromGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **Canonical name** | `Client_SendInventoryGrab_FromGrid` |
| **Address** | `0x00860e20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual residual pack/split strengthened 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | A: **accept-with-gaps** · B: **accept-with-gaps** (pack/CF/ABI; runtime open) |

## Purpose

C2S InventoryGrab (`0x2034`, size `0x20`) from a grid UI window. Optionally refreshes selection UI; gates on busy `DAT_00d1a8f6`. Packs item TFID, source inventory type, and grab quantity (whole stack or partial-split request). Does **not** apply cursor/split — that is S2C GrabResponse.

## Signature (decompile + call-site residual)

```c
// Stack args + EDI selection host (register)
uint32_t Client_SendInventoryGrab_FromGrid(UIWindow* invWindow, uint32_t quantity);
// EDI: selection host — GetObject @ vtbl+0x3ac → item with TFID +0x160/+0x164/+0x168
// Returns: always 1 (including busy-skip — not "sent OK")
```

Call xrefs (UNCONDITIONAL_CALL): `0x0083e677`, `0x00861a98`, `0x00861b3c`.

| Arg | Source (call sites) | Confidence |
|---|---|---|
| `invWindow` | PUSH window ptr; type at `*(+0x56c)+4` | **High** |
| `quantity` | GetQty vfunc `+0x25c` or field `+0x4fc` | **High** |
| EDI host | `MOV EDI, EBX/ESI` before CALL | **High** |

## Packet pack (written fields sealed)

| Off | Field | Source |
|---:|---|---|
| `+0x00` | opcode `0x2034` | literal |
| `+0x04` | *(unwritten)* | stack garbage — **not** txn id from this builder |
| `+0x08/+0x0c` | item COID lo/hi | object `+0x160/+0x164` |
| `+0x10` | TFID global byte | object `+0x168` |
| `+0x11..+0x17` | pad | unwritten |
| `+0x18` | `ucTypeFrom` | `window+0x56c→+4` |
| `+0x19..+0x1b` | pad | unwritten |
| `+0x1c` | `lQuantity` | `param_2` (whole or split request count) |

Send: sector connection vtable `+0x18`, channel `-1`, size `0x20`. Busy: set `DAT_00d1b4b0=1`, `DAT_00d1a8f6=1`.

### Pack vs Hardpoint sibling (`0x00862d90`)

Hardpoint forces `ucTypeFrom=2`, does **not** write `+0x1c`, uses `Client_SendSectorPacket(&DAT_00d1a840, 0x20, buf)`.

### Split handoff

| Stage | Unit |
|---|---|
| Pack request qty | **this function** (`+0x1c`) |
| Server decides whole vs split | sector |
| Peel / cursor / SplitCoid | `Client_RecvInventoryGrabResponse` `aa_00811be0` |
| Place | Drop / DropResponse |

## Behavioral summary

Optional UI pre-clear if selection matches tracked widget → `FUN_007fbbb0` → if not busy, pack/send `0x2034`, set busy → return 1 always.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature (stack + EDI) | **High** (call-site residual) |
| Control flow | High |
| Opcode/size | **Confirmed** |
| Packet written fields | **Confirmed** |
| Quantity = split/whole request | **High** |
| Naming | High |
| Side effects | High (net + globals) |
| Runtime / bit-exact | Open |
| Overall | **Probable / accept-with-gaps** — pack sealed; runtime open |

## Open questions

1. Parent names for three call xrefs (addresses not in named functions in DB).
2. Runtime grab / partial-split capture.
3. Who clears `DAT_00d1a8f6`.
4. Pre-clear (`DAT_00d1d8dc`) purpose.
5. Connection global identity vs Hardpoint send helper.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| Annotated | `raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.annotated.md` |
| Clean | `reconstructed-exact/Client_SendInventoryGrab_FromGrid.cpp` |
| Dual A | `reviews/A_aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| Dual B | `reviews/B_aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| Prior dual | `reviews/aa_00860e20_reconstruction_review.md`, `aa_00860e20_skeptical_review.md` |
| GrabResponse peer | `functions` / dual for `aa_00811be0` |
| DropResponse switch | `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md` |
