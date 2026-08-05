# Function record: VehicleEntity_SetSteerInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **Canonical name** | `VehicleEntity_SetSteerInput` |
| **Address** | `0x004f5620` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body span** | `0x004f5620` – `0x004f564a` inclusive (**43 B / `0x2b`**, `read_memory` 2026-07-29) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`, 1 stack arg, `ret 4`) |
| **Return type** | `void` |
| **System** | input-drive-control |
| **Completion status** | **Human-refined + dual residual sealed 2026-07-29** — static gate chain / mask imm / sibling / MoveToTarget identity / callers / bypass / consumers sealed; runtime + UF bit producers open |

---

## 1. Summary

Gated setter for the vehicle entity’s **raw steer input** float at `this+0x618`. Resolves a linked object pointer via a three-step chain, then writes only if that object is null or its flag byte at `+0xb4` has none of bits `0xC7` set. No clamps, no ramps, no controller push, no other stores.

Live re-decompile 2026-07-29 ≡ frozen raw. Instruction-level mask immediate `0xC7` and store offset `0x618` confirmed via `read_memory`.

---

## 2. Signature

```c
void __thiscall VehicleEntity_SetSteerInput(VehicleEntity* this, float steerInput);
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `VehicleEntity*` | Entity whose steer axis is updated |
| `steerInput` | stack (`[esp+4]` at entry after call) | `float` | Desired steer axis (caller-normalized; typically `[-1,+1]`) |

---

## 3. Behavior (exact)

```
wobj = *( *(*(this + 4) + 4) + this + 0xb0 );

if (wobj == NULL || (*(uint8_t*)(wobj + 0xb4) & 0xC7) == 0)
    *(float*)(this + 0x618) = steerInput;
// else: retain previous this+0x618
```

| Condition | Result |
|---|---|
| `wobj == NULL` | Write allowed |
| `(flags & 0xC7) == 0` | Write allowed |
| else | **No write** |

Mask: `0xC7` = `0x01|0x02|0x04|0x40|0x80` (decompiler decimal `199`; **instruction imm8 sealed**).

### Instruction map (`read_memory` @ `0x004f5620`)

```
8b 41 04                mov eax, [ecx+4]           ; p0
8b 50 04                mov edx, [eax+4]           ; p1
8b 84 0a b0 00 00 00    mov eax, [edx+ecx+0xb0]    ; wobj
85 c0 / 74 09           test/jz → allow if null
f6 80 b4 00 00 00 c7    test byte [eax+0xb4], 0xC7
75 0e                   jnz → suppress (skip store)
f3 0f 10 44 24 04       movss xmm0, [esp+4]
f3 0f 11 81 18 06 00 00 movss [ecx+0x618], xmm0
c2 04 00                ret 4
```

Intermediate `p0`/`p1` nulls are **not** checked (fault); only final `wobj` null is an allow path.

---

## 4. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x4` → `+4` → `+this+0xb0` | R | ptr | Gate object (`wobj`) |
| `wobj+0xb4` | R (if non-null) | u8 | Suppress flags (`& 0xC7`) |
| `this+0x618` | W (conditional) | f32 | Steer input store |

Sibling fields (not written here): `this+0x614` longitudinal (`aa_004f5650`); `this+0x61c` handbrake (`aa_004f3620`, **ungated**).

---

## 5. Callers (live xrefs 2026-07-29)

| Symbol / label | Address | Notes |
|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` | Primary local hard/soft/clear (caller-owned values) |
| `FUN_004fc650` MoveToTarget3DPoint | `0x004fc650` | Deadband straighten / reverse-align; proportional path is **inline** (not always this call) |
| `FUN_005d73a0` | `0x005d73a0` | Stop pack thr0/steer0/HB1 + Push |
| `FUN_00636ba0` | `0x00636ba0` | Xref sealed; English name open |
| `FUN_0092f090` | `0x0092f090` | Stop axes pack |
| `FUN_009373e0` | `0x009373e0` | UI/modal stop pack |

### Same-axis writers that **bypass** this function

| Writer | Address | Gate on `+0x618`? |
|---|---|---|
| MoveToTarget proportional inline | `0x004fc650` | **Yes** — same chain; bits `{1,2,0,0x80,0x40}` ≡ `0xC7` |
| `VehicleEntity_SetDriveAxes` | `0x004fbec0` | **No** — direct thr/steer/HB then Push |
| `Vehicle_setDrivingInputs` | `0x00504c70` | **No** — network/local axes then Push |

---

## 6. Callees / side effects

| Item | Value |
|---|---|
| Direct callees | **None** |
| Global / static touches | **None** |
| Other entity fields | **None** (only optional `+0x618`) |
| Exceptions / error paths | **None** (null intermediate = fault, not handled) |

### Downstream consumers of `+0x618`

| Consumer | Effect |
|---|---|
| `VehicleAction_applyAction` `0x00598650` | Stage-1 ramp `VA+0x24` toward `entity+0x618` → DI / wheelsDesc path |
| `VehicleEntity_PushDriveAxesToController` `0x004fbc10` | **Does not** read `+0x618` |
| `hkDefaultSteering_update` `0x0064f840` | Indirect (after DI curve); not a direct entity load |

---

## 7. Related artifacts

| Kind | Path |
|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.md` |
| Annotated | `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.annotated.md` |
| Exact C++ | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetSteerInput.cpp` |
| Dual residual scratch | `docs/reconstruction/reviews/a_004f5620.md` |
| Review A / B | `reviews/A_aa_004f5620_*`, `reviews/B_aa_004f5620_*` |
| Prior verified physics note | `physics/verified/fn_004f5620_setSteerInput.md` |
| Drive axes type note | `types/VehicleEntity_drive_axes.md` |
| Downstream ramp / feed | `fn_00598650_steerRamp.md`, `fn_steering_input_feed.md` |
| Sibling longitudinal | `aa_004f5650` |
| Sibling handbrake (ungated) | `aa_004f3620` |
| Pure-model experiment | `experiments/vehicle_entity_set_steer_input.py` |

---

## 8. Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| **Control flow** | **High / Confirmed** | Live ≡ raw; instruction map |
| **Store target (`+0x618` = steer f32)** | **High / Confirmed** | Imm LE + consumers |
| **Gate mask `0xC7` / byte load** | **High / Confirmed** | Instruction imm8 |
| **Pointer chain shape** | **High / Confirmed** | Setter + sibling + MoveToTarget |
| **Sibling gate parity** | **High / Confirmed** | Byte-identical body except store offs |
| **MoveToTarget chain/bit identity** | **High / Confirmed** | Live decompile 2026-07-29 |
| **Caller inventory** | **High** (calls) / **Probable** (names) | Six live xrefs |
| **Bypass writers** | **High** | SetDriveAxes + setDrivingInputs decompiles |
| **`wobj` object identity / type name** | **Probable** | Behavior verified; naming open |
| **Suppress / flag bit meanings** | **Tentative** | Mask proven; producers **UF open** (not invented) |
| **Caller value sets (DAT key binds)** | **High (secondary)** | Plates / DriveControlTick; not body |
| **Overall (gate + store behavior)** | **High** | Dual residual sealed |
| **Overall (full retail suppress story)** | **Probable** | Needs flag producers + runtime |

---

## 9. Open questions

1. **What is `wobj`?** Exact type at `*(*( *(this+4)+4 ) + this + 0xb0)` — still Probable (**UF open; not invented**).
2. **Who sets `wobj+0xb4` bits in `0xC7`?** Producers and clear paths not enumerated (**UF open; not invented**).
3. **Per-bit semantics** of `0x01`, `0x02`, `0x04`, `0x40`, `0x80` on this flag byte.
4. **Runtime / live diff:** no CE confirmation under forced suppress bits in this artifact set.
5. **Soft L/R polarity** is a DriveControlTick / plate residual, not this body.
6. **Exhaustive** inventory of all direct `+0x618` stores beyond sealed bypass table (optional).

---

## 10. Completion checklist

| Item | Status |
|---|---|
| Raw capture filed | Yes |
| Annotated notes filed | Yes |
| Exact C++ reconstruction filed | Yes |
| Control-flow sealed | Yes (static + instruction) |
| Dual residual (gate chain + sibling + MoveToTarget + bypass + consumers) | **Yes** (2026-07-29) |
| Independent + skeptical reviews | Yes (refreshed) |
| Runtime verification | **Open** |
| UF bit producers / `wobj` type | **Open** (not invented) |
| Marked fully complete | **No** (runtime / UF open) |

---

## 11. Porting notes (for implementers)

1. Apply the **identical** `0xC7` gate before writing steer if matching gated client/AI setter paths.
2. **Do not** clamp `steerInput` inside the setter.
3. Prefer this helper over raw `+0x618` stores when parity with gated paths is required.
4. Network / `SetDriveAxes` paths **bypass** the gate — do not force-gate those if matching retail.
5. MoveToTarget proportional must reimplement the **same** chain+mask (or call this setter).
6. Handbrake (`+0x61c`) and longitudinal (`+0x614`) are separate setters / fields; HB is **ungated**.
7. Do not claim “lock” bit meanings without producers; mask is a write-suppress set only.
