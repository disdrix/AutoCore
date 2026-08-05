# Review B (skeptical / adversarial): `aa_00503f30` Vehicle_ActivateEnterWorld

| Field | Value |
|---|---|
| **Stable ID** | `aa_00503f30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00503f30_Vehicle_ActivateEnterWorld.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only resets graphics | Falsified — HB + combat pools |
| 2 | Combat pool is 30 ms | Falsified — 30 ms is weapon track |
| 3 | No heat/shield touch | Falsified — zeros heat fills shield |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HB creation order | High | Missing regen / weapon track |
| Heat/shield enter reset | High | Spawn with wrong pools |
| Race→period map | Tentative | Wrong tick rate |

---

## 3. Cross-check against raw

```
if owner: clear flag; create token+weaponTrack+combatPool HBs; reset heat/shield.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
ActivateEnterWorld(veh):
  enter-world HB nest + pool reset; pair CreateWeaponTrackAction / EnsureRegenerationHeartbeat
  AutoCore vehicle enter-world critical
```

---

## 5. Open questions

1. Document TimedAction token purpose.
2. Confirm 3s vs 5s race indices.

**Verdict:** **accept-with-gaps**
