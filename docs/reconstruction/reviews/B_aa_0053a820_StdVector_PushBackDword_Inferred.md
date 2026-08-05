# Review B (skeptical / adversarial): `aa_0053a820` StdVector_PushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053a820_StdVector_PushBackDword_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Floater 0x38 element | **Falsified** — **dword** (`>>2`) |
| 2 | Always grows | **Falsified** — fast path when room |
| 3 | XP grant | **Falsified** — push only |

---

## 2. Surviving contract for AutoCore

```
VecU32.PushBack(v):
  if size < cap: *end++ = v
  else: InsertGrow(end, 1, &v)
Used on LevelUp path; element semantics caller-owned.
```

**Verdict:** **accept**
