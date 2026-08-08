# Function record: Client_RecvOpenAvailableGadgetResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080d570` |
| **Canonical name** | `Client_RecvOpenAvailableGadgetResponse` |
| **Ghidra name** | `FUN_0080d570` |
| **Address** | `0x0080d570` |
| **Body** | `0x0080d570`–`0x0080d915` (933 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-08-04 (WQ8R-G) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** (`A_` / `B_`) |

## Alias

- `FUN_0080d570`
- Dispatch label: **OpenAvailableGadgetResponse**
- Scaffold: `Inv_BUG_Item_to_tinker_not_found_Server_thinks_it_wo_0080d570`
- Descriptive: `Client_RecvTinkerOpenSlotResponse`

## Purpose

S2C handler for **opcode `0x20A8`**: apply client-side result of opening a gadget slot on an inventory item with a tinkering kit — resolve item (cargo→locker) + kit, success (increment open slots + toast/SFX) or fail (reason enum + optional catastrophic item destroy), then attempt kit consume and refresh inventory/mission UI.

## Signature (byte-sealed 2026-08-04)

```c
// stack packet*; RET 4; ClientContext* in ESI (dispatch ABI)
void Client_RecvOpenAvailableGadgetResponse(void* packet);
```

## Wire

| Field | Value |
|------:|-------|
| Opcode | **`0x20A8`** |
| Sole caller | `Client_PacketDispatch` @ `0x00815d1e` |

## Packet fields (body-used)

| Off | Role |
|----:|------|
| `+0x10/+0x14` | Item COID |
| `+0x18/+0x1c` | Kit object id |
| `+0x28` | Fail reason (1–4) |
| `+0x2c` | Success flag |
| `+0x2d` | Catastrophic (case 4) |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** |
| Opcode / sole caller | **Confirmed** |
| Dual-grid find (cargo/locker) | **Confirmed** (asm this) |
| Fail reason enum + strings | **High** |
| Success open-slot increment | **High** (vtbl+0x8c/+0x90) |
| Kit cast vtbl+0x200 | **High** |
| Kit final remove host MI expression | Probable / residual |
| sprintf vararg packing | Tentative (decomp truncated) |
| Runtime / bit-exact | Open |

## Open questions

- Full packet layout / size
- Exact kit-inventory host for post-path RemoveItem
- Server authority vs client-only presentation for open-slot counter

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.md`
- Annotated: `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvOpenAvailableGadgetResponse.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0080d570.cpp`
- Function (Ghidra): `docs/reconstruction/functions/aa_0080d570_FUN_0080d570.md`
- Reviews: `A_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md`, `B_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md`
