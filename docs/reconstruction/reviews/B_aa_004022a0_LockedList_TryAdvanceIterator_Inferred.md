# Review B (skeptical / adversarial): `aa_004022a0` LockedList_TryAdvanceIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004022a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004022a0_LockedList_TryAdvanceIterator_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Blocking EnterCriticalSection | **Falsified** — **Try**Enter only |
| 2 | Always starts at head | **Falsified** — only when `*cursor==0` |
| 3 | Awards XP / levels character | **Falsified** — iterator only |
| 4 | Return 0 always means success | **Falsified** — 0 also means “got element” vs end=1; lock-fail is `0x80070005` |

---

## 2. Surviving contract for AutoCore

```
LockedList.TryAdvance(cursor*, outPayload*):
  if !enabled: return 0
  if !TryEnterCS: return 0x80070005
  advance or seed from head; return 1 at end, 0 when yielded element
Leave CS before return on success paths.
```

**Verdict:** **accept-with-gaps**
