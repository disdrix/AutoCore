# Function record: Client_RecvInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_008151a0` |
| **Canonical name** | `Client_RecvInventoryAddItem` |
| **Address** | `0x008151a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Opcode (S2C)** | **`0x2047`** — via `Client_PacketDispatch` (not body immediate) |
| **Completion status** | **Human-refined clean C++** + dual residual 2026-07-29 — runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | A/B **accept-with-gaps**; residual scratch `reviews/a_008151a0.md` |

## Purpose

S2C add-item notify (`0x2047`): resolve object by COID, optional “Received Loot” log line, either **merge quantity** onto existing cargo stack or **re-find/full place**, refresh related UI. Does **not** consume server cargo X/Y from the packet body.

## Signature (decompiler-derived + prologue)

```c
// Retail shape: client on stack; packet base in EBX (not a second formal)
void Client_RecvInventoryAddItem(int client);
// EBX → packet (0x20 InventoryAddItem layout)
```

Prologue evidence (`read_memory` 2026-07-29): `sub esp,0x104`; loads `[ebx+8]`/`[ebx+0xc]`; stack formal used as client (`+0xe98`, `+0xf38`).

### Packet fields

| Offset | Wire | Body |
|-------:|------|------|
| `+0x08/+0x0c` | item COID lo/hi | **Used** — resolve + find + place |
| `+0x10/+0x11` | cargo X/Y | **Not read** by this function |
| `+0x12` | `bAddToExistingItem` | **Used** — merge vs re-find gate |
| `+0x14` | quantity | **Used** — loot `xN` + merge delta |
| `+0x18` | `bWasSuccessful` | **Used** — early return if 0 |

### `@+0x12` polarity (sealed)

- **Non-zero** + char + vehicle + `FUN_00571010` hit → `FUN_00571830` (**qty merge**)
- **Zero** or missing context or not in grid → `FUN_00945540` (**re-find / full place**)

Historical plate “skip place when non-zero” is **wrong**.

## Behavioral summary

1. `FUN_007a69d0`
2. `CVOGReaction_ResolveObjectTarget(1, coidLo, coidHi)` — null → return
3. Success `@+0x18` — zero → return
4. Optional loot line (`Broken:` bit19, `Received Loot`, channel `0x17`)
5. Optional loot UI `client+0xf38`
6. Place branch (Seal polarity above)
7. Optional `FUN_0089c6c0(1)` if inventory widget visible
8. `FUN_0092ce90` (`Client_RefreshMissionRelatedUi`)

## Key callees (roles)

| Addr | Role | Name status |
|------|------|-------------|
| `0x00571010` | Find cargo item by COID (`+0x160/+0x164`) | leave `FUN_*` |
| `0x00571830` | Stack quantity merge (`vtbl+0x25c/+0x260`) | leave `FUN_*` |
| `0x00945540` | Full loot place / free-slot / internal merge (`lootpickup`) | alias `Inv_lootpickup` |
| `0x00513e70` | Stack/loot eligibility probe | leave `FUN_*` |
| `0x0092ce90` | Mission-related UI refresh | role sealed prior residual |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature (stack client + EBX packet) | **High** (was Probable) |
| Control flow | High |
| Opcode binding | **High** (dispatch) |
| Naming | High |
| Side effects | High |
| Helper product names | Probable |
| Overall | **High CF / accept-with-gaps** — clean refined; runtime open |

## Open questions

- Runtime / differential / bit-exact
- Product name of log channel `0x17`
- Exact thiscall ECX / EDI handoffs into place helpers (decompiler residual)

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_008151a0_Client_RecvInventoryAddItem.md` |
| Annotated | `raw/aa_008151a0_Client_RecvInventoryAddItem.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryAddItem.cpp` |
| Dual A | `reviews/A_aa_008151a0_Client_RecvInventoryAddItem.md` |
| Dual B | `reviews/B_aa_008151a0_Client_RecvInventoryAddItem.md` |
| Residual | `reviews/a_008151a0.md` |
