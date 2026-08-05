# Review B (skeptical / adversarial): `aa_00501420` Vehicle_TryActivatePhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_00501420` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00501420_Vehicle_TryActivatePhysics.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always succeeds | Falsified — multi gate CF |
| 2 | UI-only | Falsified — physics activate |
| 3 | Finished param map | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Activation gate CF | High | Ghost vehicle never sim |
| Success path body activate | High | Crash / null body |
| Param roles | Tentative | Wrong pose on spawn |

---

## 3. Cross-check against raw

```
try activate physics: early-outs; on success build/wire body+action.
Clean outline ≡ raw; internals partial name.
```

---

## 4. Surviving contract for AutoCore

```
TryActivatePhysics(veh, …) → status:
  physics enter gate; pair ActivateEnterWorld / createVehicleAction
  AutoCore: spawn/activate must mirror retail gates
```

---

## 5. Open questions

1. Decompile param_2–4 with xrefs.
2. Live A/B activate failures.

**Verdict:** **accept-with-gaps**
