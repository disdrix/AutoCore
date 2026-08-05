# Review B (skeptical / adversarial): `aa_004406e0` StdVector_PushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004406e0` |
| **VA** | `0x004406e0` |
| **Canonical name** | `StdVector_PushBackDword_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004406e0_StdVector_PushBackDword_Inferred.md` |
| **Live tools** | batch decompile |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always calls grow helper | Fast path returns after in-place store | **Falsified** |
| 2 | Element stride 8/0x98 | `>> 2` / `end+1` dword | **Falsified** |
| 3 | ECX thiscall | `in_EAX` + `unaff_ESI` | **Falsified** |
| 4 | Null begin still fast-path stores | Requires begin≠0 for capacity math | **Attack fails** (slow path) |
| 5 | Clean invents grow | Matches live call `00466da0` | **Falsified** divergence |

---

## 2. Surviving contract

```
PushBackDword(v, *val):
  if begin && size < capacity: *end++ = *val
  else FUN_00466da0(end, val)
```

**Verdict:** **accept-with-gaps.** Accept A.
