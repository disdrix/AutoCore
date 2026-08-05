# Review B (skeptical / adversarial): `aa_00505270` Vehicle_applyCreatePacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00505270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00505270_Vehicle_applyCreatePacket.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime equip UI only | Falsified — create packet apply |
| 2 | Finished offset table | Overstated |
| 3 | Ignores hardpoints | Falsified — multi path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Packet→entity field map | High | Corrupt create state |
| Flag bytes +0x151/+0x152 | High | Wrong vehicle flags |
| Absolute vs relative bases | Tentative | Offset bugs |

---

## 3. Cross-check against raw

```
apply create pkt fields; nested resolve hardpoints/state.
Clean CF ≡ raw; absolute map incomplete.
```

---

## 4. Surviving contract for AutoCore

```
applyCreatePacket(veh, pkt, …):
  create-time field apply; pair EquipFromCreate / ActivateEnterWorld
  AutoCore CreateVehicle path critical
```

---

## 5. Open questions

1. Emit sealed pkt offset table.
2. Diff ghost create vs local create.

**Verdict:** **accept-with-gaps**
