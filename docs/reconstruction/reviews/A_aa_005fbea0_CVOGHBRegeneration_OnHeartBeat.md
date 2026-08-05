# Review A (reconstruction fidelity): `aa_005fbea0` CVOGHBRegeneration_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbea0` |
| **VA** | `0x005fbea0` |
| **Canonical name** | `CVOGHBRegeneration_OnHeartBeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fbea0_CVOGHBRegeneration_OnHeartBeat.md` |
| **System** | `heartbeat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

One **combat-pool pulse**: resolve owner vehicle; HP += race-item regen; power += regen clamp max dirty **0x8000000**; heat cool with overheat frac dirty **0x20000000** (2-tick max debounce); shield regen after empty debounce dirty **0x4000000**; `RescheduleAfterFire`. **Full rates per pulse (no dt)**. Period from ctor 3000/5000 ms not 16. AutoCore `VehicleCombatPool.cs`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fbea0_CVOGHBRegeneration_OnHeartBeat.md` |
| Annotated | `docs/reconstruction/raw/aa_005fbea0_CVOGHBRegeneration_OnHeartBeat.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRegeneration_OnHeartBeat.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fbea0_CVOGHBRegeneration_OnHeartBeat.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Owner vehicle via pOwnerObject vcalls +0x1d4/+0x1d8` | **High** | Resolve |
| `HP regen from equipped race item` | **High** | Creature helper |
| `Power regen + clamp + PowerMask 0x8000000` | **High** | Body |
| `Heat: debounce at max; cool rate; overheat frac ~0.7; HeatMask` | **High** | Plate |
| `Shield: empty 2-tick debounce then regen; ShieldMask 0x4000000` | **High** | Plate |
| `RescheduleAfterFire at end` | **High** | Call |
| `No dt multiply — full rate per pulse` | **High** | Critical |
| `Period 3s/5s from ctor not TryFire 16` | **High** | Companion |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vehicle resolve | **Yes** |
| HP/power/heat/shield sequence | **Yes** |
| Dirty masks + reschedule | **Yes** |
| No invented dt scaling | **Yes** |

---

## 5. Gaps / open

1. Exact overheat cool fraction constant name.
2. Race 0/1/2 → 3000 else 5000 mapping in ctor sibling.
3. Firing flag interaction (bIsFiring).
4. Runtime pulse capture vs AutoCore pool.

**Verdict:** **accept-with-gaps**
