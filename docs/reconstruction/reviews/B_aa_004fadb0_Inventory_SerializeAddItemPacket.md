# Review B (skeptical / adversarial): `aa_004fadb0` Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fadb0_Inventory_SerializeAddItemPacket.md` |
| **Verdict** | **accept-with-gaps** on helpers; layout High |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | XY at packet+8 | Falsified — COID; XY at +0x10/+0x11 |
| 2 | Always new slot | Falsified — merge path |
| 3 | Opcode 0x203C equip | Falsified — 0x2047 add |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Layout COID/XY | High | Corrupt add item |
| Merge rules | High | Dup stacks / fail merge |
| +0x2b0 grid | High | Null crash |

---

## 3. Cross-check against raw

```
if !grid fail; try merge else free slot; fill 0x2047 fields; return wasAdded.
Clean ≡ raw; XY-not-at-+8 correction holds.
```

---

## 4. Surviving contract for AutoCore

```
SerializeAddItemPacket(veh, item, pkt):
  0x2047 cargo add; pair FindFreeSlot / PlaceItemFootprint
  AutoCore must match COID@+8 and XY@+0x10
```

---

## 5. Open questions

1. Golden packet capture.
2. Name quantity-compat helpers.

**Verdict:** **accept-with-gaps** on helpers; layout High
