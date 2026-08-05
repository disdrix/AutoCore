# Review B (skeptical / adversarial): `aa_004fbc10` VehicleEntity_PushDriveAxesToController

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbc10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen **pass 2** — live Ghidra; supersedes thin wave2 + pass-1 static) |
| **Counterpart** | `reviews/A_aa_004fbc10_VehicleEntity_PushDriveAxesToController.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present and strengthened** |
| **Verdict** | **accept-with-gaps** on thr/HB bridge + reverse ceiling + speed-cap polarity + layout + `FUN_004c4e20` body; **reject** overclaims that this unit writes steer, is player-only, is a finished bit-exact port, or that baseMax is fully named product-side |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Writes steer here (`entity+0x618` → controller) | **Falsified** — zero loads/stores of `+0x618`; steer ramps in `VehicleAction_applyAction` |
| 2 | Player-input only | **Falsified** — callers include MoveToTarget3DPoint, setDrivingInputs, SetDriveAxes, activation paths |
| 3 | Symmetric ±0.9 thr clamp | **Falsified** — only `if (0.9 <= thr) thr = 0.9` when `ctrl+0x19` |
| 4 | Speed gate is `\|v\| > maxSpeed` | **Falsified** — compare is `local_3c < entity+0x10c`; early `SQRT` is SSA-dead / slot reuse |
| 5 | Overspeed zeros “opposing” thr | **Falsified wording** — zeros thr that continues **travel** polarity; opposing thr left alone |
| 6 | `ctrl` is Havok `VehicleAction` | **Falsified layout** — `ctrl+0x24` is **u8 handbrake**; VA `+0x24` is **f32 steer stage-1** |
| 7 | Hard-stop still copies `entity+0x61c` | **Falsified** — early return after thr0/HB1 |
| 8 | Wave2 dual A/B “sealed” speed-cap | **Falsified as complete** — scaffold left residual; this dual supersedes |
| 9 | `FUN_004c4e20` body unknown / unreadable | **Falsified this pass** — body is 12-line leaf: `entity+0x1f4` ± optional `driver+0xd48` under `DAT_00b037d4` |
| 10 | Ready for bit-exact seal of full package | **Fail** — runtime, stack init, dual-flag interaction, product names open |
| 11 | Plate “≈0.9 reverse cap” implies reverse-only | **Overstated** — compare is positive ceiling; with Accel=−1 it mainly hits reverse/positive thr ≥ 0.9 |
| 12 | Outer bonus `+0xd48` and `FUN_004c4e20` `+0xd48` are the same single application | **Falsified as identity** — **two flags** (`af1854` outer multiply path vs `b037d4` base add); image defaults differ |

---

## 2. Decisive dataflow (raw ≡ live)

```
if entity+0x101 != 0 OR entity+0x1a0 == 0: return   // complete no-op

ctrl = *(entity+0x1a0) + 8
ctrl+0x25 = 0

if entity+0x109 != 0:
  ctrl+0x20 = 0
  ctrl+0x24 = 1
  return                       // NO +0x61c copy

ctrl+0x20 = entity+0x614
if ctrl+0x19:
  if DAT_00a0f734 (0.9) <= thr: thr = 0.9
  ctrl+0x20 = thr

// baseMax:
//   if wobj null / vfunc 0x1d8 fails → 0
//   else FUN_004c4e20(entity):
//        *(entity+0x1f4)  [+ optional *(driver+0xd48) if DAT_00b037d4]
// bonus (fStack_40; port init 0):
//   + driver+0xd48 if DAT_00af1854
//   − 0.3 overheat / + 0.5 boost flags
// local_3c = (bonus+1)*baseMax; clamp to AbsoluteTopSpeed unless −1

if local_3c < entity+0x10c:
  forward = extract(FUN_00404a20 / FUN_004e8a40)
  if dot(vel, forward) <= 0:
    b = (ctrl thr < 0)         // Accel polarity "toward travel" when going back/zero-ish
  else:
    b = (ctrl thr > 0)         // Reverse polarity "toward travel" when going forward
  if !b && thr != 0:
    ctrl+0x20 = 0              // zero thr that continues travel

ctrl+0x24 = entity+0x61c
```

Live re-decompile (2026-07-29 pass 2) matches 2026-07-23 raw body CF. Constants re-verified via `read_memory`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thr/HB offsets + gates | **High** | NPC/player no drive axes to controller |
| Steer deferred to applyAction | **High** | Wrong steer owner / double-write |
| Reverse ceiling 0.9 (positive-only) | **High** | Wrong reverse clamp / over-clamp Accel |
| Speed-cap operands (`local_3c` vs `+0x10c`) | **High** | Oscillation / never-cap / always-cap |
| Travel-polarity thr zero | **High CF** | Cut thr wrong direction at limit |
| Controller ≠ VehicleAction layout | **High** | Handbrake clobber steer ramp slot |
| `FUN_004c4e20` = `entity+0x1f4` (+ opt d48) | **High** | Wrong baseMax field |
| Bonus / AbsoluteTopSpeed structure | **High structure** | Wrong top speed under buffs |
| Dual-flag `af1854` vs `b037d4` interaction | **High CF structure; product open** | Double-count or miss d48 |
| `fStack_40` init | **Tentative** | Bonus bias if stack dirty |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x614 → ctrl+0x20` | Invented? | **No** — first thr store (live) |
| `+0x61c → ctrl+0x24` | Invented? | **No** — last store normal path |
| `+0x618` write | Hidden? | **None** |
| `+0x10c` as “\|v\| proxy” | Compatible? | **No** as compare operand name — entity field vs derived max |
| `+0x1f4` as baseMax core | Invented? | **No** — `FUN_004c4e20` loads `param_1+500` |
| `DAT_00a0f734` ≈ 0.9 | Guess? | **No** — LE bytes `66 66 66 3f` re-read |
| `DAT_00aaa668` = −1 | Guess? | **No** — `00 00 80 bf` |
| Symmetric clamp | Compatible with compare? | **No** |
| Hard-stop copies HB from entity | Compatible? | **No** — forces 1 |
| Outer `af1854` ≡ inner `b037d4` | Same gate? | **No** — distinct addresses; image `01` vs `00` |

---

## 5. Surviving contract for AutoCore

```
PushDriveAxesToController(entity):
  require entity+0x101==0 and entity+0x1a0!=0
  ctrl = *(entity+0x1a0)+8
  if hard-stop(+0x109): thr=0, HB=1; return
  thr = entity+0x614 → ctrl+0x20
  optional positive ceiling 0.9 when ctrl+0x19
  baseMax = entity+0x1f4  (+ driver+0xd48 if DAT_00b037d4) via FUN_004c4e20
            // or 0 if driver-obj resolve fails
  local_3c = (bonus+1)*baseMax; clamp AbsoluteTopSpeed unless −1
  if local_3c < entity+0x10c:
    zero thr that continues travel polarity (Accel=-1 / Reverse=+1)
  HB = entity+0x61c → ctrl+0x24
  // never write steer; pair with SetLongitudinal / SetHandbrake / MoveToTarget writers
```

**AutoCore NPC drive** must call this (or equivalent thr/HB push) after axis write — steer still requires applyAction / steer consumer path separately.

**Port caution:** treat `fStack_40` init as **0**; do not invent a single “speed bonus” flag for both `af1854` and `b037d4`.

---

## 6. Open questions

1. Product names for `entity+0x1f4` and driver `+0xd48`.
2. Live capture: thr zero at AbsoluteTopSpeed vs `+0x10c` mis-set.
3. Confirm stack init of bonus accumulator under real MSVC frames.
4. Live values of `DAT_00b037d4` / `DAT_00af1854` in retail sessions (image defaults may not match live).
5. `FUN_00404a20` this-arg at call site if ECX is not still entity.
6. Server-side analog of this bridge (if any) — out of this client unit.

**Verdict:** **accept-with-gaps**
