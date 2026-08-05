# Review B (skeptical / adversarial): `CVOGReaction_RandomUnitScalar` @ `0x007a4330`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007a4330_CVOGReaction_RandomUnitScalar.md` |
| **Verdict** | **accept** (with name-warning) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns float 0..1 unit scalar | Falsified — returns RNG object* |
| 2 | Reaction damage roll | Falsified — shared RNG singleton |
| 3 | Re-inits every call | Falsified — once via flag bit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Singleton identity DAT_00d20c1c | High | Shared state bugs |
| Once-init flag | High | Double ctor |
| Name vs behavior | High | Misuse in ports |

---

## 3. Cross-check against raw

```
if !(flag&1): flag|=1; FUN_007a42d0(); atexit; return &DAT_00d20c1c.
```

---

## 4. Surviving contract for AutoCore

```
RandomUnitScalar():
  // misnomer: returns RNG*
  once: construct DAT_00d20c1c
  callers index ushort table * scale for type-8 vars
  and terrain solid UV column pick
```

---

## 5. Open questions

1. Rename plate to Map_GetSharedRng or similar in index.
2. Document RNG table stride.

**Verdict:** **accept** (with name-warning)
