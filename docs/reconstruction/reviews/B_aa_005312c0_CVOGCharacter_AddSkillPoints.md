# Review B (skeptical / adversarial): `aa_005312c0` CVOGCharacter_AddSkillPoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_005312c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005312c0_CVOGCharacter_AddSkillPoints.md` |
| **Verdict** | **needs-more-evidence** on caller absolute-vs-delta; **accept** on store CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function **adds** skill points | **Falsified by body** — `*(short*)(this+0x6ce) = param_2` (overwrite), not `+=` |
| 2 | Always toasts | **Falsified** — LogicUI only when old &lt; new |
| 3 | Decreases toast too | **Falsified** — decrease/same skips UI |
| 4 | Dirty always set | **Not broken** — `\| = 0x40` unconditional after UI branch |
| 5 | Plate “delta” is correct formal name | **Attacked** — formal is short value written as pool |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Assignment to +0x6ce | High | Double-add if server/client both add |
| Increase-only LogicUI | High | Missing/extra toasts |
| Dirty 0x40 | High | Stale skill UI |
| Caller passes absolute | Tentative | If caller passes delta, set-as-add is wrong |
| Type 0x21 meaning | Tentative | Wrong LogicUI handler |

---

## 3. Cross-check against raw

```
if skillPool(+0x6ce) < newValue:
  LogicUI(type=0x21, entity ids)
dirty |= 0x40
skillPool = newValue
```

Twin `AddAttributePoints` is identical with `+0x6cc` and type `0x23`.

---

## 4. Surviving contract for AutoCore

```
AddSkillPoints(character, short newPoolValue)  // name historical
  if pool < newPoolValue: toast LogicUI 0x21
  dirty |= 0x40
  pool(+0x6ce) = newPoolValue
```

Do **not** implement as `pool += delta` unless caller site RE proves absolute recomputation.

---

## 5. Open questions

1. CompleteObjective: absolute write or “current+delta” before call.
2. Rename candidate: `SetSkillPoints` / `SetSkillPointPool`.
3. Live mission reward skill-point values.
4. Dirty 0x40 journal/skills refresh chain.

**Verdict:** Accept assignment CF; reject naïve additive interpretation until callers sealed.
