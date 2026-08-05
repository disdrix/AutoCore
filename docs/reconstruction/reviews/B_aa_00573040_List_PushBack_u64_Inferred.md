# Review B (skeptical / adversarial): `aa_00573040` List_PushBack_u64_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00573040_List_PushBack_u64_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Head-insert | **Falsified** — updates **tail**; head only if empty |
| 2 | Dedup inside this function | **Falsified** — always append; Collect does membership first |
| 3 | Returns node* | **Falsified** — returns **0** success |
| 4 | Busy flag only logs | **Falsified** — throws `0x80070005` |
| 5 | stdcall not thiscall | **Falsified** — `mov esi,ecx` |

## Surviving contract

```text
// list thiscall; after Collect membership miss:
hr = List_PushBack_u64(list, coidLo, coidHi);  // 0 or throw
```

**Verdict:** **accept-with-gaps.** Accept A.
