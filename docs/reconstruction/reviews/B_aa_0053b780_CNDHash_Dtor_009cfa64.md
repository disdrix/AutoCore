# Review B (skeptical / adversarial): `aa_0053b780` CNDHash_Dtor_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b780` |
| **VA** | `0x0053b780` |
| **Canonical name** | `CNDHash_Dtor_009cfa64` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b780_CNDHash_Dtor_009cfa64.md` |
| **Live tools** | Independent decompile + reclaim `00538120` + recreate cross-check |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | All CNDHash dtors non-owning | This twin’s reclaim **does** delete values | **Falsified** blanket non-owning |
| 2 | Dtor ≡ Recreate | Recreate also AllocBuckets after teardown; dtor does not | **Falsified** full merge |
| 3 | FreeBuckets differs from recreate | Same `00539090` | **Attack fails** — shared |
| 4 | Safe to dtor after recreate without clearing freelist | recreate reclaim already free values; freelist holds empty nodes | **High** residual ordering |

---

## 2. Surviving contract

```
Dtor_009cfa64:
  vtbl 009cfa64; lock log
  FreeBuckets_00539090 (OWNING free of node payloads)
  freelist slab vector teardown
  // no AllocBuckets
```

### Traps

1. **Do not** apply non-owning dtor rules from `009cfa4c` family here.
2. Double-free if caller already deleted payloads and left pointers in nodes.
3. Scalar dtor `0053b760` deletes object shell.

**Verdict:** **accept-with-gaps.** Accept A.
