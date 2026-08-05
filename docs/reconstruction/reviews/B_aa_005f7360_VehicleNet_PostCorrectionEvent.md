# Review B (skeptical / adversarial): `aa_005f7360` VehicleNet_PostCorrectionEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f7360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005f7360_VehicleNet_PostCorrectionEvent.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Immediately equips wheelset | Falsified — deferred queue only |
| 2 | Same as TriggerReplay buffer clone | Falsified — structured 0x203C/0x203E events |
| 3 | Only used on initial unpack | Falsified — hardpoint **delta** path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x203C/0x203E wire shape | High | Client equip race / null wheels |
| No immediate equip contract | High | Wrong fix for wheel race |
| Spatial +0x160.. copy | Medium | Misplaced hardpoint |

---

## 3. Cross-check against raw

```
if related unhappy:
  alloc wrapper; FUN_005a2120; push;
  malloc 0x40 *buf=0x203C (or 0x30/0x203E); fill; FUN_005b2d70; FUN_005a0b30.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
PostCorrectionEvent: deferred hardpoint correction only.
  AutoCore must not treat as sync equip; pair GhostVehicle unpack order.
```

---

## 5. Open questions

1. Diff equip packet synthesis vs InventoryEquipPacket server.
2. Trace FUN_005b2d70 drain timing vs pose apply.

**Verdict:** accept-with-gaps
