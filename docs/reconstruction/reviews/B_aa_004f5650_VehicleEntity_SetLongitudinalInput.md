# Review B (skeptical / adversarial): `aa_004f5650` VehicleEntity_SetLongitudinalInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **VA** | `0x004f5650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen) |
| **Counterpart** | `reviews/A_aa_004f5650_VehicleEntity_SetLongitudinalInput.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always writes thr | Gate can suppress | **Falsified** — `0xC7` suppress in image |
| 2 | Pushes controller itself | Body is store only | **Falsified** — no call; Push is separate |
| 3 | Clamps to [−1, +1] | No clamp in raw/live | **Falsified** |
| 4 | Body inverts Accelerate to positive | Clean does not rewrite float | **Falsified** — polarity caller-owned |
| 5 | Null wobj blocks write | Raw/live: `iVar1==0` **allows** write | **Falsified** — null is allow path |
| 6 | "Brief sibling" means weaker CF seal | Size/bytes unknown? | **Falsified** — live body **0x2a** bytes; twin of SetSteer except store disp |
| 7 | All thr writers use this setter | MoveToTarget / SetDriveAxes / setDrivingInputs | **Falsified** — those **bypass** gate with direct `+0x614` |
| 8 | applyAction ramps thr from `+0x614` | throttleRamp verified note | **Falsified** — **zero** loads of `+0x614` in applyAction; thr path is Push → `ctrl+0x20` |
| 9 | Intermediate p0/p1 null is safe | Chain has no checks | **Confirmed risk** — null p0/p1 faults (retail same); only final wobj null handled |
| 10 | Static dual residual needs runtime to seal CF | Body is pure gate+store | **Static High** for CF; runtime remains policy-open only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x614` store | **High** | No throttle axis |
| `0xC7` suppress gate | **High** | Input stuck / ignored |
| Null-safety (wobj null → allow) | **High** | Wrong suppress when unlinked |
| Intermediate p0/p1 null | **High** (fault path) | Crash if chain broken — retail same |
| Sibling twin of SetSteer | **High** | Divergent thr/steer lock ports |
| Caller inventory (addresses) | **High** | Missed thr clear/stop packs |
| Bypass writers skip gate | **High** | Over-applying 0xC7 to bulk/net paths |
| Push consumer thr | **High** | Ghost / controller thr wrong |
| Bit meanings of 0xC7 | **Tentative** | Wrong lock behavior |
| Accelerate = −1 caller contract | **High** (system map) | Inverted drive if ports flip |

---

## 3. Cross-check against raw / live

```
wobj = *(*(*(this+4)+4) + this + 0xb0);
if (wobj == 0 || (*(u8*)(wobj+0xb4) & 0xC7) == 0)
    *(float*)(this + 0x614) = thr;
// else retain previous +0x614

// Live 2026-07-29: decompile ≡ raw; read_memory immediate 0xC7;
// store disp 0x614; ret 4; body end exclusive 0x004f567a.
// Clean ≡ raw (gate + single store). No CF invent.
```

Machine twin (SetSteer @ `0x004f5620`): identical through `test …,0xC7` / `movss` load; only `movss [ecx+disp]` differs (`0x618` vs `0x614`).

---

## 4. Sign convention (document only; do not change CF)

| Source | Accelerate | Reverse |
|---|---|---|
| `systems/input-drive-control.md` | **−1.0f** | **+1.0f** |
| DriveControlTick / clean plate | `0xbf800000` | `0x3f800000` |
| This body | passthrough `param_2` | passthrough |

Adversarial check: no evidence the setter flips or remaps the float. Ports that treat Accelerate as **positive** will invert thr relative to retail. **No clean CF edit.**

---

## 5. Surviving contract for AutoCore

```
SetLongitudinalInput(entity, thr):
  if wobj null OR (wobj+0xb4 & 0xC7) == 0:
    entity+0x614 = thr
  else: keep previous thr
  // NO push, NO clamp, NO callees

  pair setters:
    SetSteerInput(+0x618)     // same 0xC7 gate (byte-twin)
    SetHandbrake(+0x61c)      // UNGATED (contrast)
  consumer:
    PushDriveAxes: ctrl+0x20 = entity+0x614
      (skip if +0x101 or !+0x1a0; +0x109 hard-stop forces thr 0)
  bypass writers (ungated +0x614):
    SetDriveAxes, setDrivingInputs, MoveToTarget proportional thr
  caller contract (local input): Accel −1, Reverse +1, release 0
```

**Port tests that matter (behavioral, not inventing CF):**

* Under `0xC7` suppress, SetLongitudinalInput retains previous thr; SetHandbrake still writes.
* SetDriveAxes / setDrivingInputs still overwrite thr under the same flags (bypass).
* Push maps thr sign as stored (negative Accel).
* Null wobj still allows thr write.

---

## 6. Open questions

1. Runtime: break `0x004f5650`; force wobj flags; observe `+0x614` retain vs write.
2. Seal wobj type + 0xC7 producers (shared with SetSteerInput).
3. English names for non-input callers; optional exhaustive direct-`+0x614` store scan.
4. Bit-exact / instruction-image port diff.

**Verdict:** **accept-with-gaps** — adversarial residuals on gate, null-allow, sibling twin, consumers, and bypass writers **closed**; runtime/diff remain open.
