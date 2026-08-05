# Review B (skeptical / adversarial): `aa_0091d660` Client_Vehicle_AutoUnstickTiltKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091d660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0091d660_Client_Vehicle_AutoUnstickTiltKick_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `0091d460` edge hop | Cluster confusion | **Falsified** — this is **timer/tilt** continuous assist; sibling is edge ActionMap kick; scale **10** vs **12**; **3** RNG vs **2** |
| 2 | Writes thr/steer/HB entity axes | Invent | **Falsified** — physics apply + separate HB **list** action only |
| 3 | Is `ApplyImpulseVector` (`vtbl+0x50`) | Wrong slot | **Falsified** — `FUN_00404cb0` → **`+0x5c`** (sibling dual) |
| 4 | Thresholds are 0.7 airstab | Wrong const block | **Falsified** — **0.2 / 0.4** at `a0f70c` / `a0f720` |
| 5 | Fire only on time **or** only on count | Incomplete OR | **Falsified** — **either** count>3 **or** time>4.0 |
| 6 | `DAT_00afe2ac` is float | Type | **Falsified** — int **3** (`03000000`) compared to char/counter |
| 7 | `CVOGReaction_RandomUnitScalar` returns unit float alone | Name trap | **Falsified role** — returns RNG host; site maps u16 |
| 8 | `g_flOverheatCoolFrac` implies overheat system | Name trap | **Falsified semantics** — shared **0.3f** blend weight only |
| 9 | `DAT_00a110d8=10` is airstab re-ground Y here | Cross-system reuse | **Value yes, role different** — here **mass scale** for kick |
| 10 | Multiple callers | Graph | **Falsified** — **1** xref `0x00924669` |
| 11 | Product name sealed | No string | **Fail** — `_Inferred` |
| 12 | Ready for runtime seal | Matrix | **Fail** |

---

## 2. Decisive dataflow

```
vehicle = *(DAT_00d1b6d8+0x250)
if !vehicle: return
if vfunc(+0x198)!=0 || *(u8*)(vehicle+0x101): return

DAT_00d1f0c0 += dt
quat = physics? body+0x30 : fallback+0x94
FUN_004e8b60(quat, up4)          // up.y @ out[1]
t = (mode==2) ? 0.4f : 0.2f

if up.y >= t: clear bc/c4
else:
  maybe pulse c4 when slow && d1f0c0>0.2
  DAT_00d1f0bc += dt

if c4 > 3 || bc > 4.0:
  clear; 3×RNG → signed dir; norm
  s = (1/mass)*10
  vec = s*((0,1,0,0) + 0.3*unit_rand)
  FUN_00404cb0(&vec)
  HB 5000ms enqueue+start
```

Constants re-`read_memory` 2026-07-29. Live decompile ≡ raw.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tilt OR-timer fire | **High** | Never unsticks / spam kicks |
| 0.2/0.4 thresholds | **High** | Wrong tilt sensitivity |
| mass×10 + base +Y | **High** | Wrong impulse magnitude |
| Not drive-axis writer | **High** | Double thr |
| Distinct from `0091d460` | **High** | Merge wrong ports |
| Speed thresh numeric | **Open** | When pulses count |
| Product English | **Open** | UX label |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|---|---|---|
| up.y source | Wrong basis? | **No** — `FUN_004e8b60` out[1] = `1 - 2*(x²+z²)` style up.y |
| `DAT_00afe2ac` float 3.0? | Wrong | **No** — raw int 3 |
| Scale 12 like sibling? | Copy-paste | **No** — `a110d8=10` |
| Two RNG only? | Sibling bleed | **No** — three draws |
| HB entity `+0x61c`? | Stop pack bleed | **No** — list action 5s |

---

## 5. Surviving contract for AutoCore

```
AutoUnstickTiltKick(dt):
  // continuous client assist — not ActionMap edge kick (0091d460)
  track tilt via quat up.y vs 0.2 (or 0.4 special)
  fire when low-speed pulses > 3 OR tilted time > 4s
  apply mostly-up random physics vector, scale 10/mass, vtbl+0x5c
  start 5s heartbeat action on vehicle list
  // does not SetHandbrake/SetSteer/SetLongitudinal
```

**Verdict:** **accept-with-gaps** — adversarial residuals vs sibling kick, thresholds, OR fire, apply path, sole xref closed; speed-const numeric / product / runtime open.
