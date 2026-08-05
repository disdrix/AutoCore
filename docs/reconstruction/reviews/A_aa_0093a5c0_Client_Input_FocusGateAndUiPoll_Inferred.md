# Review A (reconstruction fidelity): `aa_0093a5c0` Client_Input_FocusGateAndUiPoll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a5c0` |
| **VA** | `0x0093a5c0`–`0x0093a818` |
| **Canonical name** | `Client_Input_FocusGateAndUiPoll_Inferred` (Ghidra `FUN_0093a5c0`; prior Named plate `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0093a5c0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093a5c0_Client_Input_FocusGateAndUiPoll_Inferred.md` |
| **System** | `input-drive-control` (+ client UI side effects) |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / xrefs / callers / `read_memory` entry. Prefer decompile/`read_memory`. Own VA only. No ledgers.

---

## 1. Purpose

Client **foreground-window gate** plus optional input/UI poll:

1. **`GetForegroundWindow()` ≠ `client+0x3188` (focus loss):** if local vehicle exists (`client+0xe98 → +0x250`), optionally `SetHandbrake(1)` + `FUN_004f3700` when `client+0x9c1==0`, then `PushDriveAxes` when `vehicle+0x101==0`. Return **0**.
2. **Focus OK:** run `FUN_007a69d0`; if `param_1==0`, run extra poll helpers (`FUN_00796d40` / `FUN_00796240`) and early-return on negative; UI modal gate via vfunc `+0x3d8` on `client+0x111c`; optional screenshot toast (**string** `"Saving Screenshot..."`); camera/UI host at `client+0xf40` with multiple vfuncs; on one path may `PushDriveAxes` again when vehicle not suppressed.

**Register convention:** `in_EAX` = client/game object at entry (`mov esi, eax` in prologue bytes). Stack: `char param_1` (key-match path pushes `1`).

**Entry bytes (`read_memory`):**

```text
0x0093a5c0: 53 55 56 57          push ebx/ebp/esi/edi
0x0093a5c4: 8b f0                mov esi, eax      ; client = EAX
0x0093a5c6: 33 db                xor ebx, ebx
0x0093a5c8: 33 ed                xor ebp, ebp
0x0093a5ca: ff 15 d0 67 9c 00    call [GetForegroundWindow]
0x0093a5d0: 3b 86 88 31 00 00    cmp eax, [esi+0x3188]
```

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0093a5c0_*`, `reconstructed-exact/FUN_0093a5c0.cpp` (+ Named plate) |
| Function record | `functions/aa_0093a5c0_FUN_0093a5c0.md` |
| Live decompile | ≡ raw CF including screenshot string |
| Callers | `Client_Input_OnKeyDown_MatchAction` @ `0x0091148f` (push `1`); `FUN_0094b520` @ `0x0094b5ad` (push `0`) |
| Sibling drive hooks | `SetHandbrake`, `FUN_004f3700`, `PushDriveAxes` duals |

**Not performed:** deep dual of every UI vfunc callee; runtime focus loss capture; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Foreground vs `client+0x3188` first gate | **High** | Win32 import + cmp |
| Focus-loss: HB1 + NoOp when `+0x9c1==0` | **High** | decompile |
| Focus-loss: Push only if `vehicle+0x101==0` | **High** | same suppress flag family |
| `param_1==0` enables extra poll path | **High** | branch on stack char |
| Screenshot path literal | **High** | `"Saving Screenshot..."` in body |
| Client in EAX/ESI | **High** | prologue `mov esi,eax` |
| Two call sites | **High** | xrefs + callers API |
| OnKeyDown path passes `1` | **High** | asm `push 1` @ `0x00911488` |
| FUN_0094b520 path passes `0` | **High** | asm `push 0` @ `0x0094b5a9` |
| Full English map of UI vfuncs (`+0xf40` slots) | **Open** | residual |
| Product name | **Open** | `_Inferred` |
| Runtime | **Open** | deferred |

---

## 4. Control flow (sealed skeleton)

```
client = EAX
ret = 0
if GetForegroundWindow() != *(HWND*)(client+0x3188):
  if char = *(client+0xe98) && vehicle = *(char+0x250):
    if *(u8*)(client+0x9c1)==0:
      SetHandbrake(vehicle, 1)
      DrivePathNoOp(vehicle)
    if *(u8*)(vehicle+0x101)==0:
      PushDriveAxesToController(vehicle)
  return 0

FUN_007a69d0()
if param_1 == 0:
  … FUN_00796d40 / FUN_00796240; maybe return negative …

// UI / modal early-outs via vfunc +0x3d8 on +0x111c
// optional screenshot toast + FUN_008f8200
// camera host +0xf40: vfuncs +0x3d8, +0x1cc, +0x450, +0x454, +0x338, +0x448 …
// secondary path may PushDriveAxes again if vehicle+0x101==0
return ret
```

---

## 5. Callers

| Caller | Site | `param_1` |
|---|---|---|
| `Client_Input_OnKeyDown_MatchAction` | `0x0091148f` | **1** (after action-slot match sets held/edge) |
| `FUN_0094b520` | `0x0094b5ad` | **0** |

---

## 6. Gaps / open

1. Product name for whole unit and for `FUN_0094b520`.
2. Semantic catalog of `client+0xf40` vfunc slots.
3. Meaning of `client+0x9c1` (suppress HB-on-blur?).
4. Runtime focus-loss drive freeze verification.

**Verdict:** **accept-with-gaps** — focus gate, dual-path drive park, param polarity, two callers, screenshot string sealed; UI vfunc English / runtime open.
