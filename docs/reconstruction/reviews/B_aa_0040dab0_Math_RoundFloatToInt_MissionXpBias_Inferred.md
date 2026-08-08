# Review B (skeptical / adversarial): `aa_0040dab0` Math_RoundFloatToInt_MissionXpBias_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-119) |
| **Counterpart** | `reviews/A_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission-grant XP authority (`AddExperience`) | **Falsified** — grant path inlines ±bias then `CVOGReaction_AddExperience`; this unit is presentation/math only |
| 2 | Toast-only helper | **Falsified** — **20** call sites across item cycle, conversion_percent, multi-float hosts |
| 3 | Trunc toward zero only (no round) | **Falsified** — ±0.5001 before `CVTTSS2SI` implements half-away-from-zero |
| 4 | Bias is exactly 0.5f | **Falsified** — image dword `8e06003f` = **0.5001f** |
| 5 | `__thiscall` / ECX float | **Falsified** — `MOVSS` from `[ESP+4]`; ECX unused; plain `RET` |
| 6 | `RET 4` callee-clean | **Falsified** — both exits `C3` (plain RET) |
| 7 | Banker's / round-half-even | **Falsified** — no SSE rounding mode; explicit ±bias then trunc |
| 8 | Same as `Mission_ComputeObjectiveXp` cast | **Falsified** — calc returns bare `(int)float` trunc; this adds bias |
| 9 | `Mission_Bulk_0040dab0` product name | **Falsified** — keyword bulk scaffold; no plate evidence |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| SSE CF / both exits | **Confirmed** | Wrong displayed XP / floater |
| Bias VA + 0.5001f | **Confirmed** | Off-by-one near .5 |
| Stack float + plain RET | **Confirmed** | Stack imbalance if ported as thiscall/stdcall |
| Not grant authority | **High** | Double-grant if miswired to AddExperience |
| Multi-caller utility | **High** | Over-narrow naming |
| Orphan call-site hosts | **Low** | Incomplete xref English only |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Math_RoundFloatToInt_MissionXpBias_Inferred.cpp

0F 57 C9                 XORPS  XMM1, XMM1
F3 0F 10 44 24 04        MOVSS  XMM0, [ESP+4]
0F 2F C8                 COMISS XMM1, XMM0
76 0D                    JBE    pos
F3 0F 5C 05 D0 A6 AA 00  SUBSS  XMM0, [00aaa6d0]
F3 0F 2C C0              CVTTSS2SI EAX, XMM0
C3                       RET
pos:
F3 0F 58 05 D0 A6 AA 00  ADDSS  XMM0, [00aaa6d0]
F3 0F 2C C0              CVTTSS2SI EAX, XMM0
C3                       RET

bias: 8e 06 00 3f = 0.5001f @ 00aaa6d0
```

Reject ports that:

- Use plain `(int)x` without ±0.5001 bias.
- Use 0.5f instead of **0.5001f**.
- Treat as thiscall or `RET 4`.
- Wire into server-side grant instead of presentation/math consumers.
- Keep `Mission_Bulk_0040dab0` as product English.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail leaf: signed round half-away-from-zero with bias 0.5001f
// Used by Client_ShowMissionRewardChatToast after Mission_ComputeObjectiveXpAsFloat.

const float MissionXpRoundBias = 0.5001f; // image 0x00aaa6d0

static int RoundFloatToInt_MissionXpBias(float value)
{
    if (value < 0f)
        return (int)(value - MissionXpRoundBias); // trunc toward zero after adjust
    return (int)(value + MissionXpRoundBias);
}

// Toast path (presentation only):
//   float f = Mission_ComputeObjectiveXpAsFloat(obj);
//   int xp = RoundFloatToInt_MissionXpBias(f);
//   // sprintf "Awarded %d ..."; enqueue floater
```

---

## 5. Verdict

Adversarial pass confirms A on CF/ABI/bias/multi-caller scope. Product demangle residual only → **accept**.
