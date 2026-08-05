# Review B (skeptical / adversarial): `aa_005b2d70` DeferredBlobQueue_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2d70` |
| **VA** | `0x005b2d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2d70_DeferredBlobQueue_Push.md` |
| **Evidence** | Live decompile; grow helper; skills + PostCorrection callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | std::vector contiguous push | **Falsified** | 0x10 blocks × 4 cells + ring index |
| 2 | Copies full 0x18 node blob inline | **Falsified** | single dword `*param_2` store |
| 3 | Always grows | **Falsified** | gated on alignment + capacity |
| 4 | Leaves count unchanged on null cell | **Falsified** | count++ always after store attempt |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ring block push math | **High** | queue corruption / lost events |
| Element = one dword | **High** | wrong skills/equip enqueue |
| Grow helper correctness | **Medium–High** | residual delete warning |
| Product name | **Low–Medium** | naming |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
Push(q, *elem):
  if need_grow: GrowBlocks(q, 1)
  slot = wrap((head+count) >> 2)
  ensure block[slot] = new dword[4]
  block[slot][idx & 3] = *elem
  count++
```

**Verdict:** **accept-with-gaps**
