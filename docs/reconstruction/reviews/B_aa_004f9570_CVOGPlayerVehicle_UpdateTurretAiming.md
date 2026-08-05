# Review B (skeptical / adversarial): `CVOGPlayerVehicle_UpdateTurretAiming` @ `0x004f9570`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f9570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f9570_CVOGPlayerVehicle_UpdateTurretAiming.md` |
| **Verdict** | **accept-with-gaps**; **needs-more-evidence** on aim math |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server-authoritative hit cone | Falsified for role — local turret update |
| 2 | Works with only one of +0x340/+0x344 | Falsified — both required in primary path |
| 3 | No multi-kill influence | Falsified — blend global used |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual turret handles +0x340/+0x344 | High | No aim |
| Vehicle xform sample | High | World aim wrong |
| Aim limit math | Tentative | Clamp wrong |
| Network sync | Tentative | Desync |

---

## 3. Cross-check against raw

```
Early mode/null gates; sample vehicle basis; apply to turret
objects via vtbl; optional multikill blend. Large open math.
```

---

## 4. Surviving contract for AutoCore

```
UpdateTurretAiming(playerVeh):
  if !turretA(+0x340) or !turretB(+0x344): return
  sample veh orientation; push aim to turret components
  client-local; seal math before porting
```

---

## 5. Open questions

1. Recover pitch/yaw formulas from decompile.
2. Name +0x340/+0x344 component types.

**Verdict:** **accept-with-gaps**; **needs-more-evidence** on aim math
