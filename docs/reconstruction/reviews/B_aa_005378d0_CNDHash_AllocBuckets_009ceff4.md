# Review B (skeptical / adversarial): `aa_005378d0` CNDHash_AllocBuckets_009ceff4

| Field | Value |
|---|---|
| **Stable ID** | `aa_005378d0` |
| **VA** | `0x005378d0` |
| **Canonical name** | `CNDHash_AllocBuckets_009ceff4` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005378d0_CNDHash_AllocBuckets_009ceff4.md` |
| **Live tools** | Independent force decompile + ctor link |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leaves `+0x08` as power-of-two size | Final store is `size - 1` (mask) | **Falsified** “size remains” |
| 2 | bits=0 allowed | Range check `>0 && <0x11` | **Falsified** |
| 3 | bits=16 allowed | `< 0x11` includes 16 | **Attack fails** — 16 OK (65536 buckets) |
| 4 | Single allocation for table+sentinels | Separate `operator_new__` + `malloc` | **Falsified** single-alloc |
| 5 | Same as twin `00537970` | Sentinel vtbl differs (`009ceff4` vs `009ceffc`) | **Falsified** full merge |
| 6 | force changes CF | force ≡ batch | **Attack fails** |

---

## 2. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size→mask | **Confirmed** | Bucket index OOB / collision |
| Sentinel head @+4 | **Confirmed** | Insert/Lookup desync |
| Range throw | **Confirmed** | Silent bad ctor |
| Twin sentinel families | **High** | Wrong vtbl stamp |

---

## 3. Cross-check

```
force ≡ batch.

Callers include: FUN_0053b0b0 @ 0053b10a; init cluster 00536f38..00537055

Throw: local = -0x7fffbffd → u32 0x80004003 after VOG_DEBUG_STOP
```

### Traps

1. **Do not** index buckets with `key % size` after alloc — use `key & mask`.
2. **Do not** free sentinels as separate heap nodes — one slab `malloc`.
3. **Do not** treat bits=0 as “one bucket” — throws.

---

## 4. Surviving contract

```
AllocBuckets_009ceff4(hash):
  require 1..16 bits
  N = hash[+8]  // size
  table = new N ptrs; slab = malloc(N*0xc)
  for i: table[i]=sentinel_i{vtbl:009ceff4, head:0}
  hash[+8] = N-1  // mask
```

**Verdict:** **accept-with-gaps.** Accept A.
