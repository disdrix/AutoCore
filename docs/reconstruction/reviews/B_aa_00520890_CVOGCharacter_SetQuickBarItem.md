# Review B (skeptical / adversarial): `aa_00520890` CVOGCharacter_SetQuickBarItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00520890_CVOGCharacter_SetQuickBarItem.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Accepts slot >= 100 | **Falsified — no-op** |
| 2 | Clears skill slot | **Falsified — item only** |
| 3 | Needs dual review depth | **N/A trivial — still documented for completeness** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offsets + dirty bit | High | Corrupt QB state |
| Bounds | High | OOB write |

---

## 3. Cross-check against raw

```
if slot<100: store coid; dirty|=2
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetQuickBarItem(slot, coid64): bound check; store; mark dirty bit2.
Pair with SetQuickBarSkill; empty = COID FFFFFFFF:FFFFFFFF.
```

---

## 5. Open questions

1. None material for trivial unit.

**Verdict:** **accept**
