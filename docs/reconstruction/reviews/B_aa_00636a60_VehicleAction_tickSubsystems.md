# Review B (skeptical / adversarial): `aa_00636a60` VehicleAction_tickSubsystems

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636a60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00636a60_VehicleAction_tickSubsystems.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | this is VehicleAction | Falsified — framework |
| 2 | Writes thr/steer axes | Falsified — component tick only |
| 3 | Finished child type map | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Framework this-ptr contract | High | Crash on wrong ECX |
| 7-child tick fanout | High | Physics subsystems stall |
| Child slot map | Medium | Missed component |

---

## 3. Cross-check against raw

```
fw+8+=dt; vtbl+0x14(self+7 kids); vtbl+0x18.
Clean ≡ raw; child identities residual.
```

---

## 4. Surviving contract for AutoCore

```
tickSubsystems(framework, &dt):
  hkVehicleFramework subsystem tick; pair applyAction
  AutoCore vehicle physics tick critical
```

---

## 5. Open questions

1. Publish child offset table.
2. Consider rename to VehicleFramework_TickSubsystems.

**Verdict:** **accept-with-gaps**
