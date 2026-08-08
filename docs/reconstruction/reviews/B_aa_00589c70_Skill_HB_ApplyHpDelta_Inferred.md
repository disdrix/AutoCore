# Review B (skeptical / adversarial): `aa_00589c70` Skill_HB_ApplyHpDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-006) |
| **Counterpart** | `reviews/A_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is heat apply (`00589bc0`) | **Falsified** — heat uses `Vehicle_AddHeat` / RTTI cast to vehicle; this unit never touches heat fields; calls `FUN_004d7e30` with HP vtbls |
| 2 | This is shield apply (`00589d90`) | **Falsified** — distinct VA; parent routes shield via separate call after HP |
| 3 | Positive `amount` means damage | **Falsified** — `deltaInt = -trunc(amount)`; `FUN_004d78e0` does `HP' = HP - deltaInt`; positive float → negative deltaInt → heal. Damage callers multiply by `-1.0f` (`0x0061e86d`) |
| 4 | `__thiscall` / ECX = skill | **Falsified** — prolog only pushes regs; no `MOV ECX` this setup; callers pass 4 stack args and `ADD ESP,0x10` |
| 5 | `RET 4` / stdcall | **Falsified** — epilogue bare `RET` (`C3`) at both exits |
| 6 | Percent mode uses current HP | **Falsified** — percent multiplies **vtbl+0x244** (max), not +0x23C (current) |
| 7 | Floor recomputes return | **Falsified** — `LEA EBX,[EBP-1]` updates applied delta only; `CMP EBP,EDI` / `SUB EAX,EBP` still use pre-floor `EDI` |
| 8 | Always kills / no floor | **Falsified** — `allowKill==0 && projected<1` path present; HB parent pushes `0` for allowKill |
| 9 | Multiple callees / network send | **Falsified** — sole CALL target `FUN_004d7e30` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 4-arg ABI + bare RET | **Confirmed** | Stack imbalance in ports |
| Sign: float+ heal / float− damage | **Confirmed** | Inverted combat math |
| Percent window [-1,1] via max HP | **Confirmed** | Wrong scaling |
| leave-1 floor when !allowKill | **Confirmed** | Unintended kills |
| Return = unclamped projected−cur | **Confirmed** | Wrong HB accounting |
| Entity resolve +0x19C / +0xAC | **High** | Null target edge cases |
| vtbl+0x23C/+0x244 English names | **High** (role) / **Low** (product symbol) | Doc only |
| `FUN_004d7e30` full contract | **Medium** | Floater/flag side effects |
| Product plate `Skill_HB_*` English | **High** (role) / **Inferred** (symbol) | Rename churn |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Skill_HB_ApplyHpDelta_Inferred.cpp

00589c70  53 55 56 57                         PUSH EBX/EBP/ESI/EDI
00589cda  0F 2F 05 68 A6 AA 00                COMISS XMM0,[-1.0f @ aaa668]
00589ce3  F3 0F 10 0D A0 F2 A0 00             MOVSS XMM1,[1.0f @ a0f2a0]
00589cf4  FF 90 44 02 00 00                   CALL [EAX+0x244]  ; max HP
00589d0e  FF 92 3C 02 00 00                   CALL [EDX+0x23C]  ; cur HP
00589d26  8D 5D FF                            LEA EBX,[EBP-1]   ; floor
00589d54  8B 8E A4 00 00 00                   MOV ECX,[ESI+0xA4]
00589d68  E8 …                                CALL FUN_004d7e30
00589d79  C3                                  RET
00589d80  C3                                  RET (ret0 path)

DAT_00aaa668 = BF 80 00 00 (-1.0f)
g_flOne      = 3F 80 00 00 (1.0f)
color quad   = FF FF FF FF | FF FF FF FF | 00 00 00 00 | 00 00 00 00
```

Reject ports that:

- Treat positive amount as damage without the sign flip.
- Use thiscall / ECX skill object as `this`.
- Merge with heat (`00589bc0`) or shield (`00589d90`).
- Skip the `[-1,1]` percent branch or use current HP for percent.
- Recompute return after floor (retail does not).
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail skill HB HP channel (client-side apply + floater path).
// amount: +heal, -damage; |amount|<=1 => fraction of max HP.
// allowKill: false => never reduce below 1 HP on the applied delta.
// Returns projected HP delta (heal +, damage -) using pre-floor projection.

int Skill_HB_ApplyHpDelta_Inferred(
    object? source,
    object? target,
    float amount,
    bool allowKill)
{
    var entity = ResolveCombatEntity(target) ?? ResolveCombatEntity(source);
    if (entity is null) return 0;

    int deltaInt = amount is >= -1f and <= 1f
        ? -(int)(entity.GetMaxHp() * amount)
        : -(int)amount;

    int cur = entity.GetCurrentHp();
    int projected = cur - deltaInt;
    if (!allowKill && projected < 1)
        deltaInt = cur - 1; // applied only; return still uses unclamped projected

    entity.CombatController.ApplyHpDelta(source, entity, deltaInt, /*floater*/ true);
    return projected == cur ? 0 : projected - cur;
}
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/sign/floor/call graph. Residual product-type English and shared apply dual → **accept-with-gaps**.
