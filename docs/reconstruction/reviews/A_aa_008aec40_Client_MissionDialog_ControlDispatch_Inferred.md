# Review A (reconstruction fidelity): `aa_008aec40` Client_MissionDialog_ControlDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aec40` |
| **VA** | `0x008aec40` |
| **Body span** | `008aec40` – `008aefbb` |
| **Canonical name** | `Client_MissionDialog_ControlDispatch_Inferred` |
| **Ghidra name** | `FUN_008aec40` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md` |
| **System** | `missions-progression` / client mission dialog UI |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission dialog UI **control-message router** (vtable-installed):

```
// this = mission dialog UI object
// param_2 = toolkit message type (5 / 6 / 8 / 0x1a observed)
// param_3 = control id (0x9c40 band + NPC multi ≥0x9c4f)
undefined4 Client_MissionDialog_ControlDispatch_Inferred(this, msg, controlId);
```

Routes:

* **Buttons** `0x9c46`–`0x9c4d` + msg 8 → `Client_MissionDialogHandleButton(index)` then optional close.
* **Close** `0x9c40` + msg 8 (and button success) → `FUN_007fca10` (+ abandon chrome if state 2).
* **Scale** `0x9c41` + msg `0x1a` → widget scale sync with `DAT_00aaa664` bias.
* **Reward slots** `0x9c42`–`0x9c45` → resolve / focus / click (`FUN_008aa3f0`) when reward-mode `+0x64c`.
* **NPC multi** `>0x9c4e` + msg 8 → `Client_ShowNpcMissionDialogUI` if index in table.
* **Default** → `FUN_0087b500(msg, id)`.

Not a network recv handler; not `HandleButton` itself.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_008aec40_FUN_008aec40.md` | ≡ live decompile (+ seal append) |
| Annotated | `raw/aa_008aec40_FUN_008aec40.annotated.md` | Strengthened |
| Clean | `reconstructed-exact/FUN_008aec40.cpp` | CF ≡ raw |
| Function record | `functions/aa_008aec40_FUN_008aec40.md` | Strengthened |
| Live decompile | `decompile_function` @ `0x008aec40` | **≡ raw** |
| Live `read_memory` | body, `0x00aaa664`, `0x00aaa6f8`, vtable `0x00a4a854` | constants + install sealed |
| Bounds | `get_function_by_address` | `008aec40`–`008aefbb` |
| Xrefs | `get_function_xrefs` | DATA only `0x00a4a854` |
| Related | HandleButton `0x008ae7c0`, ShowNpc `0x009438f0`, Flush `0x008ab8f0` / UF-010 | chain context |

**Not performed:** Launcher, runtime golden, bit-exact binary diff. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall; 2 stack args; `ret 8` | **High** | entry + epilogue bytes |
| Vtable DATA install @ `0x00a4a854` | **High** | `read_memory` → `40 ec 8a 00` |
| CF ≡ raw live decompile | **High** | identical body |
| Close path `0x9c40`/button success → `FUN_007fca10` | **High** | LAB_008aef8f |
| Button band `0x9c46`–`0x9c4d` → HandleButton(index) | **High** | asm `add ebx,-0x9c46; push; mov eax,esi; call` |
| `unaff_EDI` is decompiler phantom | **High** | only one stack push |
| `DAT_00aaa664` ≈ 1e-4f | **High** | `17 b7 d1 38` |
| `DAT_00aaa6f8` = 255.0f | **High** | `00 00 7f 43` |
| Reward slot index math → `+0x558` / `+0x698` bases | **High** | algebra on id `0x9c42` |
| Product English name | **Probable** (`_Inferred`) | no string/RTTI on this VA |
| Toolkit English for msg 5/6/8/0x1a | **Tentative** | structural click/drag/focus only |
| Runtime close → filled vs empty 0x206E | Open | UF-011 residual |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Branch on controlId vs `0x9c46`/`0x9c4d` | **Yes** |
| NPC multi `>0x9c4e` + msg 8 + table bounds | **Yes** |
| Button msg 8 → HandleButton; zero→return 1; else close label | **Yes** |
| switch: 40000 close / 0x9c41 scale / 0x9c42–45 reward | **Yes** |
| Default `FUN_0087b500` | **Yes** |
| No invent sector packet send inside this body | **Yes** |

### 4.1 Live decompile head (2026-07-29)

```c
undefined4 __thiscall FUN_008aec40(int param_1,int param_2,int param_3)
{
  ...
  if ((param_3 < 0x9c46) || (0x9c4d < param_3)) {
    if ((0x9c4e < param_3) && (param_2 == 8)) {
      if ((*(int *)(param_1 + 0x72c) != 0) &&
         (param_3 - 0x9c4fU < (uint)(*(int *)(param_1 + 0x730) - *(int *)(param_1 + 0x72c) >> 2))) {
        Client_ShowNpcMissionDialogUI(&DAT_00d1a840,*(undefined4 *)(param_1 + 0x644),0);
      }
      return 1;
    }
  }
  else if (param_2 == 8) {
    cVar1 = Client_MissionDialogHandleButton((int *)(param_3 + -0x9c46),unaff_EDI);
    ...
  }
  switch(param_3) { case 40000: ... case 0x9c41: ... case 0x9c42..0x9c45: ... }
  return FUN_0087b500(param_2,param_3);
}
```

Full body in raw capture (authoritative).

---

## 5. Surviving contract for AutoCore

```
Client_MissionDialog_ControlDispatch_Inferred(dialog, msg, id):
  if id in [0x9c46, 0x9c4d] and msg==8:
    ok = MissionDialogHandleButton(dialog, id-0x9c46)
    if not ok: return 1
    goto close
  if id > 0x9c4e and msg==8:
    if id-0x9c4f in NPC multi table: ShowNpcMissionDialogUI(...)
    return 1
  switch id:
    0x9c40 + msg8 → close (FUN_007fca10; if state==2 chrome 0x13)
    0x9c41 + msg0x1a → scale sync (bias 1e-4)
    0x9c42..0x9c45 → reward focus/drag/click when +0x64c
  return FUN_0087b500(msg, id)

// close label also shared with successful HandleButton
// vtable @ 0x00a4a854
// Does NOT itself send 0x206E — FUN_007fca10 → Flush does
```

---

## 6. Open questions

1. Official C++ method / class name for vtable slot.
2. Toolkit message enum English (5/6/8/0x1a).
3. Product names for `FUN_0087b500`, `FUN_008aa3f0`, `FUN_007fd420`, `FUN_007fca10`.
4. Runtime capture of close after accept (UF-011 empty 0x206E risk).

**Verdict:** **accept-with-gaps** — CF, control-id map, vtable install, constants, and HandleButton/close wiring sealed; product method name and msg English / runtime remain open.
