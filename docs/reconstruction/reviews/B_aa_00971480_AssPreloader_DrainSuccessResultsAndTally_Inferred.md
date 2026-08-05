# Review B (skeptical / adversarial): `aa_00971480` AssPreloader_DrainSuccessResultsAndTally_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971480` |
| **VA** | `0x00971480` |
| **Canonical name** | `AssPreloader_DrainSuccessResultsAndTally_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-B) |
| **Counterpart** | `reviews/A_aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Thiscall ECX=host (like sibling AssPreloader methods)? | **Falsified** — host from `[ebp+8]`; no ECX formal; **`RET 4`** only |
| Drains pending ring `@+0x1c` (like worker loop)? | **Falsified** — pop ESI = **`host+0x4c`** (success vec; W32-K map) |
| Is enqueue / key-tree ready itself? | **Falsified** — no enqueue; callers **invoke this first** then do membership/ready |
| Already-loaded vs new branch inverted? | **Falsified** — `je` to tally when it==end or payload null; fall-through is log path |
| Dump always runs? | **Falsified** — gated by **`DAT_00d1f618`**; cleared after |
| Scaffold `Named_assPreloader` is product method name? | **Reject** — file path Confirmed; method plate structural **Inferred** |
| Same as PreloadWorkerLoop? | **No** — worker **produces** `@+0x4c`; this **consumes** it |

---

## Residual risks

1. Pop pair layout / key type for hash find (inherited from `0043e750` + cache key convention).  
2. Extension bucket edge (`00970910` returns 4 for OTHER) — dual free open.  
3. Dump size call passes name into `vt[+0x1c]` — odd vs tally path no-arg; **preserve** decompiler/bytes oddness.  
4. Runtime / bit-exact.

---

## Minimal sealed model

```
AssPreloader_DrainSuccessResultsAndTally(host@stack):
  while PopFront_Stride8(host+0x4c, &pair):
    it = HashMap_Find(cache=host+0x110, key_from_pair)
    if it == end || payload(it)==0:
      stamp tree(host+0x10){obj,time}
      b = ExtBucket(name); tally size@+0xe8[b], count@+0xfc[b]
    else:
      log PRELOAD already-loaded; scalar_delete(obj)
  if DAT_00d1f618: dump tree@+0x14 sizes/names; clear flag
  ret 4
```

---

## Verdict

ABI + drain CF sealed; do not retype as thiscall or pending-ring drain. **accept-with-gaps**.
