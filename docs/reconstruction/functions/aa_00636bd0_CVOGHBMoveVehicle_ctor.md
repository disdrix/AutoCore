# Function record: CVOGHBMoveVehicle_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636bd0` |
| **Canonical name** | `CVOGHBMoveVehicle_ctor` |
| **Ghidra name** | `FUN_00636bd0` |
| **Address** | `0x00636bd0` |
| **Body span** | `0x00636bd0`–`0x00636c49` inclusive (**122 B** / `0x7A`; exclusive end `0x00636c4a`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; stack `void* pEntity`; `RET 4`; `EAX = this`) |
| **Return** | `EAX = this` |
| **System** | `input-drive-control` / CVOGHBMoveVehicle constructor |
| **Completion status** | **Human-refined + dual R12-006 sealed 2026-08-05** — CF/ABI/RTTI class/vtbl/field defaults/dual-period/Attach arms sealed; flag English + MI owner type + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00636bd0_CVOGHBMoveVehicle_ctor.md`, `reviews/B_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |
| **Live RE this seal** | Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / xrefs + `read_memory` body/vtbl/float globals |

---

## 1. Summary

Constructor for product class **`CVOGHBMoveVehicle`** (RTTI `.?AVCVOGHBMoveVehicle@@`). Chains base HB construction, installs subclass vtbl `PTR_FUN_009e3b70`, configures dual-period pulse (**sentinel -1000**, **fire period 50 ms**), initializes MoveTo drive defaults used by dualed OnHeartBeat, stores the vehicle entity pointer, and attaches to the owner list (null or MI this-adjusted).

Sole code caller: **`FUN_00599550`** (ToMouse subclass ctor) which calls this then overrides vtbl to `009d5590`.

---

## 2. Signature

```c
CVOGHBMoveVehicle* __thiscall CVOGHBMoveVehicle_ctor(
    CVOGHBMoveVehicle *this,
    void *pEntity);   // vehicle entity* (may be null); stored raw at +0x24
// RET 4
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `CVOGHBMoveVehicle*` | Object under construction |
| `pEntity` | stack | `void*` / entity* | Bound vehicle entity (or null) |

---

## 3. Behavior (exact)

```
CVOGHBBase_ctor(this)
*this = &PTR_FUN_009e3b70
CVOGHBBase_SetPeriodAndCounter(this, -1000, true)   // +0x0C/+0x10
*(float*)(this+0x2c) = DAT_00aaa6c4                 // 2.5f acceptDist
*(float*)(this+0x30) = 0.0f                         // cruiseScale
*(float*)(this+0x34) = DAT_00aaa7a4                 // 15.0f aim default bits
*(uint32*)(this+0x08) = 0x32                        // pulse period 50 ms
*(void**)(this+0x24) = pEntity                      // entity for OnHB/OnEnd
*(uint8*)(this+0x29) = 0
if pEntity == NULL:
    CVOGHBBase_AttachOwnerObject(this, NULL)
else:
    adj = pEntity + 4 + *(*(pEntity + 4) + 4)
    CVOGHBBase_AttachOwnerObject(this, adj)
return this
```

### Instruction map

```text
56                         push esi
8B F1                      mov  esi, ecx
E8 28 16 ED FF             call 00508200
6A 01                      push 1
68 18 FC FF FF             push 0xfffffc18
8B CE                      mov  ecx, esi
C7 06 70 3B 9E 00          mov  dword [esi], 009e3b70
E8 B4 15 ED FF             call 005081a0
F3 0F 10 05 C4 A6 AA 00    movss xmm0, [00aaa6c4]
8B 44 24 08                mov  eax, [esp+8]
85 C0                      test eax, eax
F3 0F 11 46 2C             movss [esi+0x2c], xmm0
0F 57 C0                   xorps xmm0, xmm0
F3 0F 11 46 30             movss [esi+0x30], xmm0
F3 0F 10 05 A4 A7 AA 00    movss xmm0, [00aaa7a4]
C7 46 08 32 00 00 00       mov  dword [esi+8], 0x32
F3 0F 11 46 34             movss [esi+0x34], xmm0
89 46 24                   mov  [esi+0x24], eax
C6 46 29 00                mov  byte [esi+0x29], 0
75 0E                      jnz  00636c32
50                         push eax
8B CE                      mov  ecx, esi
E8 84 17 ED FF             call 005083b0
8B C6                      mov  eax, esi
5E                         pop  esi
C2 04 00                   ret  4
8B 48 04                   mov  ecx, [eax+4]
8B 51 04                   mov  edx, [ecx+4]
8D 44 02 04                lea  eax, [edx+eax+4]
50                         push eax
8B CE                      mov  ecx, esi
E8 6C 17 ED FF             call 005083b0
8B C6                      mov  eax, esi
5E                         pop  esi
C2 04 00                   ret  4
```

Hex: `568bf1e82816edff6a016818fcffff8bcec706703b9e00e8b415edfff30f1005c4a6aa008b44240885c0f30f11462c0f57c0f30f114630f30f1005a4a7aa00c7460832000000f30f114634894624c6462900750e508bcee88417edff8bc65ec204008b48048b51048d440204508bcee86c17edff8bc65ec20400`

---

## 4. Memory map (writes)

| Location | Access | Type | Value / notes |
|---|---|---|---|
| `this+0x00` | W | vtbl* | `PTR_FUN_009e3b70` |
| `this+0x08` | W | u32 | `0x32` (50) pulse period ms |
| `this+0x0C`/`+0x10` | W via SetPeriod | i32 | `-1000` sentinel/counter |
| `this+0x18` | W via Attach | void* | null or MI-adjusted owner |
| `this+0x24` | W | entity* | raw `pEntity` |
| `this+0x29` | W | u8 | `0` |
| `this+0x2c` | W | f32 | `2.5f` (`DAT_00aaa6c4`) acceptDist |
| `this+0x30` | W | f32 | `0.0f` cruiseScale |
| `this+0x34` | W | f32 bits | `15.0f` (`DAT_00aaa7a4`) aim default |

Base ctor also zeros/inits `+0x04..+0x21` per dualed `CVOGHBBase_ctor`.

---

## 5. Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00508200` | `CVOGHBBase_ctor` |
| Callee | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |
| Callee | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` (×2 arms) |
| Caller | `0x00599550` | ToMouse subclass ctor (`FUN_00599550`) — sole code CALL @ `0x00599558` |

**DATA:** none beyond code CALL (not a vtbl slot).

---

## 6. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636bd0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00636bd0_FUN_00636bd0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |
| Report | `docs/agents/task-dual-ab-00636bd0-r12-report.md` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / size | **High** |
| RTTI class + vtbl install | **High** |
| Drive field defaults + dual period | **High** |
| Entity@+0x24 vs Attach owner split | **High** |
| `+0x29` product English | **Open** |
| MI-adjust owner product type | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 8. Alias

- `FUN_00636bd0`
- `Named_CalleeOf_Named_CalleeOf_Client_OnVehicleSwitchFailure_00636bd0` (legacy scaffold — superseded)
- Class RTTI: `CVOGHBMoveVehicle` (**High** via sibling duals + vtbl)
