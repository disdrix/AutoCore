# Review B (skeptical / adversarial): `aa_004fbec0` VehicleEntity_SetDriveAxes

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual **strengthen** — live Ghidra; supersedes thin 2026-07-23 scaffold) |
| **Counterpart** | `reviews/A_aa_004fbec0_VehicleEntity_SetDriveAxes.md` |
| **Scratch** | `reviews/a_004fbec0.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present and strengthened** |
| **Verdict** | **accept-with-gaps** on ungated thr/steer/HB + always-Push; **reject** overclaims that Push writes steer, that the body is gated, that airStab clears HB to 0, or that the unit is a finished multi-caller bulk API without further evidence |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same 0xC7 gate as single thr/steer setters | Would re-introduce suppress on bulk path | **Falsified** — no pointer chain; pure stores + call |
| 2 | No controller push (setters-only) | Incomplete consumer bridge | **Falsified** — unconditional `call 0x004fbc10` |
| 3 | Push finishes steer into controller | Overstated thr/HB bridge | **Falsified** — Push dual: zero `+0x618` refs; applyAction owns steer ramp |
| 4 | Complex multi-path body | Overfit reconstruction | **Falsified** — 46 B straight-line |
| 5 | AirStab `SetDriveAxes(0)` clears thr/steer/**HB** | Wrong recovery state | **Falsified** — site pushes **hb=1**, thr=0, steer=0 |
| 6 | Many AI/path callers already sealed | Incomplete call graph claim | **Fail as sealed multi-caller** — static graph is **1** site only |
| 7 | HB store is f32 / dword | Wrong type width | **Falsified** — `mov al` / `mov [ecx+0x61c], al` |
| 8 | Thr/steer are integer stores | Wrong load width | **Falsified** — `movss` |
| 9 | `ret 4` or `ret 8` | Wrong stack cleanup | **Falsified** — `ret 0xc` |
| 10 | Thin wave2 dual “done” | Residual incomplete | **Superseded** — this pass adds machine + xrefs + caller args |
| 11 | Ready for bit-exact package seal | Runtime / indirect calls open | **Fail** for package completeness |

---

## 2. Decisive dataflow (raw ≡ live ≡ bytes)

```
// __thiscall this@ECX; stack: thr@+4, steer@+8, hb@+0xc; ret 0xc
*(f32*)(entity + 0x614) = thr;     // ungated
*(f32*)(entity + 0x618) = steer;   // ungated
*(u8 *)(entity + 0x61c) = hb;      // ungated
VehicleEntity_PushDriveAxesToController(entity);
// Push (owned dual aa_004fbc10): may no-op on +0x101 / !+0x1a0;
//   thr → ctrl+0x20; HB → ctrl+0x24 (unless +0x109 hard-stop forces thr0/HB1);
//   NEVER touches entity+0x618 / steer
```

Live re-decompile 2026-07-29 strengthen ≡ frozen raw ≡ `read_memory`.

Rel32 at `0x004fbee6`: target **`0x004fbc10`**.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Three-field store offsets/types | **High** | Axes desync / wrong widths |
| Ungated write (vs 0xC7 singles) | **High** | Override lock ignored or over-applied |
| Always-Push | **High** | Controller lag / missed thr-HB bridge |
| Push omits steer | **High** | Double-write / missing steer owner |
| Sole static caller + (0,0,1) args | **High** | Wrong recovery axes / false multi-caller ports |
| “General bulk API” product role beyond airStab | **Tentative** | Missing ports if indirect calls exist |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x614` thr | Invented? | **No** — `14 06 00 00` in store disp |
| `+0x618` steer | Invented? | **No** — `18 06 00 00` |
| `+0x61c` HB | Invented? | **No** — `1c 06 00 00` |
| Gate 0xC7 | Hidden? | **No** — no loads of subsystem `+0xb0/+0xb4` |
| Push call | Wrong target? | **No** — rel decode `0x004fbc10` |
| AirStab all-zero | Docs overclaim? | **Yes overclaim** — hb push is **1** |
| Steer in Push | This unit “completes” steer? | **No** — Push never copies steer |

---

## 5. Surviving contract for AutoCore

```
SetDriveAxes(entity, thr:f32, steer:f32, hb:u8):
  // bulk axes — always store (bypass 0xC7 on thr/steer)
  entity+0x614 = thr
  entity+0x618 = steer
  entity+0x61c = hb
  PushDriveAxesToController(entity)   // thr/HB bridge only; steer via applyAction

// Sealed product caller (static):
//   VehicleAction_airStabilization recovery @ 0x0059858a:
//     SetDriveAxes(entity, 0.f, 0.f, 1)   // NOT all-zero HB

// Pair with:
//   gated SetLongitudinalInput / SetSteerInput (0xC7)
//   ungated SetHandbrake (no Push)
//   MoveToTarget3DPoint direct +0x614/+0x618/+0x61c then Push (bypass this API)
```

**Port tests that matter (behavioral):**

* Bulk thr/steer write under 0xC7 suppress still lands (contrast gated setters).
* Always-Push after store even when thr/steer/HB unchanged.
* Push may still no-op axes→controller when `+0x101` set or `+0x1a0` null.
* Air-stab recovery leaves entity HB **1**, thr/steer **0**, then Push.
* Steer entity field set here is **not** mirrored by Push; applyAction still required for VA steer stage.

---

## 6. Open questions

1. Runtime / differential (matrix policy) — not dual residual.
2. Indirect / computed calls to `0x004fbec0` (static graph sealed at 1).
3. Whether server/sim paths share this bulk helper or only client airStab.
4. Package-level bit-exact beyond sealed 46-byte body.
5. Out-of-scope plates still wording “SetDriveAxes(0) clears HB” — correct to **(0,0,1)** when those docs are next owned.

**Verdict:** **accept-with-gaps** — adversarial residuals on gate, Push always, steer-not-in-Push, machine body/span, and sole caller **(0,0,1)** **closed**; multi-caller bulk narrative, runtime, and package diff remain open.
