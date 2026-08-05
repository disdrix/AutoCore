# Function record: Client_RecvInventoryGrabResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **Canonical name** | `Client_RecvInventoryGrabResponse` |
| **Address** | `0x00811be0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual residual 2026-07-29; dispatch/ABI/fields/helpers sealed static; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C InventoryGrabResponse (`0x2035`; early-out `0x2039` shared slot). Whole-grab applies resolved item to cursor via inventory-type helper; stack-split peels qty, creates new stack with server COID, then applies new stack to cursor.

## Signature (register-based)

```c
// PacketDispatch: EAX = client, EBX = packet (Confirmed 2026-07-29)
// Declared cdecl formals unused.
void Client_RecvInventoryGrabResponse(void /* EAX client, EBX packet */);
```

## Packet fields (sealed)

| Offset | Field | Notes |
|-------:|-------|-------|
| `+0x00` | Opcode | `0x2035`; body early-outs `0x2039` |
| `+0x08` | Item TFID | Resolve gate |
| `+0x18` | InventoryType (u8) | Into `FUN_0093d6e0` DL — **decompiler omitted** |
| `+0x1c` | Count | Peel amount / cursor qty |
| `+0x20` | SplitFlag | `0` whole; nonzero split |
| `+0x28/+0x2c` | Split COID (split) | Bound onto new stack |
| `+0x38` | Success | Required for any success arm |

## Behavioral summary

1. Clear `client+0xb6`; `FUN_007a69d0` (string/ctx singleton).
2. If opcode `0x2039` → return.
3. Resolve TFID; require `success@+0x38`.
4. Whole: `Client_InventoryGrabApplyToCursor` (`FUN_0093d6e0`) on source + refresh.
5. Split: residual qty on source → `GiveItemByCbid` → `Object_SetCoidIdentity` (`FUN_00512160`) → init/qty/register/gfx → apply **new** to cursor + refresh.
6. Fail: ODS `"Grab Item failed: Failed on coid"` (no toast) + refresh; split-create fails toast + `FUN_007fc150`.

## Opcode binding

| Opcode | Role |
|---:|---|
| **`0x2035`** | Dispatch case → this function (**Confirmed** via PacketDispatch + xref `0x008159b0`) |
| **`0x2039`** | Shared case; body early-outs |

## Helper roles (residual)

| Addr | Proposed name | Role |
|------|---------------|------|
| `0x0093d6e0` | `Client_InventoryGrabApplyToCursor` | invType switch; grid remove if present; set qty; attach cursor |
| `0x00512160` | `Object_SetCoidIdentity` | thiscall: `+0x160/164` coid, `+0x168` flag |
| `0x007fc150` | (cursor clear UI) | Fail path held-item teardown — **not** `DAT_00d1a8f6` |
| `0x007a69d0` | (ctx singleton) | Returns `&DAT_00d1f660` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Register framing | **Confirmed** |
| Opcode dispatch | **Confirmed** |
| Control flow | High |
| Packet field map | **High** (static + asm) |
| Naming | High (function); helpers proposed |
| Side effects | High |
| Overall | Probable — residual sealed; runtime open |

## Open questions

- Runtime whole vs split captures
- Who clears `DAT_00d1a8f6` (not this body)
- PDB names for helpers
- AutoCore `AddToExistingItem` vs client SplitFlag naming at `+0x20`

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| Annotated | `raw/aa_00811be0_Client_RecvInventoryGrabResponse.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryGrabResponse.cpp` |
| Dual A | `reviews/A_aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| Dual B | `reviews/B_aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| Scratch | `tmp/a_00811be0.md` |
