# Review A (reconstruction fidelity): `aa_00404c90` Object_GetWorldPositionPtr (FUN_00404c90)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c90` |
| **VA** | `0x00404c90` |
| **Canonical name** | `FUN_00404c90` |
| **Probable role name** | `Object_GetWorldPositionPtr` / entity world-position pointer getter |
| **System** | `shared-object-pose` (DriveControlTick callee; also airStab, aim, respawn, AI pursue, …) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00404c90_Object_GetWorldPositionPtr.md` |
| **Verdict** | **accept** on CF / offsets / CC; name product string **open** (role **High**) |

---

## 1. Purpose

Thin **leaf getter**: given an entity/object `this` in **ECX**, return a **pointer to the world position float triple** (slot starts at returned address; consumers read `+0`, `+4`, `+8` as XYZ).

Two storage paths:

1. **Physics-attached:** if `this+0x08 != 0` (physics object / wrapper pointer),  
   `return *( *(this+8) + 0x3c ) + 0xb0` → rigid-body **world position** at `rb+0xb0`.
2. **Entity fallback:** else  
   `return *( *(this+4) + 4 ) + this + 0x84` → embedded pose at entity-relative **`+0x84`** (with clonebase/type offset from `*( *(this+4)+4 )`).

No writes, no callees, no globals.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00404c90_FUN_00404c90.md` |
| Raw | `docs/reconstruction/raw/aa_00404c90_FUN_00404c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00404c90_FUN_00404c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404c90.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00404c90` (2026-07-29) |
| Live body bytes | Ghidra `read_memory` `0x00404c90` length 32 |
| Function range | entry `00404c90`, body `00404c90`–`00404cad` |
| Twin quat getter | `FUN_00404a20` @ `0x00404a20` (same CF shape; offsets `0x30` / `0x94`) |
| Prior verified map | `physics/verified/fn_offsets_rigidbody.md` §B pose helpers |
| Prior airStab use | `physics/verified/fn_00598320_airStab.md` (pos pack from this helper) |
| Callers | Ghidra `get_function_xrefs` (60+ sites incl. `Client_Input_DriveControlTick` @ `0x0092339d` / `0x009233af`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf: no callees / no stores | **Confirmed** | decompile + body bytes |
| CC: `this` in **ECX** (`__fastcall` / thiscall-style) | **Confirmed** | `mov eax,[ecx+8]` / `mov eax,[ecx+4]` |
| Gate: `*(this+8) != 0` → physics path | **Confirmed** | `test eax,eax` / `jz` fallback |
| Physics path: `rb = *(*(this+8)+0x3c); return rb+0xb0` | **Confirmed** | `mov eax,[eax+0x3c]` / `add eax,0xb0` |
| Fallback: `lea eax, [edx+ecx+0x84]` with `edx = *(*(this+4)+4)` | **Confirmed** | body bytes |
| Return type = **pointer** (not position by value) | **High** | consumers load floats from returned addr (e.g. DCT `*(iVar5+8)`, `*pfVar6`) |
| Returned slot = **world position** (XYZ) | **High** | physics verified map `rb+0xb0`; airStab packs as position; twin `00404a20` = quat @ `rb+0x30` |
| Product symbol name sealed | **Open** | Ghidra still `FUN_00404c90`; role name inferred |
| Fallback `*( *(this+4)+4 )` meaning (RTTI / clonebase offset) | **Probable** | classic MSVC this-adjust pattern; not fully typed in this unit |
| Clean ≡ raw ≡ live decompile CF | **Confirmed** | identity |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load `this+8` | **Yes** |
| Non-zero → load `*(phys+0x3c)`, add `0xb0`, ret | **Yes** |
| Zero → load `this+4`, load `*(that+4)`, `lea` `base+this+0x84`, ret | **Yes** |
| No side effects | **Yes** |

### Recovered CF (byte-aligned)

```c
// __fastcall / thiscall-style: ECX = pEntity
// Returns pointer to world position floats (xyz at +0/+4/+8 of result).
int __fastcall FUN_00404c90(int pEntity)
{
    int phys = *(int *)(pEntity + 8);
    if (phys != 0) {
        int rb = *(int *)(phys + 0x3c);
        return rb + 0xb0;   // rigid-body world position
    }
    int typeInfo = *(int *)(pEntity + 4);
    int baseAdj  = *(int *)(typeInfo + 4);
    return baseAdj + 0x84 + pEntity;  // entity-embedded pose fallback
}
```

---

## 5. Assembly contract (from `read_memory`)

```
00404c90  8b4108          mov  eax, [ecx+8]       ; phys = this+8
00404c93  85c0            test eax, eax
00404c95  7409            jz   short fallback     ; → 00404ca0
00404c97  8b403c          mov  eax, [eax+0x3c]    ; rb
00404c9a  05b0000000      add  eax, 0xb0          ; rb+0xb0
00404c9f  c3              ret
00404ca0  8b4104          mov  eax, [ecx+4]       ; type / clonebase ptr
00404ca3  8b5004          mov  edx, [eax+4]       ; base adjust
00404ca6  8d840a84000000  lea  eax, [edx+ecx+0x84]
00404cad  c3              ret
```

Hex (body through final `ret`, 30 bytes):  
`8b410885c074098b403c05b0000000c38b41048b50048d840a84000000c3`

Trailing `cc cc` at `00404cae`–`00404caf` are padding, not executed.

---

## 6. Twin relationship (`FUN_00404a20` @ `0x00404a20`)

| | Position (`00404c90`) | Orientation (`00404a20`) |
|---|---|---|
| Gate | same `this+8` | same |
| Physics return | `rb + 0xb0` | `rb + 0x30` |
| Fallback return | `adj + this + 0x84` | `adj + this + 0x94` |
| Role (prior verified) | world position | orientation quaternion |

Same CF skeleton; only addend constants differ. Seals this unit as the **position** half of the pose-pointer pair.

---

## 7. Callers (sample; own unit does not own caller CF)

Notable named callers from live xrefs (not exhaustive of 60+ sites):

| Caller | Site(s) | Role of return (caller-local) |
|---|---|---|
| `Client_Input_DriveControlTick` | `0x0092339d`, `0x009233af` | range check vs aim point (XYZ loads) |
| `VehicleAction_airStabilization` | `0x005983a9` | chassis position pack |
| `CVOGPlayerVehicle_UpdateTurretAiming` | `0x004f987a` | aim / pose |
| `Client_SendRespawnInSector` | `0x00935396` | pack current pose |
| `Client_CastSkillFromQuickBarSlot` | `0x009419ec` | aim from selected |
| `Client_RecvBroadcast` | `0x00810d0b` | (parent seed; not exclusive owner) |
| `CVOGHBAICreatureBase_DoVehiclePursue` | many | AI pursue pose |
| `CVOGCombat_OnDeathAwardKillXp` | multiple | combat / corpse pose |

---

## 8. Gaps

1. **Retail symbol** for this VA (no string in body; Ghidra `FUN_00404c90`).
2. Exact typed meaning of `this+4` chain (`*( *(this+4)+4 )`) — clonebase / MSVC adjustor — **Probable**, not sealed product type.
3. Whether returned pointer is always 4×f32 (xyzw) vs 3×f32 — consumers differ; RB map documents `+0xb0..+0xbc` as 4-float pose slot.
4. Runtime / bit-exact vs loaded image — open.

**Verdict:** **accept** — sealed leaf CF, offsets, calling convention, and position-pointer role. Product name remains inferred.
