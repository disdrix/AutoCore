# Review B (skeptical / adversarial): `aa_00539090` CNDHash_FreeBuckets_Owning_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00539090_CNDHash_FreeBuckets_Owning_009cfa64.md` |
| **Verdict** | **accept** (trivial FreeBuckets CF; ownership sealed via reclaim twin) |

**Tools:** Ghidra `batch_decompile` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | FreeBuckets is non-owning (values survive) | **Falsified** — reclaim `00538120` `operator_delete`s `node+8` |
| 2 | Same body as `0053b880` / non-owning twins | **Falsified** — different reclaim callee; this owns values |
| 3 | Also tears freelist slabs | **Falsified** — no `0059c8a0`; dtor adds that after FreeBuckets |
| 4 | Clears freelist head `+0x20` | **Falsified** — reclaim *fills* freelist; head not zeroed here |
| 5 | Aborts if locked | **Falsified** — no lock check; callers (Recreate/Dtor) log lock separately |
| 6 | Stack args / `ret n` | **Falsified** — bare `ret`; ECX this |
| 7 | Always frees table | **Falsified** — gated on `+0x10 != 0` |
| 8 | Named only as VOG_DEBUG_STOP leaf | **Falsified as identity** — shared Recreate+Dtor teardown |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| count zero @ +0x0c | **High** | Stale count after teardown |
| Owning reclaim via `00538120` | **High** | Leak or double-free of values |
| free(*table) then delete table | **High** | Heap corruption / slab leak |
| Null +0x10 after free | **High** | Use-after-free if reused |
| Not full object dtor | **High** | Miss freelist slab teardown / vtbl |

---

## 3. Cross-check against raw + bytes

```
count(+0xc) = 0
call reclaim_owning_00538120
if table(+0x10):
  free(*table)
  operator_delete__(table)
  table = 0
ret
```

Clean must **not** invent lock handling, AllocBuckets, freelist-slab free, or non-owning reclaim. Scaffold `FUN_00539090` under-names the role; sibling Recreate/Dtor duals already name this FreeBuckets.

---

## 4. Surviving contract for AutoCore

```
// Port of CNDHash FreeBuckets (owning family 009cfa64 / reclaim 009cefd4)
void CNDHash_FreeBuckets_Owning(CNDHash* h) {
  h->count = 0;                    // +0x0c
  CNDHash_ReclaimAllOwning(h);     // 00538120 — delete values, freelist-push nodes
  if (h->buckets) {                // +0x10
    free(*h->buckets);             // sentinel slab
    operator_delete__(h->buckets);
    h->buckets = nullptr;
  }
}
// Recreate: FreeBuckets → AllocBuckets
// Dtor:     FreeBuckets → FreelistSlabVector_dtor
```

---

## 5. Open questions

1. Product symbol for FreeBuckets vs internal helper name.
2. Whether any path calls FreeBuckets without subsequent Alloc or object free (would leave freelist populated — intentional for Recreate).

**Verdict:** **accept**
