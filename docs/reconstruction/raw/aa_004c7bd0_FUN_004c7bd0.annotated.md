# Annotated low-level: CVOGCreature_SlewFacingYaw_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004c7bd0` |
| VA | `0x004c7bd0`–`0x004c7fc1` |
| Ghidra name | `FUN_004c7bd0` |
| Canonical name | `CVOGCreature_SlewFacingYaw_Inferred` |
| System | creature / facing / aim |
| Date | 2026-07-29 (W22-J dual seal) |
| Former scaffold | `Named_CalleeOf_CVOGCreature_SetupGraphics_004c7bd0` — parent seed only |

## Machine-level notes

- **ABI:** `__thiscall`; ECX = creature/object*; stack `int deltaMs`; **`RET 4`**; void.
- **Write:** only `*(float*)(this+0x11c)` — facing/yaw residual (radians).
- **Rate:** `(1 - align) * uintMs_as_float * 0.001f * 9.6f` with wrap on `[0, 2π)`.
- Prefer decompile CF; constants sealed via `read_memory` (no `disassemble_bytes`).

## Control flow

```
if *(this+8)==0: return
extract pose X from host(+0x3c)+0x30 via FUN_004e8a40 → local_40..
if !_finite(local_40): return

aimObj = *(layout + 0xa4)
if aimObj==0 OR !(flags>>5 & 1) OR phys body null:
  if (id108 & id10c)==~0 AND byte(id110)==0: return   // no valid aim
  targetXZ = copy float3 from world-camera-ish slot (+0xa8 → +0xe894)+0x11c
else:
  targetXZ = poseXZ + FUN_00404c90() offset (phys path)

selfXZ = host ? host+0x3c+0xb0 : layout+0x84
deltaXZ = target - self
if sqrt(dx²+dz²) <= 1.192e-7: return

unitDir = normalize(dx, 0, dz)     // Y forced 0
angle = Math_AcosClamped(…)        // FUN_0040d0a0; float stack arg
basis = FUN_004e8ad0(host pose / layout+0x94)
if (basis · e_x-ish) < 0: angle = 2π - angle
combined = wrap_2pi(angle + yaw0)
sin/cos(combined); align = dot(heading, unitDir)
if align >= 0.999: return

step = (1 - align) * u32_as_float(deltaMs) * 0.001 * 9.6
side = cross2(heading, unitDir) sign
newYaw = wrap_2pi( (side>=0 ? combined-step : combined+step) - angle )
*(this+0x11c) = newYaw
```

## Pseudocode (annotated)

```c
// __thiscall; ECX = creature*; stack int deltaMs; RET 4
// Canonical: CVOGCreature_SlewFacingYaw_Inferred
void __thiscall CVOGCreature_SlewFacingYaw_Inferred(int pCreature, int deltaMs)
{
  float align, s, c, inv, step, yaw0, ang;
  float pos[3];          /* local_40, local_3c, local_38 */
  float dir[3];          /* local_30, local_2c, local_28 — Y forced 0 */
  float basisScratch[7]; /* local_20 */
  int host;
  float *pSelf;
  float *pTgt;

  if (*(int *)(pCreature + 8) == 0) {
    return;
  }
  FUN_004e8a40(*(int *)(*(int *)(pCreature + 8) + 0x3c) + 0x30, &pos);
  if (_finite((double)pos[0]) == 0) {
    return;
  }

  /* aim path selection: linked phys vs free / camera slot */
  /* … see raw for full branch; produces dir.x/dir.z absolute then subtract self … */

  host = *(int *)(pCreature + 8);
  if (host == 0) {
    pSelf = (float *)(*(int *)(*(int *)(pCreature + 4) + 4) + 0x84 + pCreature);
  } else {
    pSelf = (float *)(*(int *)(host + 0x3c) + 0xb0);
  }
  dir[0] -= pSelf[0];
  dir[2] -= pSelf[2];

  {
    float d2 = dir[2]*dir[2] + dir[0]*dir[0];
    if (!(DAT_009cb8d4 < SQRT(d2))) {   /* 1.192e-7f */
      return;
    }
    inv = (d2 == 0.0f) ? 0.0f : (g_flOne / SQRT(d2));
    dir[0] *= inv;
    dir[2] *= inv;
    dir[1] = 0.0f;                      /* horizontal only */
    yaw0 = *(float *)(pCreature + 0x11c);
    ang = (float)FUN_0040d0a0(/* unit component — Math_AcosClamped */);
    /* basis extract; if forward.x < 0: ang = 2π - ang */
    /* combined = wrap_2pi(ang + yaw0); sin/cos; align = dot */
    if (align < 0.999 /* double @ 0x009cbab8 */) {
      float ms = (float)deltaMs;
      if (deltaMs < 0) {
        ms += 4294967296.0f;             /* DAT_00aaa5dc */
      }
      step = (g_flOne - align) * ms * g_flMsToSeconds_Inferred * 9.6f;
      /* signed slew by 2D cross sign; subtract ang; wrap → store +0x11c */
      *(float *)(pCreature + 0x11c) = /* wrapped residual */;
    }
  }
  return;
}
```

## Constants

| Symbol | VA | Value | Role |
|---|---|---|---|
| `DAT_009cb8d4` | `0x009cb8d4` | `1.1920929e-7f` | min horizontal distance |
| `DAT_00aaa7dc` | `0x00aaa7dc` | `≈6.283185f` | `2π` wrap |
| `DAT_009cbab0` | `0x009cbab0` | `9.6f` | yaw rate scale |
| `DAT_009cbab8` | `0x009cbab8` | double `0.999` | align threshold |
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | `≈0.001f` | ms→s |
| `DAT_00aaa5dc` | `0x00aaa5dc` | `2^32` | uint ms bias |
| `g_flOne` | `0x00a0f2a0` | `1.0f` | normalize / (1-align) |
| `DAT_00aaa668` | `0x00aaa668` | `-1.0f` | used in unit/acos path |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 + write `+0x11c` | **High** |
| 2π wrap + 9.6 * ms * 0.001 rate | **High** |
| Horizontal XZ slew (Y zeroed) | **High** |
| Creature/facing role | **High** structural |
| Exact acos argument component | **Medium** (decompiler elides formal) |
| Aim slot English (`+0xe894+0x11c`) | **Medium** |
| Product name | **Tentative** (`_Inferred`) |
