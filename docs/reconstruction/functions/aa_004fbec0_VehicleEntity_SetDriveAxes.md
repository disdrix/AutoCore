# Function record: VehicleEntity_SetDriveAxes

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbec0` |
| **Canonical name** | `VehicleEntity_SetDriveAxes` |
| **Address** | `0x004fbec0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body span** | `0x004fbec0` – `0x004fbeed` inclusive (**46** bytes; exclusive end `0x004fbeee`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; three stack args; `ret 0xc`) |
| **Return type** | `void` |
| **System** | input-drive-control |
| **Completion status** | **Human-refined + dual residual sealed 2026-07-29 (strengthen)** — machine body, ungated thr/steer/HB, always-Push, sole static caller sealed; runtime/diff/indirect-call inventory open |
| **Bit-for-bit / runtime / diff** | Body sealed static; package/runtime open |

---

## 1. Summary

Bulk-write vehicle drive axes then push thr/HB into the input controller:

* `entity+0x614` ← thr (**f32**, ungated)
* `entity+0x618` ← steer (**f32**, ungated)
* `entity+0x61c` ← handbrake (**u8**, ungated)
* always `VehicleEntity_PushDriveAxesToController` (`0x004fbc10`)

Unlike `SetLongitudinalInput` / `SetSteerInput`, there is **no** `0xC7` suppress gate. Unlike the single setters, this body **always** pushes after store.

Live re-decompile + `read_memory` 2026-07-29 ≡ frozen raw.

---

## 2. Signature

```c
void __thiscall VehicleEntity_SetDriveAxes(
    VehicleEntity* this,
    float thr,      // [esp+4]  → +0x614
    float steer,    // [esp+8]  → +0x618
    uint8_t hb);    // [esp+0xc] → +0x61c  (stack slot 4 bytes; byte used)
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `VehicleEntity*` | Entity whose axes are updated |
| `thr` | stack `[esp+4]` | `f32` | Longitudinal (Accel typically −1, Reverse +1 at producers) |
| `steer` | stack `[esp+8]` | `f32` | Steer target for applyAction ramp |
| `hb` | stack `[esp+0xc]` | `u8` | Handbrake / sharp flag |

---

## 3. Behavior (exact)

### 3.1 Machine body (`read_memory` @ `0x004fbec0`, length 48)

| VA | Hex | Instruction |
|---|---|---|
| `0x004fbec0` | `f3 0f 10 44 24 04` | `movss xmm0, [esp+4]` |
| `0x004fbec6` | `8a 44 24 0c` | `mov al, [esp+0xc]` |
| `0x004fbeca` | `f3 0f 11 81 14 06 00 00` | `movss [ecx+0x614], xmm0` |
| `0x004fbed2` | `f3 0f 10 44 24 08` | `movss xmm0, [esp+8]` |
| `0x004fbed8` | `f3 0f 11 81 18 06 00 00` | `movss [ecx+0x618], xmm0` |
| `0x004fbee0` | `88 81 1c 06 00 00` | `mov [ecx+0x61c], al` |
| `0x004fbee6` | `e8 25 fd ff ff` | `call 0x004fbc10` (`PushDriveAxesToController`) |
| `0x004fbeeb` | `c2 0c 00` | `ret 0xc` |
| `0x004fbeee+` | `cc cc` | int3 padding (not in body) |

### 3.2 Pseudocode

```
*(float*)(this + 0x614) = thr;
*(float*)(this + 0x618) = steer;
*(uint8_t*)(this + 0x61c) = hb;
VehicleEntity_PushDriveAxesToController(this);
```

No branches. No local gates. No clamps.

### 3.3 Push contract (callee; dual `aa_004fbc10`)

* Gate: may full no-op if `entity+0x101 != 0` or `entity+0x1a0 == 0`.
* Copies thr `+0x614 → ctrl+0x20` and HB `+0x61c → ctrl+0x24` (normal path).
* Hard-stop `+0x109`: thr0 + ctrl HB=1 early return (skips entity HB read).
* **Does not** read or write steer `+0x618`.

---

## 4. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x614` | W | f32 | Longitudinal input |
| `this+0x618` | W | f32 | Steer input (entity only; not pushed here) |
| `this+0x61c` | W | u8 | Handbrake / sharp |

---

## 5. Callers (live xrefs 2026-07-29 strengthen)

**1** caller function, **1** unconditional call site.

| Symbol | Address | Call site | Args |
|---|---|---|---|
| `VehicleAction_airStabilization` | `0x00598320` | `0x0059858a` | thr=**0**, steer=**0**, hb=**1** (`push 1; push 0; push 0` with `ecx = [VA+0x44]`) |

Site context: post-collision recovery after zero lin/ang velocity vtbl calls; then re-ground.

**Note:** Prior commentary “SetDriveAxes(0) clears thr/steer/HB” is **wrong for this site** — HB is forced **1**.

No other static xrefs (`get_bulk_xrefs` / callers). Indirect/computed targets: **open**.

---

## 6. Sibling family

| API | VA | Offset(s) | Gate | Push |
|---|---|---|---|---|
| `SetLongitudinalInput` | `0x004f5650` | `+0x614` | 0xC7 | No |
| `SetSteerInput` | `0x004f5620` | `+0x618` | 0xC7 | No |
| `SetHandbrake` | `0x004f3620` | `+0x61c` | none | No |
| **`SetDriveAxes`** | **`0x004fbec0`** | **all three** | **none** | **Always** |
| `PushDriveAxesToController` | `0x004fbc10` | thr/HB → ctrl | own gates | (is the push) |

Bypass writers of the same fields (not callers of this API): `MoveToTarget3DPoint`, `setDrivingInputs` (documented elsewhere).

---

## 7. Artifacts

- Raw: `docs/reconstruction/raw/aa_004fbec0_VehicleEntity_SetDriveAxes.md`
- Annotated: `docs/reconstruction/raw/aa_004fbec0_VehicleEntity_SetDriveAxes.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleEntity_SetDriveAxes.cpp`
- Dual A/B: `reviews/A_aa_004fbec0_*.md`, `reviews/B_aa_004fbec0_*.md`
- Scratch: `reviews/a_004fbec0.md`
- Push dual: `reviews/A_aa_004fbc10_*`, `reviews/B_aa_004fbc10_*`

---

## 8. Confidence

| Claim | Level |
|---|---|
| Machine body / offsets / types / always-Push | **High** |
| Ungated vs 0xC7 singles | **High** |
| Push omits steer | **High** (Push dual) |
| Sole static caller + (0,0,1) | **High** |
| Multi-caller bulk product role | **Tentative / open** |
| Runtime / package bit-exact | **Open** |
