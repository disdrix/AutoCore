# Review B (skeptical / adversarial): `aa_004fb660` Vehicle_createVehicleAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fb660_Vehicle_createVehicleAction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Can create multiple freely | Falsified — duplicate guard |
| 2 | No framework | Falsified — buildHavok call |
| 3 | UI action only | Falsified — physics action |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x1a0 layout | High | Broken vehicle sim |
| Framework build call | High | No physics |
| Duplicate path | High | Leak/double action |

---

## 3. Cross-check against raw

```
if existing action log; else alloc 0xC, build framework, ctor action.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
createVehicleAction(entity):
  action+framework nest; pair buildHavokVehicleFramework / TryActivatePhysics
  AutoCore physics spawn
```

---

## 5. Open questions

1. Name FUN_005fe020 / FUN_005fe5c0.
2. Document mode flags.

**Verdict:** **accept-with-gaps**
