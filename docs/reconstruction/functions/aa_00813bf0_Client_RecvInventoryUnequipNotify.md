# Function record: Client_RecvInventoryUnequipNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813bf0` |
| **Canonical name** | `Client_RecvInventoryUnequipNotify` |
| **Address** | `0x00813bf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined + dual residual sealed** (2026-07-29) — runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C InventoryUnequip (`0x203E`, size `0x30`). Local: place unequipped item by invType (cargo/locker) or UI helper. Non-local: clear hardpoints by clonebase class (ornament / power plant / melee / weapon / wheelset / armor).

## Signature

```c
void Client_RecvInventoryUnequipNotify(int pClient, int pPacket /* in_EAX */);
```

## Dual residual (2026-07-29)

| Residual | Status |
|---|---|
| C2S/S2C demux of bidirectional `0x203E` | **Sealed High** — `PacketDispatch` case vs `SendInventoryUnequip` / `SendSectorPacket` |
| Non-local hardpoint class map | **Sealed High** — see scratch |
| Runtime | Open |

Scratch: `docs/reconstruction/reviews/a_00813bf0.md`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00813bf0_Client_RecvInventoryUnequipNotify.md`
- Annotated: `docs/reconstruction/raw/aa_00813bf0_Client_RecvInventoryUnequipNotify.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvInventoryUnequipNotify.cpp`
- Dual A/B: `reviews/A_aa_00813bf0_…`, `reviews/B_aa_00813bf0_…`

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| invType switch 0/1/2/3 | High |
| C2S vs S2C demux (directional) | **High** |
| Non-local class → slot clear map | **High** |
