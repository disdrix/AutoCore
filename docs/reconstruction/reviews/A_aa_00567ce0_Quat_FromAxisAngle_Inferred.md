# Review A (reconstruction fidelity): `aa_00567ce0` Quat_FromAxisAngle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567ce0` |
| **VA** | `0x00567ce0`–`0x00567d13` |
| **Canonical name** | `Quat_FromAxisAngle_Inferred` (was `FUN_00567ce0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (leaf math helper) |
| **Counterpart** | `reviews/B_aa_00567ce0_Quat_FromAxisAngle_Inferred.md` |
| **System** | math / orientation (cross-cutting) |
| **Verdict** | **accept** — body + ABI + half-angle constant sealed |

---

## 1. Purpose

Leaf **axis–angle → unit quaternion** builder:

\[
q = \bigl(\sin(\theta/2)\,a_x,\; \sin(\theta/2)\,a_y,\; \sin(\theta/2)\,a_z,\; \cos(\theta/2)\bigr)
\]

where \(\theta\) is the full angle in **radians**, half-angle via global `DAT_00a0f298 = 0.5f`. No allocation, no logging, no class state beyond the out buffer in ECX.

Used heavily for orientation deltas (turret/weapon slot, camera look offset, AI pursue, creature graphics, skill gather area).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00567ce0_FUN_00567ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00567ce0_FUN_00567ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00567ce0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00567ce0_FUN_00567ce0.md` |
| Live Ghidra | `decompile_function` `0x00567ce0`; `analyze_function_complete`; `read_memory` body + `DAT_00a0f298` + `DAT_00af18b0` |
| Call-site bytes | `read_memory` `0x004f5510` (caller of this unit; weapon/slot path) |
| Prior role note | `A_aa_0091a5f0` labels this as half-angle quat build |

---

## 3. Signature (sealed)

```c
// ECX = out quat (float[4]); stack: axis ptr, angle radians; callee cleans 8 B
void /*__thiscall-like ECX first*/ Quat_FromAxisAngle_Inferred(
    float *pOutQuat,   // ECX
    float *pAxis,      // [esp+4] — reads float[4] (w used only for dead intermediate)
    float  flAngleRad  // [esp+8]
);
// Epilogue: RET 8
// Return: void (no EAX contract)
```

| Item | Evidence |
|---|---|
| Convention | Body: ECX dest stores; `fld [esp+8]`; `mov eax,[esp+4]`; epilogue **`C2 08 00` (`RET 8`)** |
| Leaf (no CALL) | `callees: []`; uses x87 **`FSIN` / `FCOS`** only |
| Body range | `0x00567ce0` … `0x00567d13` (next INT3 pad) |
| Half-angle | `FMUL dword ptr [DAT_00a0f298]`; `read_memory` → `00 00 00 3f` = **0.5f** |

Ghidra labels the ECX arg as `__thiscall` “this”; **semantically it is only the out quaternion buffer**, not a live C++ object with vtable.

---

## 4. Control flow (sealed)

```
half = angle * 0.5f                    // DAT_00a0f298
s    = sin(half)                       // FSIN
out[0] = s * axis[0]
out[1] = s * axis[1]
out[2] = s * axis[2]
out[3] = s * axis[3]                   // dead write (overwritten next)
out[3] = cos(half)                     // FCOS of half still on FPU stack
return
```

**No** axis normalize, **no** angle wrap, **no** null checks.

---

## 5. Machine bytes (`read_memory` @ `0x00567ce0`, 64 B)

```
D9 44 24 08          FLD  dword [esp+8]        ; angle
8B 44 24 04          MOV  eax, [esp+4]         ; axis*
D8 0D 98 F2 A0 00    FMUL dword [DAT_00a0f298] ; *0.5 → half
D9 C0                FLD  st0                  ; dup half
D9 FE                FSIN                      ; sin(half)
D9 C0                FLD  st0
D8 08                FMUL dword [eax]
D9 19                FSTP dword [ecx]          ; out.x
D9 C0                FLD  st0
D8 48 04             FMUL dword [eax+4]
D9 59 04             FSTP dword [ecx+4]        ; out.y
D9 C0                FLD  st0
D8 48 08             FMUL dword [eax+8]
D9 59 08             FSTP dword [ecx+8]        ; out.z
D8 48 0C             FMUL dword [eax+0xC]
D9 59 0C             FSTP dword [ecx+0xC]      ; out.w = s*axis.w (temps)
D9 FF                FCOS                      ; cos(half)  [half still under]
D9 59 0C             FSTP dword [ecx+0xC]      ; out.w = cos(half)
C2 08 00             RET  8
CC…                  INT3 pad
```

Hex (function body through `RET 8`):

`d94424088b442404d80d98f2a000d9c0d9fed9c0d808d919d9c0d84804d95904d9c0d84808d95908d8480cd9590cd9ffd9590cc20800`

Decompile ≡ bytes. **No conflict.** Decompiler’s intermediate `param_1[3] = sin * axis[3]` then overwrite is **real** (matches FPU), not a decompiler artifact.

---

## 6. Constants

| Symbol | VA | LE bytes | f32 | Role |
|---|---|---|---:|---|
| `DAT_00a0f298` | `0x00a0f298` | `00 00 00 3f` | **0.5** | half-angle scale |
| `DAT_00af18b0` (caller-owned) | `0x00af18b0` | `00 00 00 00 \| 00 00 80 3f \| 00 00 00 00 \| 00 00 00 00` | **(0,1,0,0)** | unit **+Y** axis used by weapon-slot / identity-angle callers |

---

## 7. Call-site ABI cross-check (`0x004f54f0` path)

`read_memory` @ `0x004f5510` (fragment):

```
MOV  ecx, [esp+4]       ; out = parent stack arg
PUSH 0                  ; angle = 0 → identity quat (0,0,0,1)
PUSH &DAT_00af18b0      ; axis = unit Y (unread for θ=0 except loads)
CALL FUN_00567ce0
…
MOV  ecx, [edx+0x158]
PUSH ecx                ; angle = vehicle+0x158
MOV  ecx, [esp+8]       ; out = parent stack arg
PUSH &DAT_00af18b0      ; axis = unit Y
CALL FUN_00567ce0
```

Confirms **ECX=out**, **[esp+4]=axis**, **[esp+8]=angle**. Ghidra’s two-arg display at some callers is **under-arity** (hides the axis push when constant).

---

## 8. Callers (context only; not owned)

~51 xrefs. Named/high-signal:

| Caller | Role note |
|---|---|
| `CVOGVehicle_GetWeaponSlotTransform` | slot orientation |
| `CVOGPlayerVehicle_UpdateTurretAiming` | turret |
| `Client` camera look (`FUN_0091a5f0` / DriveControlTick path) | look-scale orientation |
| `Skill_GatherTargetsInArea` / range helpers | area orientation |
| `CVOGCreature_UpdateGraphics` (`0x004c7490`) | graphics |
| `FUN_004f54f0` / `FUN_004f9030` | vehicle yaw about +Y via `DAT_00af18b0` |

---

## 9. Naming

| Name | Confidence | Notes |
|---|---|---|
| `Quat_FromAxisAngle_Inferred` | **High** role / **Inferred** product English | Standard half-angle formula; no RTTI/string |
| Scaffold `Named_CalleeOf_CVOGVehicle_GetWeaponSlotTransform_00567ce0` | **Low** as primary | Parent-seed only; many other parents |

Do **not** treat ECX as a quaternion *object* with methods — free-function buffer API.

---

## 10. Gaps (do not block seal)

1. Product symbol (no PDB/string).
2. Whether any caller passes non-unit axis (body does not normalize → non-unit quat).
3. Full caller catalog / per-site axis provenance.
4. Runtime live hit / bit-exact image diff.
5. Sibling matrix→quat `FUN_00567d20` not dualed here.

---

## Verdict

**accept** — leaf half-angle axis→quat sealed: ABI (`ECX` out, stack axis+angle, `RET 8`), `DAT_00a0f298=0.5`, FSIN/FCOS body, dead `axis[3]` intermediate write documented.
