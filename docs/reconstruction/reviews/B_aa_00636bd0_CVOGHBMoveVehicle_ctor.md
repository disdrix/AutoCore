# Review B (skeptical / adversarial): `aa_00636bd0` CVOGHBMoveVehicle_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-006) |
| **Counterpart** | `reviews/A_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is OnHeartBeat / fire body | **Falsified** — no MoveTo/Stop; installs vtbl; sibling `00636cc0` is OnHB |
| 2 | This is OnEnd / steer park | **Falsified** — no SetSteer/Push; OnEnd is `00636ba0` |
| 3 | This is scalar deleting dtor | **Falsified** — no delete; dtor is `00636d10` |
| 4 | Period is -1000 ms fire interval | **Falsified** — SetPeriod writes sentinel +0x0C/+0x10; pulse is `+0x08=50` |
| 5 | acceptDist is 15.0f | **Falsified** — `+0x2c` from `DAT_00aaa6c4` = **2.5f**; 15.0f goes to `+0x34` |
| 6 | `+0x30` cruise is non-zero | **Falsified** — XORPS store 0.0f |
| 7 | Attach always gets raw pEntity | **Falsified** — non-null path MI-adjusts; null path pushes 0 |
| 8 | Entity@+0x24 equals owner@+0x18 | **Falsified** — +0x24 is raw pEntity; +0x18 set by Attach |
| 9 | `__cdecl` / no RET N / void | **Falsified** — `RET 4`; EAX=this |
| 10 | Multiple code callers | **Falsified** — sole CALL from `FUN_00599550` @ `00599558` |
| 11 | Class is CVOGHBMoveVehicleToMouse | **Falsified** — installs `009e3b70`; ToMouse ctor overrides to `009d5590` after this |
| 12 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 13 | Scaffold clean (empty auto plate) is sealed | **Falsified** — replaced this pass with machine CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor role + RTTI class | **Confirmed** | Wrong type / wrong vtbl |
| Dual period: sentinel -1000, pulse 50 | **Confirmed** | HB never fires / wrong rate |
| Drive defaults 2.5 / 0 / 15f bits | **Confirmed** | Wrong MoveTo accept/cruise |
| Entity@+0x24 raw store | **Confirmed** | OnHB null gate wrong |
| MI attach expression | **Confirmed** (expr); owner type open | List attach wrong object |
| ToMouse sole code caller | **Confirmed** | Invented factory graph |
| Runtime / bit-exact | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 decompile CF (base/vtbl/SetPeriod/fields/attach)  ≡  live 2026-08-05
live decompile                                                    ≡  machine bytes
machine 2026-08-05                                                ≡  clean CVOGHBMoveVehicle_ctor.cpp

56 8B F1 E8 …          base ctor
6A 01 68 18FCFFFF …    SetPeriod(-1000, true) + vtbl store
F3 0F 10 05 C4A6AA00   load 2.5f → +0x2c
0F 57 C0 …             zero → +0x30
F3 0F 10 05 A4A7AA00   load 15.0f → +0x34
C7 46 08 32 00 00 00   pulse +0x08 = 50
89 46 24 C6 46 29 00   entity + flag
75 0E … / MI adjust    dual Attach + RET 4
```

Globals (`read_memory`):

```text
DAT_00aaa6c4: 00 00 20 40 → float 2.5
DAT_00aaa7a4: 00 00 70 41 → float 15.0
vtbl 009e3b70: 00636d10, 00508270, 005082c0, 00636cc0, 00636ba0, …
```

Reject ports that:

- Treat `-1000` as the OnHeartBeat fire period (ignore `+0x08=50`).
- Swap acceptDist/aim defaults (15 at +0x2c or 2.5 at +0x34).
- Pass raw `pEntity` to Attach without MI adjust when non-null.
- Alias entity@+0x24 with owner@+0x18.
- Call this function as OnHB/OnEnd/dtor.
- Claim ToMouse vtbl is installed here (subclass ctor overrides after).
- Claim runtime Confirmed without CE/Launcher.
- Trust empty scaffold `FUN_00636bd0.cpp` as sealed.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: CVOGHBMoveVehicle::CVOGHBMoveVehicle  (ctor)
// RTTI: .?AVCVOGHBMoveVehicle@@
// Vtbl: PTR_FUN_009e3b70

CvogHbMoveVehicle* Ctor(CvogHbMoveVehicle self, void* pEntity)
{
    CVOGHBBase_ctor(self);
    WritePtr(self + 0x00, 0x009e3b70);
    CVOGHBBase_SetPeriodAndCounter(self, -1000, true); // +0x0C/+0x10
    WriteF32(self + 0x2c, ReadF32(0x00aaa6c4)); // 2.5f acceptDist
    WriteF32(self + 0x30, 0.0f);                // cruiseScale
    WriteF32(self + 0x34, ReadF32(0x00aaa7a4)); // 15.0f aim default bits
    WriteU32(self + 0x08, 0x32);                // pulse period 50 ms
    WritePtr(self + 0x24, pEntity);             // entity for OnHB/OnEnd
    WriteU8 (self + 0x29, 0);

    if (pEntity == null) {
        CVOGHBBase_AttachOwnerObject(self, null);
    } else {
        // MSVC MI this-adjust: pEntity + 4 + *(*(pEntity+4)+4)
        var adj = pEntity + 4 + ReadI32(ReadPtr(pEntity + 4) + 4);
        CVOGHBBase_AttachOwnerObject(self, adj);
    }
    return self; // RET 4
}
```

**Pair with:** dualed OnHeartBeat `00636cc0`, OnEnd `00636ba0`, dtor `00636d10`, Base ctor/SetPeriod/Attach.

**Do not merge:** ToMouse body `00599550`; OnHB fire; treat pulse as -1000.

---

## 5. Verdict

Path B falsified OnHB/OnEnd/dtor merges, period misread, float-slot swaps, attach raw-pointer, multi-caller, ToMouse-vtbl-here, and runtime Confirmed. Surviving contract matches Path A.

**accept-with-gaps** — no Runtime Confirmed.
