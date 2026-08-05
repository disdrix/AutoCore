# Function record: Client_UI_InventorySheet_RemoveByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fcc0` |
| **Canonical name** | `Client_UI_InventorySheet_RemoveByCoid` (**INFERRED**) |
| **Address** | `0x0085fcc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` (UI sheet) |
| **Completion status** | **Dual A/B accept-with-gaps** (2026-07-29) — ABI + sheet remove-by-COID sealed; vfunc product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0085fcc0`
- `Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0085fcc0`
- Wave label: inventory sheet remove helper

## Purpose

Remove one inventory-**sheet UI** entry by instance COID (`lo`,`hi`): hash-unlink widget from `sheet+0x570`, optional selection clear via `FUN_007fbb70`, sheet vtbl `+0xbc` detach, `sheet+0x500` count--. Does **not** mutate cargo/locker grids or send packets.

## Signature (bytes-sealed)

```c
// ESI = InventorySheetHost*
// stdcall 2 dwords; ret 8
void __stdcall Client_UI_InventorySheet_RemoveByCoid(
    uint32_t coidLo,
    uint32_t coidHi);
```

Thin wrapper `FUN_0085fd20` (`0x0085fd20`): **EAX = item\*** → push `item+0x164`, `item+0x160`; ESI must already be sheet.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0085fcc0_FUN_0085fcc0.md`
- Annotated: `docs/reconstruction/raw/aa_0085fcc0_FUN_0085fcc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0085fcc0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md`

## Callers / callees

| Direction | Address | Name / role |
|-----------|---------|-------------|
| Caller | `0x008c2940` | `UI_InventorySheet_RemoveItemByCoid` — ESI=`[ecx+0x580]` |
| Caller | `0x0085fd20` | thin item→COID wrapper |
| Caller | `0x00810670` | sell/loot UI path (`[host+0x5ac]`) |
| Callee | `0x00413a60` | COID hash remove + out widget |
| Callee | `0x007fbb70` | conditional selection clear (`DAT_00d1a840`) |
| Callee | vtbl | widget `+0x3ac`, sheet `+0xbc` |
| Twin | `0x008605b0` | sheet **add** helper (count++ / vtbl `+0xa8`) |

## Key offsets (sheet host)

| Offset | Role |
|-------:|------|
| `+0x570` | COID hash table* |
| `+0x500` | tracked UI item count |
| vtbl `+0xbc` | detach widget |

Item: `+0x160/+0x164` = COID lo/hi.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High / Confirmed** |
| ESI sheet + stdcall COID ABI | **Confirmed** |
| UI-only (no grid stamp) | **Confirmed** |
| Parameter semantic names (COID) | **High** (caller family) |
| Vfunc product names | **Probable / Tentative** |
