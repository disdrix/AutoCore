# Review B (skeptical / adversarial): `aa_004ff510` Vehicle_EquipWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff510` |
| **VA** | `0x004ff510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ff510_Vehicle_EquipWheelset.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Wheelset hardpoint is `+0x260` | **Falsified** | `+0x258` / 600 |
| 2 | This body is `Vehicle_SetWheelset` | **Falsified** | Wrapper; calls named SetWheelset |
| 3 | Always writes outPrev | **Falsified** | Requires out≠0, current≠0, `current+0xcc==0` |
| 4 | Same equip still updates COID | **Falsified** | Early return |
| 5 | Null equip leaves stale COID | **Falsified** | Writes −1/−1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper CF + SetWheelset call | **High** | Broken equip |
| COID `+0x628/+0x62c` | **High** | Net/UI id stale |
| `+0xcc` gate | **Tentative** | Missing previous item on unequip UI |
| Unhappy type on **old** item | **High** | Log only on outgoing type |

---

## 3. Cross-check spine

```
EquipWheelset(veh, ws, outPrev?):
  cur = veh[+0x258]
  if ws == cur && ws: log same; return
  if outPrev && cur && !cur[+0xcc]: *outPrev = cur
  if cur: typecheck cur; clear gfx; unbind
  SetWheelset(veh, ws)
  if ws: copy COID → +0x628/+0x62c else −1/−1
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.EquipWheelset(ws, outPrev?):
  same-ptr reject; optional previous; SetWheelset; mirror COID
  RecvInventoryEquip class 0x10
```

---

## 5. Open questions

1. `+0xcc` flag product name.
2. Overlap of unbind with SetWheelset internals.

**Verdict:** **accept-with-gaps**
