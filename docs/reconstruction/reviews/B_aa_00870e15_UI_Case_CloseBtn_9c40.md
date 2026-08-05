# Review B (skeptical / adversarial): `aa_00870e15` UI_Case_CloseBtn_9c40

| Field | Value |
|---|---|
| **Stable ID** | `aa_00870e15` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00870e15_UI_Case_CloseBtn_9c40.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure `__fastcall(param_1,param_2)` as decompiler signature | Parent loads stack into EAX/EDX, saves ECX→EDI; case `ret 8` | **Falsified** — outer **thiscall + 2 stack args**; case is jump fragment |
| 2 | `in_EAX` / `unaff_EDI` are undefined garbage | Parent `mov eax,[esp+4]; mov edi,ecx` immediately before table jump | **Falsified** — **live**, intentional |
| 3 | `FUN_0087b500(in_EAX, param_2)` only two args / no this | Bytes: `push edx; push eax; mov ecx,edi; call` | **Falsified** — **thiscall(this, msg, controlId)** |
| 4 | Always closes on close-button click | Gate `cmp [edi+0x50c],-1` / `jne` skips call | **Falsified exclusive always** — **selection blocks leave** |
| 5 | This case is mission-dialog `FUN_008aec40` close | Different VA; this unit is table case under `0x00870a90` | **Falsified identity merge** — **shared id/host only** |
| 6 | `mov ebx, 0x00d1a840` loads a pointer-to-pointer | Leave host uses `*(EBX+0xf40)`; image BSS object base | **Holds as object base address** — not `*DAT_` load |
| 7 | Return value on msg 8 can be leave’s EAX | Bytes force `mov al,1` after call | **Falsified** — **always 1** on msg 8 |
| 8 | Control id still tested inside case | Case is table arm for index 0 only; no second id check | **Holds** — id already discriminated |
| 9 | Scaffold name `FUN_00870e15` is product name | Ghidra case label only | **Rename to role name OK**; RTTI still open |
| 10 | `FUN_007fca10` always Flushes 0x206E here | Leave host is class-generic; Flush only if this class maps `+0x440` to Flush | **Not sealed for this class** — **gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| msg==8 / +0x50c==-1 / leave / else forward CF | **High** | Wrong close UX / stuck dialog |
| RET 8 + EDI restore | **High** | Stack smash in ports |
| thiscall into `FUN_0087b500` | **High** | Wrong ECX on forward |
| Leave EAX/EBX register ABI | **High** | Leave host no-ops or AVs |
| id `0x9c40` = close | **High** (cross-dialog constant) | Mis-wire chrome |
| Product dialog class | **Low** | Wrong system tag only |
| `+0x50c` English type | **Medium** (sibling writes −1 clear) | Misnamed field |
| Class `+0x440` == Flush | **Low for this unit** | Wire-side assumptions |

---

## 3. Cross-check against raw + bytes

```
raw/live decompile (3× identical):
  if (in_EAX==8) {
    if (*(unaff_EDI+0x50c)==-1) FUN_007fca10();
    return 1;
  }
  return FUN_0087b500(in_EAX, param_2);

bytes:
  83F808 751D 83BF0C050000FF 750E
  53 8BC7 BB40A8D100 E8… 5B
  B001 5F C20800
  52 50 8BCF E8… 5F C20800

parent 0x00870a90:
  mov edx,[esp+8]; mov eax,[esp+4]; push edi; mov edi,ecx
  lea ecx,[edx-0x9c40]; cmp ecx,0xB; ja FORWARD_TAIL
  jmp [ecx*4+0x00870e44]   ; [0] = 0x00870e15
```

**No CF conflict** between three-rep decompile and body bytes. Decompiler only weak on **calling convention / arg count** for the forward call and on **register recovery labels**.

---

## 4. Surviving contract for AutoCore

```csharp
// Client UI case — behavior port
// Invoked only when controlId == 0x9c40 from parent switch.
uint UI_Case_CloseBtn_9c40(DialogUi self, int msg, uint controlId)
{
    if (msg == 8)
    {
        if (self.SelectedId /* +0x50c */ == -1)
            ClientLeaveDialog(self, clientStaticBase: 0x00d1a840); // FUN_007fca10 reg ABI
        return 1;
    }
    return UI_ForwardDialogMessage(self, msg, controlId); // FUN_0087b500
}
```

Port notes:

- **Do not** close while `+0x50c != -1`.
- **Do not** assume mission 0x206E Flush unless this dialog class is proven to map leave `+0x440` there.
- **Do not** trust decompiler `__fastcall` prototype for wrappers.

---

## 5. Open questions

1. Dialog RTTI / XML skin / product name for vtable containing `0x00870a90`.
2. Full schema of `+0x50c` selection payload.
3. Runtime click capture proving leave suppressed when selected.
