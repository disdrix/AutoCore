# Review B (skeptical / adversarial): `aa_005b2df0` VehicleNet_SkillsHBNodeVector_ReallocInsert_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2df0` |
| **VA** | `0x005b2df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2df0_VehicleNet_SkillsHBNodeVector_ReallocInsert_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always heap realloc | **Falsified** | in-place branches when `cap >= size+count` |
| 2 | Element size 0x18 (full HB node) | **Falsified** | stride **0xC** |
| 3 | Deque map grow (`005b2c10`) | **Falsified** | contiguous vector buffers |
| 4 | Writes BitStream | **Falsified** | pure container |
| 5 | `operator_delete` truly noreturn | **Falsified hazard** | MSVC free; decomp wrong |
| 6 | Skills-only exclusive helper | **Medium** | only traced from skills push; other xrefs not dual-sealed |

---

## 2. Surviving contract

```
ReallocInsert(vec, pos, n, value12):
  if n==0: return
  if cap < size+n: new = 1.5*cap (clamped); copy prefix; fill n; copy suffix; free old
  else: shift tail / fill in place
```

**Verdict:** **accept-with-gaps**
