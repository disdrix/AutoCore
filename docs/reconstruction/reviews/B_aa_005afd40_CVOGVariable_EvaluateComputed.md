# Review B (skeptical / adversarial): `CVOGVariable_EvaluateComputed` @ `0x005afd40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005afd40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005afd40_CVOGVariable_EvaluateComputed.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Mutates mission state | Falsified — pure evaluate into *out |
| 2 | Type 9 uses active hash +0x540 | Falsified — completed path; active is 0xb |
| 3 | Always returns 1 | Falsified — 0 when param_4 null / fail cases |
| 4 | Type 8 is wall-clock time | Falsified — RNG stream from singleton |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x40 type / +0x4c value | High | Wrong condition |
| 0xb/0xc hash bases | High | Trigger false pos/neg |
| Type 8 RNG | High | Nondeterministic gates |
| Types 1–4,6,7,0xd+ | Tentative | Missing conditions |

---

## 3. Cross-check against raw

```
if type5/8 special; if type12-ish pre; if !param4 return 0;
switch type → fill *param3; return 1|0.
Clean large; many FUN_* remain.
```

---

## 4. Surviving contract for AutoCore

```
EvaluateComputed(map, var, *out, characterCtx):
  switch var.type(+0x40):
    5/8 specials; 9 completed; 0xB active mission; 0xC active obj
  out float; return success
  server re-eval on grant/complete (plate)
```

---

## 5. Open questions

1. Table of all type codes with AutoCore names.
2. Seal Left/Right condition evaluator if separate.

**Verdict:** **accept-with-gaps**
