# Review B (skeptical / adversarial): `aa_005788d0` CVOGHBSkillBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005788d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen) |
| **Counterpart** | `reviews/A_aa_005788d0_CVOGHBSkillBase_ctor.md` |
| **Verdict** | **accept** on name + ValidateTarget attach dual residual; **accept-with-gaps** on arg4/arg7 English |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Name is `CVOGHBSkillCast` | **Falsified** — RTTI string is `CVOGHBSkillBase`; no Cast type at this vtbl |
| 2 | RTTI COL is for a different class | **Falsified** — COL immediately before `PTR_FUN_009d3fdc`; type_info name reads as SkillBase |
| 3 | Does not call ValidateTarget | **Falsified** — direct call with notify=1 |
| 4 | AttachOwner uses caster / source object (`param_2`) | **Falsified** — Attach gets `param_5` (same as ValidateTarget target) |
| 5 | Type tag `+0x1c=1` is cosmetic | **Falsified** — `HBSkillListener` hard-gates on `+0x1c==1` before RTTI cast |
| 6 | notify=1 is dead / ignored | **Falsified** — ValidateTarget dual + listener uses flag for `vtbl+0x18` on handler code 2 |
| 7 | Is the only skill HB ctor | **Holds as false** — 14 subclass callers then replace vtbl |
| 8 | Reject path frees the object | **Unproven** — body returns `this` either way; free not in unit |
| 9 | Period always runs even on reject | **Falsified** — SetPeriod only inside accept branch |
| 10 | `FUN_0058ab60` is a no-op / identity | **Falsified** — allocates `0x4b0`, copies 300 dwords from seeded ring |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class name CVOGHBSkillBase | **Confirmed** | Wrong port hierarchy |
| ValidateTarget on construct (notify=1) | **Confirmed** | Miss client-side cast gate on HB spawn |
| Attach subject = target | **Confirmed** | Wrong owner list linkage / wrong +0xB0 |
| Period/counter attach only on accept | **Confirmed** | Spurious timers |
| Type tag enables listener | **Confirmed** | Silent HB list misses |
| arg4/arg7 product English | Tentative | Wrong serialization of HB params |
| `FUN_0058ab60` product name | Tentative | Wrong heap payload label (behavior High) |

---

## 3. Cross-check

```
Prior dual (thin scaffold): CVOGHBSkillCast_ctor_Inferred, "RTTI not sealed"
First dual pass:            COL@aaede0 → af8cec ".?AVCVOGHBSkillBase@@"; name accept
This residual pass:         re-read RTTI; seal Attach=target; type tag; period; notify chain
Sibling FUN_00578830:       same vtbl install; AttachOwner(null); no ValidateTarget
ValidateTarget dual:        (skill, target, notifyFlag); handler 1=reject; list @ target+0xB0
Listener 0x005532e0:        +0x1c==1; RTTI CVOGHBSkillBase; notify → vtbl+0x18
```

**Attack on prior dual residual:** claiming “ValidateTarget gate High” without sealing **who is attached** is **insufficient** for HB list fidelity. Attach subject is target, not source.

**Attack on “source == target” assumption:** `param_2` and `param_5` are separate formals; subclass `FUN_00614dc0` / `FUN_00617ad0` pass distinct slots through. Static ctor body never equates them.

---

## 4. Surviving contract for AutoCore

```
CVOGHBSkillBase_ctor(hb, sourceObj, skillBlob, arg4, target, tfid16, arg7):
  CVOGHBBase_ctor(hb)
  hb.vtbl = CVOGHBSkillBase          // PTR_FUN_009d3fdc
  hb.typeTag(+0x1c) = 1              // skill HB for HBSkillListener
  copy skillBlob[0x18c dwords] → hb+0x24
  seed TFID @ +0x658 from sourceObj+0x160 (or DAT_009d3f88 sentinel)
  seed TFID @ +0x668 via FUN_00513b00 / sentinel
  store arg4 @ +0x688; tfid16 @ +0x690; arg7 @ +0x6a8
  +0x6a0 = FUN_0058ab60(arg7)        // heap table clone
  if ValidateTargetForSkill(hb.skillRuntime, target, notify=1):
      AttachOwner(hb, target)        // pOwner@+0x18; list target+0xB0
      copy owner TFID → +0x678
      +0x08 = +0x40
      period = (+0x3C) or 1
      SetPeriodAndCounter(hb, period, true)   // +0x0C and +0x10
  return hb                          // reject: no attach/period; still live object
```

---

## 5. Residual uncertainty

| # | Item | Blocks name / attach seal? |
|---|---|---|
| R1 | Full skill-blob field glossary | No |
| R2 | Reject-path ownership / free | Mild (static return sealed) |
| R3 | Subclass product names (14 VAs known) | No |
| R4 | arg4 / arg7 / `FUN_0058ab60` English | No |
| R5 | `this+0x08` product meaning | No |
| R6 | `FUN_0054f3c0` usefulness pre-memcpy | No (CF present; effect mostly overwritten) |

---

## 6. Concrete checks performed

1. Re-decompile `0x005788d0` (live ≡ raw body).
2. Read 4 bytes before vtbl → COL `0x00aaede0`.
3. Read COL+0x0C → type_info `0x00af8cec`; string `".?AVCVOGHBSkillBase@@"`.
4. Read `DAT_009d3f88` → `{FFFFFFFF,FFFFFFFF,0,0}`.
5. Decompile AttachOwner / SetPeriodAndCounter / HBSkillListener / FUN_0058ab60 / FUN_00578830.
6. Confirmed ValidateTarget call + AttachOwner(param_5) branch + period floor.
7. Cataloged 14 subclass callers via Ghidra; sampled `0x00614dc0`, `0x00617ad0`, `0x00650f50` re-point vtbl after base.

---

## 7. Verdict

**accept** for `CVOGHBSkillBase_ctor` product name **and** ValidateTarget-attach dual residual (attach=target, type tag, notify, period). Layout arg4/arg7 English remains open without blocking the seal.
