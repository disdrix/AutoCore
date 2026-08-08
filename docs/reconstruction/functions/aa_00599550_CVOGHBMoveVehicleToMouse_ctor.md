# Function record: CVOGHBMoveVehicleToMouse_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00599550` |
| **Canonical name** | `CVOGHBMoveVehicleToMouse_ctor` |
| **Ghidra name** | `FUN_00599550` |
| **Address** | `0x00599550` |
| **Body span** | `0x00599550`–`0x0059956f` inclusive (**32 B** / `0x20`; exclusive end `0x00599570`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; stack `pEntity`, `pHostCtx`; `RET 8`; `EAX = this`) |
| **Return** | `EAX = this` |
| **Object size** | **0x44** (`operator_new(0x44)` at all callers) |
| **System** | `input-drive-control` / CVOGHBMoveVehicleToMouse constructor |
| **Completion status** | **Human-refined + dual R13-007 sealed 2026-08-05** — CF/ABI/RET8/RTTI class/vtbl override/+0x40 store/size sealed; host-ctx product type English + complete body residual + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md`, `reviews/B_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` |
| **Live RE this seal** | Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / xrefs + `read_memory` body/vtbl/RTTI |
| **Partition** | R13-007; parent dual `0x005996a0`; dual start 2686; Terminal false |

---

## 1. Summary

Constructor for product class **`CVOGHBMoveVehicleToMouse`** (RTTI `.?AVCVOGHBMoveVehicleToMouse@@`). Chains dualed base **`CVOGHBMoveVehicle_ctor`** (`0x00636bd0`), overrides the vtbl to **`PTR_FUN_009d5590`** (ToMouse; dword0 = parent dual scalar dtor `0x005996a0`), stores a host/world-sim context pointer at **`+0x40`**, and returns `this`.

Four code callers allocate **`0x44`** bytes, construct, park the HB at player/host **`+0xc70`**, and enqueue on the HB list.

---

## 2. Signature

```c
CVOGHBMoveVehicleToMouse* __thiscall CVOGHBMoveVehicleToMouse_ctor(
    CVOGHBMoveVehicleToMouse *this,
    void *pEntity,     // vehicle entity* → base ctor
    void *pHostCtx);   // client/host +0xe04 world/sim → this+0x40
// RET 8
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `CVOGHBMoveVehicleToMouse*` | Object under construction |
| `pEntity` | stack | entity* | Forwarded to base MoveVehicle ctor |
| `pHostCtx` | stack | void* / world-sim* | Stored at `+0x40` |

---

## 3. Behavior (exact)

```
CVOGHBMoveVehicle_ctor(this, pEntity)   // base: CVOGHBBase + vtbl 009e3b70 + defaults
*this = &PTR_FUN_009d5590               // override to ToMouse vtbl
*(void**)(this + 0x40) = pHostCtx
return this
```

### Instruction map

```text
8B 44 24 04                mov  eax, [esp+4]       ; pEntity
56                         push esi
50                         push eax
8B F1                      mov  esi, ecx           ; this
E8 73 D6 09 00             call 00636bd0           ; CVOGHBMoveVehicle_ctor
8B 4C 24 0C                mov  ecx, [esp+0xC]     ; pHostCtx
C7 06 90 55 9D 00          mov  dword [esi], 009d5590
89 4E 40                   mov  [esi+0x40], ecx
8B C6                      mov  eax, esi
5E                         pop  esi
C2 08 00                   ret  8
```

Hex: `8b44240456508bf1e873d609008b4c240cc70690559d00894e408bc65ec20800`

---

## 4. Vtbl installed (`PTR_FUN_009d5590`)

| Slot | VA | Role |
|---|---|---|
| +0x00 | `0x005996a0` | ScalarDeletingDtor (parent dual R12-028) |
| +0x04 | `0x00508270` | StampLastFireTime / default OnStart (shared) |
| +0x08 | `0x005082c0` | TryFire (shared) |
| +0x0c | `0x00636cc0` | OnHeartBeat shared (R11 residual dualed) |
| +0x10 | `0x00636ba0` | OnEnd shared (MEGA-017 dualed) |
| +0x14 | `0x005081f0` | EmptyVFunc (shared) |
| +0x18 | `0x005083f0` | EndOrDestroy (shared) |
| +0x1c | `0x00599680` | ToMouse residual method (not OWN) |

---

## 5. Callers / callees

| Direction | VA | Notes |
|---|---|---|
| Callee | `0x00636bd0` | `CVOGHBMoveVehicle_ctor` (R12-006 dualed) |
| Caller | `Client_CreateVehicleObjectApply` @ `0x0081299a` | create-vehicle HB factory |
| Caller | `FUN_00810360` @ `0x0081057a` | vehicle-switch path |
| Caller | `FUN_009147a0` @ `0x009147e5` | global-entity factory |
| Caller | `FUN_0094b3a0` @ `0x0094b47f` | re-create when `+0xc70` null |

---

## 6. Confidence

| Claim | Level |
|---|---|
| Body 32 B / RET 8 / return this | **High** |
| Base ctor then ToMouse vtbl | **High** |
| RTTI product class | **High** |
| Size 0x44 | **High** |
| `+0x40` = stack arg1 | **High** |
| `+0x40` product type English | Open (role: client+0xe04 world/sim) |
| Runtime / bit-exact | Open |

## 7. Gaps

1. Product type English for `+0x40` / `client+0xe04`.
2. Complete/body `FUN_00599570` residual dual.
3. ToMouse-only vtbl slot English (`0x00599680` etc.).
4. Runtime / CE / bit-exact / differential.
