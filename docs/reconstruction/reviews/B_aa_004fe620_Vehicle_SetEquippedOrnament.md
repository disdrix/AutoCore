# Review B (skeptical / adversarial): `aa_004fe620` Vehicle_SetEquippedOrnament

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe620` |
| **VA** | `0x004fe620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fe620_Vehicle_SetEquippedOrnament.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Armor hardpoint `+0x254` | **Falsified** | Store is `+0x26c` |
| 2 | Power plant type 10 | **Falsified** | Type **6** + subtype **10** ornament |
| 3 | Same-pointer early reject | **Falsified** | No same-equip log in this body |
| 4 | Read-only | **Falsified** | Full hardpoint mutator |
| 5 | Type mismatch aborts equip | **Falsified** | Logs unhappy type but still binds |
| 6 | Always unbinds previous visually | **Falsified** | `bSkipUnbind` skips `FUN_004fbb50` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot `+0x26c` + type 6/sub10 | **High** | Wrong equip class |
| Bind/unbind vfuncs | **High** | Detached graphics |
| Unhappy log non-fatal | **High** | Over-strict port |
| Transform block `+0x3bc` | **Tentative** | Visual glitches only |

---

## 3. Cross-check spine

```
SetEquippedOrnament(veh, item, outPrev?, skipUnbind):
  maybe *outPrev = veh[+0x26c]
  unbind old (optional visual clear)
  veh[+0x26c] = item
  if item: typecheck log; bind; notify; optional chassis vectors
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.SetEquippedOrnament(item, outPrev?, skipUnbind=false)
  hardpoint +0x26c; type 6 / ornament subtype 10
  pair RecvInventoryEquip class 6/sub10 + menu equip
```

---

## 5. Open questions

1. Residual FUN_* helpers.
2. Runtime unhappy-type frequency.

**Verdict:** **accept-with-gaps**
