# Review B (skeptical / adversarial): `aa_00915670` Client_Vehicle_EngageHbAndPushAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00915670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_00915670_Client_Vehicle_EngageHbAndPushAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Also writes thr/steer (`+0x614/+0x618`) | Would invent axis pack | **Falsified** — only HB via setter; then Push copies entity state |
| 2 | Ungated always runs | Overfit | **Falsified** — needs game + vehicle + `+0x101==0` |
| 3 | `FUN_004f3700` does real work | Prior unknown | **Falsified** — sealed empty `ret` (sibling dual) |
| 4 | `SetHandbrake` is gated like steer | Wrong sibling | **Falsified** — this site always pushes `1`; setter body itself ungated |
| 5 | Multiple independent callers | Incomplete graph | **Falsified for count** — **1** xref `0x00927e48` |
| 6 | `unaff_EDI` is vehicle | Wrong host | **Falsified** — vehicle is `ESI` from `DAT+0x250`; EDI gets `+0xa31` client latches |
| 7 | Always stops heartbeat | Optional path | **Falsified** — `FUN_005081d0` only if `DAT_00d1a860==0` and host flag clear |
| 8 | Product name sealed | No string | **Fail** — `_Inferred` only |
| 9 | Ready for runtime seal | Matrix | **Fail** — deferred |

---

## 2. Decisive dataflow

```
EAX = DAT_00d1b6d8
if !EAX: return
ESI = *(EAX + 0x250)          // vehicle
if !ESI || *(u8*)(ESI+0x101): return

*(u8*)(EDI + 0xa31) = 1
ECX = ESI; push 1; CALL SetHandbrake
// optional CVOGHBBase_Stop
ECX = ESI; CALL FUN_004f3700  // empty
// optional clear EDI+0xa32
ECX = ESI; CALL PushDriveAxesToController
```

Live decompile 2026-07-29 ≡ 2026-07-23 raw.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + HB1 + Push order | **High** | Wrong stop port |
| Client latch offsets `0xa31/0xa32` | **High** | Wrong UI state |
| Sole call site | **High** | Missed stop paths |
| NoOp hook role | **High** | Phantom drive-path logic |
| Host type English / latch meaning | **Open** | Naming only |
| Runtime | **Open** | Parity residual |

---

## 4. Surviving contract for AutoCore

```
EngageHbAndPushAxes(client in EDI):
  vehicle = *(DAT_00d1b6d8 + 0x250)
  if !game || !vehicle || vehicle.driveSuppressed(+0x101): return
  client.flag_a31 = 1
  SetHandbrake(vehicle, 1)
  maybe StopHB(client host flags)
  DrivePathNoOp(vehicle)   // empty
  maybe clear client.flag_a32
  PushDriveAxesToController(vehicle)
```

**Verdict:** **accept-with-gaps** — adversarial residuals on gates, host vs vehicle, sole xref, empty NoOp closed; product/runtime open.
