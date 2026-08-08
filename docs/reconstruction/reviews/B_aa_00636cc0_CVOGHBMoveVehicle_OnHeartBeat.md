# Review B (skeptical / adversarial): `aa_00636cc0` CVOGHBMoveVehicle_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636cc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R11-023) |
| **Counterpart** | `reviews/A_aa_00636cc0_CVOGHBMoveVehicle_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | MoveTo `this` is `*(HB+0x2c)` (decompiler) | **Falsified** — ECX after gate is entity@+0x24; +0x2c is acceptDist float (2.5f) |
| 2 | This body is OnEnd / axis park | **Falsified** — no SetSteer/Push; OnEnd is neighbor `00636ba0`; this is fire/OnHeartBeat |
| 3 | Same as AI full park `005d73a0` | **Falsified** — different class, offset, callees, role |
| 4 | Direct code callers exist | **Falsified** — callers empty; DATA vtbl only |
| 5 | `this` is VehicleEntity | **Falsified** — ECX is HB; entity at +0x24; Stop reloads ESI |
| 6 | `__cdecl` / no RET N | **Falsified** — `RET 4` both paths |
| 7 | Always Continues without Stop | **Falsified** — AL==0 → `CVOGHBBase_Stop` |
| 8 | Out status 1 is Remove (0x10) | **Falsified** — image value is **1**, not 16 |
| 9 | Out status 0 is Inactive | **Falsified** — 0 is Continue |
| 10 | allowReverse is false | **Falsified** — `push 1` |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 12 | Scaffold clean (decompiler paste) is sealed | **Falsified** — wrong MoveTo this/args; replaced this pass |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| MoveTo entity@+0x24 thiscall | **Confirmed** | Port would pass float-as-pointer → crash |
| Fail → Stop → OnEnd park | **Confirmed** | Missed steer cleanup on arrival |
| OnHeartBeat vtbl+0x0c only | **Confirmed** | Invented call graphs |
| Out 0 Continue / out 1 raw | **Confirmed** / status-1 English open | Wrong list-remove semantics if 1 treated as 0x10 |
| Merge with OnEnd body | **None — forbidden** | Double-park / miss MoveTo |
| Method English "OnHeartBeat" | **High** (slot convention) | Doc-only residual |
| Runtime / bit-exact | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 decompile CF (if/call/return)  ≡  live decompile 2026-08-05
raw decompiler MoveTo this/args               ≠  machine (superseded)
machine 2026-08-05                            ≡  clean CVOGHBMoveVehicle_OnHeartBeat.cpp

56 8B F1                 PUSH ESI; MOV ESI,ECX
8B 4E 24 85 C9 75 10     entity gate
… DAT_00af4f84 / RET 4   null path out=1
6A 01 52 … 50 52 E8 …    MoveTo four stack + ECX entity
84 C0 75 07 8B CE E8 …   fail → Stop(HB)
… DAT_00d02c60 / RET 4   out=0
```

RTTI / vtbl:

```text
type 0x00af33c0: ".?AVCVOGHBMoveVehicle@@"
vtbl 009e3b70+0x0c @ 009e3b7c = 00636cc0
vtbl 009d5590+0x0c @ 009d559c = 00636cc0  (ToMouse)
neighbor +0x10 = 00636ba0 OnEnd
```

Reject ports that:

- Pass `*(this+0x2c)` as the vehicle pointer into MoveTo.
- Treat ECX as VehicleEntity for the whole function (skip entity load / Stop reload).
- Implement this as OnEnd SetSteer0+Push without MoveTo.
- Claim out-status 1 is Remove (16) or Inactive (2).
- Invent direct CALL sites from DriveControlTick.
- Claim runtime Confirmed without CE/Launcher.
- Trust scaffold FUN_00636cc0 decompiler paste as sealed.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: CVOGHBMoveVehicle::OnHeartBeat  (vtbl+0x0c)
// RTTI: .?AVCVOGHBMoveVehicle@@
// Shared by CVOGHBMoveVehicleToMouse vtbl

uint* OnHeartBeat(CvogHbMoveVehicle self, uint* pOut)
{
    var entity = ReadPtr(self + 0x24);
    if (entity == 0) {
        *pOut = ReadU32(0x00af4f84); // 1
        return pOut;
    }

    // thiscall MoveTo: ECX = entity
    bool ok = MoveToTarget3DPoint(
        entity,
        ReadF32(self + 0x2c), // acceptDist
        ReadF32(self + 0x30), // cruiseScale
        ReadPtr(self + 0x34), // aim_UNUSED (pushed; not read by MoveTo)
        allowReverse: true);

    if (!ok)
        CVOGHBBase_Stop(self); // may OnEnd: SetSteer(0)+Push

    *pOut = ReadU32(0x00d02c60); // 0 Continue
    return pOut;
}

// Dispatch: TryFire → [vtbl+0x0c]
// NOT OnEnd (00636ba0); NOT AI AxisPark (005d73a0)
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks kill decompiler-this, OnEnd-merge, full-park-merge, and status-1=Remove myths. Surviving contract matches machine. Gaps: runtime, status-1 product English, ctor dual.

Terminal: **false**.
