# Review B (skeptical / adversarial): `aa_0058cc40` Skill_HB_ApplyShortAndFloater_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058cc40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-008) |
| **Counterpart** | `reviews/A_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is HP apply (`00589c70`) | **Falsified** — HP uses vtbl +0x19C/+0x23C/+0x244 and `FUN_004d7e30`; this unit uses +0x214/+0xAC and short words +0x12c/+0x12e |
| 2 | This is heat apply (`00589bc0`) | **Falsified** — heat path is separate parent channel; no Vehicle_AddHeat / heat fields here |
| 3 | This is shield apply (`00589d90`) | **Falsified** — shield mutates pool +0x144/+0x148; distinct VA and parent flag bit |
| 4 | "Short" means duration/timer | **Falsified** — body mutates **16-bit** field at +0x12c and enqueues floater; no timer/reschedule call (that is `005787a0`) |
| 5 | Positive `amount` means damage/drain | **Falsified** — assembly `ADD EAX,EBP` then set; applied = new−old. Positive float **increases** short. Damage parents `* -1.0f` (`0x0061e8aa`) |
| 6 | `__thiscall` / ECX = skill | **Falsified** — prolog SUB ESP / PUSH regs only; callers pass 3 stack args and `ADD ESP,0xC` |
| 7 | `RET 4` / stdcall | **Falsified** — epilogue bare `RET` (`C3`) after `ADD ESP,0x38` |
| 8 | Percent mode uses current short | **Falsified** — percent multiplies word **+0x12e** (max), not +0x12c (current) |
| 9 | No floater / optional floater | **Falsified** — floater enqueue is unconditional after short path (type dword = 2 always) |
| 10 | Floater is free function only | **Falsified** — `ECX = [target+0xA4]+0xE8A4` before CALL `0x00402620` |
| 11 | Same 4-arg ABI as HP apply | **Falsified** — 3 args only; no allowKill; callers clean 0xC not 0x10 |
| 12 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 3-arg ABI + bare RET | **Confirmed** | Stack imbalance in ports |
| Sign: float+ gain / float− drain | **Confirmed** | Inverted short math |
| Percent window [-1,1] via max short | **Confirmed** | Wrong scaling |
| Fields +0x12c current / +0x12e max | **Confirmed** | Wrong offsets |
| Floater type 2 + thiscall queue | **Confirmed** | Missing UI feedback |
| Entity resolve vtbl+0x214 | **High** | Null target edge cases |
| Product English for short resource | **High** (role) / **Low** (symbol) | Doc only |
| Queue offset +0xE8A4 meaning | **Medium** | Side-structure misbind |
| Product plate `Skill_HB_*` English | **High** (role) / **Inferred** (symbol) | Rename churn |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Skill_HB_ApplyShortAndFloater_Inferred.cpp
(assembly corrects CONCAT22 + floater thiscall presentation)

0058cc40  SUB ESP,0x38 / PUSH EBX EBP ESI EDI
0058cc5c  CALL [EAX+0x214]                 ; resolve
0058cc7c  COMISS XMM0,[1.0f @ a0f2a0]
0058cc85  MOVSS XMM1,[-1.0f @ aaa668]
0058cc92  MOVSX EAX,word [ESI+0x12e]       ; max short
0058ccab  MOV BP,word [ESI+0x12c]          ; old short
0058ccb6  ADD EAX,EBP / PUSH EAX
0058ccb9  CALL [EDX+0xac]                  ; set short
0058ccbf  MOVSX EDI,word [ESI+0x12c] / SUB ; applied
0058cd17  MOV ECX,[EBX+0xa4] / ADD ECX,0xe8a4
0058cd3e  MOV [ESP+0x44],2                 ; floater type
0058cd46  CALL 0x00402620
0058cd51  ADD ESP,0x38 / RET

DAT_00aaa668 = 00 00 80 BF (-1.0f)
g_flOne      = 00 00 80 3F (1.0f)
color quad   = FF FF FF FF | FF FF FF FF | 00 00 00 00 | 00 00 00 00

Call sites: ADD ESP,0xC after CALL 0058cc40
Parent gate: TEST byte [skill+0x649],0x80
```

Reject ports that:

- Treat positive amount as drain without the parent `-1.0f` multiply.
- Use thiscall / ECX skill object as `this`.
- Merge with heat (`00589bc0`), HP (`00589c70`), or shield (`00589d90`).
- Skip the `[-1,1]` percent branch or use current short for percent.
- Drop the unconditional type-2 floater enqueue.
- Claim runtime Confirmed without Launcher evidence.
- Interpret "Short" as duration/timer (use `005787a0` for reschedule).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail skill HB short-pool channel (client-side apply + floater path).
// amount: +gain, -drain; |amount|<=1 => fraction of max short @ host+0x12e.
// Always enqueues combat floater type 2.
// Returns applied short delta (gain +, drain -).

int Skill_HB_ApplyShortAndFloater_Inferred(
    object? source,
    object? target,
    float amount)
{
    var host = (target is null && source is not null)
        ? source.ResolveShortHost()   // vtbl+0x214
        : target!.ResolveShortHost();

    int applied = 0;
    if (host is not null)
    {
        int delta = amount is >= -1f and <= 1f
            ? (int)(host.MaxShort * amount)   // +0x12e
            : (int)amount;
        int old = host.CurrentShort;          // +0x12c
        host.SetShort(old + delta);           // vtbl+0xAC
        applied = host.CurrentShort - old;
    }

    var blob = BuildFloaterType2(source, target, applied);
    target!.CombatCtrl.FloaterQueueAtE8A4.Enqueue(blob);
    return applied;
}
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/sign/floater/call graph. Residual product-type English for the short resource and queue plate → **accept-with-gaps**.
