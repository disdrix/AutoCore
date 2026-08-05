# Function record: Client_RecvInventoryDropResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **Canonical name** | `Client_RecvInventoryDropResponse` |
| **Address** | `0x00813730` |
| **Body range** | `0x00813730` – `0x00813bd2` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual residual 2026-07-29; opcode + register ABI Confirmed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C InventoryDropResponse (`0x2037`; early-out `0x203b` shared slot). Bind grid by `inventoryType@+0x1A`; place, swap, or concatenate per `swapFlag@+0x23` / concat`@+0x38`.

## Signature (decompiler-derived + sealed registers)

```c
void Client_RecvInventoryDropResponse(void); // EAX=client, EBX=packet (Confirmed)
```

| Register | Role | Seal |
|---|---|---|
| **EAX** | client context | **Confirmed** — call site `MOV EAX,EBP`; prologue `MOV ESI,EAX` |
| **EBX** | packet base | **Confirmed** — call site `MOV EBX,ESI`; prologue `CMP [EBX],0x203b` / `@+0x22` |
| Portable formals | unused void | **Tentative** (same class as GrabResponse) |

Types: 1 cargo (`vehicle+0x2b0`), 3 locker (`char+0xcbc`), 5/6 trade sides.

## Behavioral summary

Fail toast on `success@+0x22==0`; invalid grid toast; place via `PlaceItemFootprint` at locX/Y when not already there; swap/concat branches; optional UI page refresh. Server success does not guarantee client place success.

## Opcode binding

| Opcode | Role |
|---:|---|
| **`0x2037`** | Dispatch case → this function (**Confirmed** via `Client_PacketDispatch` live re-decompile + sole xref `0x008159c2`) |
| **`0x203b`** | Shared case; body early-outs (**Confirmed** bytes `CMP [EBX],0x203B`) |

Body does not positive-compare `0x2037` (dispatch-selected).

## Callers

| Site | Context |
|---|---|
| `0x008159c2` in `Client_PacketDispatch` | **Sole** xref; immediately preceded by `MOV EBX,ESI; MOV EAX,EBP` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High / Confirmed (`0x00813730`–`0x00813bd2`) |
| Signature (registers) | **Confirmed** (EAX/EBX) |
| Signature (portable formals) | Tentative |
| Control flow | High |
| Opcode dispatch | **Confirmed** (2026-07-29 residual) |
| Naming | High |
| Side effects | High |
| Base packet fields | High (body + PACKET STRUCTURES + AutoCore Write) |
| Swap/concat depth | Probable |
| Overall | Probable — clean refined; residual gaps remain |

## Sealed facts (dual residual 2026-07-29)

1. Dispatch `0x2037`/`0x203b` → this VA (sole call `0x008159c2`).
2. Register ABI EAX=client, EBX=packet (call site + prologue `read_memory`).
3. Early-out opcode `0x203b` and success gate `@+0x22` byte-confirmed.
4. Live body decompile ≡ raw capture.
5. Non-swap place can still fail after server success (toast path).

## Open questions

- Full trade type-6 ownership / concat qty accounting
- Place thiscall grid ECX recovery at both `FUN_00571620` call sites
- AutoCore Write omits occupant `@+0x28` / concat `@+0x38` (needed for stack-merge parity)
- Runtime / differential
- Product names for busy/cursor/UI helper FUN_* chain

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00813730_Client_RecvInventoryDropResponse.md` |
| Annotated | `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryDropResponse.cpp` |
| Dual A | `reviews/A_aa_00813730_Client_RecvInventoryDropResponse.md` |
| Dual B | `reviews/B_aa_00813730_Client_RecvInventoryDropResponse.md` |
| Prior dual | `reviews/aa_00813730_reconstruction_review.md`, `reviews/aa_00813730_skeptical_review.md` |
| Scratch | `tmp/a_00813730.md` |
