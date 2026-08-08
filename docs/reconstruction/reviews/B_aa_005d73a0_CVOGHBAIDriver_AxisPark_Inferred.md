# Review B (skeptical / adversarial): `aa_005d73a0` CVOGHBAIDriver_AxisPark_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d73a0` |
| **VA** | `0x005d73a0`–`0x005d73e7` inclusive (**72 B** / `0x48`) |
| **Canonical name** | `CVOGHBAIDriver_AxisPark_Inferred` |
| **Review date** | `2026-08-05` (MEGA-015 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + FireWeapons exit + ctor vtbl install + RTTI string |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | ECX is **vehicle entity** (not AI object) | **Falsified** — `MOV ESI,ECX` then vehicle = `[ESI+0xbc]`; FireWeapons takes ESI as this; RTTI Driver |
| 2 | Product class is **FollowVehicle** only (FireWeapons string) | **Falsified as host class** — RTTI `.?AVCVOGHBAIDriver@@`; ctor installs vtbl `009db02c`; FireWeapons is a **callee** with FollowVehicle scoped string |
| 3 | This is player **DriveControlTick** park | **Falsified** — vtable method on Driver AI; no keyboard / action-map reads |
| 4 | Same as mission-UI thr0/steer0/HB1 (`0092f090`) | **Falsified** — also FireWeapons clear + Push + `FUN_005cc560`; AI host |
| 5 | Same as SetSteer-only park `00636ba0` | **Falsified** — full long/HB/fire/push sequence |
| 6 | FireWeapons **fires** weapons here | **Falsified** — `PUSH 0; PUSH 0`; may-fire gate false → mask stays 0 |
| 7 | `__stdcall` / stack args / `RET 4` | **Falsified** — no stack args; exit is tail `JMP`; FireWeapons alone is RET 8 |
| 8 | Has direct CALL callers | **Falsified** — callers empty; single DATA xref at vtbl slot |
| 9 | Runtime Confirmed / product method English sealed | **Fails** — Terminal false; no scoped string in body |

---

## 2. Decisive machine dataflow

```text
005d73a0  PUSH ESI
005d73a1  MOV  ESI, ECX                 ; this = Driver*
005d73a3  MOV  ECX, [ESI+0xbc]          ; vehicle*
005d73a9  PUSH 0
005d73ab  CALL 0x004f5620               ; SetSteerInput
005d73b0  MOV  ECX, [ESI+0xbc]
005d73b6  PUSH 0
005d73b8  CALL 0x004f5650               ; SetLongitudinalInput
005d73bd  MOV  ECX, [ESI+0xbc]
005d73c3  PUSH 1
005d73c5  CALL 0x004f3620               ; SetHandbrake
005d73ca  PUSH 0
005d73cc  PUSH 0
005d73ce  MOV  ECX, ESI
005d73d0  CALL 0x005d7100               ; FireWeapons (ends RET 8)
005d73d5  MOV  ECX, [ESI+0xbc]
005d73db  CALL 0x004fbc10               ; PushDriveAxes
005d73e0  MOV  ECX, ESI
005d73e2  POP  ESI
005d73e3  JMP  0x005cc560               ; tail cleanup
```

Host install (`FUN_005d7bb0`):

```text
CALL FUN_005d1990
MOV  dword ptr [ESI], 0x009db02c        ; CVOGHBAIDriver vtbl
; … slot +0x10 @ 009db03c = 0x005d73a0
```

RTTI TypeDescriptor name: `.?AVCVOGHBAIDriver@@` @ `0x00af8d30`.

A ≡ B on live decompile + body hex + FireWeapons RET 8 + RTTI/ctor.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Axis park sequence + offsets | **High** | wrong AI stop / stuck throttle |
| ECX=Driver; vehicle@+0xbc | **High** | park wrong object |
| FireWeapons may-fire=0 clear | **High** | AI keeps shooting while parked |
| Tail FUN_005cc560 | **High** | counter leak if dropped |
| Vtbl-only dispatch | **High** | invent direct callers |
| Product method English | Medium | naming only |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// CVOGHBAIDriver virtual slot +0x10 — park AI drive axes and clear fire
// thiscall, no stack args, void (tail into owner-counter cleanup)
void CVOGHBAIDriver_AxisPark(CVOGHBAIDriver self)
{
    var vehicle = self.VehicleAt(0xbc); // entity*
    VehicleEntity_SetSteerInput(vehicle, 0f);
    VehicleEntity_SetLongitudinalInput(vehicle, 0f);
    VehicleEntity_SetHandbrake(vehicle, true);
    CVOGHBAIFollowVehicle_FireWeapons(self, mayFire: false, unused: 0);
    VehicleEntity_PushDriveAxesToController(vehicle);
    FUN_005cc560(self); // residual counter cleanup
}
```

**Do not:** treat as player input tick; treat ECX as vehicle; claim FireWeapons engages weapons; invent product method name without string; claim runtime Confirmed.

---

## 5. Open questions

1. Product method English / which stop/idle path virtual-calls slot `+0x10`.
2. Exact counters mutated by residual `FUN_005cc560`.
3. Runtime park vs leash / ReturnToNormalLocation interaction.

**Verdict:** **accept-with-gaps**
