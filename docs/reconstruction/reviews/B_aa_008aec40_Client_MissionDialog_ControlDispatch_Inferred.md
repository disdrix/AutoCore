# Review B (skeptical / adversarial): `aa_008aec40` Client_MissionDialog_ControlDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aec40` |
| **VA** | `0x008aec40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** `Client_MissionDialogHandleButton` | name confusion | **Falsified** — HandleButton is callee `0x008ae7c0`; this is outer UI dispatch |
| 2 | This **sends** C2S `0x206E` / `0x206F` directly | wire habit | **Falsified** — no packet builder here; close → `FUN_007fca10` → Flush; buttons → HandleButton |
| 3 | Direct **code** CALL xrefs exist | normal function | **Falsified** — only DATA vtable @ `0x00a4a854` |
| 4 | `unaff_EDI` is a real second HandleButton arg | trust decompiler | **Falsified** — asm: one push (index) + EAX=this |
| 5 | `DAT_00aaa664` is “level UI base” or 0 | plate reuse | **Falsified as role** — value **~1e-4** ROUND bias (`17 b7 d1 38`) |
| 6 | `DAT_00aaa6f8` is 1.0 | scale habit | **Falsified** — **255.0f** |
| 7 | Reward slots are mission **objectives** | id band habit | **Falsified as exclusive** — band used with ResolveObjectTarget + `+0x64c` reward flag; objectives use other paths |
| 8 | Product method name string-proven | symbol inflation | **Not sealed** — **Probable / `_Inferred`** |
| 9 | msg `8` means “keydown” | Win32 habit | **Not sealed** — structural “activate/click”; toolkit enum open |
| 10 | Function ends before reward cases | signature tool 5 callees | **Falsified** — body through `008aefbb` includes 0x9c42–45; LAB_008aef8f inside span |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Control-id band map | **High** | Wrong button/reward wiring |
| Close → FUN_007fca10 | **High** | Miss 0x206E flush invoker |
| Vtable-only install | **High** | Hunt non-existent CALL sites |
| Constants 1e-4 / 255 | **High** | UI scale wrong |
| HandleButton index = id−0x9c46 | **High** | Wrong accept slot |
| Product English name | **Medium** | Doc only |
| Msg type English | **Low–Med** | Mis-port toolkit |
| Runtime close payload quality | **Open** | Stale 0x206E (UF-011) |

---

## 3. Cross-check against raw

```text
// raw aa_008aec40 ≡ live decompile 2026-07-29
// thiscall ret 8; vtable 0x00a4a854

// Buttons 0x9c46..0x9c4d + msg8:
//   HandleButton(id-0x9c46) [EAX=this]; fail→return 1; success→close

// Close 0x9c40 + msg8 / shared LAB_008aef8f:
//   FUN_007fca10(); if +0x648==2: FUN_007fef20(0x13,1,0); return 1

// Scale 0x9c41 + msg 0x1a:
//   val = ROUND(+0x704 * vtbl458(+0x700) + DAT_00aaa664)
//   if val != get(+0x6e0): set; invalidate

// Reward 0x9c42..0x9c45:
//   msg5 resolve+focus; msg6 drag globals; msg8 click FUN_008aa3f0 if +0x64c

// NPC multi >0x9c4e + msg8:
//   if index in [+0x72c,+0x730): ShowNpcMissionDialogUI

// else: FUN_0087b500(msg,id)
```

Clean scaffold ≡ raw outline (no invent packet sends).

---

## 4. Surviving contract for AutoCore

```
Client_MissionDialog_ControlDispatch_Inferred(dialog, msg, controlId):
  // UI vtable handler — NOT HandleButton, NOT Flush, NOT Recv 0x206D
  // Wire:
  //   buttons → Client_MissionDialogHandleButton (may fill 0x206E / send 0x206F)
  //   close   → FUN_007fca10 → Client_MissionDialog_FlushPreparedResponse (0x206E send)
  // Constants:
  //   DAT_00aaa664 ≈ 1e-4f
  //   DAT_00aaa6f8 = 255.0f
  // Install: *(vtbl+slot) @ image 0x00a4a854 = 0x008aec40

// Port tests that matter:
//  - Must not implement HandleButton state machine here
//  - Must route 0x9c46..0x9c4d to HandleButton with index id-0x9c46
//  - Must share close path with successful button (goto LAB)
//  - Must not drop unaff_EDI as a real dependency
//  - Reward click requires +0x64c != 0
//  - NPC multi requires table bounds on +0x72c/+0x730
```

---

## 5. Open questions

1. Official class/method name for the vtable entry.
2. Full toolkit message enumeration (5/6/8/0x1a).
3. English names for residual FUN_* callees.
4. Live CE: click accept → HandleButton → close → wire 0x206E contents.
5. Whether `FUN_0087b500` is base-class control default.

**Verdict:** **accept-with-gaps** — adversarial attacks on “is HandleButton”, direct 0x206E send, code-xref-only install, real `unaff_EDI`, and wrong constants **fail**; remaining gaps are product naming, msg English, and runtime wire quality only.
