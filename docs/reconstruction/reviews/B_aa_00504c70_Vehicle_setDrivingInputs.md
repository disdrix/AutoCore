# Review B (skeptical / adversarial): `aa_00504c70` Vehicle_setDrivingInputs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A narrative polish) |
| **Counterpart** | `reviews/A_aa_00504c70_Vehicle_setDrivingInputs.md` |
| **System** | `input-drive-control` (network/ghost) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on phys-gated thr/steer/HB + Push + pose; **reject** overclaims that this is local input, that Push writes steer, that `FUN_0053d970(0)` takes null this, that 0xC7 gates apply here, or that the unit is runtime-sealed |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Local player DriveControlTick entry | Would mis-own input system | **Falsified** — only VehicleNet callers (`0x5f7720`, `0x5f9f10`) |
| 2 | Works without physics object | Ghost applies to pure visual entity | **Falsified** — `entity+0x08==0` → full no-op |
| 3 | Same 0xC7 suppress as SetSteer/SetLongitudinal | Network cannot force locked axes | **Falsified** — no 0xC7 load; straight stores |
| 4 | Push completes steer into controller | Double-write / wrong owner | **Falsified** — Push dual: zero `+0x618` use |
| 5 | `FUN_0053d970(0)` means null entity / global | Wrong motion cleanup target | **Falsified** — `mov ecx,esi` before call |
| 6 | Type compare is soft float / flag byte | Wrong gate | **Falsified** — `cmp eax, 6` integer |
| 7 | HB is f32 like thr | Wrong width | **Falsified** — `mov al` / byte store `+0x61c` |
| 8 | Activate always on ghost apply | Spurious enter-world | **Falsified** — requires `param_9==0` and `+0x1a0==0` and owner match |
| 9 | Pose apply optional / skipped when axes written | Desync pose | **Falsified** — `FUN_0053eec0` always on gated path after optional activate |
| 10 | Scaffold name `throttle` means thr-only | Incomplete axes | **Falsified** — three axes + pose |
| 11 | Many non-net static callers | Incomplete graph | **Fail as multi-caller** — **2** static xrefs only |
| 12 | Package bit-exact / runtime sealed | Premature seal | **Fail** — static only this pass |

---

## 2. Decisive dataflow (raw ≡ live)

```
// __thiscall entity @ ECX
if (entity+0x08 == 0)
  return;                           // NO thr/steer/HB, NO push, NO pose

type = vfunc( *( *(entity+0x08)+0x3c ), slot +0x18 )
if (type == 6)
  FUN_0053d970(entity);             // ECX=entity; decomp "(0)" is a lie

entity+0x614 = thr;                 // f32, ungated
entity+0x618 = steer;               // f32, ungated
entity+0x61c = hb;                  // u8,  ungated

PushDriveAxesToController(entity);  // thr/HB → ctrl; NOT steer
// Push may still no-op if +0x101 set or +0x1a0 null (Push dual)

if (param_9 == 0 && entity+0x1a0 == 0) {
  comp = *(entity + 0xb0 + *(*(entity+4)+4))
  if (comp != 0) {
    if (comp->vfunc_0x19c() == chain->vfunc_0x1c8())
      Vehicle_ActivateEnterWorld(entity)
  }
}

FUN_0053eec0(pos, rot, linVel, angVel, integrateDt)
return
```

Live re-decompile 2026-07-29 ≡ frozen raw CF. Machine prefix confirms thr/steer/HB widths and call targets.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Phys `+0x08` entry gate | **High** | Ghost axes without body / silent drop |
| Type-6 → cleanup with entity this | **High** | Null this crash / wrong body |
| thr/steer/HB offsets + widths | **High** | Axis desync / type corruption |
| Ungated vs 0xC7 singles | **High** | Network fail under lock flags |
| Always Push on gated path | **High** | Controller lag / missed thr-HB |
| Push omits steer | **High** | Wrong steer owner / missing applyAction |
| Activate only when no ctrl + flag0 + match | **High CF** | Wrong enter-world spam / never activate |
| Pose always after axes on gated path | **High** | Visual/phys desync |
| Two VehicleNet static callers only | **High** (static) | Missed indirect callers if any |
| Product meaning of type **6** | **Low–Probable** | Wrong cleanup port |
| `param_9` product name | **Probable CF** | Wrong activate policy |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x614` thr | Invented? | **No** — `14 06 00 00` store disp |
| `+0x618` steer | Invented? | **No** — `18 06 00 00` |
| `+0x61c` HB | Invented? | **No** — `1c 06 00 00` + byte opcode |
| Gate `+0x08` | Soft optional? | **No** — hard outer if |
| Type const 6 | Float DAT? | **No** — immediate compare |
| `FUN_0053d970(0)` | Literal this=0? | **No** — ECX=entity |
| Push target | Wrong rel? | **No** — `0x004fbc10` |
| Steer in Push | Hidden? | **No** — Push dual |
| Activate without owner match | Always? | **No** — dual vfunc equality |
| Pose before axes | Order swap? | **No** — eec0 last |

---

## 5. Surviving contract for AutoCore

```
Vehicle_setDrivingInputs(entity,
    pos*, rot*, linVel*, angVel*,
    thr:f32, steer:f32, hb:u8,
    skipActivate:char, integrateDt:f32):

  if entity.phys == null: return

  if bodyType(entity.phys) == 6:
    FUN_0053d970(entity)            // leave-FUN; this = entity

  entity.thr   = thr                // +0x614
  entity.steer = steer              // +0x618
  entity.hb    = hb                 // +0x61c

  PushDriveAxesToController(entity) // thr/HB only; may no-op on +0x101 / null ctrl

  if skipActivate == 0 and entity.ctrlHost == null:
    if ownerComponentsMatch(entity):
      Vehicle_ActivateEnterWorld(entity)

  FUN_0053eec0(entity, pos, rot, linVel, angVel, integrateDt)
```

**Port tests that matter (behavioral):**

* Null phys → no axis mutation and no pose apply.
* Type-6 path must not pass null this into cleanup.
* Network thr/steer land even under local 0xC7 suppress conditions.
* After call, controller thr/HB follow Push rules; steer remains on entity until applyAction.
* `skipActivate != 0` or existing `+0x1a0` prevents ActivateEnterWorld.
* Pose apply still runs when activate is skipped (gated path).
* Polarity: producers use Accel **−1** / Reverse **+1** for thr at entity (do not invert in this writer).

**Callers (static sealed):**

* `VehicleNet_UnpackGhostVehicle` @ `0x005f7720` (site `0x005f99aa`)
* `VehicleNet_ReconcilePrediction` @ `0x005f9f10` (site `0x005fa245`)

---

## 6. Open questions

1. Product name for body-type enum value **6** (do not invent).
2. Product name for `param_9` (skip-activate) — CF sealed, label open.
3. Exact stack/register packing at the two VehicleNet sites (out of OWN-ONLY body scope).
4. Indirect / computed calls to `0x00504c70` (static graph = 2).
5. Runtime / differential / package bit-exact.
6. Whether any doc still treats scaffold name `throttle` as thr-only API — correct to full setDrivingInputs contract.

**Verdict:** **accept-with-gaps** — adversarial residuals on phys gate, type-6 this-arg, three-axis widths, ungated stores, Push-not-steer, activate predicates, pose-last, and two net callers **closed**; product enums/names, VehicleNet wire layout, and runtime remain open.
