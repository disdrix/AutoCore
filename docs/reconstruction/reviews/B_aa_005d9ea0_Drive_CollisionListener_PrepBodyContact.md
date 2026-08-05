# Review B (skeptical / adversarial): `aa_005d9ea0` Drive_CollisionListener_PrepBodyContact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W25-K) |
| **Counterpart** | `reviews/A_aa_005d9ea0_Drive_CollisionListener_PrepBodyContact.md` |
| **Scratch** | `tmp/a_005d9ea0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Analyze/Contact decompile shows 4 stack formals | **Falsified** — epilogue `RET 0x14`; Contact call sites push **5** |
| 2 | param_5 is float magnitude in | **Falsified as formal type** — first use is **byte enable**; float reuse is scratch after ABS |
| 3 | Always plays FX | **Falsified** — needs enable, \|impact\|>1, type-3 nested GO |
| 4 | Lazy-creates FxMaster | **Falsified** — `PlayCollisionEffect` allowCreate **0** (Contact may pass 1 later) |
| 5 | Sound always before FX | **Partial** — sound on cache-miss path may set soundDone; FX path skips duplicate sound if already done |
| 6 | Multiple independent callers | **Falsified** — sole function caller Contact (2 sites) |
| 7 | Name is retail PDB | **Overstated** — **Inferred** sibling of string-sealed Contact/Sound/Effect |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 0x14 / 5 stack args | **High** | Stack smash |
| Contact dual A/B calls | **High** | Miss one body |
| 1.0f impact gate | **High** | Silent SFX/VFX |
| allowCreate=0 polarity | **High** | Spurious FxMaster |
| this+0xc body cache | **High** | Sound spam / miss |
| Pair type English | **Medium** | Wrong material map |
| ctx type English | **Medium** | Wrong sound/FX attach |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = ECX; (ctx, body, impact, enable, out) = stack×5
walk body[3]… → host=root[8]
scan pairs type1 → optional GO (bit5 + vtbl+0x1C8)
scan type3/type4 → materials
if this+0xc != *body:
  if enable && abs(*impact)>1: PlayCollisionSound(...); soundDone=1
  this+0xc = *body
if go && nested_type==3 && enable && abs>1:
  if !soundDone: sound(packed mats)
  PlayCollisionEffect(..., allowCreate=0); *out=1
  this+0xc = *body
RET 0x14
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Contact review already lists this unit as per-body prep.

---

## 4. Surviving contract for AutoCore

```
// Client collision per-body prep (not server damage)
PrepBodyContact(listener, ctx, body, impact, enable, &outFlag)
// outFlag=1 only when type-3 GO FX path fires
// allowCreate=0 here; Contact may PlayCollisionEffect with 1 elsewhere
// Preserve this+0xc debounce and 1.0f magnitude gate with sound path
```
