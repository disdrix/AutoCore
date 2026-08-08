# Function record: CVOGHBMoveVehicle_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636ba0` |
| **Canonical name** | `CVOGHBMoveVehicle_OnEnd` |
| **Ghidra name** | `FUN_00636ba0` |
| **Address** | `0x00636ba0` |
| **Body span** | `0x00636ba0`–`0x00636bbf` inclusive (**32 B** / `0x20`; exclusive end `0x00636bc0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (`this` in `ECX`; no stack args; tail `JMP` empty-ret) |
| **Return type** | `void` |
| **System** | `input-drive-control` / heartbeat OnEnd |
| **Completion status** | **Human-refined + dual MEGA-017 sealed 2026-08-05** — CF/ABI/RTTI/vtbl/entity bind/callees sealed; runtime + full class dual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md`, `reviews/B_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` |
| **Live RE this seal** | Ghidra `decompile_function` / `analyze_function_complete` / `disassemble_function` / xrefs + `read_memory` body/vtbl/RTTI |

---

## 1. Summary

Virtual **OnEnd** for **`CVOGHBMoveVehicle`** (RTTI `.?AVCVOGHBMoveVehicle@@`), also installed on subclass **`CVOGHBMoveVehicleToMouse`**. Invoked only through `CVOGHBBase_Stop` → `jmp [vtbl+0x10]`.

When the heartbeat is stopped while armed:

1. Load vehicle entity pointer from **`this+0x24`** (ctor-bound).
2. If non-null: **`VehicleEntity_SetSteerInput(entity, 0)`** then **`VehicleEntity_PushDriveAxesToController(entity)`**.
3. Tail to empty leaf **`0x005081e0`** (`C3`).

**Steer-only axis park** — does not zero longitudinal input or force handbrake (contrast AI follow pack `0x005d73a0`).

Live decompile ≡ raw body CF for the if/call pair; **decompiler omits** the empty-ret tail — sealed by `disassemble_function` + `read_memory`.

---

## 2. Signature

```c
void __thiscall CVOGHBMoveVehicle_OnEnd(CVOGHBMoveVehicle *this);
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `CVOGHBMoveVehicle*` | Heartbeat whose OnEnd runs |

No stack arguments. No `RET N` — control ends at `JMP 0x005081e0`.

---

## 3. Behavior (exact)

```
entity = *(this + 0x24)
if entity != NULL:
    VehicleEntity_SetSteerInput(entity, 0.0f)     // gated write entity+0x618
    VehicleEntity_PushDriveAxesToController(entity) // thr/HB → ctrl; no steer copy
// JMP empty ret 0x005081e0
```

| Condition | Result |
|---|---|
| `entity == NULL` | no axis work; still empty-ret |
| `entity != NULL` | steer park + push |

### Instruction map (`read_memory` @ `0x00636ba0`)

```text
56                   push esi
8B F1                mov  esi, ecx
8B 4E 24             mov  ecx, [esi+0x24]
85 C9                test ecx, ecx
74 0F                jz   00636bb9
6A 00                push 0
E8 6F EA EB FF       call 004f5620   ; SetSteerInput
8B 4E 24             mov  ecx, [esi+0x24]
E8 57 50 EC FF       call 004fbc10   ; PushDriveAxes
8B CE                mov  ecx, esi
5E                   pop  esi
E9 1F 16 ED FF       jmp  005081e0   ; C3 empty
```

Hex: `568bf18b4e2485c9740f6a00e86feaebff8b4e24e85750ecff8bce5ee91f16edff`

---

## 4. Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `this+0x24` | R | `VehicleEntity*` | Entity bound in ctor `FUN_00636bd0` (`param_1[9]`) |
| `entity+0x618` | W (via SetSteer) | f32 | Steer input → 0 if 0xC7 gate allows |
| thr/HB/controller | via Push | — | Push dual; **no** steer field copy |

---

## 5. Vtable / RTTI

| Item | Value |
|---|---|
| Class RTTI | `.?AVCVOGHBMoveVehicle@@` @ `0x00af33c0` |
| Subclass RTTI | `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0` |
| Base vtbl | `PTR_FUN_009e3b70` — OnEnd slot `0x009e3b80` = **this** |
| Subclass vtbl | `PTR_FUN_009d5590` — OnEnd slot `0x009d55a0` = **this** (shared) |
| OnEnd offset | **+0x10** (same slot `CVOGHBBase_Stop` tails) |
| Nearby string | `"TtVehicle"` near subclass RTTI region (profile stamp context) |

### Slot neighbors (base `009e3b70`)

| Off | VA | Role |
|---|---|---|
| +0x00 | `0x00636d10` | scalar deleting dtor |
| +0x04 | `0x00508270` | `CVOGHBBase_StampLastFireTime` |
| +0x08 | `0x005082c0` | `CVOGHBBase_TryFire` |
| +0x0c | `0x00636cc0` | fire: MoveToTarget3DPoint / may Stop |
| **+0x10** | **`0x00636ba0`** | **OnEnd (this unit)** |
| +0x14 | `0x005081f0` | `CVOGHBBase_EmptyVFunc` |

---

## 6. Callers / callees

### Callees

| Addr | Name | Role |
|---|---|---|
| `0x004f5620` | `VehicleEntity_SetSteerInput` | gated steer store `+0x618` |
| `0x004fbc10` | `VehicleEntity_PushDriveAxesToController` | thr/HB → controller |
| `0x005081e0` | empty `RET` leaf | tail only (not EmptyVFunc `005081f0`) |

### Callers

| Kind | Detail |
|---|---|
| Code CALL | **none** (`get_function_callers` empty) |
| DATA | `0x009e3b80`, `0x009d55a0` |
| Dispatch | `CVOGHBBase_Stop` `0x005081d0` → `jmp [vtbl+0x10]` when arming dormant |
| Fire path | `FUN_00636cc0` may `CVOGHBBase_Stop` when MoveToTarget returns 0 |

---

## 7. Related artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-017 append) | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.annotated.md` |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnEnd.cpp` |
| FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00636ba0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00636ba0_FUN_00636ba0.md` |
| Dual A/B | `reviews/A_aa_00636ba0_*`, `reviews/B_aa_00636ba0_*` |
| Report | `docs/agents/task-dual-ab-00636ba0-mega-017-report.md` |
| Steer setter dual | `aa_004f5620_VehicleEntity_SetSteerInput` |
| Push dual | `aa_004fbc10_VehicleEntity_PushDriveAxesToController` |
| Stop dual | `aa_005081d0_CVOGHBBase_Stop` |

---

## 8. Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| **Control flow** | **High** | bytes + disasm; decompile if/call match |
| **Empty-ret tail** | **High** | `JMP` + `read_memory` `c3` @ `005081e0` |
| **ABI thiscall / no stack args** | **High** | `MOV ESI,ECX`; no `RET N` |
| **`this+0x24` = entity** | **High** | ctor store + SetSteer/Push thiscall targets |
| **Steer-only park (not thr/HB)** | **High** | only Push 0 + two calls |
| **OnEnd vtbl+0x10** | **High** | slot + Stop convention |
| **RTTI class name** | **High** | type descriptor string |
| **Method English "OnEnd"** | **High** (convention) | not PDB string; slot sealed |
| **Runtime / diff** | **Open** | no Launcher / CE |
| **Full class dual (ctor/fire)** | **Open** | residual context only |

---

## 9. Open questions

1. Runtime confirmation: Stop after successful/failed MoveToTarget clears steer under 0xC7 gate.
2. Who constructs `CVOGHBMoveVehicle` / `ToMouse` in product flows (ctor residual).
3. Formal name of empty leaf `0x005081e0` (neighbor of EmptyVFunc).
4. Whether any path reuses this OnEnd without Stop (no static CALL evidence).

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

1. Port as **`CVOGHBMoveVehicle::OnEnd`**: if `entity != null` then `SetSteer(0)` + `PushDriveAxes`.
2. **Do not** force thr=0 or HB=1 here — that is a different pack (`0x005d73a0`).
3. Honor **SetSteerInput** 0xC7 gate (may leave prior steer if suppressed).
4. Wire only as **vtbl+0x10** OnEnd; do not invent direct call sites.
5. Subclass `CVOGHBMoveVehicleToMouse` shares this OnEnd pointer.
6. Tail may be bare return; matching empty stub optional for bit-exact.
