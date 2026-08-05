# Function record: Client_RecvInventoryEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **Canonical name** | `Client_RecvInventoryEquip` |
| **Address** | `0x00813f40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean + dual review (accept-with-gaps)** — dual-path class map + wheelset sealed static 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C InventoryEquip (`0x203C`, size `0x40`). Local-player path: putInHand or cargo pull → **`FUN_00502e90` vehicle equip** + UI. Non-local: hardpoint equip by object class (ornament, plant, weapon, **wheelset**, armor).

## Signature (decompiler-derived)

```c
void Client_RecvInventoryEquip(void* pPacket, int pClient /* in_EAX */);
```

Call site `0x0081597c` (`Client_PacketDispatch`): `PUSH ESI` (packet), `MOV EAX,EBP` (client), `CALL`.  
Image @ `0x00815979`: `56 8b c5 e8 bf e5 ff ff`.  
Entry saves client: prologue uses `MOV ESI,EAX` (`8b f0` after pushes).

**Sole xref:** `From 0081597c in Client_PacketDispatch [UNCONDITIONAL_CALL]`.

Fields: item TFID`@+8`, global flag`@+0x10`, vehicle`@+0x18`, realm`@+0x20`, oldItem`@+0x28`, putInHand`@+0x38`, srcX/Y`@+0x39/+0x3A`, invTypeFrom`@+0x3B`.

## Behavioral summary

Resolve vehicle → owner check vs `client+0xe98` → local hand/grid + `FUN_00502e90` equip + UI; else class switch `6/10/0xc/0x10/0x1c` equip helpers (class 10 → `Vehicle_EquipPowerPlant`; **class 0x10 → `FUN_004ff510` → `Vehicle_SetWheelset`**).

## Dual-path hardpoint class map (sealed 2026-07-29)

| Class | Helper | Vehicle slot / named | Evidence |
|---:|---|---|---|
| 6 / subtype 10 | `FUN_004fe620` | `+0x26c` ornament | `"Set ornament of unhappy type…"` |
| 6 / subtype 0xb | `Vehicle_SetEquippedRaceItem` | race item | **local `FUN_00502e90` only** |
| 10 | `Vehicle_EquipPowerPlant` | plant | named + RTTI `CVOGPowerPlant` |
| 0xc / subtype 9 | `FUN_004fe800` | `+0x264` melee | `"Set weapon melee of unhappy type…"` |
| 0xc other | `FUN_004fe110` → `Vehicle_AttachWeapon` | `+0x260` | `"Tried to equip same weapon %d"` |
| **0x10** | **`FUN_004ff510` → `Vehicle_SetWheelset`** | **`+0x258` (600)** | `"Tried to equip same wheelset %d"` |
| 0x1c | `FUN_00502180` → `Vehicle_SetEquippedArmor` | `+0x254` | `"Tried to equip same armor %d"` |

Local path also plays `menu_equip_{item,powerplant,weapon,wheelset,armor}` and applies NetObject mask bits; non-local applies visual scale `1.0f` prep and destroys previous-out via `FUN_009440e0`.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature (EAX client + stack packet) | High / Confirmed (call-site + prologue) |
| Control flow | High |
| Packet offsets | High |
| Dual-path hardpoint class map | High / Confirmed (strings + named callees + slot stores) |
| Side effects | High |
| Overall | High CF / Probable product names — dual residual 2026-07-29; runtime open |

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| Reconstruction A | `reviews/A_aa_00813f40_Client_RecvInventoryEquip.md` | accept-with-gaps |
| Skeptical B | `reviews/B_aa_00813f40_Client_RecvInventoryEquip.md` | accept-with-gaps |
| Prior reconstruction | `reviews/aa_00813f40_reconstruction_review.md` | accept-with-gaps (pre-residual) |
| Prior skeptical | `reviews/aa_00813f40_skeptical_review.md` | needs-more-evidence (**superseded** on class map/local equip/wheelset) |

## Open questions

- Optional product renames for sealed FUN_* helpers  
- Runtime / differential  
- Ghost PostCorrection equip synthesis (sibling)

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00813f40_Client_RecvInventoryEquip.md` |
| Annotated | `raw/aa_00813f40_Client_RecvInventoryEquip.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryEquip.cpp` |
| Scratch | `tmp/a_00813f40.md` |
