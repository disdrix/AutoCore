# Review B (skeptical / adversarial): `aa_0093a5c0` Client_Input_FocusGateAndUiPoll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a5c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0093a5c0_Client_Input_FocusGateAndUiPoll_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure key-down matcher body | Overclaim from sole OnKeyDown caller | **Falsified** — large UI/screenshot/camera poll after focus OK |
| 2 | Always parks vehicle | Overfit | **Falsified** — park only on **focus loss**; focused path is UI-first |
| 3 | Always SetHandbrake on blur | Missing gate | **Falsified** — requires `client+0x9c1==0` |
| 4 | Always Push on blur | Missing gate | **Falsified** — requires `vehicle+0x101==0` |
| 5 | `param_1` unused | Wrong ABI | **Falsified** — `param_1==0` enables extra poll; OnKeyDown passes **1** |
| 6 | thiscall ECX=client | Wrong convention | **Falsified** — prologue takes client in **EAX** (`mov esi,eax`) |
| 7 | Single caller | Incomplete | **Falsified** — **2** sites (OnKeyDown + `FUN_0094b520`) |
| 8 | Body writes thr/steer | Invent axes | **Falsified** — only HB setter + Push |
| 9 | Screenshot is unrelated dead string | Dead code | **Falsified** — reachable under edge flags + `FUN_007a13e0` + toast |
| 10 | Product-complete dual already present | Process | **Falsified** — scaffold only before this dual |
| 11 | Runtime sealed | Matrix | **Fail** |

---

## 2. Decisive dataflow (focus-loss arm)

```
client = EAX
if GetForegroundWindow() != *(client+0x3188):
  vehicle = *(*(client+0xe98)+0x250)   // if char non-null
  if vehicle:
    if *(u8*)(client+0x9c1)==0:
      SetHandbrake(1); DrivePathNoOp()
    if *(u8*)(vehicle+0x101)==0:
      PushDriveAxesToController()
  return 0
// else: UI poll tree (param_1, vfuncs, screenshot, maybe Push)
```

Live decompile ≡ raw. Entry `read_memory` confirms EAX→ESI and FGW import.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Focus gate + blur park | **High** | Ghost thr when alt-tab |
| `param_1` polarity | **High** | Wrong poll depth from OnKeyDown vs other |
| Two callers | **High** | Missed blur/UI entry |
| Screenshot string present | **High** | Naming only |
| UI vfunc semantics | **Open** | Incomplete chrome port |
| `+0x9c1` English | **Open** | When blur skips HB |

---

## 4. Surviving contract for AutoCore

```
FocusGateAndUiPoll(client in EAX, char doLightPoll):
  if not foreground(client.hwnd@+0x3188):
    park vehicle (HB1 + NoOp gated; Push if not suppressed)
    return 0
  // focused: UI/input poll; doLightPoll==0 → deeper poll helpers
  // may Push axes later if vehicle+0x101==0
```

**Verdict:** **accept-with-gaps** — blur park vs focused UI split, ABI, callers, string sealed; deep UI English / runtime open.
