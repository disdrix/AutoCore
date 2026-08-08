# Review B (skeptical / adversarial): `aa_005d5cc0` CVOGWaypoint_DoFollowObjectShortcutsUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5cc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-057) |
| **Counterpart** | `reviews/A_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is `CVOGHBAIWaypoint_*` (mega hint style) | **Falsified** — plate bytes @ `0x009dace4` are `CVOGWaypoint::DoFollowObjectShortcutsUpdate` (no HBAI infix). Do not invent product names. |
| 2 | cdecl / stack `this` / `RET 4` | **Falsified** — `MOV ESI,ECX`; epilogue plain **`RET`**. |
| 3 | Many callers / free entry | **Falsified** — sole UNCONDITIONAL_CALL from `CVOGWaypoint_UpdateState` @ `0x005d6353` (state **2**). |
| 4 | Surface-distance this = target only (decompiler) | **Falsified** — bytes: ECX still owner (`[ESI+0x10]`); stack = target physics. |
| 5 | Path-clear snap uses owner world pos | **Falsified** — clear path site sets `ECX=EBX` (targetPhys) before `Object_GetWorldPositionPtr`. |
| 6 | `operator_delete` never returns (decompiler warning) | **Falsified** — falls through zeroing vector heads then unscope. |
| 7 | This is InitFromSpawn / UpdateState shell | **Falsified** — distinct plate; body does pose math + COID maintenance; UpdateState only dispatches. |
| 8 | State-2 is idle/hold | **Falsified** — plate + TFID follow + shortcut gather = **follow-object shortcuts update**. |
| 9 | `_Inferred` required on name | **Falsified** — product plate string present; name is exact demangle of plate. |
| 10 | Runtime Confirmed / terminal | **Falsified** — no Launcher; Terminal **false**. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall void RET 0 SEH | **High** | ABI break |
| Plate product name | **High** | Wrong symbol in port |
| Sole caller state-2 | **High** | Mis-wire FSM |
| +0x52 / +0x53 flags | **High** | Wrong validity gates |
| Pose out +0x20..+0x2c | **High** | Steering uses garbage |
| Path COID +0x40/44/48 | **High** | Shortcut sticky/clear wrong |
| Surface-distance ECX=owner | **High** | Range gate inverted target |
| FUN_004d5910 / FUN_005d5960 English | **Open** | Naming only |
| Candidate vtbl class English | **Open** | Port type names |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall CVOGWaypoint_DoFollowObjectShortcutsUpdate(this)
  scope("CVOGWaypoint::DoFollowObjectShortcutsUpdate")
  follow = ResolveTFID(this+0x30)
  if !follow || !(flag+0x17c bit5): +0x52=0; unscope; return
  +0x52=1
  targetPhys = dynamic_cast<CVOGPhysicsBase>(follow)
  tgt = Pose4(targetPhys); owner = *(this+0x10)
  dist = SurfaceDistance3D(owner, targetPhys)   // ECX=owner
  +0x53 = (+0x4c > dist)
  if dist < 1.0: pose = tgt; unscope; return
  if path COID valid:
    FUN_005d5960(this)
    if dir_dot(saved, target) < 0.2:
      clear +0x40/44/48; pose = WorldPos(targetPhys)
    unscope; return
  gather shortcuts (FUN_004d5910)
  pick nearest in range → COID +0x40/44; optional +0x48; pose via vtbl
  else pose = tgt
  free vector; unscope; return
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. ABI / surface-distance this / path-clear snap corrected by `disassemble_function` + `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// CVOGWaypoint state-2 (follow-object shortcuts):
// - Dispatch only from UpdateState when *(this+0x50)==2
// - thiscall void; RET 0; SEH scope with product plate string
// - Resolve follow TFID at +0x30; gate on object flag +0x17c bit5 → +0x52
// - Surface distance owner↔target vs +0x4c → +0x53; snap pose if dist<1
// - If path COID pair valid: run state-1 peer FUN_005d5960; clear path if dir-dot<0.2
// - Else gather shortcuts, pick nearest, store COID (+0x134), write pose +0x20
// - Do not rename to CVOGHBAI*; do not merge with InitFromSpawn or UpdateState shell
// - Residual: FUN_004d5910 / FUN_005d5960 product English; candidate class
```

---

## 5. Verdict

Adversarial pass **confirms** A: plate/CF/ABI/caller/constants sealed; residual callee English + runtime open → **accept-with-gaps**. Skill-misname / multi-caller / wrong ABI / invented HBAI product name claims **falsified**.
