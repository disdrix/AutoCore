# Review B (skeptical / adversarial): `aa_009373e0` Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009373e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_009373e0_Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Void / no stack args (scaffold) | Wrong ABI for port | **Falsified** — `RET 4` @ `0x00937460`; stack formal loaded for `008aa4b0` |
| 2 | Handbrake cleared (0) like thr/steer | Wrong park semantics | **Falsified** — `MOV [ESP+4],1` then tail JMP SetHandbrake; HB **ON** |
| 3 | ECX-thiscall on entry | Wrong host register | **Falsified** — body only reads **EDI**; caller `MOV EDI,ECX` |
| 4 | Always parks axes | Misses dialog gate | **Falsified** — dual null/`f40==f38` gates before open |
| 5 | Opens arbitrary / wrong dialog index | Mis-port UI | **Falsified** — immediate `PUSH 0xA` before `CALL 007fef20` |
| 6 | Same as pure park `0x0092f090` | Collapse siblings | **Falsified** — `0092f090` has no open/caption; only thr0/steer0/HB1 |
| 7 | SetHandbrake is a normal CALL | Stack/return model wrong | **Falsified** — `JMP 004f3620` tail; no local RET after HB |
| 8 | Multiple callers / generic input tick | Overfit DriveControlTick | **Falsified** — sole xref `0x00952b25` UNCONDITIONAL_CALL |
| 9 | Caption helper unused / dead | Ignore `008aa4b0` | **Falsified** — live CALL with ESI=`[EDI+0x1058]` |
| 10 | Product name sealed without `_Inferred` | Overclaim English | **Falsified as product demangle** — behavior sealed; slot-10 English open → keep `_Inferred` |
| 11 | Scaffold decompile is ABI-complete | Trust unaff_EDI void | **Falsified** — machine overrides required (this review) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI = client host | **High** | Wrong object for open/park |
| Gate `f40`/`f38` | **High** | Park/open when dialog inactive |
| Dialog index 10 | **High** | Wrong UI surface |
| Caption host `+0x1058` + stamp formal | **High** | Mission dialog text desync |
| thr0 / steer0 / HB1 | **High** | Vehicle keeps throttle or fails to stop |
| `RET 4` / sole caller | **High** | Calling-convention mismatch |
| Product English index-10 / stub name | **Open** | Naming only |
| Runtime Confirmed | **Open** | No Launcher this pass |

---

## 3. Cross-check against raw + bytes

```
// gate
if (*(client+0xf40)==0) ret4;
if (**(client+0xf40) != *(client+0xf38)) ret4;
// open index 10
Client_OpenDialogByIndex(client, 10, 0, 0);
// caption (stack formal → EAX; dialog host ESI)
MissionDialog_SetNpcObjectAndNameCaption(*(client+0x1058), stamp);
// park if vehicle
if (actor=*(client+0xe98)) if (veh=*(actor+0x250)) {
  SetLongitudinalInput(veh, 0);
  SetSteerInput(veh, 0);
  // [esp+4]=1; jmp SetHandbrake
  SetHandbrake(veh, 1);
}
ret4;
```

Live re-decompile 2026-08-05 CF ≡ frozen raw structure; machine seals ABI deltas.

---

## 4. Surviving contract for AutoCore

```
Client_DialogGate_OpenIndex10_ParkDriveAxes_Inferred(client /*EDI*/, stamp):
  if !client.f40 or **f40 != *f38: return (ret 4)
  OpenDialogByIndex(client, 10, 0, 0)
  MissionDialog_SetNpcObjectAndNameCaption(client.dialogHost1058, stamp)
  if actor=client.e98 and vehicle=actor.veh250:
    SetLongitudinal(vehicle, 0)
    SetSteer(vehicle, 0)
    SetHandbrake(vehicle, 1)   // ON, not off
  // ABI: EDI host; 1 stack arg; ret 4
  // Not: ECX-thiscall entry; not thr/steer/HB all-zero; not DriveControlTick body
```

**Port tests that matter:**

* Gate fail must not open dialog 10 or park.
* Stamp 0 clears caption (empty string path in `008aa4b0`).
* HB must be **1** while thr/steer **0**.
* Distinct from pure park `0092f090` (no open) and interact thr0+HB path `00938670`.

---

## 5. Verdict

Adversarial attacks on ABI, HB polarity, host register, gate, index, and multi-caller claims **fail**. Residual product English only → **accept-with-gaps**. Terminal **false**.
