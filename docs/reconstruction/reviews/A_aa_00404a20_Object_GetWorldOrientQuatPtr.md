# Review A (reconstruction fidelity): `aa_00404a20` Object_GetWorldOrientQuatPtr (FUN_00404a20)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404a20` |
| **VA** | `0x00404a20` |
| **Canonical name** | `FUN_00404a20` |
| **Probable role name** | `Object_GetWorldOrientQuatPtr` / entity world-orientation quaternion pointer getter |
| **System** | `shared-object-pose` (airStab, PushDriveAxes, turret aim, respawn, …) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00404a20_Object_GetWorldOrientQuatPtr.md` |
| **Verdict** | **accept** on CF / offsets / CC / leaf purity; product symbol **open** (role **High**) |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Thin **leaf getter**: given an entity/object `this` in **ECX**, return a **pointer to the world orientation quaternion** (4×f32 starting at returned address; consumers read `+0..+0xc` as xyzw, or pass the base into basis-extract helpers).

Two storage paths:

1. **Physics-attached:** if `this+0x08 != 0` (physics object / wrapper pointer),  
   `return *( *(this+8) + 0x3c ) + 0x30` → rigid-body **orientation quaternion** at `rb+0x30`.
2. **Entity fallback:** else  
   `return *( *(this+4) + 4 ) + this + 0x94` → embedded orientation at entity-relative **`+0x94`** (with clonebase/type offset from `*( *(this+4)+4 )`).

No writes, no callees, no globals.

**Twin of** `FUN_00404c90` @ `0x00404c90` (world **position** pointer: `rb+0xb0` / entity `+0x84`). Same CF skeleton; only the addend constants differ.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00404a20_FUN_00404a20.md` |
| Raw | `docs/reconstruction/raw/aa_00404a20_FUN_00404a20.md` |
| Annotated | `docs/reconstruction/raw/aa_00404a20_FUN_00404a20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404a20.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00404a20` (2026-07-29) |
| Live body bytes | Ghidra `read_memory` `0x00404a20` length 32 |
| Function range | entry `00404a20`, body `00404a20`–`00404a3b` |
| Twin pos getter | `FUN_00404c90` @ `0x00404c90` (same CF; offsets `0xb0` / `0x84`) — dual sealed |
| Prior verified map | `physics/verified/fn_offsets_rigidbody.md` §B pose helpers |
| Prior airStab use | `physics/verified/fn_00598320_airStab.md` (quat pack from this helper → basis) |
| Prior drive axes | `physics/verified/fn_004fbc10_pushDriveAxes.md` (chassis basis via this + `FUN_004e8a40`) |
| Callers (context only) | Ghidra `get_function_callers` — airStab, PushDriveAxes, UpdateTurretAiming, SendRespawnInSector, … |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of callers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf: no callees / no stores | **Confirmed** | decompile + body bytes |
| CC: `this` in **ECX** (`__fastcall` / thiscall-style) | **Confirmed** | `mov eax,[ecx+8]` / `mov eax,[ecx+4]` |
| Gate: `*(this+8) != 0` → physics path | **Confirmed** | `test eax,eax` / `jz` fallback |
| Physics path: `rb = *(*(this+8)+0x3c); return rb+0x30` | **Confirmed** | `mov eax,[eax+0x3c]` / `add eax,0x30` |
| Fallback: `lea eax, [edx+ecx+0x94]` with `edx = *(*(this+4)+4)` | **Confirmed** | body bytes |
| Return type = **pointer** (not quat by value) | **High** | consumers load 4 floats / pass to `FUN_004e8b60` / `FUN_004e8a40` |
| Returned slot = **orientation quaternion** | **High** | RB map `+0x30..+0x3c`; calcWheelTorque / airStab / PushDriveAxes |
| Product symbol name sealed | **Open** | Ghidra still `FUN_00404a20`; role name inferred |
| Fallback `*( *(this+4)+4 )` meaning (RTTI / clonebase offset) | **Probable** | classic MSVC this-adjust; not fully typed here |
| Clean ≡ raw ≡ live decompile CF | **Confirmed** | identity |
| Twin relationship to `00404c90` | **Confirmed** | same skeleton; addends `0x30`/`0x94` vs `0xb0`/`0x84` |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load `this+8` | **Yes** |
| Non-zero → load `*(phys+0x3c)`, add `0x30`, ret | **Yes** |
| Zero → load `this+4`, load `*(that+4)`, `lea` `base+this+0x94`, ret | **Yes** |
| No side effects | **Yes** |

### Recovered CF (byte-aligned)

```c
// __fastcall / thiscall-style: ECX = pEntity
// Returns pointer to orientation quaternion floats (xyzw at +0/+4/+8/+0xc of result).
int __fastcall FUN_00404a20(int pEntity)
{
    int phys = *(int *)(pEntity + 8);
    if (phys != 0) {
        int rb = *(int *)(phys + 0x3c);
        return rb + 0x30;   // rigid-body orientation quaternion
    }
    int typeInfo = *(int *)(pEntity + 4);
    int baseAdj  = *(int *)(typeInfo + 4);
    return baseAdj + 0x94 + pEntity;  // entity-embedded orient fallback
}
```

---

## 5. Assembly contract (from `read_memory`)

```
00404a20  8b4108          mov  eax, [ecx+8]       ; phys = this+8
00404a23  85c0            test eax, eax
00404a25  7407            jz   short fallback     ; → 00404a2e
00404a27  8b403c          mov  eax, [eax+0x3c]    ; rb
00404a2a  83c030          add  eax, 0x30          ; rb+0x30  (imm8 form)
00404a2d  c3              ret
00404a2e  8b4104          mov  eax, [ecx+4]       ; type / clonebase ptr
00404a31  8b5004          mov  edx, [eax+4]       ; base adjust
00404a34  8d840a94000000  lea  eax, [edx+ecx+0x94]
00404a3b  c3              ret
```

Hex (body through final `ret`, 28 bytes):  
`8b410885c074078b403c83c030c38b41048b50048d840a94000000c3`

Trailing `cc cc cc cc` at `00404a3c`–`00404a3f` are padding, not executed.

**Encoding note vs twin `00404c90`:** physics addend here is `add eax,0x30` (3-byte `83 c0 30`), so the `jz` displacement is `07`. Position twin uses `add eax,0xb0` (5-byte `05 b0 00 00 00`), so its `jz` is `09`. Same logical CF.

---

## 6. Twin relationship (`FUN_00404c90` @ `0x00404c90`)

| | Position (`00404c90`) | Orientation (`00404a20`) |
|---|---|---|
| Gate | same `this+8` | same |
| Physics return | `rb + 0xb0` | `rb + 0x30` |
| Fallback return | `adj + this + 0x84` | `adj + this + 0x94` |
| Role (prior verified) | world position | orientation quaternion |

Same CF skeleton; only addend constants differ. Seals this unit as the **orientation** half of the pose-pointer pair.

---

## 7. Callers (sample; own unit does not own caller CF)

Notable callers from live `get_function_callers` (OWN-ONLY — listed for role evidence only):

| Caller | VA | Role of return (caller-local) |
|---|---|---|
| `VehicleAction_airStabilization` | `0x00598320` | chassis orientation pack |
| `VehicleEntity_PushDriveAxesToController` | `0x004fbc10` | quat → forward basis for drive axes |
| `CVOGPlayerVehicle_UpdateTurretAiming` | `0x004f9570` | aim / pose basis |
| `Client_SendRespawnInSector` | `0x00935300` | pack current orientation |
| `Skill_RangeCheckTargetForResolveList_Inferred` | `0x0058c0a0` | pose context |
| `Drive_CollisionListener_DoVehicleCollision` | `0x005d9290` | collision pose |

Scaffold human name `Named_CalleeOf_Client_SendRespawnInSector_00404a20` is a **parent-seed alias**, not exclusive ownership.

---

## 8. Gaps

1. **Retail symbol** for this VA (no string in body; Ghidra `FUN_00404a20`).
2. Exact typed meaning of `this+4` chain (`*( *(this+4)+4 )`) — clonebase / MSVC adjustor — **Probable**, not sealed product type.
3. Guaranteed consumer width (always 4×f32) — RB map documents `+0x30..+0x3c`; some callers only need basis extract.
4. Runtime / bit-exact vs loaded image — open.
5. Register wiring at individual call sites if ECX clobbered before call — parent residual (OWN-ONLY).

**Verdict:** **accept** — sealed leaf CF, offsets, calling convention, leaf purity, and orientation-quaternion-pointer role. Product name remains inferred.
