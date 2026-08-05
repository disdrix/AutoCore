# Review B (skeptical / adversarial): `aa_00403680` CombatFloaterVector_InsertN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403680` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00403680_CombatFloaterVector_InsertN_0x38_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always reallocates | **Falsified** — in-place when `size+n ≤ cap` |
| 2 | Doubles capacity exactly | **Overstated** — `cap + (cap>>1)` with overflow→0 then force-fit |
| 3 | Element size 0x4 | **Falsified** — **0x38** |
| 4 | Part of XP formula | **Falsified** — container only |
| 5 | `n==0` still mutates | **Falsified** — whole body gated on `param_3 != 0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vector layout + 0x38 | High | Heap corruption on floater spam |
| Realloc vs shift branch split | High | Lost floaters / UAF |
| Helper FUN names | Tentative | Wrong modernization of move/copy |

---

## 3. Surviving contract for AutoCore

```
FloaterVector.InsertN(at, n, value):
  if n==0: return
  if size+n > capacity: grow (1.5x-ish), relocate, insert n copies of value
  else: shift/move tail; construct n at insert point from value template
ElementSize = 0x38. Used by kill-XP combat floater queue grow path.
```

---

## 4. Open questions

1. Seal relocate helpers dual units if any still missing.
2. Confirm no non-trivial dtor on T (delete old buffer bare).

**Verdict:** **accept-with-gaps**
