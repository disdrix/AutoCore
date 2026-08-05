# Review B (skeptical / adversarial): `aa_00531250` CVOGCharacter_AddAttributePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00531250_CVOGCharacter_AddAttributePoints.md` |
| **Verdict** | **needs-more-evidence** on caller absolute-vs-delta; **accept** on store CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function **adds** attribute points | **Falsified** — overwrite store to `+0x6cc` |
| 2 | Distinct dirty flag from skill | **Falsified** — same `+0x634 \|= 0x40` |
| 3 | Always toasts | **Falsified** — only when pool increases |
| 4 | Independent of skill twin | **Structure only** — CF clone with different pool/type |
| 5 | Name “Add” matches body | **Name inflation** — set/assign |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Assign +0x6cc | High | Pool corruption |
| LogicUI 0x23 | High | Wrong toast type |
| Shared dirty 0x40 | High | UI refresh coupling skill/attrib |
| Caller absolute | Tentative | Off-by-one / double apply |

---

## 3. Cross-check against raw

```
if attribPool(+0x6cc) < newValue:
  LogicUI(type=0x23, entity ids)
dirty |= 0x40
attribPool = newValue
```

Identical structure to skill points (`+0x6ce`, type `0x21`).

---

## 4. Surviving contract for AutoCore

```
AddAttributePoints(character, short newPoolValue)  // historical name
  if pool < newPoolValue: toast LogicUI 0x23
  dirty |= 0x40
  pool(+0x6cc) = newPoolValue
```

Mirror skill-point implementation; seal caller math once for both.

---

## 5. Open questions

1. CompleteObjective absolute vs `current+delta` for both pools.
2. Rename to Set* if absolute confirmed.
3. Live mission attribute rewards.
4. Whether dirty 0x40 is “points UI” generically.

**Verdict:** Accept assignment CF; reject additive naive mirror of the name.
