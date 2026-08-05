# Review A (reconstruction fidelity): `aa_0091d660` Client_Vehicle_AutoUnstickTiltKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091d660` |
| **VA** | `0x0091d660`–`0x0091da67` |
| **Canonical name** | `Client_Vehicle_AutoUnstickTiltKick_Inferred` (Ghidra `FUN_0091d660`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ constants) |
| **Counterpart** | `reviews/B_aa_0091d660_Client_Vehicle_AutoUnstickTiltKick_Inferred.md` |
| **System** | `input-drive-control` / client vehicle assist (physics kick) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `read_memory` on constants / xrefs. Prefer decompile/`read_memory`. Own VA only. No ledgers. Sibling dual: `aa_0091d460` random-up kick; apply helper `aa_00404cb0`.

---

## 1. Purpose

**Tick-driven auto-unstick** for the local player vehicle when chassis up-axis Y is below a tilt threshold for long enough (or enough low-speed pulses): build a **mostly-upward random float4**, scale by **`(1/mass)*10`**, apply via **`FUN_00404cb0`** (`vtbl+0x5c`), then enqueue a **5 s** `CVOGHBBase` action and start it.

**Signature:** `void FUN_0091d660(float dt)` — stack float (caller `PUSH` then `CALL` @ `0x00924669`).

**High-level algorithm (live decompile ≡ raw):**

1. `vehicle = *(DAT_00d1b6d8 + 0x250)` (0 if no game).
2. Require vehicle; SEH frame; component-chain vfunc **`+0x198` returns 0**; `vehicle+0x101 == 0`.
3. `DAT_00d1f0c0 += dt` (upright-recovery timer / sample accumulator).
4. Load world orientation quat: physics path `*(vehicle+8)+0x3c → +0x30` else component fallback `+0x94`.
5. `FUN_004e8b60(quat, out)` — extracts up-basis; **`out[1]` = up.y** (see sibling basis extract; factor `g_flLevelUpUiBase_Inferred` = **2.0** @ `0x00a10e74`).
6. Tilt threshold `t = DAT_00a0f70c` (**0.2**); if special mode (`vehicle+600` chain `+0x4ce == 2`) use `DAT_00a0f720` (**0.4**).
7. If `t ≤ up.y`: clear stuck time `DAT_00d1f0bc` and pulse count `DAT_00d1f0c4`.
8. Else (tilted): if physics present, **speed** `‖v‖` from body `+0x40..+0x48` **&lt; `g_flVehicleHpTechCoeff`** and `DAT_00d1f0c0 > 0.2`: `DAT_00d1f0c4++`, reset `DAT_00d1f0c0`. Always `DAT_00d1f0bc += dt` while tilted.
9. Fire when **`DAT_00d1f0c4 > 3`** (`DAT_00afe2ac` = **3**) **OR** **`DAT_00d1f0bc > 4.0`** (`_DAT_00afe2a8` = **4.0f**):
   - Clear counters.
   - Draw **3× u16** from RNG host (`CVOGReaction_RandomUnitScalar` / `0x007a4330` table; wrap index ≥ `0x100000`).
   - Map: `u * DAT_00aaa638 − 0.5` with `DAT_00aaa638 ≈ 1/65535`, `DAT_00a0f298 = 0.5`; two axes × **2.0**.
   - Normalize xyz; scale `(1/mass)*DAT_00a110d8` with `DAT_00a110d8 = **10.0**`; mass at body `+0x2c`.
   - `vec = scale * (inv * rand_comp * 0.3 + base)` with base **`(0,1,0,0)`** from `DAT_00afda50` block; `g_flOverheatCoolFrac = 0.3`.
   - `FUN_00404cb0(&vec)` (physics thiscall — same family as `0091d460`).
   - `operator_new(0x2c)` → `FUN_005075f0(vehicle, 5000)` HB action → `CVOGHBList_Enqueue` → `CVOGHBBase_Start`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0091d660_*`, `reconstructed-exact/FUN_0091d660.cpp` |
| Function record | `functions/aa_0091d660_FUN_0091d660.md` |
| Live decompile | ≡ raw CF |
| Constants | `read_memory` `a0f70c/a0f720/afe2a8/afe2ac/a0f298/aaa638/a110d8/afda50/a10e74/a0f714` |
| Basis helper | live decompile `FUN_004e8b60` (up extract) |
| Apply helper | dual `aa_00404cb0` |
| Sibling kick | dual `aa_0091d460` (edge-triggered; mass×12; 2 RNG) |
| Xrefs | **1** site `0x00924669` (`PUSH` float then `CALL`) |

**Not performed:** Launcher; exact enclosing parent name at `0x00924669` (Ghidra has no function wrapper at that VA); product ActionMap bind; bit-exact.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| dt stack arg + sole site `0x00924669` | **High** | asm push + bulk xrefs |
| Gates: vehicle, vfunc+0x198==0, +0x101==0 | **High** | same family as sibling kick |
| up.y from `FUN_004e8b60` out[1] | **High** | helper decompile; stack layout `fStack_2c` |
| Thresholds 0.2 / 0.4 | **High** | `cdcc4c3e` / `cdcccc3e` |
| Fire: count>3 OR time>4.0 | **High** | `afe2ac=3`, `afe2a8=4.0f` |
| 3 RNG u16 + map via 1/65535 − 0.5 | **High** | `aaa638`, `a0f298` |
| Base (0,1,0,0) + 0.3 * unit-ish | **High** | `afda50` + `a0f714` |
| Scale (1/mass)*10 | **High** | `a110d8=10.0`; contrast sibling ×12 |
| Apply via `FUN_00404cb0` not drive axes | **High** | callees list |
| 5 s HB enqueue+start | **High** | `FUN_005075f0(...,5000)` |
| Special mode `+0x4ce==2` → 0.4 threshold | **High CF** | product mode English open |
| `g_flVehicleHpTechCoeff` numeric | **Open value** / **High role** | low-speed gate; Ghidra name may be misnomer |
| Product English “unstick” | **Inferred** | no string; behavior-based |
| Runtime | **Open** | deferred |

---

## 4. Constants (`read_memory`)

| Symbol | VA | LE bytes | Value | Role |
|---|---|---|---|---|
| `DAT_00a0f70c` | `0x00a0f70c` | `cd cc 4c 3e` | **0.2** | default up.y threshold |
| `DAT_00a0f720` | `0x00a0f720` | `cd cc cc 3e` | **0.4** | special-mode threshold |
| `_DAT_00afe2a8` | `0x00afe2a8` | `00 00 80 40` | **4.0** | max tilted time (s) |
| `DAT_00afe2ac` | `0x00afe2ac` | `03 00 00 00` | **3** | max low-speed pulses (int) |
| `DAT_00a0f298` | `0x00a0f298` | `00 00 00 3f` | **0.5** | RNG center |
| `DAT_00aaa638` | `0x00aaa638` | `80 00 80 37` | **≈1/65535** | u16→[0,1] |
| `DAT_00a110d8` | `0x00a110d8` | `00 00 20 41` | **10.0** | mass scale factor |
| `g_flOverheatCoolFrac` | `0x00a0f714` | `9a 99 99 3e` | **0.3** | random blend weight (name misnomer here) |
| `g_flLevelUpUiBase_Inferred` | `0x00a10e74` | `00 00 00 40` | **2.0** | quat factor + two RNG axes |
| `DAT_00afda50` block | `0x00afda50` | `0,1,0,0` | base dir | mostly +Y |

---

## 5. Formula (sealed CF)

```
vehicle = *(DAT_00d1b6d8 + 0x250)
require vehicle && vfunc_0x198(chain)==0 && *(u8*)(vehicle+0x101)==0

DAT_00d1f0c0 += dt
up = ExtractUp(quat)                 // FUN_004e8b60; use up.y
t = (special_mode) ? 0.4f : 0.2f

if up.y >= t:
  DAT_00d1f0bc = 0; DAT_00d1f0c4 = 0
else:
  if physics && |vel| < speedThresh && DAT_00d1f0c0 > 0.2:
    DAT_00d1f0c4++; DAT_00d1f0c0 = 0
  DAT_00d1f0bc += dt

if DAT_00d1f0c4 > 3 || DAT_00d1f0bc > 4.0:
  clear counters
  draw 3×u16; map to signed; *2 on two axes; normalize
  s = (mass==0)?0:(1/mass)*10
  vec = s * (inv*r*0.3 + (0,1,0,0))
  FUN_00404cb0(physics, &vec)        // vtbl+0x5c
  HB = FUN_005075f0(vehicle, 5000); Enqueue; Start
```

---

## 6. Gaps / open

1. Product name / ActionMap (none in body).
2. Numeric value of `g_flVehicleHpTechCoeff` (role sealed).
3. English for special mode `+0x4ce==2`.
4. Parent function at call site `0x00924669`.
5. Runtime golden vs sibling edge kick.

**Verdict:** **accept-with-gaps** — tilt timers, thresholds, RNG map, mass×10 apply, HB 5s enqueue, sole xref sealed; product/runtime/speed-const open.
