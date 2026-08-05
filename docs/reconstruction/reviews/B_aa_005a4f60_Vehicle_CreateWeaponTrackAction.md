# Review B (skeptical / adversarial): `aa_005a4f60` Vehicle_CreateWeaponTrackAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005a4f60_Vehicle_CreateWeaponTrackAction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Combat pool regen action | Falsified — weapon track |
| 2 | Period 3000 ms | Falsified — 30 ms |
| 3 | Finished tick body | Overstated — ctor only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 30 ms period | High | Weapon track rate |
| Owner attach | High | Orphan HB |
| Tick body elsewhere | Tentative | Missing track logic |

---

## 3. Cross-check against raw

```
HBBase ctor; period 30ms; attach owner; optional weapon helper.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
CreateWeaponTrackAction(hb, veh):
  30ms weapon track HB; pair ActivateEnterWorld
  AutoCore vehicle combat tracking
```

---

## 5. Open questions

1. Find tick vfunc for type 4 HB.
2. Live interval confirm.

**Verdict:** **accept-with-gaps**
