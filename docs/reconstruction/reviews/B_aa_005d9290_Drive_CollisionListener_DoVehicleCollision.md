# Review B (skeptical / adversarial): `aa_005d9290` Drive_CollisionListener_DoVehicleCollision

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d9290_Drive_CollisionListener_DoVehicleCollision.md` |
| **Verdict** | **accept-with-gaps**; math residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Player steer input | Falsified — collision listener |
| 2 | No damage path possible | Overstated — side effects present |
| 3 | Finished formula | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Contact response entry | High | Miss crash events |
| Impulse math | Tentative | Wrong bounce/dmg |
| FUN damage vs FX split | Tentative | Desync |

---

## 3. Cross-check against raw

```
listener(pair, normal, impulse): compute response; call side-effect FUN*.
Clean ≡ raw outline; formula residual.
```

---

## 4. Surviving contract for AutoCore

```
DoVehicleCollision(...):
  crash response hook
  pair Physics_ApplyImpulseVector + combat damage
  AutoCore vehicle collision must match filters
```

---

## 5. Open questions

1. Seal damage vs impulse split.
2. Live collision capture.

**Verdict:** **accept-with-gaps**; math residual
