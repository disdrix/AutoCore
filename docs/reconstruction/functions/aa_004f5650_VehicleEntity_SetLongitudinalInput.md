# Function record: VehicleEntity_SetLongitudinalInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **Canonical name** | `VehicleEntity_SetLongitudinalInput` |
| **Address** | `0x004f5650` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body span** | `0x004f5650` – `0x004f567a` (exclusive end; **0x2a** bytes) — sealed Ghidra `get_function_by_address` 2026-07-29 |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; float arg stack; `ret 4`) |
| **Return type** | `void` |
| **System** | input-drive-control |
| **Primary sibling** | `aa_004f5620` `VehicleEntity_SetSteerInput` @ `0x004f5620`–`0x004f564a` (same body; store `+0x618`) |
| **Completion status** | **Human-refined + dual residual sealed 2026-07-29** — gate+store, sibling byte-delta, callers, consumers, bypass writers sealed (static); runtime/diff open |

---

## 1. Summary

Gated setter for the vehicle entity’s **raw longitudinal input** float at `this+0x614`. Identical suppress-gate to `VehicleEntity_SetSteerInput` (`0xC7` mask on linked object `+0xb4`). Live re-decompile 2026-07-29 ≡ frozen raw. Machine image is a **byte-identical twin** of SetSteerInput except the store displacement (`0x614` vs `0x618`). No clamps, ramps, callees, or controller push.

---

## 2. Signature

```c
void __thiscall VehicleEntity_SetLongitudinalInput(VehicleEntity* this, float longitudinalInput);
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `VehicleEntity*` | Entity whose long axis is updated |
| `longitudinalInput` | stack `[esp+4]` | `float` | Desired axis (caller-normalized; DriveControlTick: Accel **−1**, Reverse **+1**, release **0**) |

---

## 3. Behavior (exact)

```
wobj = *( *(*(this + 4) + 4) + this + 0xb0 );

if (wobj == NULL || (*(uint8_t*)(wobj + 0xb4) & 0xC7) == 0)
    *(float*)(this + 0x614) = longitudinalInput;
// else: retain previous this+0x614
```

| Condition | Result |
|---|---|
| `wobj == NULL` | Write **allowed** |
| `(flags & 0xC7) == 0` | Write **allowed** |
| else | **No write** (previous thr retained) |

Mask: `0xC7` = `0x01|0x02|0x04|0x40|0x80` (decompiler decimal `199`; machine immediate `0xC7`).

**Null-safety:** intermediate `p0`/`p1` loads are **unchecked** (null intermediate faults like retail). Only final **wobj** null is an allow path.

---

## 4. Machine image (sibling seal)

Live `read_memory` @ `0x004f5650` / `0x004f5620` (2026-07-29):

| Bytes (both) | Role |
|---|---|
| `8B 41 04` | `mov eax,[ecx+4]` → p0 |
| `8B 50 04` | `mov edx,[eax+4]` → p1 |
| `8B 84 0A B0 00 00 00` | `mov eax,[edx+ecx+0xb0]` → wobj |
| `85 C0` / `74 09` | `test eax,eax` / `jz store` (null allow) |
| `F6 80 B4 00 00 00 C7` | `test byte [eax+0xb4], 0xC7` |
| `75 0E` | `jnz ret` (suppress) |
| `F3 0F 10 44 24 04` | `movss xmm0,[esp+4]` (arg float) |
| **`F3 0F 11 81 14 06 00 00`** | **`movss [ecx+0x614],xmm0`** ← this function |
| `F3 0F 11 81 18 06 00 00` | sibling `movss [ecx+0x618],xmm0` (SetSteer only) |
| `C2 04 00` | `ret 4` |

**Sibling delta:** only the 32-bit store displacement differs (`14 06 00 00` = `0x614` vs `18 06 00 00` = `0x618`). Gate chain, mask, null-allow, and epilogue are bitwise identical. Both bodies **0x2a** bytes (exclusive ends `0x004f567a` / `0x004f564a`).

Live decompile (Ghidra MCP) ≡ raw capture plate (WI-MOV-001).

---

## 5. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x4` → `+4` → `+this+0xb0` | R | ptr | Gate object (`wobj`) |
| `wobj+0xb4` | R (conditional) | u8 | Suppress flags (`& 0xC7`) |
| `this+0x614` | W (conditional) | f32 | Longitudinal input store |

Sibling fields (not written here): `+0x618` steer, `+0x61c` handbrake.

---

## 6. Callers (live xrefs 2026-07-29)

| Symbol / label | Address | Call-site count | Notes |
|---|---|---:|---|
| `Client_Input_DriveControlTick` | `0x009223b0` | **5** | Accel `DAT_00d1bc26`→**−1**; Reverse `DAT_00d1bc5a`→**+1**; clear/damp sites → 0; gated by caller `vehicle+0x101==0` |
| `FUN_004fc650` (`MoveToTarget3DPoint`) | `0x004fc650` | **1** | Arrival / thr→0 path **via setter**; cruise thr often **bypasses** (direct `+0x614`) |
| `FUN_005d73a0` | `0x005d73a0` | 1 | thr0/steer0/HB1 + Push family |
| `FUN_00914c20` | `0x00914c20` | 1 | non-input thr write |
| `FUN_00925820` | `0x00925820` | 1 | non-input thr write |
| `FUN_0092f090` | `0x0092f090` | 1 | thr0/steer0/HB1 pack |
| `FUN_009373e0` | `0x009373e0` | 1 | UI/modal stop pack |
| `FUN_00938670` | `0x00938670` | 1 | SetFlag_109 + HB1 + thr0 |
| `FUN_00946c00` | `0x00946c00` | **4** | Dialog/mission case arms thr |

**Total:** 9 calling functions, **16** unconditional call sites.

### Bypass writers (same field — **not** callers of this setter)

These store `+0x614` **ungated** (no `0xC7` walk):

| Writer | Address | Notes |
|---|---|---|
| `VehicleEntity_SetDriveAxes` | `0x004fbec0` | Always stores thr/steer/HB then `PushDriveAxesToController` |
| `Vehicle_setDrivingInputs` | `0x00504c70` | Network/ghost + local entry; thr/steer/HB then Push |
| `Drive_CVOGVehicle_MoveToTarget3DPoint` | `0x004fc650` | Proportional cruise thr **direct** `this[0x614]=thr` (also calls this setter on arrival arm) |

---

## 7. Callees / side effects

| Item | Value |
|---|---|
| Direct callees | **None** |
| Global / static touches | **None** |
| Other entity fields | **None** (only optional `+0x614`) |
| Exceptions / error paths | Intermediate null chain faults (retail same) |

### Downstream consumers of `+0x614`

| Consumer | Effect | Confidence |
|---|---|---|
| `VehicleEntity_PushDriveAxesToController` `0x004fbc10` | `ctrl+0x20 = entity+0x614` (unless `+0x101≠0` / no `+0x1a0`; hard-stop `+0x109` forces thr 0) | **High** |
| `VehicleAction_applyAction` `0x00598650` | **Does not** load `+0x614` (no thr ramp here; steer uses `+0x618`) | **High** |

Primary thr path: **entity+0x614 → Push → ctrl+0x20**. Sign preserved (Accel negative).

---

## 8. Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` |
| Annotated | `raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.annotated.md` |
| Clean | `reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp` |
| Review A / B | `reviews/A_aa_004f5650_*`, `reviews/B_aa_004f5650_*` |
| Sibling record | `functions/aa_004f5620_VehicleEntity_SetSteerInput.md` |
| Verified physics note | `physics/verified/fn_004f5620_setSteerInput.md` |
| Push consumer | `physics/verified/fn_004fbc10_pushDriveAxes.md` |
| Thr path (no applyAction ramp) | `physics/verified/fn_00598650_throttleRamp.md` |
| Drive axes type | `types/VehicleEntity_drive_axes.md` |
| System map | `systems/input-drive-control.md` |

---

## 9. Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| **Control flow** | **High / Confirmed** | Live decompile ≡ raw; single branch + store |
| **Store target (`+0x614`)** | **High / Confirmed** | Machine `movss [ecx+0x614]`; drive-axes + Push consumer |
| **Gate mask `0xC7`** | **High / Confirmed** | Immediate `0xC7` in image; decimal 199 in decompile |
| **Sibling byte-identity (except store)** | **High / Confirmed** | Parallel `read_memory` of SetSteer body |
| **Body size 0x2a** | **High / Confirmed** | Ghidra body end exclusive `0x004f567a` |
| **Caller inventory** | **High** (calls) / **Probable** (English names of AI/UI) | Live xrefs sealed |
| **Bypass writers** | **High** | Live decompile SetDriveAxes / setDrivingInputs; MoveToTarget verified note |
| **Push consumer path** | **High** | Verified push + throttleRamp notes |
| **Suppress bit meanings** | **Tentative** | Mask proven; producers open |
| **`wobj` type name** | **Probable** | Behavior sealed; class name open |
| **Overall (gate + store)** | **High** | Dual residual sealed; runtime/diff open |

---

## 10. Open questions

1. Same open set as SetSteerInput: `wobj` type name, `0xC7` producers/clearers, per-bit semantics.
2. Runtime / live differential (force flags; observe `+0x614` retain vs write).
3. Bit-exact / image-level port diff.
4. Full English names for every non-input caller.
5. Exhaustive scan of every direct `+0x614` store beyond sealed bypass trio (optional residual).

---

## 11. Completion checklist

| Item | Status |
|---|---|
| Raw / annotated / clean | Yes (human-refined clean) |
| Control-flow sealed (static) | Yes |
| Live re-decompile ≡ raw | **Yes** (2026-07-29) |
| Body span / sibling byte-delta sealed | **Yes** (2026-07-29) |
| Caller inventory (live xrefs) | **Yes** (2026-07-29) |
| Consumers + bypass writers | **Yes** (2026-07-29 dual residual) |
| Independent + skeptical reviews | Yes (refreshed) |
| Runtime / diff | **Open** |
| Marked fully complete | **No** (runtime/diff open) |

---

## 12. Porting notes

1. Apply the **identical** `0xC7` gate before writing thr if matching gated client paths.
2. **Do not** clamp `longitudinalInput` inside the setter.
3. Preserve sign contract: **Accelerate = −1**, **Reverse = +1** (caller-owned; this body is passthrough).
4. Prefer this helper for gated paths; bulk/network paths (`SetDriveAxes`, `setDrivingInputs`) intentionally **bypass** the gate.
5. After local axis write, thr reaches Havok input only via **PushDrive** (`ctrl+0x20`); this setter does not push.
