# Review B (skeptical / adversarial): `aa_005fbdb0` CVOGHBRegeneration_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbdb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fbdb0_CVOGHBRegeneration_ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; **High** 3s/5s + -1000 contract; layout dual-field residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Period is 16ms | **Falsified — 3000/5000** |
| 2 | No race map | **Falsified — H/B/T 3s else 5s** |
| 3 | Skips AttachOwner | **Falsified — always attach** |
| 4 | Sets only +0x0C period | **Falsified — also +0x08 pulse ms** |
| 5 | Finished TryFire field unification | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3s/5s race map | High | Regen spam or starvation |
| -1000 sentinel pair | High | Reschedule/TryFire wrong |
| +0x08 pulse period | High | UI remaining / schedule |
| Debounce zero | High | Instant heat/shield edge |
| Layout +0x08 vs +0x0C | Tentative | Port to wrong field |

---

## 3. Cross-check against raw

```
Base_ctor; regenVtbl; clear +0x24..; resolve creature;
SetPeriodAndCounter(-1000,true);
+0x08 = override or race?3000:5000;
AttachOwnerObject(vehicle).
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Regeneration_ctor:
  combat-pool HB; period 3000ms races H/B/T else 5000; override wins if nonzero
  SetPeriodAndCounter(-1000,true) for sentinel/counter; pulse ms at +0x08
  NOT g_dwTimedActionDefaultPeriodMs (16)
  pair OnHeartBeat no-dt full-rate pulse; AutoCore VehicleCombatPool.cs must match
  AttachOwner required before list Enqueue/Start
```

---

## 5. Open questions

1. Unify HB layout docs (+0x08 pulse vs +0x0C sentinel).
2. Cross-check VehicleCombatPool.cs constants.
3. Seal Object_GetRootRaceId race enum.
4. Live capture period per race.

**Verdict:** **accept-with-gaps** on CF; **High** 3s/5s + -1000 contract; layout dual-field residual
