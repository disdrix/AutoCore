# Skeptical / adversarial review B: `Client_Input_DriveControlTick` @ `0x009223b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 (soft/analog residual strengthen `2026-07-29`) |
| **Scope** | DriveControlTick digital axes, gates, soft-steer polarity, analog path, setter cross-links |
| **Counterpart** | `reviews/A_aa_009223b0_Client_Input_DriveControlTick.md` |
| **Verdict** | **needs-more-evidence** for unit-complete seal; **soft body values sealed**; UF-006 labels open; **body CF not broken** |

**Generic approval is insufficient.** This review attacks naming, polarity labels, gate semantics, and over-claims in plates/system maps — not only whether clean compiled from the raw paste.

---

## 1. What was inspected

### Primary unit artifacts

| Path | Role |
|------|------|
| `raw/aa_009223b0_Client_Input_DriveControlTick.md` | Immutable decompile capture |
| `raw/aa_009223b0_Client_Input_DriveControlTick.annotated.md` | Annotated scaffold |
| `reconstructed-exact/Client_Input_DriveControlTick.cpp` | Sectioned clean |
| `functions/aa_009223b0_Client_Input_DriveControlTick.md` | Function record |
| `systems/input-drive-control.md` | System-level claims |
| `UNRESOLVED_FINDINGS.md` UF-003, UF-006 | Known open polarity / branch gaps |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `raw/aa_004f5620_*` + clean SetSteerInput | Prove setter is gate+store only; signs are caller-owned |
| `raw/aa_004f5650_*` + clean SetLongitudinalInput | Same for thr |
| `raw/aa_004f3620_*` + clean SetHandbrake | Prove no 0xC7 gate; handbrake byte |
| `types/VehicleEntity_drive_axes.md` | Layout claims |
| Fresh Ghidra re-decompile of `0x009223b0` | Confirm raw not stale |

**Not performed:** CE hold-key runtime, ActionMap table dump at `VOGClient+0x116c`, instruction-level size of full tick, full secondary-branch semantic map.

---

## 2. Evidence used

### A. Authoritative thr/steer immediates (raw body)

```c
// Accel path (excerpt)
VehicleEntity_SetLongitudinalInput(0xbf800000);  // -1.0f
// Reverse path
VehicleEntity_SetLongitudinalInput(0x3f800000);  // +1.0f
// Hard steer R / L
VehicleEntity_SetSteerInput(0xbf800000);         // -1.0f
VehicleEntity_SetSteerInput(0x3f800000);         // +1.0f
// Soft
VehicleEntity_SetSteerInput(0xbf000000);         // -0.5f  // DAT_00d1bd2a
VehicleEntity_SetSteerInput(0x3f000000);         // +0.5f  // DAT_00d1bcf6
// Handbrake
VehicleEntity_SetHandbrake(1);
VehicleEntity_SetHandbrake(0);
```

Mechanical consequences:

1. Longitudinal retail: accelerate **negative**, reverse **positive** — sealed in hex immediates.
2. Hard steer: right bind `d1bcc2` → **negative**, left bind `d1bc8e` → **positive**.
3. Soft binds write **half** magnitude with **opposite** sign pairing relative to hard left/right **if** SoftL/SoftR labels match physical left/right (see Claim 3).
4. Setters themselves do not embed these constants — ownership is this tick.

### B. Drive-enable gate

Every digital thr/steer write is nested under `*(char*)(param_2+0x101)==0`. Push uses the same flag. Handbrake continuous path also checks `+0x101`. Alternate name `suppressDriveAxisApply` is **Probable**, not proven.

### C. Fresh re-decompile

Live Ghidra decompile at `0x009223b0` (2026-07-23) retained the same plate, same DATs, same setter call sites. Raw is not a one-off hallucination.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — “Clean is bit-faithful to retail EXE”

| Sub-claim | Attack result |
|-----------|----------------|
| Clean ≡ decompiler CF | **Not broken** for sampled axis regions; section comments are non-executing. |
| Bit-for-bit vs loaded image | **Not proven.** Project explicitly DEFERRED. Decompiler float10 / cast noise may differ from assembly. |
| `undefined4`→`uint32_t` rename | Harmless for structure; not a proof of type. |

**Severity:** Low for RE navigation; **blocking** for “bit-exact complete” matrix cells.

---

### Claim 2 — ActionMap name bindings (Accel/Reverse/SteerL/R/Soft/Brake)

| Sub-claim | Attack result |
|-----------|----------------|
| DAT addresses exist as held-char samples | **Not broken** — decompile loads those globals. |
| Names Accel/Reverse/SteerL/… are correct | **Weak.** Names come from Ghidra plate `WI-MOV-001` and system map, not from an ActionMap string dump in this unit’s artifacts. |
| Spacing `0x34` ActionMap stride | Mentioned in PollBoundActions plate; **not re-proven** as layout of `d1bc26` cluster here. |

**Alternate:** DATs could be remapped by a different ActionMap generation; plate could be outdated relative to a custom bind set.

**Severity:** Medium for ports that hardcode bind semantics without verifying ActionMap.

---

### Claim 3 — Soft L/R polarity (UF-006)

| Sub-claim | Attack result |
|-----------|----------------|
| Soft path writes ±0.5 bit patterns | **Not broken** — re-sealed 2026-07-29 via image `push` immediates (`0x00922c48` = `0xbf000000`, `0x00922cf8` = `0x3f000000`) plus fresh decompile. |
| SoftL = left, SoftR = right (physical) | **Still BROKEN as proven.** Soft `d1bd2a` → `-0.5`, soft `d1bcf6` → `+0.5`. Hard left is `+1`, hard right is `-1`. If soft names track hard names, soft is **sign-inverted** vs hard. If soft names are wrong, labels need fix. |
| Clean comments stating SoftL→-0.5 SoftR→+0.5 | Matches body; **must not** be read as “soft left = same sign as hard left.” |
| “Fix” by flipping soft immediates in clean | **Attack fails as RE action.** Retail image has those bits; flipping would invent a port-only patch. Residual is documentation / runtime, not body rewrite. |

**Severity:** Medium for steering feel in ports; documented as UF-006. **Body magnitudes sealed; polarity residual open.**

#### Soft/hard evidence table (adversarial residual)

| Flag | Role (plate) | Immediate | f32 | Sign vs counterpart |
|------|--------------|-----------|----:|---------------------|
| `DAT_00d1bc8e` | Hard L | `0x3f800000` | +1.0 | baseline hard left |
| `DAT_00d1bcc2` | Hard R | `0xbf800000` | −1.0 | baseline hard right |
| `DAT_00d1bd2a` | Soft L (plate) | `0xbf000000` | −0.5 | **opposite** hard L if label correct |
| `DAT_00d1bcf6` | Soft R (plate) | `0x3f000000` | +0.5 | **opposite** hard R if label correct |

Display-name strings (“Steer Left Soft” / “Steer Right Soft”) in InitActionDisplayNames are **not** sufficient to seal DAT identity — need bind table or hold-key CE.

---

### Claim 3b — Analog path is “fully mapped”

| Sub-claim | Attack result |
|-----------|----------------|
| Analog present when `DAT_00d1b618` non-null and returns non-zero | **Not broken** (structural). |
| Samples thr/steer deltas via `DAT_00d1b620` channels 6/7 and 9/10 | **Not broken** (decompile). |
| Drive branch writes continuous floats to same setters | **Not broken.** |
| Full deadzone / scale / device identity | **Overclaim if sealed** — clamp `DAT_00aaa668` observed; continuous mapping still partial. |
| Analog and digital are independent simultaneous writers | **Partially attacked:** digital thr clear and steer clear **skip** when analog active — partial mutual exclusion, not dual-write merge. |

**Severity:** Medium for gamepad parity; Low for digital keyboard path.

---

### Claim 4 — `vehicle+0x101` is “drive disabled / suppress apply”

| Sub-claim | Attack result |
|-----------|----------------|
| Flag gates axis writes and Push | **Not broken** (structural). |
| Semantic name | **Overclaim if sealed.** Could be dead/despawned/remote/cinematic. |
| Interaction with `+0x109` clear on thr paths | Observed clears when applying thr; **meaning of +0x109** still open. |

**Severity:** Low for CF; medium for TYPE_REGISTRY naming.

---

### Claim 5 — Handbrake is only `DAT_00d1bd5e`

| Sub-claim | Attack result |
|-----------|----------------|
| Continuous latch uses `d1bd5e` + analog ch 8 | **Not broken.** |
| Early SECTION 8 also samples `d1bd5e`/`d1bd5f` | **Not the same as handbrake.** Air-stab / impulse countdown path — conflating with HB is a category error. |
| SetHandbrake has no 0xC7 gate | **Not broken** (setter unit). |

**Severity:** Medium if readers collapse SECTION 8 into “handbrake.”

---

### Claim 6 — Steer is pushed with thr/handbrake

| Sub-claim | Attack result |
|-----------|----------------|
| `PushDriveAxesToController` copies thr + HB | Supported by system map / prior art. |
| Steer `+0x618` also pushed | **Attacked and fails** if claimed — system map and Push notes say steer is **not** copied; applyAction reads entity. Clean SECTION 14 correctly says NOT steer. |

**Severity:** Critical only if a port assumes DI gets steer from Push.

---

### Claim 7 — Full function is “drive control only”

| Sub-claim | Attack result |
|-----------|----------------|
| Function also does camera, terrain cast, QB skills, secondary weapons | **Not broken** — body is multi-purpose. |
| Treating unit as pure axis mapper | **Overclaim.** Secondary sections 8–12, 15 are large and incomplete semantically. |

**Severity:** Medium for work-queue scoping; clean SECTION index correctly flags secondary work.

---

### Claim 8 — Cross-linked setters implement signs

| Sub-claim | Attack result |
|-----------|----------------|
| SetSteer/SetLongitudinal store caller float | **Not broken.** |
| Setters apply Accel=-1 etc. | **BROKEN if claimed inside setters.** Signs live only in DriveControlTick (and other callers). Review A correctly attributes signs to this unit. |

---

## 4. What survives attack

1. Immediate bit patterns for digital thr/steer/soft/HB as listed in §2.A (**soft ±0.5 re-confirmed by image push 2026-07-29**).
2. Drive-enable gate on `+0x101` for digital axis writes + Push.
3. Setter addresses and roles (gate+store thr/steer; ungated HB).
4. Clean CF fidelity to raw for axis regions (no invented branches in SECTION comments).
5. Soft vs hard polarity tension is real and must stay open (UF-006) — **do not invent a fix**.
6. Soft/hard exclusive priority order (hard-R → hard-L → soft-L → soft-R → clear).
7. Analog SECTION 3 structural CF (presence, channels, drive vs camera branch, setter continuous write).

---

## 5. What does **not** survive as sealed

1. ActionMap **string** names for each DAT without table dump / runtime.
2. SoftL/SoftR physical direction labels (UF-006 residual).
3. Full secondary-branch semantics (camera, air-stab, combat modes) — UF-003.
4. Bit-exact completeness / runtime matrix cells.
5. Semantic names for `+0x101`, `+0x109`, `+0xa31` latches beyond structural use.
6. Full analog deadzone / scale / device identity.

---

## 6. Concrete checks performed

| # | Check | Result |
|---|-------|--------|
| 1 | Count of thr ±1 immediates in clean | Accel `0xbf800000` ×1, Reverse `0x3f800000` ×1 |
| 2 | Count of hard/soft steer immediates | Hard ±1 ×1 each; soft ±0.5 ×1 each |
| 3 | `SetHandbrake(1)` ×1 in continuous path region | Present |
| 4 | `PushDriveAxesToController` ×1 | Present, after HB section |
| 5 | Fresh Ghidra decompile vs raw key markers | Match (2026-07-23 and 2026-07-29) |
| 6 | Setter bodies contain no Accel constants | Confirmed via setter raws/reviews |
| 7 | Soft vs hard sign pairing | Soft signs invert relative to hard L/R if labels share meaning |
| 8 | Image `push 0xbf000000` @ soft-L call site | **Confirmed** `0x00922c48` (`read_memory`) |
| 9 | Image `push 0x3f000000` @ soft-R call site | **Confirmed** `0x00922cf8` |
| 10 | Analog thr clear skip when `DAT_00d1b618` active | Present in reverse-clear branch |
| 11 | Steer clear skip when analog active | Present before `SetSteerInput(0)` |

---

## 7. Verdict

**needs-more-evidence** to seal the unit as **complete** (UF-003 residual secondary branches, UF-006 label polarity, runtime, callers).

**Soft-steer body residual is sealed** (magnitudes, hex, priority, image immediates). **UF-006 remains open** for label↔physical only.

**Body reconstruction for drive-axis paths is not falsified** — clean may be used as the working exact surface for ports of thr/steer/HB with the documented gaps.

Do **not** promote verification matrix to complete without: (a) soft-bind runtime for UF-006, (b) caller map, (c) secondary-branch notes at least to “indexed incomplete.”

---

## 8. Required links (must remain)

| Symbol | VA | Stable |
|--------|-----|--------|
| `VehicleEntity_SetSteerInput` | `0x004f5620` | `aa_004f5620` |
| `VehicleEntity_SetLongitudinalInput` | `0x004f5650` | `aa_004f5650` |
| `VehicleEntity_SetHandbrake` | `0x004f3620` | `aa_004f3620` |
| `Client_Input_DriveControlTick` | `0x009223b0` | `aa_009223b0` |
