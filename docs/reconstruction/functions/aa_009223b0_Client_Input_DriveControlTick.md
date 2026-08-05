# Function record: Client_Input_DriveControlTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Canonical name** | `Client_Input_DriveControlTick` |
| **Address** | `0x009223b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Human-refined partial** -- ACCEL/REVERSE/STEER(hard+soft)/HANDBRAKE + soft/analog residual sealed (body High); **camera look-offset locals vs steer sealed (CF High)** strengthen 2026-07-29 (storage/gate/domain/consumer + bind matrix); **UF-006 bind label polarity residual open** (strings High; name↔DAT Probable); skills/airborne + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Last refined** | 2026-07-29 (camera look locals-vs-steer strengthen; UF-006 label residual; soft body seal) |

## Purpose

Local-player drive-control tick: sample ActionMap held flags (and optional analog device) -> write vehicle entity drive axes -> optional push to controller. Also hosts camera offsets, brake-edge air-stab, terrain cast, combat/skill, and secondary-weapon side paths in the same function.

## Signature (decompiler-derived)

```c
undefined4 Client_Input_DriveControlTick(int *param_1, int param_2)
// param_1 -- client/controller (VOGClient-related; type tentative)
// param_2 -- vehicle entity*, or 0
// returns 1 on normal / early-out paths observed
```

## Artifacts

| Layer | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009223b0_Client_Input_DriveControlTick.md` |
| Annotated | `docs/reconstruction/raw/aa_009223b0_Client_Input_DriveControlTick.annotated.md` |
| Clean (sectioned) | `docs/reconstruction/reconstructed-exact/Client_Input_DriveControlTick.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009223b0_Client_Input_DriveControlTick.md` |
| Review A (soft/analog refresh) | `docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick_soft_analog_refresh.md` |
| Review B (soft/analog refresh) | `docs/reconstruction/reviews/B_aa_009223b0_Client_Input_DriveControlTick_soft_analog_refresh.md` |
| Review A (camera residual) | `docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick_camera_refresh.md` |
| Review B (camera residual) | `docs/reconstruction/reviews/B_aa_009223b0_Client_Input_DriveControlTick_camera_refresh.md` |
| System map | `docs/reconstruction/systems/input-drive-control.md` |
| Camera scratch | `tmp/a_camera_dct.md` |

## Primary callees (drive axes)

| Symbol | VA | Stable | Slot |
|---|---|---|---|
| `VehicleEntity_SetSteerInput` | `0x004f5620` | `aa_004f5620` | `entity+0x618` |
| `VehicleEntity_SetLongitudinalInput` | `0x004f5650` | `aa_004f5650` | `entity+0x614` |
| `VehicleEntity_SetHandbrake` | `0x004f3620` | `aa_004f3620` | `entity+0x61c` |
| `VehicleEntity_PushDriveAxesToController` | `0x004fbc10` | -- | thr/HB -> controller |

## Digital ActionMap -> axis (body immediates)

| Flag | Immediate | Setter |
|---|---|---|
| `DAT_00d1bc26` Accel | `0xbf800000` (-1) | Longitudinal |
| `DAT_00d1bc5a` Reverse | `0x3f800000` (+1) | Longitudinal |
| `DAT_00d1bcc2` SteerR | `0xbf800000` (-1) | Steer |
| `DAT_00d1bc8e` SteerL | `0x3f800000` (+1) | Steer |
| `DAT_00d1bd2a` SoftL | `0xbf000000` (-0.5) | Steer (UF-006 label open) |
| `DAT_00d1bcf6` SoftR | `0x3f000000` (+0.5) | Steer |
| `DAT_00d1bd5e` Brake | `1` / `0` | Handbrake |

Gate for axis writes + Push: `vehicle+0x101 == 0`.

### Soft-steer residual seal (2026-07-29)

| Item | Sealed? | Evidence |
|---|---|---|
| Soft L flag `DAT_00d1bd2a` -> `SetSteerInput(0xbf000000)` = **-0.5f** | **Yes (High)** | Fresh decompile `0x009223b0`; image bytes `push 0xbf000000` @ `0x00922c48` (`read_memory`) |
| Soft R flag `DAT_00d1bcf6` -> `SetSteerInput(0x3f000000)` = **+0.5f** | **Yes (High)** | Fresh decompile; image bytes `push 0x3f000000` @ `0x00922cf8` |
| Steer priority (exclusive if/else) | **Yes (High)** | hard-R `d1bcc2` -> hard-L `d1bc8e` -> soft-L `d1bd2a` -> soft-R `d1bcf6` -> clear 0 (skip clear if analog active) |
| Hard L `d1bc8e` -> **+1.0** (`0x3f800000`); Hard R `d1bcc2` -> **-1.0** (`0xbf800000`) | **Yes (High)** | Same decompile / clean SECTION 7 |
| Display string literals `"Steer Left Soft"` / `"Steer Right Soft"` | **High** | Image `read_memory` `0x00a853d8` / `0x00a853c4`; stores ActionMap `+0x34d` / `+0x381` (`Client_InitActionDisplayNames`) |
| Display name ↔ held DAT (stride from Accel `+0x27d`↔`DAT_00d1bc26`) | **Probable** | `held = d1bc26 + (name_off − 0x27d)`; hard L/R/Brake match plate; soft maps **UI Left Soft→`d1bcf6`→+0.5**, **UI Right Soft→`d1bd2a`→−0.5** (plate SoftL/SoftR names swapped vs UI) |
| Soft physical = Hard physical under player key | **Open (UF-006)** | Story B (UI+arithmetic): soft **same sign** as hard. Story A (plate SoftL/SoftR): soft **opposes** hard. **Do not invent a fix** (no value flip / forced rename without runtime or formal layout seal). |

**UF-006 status:** residual **open** (bind **label** polarity only) -- body hex/values **sealed High**; display strings **High**; name↔DAT **Probable** with dual label stories documented in dual A/B `*_soft_analog_refresh.md`. Needs runtime bind hold and/or formal ActionMap name-field vs held-byte layout seal. Documented as CX-001; **not** a SetSteerInput body bug.

### Analog device residual (SECTION 3)

| Item | Sealed? | Notes |
|---|---|---|
| Presence probe `DAT_00d1b618()` | **Yes (structural)** | If null/false, skip analog block |
| Sample via `DAT_00d1b620`(ch) | **Yes (structural)** | ch 6/7 -> thr delta; ch 9/10 -> steer delta; ch 0xb/0xc camera path |
| Drive path when vehicle+`0x101==0` | **Yes (High CF)** | Clear `+0x109`/HB if set; clamp thr; `SetLongitudinalInput` + `SetSteerInput` with sampled floats (not +/-1/+/-0.5 immediates) |
| Non-drive path | **Yes (CF)** | Camera/look offsets only (`pClient` vtbl `+0x44c`); no axis setters |
| Continuous scale / deadzone math | **Partial** | Clamp bounds `DAT_00aaa668` / `g_flOne`; full device layout open |
| Analog vs digital mutual exclusion | **Partial** | Digital thr clear skips when analog present; steer clear skips when analog active |

### Camera look-offset residual (SECTION 1 / 3 / 5–7 / 15) — 2026-07-29 (strengthen)

**Separation (High / sealed structural):** look stack locals are **not** the steer axis. Four independent axes:

| Separation | Steer | Look |
|---|---|---|
| Storage | `entity+0x618` via `SetSteerInput` only | stack `local_d*` (never → drive slots) |
| Gate | `+0x101==0` (+ setter `0xC7`) | look math **not** gated on `+0x101` |
| Value domain | hard ±1.0 / soft ±0.5 | `local_d4` seed 1.0; hard ±0.03 / soft ±0.2 |
| Consumer | physics / `applyAction` on `+0x618` | `FUN_0091a5f0` + SECTION 15 slots |

Same SECTION 7 bind may fire **both**; soft-steer ±0.5 (UF-006) ≠ soft-look ±0.2 on `local_d4`. Live re-decompile + re-`read_memory` 2026-07-29.

| Local / sink | Role | Sealed? |
|---|---|---|
| `local_d4` | Look scale / aim param (seed `1.0`; hard ±0.03, soft ±0.2 normal mode) | **Yes (High)** body + `read_memory` |
| `local_d0, local_cc, local_c8, local_c4` | Look vector seeded from `DAT_00d1a640..64c`; thr/steer side-effects | **Yes (High)** CF; **component names open** |
| `local_a4` | Look step magnitude (`DAT_00aaacc8` = **11.0** default) | **Yes (High)** |
| `FUN_0091a5f0(local_d4, &local_d0)` | Apply look when helper `piStack_a8 != 0` | **Yes (High)** CF; callee semantics open |
| `pClient` vtbl `+0x44c` | Analog camera channel when non-drive | **Yes (High)** CF |
| SECTION 15 `*(…+0xe894)+0x11c/120/124` | World camera slot write at tick end | **Yes (High)** CF |
| Gate `+0x101` on look locals | **Does not suppress** look math — only axis setters | **Yes (High)** |
| Bind interleave matrix (hard/soft × steer+look) | See dual A camera_refresh | **Yes (High)** CF |

| DAT | Hex LE | f32 (`read_memory`) | Look use |
|---|---|---:|---|
| `DAT_00aaa8fc` | `8fc2f53c` | 0.03 | hard L/R `local_d4` ± (normal mode) |
| `DAT_00a0f70c` | `cdcc4c3e` | 0.2 | soft L/R `local_d4` ± (normal mode) |
| `DAT_00aaa878` | `6f12833b` | 0.004 | alternate-mode `local_d4` step |
| `DAT_00aaa688` | `0000a040` | 5.0 | hard L/R → `local_c8` (normal) |
| `DAT_00aaa68c` | `0000c03f` | 1.5 | combat/special look table |
| `DAT_00aaacc8` | `00003041` | 11.0 | default `local_a4` |
| `DAT_00aaacc4` | `0000a0c0` | −5.0 | reverse special look step |

**UF-003 partial:** camera locals-vs-steer residual **sealed** (structural High); skills / airborne / full mode-table semantics / component names remain **open**. Dual: A/B `*_camera_refresh.md`. Scratch: `tmp/a_camera_dct.md`.

## Callers / callees

- Callers: not fully mapped (open; see WQ-004).
- Callees: see clean SECTION index and system map call graph.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (axis paths) | High |
| Hex immediates for thr/steer/soft/HB | High (decompile + image `push` immediates for soft +/-0.5) |
| Soft/hard exclusive priority order | High |
| Analog presence -> same setters with continuous floats | High (CF); scale details Medium |
| ActionMap **display strings** (Steer Left/Right Soft) | **High** (image + InitActionDisplayNames) |
| ActionMap **name → held DAT_*** (soft slots) | **Probable** (stride arithmetic; hard/brake consistent) |
| Soft L/R product label vs plate SoftL/SoftR | **Open residual (UF-006)** — dual stories; no invented fix |
| Soft physical polarity under player key | Open (runtime) |
| Parameter type names | Tentative |
| Camera look locals **≠** steer axis (storage/gate/domain/consumer) | **High** (sealed structural) |
| SECTION 7 bind interleave matrix | **High** CF |
| Soft look ±0.2 (`local_d4`) ≠ soft steer ±0.5 (`+0x618`) | **High** |
| Look-vector component semantic names (yaw/pitch/…) | Open |
| Full combat/special look mode tables | Partial |
| `FUN_0091a5f0` product dual | Open (apply-site CF High) |
| Skills / airborne secondary | Open (UF-003 remainder) |

## Open questions / residual gaps

1. Parent caller each frame.
2. **UF-006 (open residual):** seal display name ↔ held DAT for soft L/R (formal ActionMap layout or runtime hold). Until then keep dual stories — plate SoftL@`d1bd2a`/SoftR@`d1bcf6` vs UI order Left Soft@`d1bcf6`/Right Soft@`d1bd2a`. Body ±0.5 **sealed**; do not flip.
3. Full SECTION 8-12 semantic naming (skills/airborne).
4. Interaction of `+0x109` hard-stop with other systems.
5. Full analog channel scale / deadzone table.
6. Semantic axis names for look `local_d0..c4` and exact product meaning of `local_d4`.
