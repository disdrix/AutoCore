# Review B (skeptical / adversarial): `aa_00589bc0` Skill_HB_ApplyHeatDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-005) |
| **Counterpart** | `reviews/A_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is HP apply (`00589c70`) | **Falsified** — no `FUN_004d7e30`, no HP vtbls +0x23C/+0x244-as-GetMaxHp call; uses `Vehicle_AddHeat` + heat fields |
| 2 | This is shield apply (`00589d90`) | **Falsified** — distinct VA; shield writes `+0x144`/`+0x148`, no RTTI vehicle cast |
| 3 | Positive `amount` cools | **Falsified** — positive ECX delta into `Vehicle_AddHeat` increases heat (AddHeat: `nCurrentHeat += delta`) |
| 4 | `__thiscall` / ECX = skill | **Falsified** — prolog only PUSH ESI/EDI; no this setup; callers pass 3 stack args + `ADD ESP,0xC` |
| 5 | `RET 4` / stdcall | **Falsified** — epilogue bare `RET` (`C3`) |
| 6 | Only 2 args (decompiler truth) | **Falsified** — `MOVSS XMM0,[ESP+0x14]` after 2 pushes = third float; callers clean 12 B |
| 7 | Heat delta = MI adjustor dword | **Falsified** — decompiler artifact; real delta is CVTTSS2SI of amount / max\*amount into ECX before PUSH |
| 8 | Percent uses current heat | **Falsified** — percent multiplies **`+0x244` max**, snapshot current is `+0x150` only for return |
| 9 | Always applies (no gate) | **Falsified** — null netobj or `net[+0x7E]==0` skips `Vehicle_AddHeat` (return 0) |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 3-arg ABI + bare RET + ADD ESP,0xC | **Confirmed** | Stack imbalance in ports |
| Sign: float+ heat / float− cool | **Confirmed** | Inverted heat math |
| Percent window [-1,1] via max heat +0x244 | **Confirmed** | Wrong scaling |
| RTTI vehicle / creature+0x250 | **Confirmed** | Wrong target type |
| Gate net+0xA8 / +0x7E | **Confirmed** | Client-side no-op missed |
| Return = actual +0x150 delta | **Confirmed** | Wrong HB accounting |
| param_1 unused | **Confirmed** | Overfitting source semantics |
| Netobj +0x7E English name | **High** (role) / **Low** (product) | Doc only |
| Product plate `Skill_HB_*` English | **High** (role) / **Inferred** (symbol) | Rename churn |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 decompile body preserved (wrong math)
live force_decompile 2026-08-05 ≡ same wrong decompile
assembly + read_memory seal authoritative clean Skill_HB_ApplyHeatDelta_Inferred.cpp

00589bc0  56 57                               PUSH ESI/EDI
00589c08  F3 0F 10 44 24 14                   MOVSS XMM0,[ESP+0x14]  ; amount
00589c0e  0F 2F 05 A0 F2 A0 00                COMISS XMM0,[1.0f]
00589c17  F3 0F 10 0D 68 A6 AA 00             MOVSS XMM1,[-1.0f]
00589c24  F3 0F 2A 8E 44 02 00 00             CVTSI2SS XMM1,[ESI+0x244]
00589c49  8B BE 50 01 00 00                   MOV EDI,[ESI+0x150]
00589c5a  E8 …                                CALL Vehicle_AddHeat
00589c69  C3                                  RET

DAT_00aaa668 = BF 80 00 00 (-1.0f)
g_flOne      = 3F 80 00 00 (1.0f)
```

Reject ports that:

- Trust the 2-arg decompiler body or pass MI adjustor as heat delta.
- Treat positive amount as cool without evidence.
- Use thiscall / ECX skill object as `this` for this helper.
- Merge with HP (`00589c70`) or shield (`00589d90`).
- Skip the `[-1,1]` percent branch or use current heat for percent.
- Skip the netobj `+0x7E` gate.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail skill HB heat channel.
// amount: +heat, -cool; |amount|<=1 => fraction of max heat.
// source arg is ABI-present but ignored; resolve target via RTTI only.
// Applies only when net/ghost gate byte +0x7E is set.
// Returns actual current-heat delta after Vehicle_AddHeat clamp.

int Skill_HB_ApplyHeatDelta_Inferred(
    object? sourceIgnored,
    object? target,
    float amount)
{
    var vehicle = DynCastVehicle(target)
               ?? DynCastCreature(target)?.VehicleAt250;
    if (vehicle is null) return 0;

    int delta = amount is >= -1f and <= 1f
        ? (int)(vehicle.MaxHeat * amount)
        : (int)amount;

    int cur = vehicle.CurrentHeat;
    if (vehicle.NetObj is { Gate7E: true })
        vehicle.AddHeat(delta);
    return vehicle.CurrentHeat - cur;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on HP/shield merge, thiscall, 2-arg-only, adjustor-as-delta, inverted sign, and ungated apply are **falsified** by sealed assembly. Remaining gaps are product English, orphan site plates, and runtime.
