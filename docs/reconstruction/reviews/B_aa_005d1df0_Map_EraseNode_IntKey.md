# Review B (skeptical / adversarial): `aa_005d1df0` Map_EraseNode_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d1df0_Map_EraseNode_IntKey.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | lower_bound only | Falsified — erase |
| 2 | String-key map only | Falsified — int-key name/path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase rebalance correctness | High | Corrupt maps |
| Iterator out contract | Medium | Use-after-free |

---

## 3. Cross-check against raw

```
Map_EraseNode_IntKey(map, outIt, node):
  unlink/rebalance int-key map node
STL residual. Clean CF noisy but present.
```

---

## 4. Surviving contract for AutoCore

```
Map erase primitive if AutoCore ports client map containers.
```

---

## 5. Open questions

1. List erase call sites in table reload.

**Verdict:** **accept-with-gaps**
