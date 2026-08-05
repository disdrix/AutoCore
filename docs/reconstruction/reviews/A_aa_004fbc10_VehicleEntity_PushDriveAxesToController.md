# Review A (reconstruction fidelity): `aa_004fbc10` VehicleEntity_PushDriveAxesToController

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbc10` |
| **VA** | `0x004fbc10` |
| **Body span** | `004fbc10` – `004fbeb2` |
| **Canonical name** | `VehicleEntity_PushDriveAxesToController` |
| **Review date** | `2026-07-29` (dual residual strengthen **pass 2** — live Ghidra; supersedes thin wave2 scaffold + pass-1 static seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004fbc10_VehicleEntity_PushDriveAxesToController.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present and strengthened** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bridge from **entity drive axes** into the **input controller** block after thr/HB writers run:

1. Gate: `entity+0x101 == 0` **and** `entity+0x1a0 != 0`.
2. `ctrl = *(entity+0x1a0) + 8`; clear `ctrl+0x25 = 0`.
3. Hard-stop (`entity+0x109 != 0`): `ctrl+0x20 = 0`, `ctrl+0x24 = 1`, **return** (does **not** copy `entity+0x61c`).
4. Else copy thr: `ctrl+0x20 ← entity+0x614` (sign preserved; Accel=**−1**, Reverse=**+1** at producers).
5. If `ctrl+0x19 != 0` and thr **≥** `DAT_00a0f734` (**0.9**), store **0.9** (positive ceiling only — **not** ±0.9).
6. Derive `local_3c` (max speed) from `FUN_004c4e20` base + bonus modifiers + AbsoluteTopSpeed clamp.
7. If `local_3c < entity+0x10c`, may **zero** `ctrl+0x20` when thr would push further along travel polarity.
8. Normal exit: `ctrl+0x24 ← entity+0x61c` (handbrake byte).

**Steer `entity+0x618` is never read or written** — applyAction ramps it into Havok `VehicleAction`.

**Calling convention:** MSVC `__fastcall` / `__thiscall` — entity `this` in **ECX**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fbc10_VehicleEntity_PushDriveAxesToController.md` |
| Annotated | `docs/reconstruction/raw/aa_004fbc10_VehicleEntity_PushDriveAxesToController.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_PushDriveAxesToController.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fbc10_VehicleEntity_PushDriveAxesToController.md` |
| Verified physics | `docs/reconstruction/physics/verified/fn_004fbc10_pushDriveAxes.md` |
| Basis extract | `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md` |
| Entity axes type | `docs/reconstruction/types/VehicleEntity_drive_axes.md` |
| System map | `docs/reconstruction/systems/input-drive-control.md` |
| Sibling setters | `aa_004f5650` thr, `aa_004f5620` steer, `aa_004f3620` HB |
| Prior dual | thin wave2 A/B 2026-07-23; pass-1 residual 2026-07-29 (MCP-unavailable note) |
| Scratch | `tmp/a_004fbc10.md` |

**This pass (live):** Ghidra MCP `decompile_function` @ `0x004fbc10`, `0x004c4e20`, `0x00404a20`, `0x004e8a40`; `read_memory` re-verify of all thr/bonus constants + `DAT_00b037d4`. **Not performed:** Launcher, runtime golden, bit-exact binary diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Entry gate `+0x101==0` ∧ `+0x1a0!=0` else full no-op | **High** | Live decompile ≡ raw first `if` |
| `ctrl = *(entity+0x1a0)+8` | **High** | Live |
| `ctrl+0x25 = 0` on entry | **High** | Live |
| Hard-stop `+0x109` → thr0, HB1, return (skips `+0x61c` copy) | **High** | Live early return |
| Thr copy `+0x614 → ctrl+0x20` (no negate/abs) | **High** | Live |
| `ctrl+0x19` clamp uses **positive ceiling 0.9 only** | **High** | `DAT_00a0f734 <= thr`; LE `66 66 66 3f` re-read |
| HB normal path `+0x61c → ctrl+0x24` | **High** | Last store on non-stop path |
| Steer `+0x618` not touched | **High** | Zero body references; applyAction consumer |
| Speed-cap compare is `local_3c < entity+0x10c` | **High** | Live `if (local_3c < fVar9)` after `fVar9 = *(+0x10c)` |
| Compare is **not** direct `\|v\| > max` | **High** | `SQRT` result reused as basis storage; SSA dead |
| Overspeed zeros thr that continues travel direction | **High CF** | Polarity table from `dot(vel, forward)` + thr sign |
| Max formula `(bonus+1)*baseMax` then top-speed clamp | **High structure** | Live; AbsoluteTopSpeed at `vehicleData+0x634` |
| **`FUN_004c4e20` body** | **High (sealed this pass)** | Returns `*(entity+0x1f4)` (= +500); optional `+ *(driver+0xd48)` when `DAT_00b037d4` |
| Bonus ±0.3/0.5 + AbsoluteTopSpeed sentinel −1 | **High** | `read_memory` re-verified this pass |
| Input controller layout-distinct from Havok `VehicleAction` | **High** | `ctrl+0x24` u8 HB vs VA `+0x24` f32 steer |
| `FUN_00404a20` / `FUN_004e8a40` product roles | **High** | Quat basis @ phys `+0x30` / entity `+0x94`; forward from unit quat (×2.0) |
| `fStack_40` initial = 0 | **Probable (port)** | No store; stack reuse |
| Interaction of `DAT_00af1854` bonus `+0xd48` vs `FUN_004c4e20` `DAT_00b037d4` path | **High CF; product semantics open** | Two independent flags; image defaults `af1854=1`, `b037d4=0` |
| Runtime golden / thr-cap live | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Gate suppress + controller host | **Yes** |
| Clear `ctrl+0x25` | **Yes** |
| Hard-stop early return | **Yes** |
| Thr copy + optional 0.9 ceiling | **Yes** |
| Vel load (body / fallback `DAT_00b041b0`) | **Yes** |
| `+0x10c` load + `SQRT\|v\|` (dead reuse) | **Yes** |
| baseMax via wobj vfunc `0x1d8` + `FUN_004c4e20` | **Yes** |
| Driver `+0xd48` bonus under `DAT_00af1854` | **Yes** |
| Flag `0x1000`/−0.3 and `0x4000`/+0.5 adjust | **Yes** |
| AbsoluteTopSpeed clamp vs `DAT_00aaa668` (−1) | **Yes** |
| Overspeed polarity gate → may zero thr | **Yes** |
| HB copy last | **Yes** |
| No invent steer write / keyboard poll | **Yes** |

### 4.1 Overspeed polarity (sealed CF)

`forwardSpeed = dot(linVel, chassisForward)` after `FUN_00404a20` + `FUN_004e8a40`.

| Travel | `bVar7` true when | Zero thr when (`!bVar7 && thr != 0`) |
|--------|-------------------|--------------------------------------|
| `forwardSpeed > 0` | thr **> 0** (Reverse input) | thr ≤ 0 → zeros **Accel (negative)** |
| `forwardSpeed ≤ 0` | thr **< 0** (Accel input) | thr ≥ 0 → zeros **Reverse (positive)** |

Interpretation under Accel=−1 / Reverse=+1: when over the derived limit relative to `entity+0x10c`, thr that would **push further in the direction of travel** is cleared; opposing thr remains.

### 4.2 Max-speed derivation (structure + `FUN_004c4e20` sealed)

Live decompile of `FUN_004c4e20` @ `0x004c4e20`:

```
// param_1 = entity (same shape as PushDrive this)
driver = vfunc_0x210(component_chain(entity), 0)
if driver != 0 && DAT_00b037d4 != 0:
    baseMax = *(float*)(driver + 0xd48) + *(float*)(entity + 0x1f4)   // +500
else:
    baseMax = *(float*)(entity + 0x1f4)
```

PushDriveAxes outer formula (unchanged):

```
// baseMax from above, or 0 if wobj null / vfunc 0x1d8 fails before FUN_004c4e20
bonus   ≈ 0
        + driver+0xd48 when DAT_00af1854 && driver via vfunc 0x210   // separate flag
        − 0.3 when flag 0x1000 or (obj+0xb5 & 0x10)
        + 0.5 when flag 0x4000 or (obj+0xb5 & 0x40)
local_3c = (bonus + 1.0) * baseMax
if vehicleData+0x634 != −1.0 and vehicleData+0x634 < local_3c:
    local_3c = vehicleData+0x634
gate when local_3c < entity+0x10c
```

**Image defaults (this pass `read_memory`):** `DAT_00af1854 = 1`, `DAT_00b037d4 = 0` → baseMax is **only** `entity+0x1f4`; bonus **may** still include `driver+0xd48` multiplicatively via `(1+d48)*base`. If both flags ever set live, `+0xd48` participates in **both** base add and outer bonus — do not collapse flags.

### 4.3 Basis helpers (callee product roles)

| Addr | Role (sealed) |
|------|----------------|
| `FUN_00404a20` | If `entity+0x08 != 0`: return `*(*(+0x08)+0x3c) + 0x30` (quat on rigid body). Else: `*(*(entity+4)+4) + entity + 0x94`. |
| `FUN_004e8a40` | Unit-quat → **forward (+Z)**; scale constant `0x00a10e74` = **2.0** (see `fn_004e8ad0_basisExtract.md`). |

---

## 5. Layout (body-backed)

### Entity

| Offset | Type | Role |
|-------:|------|------|
| `+0x04` | ptr | link chain for `+0xb0` / `+0xb8` / `+0xac` / vfunc hosts |
| `+0x08` | ptr | physics wrapper; lin vel at `*(*(+0x08)+0x3c)+0x40`; quat at `…+0x30` |
| `+0x101` | u8 | drive-suppressed — must be 0 |
| `+0x109` | u8 | hard-stop |
| `+0x10c` | f32 | requested / target speed vs derived max |
| `+0x1a0` | ptr | input-controller holder |
| `+0x1f4` | f32 | **base max-speed field** (`FUN_004c4e20` return core; +500 decimal) |
| `+0x614` | f32 | thr source |
| `+0x618` | f32 | steer — **unread** |
| `+0x61c` | u8 | handbrake source |

### Input controller (`ctrl = *(host)+8`)

| Offset | Type | W? | Meaning |
|-------:|------|:--:|---------|
| `+0x19` | u8 | R | enable 0.9 thr ceiling |
| `+0x20` | f32 | **Y** | thr |
| `+0x24` | u8 | **Y** | handbrake |
| `+0x25` | u8 | **Y** | cleared 0 |

---

## 6. Constants (re-verified `read_memory` this pass)

| Symbol | Addr | LE bytes | float / value | Role |
|--------|------|----------|--------------:|------|
| `DAT_00a0f734` | `0x00a0f734` | `66 66 66 3f` | **0.9** | thr ceiling when `ctrl+0x19` |
| `DAT_00aaa668` | `0x00aaa668` | `00 00 80 bf` | **−1.0** | no AbsoluteTopSpeed sentinel |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** | `(bonus+1)*baseMax` |
| `g_flOverheatCoolFrac` | `0x00a0f714` | `9a 99 99 3e` | **0.3** | bonus penalty |
| `DAT_009cd0d8` | `0x009cd0d8` | `00 00 00 3f` | **0.5** | bonus add |
| `DAT_00af1854` | `0x00af1854` | `01` | **1** (u8) | enables outer driver `+0xd48` bonus path |
| `DAT_00b037d4` | `0x00b037d4` | `00` | **0** (u8 image) | enables `FUN_004c4e20` add of `driver+0xd48` to base |
| `g_flLevelUpUiBase_Inferred` | `0x00a10e74` | (prior) | **2.0** | quat→forward scale in `FUN_004e8a40` |

---

## 7. Gaps / open

1. Live-stack proof for initial `fStack_40` (port treat as 0).
2. Runtime / differential / bit-exact still open.
3. Product name for `entity+0x1f4` base-max field and driver `+0xd48` (speed bonus float).
4. Which object is `param_1` at `FUN_00404a20` call site (zero-arg decompile vs entity thiscall) — body offsets match entity shape; register wiring residual if ECX clobbered before call.
5. Dual-flag live semantics if both `af1854` and `b037d4` set at runtime.

**Verdict:** **accept-with-gaps** — dual residuals sealed at static CF level with **live re-decompile** and **`FUN_004c4e20` body seal**. Package not complete (runtime/diff).
