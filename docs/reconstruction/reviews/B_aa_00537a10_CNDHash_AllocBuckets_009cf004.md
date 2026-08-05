# Review B (skeptical / adversarial): `aa_00537a10` CNDHash_AllocBuckets_009cf004

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537a10` |
| **VA** | `0x00537a10` |
| **Canonical name** | `CNDHash_AllocBuckets_009cf004` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00537a10_CNDHash_AllocBuckets_009cf004.md` |
| **Live tools** | Independent `force_decompile` + sealed twin + xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leaves `+0x08` as power-of-two size | Final store is `size - 1` (mask) | **Falsified** “size remains” |
| 2 | bits=0 allowed | Range `>0 && <0x11` | **Falsified** |
| 3 | bits=16 allowed | `< 0x11` includes 16 | **Attack fails** — 16 OK |
| 4 | Byte-identical to `005378d0` | Sentinel `009cf004` ≠ `009ceff4` | **Falsified** merge |
| 5 | force changes CF | force ≡ batch ≡ raw | **Attack fails** |
| 6 | No real callers | Xrefs `00536ed9`, `00539dbc` | **Falsified** orphan |

---

## 2. Surviving contract

```
AllocBuckets_009cf004(hash):
  require 1..16 bits
  N = hash[+8]  // size
  table = new N ptrs; slab = malloc(N*0xc)
  for i: table[i]=sentinel_i{vtbl:009cf004, head:0}
  hash[+8] = N-1  // mask
```

**Traps:** index with `key & mask`, not `% size`; free slab as one `malloc`, not per-sentinel.

**Verdict:** **accept-with-gaps.** Accept A.
