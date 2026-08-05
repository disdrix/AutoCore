# Review A (reconstruction fidelity): `aa_005fbdb0` CVOGHBRegeneration_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbdb0` |
| **VA** | `0x005fbdb0` |
| **Canonical name** | `CVOGHBRegeneration_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fbdb0_CVOGHBRegeneration_ctor.md` |
| **System** | `heartbeat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct combat-pool regen HB (size ~0x28): SEH frame; `CVOGHBBase_ctor`; install `g_pVtbl_VehicleCombatPoolAction`; clear debounce bytes **+0x24..+0x26**; resolve creature via vehicle vtbl **+0x1d4 / +0x1d8** (+ optional RTDynamicCast to Creature); `SetPeriodAndCounter(-1000, true)`; set **+0x08** period = override or race map **Human/Biomek/Tribe → 3000** else **5000** when override==0 and creature ok; `AttachOwnerObject(vehicle)`. **Not 16ms** — 16 is Remove status. Pairs with OnHeartBeat no-dt pulse dual.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fbdb0_CVOGHBRegeneration_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_005fbdb0_CVOGHBRegeneration_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRegeneration_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fbdb0_CVOGHBRegeneration_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Base_ctor then regen vtbl` | **High** | Body |
| `Clear +0x24/+0x25/+0x26 debounce` | **High** | Heat/shield pads |
| `Vehicle vtbl+0x1d4 / +0x1d8 resolve` | **High** | Same as OnHeartBeat |
| `SetPeriodAndCounter(-1000,true)` | **High** | Sentinel + counter |
| `+0x08 = override or 3000/5000 by race` | **High** | Critical period map |
| `Race 0/1/2 (Human/Biomek/Tribe) → 3000 else 5000` | **High** | Plate + body |
| `AttachOwnerObject(vehicle)` | **High** | End |
| `nPeriodOverrideMs==0 triggers race pick` | **High** | Branch |
| `Size ~0x28 class` | **Probable** | Plate |
| `Caller Vehicle_EnsureRegenerationHeartbeat` | **High** | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + base + vtbl + debounce | **Yes** |
| Resolve + sentinel + period + attach | **Yes** |
| No invented dt / 16ms period | **Yes** |

---

## 5. Gaps / open

1. Exact RACE_* enum values vs Object_GetRootRaceId.
2. Why -1000 at +0x0C while pulse period at +0x08 (layout dual-field).
3. TryFire interaction: which field is nPeriodMs for elapsed vs sentinel.
4. Override non-zero path (custom period) call sites.

**Verdict:** **accept-with-gaps**
