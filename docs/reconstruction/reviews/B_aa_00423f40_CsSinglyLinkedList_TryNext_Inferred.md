# Review B (skeptical / adversarial): `aa_00423f40` CsSinglyLinkedList_TryNext_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423f40` |
| **VA** | `0x00423f40` |
| **Canonical name** | `CsSinglyLinkedList_TryNext_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md` |
| **System** | container / thread-safe list (DB load cursor) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Blocking EnterCriticalSection | TryEnter only | **Falsified** |
| 2 | Doubly-linked | Only +8 next read | **Falsified** |
| 3 | Returns bool only | Tri-state 0/1/HRESULT | **Falsified** |
| 4 | Skill-only helper | Many non-skill callers | **Falsified** |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x00423f40` (autoassault.exe, 2026-07-29) matches `raw/aa_00423f40_FUN_00423f40.md` control flow and callees.

---

## 3. Surviving contract

```
// try next under CS; 0 ok, 1 end, 0x80070005 denied/disabled.
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent.
