# Review B (skeptical / adversarial): `aa_00792d20` NDUIContainerPanel_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792d20` |
| **VA** | `0x00792d20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00792d20_NDUIContainerPanel_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Final inventory grid type | **Falsified** | Grid `FUN_008609b0` subclasses this and swaps vtbl to `00a6476c` |
| 2 | No allocations | **Falsified** | Five `new(0x34)` helpers |
| 3 | Base-only (no subclass layer) | **Falsified** | Own vtbl after base |
| 4 | XML / rebuild items | **Falsified** | Ctor only; rebuild is `FUN_00860700` |

---

## 2. Surviving contract

```
panel = NDUIContainerPanel_Ctor(mem):
  base window
  container vtbl + flags
  alloc 5 helper pods
  return mem
// grid: FUN_008609b0 → this → grid vtbl
```

**Verdict:** **accept-with-gaps**
