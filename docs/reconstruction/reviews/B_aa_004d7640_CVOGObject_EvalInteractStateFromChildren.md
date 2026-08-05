# Review B (skeptical / adversarial): `aa_004d7640` CVOGObject_EvalInteractStateFromChildren

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d7640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d7640_CVOGObject_EvalInteractStateFromChildren.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on full priority matrix |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Works for all object types | **Falsified — type 0x12 only** |
| 2 | Single child type only | **Falsified — multi-type loop** |
| 3 | Return 1 means success interact | **Weak — early return 1 for non-NPC type** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type 0x12 gate | High | Wrong icons on non-NPC |
| Child type codes | High | Wrong state |
| Priority winner | Tentative | Wrong icon priority |

---

## 3. Cross-check against raw

```
if type!=0x12 return 1;
build child lists; walk; for each child type set/raise interact state; return aggregate
Clean preserves structure.
```

---

## 4. Surviving contract for AutoCore

```
On NPC interact icon eval from children:
  only type 0x12; aggregate GiveMission/objective/deliver child states
  complete (8) outranks offer/active
Feed Client_UpdateNpcInteractIcons consumers.
```

---

## 5. Open questions

1. Full priority table seal.
2. Cross-check EvalOfferableMissionInteractState sibling.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on full priority matrix
