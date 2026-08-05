# Review B (skeptical / adversarial): `aa_004cb270` StdTree_IteratorIncrement_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cb270_StdTree_IteratorIncrement_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Simple linked-list `*it = **it` | Has right-min and parent-climb | **Falsified** as list-only next |
| 2 | Returns next in EAX | Writes through `*param_1` only | **Falsified** EAX-return |
| 3 | Mutates tree structure | Only iterator pointer | **Falsified** structure mutate |
| 4 | Nil test inverted | `== '\\0'` means non-nil (isnil flag) | **Survives** MSVC convention |
| 5 | Combat-specific | Shared utility many xrefs | **Falsified** domain-only |

---

## 2. Live ≡ raw

Full CF matches annotated/clean.

---

## 3. Surviving contract

```
// ECX=it*; *it = tree_successor(*it)
```

**Verdict:** **accept**.
