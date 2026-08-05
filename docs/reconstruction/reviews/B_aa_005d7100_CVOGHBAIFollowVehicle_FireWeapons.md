# Review B (skeptical / adversarial): `aa_005d7100` CVOGHBAIFollowVehicle_FireWeapons

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d7100_CVOGHBAIFollowVehicle_FireWeapons.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on angle thresholds |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only fires in combat state | **Falsified — geometry + may-fire only** |
| 2 | Ignores may-fire | **Falsified — param_2 gate** |
| 3 | Single omnidirectional fire | **Falsified — multi-arc mask** |
| 4 | Finished exact angles | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| may-fire polarity | High | Never shoot / always shoot |
| Arc masks | High | Wrong hardpoint fire |
| Target slot +0xa0 | High | Fire at nothing |

---

## 3. Cross-check against raw

```
if !mayFire: skip geometry;
target pos; self pose; angle deltas → front/turret/rear mask;
apply weapons.
Clean preserves CF; thresholds open.
```

---

## 4. Surviving contract for AutoCore

```
FireWeapons(followOrDriver, mayFire):
  if mayFire: compute arc fire masks from target geometry; fire allowed groups
  DoLogic always passes mayFire — idle drivers can still shoot
  Server weapon AI should not require drive state==combat
```

---

## 5. Open questions

1. Extract angle constants from raw/memory.
2. Map mask bits to weapon groups.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on angle thresholds
