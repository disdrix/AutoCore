# Review B (skeptical / adversarial): `aa_005b3370` GrowableArray_DoubleGrow

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b3370_GrowableArray_DoubleGrow.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Grows by +1 only | Off-by-one port | **Falsified** — doubles count (or 1 if 0) |
| 2 | `[1]` is capacity updated to newCap | Misread decompile | **Falsified** — `[1]` is **count**, left unchanged; newCap → `[2]` |
| 3 | Always frees old buffer | Ignore high-bit sentinel | **Falsified** — free only if `(int)[2] >= 0` |
| 4 | Element size always 4 | HB-centric | **Falsified** — `param_2` is stride; callers pass various sizes |
| 5 | Allocator tag is `0x24` / `0x50` | Confuse with object heaps | **Falsified** — tag **`0x12`** on alloc and free |
| 6 | Copies full new capacity | Over-read | **Falsified** — copies `count * elemSize` only |
| 7 | Thread-safe itself | Assume | **Falsified** — no CS; callers (Enqueue) lock outside |
| 8 | Name is PDB `std::vector` | Inflation | **Not sealed** — behavior is vector-like grow; product name open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Double / 1 policy | **High** | OOM thrash or stuck full |
| Free sentinel high bit | **High** | Double-free of static empty seed `0x80000000` |
| Count vs capacity slots | **High** | Corrupt list counts |
| Tag `0x12` | **High** | Allocator domain mismatch |
| Product name | **Low** | Doc only |

---

## 3. Cross-check against raw

```text
// raw ≡ live
newCap = (count == 0) ? 1 : count * 2;
newp = Alloc(newCap * elemSize, 0x12);
memcpy(newp, oldp, count * elemSize);
if ((int)capRaw >= 0)
  Free(oldp, (capRaw & 0x7fffffff) * elemSize, 0x12);
data = newp;
capRaw = newCap;   // count unchanged
```

Matches Enqueue dual: pending header `{ptr, count, capRaw}` at `list+0x28`.

---

## 4. Surviving contract for AutoCore

```
GrowableArray_DoubleGrow(hdr /* {void* p; int count; int capRaw} */, elemSize):
  newCap = count == 0 ? 1 : count * 2
  newp = heap_alloc(newCap * elemSize, tag=0x12)
  memcpy(newp, p, count * elemSize)
  if (int)capRaw >= 0:
      heap_free(p, (capRaw & 0x7fffffff) * elemSize, tag=0x12)
  p = newp
  capRaw = newCap
  // count unchanged
```

**Port tests:**

* First grow from ctor seed `capRaw=0x80000000`, `count=0` → alloc 1, **no free**.
* Full list `count==cap` → capacity becomes `2*count`.
* Must not zero or alter `count`.

---

## 5. Open questions

1. Allocator identity / name for `DAT_00b05060`.
2. Whether any non-triple header layout reuses this VA (xrefs suggest same triple).

**Verdict:** **accept**
