# Review B (skeptical / adversarial): `aa_005d3cf0` CVOGHBAIBot_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3cf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d3cf0_CVOGHBAIBot_ctor.md` |
| **Verdict** | **accept** (short ctor CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Chains CharacterOrMine | **Falsified — CreatureBase** |
| 2 | Size 0x110 | **Falsified — 0x100** |
| 3 | Extra mid-field zero block | **Falsified — body is parent+vtbl** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bot vtbl | High | Wrong AI class |
| CreatureBase parent | High | Missing foot AI state |
| Size 0x100 | High | Heap overrun |

---

## 3. Cross-check against raw

```
CreatureBase_ctor; *this=BotVtbl; return.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Bot_ctor:
  AICode 3 summons; size 0x100 via CreatureBase
  tick path shared with foot creature family unless Bot vtbl overrides
  pair with CreateByAICode case 3
```

---

## 5. Open questions

1. Diff Bot vs CreatureBase vtbl slots for combat/pursue.

**Verdict:** **accept** (short ctor CF clear)
