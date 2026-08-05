# Review B (skeptical / adversarial): `aa_0051e390` CVOGHBOKToCastAgain_OnStart

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual seal; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_0051e390_CVOGHBOKToCastAgain_OnStart.md` |
| **Verdict** | **accept-with-gaps** on CF; prior flag-ABI / owner-slot opens **closed by bytes** |
| **Scratch** | `reviews/a_0051e390.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Clears casting flag | **Falsified** — `push 1`; OnEnd clears with `push 0` |
| 2 | No stamp / stamp optional | **Falsified** — unconditional tail `jmp StampLastFireTime` |
| 3 | Ignores null owner | **Falsified** — `cmp [esi+0x18],0` / `je` |
| 4 | `+0x18` is the skill | **Falsified** — skill load is `+0x24`; ctor AttachOwner(**owner**) → `+0x18` |
| 5 | Flag call has 3 args / `unaff_SI` live | **Falsified** — only `push 1`; ESI = saved this |
| 6 | Flag is wide (int) | **Falsified** — callee writes **byte** `skill+0x628`; `RET 4` |
| 7 | Stamp resets period / “start tick” differently | **Falsified as other fields** — only `HB+0x14 = g_dwClientTickMs` |
| 8 | Direct CALL xrefs to OnStart | **Data-only** vtbl `0x009ce1c8` — still activation path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Casting flag set to 1 on skill | **High** | Cast UI / LocalCastValidate gate wrong |
| Stamp timing (activate baseline) | **High** | Remaining-duration skew |
| Owner gate vs skill target split | **High** | Wrong object mutator if fused |
| SetIsCastingFlag ABI / byte width | **High** | Stack garbage / wrong write size |
| True-path tick/float side effects | **High** | Cast-start bookkeeping wrong |
| Null-`+0x18` production incidence | **Tentative** | If null, flag never set but stamp still runs |

---

## 3. Cross-check against raw / bytes

```
// raw decomp noise kept for history; machine:
if +0x18: SetIsCasting(ECX=+0x24, char 1);  // no SI arg
always: StampLastFireTime(this);             // +0x14 = tick; tail jmp
```

Clean 2026-07-29 drops `unaff_SI` and documents owner/skill split. **Clean ≡ asm** on CF.

Alloc residual from prior B: StartCastAgainHeartbeat `push 0x28` / `operator_new` — **High** for HB size; owned by `aa_00519200`.

---

## 4. Surviving contract for AutoCore

```
OKToCastAgain_OnStart(HB):
  // mark skill casting for cast-again window
  if HB.owner(+0x18) != null:
    skill = HB.skill(+0x24)
    skill.isCasting(+0x628) = 1
    skill.field_170 = 0.0f
    skill.castStamp(+0x178) = g_dwClientTickMs
  HB.lastFire(+0x14) = g_dwClientTickMs   // always
  // duration already on HB+0x8 from ctor (cd*equipMod + charge; 500ms plant clamp)
  // OnEnd must clear casting flag (push 0)
```

---

## 5. Open questions

1. Product English for skill `+0x628` / `+0x170` / `+0x178` (CF sealed).
2. Any live path with null owner on a queued type-8 HB (unlikely if ctor always attaches).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** on CF; flag ABI + owner/skill slots **sealed**
