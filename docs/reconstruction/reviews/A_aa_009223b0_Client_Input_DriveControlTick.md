# Reconstruction review A: `aa_009223b0` Client_Input_DriveControlTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **VA** | `0x009223b0` |
| **Canonical name** | `Client_Input_DriveControlTick` |
| **Review date** | `2026-07-23` (soft/analog residual strengthen `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to raw / re-decompile) |
| **Author of reconstruction** | Not this reviewer |
| **Counterpart** | `reviews/B_aa_009223b0_Client_Input_DriveControlTick.md` (skeptical) |
| **Verdict** | **accept-with-gaps** (soft body values sealed; UF-006 label residual open) |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_009223b0_Client_Input_DriveControlTick.md` | Authoritative Ghidra decompile body |
| Annotated low-level | `docs/reconstruction/raw/aa_009223b0_Client_Input_DriveControlTick.annotated.md` | Scaffold annotated copy |
| Exact C++ (refined) | `docs/reconstruction/reconstructed-exact/Client_Input_DriveControlTick.cpp` | Sectioned clean; CF must ≡ raw |
| Function record | `docs/reconstruction/functions/aa_009223b0_Client_Input_DriveControlTick.md` | Status / confidence |
| System map | `docs/reconstruction/systems/input-drive-control.md` | ActionMap → setter contracts |
| Fresh re-decompile | Ghidra `decompile_function` `0x009223b0` (2026-07-23 + 2026-07-29 soft pass) | Confirm raw still matches live tool |
| Soft immediates image | `read_memory` @ `0x00922c48` / `0x00922cf8` | `push 0xbf000000` / `push 0x3f000000` before SetSteerInput |
| Display-name cross-link | `Client_InitActionDisplayNames` clean | “Steer Left Soft” / “Steer Right Soft” slots |
| Setter clean (cross-link) | `VehicleEntity_SetSteerInput.cpp` @ `0x004f5620` | Gate+store consumer of steer calls |
| Setter clean (cross-link) | `VehicleEntity_SetLongitudinalInput.cpp` @ `0x004f5650` | Gate+store consumer of thr calls |
| Setter clean (cross-link) | `VehicleEntity_SetHandbrake.cpp` @ `0x004f3620` | Ungated `+0x61c` consumer |

**Primary claims under review (clean must match low-level):**

1. UI modal gate early-return via `DAT_00d1b6d8[0x7f]` vtbl `+0x3c` non-zero.
2. Analog path (`DAT_00d1b618`/`620`) either camera offsets or `SetLongitudinal`+`SetSteer` when vehicle drive-enabled.
3. Digital accelerate: `DAT_00d1bc26` → `SetLongitudinalInput(0xbf800000)` (`-1.0f`) when `vehicle+0x101==0`.
4. Digital reverse: `DAT_00d1bc5a` → `SetLongitudinalInput(0x3f800000)` (`+1.0f`) when drive-enabled; clear thr to 0 if neither accel nor reverse (and no analog).
5. Steer priority order: hard-R `d1bcc2` → hard-L `d1bc8e` → soft-L `d1bd2a` → soft-R `d1bcf6` → clear 0.
6. Soft constants `0xbf000000` / `0x3f000000` (±0.5); hard `±1.0` bit patterns as above.
7. Continuous handbrake: `DAT_00d1bd5e` (or analog ch 8) → `SetHandbrake(1)`; release clears latch + `SetHandbrake(0)`.
8. End-of-tick `VehicleEntity_PushDriveAxesToController` only when `vehicle+0x101==0`.
9. Section comments do **not** invent branches; only annotate existing CF.

**Not re-authored in this review.** Live CE/runtime not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth CF, constants, call order |
| Fresh Ghidra re-decompile | `0x009223b0` HTTP 2026-07-23 | Confirmed same setter sites, ActionMap DATs, labels (`LAB_00922d94`, etc.) |
| Clean C++ section markers | reconstructed-exact SECTIONs 1–15 | Map claims ↔ body regions |
| Setter raws / cleans | `aa_004f5620`, `aa_004f5650`, `aa_004f3620` | Confirm call targets and gate ownership (callers vs setters) |
| System map | `input-drive-control.md` | Sign convention table vs body immediates |

No instruction-byte length measure of full function. No bind-table runtime correlation.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw (spot-checked regions)

| Region | Raw | Clean | Match |
|---|---|---|---|
| UI early-out | `[0x7f]+0x3c != 0 → return 1` | SECTION 2 same | **Yes** |
| Analog present | `DAT_00d1b618` + sample 6/7/9/10 | SECTION 3 same | **Yes** |
| Vehicle null | `param_2==0 → return 1` | SECTION 4 same | **Yes** |
| Accel | `d1bc26` / latch `param_1[0x319]` → thr `-1` | SECTION 5 same | **Yes** |
| Reverse | `d1bc5a` → thr `+1`; clear-0 path | SECTION 6 same | **Yes** |
| Steer order | R hard, then L hard / soft L / soft R / clear | SECTION 7 same priority | **Yes** |
| Soft immediates | `0xbf000000`, `0x3f000000` | Same hex constants | **Yes** |
| Post-steer join | `LAB_00922d94` thr damp | SECTION 7b | **Yes** |
| Handbrake latch | `d1bd5e` / analog ch8 | SECTION 13 | **Yes** |
| Push | `+0x101==0` → PushDriveAxes | SECTION 14 | **Yes** |

### 3.2 Axis write contracts (caller-owned signs)

| ActionMap (plate / map) | Immediate in body | Setter | Entity slot |
|---|---|---|---|
| Accelerate `DAT_00d1bc26` | `0xbf800000` | `SetLongitudinalInput` `0x004f5650` | `+0x614` |
| Reverse `DAT_00d1bc5a` | `0x3f800000` | same | `+0x614` |
| Steer right `DAT_00d1bcc2` | `0xbf800000` | `SetSteerInput` `0x004f5620` | `+0x618` |
| Steer left `DAT_00d1bc8e` | `0x3f800000` | same | `+0x618` |
| Soft L `DAT_00d1bd2a` | `0xbf000000` | same | `+0x618` |
| Soft R `DAT_00d1bcf6` | `0x3f000000` | same | `+0x618` |
| Brake `DAT_00d1bd5e` | `1` / `0` | `SetHandbrake` `0x004f3620` | `+0x61c` |

Clean preserves hex immediates (no float-literal modernization that could flip bits).

### 3.3 Shared drive-enable gate

All digital axis setter calls in SECTIONs 5–7 and handbrake engage/release path observe `*(char*)(param_2 + 0x101) == '\0'` before writing (or before Push). Clean does not remove or invert this gate.

### 3.4 Type renames only

`undefined4` → `uint32_t /* width from decompiler */`; `undefined1` → `uint8_t`. No structural CF rewrite.

### 3.5 Cross-links to setters

Clean header and SECTIONs 3/5/6/7/13/14 name:

- `VehicleEntity_SetSteerInput` @ `0x004f5620` (`aa_004f5620`)
- `VehicleEntity_SetLongitudinalInput` @ `0x004f5650` (`aa_004f5650`)
- `VehicleEntity_SetHandbrake` @ `0x004f3620` (`aa_004f3620`)

Setter cleans already list this function as a primary caller — bidirectional documentation is consistent.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Camera / look-vector math on `local_d*` | Low | Large; secondary to drive axes; not fully named |
| Soft L/R label polarity vs hard (UF-006) | Medium | **Body values sealed 2026-07-29** (hex + image push); **labels** SoftL/SoftR vs physical left/right still open — do not invent fix |
| Full caller of DriveControlTick | Medium | Parent frame tick not mapped in this unit |
| `DAT_00afe2b0` thr-damp constant | Low | Named only as DAT; value not re-read this pass |
| Annotated layer still scaffold-dense | Low | Clean is refined; annotated may lag SECTION map |
| Bit-exact / runtime | Open | Deferred per project rules |
| Analog continuous scale / deadzone | Medium | SECTION 3 CF sealed; full device math partial |

None of the above is a CF drift between clean and raw.

---

## 5. Soft / analog evidence tables (2026-07-29 residual seal)

### 5.1 Soft-steer body (sealed)

| Bind flag (plate) | Body test | Immediate | Float | Image site | Match clean SECTION 7 |
|---|---|---|---:|---|---|
| Soft L `DAT_00d1bd2a` | `!= '\0'` then `+0x101==0` | `0xbf000000` | −0.5 | `push` @ `0x00922c48` | 7c |
| Soft R `DAT_00d1bcf6` | same | `0x3f000000` | +0.5 | `push` @ `0x00922cf8` | 7d |
| Hard R `DAT_00d1bcc2` | first priority | `0xbf800000` | −1.0 | decompile | 7a |
| Hard L `DAT_00d1bc8e` | else of hard-R | `0x3f800000` | +1.0 | decompile | 7b |
| Clear | no hard/soft; no analog | `0` | 0.0 | decompile | 7e |

**Priority (exclusive):** hard-R → hard-L → soft-L → soft-R → clear. Not additive.

### 5.2 UF-006 polarity residual (documented, not fixed)

| Hard bind (plate) | Hard value | Soft bind (plate) | Soft value | Same physical direction? |
|---|---:|---|---:|---|
| SteerLeft `d1bc8e` | **+1.0** | SoftL `d1bd2a` | **−0.5** | **Unknown** — signs **oppose** if labels share meaning |
| SteerRight `d1bcc2` | **−1.0** | SoftR `d1bcf6` | **+0.5** | same residual |

Display strings (“Steer Left Soft” / “Steer Right Soft”) exist in `Client_InitActionDisplayNames` but do **not** prove runtime DAT identity without table/bind dump. **UF-006 remains open.** No value flip applied.

### 5.3 Analog device (SECTION 3)

| Step | Evidence | Confidence |
|---|---|---|
| `DAT_00d1b618` code* present and returns non-zero | decompile early block | High CF |
| Sample thr = ch7 − ch6 via `DAT_00d1b620` | decompile | High CF |
| Sample steer = ch9 − ch10 | decompile | High CF |
| If no vehicle or `+0x101!=0` → camera path only | decompile if/else | High CF |
| Else: clear `+0x109`/HB; clamp thr; `SetLongitudinal` + `SetSteer` continuous | decompile | High CF |
| Digital thr clear skipped when analog present | reverse clear branch | High CF |
| Steer clear skipped when analog active | 7e early goto | High CF |
| Full stick curve / deadzone constants | partial (`DAT_00aaa668` clamp) | Medium–Low |

---

## 6. Verdict rationale

**accept-with-gaps:** Clean body preserves decompiler control flow and all critical ActionMap→setter immediates. Soft ±0.5 now double-confirmed (decompile + image push bytes). Section comments improve navigability without inventing branches. Gaps: UF-006 label↔physical polarity, secondary naming, callers, runtime — not reconstruction faithfulness failures.

---

## 7. Cross-reference checklist

| Link | Present in clean header? |
|---|---|
| SetSteerInput `0x004f5620` | Yes |
| SetLongitudinalInput `0x004f5650` | Yes |
| SetHandbrake `0x004f3620` | Yes |
| PushDriveAxes `0x004fbc10` | Yes |
| System map `input-drive-control.md` | Yes |
| Dual review B counterpart | Yes |
| UF-006 residual documented | Yes (function record + this review) |

---

## 8. Suggested follow-ups (not blocking accept-with-gaps)

1. Promote annotated raw with SECTION index matching clean.
2. Resolve UF-006 soft polarity via runtime bind hold test (only remaining soft residual).
3. Map caller of `0x009223b0` (WQ-004 vertical trace remainder).
4. Pair with `Client_Input_PollBoundActions` frame order documentation.
5. Expand analog deadzone/scale constants if gamepad parity is required.
