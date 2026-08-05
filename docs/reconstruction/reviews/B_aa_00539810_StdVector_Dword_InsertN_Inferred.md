# Review B (skeptical / adversarial): `aa_00539810` StdVector_Dword_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00539810_StdVector_Dword_InsertN_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Element size 0x38 (floater) | **Falsified** — all math `>>2` / `*4` |
| 2 | Always reallocates | **Falsified** — in-place when `cap >= size+n` |
| 3 | Exact double capacity | **Overstated** — `cap + cap/2` with overflow→0 then force-fit |
| 4 | Is push_back itself | **Falsified** — insert-N; push_back is `0x0053a820` |
| 5 | Same VA as `0x004e39d0` | **Falsified** — twin implementation, distinct address |
| 6 | `operator_delete` noreturn ends function early without rewrite | **Artifact** — decompiler warning; store triad still present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dword vector insert | High | Heap corruption on LevelUp list |
| Grow policy | High | OOM / length_error mis-map |
| Sole caller assumption | Medium | Miss other domains if xrefs incomplete |

---

## 3. Surviving contract for AutoCore

```
StdVector_Dword_InsertN(vec, at, n, &value):
  if n==0: return
  if size+n > capacity: realloc 1.5x-ish; relocate; fill n copies of *value
  else: shift tail; fill hole with *value
ElementSize = 4. Used by StdVector_PushBackDword slow path (count=1).
```

---

## 4. Open questions

1. Confirm `FUN_00537590` ≡ length_error throw.
2. Dual seal of fill helpers only if still open (`004e2f70` family).

**Verdict:** **accept-with-gaps**
