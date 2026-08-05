# Function record: VehicleEntity_SetHandbrake

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3620` |
| **Canonical name** | `VehicleEntity_SetHandbrake` |
| **Address** | `0x004f3620` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body span** | `0x004f3620` – `0x004f362c` inclusive (**13** bytes; exclusive end `0x004f362d`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; stack arg; `ret 4`) |
| **Return type** | `void` |
| **System** | input-drive-control |
| **Completion status** | **Human-refined + dual residual sealed 2026-07-29 (strengthen)** — static store/consumers/bypass/call graph sealed; runtime/diff open |

---

## 1. Summary

Ungated setter for the vehicle entity **handbrake / sharp-turn flag** byte at `this+0x61c`. Unlike `SetSteerInput` / `SetLongitudinalInput`, there is **no** `0xC7` suppress gate — every call stores. Live re-decompile + `read_memory` 2026-07-29 ≡ frozen raw.

---

## 2. Signature

```c
void __thiscall VehicleEntity_SetHandbrake(VehicleEntity* this, uint8_t handbrakeOn);
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `VehicleEntity*` | Entity whose handbrake flag is updated |
| `handbrakeOn` | stack `[esp+4]` at entry | `uint8_t` (promoted) | Non-zero = engaged (callers use 0/1; consumers test ≠0) |

---

## 3. Behavior (exact)

### 3.1 Machine body (`read_memory` @ `0x004f3620`, length 16)

| VA | Hex | Instruction |
|---|---|---|
| `0x004f3620` | `8a 44 24 04` | `mov al, [esp+4]` |
| `0x004f3624` | `88 81 1c 06 00 00` | `mov [ecx+0x61c], al` |
| `0x004f362a` | `c2 04 00` | `ret 4` |
| `0x004f362d+` | `cc …` | int3 padding (not in body) |

### 3.2 Pseudocode

```
*(uint8_t*)(this + 0x61c) = handbrakeOn;
```

No branches. No other stores. No callees.

---

## 4. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x61c` | W | u8 | Handbrake / sharp flag |

Sibling fields (not written here): `+0x614` longitudinal, `+0x618` steer, `+0x109` hard-stop (SetFlag_109).

---

## 5. Callers (SetHandbrake only — live xrefs 2026-07-29 strengthen)

**10** caller functions, **18** unconditional call sites (`get_function_callers` + `get_xrefs_to`).

| Symbol / label | Address | Call sites | Notes |
|---|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` | `0x009224d9`, `0x009228ee`, `0x00922979`, `0x00922dd7`, `0x0092358e` (**0**); `0x009235b9` (**1**) | Primary local; Brake/bounce → 1 |
| `Client_Input_PollBoundActions` | `0x00925d60` | `0x00927d58` | Engage **1** (pairs SetFlag_109) |
| `FUN_005d0d60` | `0x005d0d60` | `0x005d0f4c` | AI/spawn path → **1** |
| `FUN_005d73a0` | `0x005d73a0` | `0x005d73c5` | thr0/steer0/HB1 + Push |
| `FUN_00915670` | `0x00915670` | `0x00915698` | HB1 + Push |
| `FUN_0092f090` | `0x0092f090` | `0x0092f0cc` | thr0/steer0/HB1 |
| `FUN_009373e0` | `0x009373e0` | `0x0093745b` | UI/modal stop pack |
| `FUN_00938670` | `0x00938670` | `0x00938698` | SetFlag_109(1) + HB1 + thr0 |
| `FUN_0093a5c0` | `0x0093a5c0` | `0x0093a5f8` | Focus-loss HB1 |
| `FUN_00946c00` | `0x00946c00` | `0x00946d67`, `0x00946da7`, `0x00946de7`, `0x00946eb8` | Dialog/mission case arms ×4 |

### Bypass writers (same byte — **not** callers)

| Writer | Address | Notes |
|---|---|---|
| `Drive_CVOGVehicle_MoveToTarget3DPoint` | `0x004fc650` | Direct `+0x61c` = 0/1: sharp when `speed > DAT_00aaa7a4` **and** `\|headingErr\| > DAT_00a0f710`; arrival forces 1 |
| `VehicleEntity_SetDriveAxes` | `0x004fbec0` | Bundled thr/steer/HB then `PushDriveAxes` |

---

## 6. Callees / side effects

| Item | Value |
|---|---|
| Direct callees | **None** |
| Global / static touches | **None** |
| Other entity fields | **None** |
| Exceptions / error paths | **None** |

### Downstream consumers of `+0x61c`

| Consumer | Effect | Evidence |
|---|---|---|
| `VehicleEntity_PushDriveAxesToController` `0x004fbc10` | `ctrl+0x24 = entity+0x61c` (unless hard-stop `+0x109` forces ctrl HB=1 and returns) | live decompile |
| `VehicleAction_calcWheelTorque` `0x00598040` | Rear drive torque × **0.5** when non-zero | live decompile; `DAT_00a0f298` = `00 00 00 3f` |

---

## 7. Related artifacts

| Kind | Path |
|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004f3620_VehicleEntity_SetHandbrake.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3620_VehicleEntity_SetHandbrake.annotated.md` |
| Exact C++ | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetHandbrake.cpp` |
| Dual residual scratch | `docs/reconstruction/reviews/a_004f3620.md` |
| Review A / B | `reviews/A_aa_004f3620_*`, `reviews/B_aa_004f3620_*` |
| Drive axes type note | `docs/reconstruction/types/VehicleEntity_drive_axes.md` |
| Push verified | `physics/verified/fn_004fbc10_pushDriveAxes.md` |
| calcWheelTorque verified | `physics/verified/fn_00598040_calcWheelTorque.md` |
| Server HB wire | `physics/verified/server_handbrake_wire.md` |
| Sibling steer | `aa_004f5620` |
| Sibling longitudinal | `aa_004f5650` |
| Sibling hard-stop flag | `aa_004f3630` SetFlag_109 |

---

## 8. Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| **Control flow** | **High / Confirmed** | 13-byte store+ret4; live ≡ raw ≡ bytes |
| **Store target (`+0x61c`)** | **High / Confirmed** | Immediate + consumers + drive-axes docs |
| **No 0xC7 gate** | **High / Confirmed** | Body has no pointer chain / flag test |
| **Semantic name “handbrake”** | **High** | Player Brake + NPC sharp same byte |
| **Caller inventory** | **High** (calls) / **Probable** (names) | 18 live xrefs; English labels open |
| **Overall** | **High** | Dual residual sealed; runtime/diff open |

---

## 9. Open questions

1. Runtime / live diff under Brake hold (matrix policy).
2. Package-level bit-exact / image diff (body itself sealed).
3. Original PDB symbol; English names for AI/UI callers.
4. Exhaustive scan of every direct `+0x61c` store (MoveToTarget + SetDriveAxes sealed; others optional).

---

## 10. Completion checklist

| Item | Status |
|---|---|
| Raw capture filed | Yes |
| Annotated notes filed | Yes (machine bytes) |
| Exact C++ reconstruction filed | Yes (human-refined + residual plate) |
| Control-flow sealed | Yes (static + bytes) |
| Dual residual (consumers + bypass + ungated + call graph) | **Yes** (2026-07-29 strengthen) |
| Independent + skeptical reviews | Yes (refreshed) |
| Runtime verification | **Open** |
| Binary / instruction-level diff (package) | **Open** (13-byte body sealed) |
| Marked fully complete | **No** (runtime/diff open) |
