# Function record: CVOGHBMoveVehicle_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636cc0` |
| **Canonical name** | `CVOGHBMoveVehicle_OnHeartBeat` |
| **Ghidra name** | `FUN_00636cc0` |
| **Address** | `0x00636cc0` |
| **Body span** | `0x00636cc0`–`0x00636d07` inclusive (**72 B** / `0x48`; exclusive end `0x00636d08`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; stack `uint32_t* pOutStatus`; `RET 4`) |
| **Return** | `EAX = pOutStatus` (writes `*pOutStatus` before return) |
| **System** | `input-drive-control` / heartbeat OnHeartBeat |
| **Completion status** | **Human-refined + dual R11-023 sealed 2026-08-05** — CF/ABI/RTTI class/vtbl+0x0c/entity bind/MoveTo arg map/Stop path sealed; runtime + status-1 English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md`, `reviews/B_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` |
| **Live RE this seal** | Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / xrefs + `read_memory` body/vtbl/globals/ctor constants |

---

## 1. Summary

Virtual **OnHeartBeat** for **`CVOGHBMoveVehicle`** (RTTI `.?AVCVOGHBMoveVehicle@@`), also installed on subclass **`CVOGHBMoveVehicleToMouse`**. Invoked only through `CVOGHBBase_TryFire` → `call [vtbl+0x0c]`.

When the heartbeat fires:

1. Load vehicle entity from **`this+0x24`** (ctor-bound).
2. If **null**: `*pOutStatus = 1` (`DAT_00af4f84`) and return.
3. If non-null: **`MoveToTarget3DPoint(entity, acceptDist@+0x2c, cruiseScale@+0x30, aim@+0x34, allowReverse=1)`** with **ECX=entity**.
4. If MoveTo returns **0**: **`CVOGHBBase_Stop(this)`** → may run dualed **OnEnd** (SetSteer0 + Push).
5. `*pOutStatus = 0` (Continue / `DAT_00d02c60`).

**Machine corrects decompiler:** MoveTo `this` is entity at `+0x24`, not `*(this+0x2c)`.

---

## 2. Signature

```c
uint32_t* __thiscall CVOGHBMoveVehicle_OnHeartBeat(
    CVOGHBMoveVehicle *this,
    uint32_t *pOutStatus);
// RET 4
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `CVOGHBMoveVehicle*` | Heartbeat object |
| `pOutStatus` | stack | `uint32_t*` | EHB-like status out |

---

## 3. Behavior (exact)

```
entity = *(this + 0x24)
if entity == NULL:
    *pOutStatus = DAT_00af4f84   // 1
    RET 4
// ECX remains entity
ok = MoveToTarget3DPoint(entity, *(f32*)(this+0x2c), *(f32*)(this+0x30),
                         *(void**)(this+0x34), 1)
if ok == 0:
    CVOGHBBase_Stop(this)       // ECX = HB
*pOutStatus = DAT_00d02c60      // 0 Continue
RET 4
```

| Condition | Result |
|---|---|
| `entity == NULL` | out=1; no MoveTo; no Stop |
| MoveTo returns 1 | axes written by MoveTo; out=0; no Stop |
| MoveTo returns 0 | Stop → OnEnd may park steer; out=0 |

### Instruction map

```text
56                   push esi
8B F1                mov  esi, ecx
8B 4E 24             mov  ecx, [esi+0x24]
85 C9                test ecx, ecx
75 10                jnz  00636cda
8B 0D 84 4F AF 00    mov  ecx, [00af4f84]
8B 44 24 08          mov  eax, [esp+8]
89 08                mov  [eax], ecx
5E                   pop  esi
C2 04 00             ret  4
8B 56 34             mov  edx, [esi+0x34]
8B 46 30             mov  eax, [esi+0x30]
6A 01                push 1
52                   push edx
8B 56 2C             mov  edx, [esi+0x2c]
50                   push eax
52                   push edx
E8 63 59 EC FF       call 004fc650
84 C0                test al, al
75 07                jnz  00636cf8
8B CE                mov  ecx, esi
E8 D8 14 ED FF       call 005081d0
8B 0D 60 2C D0 00    mov  ecx, [00d02c60]
8B 44 24 08          mov  eax, [esp+8]
89 08                mov  [eax], ecx
5E                   pop  esi
C2 04 00             ret  4
```

Hex: `568bf18b4e2485c975108b0d844faf008b44240889085ec204008b56348b46306a01528b562c5052e86359ecff84c075078bcee8d814edff8b0d602cd0008b44240889085ec20400`

---

## 4. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x24` | R | `VehicleEntity*` | ctor bind; MoveTo ECX |
| `this+0x2c` | R | f32 | acceptDist (ctor 2.5f) |
| `this+0x30` | R | f32 | cruiseScale (ctor 0) |
| `this+0x34` | R | dword | pushed as aim_UNUSED |
| entity axes | W via MoveTo | thr/steer/HB | +0x614/+0x618/+0x61c |
| `*pOutStatus` | W | u32 | 1 or 0 |

---

## 5. Vtable / RTTI

| Item | Value |
|---|---|
| Class RTTI | `.?AVCVOGHBMoveVehicle@@` @ `0x00af33c0` |
| Subclass RTTI | `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0` |
| Base vtbl | `PTR_FUN_009e3b70` — OnHeartBeat slot `0x009e3b7c` = **this** |
| Subclass vtbl | `PTR_FUN_009d5590` — OnHeartBeat slot `0x009d559c` = **this** (shared) |
| OnHeartBeat offset | **+0x0c** (TryFire convention) |
| OnEnd neighbor | `0x00636ba0` @ +0x10 (MEGA-017 dual) |

### Slot neighbors (base `009e3b70`)

| Off | VA | Role |
|---|---|---|
| +0x00 | `0x00636d10` | scalar deleting dtor |
| +0x04 | `0x00508270` | StampLastFireTime |
| +0x08 | `0x005082c0` | TryFire |
| **+0x0c** | **`0x00636cc0`** | **OnHeartBeat (this unit)** |
| +0x10 | `0x00636ba0` | OnEnd |
| +0x14 | `0x005081f0` | EmptyVFunc |

---

## 6. Callers / callees

### Callees

| Addr | Name | Role |
|---|---|---|
| `0x004fc650` | `CVOGVehicle::MoveToTarget3DPoint` | AI axis generator; bool AL |
| `0x005081d0` | `CVOGHBBase_Stop` | fail path; tails OnEnd when armed |

### Callers

| Kind | Detail |
|---|---|
| Code CALL | **none** |
| DATA | `0x009e3b7c`, `0x009d559c` |
| Dispatch | `CVOGHBBase_TryFire` → `[vtbl+0x0c]` |

---

## 7. Related artifacts

| Kind | Path |
|---|---|
| Raw (+ R11-023 append) | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636cc0_FUN_00636cc0.annotated.md` |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnHeartBeat.cpp` |
| FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00636cc0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00636cc0_FUN_00636cc0.md` |
| Dual A/B | `reviews/A_aa_00636cc0_*`, `reviews/B_aa_00636cc0_*` |
| Report | `docs/agents/task-dual-ab-00636cc0-r11-report.md` |
| OnEnd dual | `aa_00636ba0_CVOGHBMoveVehicle_OnEnd` |
| MoveTo verified | `physics/verified/fn_004fc650_driveController.md` |
| Stop dual | `aa_005081d0_CVOGHBBase_Stop` |
| TryFire dual | `aa_005082c0_CVOGHBBase_TryFire` |

---

## 8. Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| **Control flow** | **High** | bytes + disasm |
| **MoveTo this = entity@+0x24** | **High** | ECX live across TEST/JNZ; four stack pushes |
| **ABI thiscall + RET 4** | **High** | both epilogues |
| **Stop on MoveTo fail** | **High** | TEST AL / MOV ECX,ESI / call |
| **OnHeartBeat = vtbl+0x0c** | **High** | DATA slots + TryFire convention |
| **RTTI class name** | **High** | parent dual + shared vtbl |
| **Out status 0 = Continue** | **High** | value 0 matches sealed enum |
| **Out status 1 English** | **Open** | not 0/2/0x10 |
| **Method English "OnHeartBeat"** | **High** (convention) | not PDB string; slot sealed |
| **Runtime / diff** | **Open** | no Launcher / CE |
| **Ctor dual** | **Open** | residual context only |

---

## 9. Open questions

1. Product name / meaning of out-status **1** when entity is null.
2. Who writes entity aim `+0x190` before this HB (MoveTo reads entity aim, not HB `+0x34`).
3. Full ctor dual `FUN_00636bd0` (who constructs / rebinds entity).
4. Runtime confirmation: failed MoveTo → Stop → OnEnd clears steer under 0xC7 gate.

---

## 10. Completion checklist

| Item | Status |
|---|---|
| Raw capture + re-verify append | Yes |
| Annotated refresh | Yes |
| Exact C++ named + FUN twin | Yes |
| Control-flow sealed (machine) | Yes |
| Dual A/B | Yes |
| Runtime verification | **Open** |
| Parent ledgers | **Not touched** (OWN-ONLY) |

---

## 11. Porting notes (for implementers)

1. Port as **`CVOGHBMoveVehicle::OnHeartBeat`**: null-entity → status 1; else MoveTo with allowReverse; fail → Stop; always status 0 on entity path.
2. **this** is the HB object; MoveTo **this** is **entity at +0x24** — do not treat acceptDist as vehicle pointer.
3. Wire only as **vtbl+0x0c**; no invented direct callers.
4. Subclass `CVOGHBMoveVehicleToMouse` shares this pointer.
5. Pair with dualed OnEnd for fail-path steer park semantics.
6. Do **not** trust scaffold/decompiler arg order for MoveTo without machine check.
