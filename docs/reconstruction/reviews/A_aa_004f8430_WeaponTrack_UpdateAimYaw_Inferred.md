# Review A (reconstruction fidelity): `aa_004f8430` WeaponTrack_UpdateAimYaw_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8430` |
| **VA** | `0x004f8430` |
| **Canonical name** | `WeaponTrack_UpdateAimYaw_Inferred` (was `FUN_004f8430`) |
| **Ghidra symbol** | `FUN_004f8430` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — weapon-track residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f8430_WeaponTrack_UpdateAimYaw_Inferred.md` |
| **System** | combat / vehicle weapon-track aim |
| **Callers** | `Vehicle_CreateWeaponTrackAction` `0x005a4f60`, `WeaponTrackAction_OnHeartBeat` `0x005a5020` |
| **Callees** | `FUN_004e8a40` (basis/pos extract), `FUN_004e9530`, `Object_GetWorldPositionPtr` `0x00404c90`, `Math_AcosClamped` `0x0040d0a0`, `FUN_005a53e0`, `Object_SetSelectedTarget`, `_finite`, `fsin`/`fcos`, RTTI cast to `CVOGPhysicsBase` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Per-tick weapon-track aim yaw update** on the vehicle (this = track/vehicle view used by HB action).

Gates: requires `this+8 != 0` (host/hardpoint chain) **and** selected-object slot on clonebase chain (`*( *( *(this+4)+4 ) + 0xb0 + this ) != 0`).

CF (live decompile):

```
extract hardpoint basis → local_30..local_28 via FUN_004e8a40(host+0x3c+0x30)
if !_finite(local_30): return

// Resolve aim target XZ (local_20, local_18):
//  - if no valid phys-selected target (RTTI CVOGPhysicsBase, bit @+0x17c>>5, body+8):
//      free-slew mode (bVar3) when flag this+0x103==0
//      else offset hardpoint +0xb0/+0xb8 or FUN_004e9530 float3
//  - else: world pos of selected via GetWorldPositionPtr; optional relative add if self;
//      may retarget track action +0x284 slot via FUN_005a53e0

dt = (g_dwClientTickMs - this+0x140) as seconds; stamp this+0x140 = tick
// unsigned wrap: if signed dt < 0 add _DAT_00aaa5dc

if free-slew (bVar3):
  // approach stored aim target yaw this+0x15c → current this+0x158
  wrap delta into (-π, π]; rate-limit by dt * 2π; clamp small-angle scale
  wrap result into [0, 2π); store this+0x158
else:
  // aim toward target XZ delta (or fallback this+0x170/0x178 velocity when ‖vel‖ large)
  if ‖delta_xz‖ > eps:
    if ‖delta‖ > 240 and selected has flag path → Object_SetSelectedTarget(null); return
    normalize delta; angle via AcosClamped + sign from host forward
    sin/cos of (angle + current yaw); compare forward·delta to thresholds
    if below threshold: slew this+0x158 by ± dt*2π * scale (cross product side)
    store this+0x158; return
```

**Not** heat/fire cost. Pure orientation / selected-target aim for weapon track HB (30 ms).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004f8430` |
| Callers | `get_function_callers` → `005a4f60`, `005a5020` |
| Constants | `read_memory` (see §4) |
| Related duals | `A_aa_005a5020_*`, `A_aa_005a4f60_*`, `A_aa_0040d0a0_Math_AcosClamped` |
| Raw / clean | `raw/aa_004f8430_*`, `FUN_004f8430.cpp` |

---

## 3. Signature

```c
// ECX = vehicle / weapon-track host (offsets 0x103, 0x140, 0x158, 0x15c, 0x170.., 0x260, 0x284)
void __fastcall WeaponTrack_UpdateAimYaw(VehicleWeaponTrackHost *this);
```

---

## 4. Constants (read_memory)

| Addr | Hex LE | Float | Role |
|---|---|---|---|
| `0x00af18a0` / `0x00aaa7dc` | `da0fc940` | **2π ≈ 6.283185** | Full-turn wrap / slew rate scale |
| `0x009cd1f0` | `da0f49c0` | **−π** | Angle wrap low |
| `0x009cd110` | `da0f4940` | **+π** | Angle wrap high |
| `0x009cd1f8` | `da0fc93e` | **≈0.3927 (π/8)** | Small-angle scale gate |
| `0x00a10e78` | `cdcc4c3d` | **0.05** | Min slew scale floor |
| `0x00aaa668` | `000080bf` | **−1.0** | Negative side for free slew |
| `0x009cd10c` | `00000034` | **≈1.19e−7** | Near-zero length eps |
| `0x009cd1fc` | `00007043` | **240.0** | Clear-target distance gate |
| `0x00a1109c` | `00002042` | **40.0** | Dot-threshold distance band |
| `0x00aaa948` / `0x00aaa660` / `0x00a111a8` | ~`3f7f…` | **≈0.999–1.0** | Forward·target cosine thresholds |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| HB weapon-track aim step (not heat) | **High** (callers) |
| Writes aim yaw at `this+0x158` | **High** |
| dt from `g_dwClientTickMs` vs `this+0x140` | **High** |
| Free-slew vs target-aim branches | **High** CF |
| Clear selected when far (240) + flag | **High** |
| Exact hardpoint / clonebase English names | **Medium** residual |
| Full float-const semantic for every band | **Medium** (values pinned; product meaning residual) |

**Verdict:** **accept-with-gaps**
