# Review B (skeptical / adversarial): `aa_004f3620` VehicleEntity_SetHandbrake

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual **strengthen**) |
| **Counterpart** | `reviews/A_aa_004f3620_VehicleEntity_SetHandbrake.md` |
| **Scratch** | `reviews/a_004f3620.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Gated like steer/longitudinal | Would hide suppress contract | **Falsified** — body has no `0xC7` walk; siblings do; bytes are pure store |
| 2 | Also writes thr/steer | Wrong axis layout | **Falsified** — HB only (`[ecx+0x61c]`) |
| 3 | Complex CF / multi-path body | Overfit reconstruction | **Falsified** — 13 B: load arg, store, ret 4 |
| 4 | MoveToTarget *calls* SetHandbrake | Prior function-record error | **Falsified** — **direct** `+0x61c` stores; not in 18 xrefs |
| 5 | `+0x61c` is service brake torque | Misread brake-spec | **Falsified** — rear **drive** torque ×0.5 (`DAT_00a0f298`); hk brake separate |
| 6 | Controller never reads entity HB | Incomplete consumer map | **Falsified** — Push copies to `ctrl+0x24` (unless hard-stop forces 1) |
| 7 | Ungated claim needs runtime unit test to seal CF | Static body insufficient? | **Static High** for CF (bytes); runtime remains policy-open only |
| 8 | Body ends at `~0x004f3626` | Span error hides pad/next fn | **Falsified** — ends `0x004f362c`; next int3s at `0x004f362d+` |
| 9 | Missing callers | Incomplete stop/HB ports | **Falsified for call graph** — 10 functions / 18 sites via live xrefs (English names still open) |
| 10 | 0.5 constant is RearWheelFrictionScalar | Prior wrong claim | **Falsified** — `read_memory` `00a0f298` = `0x3f000000` float 0.5; distinct from vehicleData rear friction setup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x61c` layout | **High** | Wrong HB / sharp flag |
| Machine body / `ret 4` | **High** | Wrong convention or length |
| Ungated store | **High** | Missed suppress contract |
| Caller dual-path (local + AI/UI packs) | **High** | Incomplete stop/HB ports |
| MoveToTarget **bypass** | **High** | NPC sharp never hits “SetHandbrake” API |
| Push / calcWheelTorque / 0.5f | **High** | Ghost / torque wrong |
| Non-0/1 exotic values | **Medium** | Only if unknown writer |
| Exhaustive direct-store inventory | **Medium** | Other bypass writers unknown |

---

## 3. Cross-check against raw + bytes

```
// clean ≡ raw ≡ machine
// 8a442404 88811c060000 c20400
*(u8*)(entity+0x61c) = handbrakeOn;
// ret 4
```

Live re-decompile 2026-07-29 strengthen ≡ frozen raw ≡ `read_memory`.

---

## 4. Surviving contract for AutoCore

```
SetHandbrake(entity, on):
  ungated *(u8*)(entity+0x61c) = on;   // no 0xC7; 13-byte body; ret 4
  // Consumers:
  //   PushDriveAxes: ctrl+0x24 = entity+0x61c  (skip if +0x101 or !+0x1a0;
  //                  +0x109 hard-stop forces ctrl HB=1 without this read)
  //   calcWheelTorque: if on≠0 && rear → torque *= 0.5f (DAT_00a0f298)
  // Bypass writers (same byte): MoveToTarget3DPoint, SetDriveAxes
  // Call graph: 10 functions, 18 call sites (DriveControlTick 6, UI dialog 4, …)
  // Wire: VehicleFlags.Handbreak / ghost pack bit0 → client +0x61c
```

**Port tests that matter (behavioral, not this body):**

* HB store under `0xC7` suppress still writes (contrast thr/steer).
* Hard-stop `+0x109` overrides controller HB independently of entity `+0x61c`.
* NPC sharp can set `+0x61c` without going through a setter API.
* Rear drive torque halves when `+0x61c≠0` (not service brake).

---

## 5. Open questions

1. Runtime / differential (matrix policy) — not dual residual.
2. Full English naming of AI/UI callers (`FUN_0093a5c0` focus-loss, `FUN_00946c00` dialog arms, etc.).
3. Inventory of **all** direct `+0x61c` stores beyond MoveToTarget / SetDriveAxes (search residual optional).
4. Package-level bit-exact beyond sealed 13-byte body.

**Verdict:** **accept-with-gaps** — adversarial residuals on gate, body span, consumers, 0.5f constant, MoveToTarget-as-caller, and call-graph completeness **closed**; runtime / package diff / English names remain open.
