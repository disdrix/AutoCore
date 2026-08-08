# Review B (skeptical / adversarial): `aa_00636ba0` CVOGHBMoveVehicle_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636ba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-017) |
| **Counterpart** | `reviews/A_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full stop pack: thr0 + steer0 + HB1 | **Falsified** — only SetSteer(0) + Push; no SetLongitudinal / SetHandbrake |
| 2 | Same body as AI park `0x005d73a0` | **Falsified** — different entity offset (`+0x24` vs `+0xbc`), different callees, different tail |
| 3 | Direct code callers exist | **Falsified** — `get_function_callers` empty; DATA vtbl only |
| 4 | `this` is VehicleEntity | **Falsified** — ECX is HB object; entity at `+0x24`; SetSteer thiscall uses entity ECX |
| 5 | `__cdecl` / stack `this` | **Falsified** — `MOV ESI,ECX`; no `RET N` |
| 6 | Decompiler complete (bare return only) | **Falsified as complete CF** — machine has `JMP 0x005081e0`; decompiler gap |
| 7 | Tail is `CVOGHBBase_EmptyVFunc` `0x005081f0` | **Falsified** — target is neighbor empty `0x005081e0` (`c3`) |
| 8 | Push copies steer to controller | **Falsified** — Push dual: thr/HB only; steer via applyAction ramp |
| 9 | Class is generic CVOGHBBase | **Falsified** — RTTI `.?AVCVOGHBMoveVehicle@@`; subclass ToMouse shares slot |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | Product system is pure physics framework | **Clarify** — partition `input-drive-control`; body is HB OnEnd that parks drive steer |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Steer-only park + Push | **Confirmed** | Wrong AI stop semantics if thr/HB assumed |
| Entity at `this+0x24` | **Confirmed** | Wrong object if treated as entity-this |
| OnEnd virtual dispatch only | **Confirmed** | Invented call graphs |
| RTTI class name | **Confirmed** | Misfile under wrong system |
| Merge with `005d73a0` | **None — forbidden** | Over-clear thr/HB |
| Method English "OnEnd" | **High** (slot convention) | Doc-only residual |
| Runtime / bit-exact | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 body  ≡  live decompile 2026-08-05 (if/call)
machine 2026-08-05   ≡  clean CVOGHBMoveVehicle_OnEnd.cpp (incl. empty-ret tail)

56 8B F1                 PUSH ESI; MOV ESI,ECX
8B 4E 24                 MOV ECX,[ESI+0x24]   ; entity*
85 C9 74 0F              TEST/JZ skip
6A 00 E8 …               PUSH 0; CALL SetSteerInput (004f5620)
8B 4E 24 E8 …            MOV ECX,[ESI+0x24]; CALL Push (004fbc10)
8B CE 5E E9 …            MOV ECX,ESI; POP ESI; JMP 005081e0
```

RTTI / vtbl:

```text
type 0x00af33c0: ".?AVCVOGHBMoveVehicle@@"
vtbl 009e3b70+0x10 @ 009e3b80 = 00636ba0
vtbl 009d5590+0x10 @ 009d55a0 = 00636ba0  (ToMouse)
```

Reject ports that:

- Zero thr or force HB inside this OnEnd.
- Treat ECX as VehicleEntity (skip `+0x24` load).
- Invent direct CALL sites from DriveControlTick.
- Merge with FollowVehicle AI park `005d73a0`.
- Claim Push writes steer.
- Use `005081f0` as the sealed tail target.
- Claim runtime Confirmed without CE/Launcher.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: CVOGHBMoveVehicle::OnEnd  (vtbl+0x10)
// RTTI: .?AVCVOGHBMoveVehicle@@
// Shared by CVOGHBMoveVehicleToMouse vtbl

void OnEnd(CvogHbMoveVehicle self)
{
    var entity = ReadPtr(self + 0x24);
    if (entity == 0)
        return; // empty-ret path

    VehicleEntity_SetSteerInput(entity, 0.0f);           // gated +0x618
    VehicleEntity_PushDriveAxesToController(entity);     // thr/HB only
}

// Dispatch: CVOGHBBase_Stop → jmp [vtbl+0x10]
// Fire residual FUN_00636cc0 may Stop when MoveToTarget fails
// NOT equivalent to FUN_005d73a0 (thr0/steer0/HB1 + weapons clear)
```

---

## 5. Verdict

Adversarial review **fails** over-claims (full park, entity-this, code callers, Push-steer, EmptyVFunc tail) and **retains** steer-only OnEnd contract under RTTI class.

**accept-with-gaps** — same gaps as Path A (runtime, residual class dual, empty-leaf English). No CF rejection.

Terminal: **false**.
