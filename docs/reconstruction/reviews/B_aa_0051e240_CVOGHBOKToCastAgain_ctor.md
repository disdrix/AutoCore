# Review B (skeptical / adversarial): `aa_0051e240` CVOGHBOKToCastAgain_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_0051e240_CVOGHBOKToCastAgain_ctor.md` |
| **Scratch** | `reviews/a_0051e240.md` |
| **Verdict** | **accept-with-gaps** — prior open insert ABI **closed**; English/runtime remain |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Signature is `(hb, skill, charge)` only | **Falsified** — `RET 0xC` + 3 pushes; owner is stack0 |
| 2 | No equip modifier | **Falsified** — multiplies skill+0x10 |
| 3 | Never clamps | **Falsified** — min(,500) when pool+0x6b4≥1 |
| 4 | Always inserts category CD | **Falsified** — skip if category == -1 |
| 5 | AttachOwner / GetMap take skill | **Falsified** — both take **owner** (EDI) |
| 6 | Vehicle vfuncs on skill | **Falsified** — **owner**.vtbl+0x210 / +0x1dc |
| 7 | No-vehicle path uses polluted FPU | **Falsified** — loads **`g_flOne`** |
| 8 | Category insert ABI unfinished | **Falsified this pass** — `{key,start,duration}` + map + out sealed |
| 9 | flCategoryScale init 0.0 | **Falsified** — constant at `0x00a0f2a0` is 1.0f |
| 10 | "Active plant" English for +0x6b4 | **Unproven** — field gate CF High; name open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-stack ABI / `RET 0xC` | **High** | Wrong ctor call → stack corruption |
| Owner vs skill roles | **High** | Map on wrong object; attach wrong |
| Duration formula | **High** | Wrong skill CD UI |
| No-vehicle mod = 1.0 | **High** | Invented garbage scale |
| 500 ms clamp gate | **High** | Stuck long CD under pool flag |
| Type id 8 + skill@+0x24 | **High** | HB dispatch / abort match fail |
| Category insert pack | **High** | Category CD desync |
| +0x6b4 / vfunc product names | **Tentative** | Docs only |
| GetSkillCooldownModifier internals | **Sibling** | Plant scale edge cases |

---

## 3. Cross-check against raw + bytes

```
HBBase_ctor; vtbl 0x009ce1c4; period(1,1);
EDI=owner, EBX=skill;
mod = (owner.vtbl+0x210()==0) ? g_flOne : ST0(GetSkillCooldownModifier(…));
HB+0x8 = ROUND(ceil(skill+0x10 * mod)) + charge;
if owner.vtbl+0x1dc() && pool+0x6b4>=1: HB+0x8 = min(HB+0x8, 500);
if skill+0x5e8!=-1:
  entry={key, DAT_00b041cc, HB+0x8};
  Insert(GetCategoryCooldownMap(owner), &out, &entry);
AttachOwner(hb, owner); HB+0x24=skill; HB+0x1c=8; RET 0xC.
```

Clean updated 2026-07-29 to match asm; raw body left intact (append-only policy).

---

## 4. Surviving contract for AutoCore

```
CVOGHBOKToCastAgain_ctor(hb, ownerEntity, skill, chargeDelayMs):  // RET 0xC
  equipMod = 1.0 if owner cannot resolve vehicle path, else plant-aware scale
  durationMs = round(ceil(skill.cooldownMs * equipMod)) + chargeDelay
  if combat-pool-like object +0x6b4 >= 1: clamp duration to 500
  if skill.categoryKey != -1:
    owner.categoryMap[key] = { start: clientTick, duration }
  HB.owner = ownerEntity; HB.skill = skill; HB.type = 8
Used by Skill_StartCastAgainHeartbeat for optimistic hotbar CD overlay.
Plant SkillCooldown must be identity 1.0 on wire — 0.0 collapses duration to charge-only.
```

---

## 5. Open questions

1. Seal product names for `owner.vtbl+0x210` / `+0x1dc` and field `+0x6b4`.
2. Second `+0x210` stack args / `skill+0x5ec` semantic.
3. Runtime hotbar capture vs formula (matrix policy).
4. Whether any other direct caller of ctor exists besides StartCastAgainHeartbeat (not required for CF).

**Verdict:** **accept-with-gaps** — CF + ABI + insert pack **sealed**; English/runtime/diff open.
