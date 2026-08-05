# Review A (reconstruction fidelity): `aa_008af020` FUN_008af020 (dialog close sibling)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008af020` |
| **VA** | `0x008af020` |
| **Canonical name** | `FUN_008af020` (proposed: `Client_MissionDialog_PrimaryButtonClose` — **Probable**) |
| **Body range** | `0x008af020` – `0x008af056` (19 instructions; 4 BBs) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008af020_Client_MissionDialog_PrimaryButtonClose.md` |
| **System tag** | `missions-progression` |
| **Chain** | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` (flush invoker path) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live) | `FUN_008af020` @ `0x008af020` |
| Function info | body `008af020–008af056`; callees: HandleButton, `FUN_007fca10`, `FUN_007fef20` |
| Image bytes | `read_memory` `0x008af020` len 64 → hex below |
| Parent dispatch (not owned) | code @ `0x008af060` (DATA vtbl `0x00a4a870`); CALL site `0x008af090` |
| Sibling event path (not owned) | `FUN_008aec40` @ `0x008aec40` (DATA vtbl `0x00a4a854`) |
| HandleButton | `Client_MissionDialogHandleButton` @ `0x008ae7c0` |
| Close/flush invoker | `FUN_007fca10` @ `0x007fca10` → dialog `vtbl+0x440` = Flush |
| Open dialog table | `FUN_007fef20` @ `0x007fef20` (`client+0x1030+index*4`) |
| Client singleton imm | `0x00d1a840` (`DAT_00d1a840`) in EBX/ECX at call sites |
| Raw / annotated / clean | `raw/aa_008af020_*`, `reconstructed-exact/FUN_008af020.cpp` |
| Function record | `functions/aa_008af020_FUN_008af020.md` |
| Prior chain refs | Flush A/B + CHAIN c2s_206e (lists this as alt dispatch) |

---

## 2. Evidence used

### 2.1 Live decompile (≡ frozen raw control flow)

```c
// 0x008af020
undefined4 FUN_008af020(void)
{
  char cVar1;
  int unaff_ESI;       // dialog object (parent sets ESI = ECX)
  // decompiler also invents unaff_retaddr for 2nd HandleButton arg

  cVar1 = Client_MissionDialogHandleButton((int *)0x0, /*stack garbage / unused*/);
  if (cVar1 != '\0') {
    FUN_007fca10();                        // close visible → Flush if prepared
    if (*(int *)(unaff_ESI + 0x648) == 2) {
      FUN_007fef20(0x13, 1, 0);            // reopen dialog table slot 0x13
    }
  }
  return 1;  // AL=1 (CONCAT31 noise is decompiler width artifact)
}
```

### 2.2 Assembly (authoritative; `read_memory` 2026-07-29)

```text
008af020  6A 00                 push    0                 ; pDialogContext = 0
008af022  8B C6                 mov     eax, esi          ; dialog this → HandleButton in_EAX
008af024  E8 97 F7 FF FF        call    Client_MissionDialogHandleButton
008af029  84 C0                 test    al, al
008af02b  74 27                 jz      ret1              ; success==0 → skip close
008af02d  53                    push    ebx
008af02e  8B C6                 mov     eax, esi
008af030  BB 40 A8 D1 00        mov     ebx, 0x00d1a840   ; client host for FUN_007fca10
008af035  E8 D6 D9 F4 FF        call    FUN_007fca10
008af03a  83 BE 48 06 00 00 02  cmp     dword ptr [esi+0x648], 2
008af041  5B                    pop     ebx
008af042  75 10                 jnz     ret1
008af044  6A 00                 push    0                 ; param_4
008af046  6A 01                 push    1                 ; param_3 (open, not toggle-close)
008af048  6A 13                 push    0x13              ; dialog table index 19
008af04a  B9 40 A8 D1 00        mov     ecx, 0x00d1a840
008af04f  E8 CC FE F4 FF        call    FUN_007fef20
008af054  B0 01                 mov     al, 1
008af056  C3                    ret
```

**Immediates sealed (signature + memory):** `0`, `1`, `2`, `0x13` (`19`).

### 2.3 Parent invoker (static; outside body)

Code at `0x008af060` (vtable DATA `0x00a4a870` on mission-dialog class `0x00a4a51c`):

```text
; __thiscall-like: ECX = dialog, [esp+4] = message id, ret 8
cmp  [esp+4], 0x20   → float path (unrelated)
cmp  [esp+4], 0x0D   → mov esi, ecx; call FUN_008af020; ret 8
else fallthrough/jmp
```

| Item | Value | Confidence |
|---|---|---|
| Direct CODE xref to body | only `0x008af090` (inside parent) | **High** |
| Parent DATA xref | `0x00a4a870` → `0x008af060` | **High** |
| Vtable base | `0x00a4a51c` (dialog ctor class) | **High** (prior Flush seal) |
| Parent method offset | `0x00a4a870 − 0x00a4a51c = **0x354**` | **High** |
| Sibling `FUN_008aec40` slot | `0x00a4a854` → offset **0x338** | **High** |
| Message gate for this path | id **`0x0D`** | **High** (image) |

### 2.4 Role vs sibling `FUN_008aec40`

| Path | HandleButton arg | Close trigger | State-2 reopen `0x13` |
|---|---|---|---|
| `FUN_008aec40` btn ids `0x9c46..0x9c4d`, msg==8 | `(param_3 − 0x9c46)` | on HandleButton ≠ 0 → `FUN_007fca10` | yes if `+0x648==2` |
| `FUN_008aec40` close id `0x9c40` (40000), msg==8 | **none** | always `FUN_007fca10` | yes if `+0x648==2` |
| **`FUN_008af020`** (this) | **always `0`** | on HandleButton ≠ 0 → `FUN_007fca10` | yes if `+0x648==2` |

Same **close + optional journal reopen** tail as sibling success/close labels (`LAB_008aef8f` family). This unit is the **thin primary-context (slot 0) close sibling**, not the full UI event matrix.

### 2.5 Flush chain contribution

```
UI msg 0x0D → vtbl+0x354 parent @ 0x008af060
  → FUN_008af020
       HandleButton(dialog, context=0)
       if nonzero: FUN_007fca10
                    → if visible: dialog.vtbl+0x440 = Client_MissionDialog_FlushPreparedResponse
       if dialog+0x648 == 2: FUN_007fef20(client, index=0x13, open=1, flag=0)
  return 1
```

Matches CHAIN c2s_206e invoker static seal (this VA listed as alt dispatch).

---

## 3. Confirmed claims with confidence

| Claim | Confidence | Notes |
|---|---|---|
| Function exists at `0x008af020` | **High** | Ghidra function + bytes |
| ESI = mission dialog object | **High** | Parent `mov esi,ecx`; `+0x648` state field |
| HandleButton context arg is literal **0** | **High** | `push 0` |
| HandleButton dialog is ESI via EAX | **High** | `mov eax,esi` + HandleButton `in_EAX` |
| Nonzero HandleButton → `FUN_007fca10` | **High** | test/jz |
| `FUN_007fca10` uses client `DAT_00d1a840` in EBX | **High** | imm load |
| After close, if `dialog+0x648 == 2` open slot **0x13** | **High** | cmp + `FUN_007fef20(0x13,1,0)` |
| Always returns success **1** (AL) | **High** | `mov al,1; ret` both paths |
| Is dialog-close sibling of `FUN_008aec40` close/success tail | **High** | identical post-HandleButton block |
| Contributes to 0x206E flush when prepared + visible | **High** (static) | via `FUN_007fca10` → Flush |
| Proposed name `Client_MissionDialog_PrimaryButtonClose` | **Probable** | primary context 0 + close; not retail symbol |
| Message `0x0D` product meaning | **Tentative** | only compared as int in parent |
| What UI object is table index `0x13` | **Probable** | same reopen used after abandon modal; mission UI family |

---

## 4. Control flow: clean ≡ decompiler ≡ asm

| Stage | Match |
|---|---|
| HandleButton(context=0) | **Yes** |
| Early out if HandleButton returns 0 | **Yes** |
| FUN_007fca10 close/flush | **Yes** |
| Gate `+0x648 == 2` → FUN_007fef20(0x13,1,0) | **Yes** |
| Return 1 | **Yes** |

Decompiler noise to ignore in clean plate: `CONCAT31` / `extraout_var*` (AL=1 only); `unaff_retaddr` as 2nd HandleButton arg (unused / not pushed).

---

## 5. Remaining uncertainty

1. **Runtime** — no live click trace that msg `0x0D` is the Accept button path users hit (static only).
2. **Rename** — Probable, not Confirmed retail name.
3. **Parent function** at `0x008af060` is not defined as a Ghidra function (DATA-only entry); full parent dual is out of scope (owned by other VA if queued).
4. **State-2 + context 0** — HandleButton state 2 only opens abandon modal when context==1; context 0 falls through return 1 → this unit closes and may reopen `0x13` without modal (static edge).
5. **Double-close** — HandleButton state 1 GiveMission path already calls `Client_HideMissionDialogIfOpen` before return 1; this still calls `FUN_007fca10` (different host field vs hide — known flush chain distinction).

---

## 6. Verdict

**accept-with-gaps.**

Unit is a real, small **dialog close sibling**: primary HandleButton context **0** → close/flush invoker → optional journal-style reopen at dialog table **0x13** when router state is **2**. Sealed by image bytes + parent CALL + shared tail with `FUN_008aec40`. Gaps: runtime, product name of msg `0x0D`, formal rename.
